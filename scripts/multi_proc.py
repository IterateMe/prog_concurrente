#!/usr/bin/env python3

from multiprocessing import Pool
import os
import subprocess
import sys

NUM_PROCESSES = 2

def run_process(task_desc):
    p = subprocess.Popen(["./asset_conv"], stdin=subprocess.PIPE)
    p.communicate(input=task_desc.encode())


def init():
    global NUM_PROCESSES
    args_len = len(sys.argv)
    if args_len == 2:
        NUM_PROCESSES = int(sys.argv[1])
        
    

if __name__ == "__main__":
    init()

    print("Starting with {} processes".format(NUM_PROCESSES))

    pool = Pool(NUM_PROCESSES)
    
    queues = [ [] for i in range(NUM_PROCESSES) ]
    i = 0
    for line in sys.stdin:
        queues[i].append(line)
        i = (i + 1) % NUM_PROCESSES

    task_descs = []
    for q in queues:
        task_desc = '\n'.join(q)
        task_descs.append(task_desc)

    pool.map(run_process, task_descs)
    



//
// Created by wgrav on 5/7/2022.
//

#ifndef S6_APP1_TRANSLATE_PYTIN_H
#define S6_APP1_TRANSLATE_PYTIN_H


class translate_pytin {

    double curl_E(double E[2]){
        double curl_Ee[] = {0,0,0} ;
        curl_Ee[] = curl_Ee[] + E[] - E[];
        curl_Ee[] = curl_Ee[] - E[] - E[];

        curl_Ee[] = curl_Ee[] + E[] - E[];
        curl_Ee[] = curl_Ee[] - E[] - E[];

        curl_Ee[] = curl_Ee[] + E[] - E[];
        curl_Ee[] = curl_Ee[] + E[] - E[];

        return curl_Ee;
    }

    double curl_H(double H[]){
        double curl_Hh[] ={0,0,0,0}
        curl_Hh[] = curl_Hh[] + H[] - H[];
        curl_Hh[] = curl_Hh[] - H[] - H[];

        curl_Hh[] = curl_Hh[] + H[] - H[];
        curl_Hh[] = curl_Hh[] - H[] - H[];

        curl_Hh[] = curl_Hh[] + H[] - H[];
        curl_Hh[] = curl_Hh[] + H[] - H[];

        return curl_Hh;
    }



};


#endif //S6_APP1_TRANSLATE_PYTIN_H
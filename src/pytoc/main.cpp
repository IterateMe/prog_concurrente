#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <thread>
#include <stdlib.h>
#include <mutex>
#include <condition_variable>
#include <tuple>
#include <future>

namespace src{
    
    class Matrix
    {
    private:
        std::vector<float> DATA;
        int X;
        int Y;
        int Z;
        int A;

    public:
        Matrix(int x, int y, int z, int a){
            X = x;
            Y = Y;
            Z = z;
            A = a;
            int length = x*y*z*a;
            std::vector<float> data(length, 0);
            DATA = data;
        }

        Matrix(int x, int y, int z, int a, std::vector<float> data){
            X = x;
            Y = Y;
            Z = z;
            A = a;
            int length = x*y*z*a;
            if(data.size() == length){
                DATA = data;
            }else{
                std::cout << "ERROR - Length doesn t fit the x-y-z-a args" << std::endl;
            }
        }

        std::vector<float> slice4d(std::tuple<int, int> Xslice, 
                        std::tuple<int, int> Yslice,
                        std::tuple<int, int> Zslice,
                        int Aslice){
            //Initier le vecteur avec des 0
            int temp_vec_length = (std::get<1>(Xslice)-std::get<0>(Xslice))*(std::get<1>(Yslice)-std::get<0>(Zslice))*(std::get<1>(Zslice)-std::get<0>(Zslice));
            std::vector<float> temp_vec(temp_vec_length, 0);

            //Verifier les dimensions demandees en slice
            
            //Executer la slice
            for(int x=std::get<0>(Xslice); x < X+std::get<1>(Xslice); x++){
                for(int y=std::get<0>(Yslice); y < Y+std::get<1>(Yslice); y++){
                    for(int z=std::get<0>(Zslice); x < Z+std::get<1>(Zslice); z++){
                        //slicing
                        // A completer -> Remplir le vecter
                    }
                }
            }
            return temp_vec;
        }

        std::tuple<Matrix> timestep(Matrix E, Matrix H, int source_pos, int source_val){
            // A completer
        }

    };

    std::vector<float> vec_op_E(std::tuple<int> range,
                            std::vector<float> a0,
                            std::vector<float> a1,
                            std::vector<float> b0,
                            std::vector<float> b1,
                            std::vector<float> c0,
                            std::vector<float> c1,
                            std::vector<float> d0,
                            std::vector<float> d1,
                            std::vector<float> e0,
                            std::vector<float> e1,
                            std::vector<float> f0,
                            std::vector<float> f1){
        //Addition et soustractions element par element avec for loop

    }

    Matrix curl_E(Matrix E){
        Matrix CURL_E = Matrix(100,100,100,3);
        std::vector<float> A0 = E.slice4d({0,0},{1,0},{0,0},2);
        std::vector<float> A1 = E.slice4d({0,0},{0,-1},{0,0},2);

        std::vector<float> B0 = E.slice4d({0,0},{0,0},{1,0},1);
        std::vector<float> B1 = E.slice4d({0,0},{0,0},{0,-1},1);


        std::vector<float> C0 = E.slice4d({0,0},{0,0},{0,1},0);
        std::vector<float> C1 = E.slice4d({0,0},{0,0},{0,-1},0);

        std::vector<float> D0 = E.slice4d({1,0},{0,0},{0,0},2);
        std::vector<float> D1 = E.slice4d({-1,0},{0,0},{0,0},2);


        std::vector<float> E0 = E.slice4d({1,0},{0,0},{0,0},1);
        std::vector<float> E1 = E.slice4d({0,-1},{0,0},{0,0},1);

        std::vector<float> F0 = E.slice4d({0,0},{1,0},{0,0},0);
        std::vector<float> F1 = E.slice4d({0,0},{0,-1},{0,0},0);

        // Separer les donnees en 4 pour additionner et soustraire
        int vec_size = A0.size();
        int quarter = vec_size / 4;
        std::thread first(vec_op_E, (0,quarter), A0, A1, B0, B1, C0, C1, D0, D1, E0, E1, F0, F1);
        std::thread second(vec_op_E, (quarter+1,2*quarter), A0, A1, B0, B1, C0, C1, D0, D1, E0, E1, F0, F1);
        std::thread third(vec_op_E, (2*quarter+1,3*quarter), A0, A1, B0, B1, C0, C1, D0, D1, E0, E1, F0, F1);
        std::thread forth(vec_op_E, (3*quarter+1,vec_size), A0, A1, B0, B1, C0, C1, D0, D1, E0, E1, F0, F1);

        first.join();
        second.join();
        third.join();
        forth.join();

        // Ajouts et soustractions comme dans le code python (operations += et -=)

        // retourner la matrice resultante
        return CURL_E;
    }

    std::vector<int> curl_H(Matrix H){
        //Logique similaire à curl_E
        
    }

    class WaveEquation
    {
        private:
            Matrix E = Matrix(100,100,100,3);
            Matrix H = Matrix(100,100,100,3);
            int courant_nbr;
        public:
            WaveEquation(int courant){
                courant_nbr = courant;
            }

            void source(int index){
                std::tuple<int> var1 = (1,2);
                // A completer
            }

            void call(){
                // A completer
            }
        
    };
}

int main(int argc, char** argv)
{
    using namespace src;

    // A completer
    
}
#ifndef estoque_h
#define estoque_h
#include <vector>
#include <iostream>
#include "produto.hpp"

class estoque{
    private:
        vector <produto> lista;
    public:
        void add_estoque(produto prod){
              lista.push_back(prod);  
        }

};


#endif
#ifndef produto_h
#define produto_h
#include <string>
#include <iostream>
#include "cliente.hpp"
using namespace std;

class produto{
  private:
    string modelo;
    string marca;
    int numero_calcado;
    string cor;
    int codigo_produto;
    double preco;
  public:
    produto(){

    }
    void set_modelo(){

    }
    void set_marca(){

    }
    void set_numero_calcado(){

    }
    void set_cor(){

    }
    void set_codigo_produto(){

    }
    void set_preco(){

    }
    string get_modelo(){ return modelo;}
    string get_marca(){ return marca;}
    int get_numero_calcado(){ return numero_calcado;}
    string get_cor(){ return cor;}
    int get_codigo_produto(){return codigo_produto; }
    double get_preco(){ return preco;}

    void verificar(){

    }
    void info_prod(){
      cout << "produto: "<<modelo<<endl;
      cout << "marca: "<<marca<<endl;
      cout << "numero do calçado: "<<numero_calcado<<endl;
      cout << "cor: "<<cor<<endl;
      cout << "preço: "<<preco<<endl;
    }
}; 


#endif
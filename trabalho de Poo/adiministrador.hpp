#ifndef administrador_h
#define administrador_h
#include "ususario.hpp"
#include <string>
#include "estoque.hpp"
using namespace std;


class adm: public usuario{
  private: 
  string nome;
  estoque estoque_calcado;
  static int id;
  public:
    adm(string email,string senha):usuario(email,senha,1){
      cout<<"nome completo ";
      cin>>nome;
      id++;
    }
    void add_estoque(produto prod){
      estoque_calcado.add_estoque(prod);
    }
}; 

int adm::id=0;
#endif
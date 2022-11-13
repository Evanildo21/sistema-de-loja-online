#ifndef administrador_h
#define administrador_h
#include "usuario.hpp"
#include <string>

using namespace std;


class adm: public usuario{
  private: 
  static int id;
  public:
    adm(string nome=" ",string email="",string senha=""):usuario(nome,email,senha,2){
     
      cout<<"seja bem vindo "<<nome;
    }
    void add_novo_produto(){
      estoque_calcado.cadastrar_new_prod();
    }
    void add_new_quantidade_produto(){
      int identificador;
      int new_quantidade;
      cout<<"digite o codigo do produto"<<endl;
      cin>>identificador;
      cout<<"digite a nova quantidade de produtos"<<endl;
      cin>> new_quantidade;
      estoque_calcado.add_estoque(identificador,new_quantidade);
    }
  
 
}; 

int adm::id=0;
#endif
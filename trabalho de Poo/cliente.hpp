#ifndef cliente_h
#define cliente_h
#include "usuario.hpp"

using namespace std;

class cliente: public usuario{
  private: 
    carrinho meu_carrinho;
    
  public:
    cliente(string nome=" ",string email=" ",string senha=" "):usuario(nome,email,senha,1){
      
      cout<<"seja bem vindo "<<nome;
  }
  void new_pedido(int codigo,int quantidade){
       estoque_calcado.remover_estoque(codigo,quantidade,&meu_carrinho);
  }
  void lista_produto(){
        
         meu_carrinho.lista_de_produtos_no_carrinho();
  }
  carrinho * get_carrinho(){
       return &meu_carrinho;}
  int num_pedidos(){
    return meu_carrinho.get_numero_de_pedidos();
  }
}; 


#endif
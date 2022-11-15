#ifndef carrinho_h
#define carrinho_h
#include "produto.hpp"
#include <queue>
using namespace std;


class carrinho{
  private: 
  static int numero_de_pedidos;
  vector <produto*> compras;
  vector <int> qtd_pedido;
  public:
    void add_carrinho(produto *prod,int quantidade){
        numero_de_pedidos++;
        compras.push_back(prod);
        qtd_pedido.push_back(quantidade);
    }
    void lista_de_produtos_no_carrinho(){
      
      for(int i=0; i<compras.size();i++){
        cout<<"-------------------------------"<<endl;
        cout<< " quantidade de pedido "<<qtd_pedido[i]<<endl;
        compras[i]->info_prod();
        cout<<"endereço para entrega: "<<compras[i]->get_endereco();
        cout<<endl;
      }
    }
    void remover_pedido(int id,vector<produto*> &fila){
      for(int i=0;i<compras.size();i++){
          if(id==compras[i]->get_codigo_produto()){
              fila.push_back(compras[i]);
            compras.erase (compras.begin()+ i);
          }
      }
    }
    int get_numero_de_pedidos(){return numero_de_pedidos;}
    
}; 
int carrinho::numero_de_pedidos=0;

#endif
#ifndef carrinho_h
#define carrinho_h
#include "produto.hpp"

using namespace std;


class carrinho{
  private:  
  vector <produto*> compras;
  vector <int> qtd_pedido;
  public:
    void add_carrinho(produto *prod,int quantidade){
        compras.push_back(prod);
        qtd_pedido.push_back(quantidade);
    }
    void lista_de_produtos_no_carrinho(){
      
      for(int i=0; i< compras.size();i++){
        cout<<"-------------------------------"<<endl;
        cout<< " quantidade de pedido "<<qtd_pedido[i]<<endl;
        compras[i]->info_prod();
        cout<<endl;
      }
    }
    vector <produto*> produtos(){
       return compras;
    }
    vector <int> quantidade_de_pedidos(){
       return qtd_pedido;
    }
}; 


#endif
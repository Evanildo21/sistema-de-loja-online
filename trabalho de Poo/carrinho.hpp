#ifndef carrinho_h
#define carrinho_h
#include "pedido.hpp"
using namespace std;


class carrinho{
  private: 
  static int numero_de_pedidos;
  vector <pedido*> compras;
  vector <pedido*> pedido_aprovados;
  public:
    void add_carrinho(pedido *produto){
      if(produto!= NULL){
        numero_de_pedidos++;
        compras.push_back(produto);}
    }
    void lista_de_produtos_no_carrinho(){
      if(numero_de_pedidos>0){
      for(int i=0; i<compras.size();i++){
        cout<<"-------------------------------"<<endl;
        cout<< " quantidade de pedido "<<compras[i]->get_quantidade_do_pedido()<<endl;
        compras[i]->get_produto()->informaçoes_do_produto();
        compras[i]->info_pedidio();
        cout<<endl;}
      }else{
        cout<<endl<<"voce não tem novos pedidos "<<endl<<endl;
      }
    }
    void lista_de_produtos_aprovados(){
      if(pedido_aprovados.size()>0){
      cout<<"---------pedidos ja aprovados ou entregues----------------"<<endl;
      for(int i=0; i<pedido_aprovados.size();i++){
        cout<<"-------------------------------"<<endl;
        cout<< " quantidade de pedido "<<pedido_aprovados[i]->get_quantidade_do_pedido()<<endl;
        compras[i]->get_produto()->informaçoes_do_produto();
        compras[i]->info_pedidio();
        cout<<endl;}
    }}

    void remover_pedido(int id,vector<pedido*> &fila){
      for(int i=0;i<compras.size();i++){
          if(id==compras[i]->get_produto()->get_codigo_produto()){
              compras[i]->set_status("aprovado");
              fila.push_back(compras[i]);
              pedido_aprovados.push_back(compras[i]);
            compras.erase (compras.begin()+ i);
            numero_de_pedidos--;
          }
      }
    }
    int get_numero_de_pedidos(){return numero_de_pedidos;}
    vector <pedido*> get_lista_aprovada(){return pedido_aprovados;}
}; 
int carrinho::numero_de_pedidos=0;

#endif
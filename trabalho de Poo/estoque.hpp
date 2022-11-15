#ifndef estoque_h
#define estoque_h
#include <vector>
#include <iostream>
#include "carrinho.hpp"

class estoque{
    private:
       vector <produto*> lista;
        static int quantidade_produto_estoque;
        
    public:
        void add_estoque(int id,int quantidade){
         int auxiliar=quantidade_produto_estoque; //recebe a quantidade de podutos no momento
        for(int i=0;i<lista.size();i++){
           if(lista[i]->get_codigo_produto()==id){
             lista[i]->set_quantidade(lista[i]->get_quantidade()+quantidade);
             quantidade_produto_estoque=quantidade_produto_estoque+quantidade;
           }
        }
        if(auxiliar==quantidade_produto_estoque){
           cout<<"produto não encontrado"<<endl;
        }
        }
        void cadastrar_new_prod(){
        lista.push_back(new produto);
        quantidade_produto_estoque=quantidade_produto_estoque+lista[lista.size()-1]->get_quantidade();  
        }
        void numero_total(){
           cout<<"quantidade de produtos no estoque "<<quantidade_produto_estoque<<endl;
        }
        void ver_lista(){
           for(int i=0;i<lista.size();i++){
              cout<<"-------------------------"<<endl;
              lista[i]->info_prod();
              cout<<"quantidade disponivel: "<<lista[i]->get_quantidade()<<endl;
           }
        }
        void remover_estoque(int codigo,int quantidade,carrinho *carrinho_cliente){
            for(int i=0;i<lista.size();i++){
              if((lista[i]->get_codigo_produto()==codigo) && (lista[i]->get_quantidade()>=quantidade)){
                 cout<<"digite o endereço para entrega: "; string endereco; cin>>endereco; lista[i]->set_endereço(endereco);
                 carrinho_cliente->add_carrinho(lista[i],quantidade);
                 quantidade_produto_estoque=quantidade_produto_estoque-quantidade;
                 lista[i]->set_quantidade(lista[i]->get_quantidade()-quantidade);
              }
           }
        }
  
      void verificar_existencia_prod(produto *new_produto){
            for(int i=0;i<=lista.size();i++){
        if(new_produto->get_codigo_produto()==lista[i]->get_codigo_produto()){
             cout<<"oi";
             lista[i]->set_quantidade(lista[i]->get_quantidade()+new_produto->get_quantidade());
             delete new_produto;
        }else{ lista.push_back(new_produto);}
        }
      }
};

int estoque::quantidade_produto_estoque=0;
#endif
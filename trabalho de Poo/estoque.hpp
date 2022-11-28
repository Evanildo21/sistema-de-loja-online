#ifndef estoque_h
#define estoque_h
#include <vector>
#include <iostream>
#include "carrinho.hpp"

class estoque{
    private:
       vector <produto*> lista;
        static int quantidade_produto_estoque;
        static int numero_de_pedidos;
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
         produto *p = verificar_existencia_prod(new produto);
        if(p!=NULL){
        lista.push_back(p);
        quantidade_produto_estoque+=lista[lista.size()-1]->get_quantidade();  
        }
        }
        void numero_total(){
           cout<<"quantidade de produtos no estoque "<<quantidade_produto_estoque<<endl;
        }
        void ver_lista(){
           for(int i=0;i<lista.size();i++){
              cout<<"-------------------------"<<endl;
              lista[i]->informaçoes_do_produto();
              cout<<"quantidade disponivel: "<<lista[i]->get_quantidade()<<endl;
           }
        }
        pedido * remover_estoque(int codigo,int quantidade,pedido *pedido){
            for(int i=0;i<lista.size();i++){
              if((lista[i]->get_codigo_produto()==codigo) && (lista[i]->get_quantidade()>=quantidade)){
                 pedido->new_pedido(lista[i],quantidade);
                 quantidade_produto_estoque-=quantidade;
                 lista[i]->set_quantidade(lista[i]->get_quantidade()-quantidade);
                 numero_de_pedidos++;
                 return pedido;
              }else if((lista[i]->get_codigo_produto()==codigo) && (lista[i]->get_quantidade()<quantidade)){
                 cout<<endl<<"quantidade invalida! "<<endl<<endl;
                  return NULL;
              }
           }
           cout<<endl<<"pedido não encontrado! "<<endl<<endl;
           return NULL;
        }
  
      produto* verificar_existencia_prod(produto *new_produto){
            for(int i=0;i<lista.size();i++){
        if(new_produto->get_codigo_produto()==lista[i]->get_codigo_produto()){
            cout<<"\n\ncodigo do produto já existente!\ndigite outro "<<endl;
               new_produto->set_codigo_produto();
               new_produto = verificar_existencia_prod(new_produto);}
         if((new_produto->get_cor()==lista[i]->get_cor()) &&
            (new_produto->get_marca()==lista[i]->get_marca())&&
            (new_produto->get_modelo()==lista[i]->get_modelo())&&
            (new_produto->get_numero_calcado()==lista[i]->get_numero_calcado())&&
            (new_produto->get_preco()==lista[i]->get_preco())){   
             
               lista[i]->set_quantidade(lista[i]->get_quantidade()+new_produto->get_quantidade());
               quantidade_produto_estoque+=new_produto->get_quantidade();
               delete new_produto;
               return NULL;
        }
        }
            return new_produto;
      }
      
      void set_numero_de_pedido(){ numero_de_pedidos--;}
      int get_numero_de_pedido(){return numero_de_pedidos;}
   
      
      };
int estoque ::numero_de_pedidos=0;
int estoque::quantidade_produto_estoque=0;
#endif
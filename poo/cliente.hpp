#ifndef cliente_h
#define cliente_h
#include "usuario.hpp"
#include "pedido.hpp"
using namespace std;

class cliente: public usuario{
  private: 
    carrinho meu_carrinho;
    
  public:
    cliente(string nome=" ",string email=" ",string senha=" "):usuario(nome,email,senha,1){
      
      cout<<"seja bem vindo "<<nome;
  }
  void new_pedido(int codigo,int quantidade){
       pedido *p =estoque_calcado.remover_estoque(codigo,quantidade,new pedido);
         if(p!=NULL){
         p->set_dono_do_pedido(get_nome());
          meu_carrinho.add_carrinho(p);}
        else{delete p;}
  }
  void lista_produto(){
        
         meu_carrinho.lista_de_produtos_no_carrinho();
  }
  carrinho * get_carrinho(){
       return &meu_carrinho;}

  int num_pedidos(){
    return meu_carrinho.get_numero_de_pedidos();
  }
        void inf(){
        cout<<"----------clientes--------------------"<<endl;
        cout<<"cliente: "<<get_nome()<<" ";
        cout<<"email: "<<get_email()<<" ";
        cout<<"senha: "<<get_senha()<<endl;
    
    }
  void menu_cliene(){
    int comando=0;
    
    while(comando!=4){
        cout<<" menu "<<endl;
        cout<<"[1] ver produtos a venda "<<endl;
        cout<<"[2] fazer um pedido" <<endl;
        cout<<"[3] ver meus pedidos  "<<endl;
        cout<<"[4] sair  "<<endl;
        comando=numero();
        if(comando==1){
            ver_estoque();
        }
        else if(comando==2){
            int codigo_produto; cout<<"codigo do produto: ";codigo_produto=numero();
            int quantidade_produto;cout<<"quantidade de produto: ";quantidade_produto=numero();
           new_pedido(codigo_produto,quantidade_produto);
        }
        else if(comando==3){
             lista_produto();
             meu_carrinho.lista_de_produtos_aprovados();
        }else{
            comando==4;
        }

}}
}; 


#endif
#ifndef administrador_h
#define administrador_h
#include "usuario.hpp"
#include "pedido.hpp"
#include <string>

using namespace std;


class adm: public usuario{
  private: 
  static vector <pedido*> fila_produto;
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
    void ver_encomendas(vector<cliente*> &lista){
        for(int i=0;i<lista.size();i++){
            lista[i]->lista_produto();
        }
      }
    void fila_de_prioridades(vector<cliente*> &lista,int codigo_prod){
          for(int i=0;i<lista.size();i++){
            carrinho *auxiliar = lista[i]->get_carrinho();
            auxiliar->remover_pedido(codigo_prod,fila_produto); 
            }
          }

    void ver_fila(){
      if(fila_produto.size()>0){
      for(int i=0;i<fila_produto.size();i++){
          cout<<"-------------------------------"<<endl;
              // fila_produto[i]->get_produto()->informaçoes_do_produto(); opsional
               cout<<"    informações do pedido: "<<endl;
               fila_produto[i]->info_pedidio();

          cout<<endl;
          cout<<"-------------------------------"<<endl;
      }}else{
        cout<<"não tem produtos na lista "<<endl;
      }
    }
    void remover_da_fila(){
      if(fila_produto.size()>0){  
        fila_produto[0]->set_status("entregue");
        fila_produto.erase (fila_produto.begin());
          cout<<endl;
         cout<<"pedido entregue"<<endl;
    }else{
        cout<<"não tem produtos na lista "<<endl;
      }
    }
       void inf(){
        cout<<"------------adiministradores------------------"<<endl;
         
        cout<<" adiministrador "<<get_nome()<<" ";
        cout<<"email: "<<get_email()<<" ";
        cout<<"senha: "<<get_senha()<<endl;
    
    }
}; 
vector <pedido*> adm::fila_produto;
int adm::id=0;
#endif
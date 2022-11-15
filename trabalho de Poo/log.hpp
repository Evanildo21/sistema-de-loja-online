#ifndef log_h
#define log_h
#include "adiministrador.hpp"
#include "cliente.hpp"
#include "entregador.hpp"

class log{
private:
 vector <adm*> lista_adm;
 vector <cliente*> lista_clientes;
 vector <entregador*> lista_entregador;
public:
  void list_adiministradores(adm *adm){
      lista_adm.push_back(adm);
  }
  void list_cliente(cliente *cliente){      
    lista_clientes.push_back(cliente);
    }
     void list_entregador(entregador *entre){      
    lista_entregador.push_back(entre);
    }
      void inf_entregador(){
        cout<<"----------entregdores--------------------"<<endl;
         for(int i=0;i<lista_entregador.size();i++){
        cout<<"funcionario: "<<lista_entregador[i]->get_nome()<<" ";
        cout<<"email: "<<lista_entregador[i]->get_email()<<" ";
        cout<<"senha: "<<lista_entregador[i]->get_senha()<<endl;
    }}
    void inf_clientes(){
        cout<<"----------clientes--------------------"<<endl;
         for(int i=0;i<lista_clientes.size();i++){
        cout<<"cliente: "<<lista_clientes[i]->get_nome()<<" ";
        cout<<"email: "<<lista_clientes[i]->get_email()<<" ";
        cout<<"senha: "<<lista_clientes[i]->get_senha()<<endl;
    }
    }
       void inf_adm(){
        cout<<"------------adiministradores------------------"<<endl;
         for(int i=0;i<lista_adm.size();i++){
        cout<<" adiministrador "<<lista_adm[i]->get_nome()<<" ";
        cout<<"email: "<<lista_adm[i]->get_email()<<" ";
        cout<<"senha: "<<lista_adm[i]->get_senha()<<endl;
    }
    }

void logim(string email,string senha){
    for(int i=0;i<lista_clientes.size();i++){
            if(i<lista_adm.size()){
            if(email==lista_adm[i]->get_email() && senha==lista_adm[i]->get_senha()){
               if(lista_adm[i]->get_tipo()==2){
                    menu_adm(lista_adm[i]);}
                    }}
            if(i<lista_entregador.size()){
                 if(email==lista_entregador[i]->get_email() && senha==lista_entregador[i]->get_senha()){
               if(lista_entregador[i]->get_tipo()==3){
                    menu_entregador(lista_entregador[i]);}
                    }
            }
            if(email==lista_clientes[i]->get_email() && senha==lista_clientes[i]->get_senha()){
               if(lista_clientes[i]->get_tipo()==1){
                   menu_cliene(lista_clientes[i]);
             
    }}
 }
 }
 bool verifiar(string email,string senha){
           for(int i=0;i<lista_clientes.size();i++){
                if(i<lista_adm.size()){
                if(email==lista_adm[i]->get_email() && senha==lista_adm[i]->get_senha()){
                    return true;}}
                if(i<lista_entregador.size()){
                if(email==lista_entregador[i]->get_email() && senha==lista_entregador[i]->get_senha()){
                    return true;}}
                if(email==lista_clientes[i]->get_email() && senha==lista_clientes[i]->get_senha()){
                   return true;}}
            return false;
 }

void menu_adm(adm *auxiliar){
    int comando=0;
    while(comando!=6){
        cout<<" menu "<<endl;
        cout<<"[1] cadastrar novos produtos  "<<endl;
        cout<<"[2] adicionar produtos "<<endl;
        cout<<"[3] ver todos os produto do estoque " <<endl;
        cout<<"[4] ver encomendas  "<<endl;
        cout<<"[5] cadastrar funcionario "<<endl;
        cout<<"[6] sair"<<endl;
        cin>>comando;
        if(comando==2){
            auxiliar->add_new_quantidade_produto();
        }
        else if(comando==3){
           auxiliar->estoque_calcado.numero_total();
           auxiliar->ver_estoque();
        }
        else if(comando ==1){
            auxiliar->add_novo_produto();
        }
        else if(comando ==5 ){
           cout<<endl;
            cout<<"digite para cadastrar"<<endl;
            cout<<"[1] entregador "<<endl;
            cout<<"[2] adiministrador de sistema "<<endl;
             int instruçao;cin>>instruçao;
             if(instruçao==1){ lista_entregador.push_back(new entregador);
             }else if(instruçao==2){  list_adiministradores(new adm);}
        }
        else if(comando==4){
            int instruçao=0;
            auxiliar->ver_encomendas(lista_clientes);
            while(instruçao!=3){
            cout<<endl;
            cout<<"[1] remover uma encomenda "<<endl;
            cout<<"[2] organizar toda a fila de prioridade"<<endl;
            cout<<"[3] voltar ao menu inicial "<<endl;
            cin>>instruçao;
            if(instruçao==1){
                cout<<"digite o codigo do produto ";int cod;cin>>cod;
                auxiliar->fila_de_prioridades(lista_clientes,cod);
            }else if(instruçao==2){
                 for(int i=0;i<=lista_clientes[i]->num_pedidos();i++){
                 cout<<"digite o codigo do produto ";int cod;cin>>cod;
                 auxiliar->fila_de_prioridades(lista_clientes,cod);
                 }
            }else{
                auxiliar->ver_fila();
                instruçao=3;
            }}

        }else if(comando==6){
            
        }
        else{
            comando = 7;
        }

}}
void menu_cliene(cliente *auxiliar){
    int comando=0;
    
    while(comando!=4){
        cout<<" menu "<<endl;
        cout<<"[1] ver produtos a venda "<<endl;
        cout<<"[2] fazer um pedido" <<endl;
        cout<<"[3] ver meus pedidos  "<<endl;
        cout<<"[4] sair  "<<endl;
        cin>>comando;
        if(comando==1){
            auxiliar->ver_estoque();
        }
        else if(comando==2){
            int codigo_produto; cout<<"codigo do produto: "; cin>>codigo_produto;
            int quantidade_produto;cout<<"quantidade de produto: "; cin>>quantidade_produto;
           auxiliar->new_pedido(codigo_produto,quantidade_produto);
        }
        else if(comando==3){
            auxiliar->lista_produto();
        }else{
            comando==4;
        }

}}
        void return_lista_clientes(vector <cliente*> &lista){
                 lista=lista_clientes;
        }
    
void menu_entregador(entregador *auxiliar){
      int comando=0;
    
    while(comando!=3){
        cout<<" menu "<<endl;
        cout<<"[1] ver lista de entregas "<<endl;
        cout<<"[2] remover da lista" <<endl;
        cout<<"[3] sair  "<<endl;
        cin>>comando;
        if(comando==1){
            auxiliar->ver_produtos(lista_adm[0]);
        }else if(comando==2){
            auxiliar->retirar_encomenda(lista_adm[0]);
        }else{
            comando=3;
        }
}}





};


#endif 
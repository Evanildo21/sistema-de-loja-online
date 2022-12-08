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
 static int numero_usuarios;
public:
  void list(adm *adm){
      lista_adm.push_back(adm);
      numero_usuarios++;
  }
  void list(cliente *cliente){      
    lista_clientes.push_back(cliente);
      numero_usuarios++;
    }
     void list(entregador *entre){      
    lista_entregador.push_back(entre);
      numero_usuarios++;
    }
      
         

void logim(string email,string senha){
    for(int i=0;i<numero_usuarios;i++){
            if(i<lista_adm.size()){
            if(email==lista_adm[i]->get_email() && senha==lista_adm[i]->get_senha()){
               if(lista_adm[i]->get_tipo()==2){
                    menu_adm(lista_adm[i]);}
                    }}
            if(i<lista_entregador.size()){
                 if(email==lista_entregador[i]->get_email() && senha==lista_entregador[i]->get_senha()){
               if(lista_entregador[i]->get_tipo()==3){
                lista_entregador[i]->menu_entregador(lista_adm[0]);}
                    }
            }if(i<lista_clientes.size()){
            if(email==lista_clientes[i]->get_email() && senha==lista_clientes[i]->get_senha()){
               if(lista_clientes[i]->get_tipo()==1){
                   lista_clientes[i]->menu_cliene();
               }
    }}
 }
 }
 bool verifiar(string email,string senha){
           for(int i=0;i<numero_usuarios;i++){
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
        comando=auxiliar->numero();
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
             int instruçao=auxiliar->numero();
             if(instruçao==1){ lista_entregador.push_back(new entregador);
             }else if(instruçao==2){  list(new adm);}
        }
        else if(comando==4){
            int instruçao =0 ;
            while(instruçao!=4){
            cout<<endl;
            if(lista_clientes[0]->num_pedidos()>0){
            cout<<"[1] ver encomendas"<<endl;
            cout<<"[2] remover uma encomenda "<<endl;
            cout<<"[3] organizar toda a fila de prioridade"<<endl;
            cout<<"[4] voltar ao menu inicial "<<endl;
            int instruçao= auxiliar->numero();
            if(instruçao==1){
             auxiliar->ver_encomendas(lista_clientes);
            }
            else if(instruçao==2){
                cout<<"digite o codigo do produto ";int cod;cod=auxiliar->numero();
                auxiliar->fila_de_prioridades(lista_clientes,cod);
            }else if(instruçao==3){
                 for(int i=0;i<lista_clientes[i]->num_pedidos();i++){
                 cout<<"digite o codigo do produto ";int cod;cod=auxiliar->numero();
                 auxiliar->fila_de_prioridades(lista_clientes,cod);
                 }
            }else{
                auxiliar->ver_fila();
                instruçao=4;
            }}else{
                cout<<endl<<"não tem encomendas"<<endl<<endl;
                 instruçao=4;
            }}

        }else if(comando==6){
            
        }
        else{
            comando = 7;
        }

}}

        void return_lista_clientes(vector <cliente*> &lista){
                 lista=lista_clientes;
        }
    



       int numero_de_ususario(){return numero_usuarios;}
 
       void info(){
           for(int i=0;i<=numero_usuarios;i++){
            if(lista_clientes.size()>i){
                lista_clientes[i]->inf();
            }
            if(lista_adm.size()>i){
                lista_adm[i]->inf();
            }
            if(lista_entregador.size()>i){
                lista_entregador[i]->inf();
            }

           }
       }
};

int log::numero_usuarios=0;
#endif 
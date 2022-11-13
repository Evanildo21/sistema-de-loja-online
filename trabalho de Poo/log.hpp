#ifndef log_h
#define log_h
#include "adiministrador.hpp"
#include "cliente.hpp"

class log{
private:
 vector <adm*> lista_adm;
 vector <cliente*> lista_usuario;
public:
  void list_adiministradores(adm *adm){
      lista_adm.push_back(adm);
  }
  void list_cliente(cliente *cliente){      
    lista_usuario.push_back(cliente);
    }
    void inf_clientes(){
        cout<<"------------------------------"<<endl;
         for(int i=0;i<lista_usuario.size();i++){
        cout<<lista_usuario[i]->get_nome()<<" ";
        cout<<lista_usuario[i]->get_email()<<" ";
        cout<<lista_usuario[i]->get_senha()<<endl;
    }
    }
       void inf_adm(){
        cout<<"------------------------------"<<endl;
         for(int i=0;i<lista_adm.size();i++){
        cout<<lista_adm[i]->get_nome()<<" ";
        cout<<lista_adm[i]->get_email()<<" ";
        cout<<lista_adm[i]->get_senha()<<endl;
    }
    }

void logim(string email,string senha){
    for(int i=0;i<=lista_usuario.size();i++){
            if(email==lista_adm[i]->get_email() && senha==lista_adm[i]->get_senha()){
               if(lista_adm[i]->get_tipo()==2){
                    menu_adm(lista_adm[i]);break;}
                    }

            if(email==lista_usuario[i]->get_email() && senha==lista_usuario[i]->get_senha()){
               if(lista_usuario[i]->get_tipo()==1){
                   menu_cliene(lista_usuario[i]);break;
             
    }}
 }
 }
 bool verifiar(string email,string senha){
           for(int i=0;i<=lista_usuario.size();i++){
                if(email==lista_adm[i]->get_email() && senha==lista_adm[i]->get_senha()){
                    return true;}
                if(email==lista_usuario[i]->get_email() && senha==lista_usuario[i]->get_senha()){
                   return true;}}
            return false;
 }

void menu_adm(adm *auxiliar){
    int comando=0;
    while(comando!=5){
        cout<<" menu "<<endl;
        cout<<"[1] adicionar produtos "<<endl;
        cout<<"[2] ver todos os produto do estoque " <<endl;
        cout<<"[3] cadastrar novos produtos  "<<endl;
        cout<<"[4] cadastrar novos adiministradores "<<endl;
        cout<<"[5] sair  "<<endl;
        cin>>comando;
        if(comando==1){
            auxiliar->add_new_quantidade_produto();
        }
        else if(comando==2){
           auxiliar->estoque_calcado.numero_total();
           auxiliar->ver_estoque();
        }
        else if(comando ==3){
            auxiliar->add_novo_produto();
        }
        else if(comando ==4 ){
            list_adiministradores(new adm);
        }
        else{
          comando=5;
        }

}}
void menu_cliene(cliente *auxiliar){
    int comando;
    
    while(comando!=5){
        cout<<" menu "<<endl;
        cout<<"[1] ver produtos a venda "<<endl;
        cout<<"[2] fazer um pedido" <<endl;
        cout<<"[3] sair  "<<endl;
        cin>>comando;
        if(comando==1){
            auxiliar->ver_estoque();
        }
        if(comando==2){
            int codigo_produto;
            int quantidade_produto;
           auxiliar->new_pedido(codigo_produto,quantidade_produto);
        }
        else{
            comando=5;
        }

}}
    
    
};


#endif 
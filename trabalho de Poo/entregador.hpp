#ifndef entregador_h
#define entregador_h
#include "estoque.hpp"
#include "adiministrador.hpp"

using namespace std;
class entregador:public usuario{
private:
 
public:
    entregador(string nome=" ",string email=" ",string senha=" "):usuario(nome,email,senha,3){
        cout<<" seja bem vindo ";
    }
    void ver_produtos(adm *administrador){
    administrador->ver_fila();  
    }
    void retirar_encomenda(adm *administrador){
     administrador->remover_da_fila();
     
    }
     void inf(){
        cout<<"----------entregdores--------------------"<<endl;
        cout<<"funcionario: "<<get_nome()<<" ";
        cout<<"email: "<<get_email()<<" ";
        cout<<"senha: "<<get_senha()<<endl;
    }
    void menu_entregador(adm *auxiliar){
      int comando=0;
    
    while(comando!=3){
        cout<<" menu "<<endl;
        cout<<"[1] ver lista de entregas "<<endl;
        cout<<"[2] remover da lista" <<endl;
        cout<<"[3] sair  "<<endl;
        comando=numero();
        if(comando==1){
            ver_produtos(auxiliar);
        }else if(comando==2){
            retirar_encomenda(auxiliar);
        }else{
            comando=3;
        }
}}
};



#endif
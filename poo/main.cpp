
#include <iostream>
#include "cliente.hpp"
#include "log.hpp"
#include <stdexcept>


using namespace std;


int main(){ 
      
    string email,senha;
    log login;
    adm *a= new adm("evanildo","evanildo@.com","12345");
    cliente *c= new cliente("rafael","rafa@.com","67891");
    entregador *e =new entregador("ricardo","r@.com","13579");
    login.list(a);
    login.list(c);
    login.list(e);
    int comando;
    do{
        
        cout<<endl;cout<<"__________________"<<endl;
        cout<<" loja de calçados "<<endl;
        cout<<"__________________"<<endl;
        cout<<"   menu  "<<endl;
        cout<<"[1] login "<<endl;
        cout<<"[2] novo usuario "<<endl;
        cout<<"[3] sair "<<endl;
        comando = a->numero();
        cout<<endl;
        if(comando==1){
           login.info();
            cout<<"email: "<<endl; cin>> email;
            cout<<"senha: "<<endl; cin>> senha;
            if(login.verifiar(email,senha)){
            login.logim(email,senha);
                    cout<<"volte sempre";
            }else{
                cout<<"email ou senha invalido! "<<endl;
            }
           
            
         }if(comando==2){
             
            login.list(new cliente);}
        if(comando >3){
            cout<<" erro! "<<endl;
        }}while (comando != 3);

    return 0;
}




#include <iostream>
#include <string>
#include <vector>
#include "cliente.hpp"
#include "log.hpp"
#include "adiministrador.hpp"

using namespace std;


int main(){ 
      int comando;
    string email,senha;
    log login;
    adm *a= new adm("evanildo","evanildo@.com","12345");
    cliente *cli= new cliente("rafael","rafa@.com","67891");
    login.list_adiministradores(a);
    login.list_cliente(cli);
    while (true)
    {
        
        cout<<" loja de calçados "<<endl;
        cout<<"   menu  "<<endl;
        cout<<"[1] login "<<endl;
        cout<<"[2] novo usuario "<<endl;
        cin>>comando;
        cout<<endl;
        if(comando==1){
            login.inf_adm();
            login.inf_clientes();
            cout<<"email: "<<endl; cin>> email;
            cout<<"senha: "<<endl; cin>> senha;
            if(login.verifiar(email,senha)){
            login.logim(email,senha);
                    cout<<"volte sempre";
            }
           
            
         }
         if(comando==2){
             
            login.list_cliente(new cliente);}}

    return 0;
}



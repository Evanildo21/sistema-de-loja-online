#ifndef usuario_h
#define usuario_h
#include <iostream>
#include <string>
#include <vector>
#include "estoque.hpp"
using namespace std;

class usuario{
  private: 
    int tipo; 
    string nome;
    static int id_usuario;
    string email;
    string senha; 
  public:
      static estoque estoque_calcado;
    usuario(string nome=" ",string email=" ",string senha=" ",int tipo = 0){

         set_nome(nome);
         set_email(email);
         set_senha(senha);
         id_usuario++;
         this->tipo = tipo;
    }
    void set_nome(string nome){
          if(nome.size()>4){
            this->nome=nome;
          }
          else{
            cout<<"nome: ";cin>>nome;
            set_nome(nome);
          }
    }
    void set_email(string email){
       int cont=0;
       for(int i=0;i<email.size();i++){
         if((email[i]=='@')||(email[i]=='.')||(email[i]=='c')||(email[i]=='o')||(email[i]=='m')){
              cont++;
         }
       }
       if(cont>=4){
         this->email=email;
       }else{
         cout<<"email: ";cin>>email;set_email(email);
       }

    }
    void set_senha(string senha){
      if(senha.size()>4){
        this->senha=senha;
      }else{
        cout<<"senha: ";cin>>senha;set_senha(senha);
      }

    }
    string get_email(){ return email;}
    string get_senha(){return senha;}
    string get_nome(){return nome;}
    int get_tipo(){return tipo;}
    void ver_estoque(){
     estoque_calcado.ver_lista();
    }
   
}; 
int usuario::id_usuario=0;
estoque usuario::estoque_calcado;

#endif
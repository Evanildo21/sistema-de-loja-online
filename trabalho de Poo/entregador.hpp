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
         cout<<endl;
         cout<<"pedido entregue"<<endl;
    }

};



#endif
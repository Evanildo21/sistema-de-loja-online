#ifndef pedido_h
#define pedido_h
#include "produto.hpp"
#include "iostream"
using namespace std;
class pedido{
private:
 string dono_do_pedido;
 string endereço;
 string status;
 produto *prod;
 int quantidade_pedido;
 double preco_do_pedido;
 public:
  void set_endereço(){
        string cidade; cin.ignore(); getline(cin,cidade);
        if((cidade!="")&&(cidade.size()>4)){
                endereço=cidade;
        }else{
            cout<<"endereço invalido! "<<endl;
            set_endereço();
        }
    }
    void new_pedido(produto *produto,int quantidade){
        prod=produto;
        quantidade_pedido= quantidade;
        dono_do_pedido= " ";
        status = "andamento ";
        preco_do_pedido = produto->get_preco()*quantidade;
        cout<<"endereço de entrega? "<<endl;set_endereço();
        
    }
    produto * get_produto(){return prod;}
    void set_status(string status){
        this->status = status;
    }
     string get_endereco(){return endereço;}
     void set_dono_do_pedido(string nome){
            dono_do_pedido=nome; }

     string get_dono_do_pedido(){return dono_do_pedido;}
     int get_quantidade_do_pedido(){return quantidade_pedido;};
     void info_pedidio(){
            cout<<"----------------------------------------"<<endl;
            cout<<"cliente: "<<dono_do_pedido<<endl;
            cout<<"status atual: "<<status<<endl;
            cout<<"preco total do pedido: "<<preco_do_pedido<<" R$"<<endl;
            cout<<"endereço de entrega: "<<endereço<<endl;
              
    }
};



#endif



#ifndef cliente
#define cliente
#include "ususario.hpp"
#include "produto.hpp"
#include "carrinho.hpp"
using namespace std;

class cliente: public usuario{
  private: 
    string nome;
    static int id_usuario;
    carrinho x;
    produto prod;

  public:

}; 

int cliente::id_usuario=0;
#endif
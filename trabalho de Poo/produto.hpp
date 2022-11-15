#ifndef produto_h
#define produto_h

using namespace std;

class produto{
  private:
    int quantidade;
    string modelo;
    string marca;
    int numero_calcado;
    string cor;
    int codigo_produto;
    double preco;
    string endereço;
  public:
    produto(){
        cout<<"codigo do produto"<<endl; cin>> codigo_produto;
        cout<<"tipo de calçado "<<endl; cin>>modelo;
        cout<<"marca "<<endl; cin>>marca;
        cout<<"numero do calçado "<<endl; set_numero_calcado();
        cout<<"cor "<<endl; cin>>cor;
        cout<<"preço "<<endl; cin >> preco;
        cout<<"quantidade "; cin>>quantidade;
        
    }
    void set_cor(){

    }
    void set_numero_calcado(){
      int numero;
      cin>>numero;
      if(numero>10){
        if(numero%2==0){
          numero_calcado=numero-1;
        }else{
           numero_calcado=numero;
        }

      }
    }
    void set_codigo_produto(){

    }
    void set_preco(){

    }
    void set_endereço(string cidade){
        if((cidade!="")&&(cidade.size()>4)){
                endereço=cidade;
        }
    }
    string get_modelo(){ return modelo;}
    string get_marca(){ return marca;}
    int get_numero_calcado(){ return numero_calcado;}
    string get_cor(){ return cor;}
    int get_codigo_produto(){return codigo_produto; }
    double get_preco(){ return preco;}
    int get_quantidade(){return quantidade;}
    string get_endereco(){return endereço;}
    void set_quantidade(int new_quantidade){
      if(new_quantidade>=0){
      quantidade=new_quantidade;}
    }
    
    void info_prod(){
              cout<<"codigo: "<<get_codigo_produto()<<endl;
              cout<<"produto: "<<get_modelo()<<endl;
              cout<<"marca: "<<get_marca()<<endl;
              cout<<"numero calçado: "<<get_numero_calcado()<<"-"<<get_numero_calcado()+1<<endl;
              cout<<"cor: "<<get_cor()<<endl;
              cout<<"valor: "<<get_preco()<<endl;
              
    }
}; 


#endif
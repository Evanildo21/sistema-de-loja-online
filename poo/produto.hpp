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
   
  public:
    produto(){
        cout<<"codigo do produto"<<endl;set_codigo_produto();
        cout<<"tipo de calçado "<<endl; cin>>modelo;
        cout<<"marca "<<endl; set_marca();
        cout<<"numero do calçado "<<endl; set_numero_calcado();
        cout<<"descriçao(cor,formato...) "<<endl; set_cor();
        cout<<"preço "<<endl; cin >> preco;
        cout<<"quantidade "<<endl; set_quantidade();
        
    }
    void set_cor(){
      string aux;
      cin.ignore();
      getline(cin,aux);
      if(aux!=" "){
        cor=aux;
      }else{
        set_cor();
      }
    }
     void set_marca(){
      string auxiliar;
      cin.ignore();
      getline(cin,auxiliar);
      if(auxiliar!=" "){
        marca=auxiliar;
      }else{
        set_marca();
      }
    }
     void set_modelo(){
      string auxiliar;
      cin.ignore();
      getline(cin,auxiliar);
      if(auxiliar!=" "){
        cor=auxiliar;
      }else{
        set_modelo();
      }
    }
    void set_numero_calcado(){
      int Numero= numero();
      if(Numero){
        if(Numero>10){
            if(Numero%2==0){numero_calcado=Numero-1;}
            else{numero_calcado=Numero;}}
        else{
            cout<<"numero invalido!\n digite outro"<<endl;
            set_numero_calcado();}}
      else{set_numero_calcado();}

      
    }
    int numero(){
      string codigo;cin>>codigo;
      string numero="0123456789";
      int contador=0;
      for(int i=0;i<codigo.size();i++){
      for(int j=0;j<numero.size();j++){
        if(codigo[i]==numero[j]){
              contador++;
        }
      }
      }
      if(contador==codigo.size()){
      return  atoi(codigo.c_str());}
      cout<<"\nerro!!\ndigite um numero: "<<endl;
      return 0;
    }
    void set_codigo_produto(){
      codigo_produto= numero();
      
      if(codigo_produto);
      else{ set_codigo_produto();}
    
    }
    void set_preco(){

    }
  
    void set_quantidade(){
      quantidade=numero();
      if(quantidade);
      else{ set_numero_calcado();}
    }

    string get_modelo(){ return modelo;}
    string get_marca(){ return marca;}
    int get_numero_calcado(){ return numero_calcado;}
    string get_cor(){ return cor;}
    int get_codigo_produto(){return codigo_produto; }
    double get_preco(){ return preco;}
    int get_quantidade(){return quantidade;}
  
    void set_quantidade(int new_quantidade){
      if(new_quantidade>=0){
      quantidade=new_quantidade;}
    }
    
    void informaçoes_do_produto(){
              cout<<"codigo: "<<get_codigo_produto()<<endl;
              cout<<"produto: "<<get_modelo()<<endl;
              cout<<"marca: "<<get_marca()<<endl;
              cout<<"numero calçado: "<<get_numero_calcado()<<"-"<<get_numero_calcado()+1<<endl;
              cout<<"cor: "<<get_cor()<<endl;
              cout<<"valor: "<<get_preco()<<endl;
              
    }
}; 


#endif
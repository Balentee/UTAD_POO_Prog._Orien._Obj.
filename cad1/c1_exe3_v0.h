#define DATA_H

#include <iostream>

class Data{
private:
   int dia;
   int mes;
   int ano;

public:
    //Construtor padrão (sem parametros)
    Data() : dia{1}, mes{1}, ano{2023} {};
    //Construtor com parametrização
    Data(int d, int m, int a) : dia(d), mes(m), ano(a) {};
    // Destructor
    //virtual ~Data();

    //inline: -> que vai estar definido e implementado diretamente (ajuda na performance, nao necessario)
    //no .h. quando os métodos são bastante simples
    inline void SetDia (int d){
        dia = d;
    }
    inline void SetMes (int m){
        mes = m;
    }
    inline void SetAno (int a){
            ano = a;
        }
    inline int GetDia (){
            return dia;
        }
    inline int GetMes (){
            return mes;
        }
    inline int GetAno (){
            return ano;
        }
    void Show(){
        std::cout << GetDia() << "/" << GetMes() << "/" << GetAno() << std::endl;
    }   
    void Update(int d, int m, int a){
        SetDia(d);
        SetMes(m);
        SetAno(a);
    }

    /*Implemente para a classe Data o método Igual() para verificar se dois objectos do tipo
    Data são iguais. O método deve devolver true se forem iguais e false caso contrário.*/
    bool Igual(Data x){
        if(x.ano != GetAno() || x.mes != GetMes() || x.dia != GetDia()){
            //std::cout << "false\n\n";    //debug 
            return(false);
        }else {
            //std::cout << "true\n\n";     //debug
            return(true);
        }
    }
    /*Verifique se dois objectos do tipo Data são iguais fazendo a sobrecarga do operador “==”.*/
    bool operator==(Data x){
        if(x.ano != GetAno() || x.mes != GetMes() || x.dia != GetMes()){
            //std::cout << "false\n\n";    //debug 
            return(false);
        }else {
            //std::cout << "true\n\n";     //debug
            return(true);
        }
    }
    /*Implemente a sobrecarga dos operadores “!=”, “<<” e “>>”.*/
    bool operator!=(Data x){
        if(x.ano != GetAno() || x.mes != GetMes() || x.dia != GetDia()){
            //std::cout << "false\n\n";    //debug 
            return(true);
        }else {
            //std::cout << "true\n\n";     //debug
            return(false);
        }
    }

    friend ostream & operator << (ostream &os, Data data);
    friend istream & operator >> (istream &is, Data &data);
    //int fok();
};
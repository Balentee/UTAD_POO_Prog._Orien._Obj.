#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <fstream>

using namespace std;

class Data{
private:
   int dia;
   int ano;
   int mes;

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
        std::cout << GetDia() << "/" << GetMes() << "/" << GetAno();
    }    
    void Update(int d, int m, int a){
        SetDia(d);
        SetMes(m);
        SetAno(a);
    }
    bool Igual(Data x);
    bool operator==(Data x);
    bool operator!=(Data x);

    friend ostream & operator << (ostream &os, Data data);
    friend istream & operator >> (istream &is, Data &data);
    
    void SaveFile(ofstream& os);
    void ReadFile(ifstream& is);
};
#endif
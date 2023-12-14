#ifndef PESSOA_H
#define PESSOA_H
#include <iostream> // Input/Output
#include <iomanip> // Formatting
#include <fstream > // Filestreams
#include "Data.h" // classe Data

using namespace std;

class Pessoa{
private:
    string nome;
    Data data;
    string morada;
public:
    Pessoa(): nome{"empty"}, data{01,01,2023}, morada{"empty"} {};
    Pessoa(string n, Data d, string m): nome(n), data(d), morada(m) {};
    inline void SetNome(string n){
        nome = n;
    }
    inline void SetData(Data d){
        data = d;
    }
    inline void SetMorada(string m){
        morada = m;
    }
    inline string GetNome(){
        return nome;
    }
    inline Data GetData(){
        return data;
    }
    inline string GetMorada(){
        return morada;
    }
    void Show();
    void Readk();
    void Savefile(ofstream& os);
    void Readfile(ifstream& is);
    void ReadFilePlus(ifstream& is);
    bool MaisNovo(Pessoa x);
    bool operator ==(Pessoa x);
    bool operator !=(Pessoa x);
    friend ostream& operator <<(ostream& os, Pessoa pessoa);
    friend istream& operator >>(istream& is, Pessoa &pessoa);
};
#endif
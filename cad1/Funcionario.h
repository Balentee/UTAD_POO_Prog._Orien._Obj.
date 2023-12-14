#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Pessoa.h"

class Funcionario: public Pessoa{
private:
    int num_func;
    string setor;
public:
    Funcionario();
    Funcionario(int _num_func, string _setor, string _nome, Data _data, string _morada);
    //set
    inline void SetNumFunc(int _num_func){
        num_func = _num_func;
    }
    inline void SetSector(string _setor){
        setor = _setor;
    }
    //get
    inline int GetNumFunc(){
        return num_func;
    }
    inline string GetSector(){
        return setor;
    }
    //show
    void Show();
    //set funcionario
    void SetFuncionario();
    //sobrecarga >>
    friend istream & operator >> (istream &is, Funcionario &funcionario);
    //savefile
    void Savefile(ofstream &os);
    //readfile
    void Readfile(ifstream &is);
};
#endif
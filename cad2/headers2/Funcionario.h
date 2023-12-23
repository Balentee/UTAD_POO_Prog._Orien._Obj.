#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "C:/Users/Tiago Valente/poo/cad1/headers1/Pessoa.h"

class Funcionario: public Pessoa{
private:
    int num_func;
    string setor;
    float ord_base;
    int h_extra;
    float p_hora_extra; // preço das h extra

public:
    Funcionario();
    Funcionario(int _num_func, string _setor, string _nome, Data _data, string _morada, float _ord_base, int _h_extra, float _p_hora_extra);
    
    //set
    void SetNumFunc(int _num_func){
        num_func = _num_func;
    }
    void SetSector(string _setor){
        setor = _setor;
    }
    void SetOrdBase(float _ord_base){
        ord_base = _ord_base;
    }
    void SetHExtra(int _h_extra){
        h_extra = _h_extra;
    }
    void SetPHExtra(float _p_hora_extra){
        p_hora_extra = _p_hora_extra;
    }
    //get
    int GetNumFunc(){
        return num_func;
    }
    string GetSector(){
        return setor;
    }
    float GetOrdBase(){
        return ord_base;
    }
    int GetHExtra(){
        return h_extra;
    }
    float GetPHExtra(){
        return p_hora_extra;
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
    //exe06 - calcula ordenado
    virtual void Calcula_ordenado() = 0;
};
#endif
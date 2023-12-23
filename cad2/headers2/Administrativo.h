#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Administrativo.cpp"

class Administrativo : public Funcionario{

public:
    Administrativo(int _num_func, string _setor, string _nome, Data _data, string _morada, float _ord_base, int _h_extra, float _p_hora_extra);
    ~Administrativo();
};
#endif
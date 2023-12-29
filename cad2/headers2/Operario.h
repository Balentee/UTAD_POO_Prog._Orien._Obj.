#ifndef OPERARIO_H
#define OPERARIO_H 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Funcionario.h"

class Operario : public Funcionario{
private:
    bool f_turno;
public:
    Operario();
    Operario(int _num_func, string _setor, string _nome, Data _data, string _morada, float _ord_base, int _h_extra, float _p_hora_extra, bool _f_turno);
    inline void SetTurno(bool _f_turno){
        f_turno = _f_turno;
    }
    inline bool GetTurno(){
        return f_turno;
    }
    void Show();
    void SetOperario();
    float Calcula_ordenado();
    void Savefile(ofstream &of);
    void Readfile(ifstream &is);
};

#endif
#ifndef OPERARIO_H
#define OPERARIO_H 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Operario.cpp"

class Operario : public Funcionario{
private:
    bool f_turno;
public:
    Operario();
    Operario(int _num_func, string _setor, string _nome, Data _data, string _morada, float _ord_base, int _h_extra, float _p_hora_extra, bool _f_turno);
    ~Operario();
    inline void SetTurno(bool _f_turno){
        f_turno = _f_turno;
    }
    inline bool GetTurno(){
        return f_turno;
    }
    float Calcula_ordenado();
};

#endif
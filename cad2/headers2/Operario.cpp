#include "Operario.h"

Operario::Operario(){

}

Operario::Operario(int _num_func, string _setor, string _nome, Data _data, string _morada, float _ord_base, int _h_extra, float _p_hora_extra, bool _f_turno) 
  : Funcionario(_num_func, _setor, _nome, _data, _morada, _ord_base, _h_extra, _p_hora_extra){
    f_turno = _f_turno;
}

float Operario::Calcula_ordenado(){
    if(f_turno){
        return GetOrdBase() * 1.25 + GetHorasExtra() + GetPHExtra();
    }else{
        return GetOrdBase() * 1.25 + GetHorasExtra() + GetPHExtra();
    }
}
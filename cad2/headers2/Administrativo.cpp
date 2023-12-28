#include "Administrativo.h"

Administrativo::Administrativo() : Funcionario(){
	SetPHExtra(10);
}

Administrativo::Administrativo(int _num_func, string _setor, string _nome, Data _data, string _morada, float _ord_base, int _h_extra, float _p_hora_extra): Funcionario(_num_func, _setor, _nome, _data, _morada, _ord_base, _h_extra, 10){

}

float Administrativo::Calcula_ordenado(){
	return GetOrdBase() + GetHExtra() * GetPHExtra();
}
#include "Administrativo.h"

Administrativo::Administrativo(int _num_func, string _setor, string _nome, Data _data, string _morada, float _ord_base, int _h_extra, float _p_hora_extra): Funcionario(_num_func, _setor, _nome, _data, _morada, _ord_base, _h_extra, _p_hora_extra){

}

float Administrativo::Calcula_Ordenado()
{
	return GetOrdBase() + GetHExtra() * GetPHExtra();
}
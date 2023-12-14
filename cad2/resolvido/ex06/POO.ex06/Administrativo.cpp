#include "Administrativo.h"



Administrativo::Administrativo(int _num, string _setor, string _nome, string _morada, 
										int _d, int _m, int _a, float _ord, int _hextra)
	: Func(_num, _setor, _nome, _morada, _d, _m, _a, _ord,  _hextra, 10)
{
}

Administrativo::Administrativo()
	: Func()
{
	SetPrecoHorasExtra(10);
}


Administrativo::~Administrativo()
{
}


float Administrativo::Calcula_Ordenado()
{
	return GetOrdBase() + GetHorasExtra() * GetPrecoHorasExtra();
}


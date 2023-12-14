#pragma once
#include "Func.h"
class Administrativo
	:public Func
{
public:
	Administrativo(int _num, string _setor, string _nome, string _morada, int _d, 
												int _m, int _a, float _ord, int _hextra);
	Administrativo();
	~Administrativo();

	float Calcula_Ordenado();
};


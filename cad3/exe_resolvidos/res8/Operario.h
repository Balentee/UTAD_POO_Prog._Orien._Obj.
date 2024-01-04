#pragma once
#include "Func.h"
class Operario
	:public Func
{
private:
	bool f_turno;
public:

	bool GetTurno() { return f_turno; }
	void SetTurno(bool t) { f_turno = t; }

	Operario(int _num, string _setor, string _nome, string _morada, int _d,
		int _m, int _a, float _ord, int _hextra, bool _turno);

	Operario();
	~Operario();
	void Show();
	void ReadK();

	float Calcula_Ordenado();

	void ReadFile(ifstream &is);
	void SaveFile(ofstream &os);
};


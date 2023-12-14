#include "Operario.h"



Operario::Operario(int _num, string _setor, string _nome, string _morada
					, int _d, int _m, int _a, float _ord, int _hextra, bool _turno)

	: Func(_num, _setor, _nome, _morada, _d, _m, _a, _ord, _hextra, 8)
{

	f_turno = _turno;
}

Operario::Operario()
	:Func()
{
	SetPrecoHorasExtra(8);
}


Operario::~Operario()
{
}

float Operario::Calcula_Ordenado()
{
	if (f_turno)
	{
		return GetOrdBase() * 1.25f + GetHorasExtra() * GetPrecoHorasExtra();
	}
	else
	{
		return GetOrdBase()  + GetHorasExtra() * GetPrecoHorasExtra();

	}

}

void Operario::Show()
{
	Func::Show();
	cout << "Em Turno:";
	if (f_turno)
	{
		cout << "Sim;";
	}
	else
	{
		cout << "Não;";
	}
}

void Operario::ReadK() 
{
	Func::ReadK();

	cout << "Trabalha por turno: (S/N)";
	string op;
	cin >> op;
	if (op == "S")
	{
		f_turno = true;
	}
	else
	{
		f_turno = false;
	}
	cin.ignore(INT16_MAX, '\n');
}

void Operario::ReadFile(ifstream & is)
{
	Func::ReadFile(is);

	string turno;
	getline(is, turno, ';');

	if (turno == "sim")
	{
		f_turno = true;			 
	}
	else
	{
		f_turno = false;
	}
}

void Operario::SaveFile(ofstream & os)
{
	Func::SaveFile(os);

	if (f_turno)
	{
		os << "sim;";
	}
	else
	{
		os << "não;";
	}
}

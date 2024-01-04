
#include "Func.h"



Func::Func()
{
}


Func::~Func()
{
}

Func::Func(int _num, string _setor, string _nome,string _morada, Data _data
										, float _ord, int _hextra, float _phoras)
	:Pessoa(_nome, _morada, _data)
{
	setor = _setor;
	num = _num;

	ord_base = _ord;
	h_extra = _hextra;
	p_horas_extra = _phoras;
}

Func::Func(int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a
	, float _ord, int _hextra, float _phoras)
	
	:Pessoa(_nome, _morada, _d, _m, _a)
{
	setor = _setor;
	num = _num;
	ord_base = _ord;
	h_extra = _hextra;
	p_horas_extra = _phoras;
}

void Func::Show(void)
{
	Pessoa::Show();
	cout << "Num:" << num << ";Setor:" << setor 
		<< ";Ordenado Base:" << ord_base
		<< ";Horas Extra:" << h_extra << ";";
}

void Func::ReadK(void)
{
	Pessoa::ReadK();
	cout << "Num:";
	cin >> num;
	cout << "Setor:";
	cin >> setor;

	//extra 
	cout << "Ord Base:";
	cin >> ord_base;

	cout << "Horas Extras";
	cin >> h_extra;
}

/*ostream & operator << (ostream &os, const Func F)
{
	os << (Pessoa &)F;
	os << "Num: " << F.num;
	os << "; Setor: " << F.setor;

	return os;
}
*/

istream & operator >> (istream &is, Func &F)
{
	char aux[100];

	is >> (Pessoa &)F;
	cout << "Num:";
	is >> F.num;
	cout << "Setor:";
	is >> aux;
	F.setor = aux;

	return is;
}

void Func::SaveFile(ofstream &os)
{
	Pessoa::SaveFile(os);
	os << num << ";" << setor <<  ";"<< ord_base << ";" << h_extra << ";";
}

void Func::ReadFile(ifstream &is)
{
	char aux[100];

	Pessoa::ReadFile(is);
	is.getline(aux, 100, ';');
	num = atoi(aux);
	is.getline(aux, 100, ';');
	setor = aux;

	float ord; 
	is >> ord;
	ord_base = ord;  //corrigir erro
	is.ignore(INT16_MAX, ';');

	int h;
	is >> h;
	h_extra = h;
	is.ignore(INT16_MAX, ';');
}

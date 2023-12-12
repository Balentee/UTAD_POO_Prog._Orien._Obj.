#include "Func.h"
Func::Func()
{
}
Func::~Func()
{
}
Func::Func(int _num, string _setor, string _nome,string _morada, Data _data) 
	:Pessoa(_nome, _morada, _data)
{
	setor = _setor;
	num = _num;
}
Func::Func(int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a) :Pessoa(_nome, _morada, _d, _m, _a)
{
	setor = _setor;
	num = _num;
}
void Func::Show(void)
{
	Pessoa::Show();
	cout << "Num:" << num << ";Setor:" << setor << "\n";
}
void Func::ReadK(void)
{
	Pessoa::ReadK();
	cout << "Num:";
	cin >> num;
	cout << "Setor:";
	cin >> setor;
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
	os << num << ";" << setor << "\n";
}
void Func::ReadFile(ifstream &is)
{
	char aux[100];

	Pessoa::ReadFile(is);
	is.getline(aux, 100, ';');
	num = atoi(aux);
	is.getline(aux, 100, '\n');
	setor = aux;
}
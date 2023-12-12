
#include "Pessoa.h"

Pessoa::Pessoa()
{
}

Pessoa::~Pessoa()
{
}

Pessoa::Pessoa(string _nome, string _morada, Data _data)
{
	nome = _nome;
	morada = _morada;
	data = _data;
}

Pessoa::Pessoa(string _nome, string _morada, int _dia, int _mes, int _ano)
{
	nome = _nome;
	morada = _morada;
	data.SetDia(_dia);
	data.SetMes(_mes);
	data.SetAno(_ano);
}

void Pessoa::Show(void)
{
	cout << "Nome: " << nome << "; ";
	cout << "Morada: " << morada << "; ";
	data.Show();
//	cout << "; Data de nascimento: " << data << ";";
}

ostream & operator << (ostream &os, const Pessoa P)
{
	os << "Nome: " << P.nome << "; ";
	os << "Morada: " << P.morada << "; ";
	os << "Data de nascimento: " << P.data;

	return os;
}

istream & operator >> (istream &is, Pessoa &P)
{
	char aux[100];

	cout << "Nome: ";
	is.getline(aux, sizeof aux);
	P.nome = aux;
	cout << "Morada: ";
	is.getline(aux, sizeof aux);
	P.morada = aux;
	cout << "Data de nascimento: ";
	is >> P.data;

	return is;
}

void Pessoa::ReadK(void)
{
	char aux[100];

	cout << "Nome: ";
	cin.getline(aux, sizeof aux);
	nome = aux;
	cout << "Morada: ";
	cin.getline(aux, sizeof aux);
	morada = aux;
	cout << "Data de nascimento: ";
	cin >> data;
}


void Pessoa::SaveFile(ofstream &os)
{
	os << nome << ";" << morada << ";"  << data << ";";
	/*
	os << nome << ";" << morada << ";";
	data.SaveFile(os);
	os<<"\n";
	*/
}

void Pessoa::ReadFile(ifstream &is)
{
	char aux[100];

	is.getline(aux, 100, ';');
	nome = aux;
	is.getline(aux, 100, ';');
	morada = aux;

	data.ReadFile(is);
	//OU
/*	is.getline(aux,10,'/');
	data.SetDia(atoi(aux));
	is.getline(aux,10,'/');
	data.SetMes(atoi(aux));
	is.getline(aux,10,';');
	data.SetAno(atoi(aux));*/
}

bool Pessoa::MaisNovo(Pessoa P)
{
	if (data < P.data)
		return true;
	else
		return false;
}

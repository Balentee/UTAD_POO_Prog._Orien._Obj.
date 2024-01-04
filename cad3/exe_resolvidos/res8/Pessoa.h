#pragma once

#include "Data.h"
#include <string>

class Pessoa
{
private:
	string nome, morada;
	Data   data;

public:
	Pessoa();
	Pessoa(string _nome, string _morada, Data _data);
	Pessoa(string _nome, string _morada, int _dia, int _mes, int _ano);
	virtual ~Pessoa();

	void SetNome(string _nome) { nome = _nome; }
	string GetNome(void) { return nome; }
	void SetMorada(string _morada) { morada = _morada; }
	string GetMorada(void) { return morada; }
	void SetData(Data _data) { data = _data; }
	Data GetData(void) { return data; }

	bool MaisNovo(Pessoa P);
	void Show(void);
	void ReadK(void);

	friend ostream & operator << (ostream &os, const Pessoa P);
	friend istream & operator >> (istream &is, Pessoa &P);

	void SaveFile(ofstream &os);
	void ReadFile(ifstream &is);
};


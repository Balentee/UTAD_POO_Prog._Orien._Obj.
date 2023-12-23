#pragma once

#include "Pessoa.h"
class Func :
	public Pessoa
{
private:
	string setor;
	int num;
public:
	Func();
	Func(int _num, string _setor, string _nome, string _morada, Data _data);
	Func(int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a);
	virtual ~Func();

	void SetNum(int _num) { num = _num; }
	void SetSetor(string _setor) { setor = _setor; }

	int GetNum(void) { return num; }
	string GetSetor(void) { return setor; }

	void Show(void);
	void ReadK(void);

	//friend ostream & operator << (ostream &os, const Func F);
	friend istream & operator >> (istream &is, Func &F);

	void SaveFile(ofstream &os);
	void ReadFile(ifstream &is);

	virtual float Calcula_ordenado();
};


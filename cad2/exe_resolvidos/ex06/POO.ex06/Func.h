#pragma once

#include "Pessoa.h"
class Func :
	public Pessoa
{
private:
	string setor;
	int num;

	float ord_base;
	int h_extra;
	float p_horas_extra;
public:
	Func();
	Func(int _num, string _setor, string _nome, string _morada, Data _data, float _ord, int _hextra, float _phoras);
	Func(int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a, float _ord, int _hextra, float _phoras);
	virtual ~Func();

	float GetOrdBase() { return ord_base; }
	void SetOrdBase(float _ord) { ord_base = _ord; }
	
	float GetPrecoHorasExtra() { return p_horas_extra; }
	void SetPrecoHorasExtra(float _ph) { p_horas_extra = _ph; }

	int GetHorasExtra() { return h_extra; }
	void SetHorasExtra(int _h) { h_extra = _h; }


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

	virtual float Calcula_Ordenado() = 0 ;

};


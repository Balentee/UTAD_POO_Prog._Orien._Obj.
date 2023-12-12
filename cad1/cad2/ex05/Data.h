#pragma once


#include <iostream>
#include <fstream>

using namespace std;

class Data
{
private:
	int ano, mes, dia;

public:
	Data();
	Data(int _dia, int _mes, int _ano);
	virtual ~Data();

	void SetDia(int _dia) { dia = _dia; }
	void SetMes(int _mes) { mes = _mes; }
	void SetAno(int _ano) { ano = _ano; }

	int GetDia(void) { return dia; }
	int GetMes(void) { return mes; }
	int GetAno(void) { return ano; }

	void Show(void);
	void Update(int _dia, int _mes, int _ano);
	bool Igual(const Data data);

	bool operator == (const Data data) const;
	bool operator < (const Data data) const;
	bool operator > (const Data data) const;

	friend ostream & operator << (ostream &os, const Data data);
	friend istream & operator >> (istream &is, Data &data);

	void SaveFile(ofstream &os);
	void ReadFile(ifstream &is);

};


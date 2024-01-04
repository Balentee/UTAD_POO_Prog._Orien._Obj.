#pragma once
#include"Func.h"
#include "Operario.h"
#include "Administrativo.h"
#include<list>

class Gestor_Func
{
private:
	list<Func*> Lista;
public:
	void AdicionarFunc(Func* f);
	bool RemoverFunc(int numF);
	bool RemoverFunc(string Nome);

	void Show();
	void ReadFile();
	void SaveFile();
	Gestor_Func();
	~Gestor_Func();

	friend istream& operator>> (istream& is, Gestor_Func &gf);
	friend ostream& operator<<(ostream& os, Gestor_Func gf);
};


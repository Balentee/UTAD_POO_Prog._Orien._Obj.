#include <iostream>
#include <iomanip>
#include "Gestor_Num.h"

using namespace std;

Gestor_Num::Gestor_Num()
{
	if (!lista.empty())
	{
		lista.clear();
	}
}

Gestor_Num::~Gestor_Num()
{
	if (!lista.empty())
	{
		lista.clear();
	}
}

void Gestor_Num::SetLista(list<int> _lista){
    if (!lista.empty()){
		lista.clear();
	}
	lista = _lista;
}

list<int> Gestor_Num::GetLista(){
    return lista;
}

void Gestor_Num::InserirNum(int num){
    lista.push_back();
    return;
}

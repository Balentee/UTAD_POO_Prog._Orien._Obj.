#include <iostream>
#include <fstream>
#include <list>
#include "C:\Users\Tiago Valente\poo\cad3\headers3\Gestor_Num.h"

using namespace std;

Gestor_Num::Gestor_Num(){
	if (!lista.empty()){
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
    lista.push_back(num);
    return;
}

void Gestor_Num::Remover(int num){
	lista.remove(num);
}

void Gestor_Num::Show(){
	list<int>::iterator i = lista.begin();

	while (i != lista.end()){
		cout << ".." << *i;
		i++;
	};
}

int Gestor_Num::PosicaoNaLista(int num){
	// preciso de ir de elemento em elemento e de ir contando os elementos;
	// quando chegar ao elemento correspondente; retorna contador;
	list<int>::iterator i = lista.begin(); // aponta para primeiro(se adicionar +1 aponta para o segundo)
	int n = -1; // incializa -1 para contar 0 ao começar o ciclo
	while(i != lista.end()){
		n++;
		if(*i == num){
			return n;
		}
		i++;
	}
	return -1;
}
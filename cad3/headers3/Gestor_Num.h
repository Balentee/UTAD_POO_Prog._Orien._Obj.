#ifndef GESTOR_NUM_H
#define GESTOR_NUM_H

#include <list>

using namespace std;

class Gestor_Num{
private:
    list<int> lista;

public:
    //Criar objetos
    Gestor_Num();

    //Metodos acesso
    void SetLista(list<int> _lista);
	list<int> GetLista();

    //a) Inserir um novo número inteiro na lista;
    void InserirNum(int num);
    //b) 
    void Remover(int num);
    //c)
    void Show();
    //d)
    int PosicaoNaLista(int num);
};
#endif
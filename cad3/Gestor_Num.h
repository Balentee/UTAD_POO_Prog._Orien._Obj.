#include <iostream>
#include <iomanip>
#include <list>

class Gestor_Num:{
private:
    list<int> lista;

public:
    //Criar objetos
    Gestor_Num();
    ~Gestor_Num();

    //Metodos acesso
    void SetLista(list<int> _lista);
	list<int> GetLista();

    //a) Inserir um novo número inteiro na lista;
    void InserirNum(int num);
    
};
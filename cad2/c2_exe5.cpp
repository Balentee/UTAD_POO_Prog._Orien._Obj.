#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <unistd.h> //for sleep ;_;
#include "C:/Users/Tiago Valente/poo/cad1/headers1/Funcionario.h"
#include "C:/Users/Tiago Valente/poo/cad1/headers1/Funcionario.cpp"
#include "C:/Users/Tiago Valente/poo/cad1/headers1/Pessoa.h"
#include "C:/Users/Tiago Valente/poo/cad1/headers1/Pessoa.cpp"
#include "C:/Users/Tiago Valente/poo/cad1/headers1/Data.h"
#include "C:/Users/Tiago Valente/poo/cad1/headers1/Data.cpp"

#define new_morada_a "Rua do meio n 4"
#define new_setor_a "Ferragem"

using namespace std;

void Swap(Funcionario *x, Funcionario *y)
{
	Funcionario	aux;

	aux = *x;
	*x = *y;
	*y = aux;
}

void SelectionSort(Funcionario *A, int size)
{
	int i, j, aux;

	for (i = 0; i<size - 1; i++){
		aux = i;
		for (j = i + 1; j<size; j++)
			if ((A + j)->GetData().GetAno() < (A + aux)->GetData().GetAno())
				aux = j;
		Swap(A + aux, A + i);
	}
}

int main(){
    cout << "Exercicio 5\n";
    //Funcionario(int nf, string s, Pessoa p)
    Funcionario a(25023,"Pintura","Joca Gaio", Data(20,9,1987),"Rua da direita n2");
    Funcionario b(25023,"Comercial","Ana Rola",Data(4,2,1990),"Rua da esquerda n3");
    
    cout << "Exercicio 5.5" << endl << endl;
    a.Show();
    cout << endl << endl;
    b.Show();
    cout << endl << endl; system("pause"); system("cls");
    
    cout << "Exercicio 5.6" << endl << endl;
    cout << "Morada do Joca Gaio vai ser alterada para \"" << new_morada_a << "\".\n\n";
    a.SetMorada(new_morada_a);
    a.SetSector(new_setor_a);
    a.Show();
    cout << endl << endl; system("pause"); system("cls");
    
    cout << "Exercicio 5.7" << endl << endl;
    b.SetData(Data(23,2,1990));
    b.Show();
    cout << endl << endl; system("pause"); system("cls");
    
    cout << "Exercicio 5.8" << endl << endl;
    Funcionario c;
    cin >> c;
    cout << endl << endl; system("pause"); system("cls");

    cout << "Exercicio 5.9" << endl << endl;
    Funcionario d;
    d.SetFuncionario();
    system("cls"); cout << "Exercicio 5.9" << endl << endl << "Novo Utilizador Criado com Sucesso!" << endl;
    d.Show();
    cout << endl << endl; system("pause"); system("cls");
    
    cout << "Exercicio 5.10 e 5.11" << endl << endl;
    ofstream ofile;
    string nomeFicheiro;
    cout << "Salvar Dados em ficheiro" << endl;
    cout << "Nome do ficheiro: ";
    cin >> nomeFicheiro;
    nomeFicheiro += ".txt";
    ofile.open(nomeFicheiro);
    if(ofile){
        a.Savefile(ofile);
        ofile << endl;
        b.Savefile(ofile);
        ofile << endl;
        c.Savefile(ofile);
        ofile << endl;
        d.Savefile(ofile);
        ofile.close();
        cout << "A guardar ficheiro .";sleep(1); cout << ".";sleep(1); cout << "." << endl << endl;sleep(1);
        cout << "Ficheiro " << nomeFicheiro << " guardado com sucesso!";
    }else{
        cout << "Erro na criacao de " << nomeFicheiro;
    }
    cout << endl << endl; system("pause"); system("cls");
    
    cout << "Exercicio 5.12 e 5.13" << endl << endl;
    int contador = 0;
    ifstream ifile;
    nomeFicheiro = "";
    Funcionario vector[100];
    cout << "Ler Dados de um ficheiro" << endl;
    cout << "Nome do ficheiro (.txt): ";
    cin >> nomeFicheiro;
    nomeFicheiro += ".txt";
    ifile.open(nomeFicheiro);
    if(ifile){
        while(ifile.peek() != EOF){
			vector[contador].Readfile(ifile);
			contador++;
        }
        ifile.close();
        cout << endl <<"Leitura realizada com sucesso!" << endl << endl;
    }else{
        cout << "Erro na leitura de " << nomeFicheiro;
    }
    cout << "Conteudo do ficheiro:" << endl << endl;
    for (int i = 0; i < contador; i++){
		vector[i].Show();
        cout << endl;
    }
    cout << endl << endl; system("pause"); system("cls");

    cout << "Exercicio 5.14" << endl << endl;
    cout << "Conteudo do ficheiro ordenado pela data de nascimento:" << endl << endl;
    SelectionSort(vector, contador);
    for (int i = 0; i < contador; i++){
		vector[i].Show();
        cout << endl;
    }
    cout << endl << endl; system("pause"); system("cls");

    return 0;
}

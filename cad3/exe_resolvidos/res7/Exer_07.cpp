// Exer_07.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <list>
#include "GestorN.h"

using namespace std;

int main()
{

	GestorN gestor;
	int temp;

	//pr�-carregar a lista com alguns n�meros de exemplo (facultativo)
	gestor.InserirInicio(1);
	gestor.InserirInicio(3);
	gestor.InserirInicio(4);
	gestor.InserirInicio(7);
	gestor.InserirInicio(2);
	gestor.InserirInicio(9);
	gestor.InserirInicio(5);
	// *******************************

	//EXEMPLOS DE USO DOS METODOS DA CLASSE GESTORA

	//listar
	cout << "Lista de inteiros:\n";
	gestor.Show();

	//remover
	cout << "Numero a remover:\n";
	cin >> temp;
	gestor.Remover(temp);

	//listar
	cout << "Lista de inteiros:\n";
	gestor.Show();

	//teste �s sobrecargas dos operadores >> e <<
	cout << "Insira novo numero:\n";
	cin >> gestor; //inserir novo n�mero na lista

	//listar
	cout << "Lista de inteiros:\n";
	cout << gestor;

	//pesquisar por num
	cout << "Insira o numero cujo indice quer obter:\n";
	cin >> temp;
	int onde_esta_o_num = gestor.EncontrarIndice(temp);
	if (onde_esta_o_num != -1)
	{
		//posicao na lista � o seu indice + 1 !!
		cout << "Numero foi encontrado na posicao " << onde_esta_o_num + 1 << " .\n\n";

	}
	else
	{
		cout << "Numero nao foi encontrado.\n\n";
	}

	//interacao com ficheiros

	char ficheiro[] = "numeros.txt";

	//READ FILE: adicionar � lista a partir de um ficheiro
	ifstream ifile;
	ifile.open(ficheiro);
	if (ifile)
	{
		cout << "A ler numeros a partir de " << ficheiro << "... \n";
		gestor.ReadFile(ifile);
		cout << "Ficheiro lido com sucesso.\n\n";
		ifile.close();
	}

	gestor.Show();

	//SAVE FILE: guardar lista num ficheiro
	ofstream ofile;
	ofile.open(ficheiro);
	if (ofile)
	{
		gestor.SaveFile(ofile);
		cout << "Dados foram guardados em ficheiro. \n\n";
		ofile.close();
	}
	
	system("pause");
	return 0;
}


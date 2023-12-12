// MP2_1718_A.cpp : Defines the entry point for the console application.
//

#include "Pessoa.h"
#include "Func.h"
#include "Data.h"

void BubbleSort(Func *A, int size);
void SelectionSort(Func *A, int size);
void InsertionSort(Func *A, int size);
void Swap(Func *x, Func *y);


int main()
{
	Func a(25023, "Pintura", "Joca Gaio", "Rua da direita n2", 20, 9, 1987);
	Func b(25024, "Comercial", "Ana Rola", "Rua da esquerda n3", 4, 2, 1990);
	ofstream ofile;
	ifstream ifile;
	string str;
	int i, contador;

	////((Pessoa)a).Show();//Para invocar m�todos da classe Pessoa
	//b.Show();

	//a.SetMorada("Rua do meio n4");
	//a.SetSetor("Ferragem");
	//a.Show();
	
	// 5.7
	Data dtn=b.GetData();
	dtn.SetDia(23);
	b.SetData(dtn);
	b.Show();
	
		//
	Func c, d;

	fflush(stdin);
	c.ReadK();
	fflush(stdin);
	d.ReadK();
	c.Show();
	d.Show();

	//cout << "Nome do ficheiro: ";
	//cin >> str;

	str= "funcionarios.txt";
	ofile.open(str);
	if (ofile)
	{
		a.SaveFile(ofile);
		b.SaveFile(ofile);
		c.SaveFile(ofile);
		d.SaveFile(ofile);
		ofile.close();
		cout << "Ficheiro " << str << " criado com sucesso!" << endl;
	}
	else
		cout << "ERRO: n�o � poss�vel abrir o ficheiro " << str << '\n';

	Func vector[4];

	ifile.open(str);
	if (ifile)
	{
		//for (int i = 0; i < 4; i++)
		//	vector[i].ReadFile(ifile);
		contador=0;
		while (ifile.peek() != EOF){
			vector[contador].ReadFile(ifile);
			contador++;
		}

		ifile.close();
		cout << "Ficheiro " << str << " lido com sucesso!" << endl;
	}
	else
		cout << "ERRO: n�o � poss�vel abrir o ficheiro " << str << '\n';


	SelectionSort(vector, 4);
	for (int i = 0; i < contador; i++)
		cout << vector[i] << "\n";

	fflush(stdin);
	cin.get();

    return 0;
}

void BubbleSort(Func *A, int size)
{
	bool swaped;
	int i, j;

	i = size;
	do {
		swaped = false;
		for (j = 1; j<i; j++)
			if ((A + j - 1)->GetNome() >(A + j)->GetNome())
			{
				Swap(A + j - 1, A + j);
				swaped = true;
			}
		i--;
	} while (i>0 && swaped);
}

void SelectionSort(Func *A, int size)
{
	int i, j, aux;

	for (i = 0; i<size - 1; i++)
	{
		aux = i;
		for (j = i + 1; j<size; j++)
			if ((A + j)->GetData() < (A + aux)->GetData())
				aux = j;
		Swap(A + aux, A + i);
	}
}

void InsertionSort(Func *A, int size)
{
	int i, j;
	Func aux;

	for (i = 1; i<size; i++)
	{
		aux = *(A + i);
		j = i;
		while (j>0 && (A + j - 1)->GetNome() > aux.GetNome())
		{
			*(A + j) = *(A + j - 1);
			j = j - 1;
		}
		*(A + j) = aux;
	}
}

void Swap(Func *x, Func *y)
{
	Func	aux;

	aux = *x;
	*x = *y;
	*y = aux;
}



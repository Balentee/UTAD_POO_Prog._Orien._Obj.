#include "Func.h"
#include "Operario.h"
#include "Administrativo.h"
#include <vector>
#include <clocale>

//todos os metodos recebem a lista de funcionarios em referencia para poder permitir modificações se necessário
void LerFicheiro(vector<Func*> &Lista);
void CalcularOrdenados(vector<Func*> &Lista);
void PesquisaFuncionario(vector<Func*> &Lista);
void AlteraOrdenado(vector<Func*> &Lista);
void CriarFuncionario(vector<Func*> &Lista);
void ApresentaTurnos(vector<Func*> &Lista);
void RemoveFuncionario(vector<Func*> &Lista);
void GuardarAdministrativos(vector<Func*> &Lista);
void GuardarOperarios(vector<Func*> &Lista);

int main()
{
	setlocale(LC_ALL, ""); //para apresentar os acentos e tils 

	/*
	Este exercicio usa a classe vector em detrimento da abordagem comum de vectores estátivos (ex: int J[10] )
	a classe vector permite criar um objecto vector que armazena dinamicamente os valores que acrescentamos ao fim do vector (com o metodo Push_back()) 
	e vai crescer e diminuir a medida que adicionamos ou removemos (com o metodo erase) posições nesse vector).
	como a classe vector é dinamica, ele possui um metodo para nos informar de quantos objectos estão no vector nesse instante ( .size() )

	A dclaração do vector tendo por base templates, o que nos permite ter um vector para o tipo de classe que quisermos.

	vector<int> L;
	vector<string> J;
	vector<Operario> M;

	ou Seja, vector<T>, onde T é o nome da classe ou tipo que queremos criar o objecto.
	*/
	   
	vector<Func*> Lista; //objcto da classe vector que permite armazenar apontadores do tipo Func*, o que permite alocar Operarios e Administrativos devido à relação de herança
	


	int op;
	while (true)
	{
		cout << endl << endl << " ------    Bem Vindo ao Sistema XPTO     -----  " << endl
			<< "\t 1 - Ler Ficheiro" << endl
			<< "\t 2 - Calcular e apresentar o ordenado de todos os funcionários." << endl
			<< "\t 3 - Pesquisar um funcionário pelo seu número." << endl
			<< "\t 4 - Alterar o ordenado base de um funcionário, identificado pelo seu número" << endl
			<< "\t 5 - Adicionar ao vector um Operario ou Administrativo" << endl
			<< "\t 6 - Apresentar o nome dos operários que trabalham por turnos"<< endl
			<< "\t 7 - Eliminar do vetor um funcionário" << endl
			<< "\t 8 - Guardar, num ficheiro Administrativos." << endl
			<< "\t 9 - Guardar, num ficheiro Operarios." << endl
			<< "\t 0 - Sair" << endl
			<< "Escolha a opção:";
		cin >> op;
				 
		switch (op)
		{
		case 1:
			LerFicheiro(Lista);
			break;
		case 2:
			CalcularOrdenados(Lista);
			break;
		case 3:
			PesquisaFuncionario(Lista);
			break;
		case 4:
			AlteraOrdenado(Lista);
			break;
		case 5:
			CriarFuncionario(Lista);
			break;
		case 6:
			ApresentaTurnos(Lista);
			break;
		case 7:
			RemoveFuncionario(Lista);
			break;
		case 8:
			GuardarAdministrativos(Lista);
			break;
		case 9:
			GuardarOperarios(Lista);
			break;
		case 0:
			exit(0);
			break;
		}
	}

	//para não fechar a consola;
	getchar();
}

void LerFicheiro(vector<Func*> &Lista)
{
	ifstream file;
	file.open("Funcionarios.txt");

	if (! file.is_open())
	{
		exit(-1);
	}


	do {	
		string tipo;
		getline(file, tipo, ':');  //no ficheiro o tipo de funcionario é dado pelo primeiro caracter separado por : da restante linha

		if (tipo == "O")
		{
			Operario *op = new Operario(); //alocar o espaço para um operario
			op->ReadFile(file);            //preencher os dados a partir do ficheiro com o metodo readfile da classe operario.
			Lista.push_back(op);		//guardar o operario na lista
		}
		else  if (tipo == "A")
		{
			Administrativo *adm = new Administrativo();
			adm->ReadFile(file);
			Lista.push_back(adm);
		}

		file.ignore(INT16_MAX, '\n'); //para mudar para a linha seguinte
	}
	while (file.peek() != EOF); //repetimos até chegar o caracter seguinte ser o fim do ficheiro.	


	cout << endl << "Foram lidos " << Lista.size() << " funcionarios para a Lista"; //apresentamos o resultado.

	file.close();
}

void CalcularOrdenados(vector<Func*> &Lista)
{
	//para todos os funcionarios na lista vamos apresentar a informação no ecra;

	cout << endl << endl << "-----    Lista de Funcionarios    -----" << endl;

	for (int i = 0; i < Lista.size(); i++)
	{
		cout << Lista[i]->GetNum() << "\t"
			<< Lista[i]->GetNome() << "\t"
			<< Lista[i]->Calcula_Ordenado() << endl; //como o CalculaOrdenadao é um metodo virtual puro, ele vai chamar correctamente a implementação 
													//do Operario, ou do Administrativo sem necessidade de Converter o objecto (dynamic_cast)

	}

	cout << endl << endl;

}

void PesquisaFuncionario(vector<Func*> &Lista)
{
	cout << endl << endl << "-----    Pesquisa de Funcionarios    -----" << endl;

	int numero;
	cout << "Insira o numero do Funcionario:" << endl;
	cin >> numero;

	//percorremos o vector a procura do utilizador com o numero inserido.
	for (int i = 0; i < Lista.size(); i++)
	{
		
		if (Lista[i]->GetNum() == numero)
		{
			//caso o numero exista, temos que converter para o tipo correcto (Operario ou Administrativo)

			if (Operario *op = dynamic_cast<Operario*>(Lista[i]))
			{
				//se for um operario, ele vai converter neste if, e executa esta linha, caso não seja, ele não entra aqui, pois a conversão resulta em NULL
				op->Show();
			}

			if (Administrativo *adm = dynamic_cast<Administrativo*>(Lista[i]))
			{
				//se for um Administrativo, ele vai converter neste if, e executa esta linha, caso não seja, ele não entra aqui, pois a conversão resulta em NULL

				adm->Show();
			}

			return; //se encontrar termina aqui
		}

	}


	cout << "Não foi encontrado o utilizador" << endl;

}


void AlteraOrdenado(vector<Func*> &Lista)
{
	cout << endl << endl << "-----    Alterar Ordenado de Funcionario    -----" << endl;

	int numero;
	cout << "Insira o numero do Funcionario:";
	cin >> numero;

	for (int i = 0; i < Lista.size(); i++)
	{
		if (Lista[i]->GetNum() == numero) //procuramos o funcionario na lista, e se encontrar
		{

			cout << "Ordenado Actual: " << Lista[i]->GetOrdBase();
			cout << "insira o novo ordenado:";
			float ord;
			cin >> ord;
			//como o metodo de alterar o ordenado pertence a classe Func não é necessário converter o objecto com o dynamic cast
			Lista[i]->SetOrdBase(ord);

			return;
		}

	}

	cout << "Não foi encontrado nenhum funcionario com o numero " << numero << endl;

}

void CriarFuncionario(vector<Func*> &Lista)
{
	cout << endl << endl << "-----    Criar Funcionario    -----" << endl;

	string tipo;
	//descartar o lixo do buffer
	cin.ignore(INT16_MAX, '\n');

	cout << "Deseja inserir: " << endl
		<< "O - Operario" << endl
		<< "A - Administrativo" << endl;

	getline(cin, tipo, '\n');

	if (tipo == "O" || tipo == "o")
	{
		Operario *op = new Operario();
		op->ReadK(); //o metodo readK permite ler a informação a partir do teclado.
		Lista.push_back(op);
	}
	else if (tipo == "A" || tipo == "a")
	{
		Administrativo *adm = new Administrativo();
		adm->ReadK();
		Lista.push_back(adm);
	}


	cout << endl;

}
void ApresentaTurnos(vector<Func*> &Lista)
{
	cout << endl << endl << "-----    Lista de Operarios que trabalham em turno    -----" << endl;

	for (int i = 0; i < Lista.size(); i++) //percorremos cada um dos funcionarios
	{
		if (Operario *op = dynamic_cast<Operario*>(Lista[i])) // tentamos converter para operario, caso não seja possivel é porque nessa posição está um administrativo
		{
			if (op->GetTurno()) //se for um operario, vamos vereficar se ele trabalha por turno.
			{
				cout <<op->GetNum() << "\t " << op->GetNome() << endl;
			}
		}
	}
	cout << endl;
}


void RemoveFuncionario(vector<Func*> &Lista)
{
	//listar todos os funcionarios para saber qual vamos remover (opcional, mas fica mais completo)
	cout << endl << endl << "-----    Lista de Funcionarios    -----" << endl;

	for (int i = 0; i < Lista.size(); i++)
	{
		cout << Lista[i]->GetNum() << "\t " << Lista[i]->GetNome() << "\t " << Lista[i]->GetSetor() << endl;
	}

	int numero;
	cout << "insira o numero do Funcionario a remover:" << endl;
	cin >> numero;

	//procurar o funcionario na lista;
	for (int i = 0; i < Lista.size(); i++)
	{
		if (Lista[i]->GetNum() == numero) // se existir
		{
			//removemos do vector com o metodo erase, que recebe um "iterador" que aponta para a posição que queremos remover a partir do inicio.
			Lista.erase(Lista.begin() + i);
			
			cout << endl << "O funcionario " << numero << " foi removido com sucesso" << endl;
			return; //como foi removido, podemos terminar;
		}
	}

	cout << "Nenhum utilizador encontrado com esse numero!" << endl;
}

void GuardarAdministrativos(vector<Func*> &Lista)
{

	ofstream file;
	file.open("Administrativos.txt");

	if (!file.is_open())
	{
		exit(-1);
	}
	
	for (int i = 0; i < Lista.size(); i++)
	{
		//como apenas queremos guardar administrativos, vamos tentar converter, se for possivel guardamos no ficheiro, se não for, 
		// é um operario, então passamos a frente.
		if (Administrativo *adm = dynamic_cast<Administrativo*>(Lista[i]))
		{
			adm->SaveFile(file);
			file << endl;

		}

	}

	cout << "Ficheiro Administrativos.txt Guardado com sucesso" << endl;
	file.close();
}


void GuardarOperarios(vector<Func*> &Lista)
{

	ofstream file;
	file.open("Operarios.txt");

	if (!file.is_open())
	{
		exit(-1);
	}

	for (int i = 0; i < Lista.size(); i++)
	{
		//como apenas queremos guardar Operarios, vamos tentar converter, se for possivel guardamos no ficheiro, se não for, 
		// é um Administrativos, então passamos a frente.
		if (Operario *adm = dynamic_cast<Operario*>(Lista[i]))
		{
			adm->SaveFile(file);
			file << endl;
		}

	}

	cout << "Ficheiro Operarios.txt Guardado com sucesso" << endl;

	file.close();
}
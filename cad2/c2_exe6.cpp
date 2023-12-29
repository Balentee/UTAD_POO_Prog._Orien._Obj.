#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include "C:/Users/Tiago Valente/poo/cad1/headers1/Pessoa.h"
#include "C:/Users/Tiago Valente/poo/cad1/headers1/Pessoa.cpp"
#include "C:/Users/Tiago Valente/poo/cad1/headers1/Data.h"
#include "C:/Users/Tiago Valente/poo/cad1/headers1/Data.cpp"
#include "C:/Users/Tiago Valente/poo/cad2/headers2/Funcionario.h"
#include "C:/Users/Tiago Valente/poo/cad2/headers2/Funcionario.cpp"
#include "C:/Users/Tiago Valente/poo/cad2/headers2/Operario.h"
#include "C:/Users/Tiago Valente/poo/cad2/headers2/Operario.cpp"
#include "C:/Users/Tiago Valente/poo/cad2/headers2/Administrativo.h"
#include "C:/Users/Tiago Valente/poo/cad2/headers2/Administrativo.cpp"

using namespace std;

//Inicializar metodos
void LerFicheiro(vector<Funcionario*> &Lista);
void CalcularOrdenados(vector<Funcionario*> &Lista);
void PesquisarFuncionario(vector<Funcionario*> &Lista);
void AlteraOrdenado(vector<Funcionario*> &Lista);
void AdicionarFuncionario(vector<Funcionario*> &Lista);
void TrabalhadoresTurnos(vector<Funcionario*> &Lista);
void EliminarFunc(vector<Funcionario*> &Lista);
void SalvarDadosAdministrativos(vector<Funcionario*> &Lista);
void SalvarDadosOperarios(vector<Funcionario*> &Lista);

int main(){
    cout << "Exercicio 6\n";
    cout << "Classes abstratas, dynamic cast, etc.";
    cout << endl << endl; system("pause"); system("cls");
    /*
    cout << "Exercicio 6.1" << endl << " - Atualizar Funcionario.h e metodos" << endl;
    cout << "Exercicio 6.2" << endl << " - Definir classes Operario e Administrativo" << endl; 
    cout << "Exercicio 6.3" << endl << " - Implementar metodos nas classes" << endl;
    cout << "Exercicio 6.4" << endl << " - Implementar metodo Calcula_ordenado()" << endl;
    cout << endl << endl; system("pause"); system("cls");
    */
    int op, update;
    vector<Funcionario*> Lista;
    while(true){
        cout << "Exercicio 6.5" << endl << " - Menu - " << endl << endl;
        cout << "1 - Ler funcionarios.txt" << endl;
        cout << "2 - Calcular Ordenados" << endl;
        cout << "3 - Pesquisar Funcionario" << endl;
        cout << "4 - Alterar Ordenado" << endl;
        cout << "5 - Adicionar Operario ou Administrativo" << endl;
        cout << "6 - Trabalhadores por turnos" << endl;
        cout << "7 - Eliminar por numero de funcionario" << endl;
        cout << "8 - Salvar \"Aministrativos.txt\"" << endl;
        cout << "9 - Salvar \"Operarios.txt\"" << endl;
        cout << "0 - Sair" << endl << endl;
        cout << "menu shit, choose shit: ";
        cin >> op;
        switch (op){
            case 0: 
                system("cls");
                cout << "bye then, bitch :(" << endl;
                sleep(1);system("cls");
                return 0;
                break;
            case 1:
                // ler ficheiro para vetor, 1º caracter indica se é op
                system("cls");
                cout << "1 - Ler funcionarios.txt" << endl;
                if (update != 69){
                    LerFicheiro(Lista);
                    update = 69;
                }else{
                    for (Funcionario* i : Lista){
                        cout << "\t";
                        i->Show();
                        cout << endl;
                    }
                    cout << "\n Ja leste o ficheiro nabo...";
                }
                cout << endl << endl; system("pause"); system("cls");
                break;
            case 2:
                // Calcular ordenado
                system("cls");
                cout << "2 - Calcular Ordenados" << endl;
                CalcularOrdenados(Lista);
                cout << endl << endl; system("pause"); system("cls");  
                break;
            case 3:
                // Pesquisa atraves do num func
                system("cls");
                cout << "3 - Pesquisar Funcionario" << endl << " ";
                for (Funcionario* i : Lista){
                        cout << i->GetNumFunc() << "  ";
                }
                cout << endl << endl;
                PesquisarFuncionario(Lista);
                cout << endl << endl; system("pause"); system("cls");  
                break;
            case 4:
                // Altera o ordenado atraves do num func
                system("cls");
                cout << "4 - Alterar Ordenado" << endl << endl;
                for (Funcionario* i : Lista){
                    cout << i->GetNumFunc() << "  ";
                }
                cout << endl << endl;
                AlteraOrdenado(Lista);
                cout << endl << endl; system("pause"); system("cls");  
                break;
            case 5:
                // Adicionar um novo Oper ou Admin
                system("cls");
                AdicionarFuncionario(Lista);
                cout << endl << endl; system("pause"); system("cls");  
                break;
            case 6:
                // Apresenta quem trabalha por turnos
                system("cls");
                cout << "6 - Trabalhadores por turnos" << endl << endl;
                TrabalhadoresTurnos(Lista);
                cout << endl << endl; system("pause"); system("cls");  
                break;
            case 7:
                // Eliminar atraves do numero de funcionario
                system("cls");
                cout << "7 - Eliminar por numero de funcionario" << endl << endl;
                for (Funcionario* i : Lista){
                    cout << i->GetNumFunc() << "  ";
                }
                cout << endl << endl;
                EliminarFunc(Lista);
                cout << endl << endl; system("pause"); system("cls");  
                break;    
            case 8:
                // Guardar ficheiro por tipo de funcionario
                system("cls");
                cout << "8 - Salvar \"Aministrativos.txt\"" << endl << endl;
                SalvarDadosAdministrativos(Lista);
                cout << endl << endl; system("pause"); system("cls");  
                break;    
            case 9:
                // Guardar ficheiro por tipo de funcionario
                system("cls");
                cout << "9 - Salvar \"Operarios.txt\"" << endl << endl;
                SalvarDadosOperarios(Lista);
                cout << endl << endl; system("pause"); system("cls");  
                break;    
            default:
                sleep(1);system("cls");
                break;
        }
    }
    return 0;
}

void LerFicheiro(vector<Funcionario*> &Lista){
    ifstream is;
    is.open("funcionarios.txt");
    if(!is.is_open()){
        exit (-1);
    }

    do{
        string tipo;
        getline(is, tipo, ':');

        if(tipo == "O"){
            Operario *oper = new Operario();
            oper->Readfile(is);
			Lista.push_back(oper);
            cout << "\t";
            oper->Show();
            cout << endl;
        }
        else if(tipo == "A"){
            Administrativo *admin = new Administrativo();
            admin->Readfile(is);
			Lista.push_back(admin);
            cout << "\t";
            admin->Show();
            cout << endl;
        }
        is.ignore(INT16_MAX, '\n');
    }while(is.peek() != EOF);

    if(Lista.size() > 1){
        cout << endl << "Foram lidos " << Lista.size() << " funcionarios para a Lista"; 
    }
    else if(Lista.size() == 1){
        cout << endl << "Foi lido " << Lista.size() << " funcionario para a Lista";
    }
    else if(Lista.size() < 1){
        cout << endl << "Não foi lido nenhum funcionario para a Lista";
    }
	
    is.close();
}

void CalcularOrdenados(vector<Funcionario*> &Lista){
    for (Funcionario* i : Lista){
        cout << i->GetNumFunc() << setfill('.') << setw(20) << i->GetNome() << " -> recebe " << i->Calcula_ordenado() << " euros mensais ( " << i->GetOrdBase() << " de ord. base com " << (i->GetHExtra() * i->GetPHExtra()) << " das horas extra)" << endl;
    }
}

void PesquisarFuncionario(vector<Funcionario*> &Lista){
	int numero, exists;
	cout << " Insira o numero do Funcionario: ";
	cin >> numero;
    cout << endl;
	for (Funcionario* i : Lista){
        if(numero == i->GetNumFunc()){
            exists = 69;
            if(Operario* oper = dynamic_cast<Operario*>(i)){
                oper->Show();
            }
            if(Administrativo* admin = dynamic_cast<Administrativo*>(i)){
                admin->Show();
            }
            return;
        }
}
    if(exists != 69){
        cout << "Nao existe nenhum funcionario com o numero " << numero;
    }
}

void AlteraOrdenado(vector<Funcionario*> &Lista){
	int numero, exists;
    float ordenado;
	cout << " Insira o numero do Funcionario: ";
	cin >> numero;
    cout << endl;
	for (Funcionario* i : Lista){
        if(numero == i->GetNumFunc()){
            exists = 69;
            system("cls");cout << "4 - Alterar Ordenado" << endl ; cout << "\nNumero do Funcionario->" << numero << endl << endl;
            cout << "Ordenado de "<< i->GetNome() << endl;
            cout << "  Ordenado atual: " << i->GetOrdBase() << endl;
            cout << "  Novo ordenado: ";
            cin >> ordenado;
            i->SetOrdBase(ordenado);
            cout << endl;
            i->Show();
            cout << endl;
        }
}
    if(exists != 69){
        cout << "Nao existe nenhum funcionario com o numero " << numero;
    }
}

void AdicionarFuncionario(vector<Funcionario*> &Lista){
    string tipo;
    do{
        cout << "5 - Adicionar Operario ou Administrativo" << endl << endl;
        cout << "  Qual o tipo de Funcionario a adicionar (selecione atraves do teclado)" << endl;
        cout << "    | O - Operario | A - Administrativo | 0 - Voltar ao menu | ";
        cin >> tipo;
        if(tipo == "0"){return;}
        system("cls");
    }while(tipo != "O" && tipo != "A" && tipo != "o" && tipo != "a"); 
    if(tipo == "O"){
        cout << "5 - Adicionar Operario" << endl << endl;
        Operario* oper = new Operario();
        oper->SetOperario();
        Lista.push_back(oper);
    }else{
        cout << "5 - Adicionar Administrativo" << endl << endl;
        Administrativo* admin = new Administrativo();
        admin->SetFuncionario();
        Lista.push_back(admin);
    }
}

void TrabalhadoresTurnos(vector<Funcionario*> &Lista){
    for(Funcionario* i : Lista){
        if(Operario* oper = dynamic_cast<Operario*>(i)){
            if (oper->GetTurno()){
				cout << oper->GetNumFunc() << "  " << oper->GetNome() << endl;
			}
        }
    }
}

void EliminarFunc(vector<Funcionario*> &Lista){
    int numero, exists;
    cout << "Insira o numero do Funcionario: ";
	cin >> numero;
    cout << endl ;
	for (Funcionario* i : Lista){
        if(numero == i->GetNumFunc()){
            exists = 69;
            cout << "Confirme que quer remover o Funcionario " << i->GetNome() << endl << endl;
            cout << "Insira o numero de funcionario corretamente para confirmar: ";
            cin >> numero;
            if (numero != i->GetNumFunc() ){
                cout << " -ABORTADO- ";
                return;
            }else{
            system("cls"); cout << "7 - Eliminar por numero de funcionario" << endl << endl;
            cout << "Numero do Funcionario -> " << i->GetNumFunc() << endl << endl;
            cout << "Removido o Funcionario " << i->GetNome();
            Lista.erase(remove(Lista.begin(), Lista.end(), i));
            }
        }
    }
    if(exists != 69){
        cout << "Nao existe nenhum funcionario com o numero " << numero;
    }
}

void SalvarDadosAdministrativos(vector<Funcionario*> &Lista){
	ofstream of;
	of.open("Administrativos.txt");

	if (!of.is_open()){
		exit(-1);
	}
    
    for (Funcionario* i : Lista){
        if(Administrativo* admin = dynamic_cast<Administrativo*>(i)){
            admin->Savefile(of);
            of << endl;
            cout << i->Show() << endl;
        }
    }
    cout << "Ficheiro Administrativos.txt Guardado com sucesso" << endl;
    of.close();
}

void SalvarDadosOperarios(vector<Funcionario*> &Lista){
	ofstream of;
	of.open("Operarios.txt");

	if (!of.is_open()){
		exit(-1);
	}
    
    for (Funcionario* i : Lista){
        if(Operario* oper = dynamic_cast<Operario*>(i)){
            oper->Savefile(of);
            of << endl;
            cout << i->Show() << endl;
        }
    }

    cout << "Ficheiro Operarios.txt Guardado com sucesso" << endl;
    of.close();
}

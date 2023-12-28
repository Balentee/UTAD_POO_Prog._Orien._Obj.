#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
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
void CalcularOrdenado(vector<Funcionario*> &Lista);

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
    int op;
    vector<Funcionario*> Lista;
    while(true){
        cout << "Exercicio 6.5" << endl << " - Menu - " << endl << endl;
        cout << "menu shit, choose shit: ";
        cin >> op;
        switch (op){
            case 0: 
                system("cls");
                cout << "bye" << endl << endl;
                return 0;
                break;
            case 1:
                // ler ficheiro para vetor, 1º caracter indica se é op
                system("cls");
                cout << "1-" << endl;
                LerFicheiro(Lista);
                cout << endl << endl; system("pause"); system("cls");
                break;
            case 2:
                // Calcular ordenado
                system("cls");
                cout << "2-" << endl;
                CalcularOrdenado(Lista);
                cout << endl << endl; system("pause"); system("cls");  
                break;

            default:
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

void CalcularOrdenado(vector<Funcionario*> &Lista){
    
}
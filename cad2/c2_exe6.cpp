#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <unistd.h> //for sleep
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
void LerFicheiro(vector<Func*> &Lista);

int main(){
    cout << "Exercicio 6\n";
    cout << "Classes abstratas, dynamic cast, etc.";
    cout << endl << endl; system("pause"); system("cls");

    cout << "Exercicio 6.1" << endl << " - Atualizar Funcionario.h e metodos" << endl;
    cout << "Exercicio 6.2" << endl << " - Definir classes Operario e Administrativo" << endl; 
    cout << "Exercicio 6.3" << endl << " - Implementar metodos nas classes" << endl;
    cout << "Exercicio 6.4" << endl << " - Implementar metodo Calcula_ordenado()" << endl;
    cout << endl << endl; system("pause"); system("cls");

    int op;
    while(true){
        cout << "Exercicio 6.5" << endl << " - Menu" << endl << endl;
        cout << "menu shit, choose shit: ";
        cin >> op;
        switch (op){
        case 1:
            // ler ficheiro para vetor, 1º caracter indica se é op
            void LerFicheiro(vector<Func*> &Lista);
            break;
        
        default:
            break;
        }
    }
    return 0;
}

void LerFicheiro(vector<Func*> &Lista){
    ifstream is;
    is.open("funcionarios.txt");

    if(!is.is_open()){
        exit (-1);
    }

    do{
        string tipo;
        getline(is, tipo, ":");

        if(tipo == "O"){
            Operario *operario = new operario();
            
        }
        if(tipo == "A"){
            Administrativo
        }


    }while(find.peek() != EOF);
}
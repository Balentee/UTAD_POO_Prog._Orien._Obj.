#include <iostream>
#include <iomanip>

using namespace std;

// 1. Biblioteca de Streams do C++ e Manipuladores em C++

// 1.1 - Programa para ler o nome e a idade de uma pessoa.
void exe1_1(){
    int idade;
    char nome[30];
    cout << "Escreva o seu nome:" << endl;
    cin >> nome;
    cout << "Insira a sua idade:" << endl;
    cin >> idade;
    cout << "\nNome do sujeito: "<< nome << "\nIdade: " << idade << " anos" << endl;
}

// 1.2 - Desenvolva um programa que permita fazer a leitura e escrita dos seguintes tipos de dados:
//          inteiro / real / caracter / string
void exe1_2(){
    int inteiro;
    float real;
    char caracter;
    char string[100];

    cout << "Num inteiro:";
    cin >> inteiro;
    cout << "\nNum real:";
    cin >> real;
    cout << "\nLetra:";
    cin >> caracter;
    cout << "\nSring:";
    cin >> string;

    cout <<"\n\nInteger: " << inteiro <<"\nFloat: " << real <<"\nChar: " << caracter <<"\nString: " << string << endl;
    cout <<"\n TESTING TYPES ENDED" << endl;
}

// 1.3 - Exemplo do uso do manipulador setw e setfill
void exe1_3(){
    cout <<"ENSAIO do setw() .............. " << endl;
    cout << setw(10) << 11 << endl;
    cout << setw(10) << 23222 << endl;
    cout << setw(10) << 1234567891011 << endl;
    cout << setfill('-') << setw(10) << 11 << endl;
}

// 1.4 - Exemplo do uso do manipulador setprecision (e setf)
void exe1_4(){
    cout << "Precisao global ....................... " << endl;
    cout << "5 digitos, parte inteira e decimal " << setprecision(5) << 1234.537 << endl;
    cout << "6 digitos parte inteira e decimal " <<setprecision(6)<< 123456.537<< endl << endl;
    cout << "Precisao da parte decimal ....................... " << endl;
    cout.setf(ios::floatfield,ios::fixed); //wtf?
    cout << "2 digitos na parte decimal " << setprecision(2) << 1234.537 << endl;
    cout << "5 digitos na parte decimal " << setprecision(5) << 1234.537 << endl;
}


int main (){
    exe1_1();
    system("pause");
    system("cls");
    exe1_2();
    system("pause");
    system("cls");
    exe1_3();
    system("pause");
    system("cls");
    exe1_4();
    
    system("pause");
    return (0);
}



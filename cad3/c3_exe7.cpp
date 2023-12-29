#include <iostream>
#include <fstream>
#include <list>
#include <unistd.h>
#include "C:\Users\Tiago Valente\poo\cad3\headers3\Gestor_Num.h"
#include "C:\Users\Tiago Valente\poo\cad3\headers3\Gestor_Num.cpp"

using namespace std;
/*7. Utilize a biblioteca STL para especificar uma classe cuja principal responsabilidade é a de disponibilizar alguns métodos capazes 
de gerir uma  sequência  de  números  inteiros,  armazenados em memória na forma de lista simplesmente ligada (NOTA: no Anexo A,desta 
folha de exercícios, encontra alguma documentação relativa à classe template list͛ da Standard Template Library, ou STL). Esta classe gestora,
Gestor_Num͟, além dos seus construtores, destrutor e métodos de acesso,deve disponibilizar um conjunto de funcionalidades que permitam também: 
 
a) Inserir um novo número inteiro na lista; 
b) Remover um número da lista; 
c) Listar, no ecrã, todos os números da lista; 
d) Obter a posição absoluta de um determinado número, na lista.*/
int main(){
    Gestor_Num gnum;
    int num;
    cout << "7 - Introducao a Listas\n\n";
    cout << "  Introduzir numeros na lista (0 para parar)\n";
    while (1){
        cout << "  Inserir numero: ";
        cin >> num;
        if(num == 0){
            break;
        }else{
            gnum.InserirNum(num);
        }
    }
    cout << "\n\n"; system("pause"); system("cls");
    while (1){
    cout << "7 - Introducao a Listas\n\n";
    gnum.Show();
    cout << "  \n\nRemover numeros da lista (0 para parar)\n";
        cout << "  Remover numero: ";
        cin >> num;
        if(num == 0){
            break;
        }else{
            gnum.Remover(num);
        }
        cout << "\n\n"; system("cls");
    }
    cout << "\n\n"; system("pause"); system("cls");
    cout << "7 - Introducao a Listas\n\n";
    cout << "Listar numeros da lista\n";
    gnum.Show();
    cout << "\n\n"; system("pause"); system("cls");
    while (1){
        cout << "7 - Introducao a Listas\n\n";
        gnum.Show();
        cout << "  \n\nPosicao de um numero na lista\n";
        cout << "  Saber posicao de: ";
        cin >> num;
        if(num == 0){
            break;
        }else if((gnum.PosicaoNaLista(num)) != -1){
            cout << " Encontra -se na posicao [" << gnum.PosicaoNaLista(num) << "] da lista.";
            cout << "\n\n"; system("pause"); system("cls");
        }
        cout << "\n\n"; system("cls");
        }
    cout << "\n\n"; system("cls");
    cout << "Ok all done, bye.\n\n\n";
    sleep(1);system("cls");
    return 0;
}

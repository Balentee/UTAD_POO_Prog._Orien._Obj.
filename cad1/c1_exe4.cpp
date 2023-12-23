#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "headers1/Data.h"
#include "headers1/Pessoa.h"
#include "headers1/Data.cpp"
#include "headers1/Pessoa.cpp"

using namespace std;

int main(){
    int n = 0, i;
    char morada[100];
    Data data; 
    string nomeficheiro, nomeficheirotxt, line;
    ofstream ofile;
    ifstream ifile;
    Pessoa P[100];
    Pessoa Jonas("Jonas Culatra", Data(20,9,1987),"Rua da direita n 2");
    Pessoa Joni("Joni Rato", Data(4,2,1990),"Rua da esquerda n 3");
    Pessoa Utilizador; // teste radk
    Pessoa Administrador; //teste sobrec. op.
    /*
    Jonas.Show();
    cout << endl << endl;
    Joni.Show();
    
    cout << "\n\n-Altere a morada do Joni Rato: ";
    cin.getline(morada, sizeof morada); //cin >> morada;
    Joni.SetMorada(morada);
    cout << "Atualizado: ";
    Joni.Show();

    cout << "\n\n-Altere a data de nascimento do Joni Rato: " << endl;
    cin >> data;
    Joni.SetData(data);
    cout << "Atualizado: ";
    Joni.Show();
    
    cout << "\n\n-Introduzir novo usuario:" << endl;
    Utilizador.Readk();
    cout << "Atualizado: ";
    Utilizador.Show();
    cout << endl;

    cout << "\n-Introduzir novo administrador:" << endl;
    cin >> Administrador;
    cout << "Atualizado: " << Administrador;

    if(Utilizador == Administrador){
        cout << "\n\nUtilizador e Administrador tem o mesmo nome e data";
    }
    if(Utilizador != Administrador){
        cout << "\n\nUtilizador e Administrador sao pessoas diferentes";
    }
    
    cout << "\n";
    Utilizador.MaisNovo(Administrador);

    cout << "\n*Criacao de ficheiro com os dados de todas as pessoas*\n";
    cout << " Nome do ficheiro a salvar: ";
    cin >> nomeficheiro;
    nomeficheirotxt = nomeficheiro + ".txt";

    ofile.open(nomeficheirotxt);
    if(ofile){
        Jonas.Savefile(ofile);
        ofile << endl;
        Joni.Savefile(ofile);
        ofile << endl;
        Utilizador.Savefile(ofile);
        ofile << endl;
        Administrador.Savefile(ofile);
        ofile.close();
        cout << "Ficheiro " << nomeficheirotxt <<  " criado com sucesso!" << endl << endl;
    }else{
        cout << "ERRO - nao e possivel salvar o ficheiro " << nomeficheirotxt << endl << endl;
    }
    */
    cout << "\n*Leitura de ficheiro com os dados de todas as pessoas*\n";
    cout << " Nome do ficheiro a ler: ";
    cin >> nomeficheiro;
    nomeficheirotxt = nomeficheiro + ".txt";

    ifile.open(nomeficheirotxt);
    if(!ifile){
        cout << "ERRO - nao e possivel ler o ficheiro " << nomeficheirotxt << endl << endl;
    }else{
    Jonas.Readfile(ifile);
    Joni.Readfile(ifile);
    Utilizador.Readfile(ifile);
    Administrador.Readfile(ifile);
    ifile.close();
    cout << "Ficheiro " << nomeficheirotxt <<  " lido com sucesso!" << endl << endl;
    }

    cout << "\n*Ler dados de ficheiro para um vetor de objetos Pessoa*\n";
    cout << " Nome do ficheiro a ler: ";
    cin >> nomeficheiro;
    nomeficheirotxt = nomeficheiro + ".txt";

    ifile.open(nomeficheirotxt);
    //saber numero de linhas nao vazias
    
    if(ifile){
        cout << endl; // +facil para ver no terminal
        while(ifile){
            P[n].ReadFilePlus(ifile);
            ifile.get();
            cout << "P[" << n << "] lido." << endl;      
            n++;
        }
        ifile.close();
        cout << "Ficheiro " << nomeficheirotxt << " lido para memoria(vetor)." << endl << endl;
    }
    else{
        cout << "ERRO - nao e possivel ler o ficheiro " << nomeficheirotxt << endl << endl;
    }
    for(i = 0; i < n; i++){
        P[i].Show();
        cout << endl;
    }
    
    //apresentar dados de quem nasceu antes de 1990
    cout << "\nEstas pessoas nasceram antes de 1990: " << endl;
    for(i = 0; i < n; i++){
        if(P[i].GetData().GetAno() < 1990){
            cout << "\t";
            P[i].Show();
            cout << endl;
        }
    }
    
    return 0;   
}

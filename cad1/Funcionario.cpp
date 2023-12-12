#include "Funcionario.h"

// default 
Funcionario::Funcionario(){

}

// c/parametros
Funcionario::Funcionario(int _num_func, string _setor, string _nome, Data _data, string _morada):Pessoa(_nome, _data, _morada){
    num_func = _num_func;
    setor = _setor;
}

// Show
void Funcionario::Show(){
    cout << num_func << ";" << setor << ";";
    Pessoa::Show();
}

// set Funcionario
void Funcionario::SetFuncionario(){
    char aux[100];
    cout << "Novo Utilizador" << endl << endl;
    cout << " Dados Funcionario" << endl;
    cout << " Introduza o seu ID:";
    cin >> num_func;
    cout << " Indroduza o setor correspondente:";
    cin >> setor;
    cout << endl;
    cout << "Dados Pessoais" << endl;
    Pessoa::Readk();
}

//sobrecarga >>
istream & operator >> (istream &is, Funcionario &funcionario){
    char aux[100];
    cout << "Novo Utilizador" << endl << endl;
    cout << " Dados Funcionario" << endl;
    cout << " Introduza o seu ID:";
    is >> funcionario.num_func;
    cout << " Indroduza o setor correspondente:";
    is.ignore();
    is.getline(aux, sizeof aux);
    funcionario.SetSector(aux);
    cout << endl;
    cout << "Dados Pessoais" << endl;
    is >> (Pessoa &)funcionario;
    return is;
}

//Savefile
void Funcionario::Savefile(ofstream &os){
    os << num_func << ";" << setor << ";";
    Pessoa::Savefile(os);
}

//Readfile
void Funcionario::Readfile(ifstream &is){
    char aux[100];
    is.getline(aux, sizeof aux, ';');
    num_func = atoi(aux);
    is.getline(aux, sizeof aux, ';');
    setor = aux;
    Pessoa::ReadFilePlus(is);
}
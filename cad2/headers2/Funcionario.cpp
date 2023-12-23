#include "Funcionario.h"

// default 
Funcionario::Funcionario(){

}

// c/parametros
Funcionario::Funcionario(int _num_func, string _setor, string _nome, Data _data, string _morada, float _ord_base, int _h_extra, float _p_hora_extra):Pessoa(_nome, _data, _morada){
    num_func = _num_func;
    setor = _setor;
    ord_base = _ord_base;
    h_extra = _h_extra;
    p_hora_extra = _p_hora_extra;
}

// Show
void Funcionario::Show(){
    cout << num_func << ";" << setor << ";";
    Pessoa::Show();
    cout << ord_base << ";" << h_extra << ";" << p_hora_extra << ";";
}

// set Funcionario
void Funcionario::SetFuncionario(){
    char aux[100];
    cout << "Novo Utilizador" << endl << endl;
    cout << " Dados Funcionario" << endl;
    cout << " Introduza o ID:";
    cin >> num_func;
    cout << " Indroduza o setor:";
    cin >> setor;
    cout << endl;
    cout << "Dados Pessoais" << endl;
    Pessoa::Readk();
    cout << endl;
    cout << "Dados Economicos" << endl;
    cout << " Introduza o ordenado:";
    cin >> ord_base;
    cout << " Indroduza as horas extra:";
    cin >> h_extra;
    cout << " Indroduza o preco das horas extra:";
    cin >> p_hora_extra;

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
    cout << endl;
    cout << "Dados Economicos" << endl;
    cout << " Introduza o ordenado:";
    is >> funcionario.ord_base;
    cout << " Indroduza as horas extra:";
    is >> funcionario.h_extra;
    cout << " Indroduza o preco das horas extra:";
    is >> funcionario.p_hora_extra;
    return is;
}

//Savefile
void Funcionario::Savefile(ofstream &os){
    os << num_func << ";" << setor << ";";
    Pessoa::Savefile(os);
    os << ord_base << ";" << h_extra << ";" << p_hora_extra << ";";
}

//Readfile
void Funcionario::Readfile(ifstream &is){
    char aux[100];
    is.getline(aux, sizeof aux, ';');
    num_func = atoi(aux);
    is.getline(aux, sizeof aux, ';');
    setor = aux;
    Pessoa::ReadFilePlus(is);
    is.getline(aux, sizeof aux, ';');
    ord_base = atof(aux);
    is.getline(aux, sizeof aux, ';');
    h_extra = atoi(aux);
    is.getline(aux, sizeof aux, ';');
    p_hora_extra = atof(aux);
}
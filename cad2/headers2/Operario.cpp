#include "Operario.h"

Operario::Operario() : Funcionario(){
    SetPHExtra(8);
}

Operario::Operario(int _num_func, string _setor, string _nome, Data _data, string _morada, float _ord_base, int _h_extra, float _p_hora_extra, bool _f_turno) 
  : Funcionario(_num_func, _setor, _nome, _data, _morada, _ord_base, _h_extra, 8){
    f_turno = _f_turno;
}

void Operario::Show(){
    Funcionario::Show();

    cout << f_turno << ";";
}

void Operario::SetOperario(){
    Funcionario::SetFuncionario();
    cout << "Trabalha por turno: (S/N)";
	string op;
	cin >> op;
	if (op == "S")
	{
		f_turno = true;
	}
	else
	{
		f_turno = false;
	}
}

float Operario::Calcula_ordenado(){
    if(f_turno){
        return GetOrdBase() * 1.25 + GetHExtra() + GetPHExtra();
    }else{
        return GetOrdBase() * 1.25 + GetHExtra() + GetPHExtra();
    }
}

void Operario::Savefile(ofstream &of){
	Funcionario::Savefile(of);
	of << f_turno << ";";
}

void Operario::Readfile(ifstream & is){
    Funcionario::Readfile(is);

	string turno;
	getline(is, turno, ';');
	if (turno == "sim"){
		f_turno = true;			 
	}
	else{
		f_turno = false;
	}
}
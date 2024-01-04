#include "Gestor_Func.h"

bool Gestor_Func::RemoverFunc(int num)
{
	//remover com a ajuda de um iterador
	list<Func*>::iterator pos = Lista.begin();
	do {
		// (*pos) acede ao conteudo da posição na lista, no caso ao funcionario
		if ( (*pos)->GetNum() == num )
		{
			Lista.erase(pos);
			return true;
			// ou break;
			//Lista.remove(*pos);
		}
		pos++;//avança para a posição seguinte
	} while (pos != Lista.end());

	//alternativa - remover 

	for (Func* f : Lista)
	{
		if (f->GetNum() == num)
		{
			Lista.remove(f);
			return true; // ou break;
		}
	}

	return false;


}

bool Gestor_Func::RemoverFunc(string Nome)
{
	for (Func* f : Lista)
	{
		if (f->GetNome() == Nome) 
		{
			Lista.remove(f);
			return true; // ou break;
		}
	}

	return false;
}

void Gestor_Func::Show()
{
	cout << "------------------------------- Lista de Funcionarios ------------------------------------" << endl;
	for (Func *f : Lista)
	{
		if (Operario *op = dynamic_cast<Operario*>(f))
		{
			op->Show();
		}
		else {
			f->Show();
		}
		cout << endl << endl;
	}

	cout << "------------------------------------------------------------------------------------------" << endl;

}


void Gestor_Func::AdicionarFunc(Func* _f)
{
	//para evitar duplicados
	for (Func* f : Lista)
	{
		if (f->GetNum() == _f->GetNum()) //se for igual já existe
		{
			return;
		}
	}

	Lista.push_back(_f);
}




Gestor_Func::Gestor_Func()
{
}


Gestor_Func::~Gestor_Func()
{
}

void Gestor_Func::ReadFile()
{
	ifstream file;
	file.open("funcionarios.txt");
	if (!file.is_open())
	{
		return;
	}

	do
	{
		string tipo;
		getline(file, tipo, ':'); // atenção ao caracter
		if (tipo == "O")
		{
			Operario *op = new Operario();
			op->ReadFile(file);
			this->AdicionarFunc(op);
				//ou 
			//Lista.push_back(op);
		}
		else if (tipo == "A")
		{
			Administrativo *adm = new Administrativo();
			adm->ReadFile(file);
			this->AdicionarFunc(adm); //alternativa Lista.push_back(adm)
		}
		file.ignore(INT16_MAX, '\n');
	} while (file.peek() != EOF);

	file.close();
}

void Gestor_Func::SaveFile()
{
	ofstream file;
	file.open("funcionarios.txt");
	if (!file.is_open())
	{
		return;
	}

	for (Func* f : Lista)
	{
		if (Operario* op = dynamic_cast<Operario*>(f))
		{
			file << "O:";
			op->SaveFile(file);
		}

		if (Administrativo *adm = dynamic_cast<Administrativo*>(f))
		{
			file << "A:";
			adm->SaveFile(file);
		}

		file << endl;
	}
	
	file.close();
}

istream & operator>>(istream & is, Gestor_Func & gf)
{
	cout << "Deseja inserir:" << endl
		<< "O - Operário" << endl
		<< "A - Administrativo" << endl
		<< ">";
	string tipo;
	getline(is, tipo, '\n');

	if (tipo == "O" || tipo == "o")
	{
		Operario *op = new Operario();
		op->ReadK();
		gf.AdicionarFunc(op);
	}
	else if(tipo == "A" || tipo == "a")
	{
		Administrativo *adm = new Administrativo();
		adm->ReadK();
		gf.AdicionarFunc(adm);
	}

	is.ignore(INT16_MAX, '\n');//limpar o buffer

	cout << "Deseja Inserir Mais (S/N)" << endl;
	string op;
	getline(is, op, '\n');
	
	if (op == "S" || op == "s")
	{
		is >> gf; //voltamos a chamar o operador
	}
	return is;
}

ostream & operator<<(ostream & os,  Gestor_Func gf)
{
	gf.Show();
	return os;
}

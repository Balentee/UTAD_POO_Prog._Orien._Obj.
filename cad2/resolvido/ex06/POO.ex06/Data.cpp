
#include "Data.h"


Data::Data()
{
	//dia = mes = ano = 0;
}

Data::~Data()
{
}

Data::Data(int _dia, int _mes, int _ano)
{
	dia = _dia;
	mes = _mes;
	ano = _ano;
}

void Data::Show(void)
{
	cout << GetDia() << "/" << GetMes() << "/" << GetAno() << "\n";
}

void Data::Update(int _dia, int _mes, int _ano)
{
	SetDia(_dia);// dia = _dia;
	SetMes(_mes);//	mes = _mes;
	SetAno(_ano);//	ano = _ano;
}

bool Data::Igual(const Data data)
{
	if (data.ano != ano || data.mes != mes || data.dia != dia)
		return(false);
	return(true);
}

ostream & operator << (ostream &os, const Data data)
{
	os << data.dia << "/" << data.mes << "/" << data.ano ;

	return os;
}

istream & operator >> (istream &is, Data &data)
{
	int aux;
		
	cout << "Dia: ";
	is >> aux;
	//is>>data.dia;
	data.SetDia(aux);
	cout << "Mês: ";
	is >> data.mes;
	cout << "Ano: ";
	is >> data.ano;

	return is;
}

bool Data::operator == (const Data data) const
{
	if (data.ano != ano || data.mes != mes || data.dia != dia)
		return(false);
	return(true);
}

bool Data::operator < (const Data data) const
{
	if (data.ano < ano)
		return(false);
	else	if (data.ano == ano && data.mes < mes)
		return(false);
	else	if (data.ano == ano && data.mes == mes && data.dia < dia)
		return(false);
	return(true);
}

bool Data::operator >(const Data data) const
{
	if (data.ano > ano)
		return(false);
	else	if (data.ano == ano && data.mes > mes)
		return(false);
	else	if (data.ano == ano && data.mes == mes && data.dia > dia)
		return(false);
	return(true);
}

void Data::SaveFile(ofstream &os)
{
	os << GetDia() << "/" << GetMes() << "/" << GetAno() << ";"<<"\n";
}

void Data::ReadFile(ifstream &is)
{
	char aux[10];

	is.getline(aux, 10, '/');
	dia = atoi(aux);
	is.getline(aux, 10, '/');
	mes = atoi(aux);
	is.getline(aux, 10, ';');
	ano = atoi(aux);
}
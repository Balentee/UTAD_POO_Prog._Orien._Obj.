#include "Pessoa.h" // classe Pessoa

void Pessoa::Show(){
    cout << GetNome() << ";";
    data.Show();
    cout << ";" << GetMorada();
}

void Pessoa::Readk(){
    char aux[100];
    cout << "Introduza nome: ";
    cin.ignore();
    cin.getline(aux, sizeof aux);
    nome = aux;
    cout << "Introduza data: " << endl;
    cin >> data;
    cout << "Introduza morada: ";
    cin.ignore();
    cin.getline(aux, sizeof aux);
    morada = aux;
}       

void Pessoa::Savefile(ofstream& os){
    os << nome << ";" << data << ";" << morada << ";";
}

void Pessoa::Readfile(ifstream& is){
    string line;
    while(getline(is, line)){
        cout << line << endl;
}
}

void Pessoa::ReadFilePlus(ifstream& is){
    char aux[100];
    is.getline(aux, sizeof aux, ';');
    nome = aux;
    is.getline(aux, sizeof aux, '/');
    data.SetDia(atoi(aux));
    is.getline(aux, sizeof aux, '/');
    data.SetMes(atoi(aux));
    is.getline(aux, sizeof aux, ';');
    data.SetAno(atoi(aux)); 
    is.getline(aux, sizeof aux, ';');
    morada = aux;
}

bool Pessoa::MaisNovo(Pessoa x){
    if(data == x.data){
        cout << "\nAs duas pessoas tem a mesma idade." << endl;
        return false;
    }
    cout << "\nA pessoa mais nova e: ";
    if(data.GetAno() > x.data.GetAno()){
        Show();
        return true;
    }else if (data.GetMes() > x.data.GetMes() && data.GetAno() == x.data.GetAno()){
        Show();
        return true;  
    }else if (data.GetDia() > x.data.GetDia() && data.GetMes() == x.data.GetMes() && data.GetAno() == x.data.GetAno()){
        Show();
        return true;
    }else{
        x.Show();
        return true;
    }
}

bool Pessoa::operator ==(Pessoa x){
    if (x.nome == GetNome() && x.data == GetData()){
        return true;
    }else{
        return false;
    }
}

bool Pessoa::operator !=(Pessoa x){
    if (x.nome == GetNome() && x.data == GetData()){
        return false;
    }else{
        return true;
    }
}

ostream & operator << (ostream &os, Pessoa pessoa) {
    os << pessoa.GetNome() << ";" << pessoa.GetData() << ";" << pessoa.GetMorada();
    return os;
}

istream & operator >> (istream &is, Pessoa &pessoa) {
    char aux[100];
    cout << "Introduza nome: ";
    is.getline(aux, sizeof aux);
    pessoa.SetNome(aux);
    cout << "Introduza data: " << endl;
    is >> pessoa.data;
    pessoa.SetData(pessoa.data);
    cout << "Introduza morada: ";
    is.ignore();
    is.getline(aux, sizeof aux);
    pessoa.SetMorada(aux);
    return is;
}
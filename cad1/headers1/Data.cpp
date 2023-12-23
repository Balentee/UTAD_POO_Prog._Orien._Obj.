#include "Data.h" // classe Data

/*Implemente para a classe Data o método Igual() para verificar se dois objectos do tipo
Data são iguais. O método deve devolver true se forem iguais e false caso contrário.*/
bool Data::Igual(Data x){
    if(x.ano != GetAno() || x.mes != GetMes() || x.dia != GetDia()){
        //std::cout << "false\n\n";    //debug 
        return(false);
    }else {
        //std::cout << "true\n\n";     //debug
        return(true);
    }
}
/*Verifique se dois objectos do tipo Data são iguais fazendo a sobrecarga do operador “==”.*/
bool Data::operator==(Data x){
    if(x.ano != GetAno() || x.mes != GetMes() || x.dia != GetDia()){
        //std::cout << "false\n\n";    //debug 
        return(false);
    }else {
        //std::cout << "true\n\n";     //debug
        return(true);
    }
}
/*Implemente a sobrecarga dos operadores “!=”, “<<” e “>>”.*/
bool Data::operator!=(Data x){
    if(x.ano != GetAno() || x.mes != GetMes() || x.dia != GetDia()){
        //std::cout << "false\n\n";    //debug 
        return(true);
    }else {
        //std::cout << "true\n\n";     //debug
        return(false);
    }
}
// sobrecarga operador "<<"
ostream & operator << (ostream &os, Data data) {
    os << data.GetDia() << "/" << data.GetMes() << "/" << data.GetAno();
    return os;
}
//sobrecarga operador ">>"
istream & operator>>(istream &is, Data &data) {
    int x;
    std::cout << "\tIntroduzir dia:";
    is >> x;
    data.SetDia(x);
    std::cout << "\tIntroduzir mes:";
    is >> x;
    data.SetMes(x);
    std::cout << "\tIntroduzir ano:";
    is >> x;
    data.SetAno(x);
    return is;
}
//salvar ficheiro
void Data::SaveFile(ofstream& os){
    os << "Data:" << GetDia() << "/" << GetMes() << "/" << GetAno() << endl;
}
//ler ficheiro
void Data::ReadFile(ifstream& is){
    string line;
    while(getline(is,line)){
        cout << line << endl;
    }
}

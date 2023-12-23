#include <iostream> // Input/Output
#include <iomanip> // Formatting
#include <fstream > // Filestreams
#include "headers1/Data.h" // classe Data
#include "headers1/Data.cpp" // cpp da classe Data

using namespace std;

int main(){
    /*Crie 2 objetos do tipo Data usando para um o construtor por defeito e para outro o
    construtor por parâmetros.*/
    Data defaultData;
    Data paramData(16,10,2023);
    //Criar novo objeto Data
    Data newData(00,00,0000);
    
    /*Invoque o método Show() usando cada um dos objetos anteriormente criados.*/
    cout << "\nData default: ";
    defaultData.Show();
    cout << "\nData criacao do programa: ";
    paramData.Show();

    /*Altere os atributos do objeto criado com o construtor por defeito com dados
    introduzidos pelo utilizador através do teclado.*/
    int ndia, nmes, nano;

    cout << "\nAlterar data por defeito" << endl;
    cout << "Digite novo dia: ";
    cin >> ndia;
    cout << "Digite novo mes: ";
    cin >> nmes;
    cout << "Digite novo ano: ";
    cin >> nano;
    defaultData.Update(ndia, nmes, nano);

    /*Altere os atributos do objeto criado com o construtor por parâmetros usando o
    método Update().*/
    paramData.Update(30, 10, 2023);

    /*Show alteracoes às datas*/
    cout << "\nData escolhida: ";
    defaultData.Show();
    cout << "\nData de conclusao do programa: ";
    paramData.Show();
    cout << endl;
    
    cout << "Comparar datas: " << endl;
    // Funcao para ver se 2 datas são iguais
    cout << "Ao comparar com funcao Igual(): ";
    if (defaultData.Igual(paramData)){
        cout << "As datas sao iguais\n\n";
    }else{
        cout << "As datas sao diferentes\n\n";
    }

    // O mesmo que a função anterior mas com SOBRECARGA DE OPERADORES (==)
    cout << "Ao comparar com sobrecarga '==': ";
    if (defaultData == paramData) {
        cout << "As datas sao iguais\n\n";
    }else{
        cout << "As datas sao diferentes\n\n";
    }

    // sobrecarga de operadores "!="
    cout << "Ao comparar com sobrecarga '!=': ";
    if (defaultData != paramData) {
        cout << "As datas sao diferentes\n";
    }else {
        cout << "As data sao iguais\n";
    }

    //sobrecarga de operadores ">>" e "<<"
    cout << "Nova data: " << endl;
    
    // mesmo que .Update mas com operador "<<"
    cin >> newData;
    
    // mesmo que .Show mas com operador ">>"
    cout << "\nMostrar data sem parametros:";
    cout << defaultData;
    cout << "\nMostrar data com parametros:";
    cout << paramData;
    cout << "\nMostrar nova data:";
    cout << newData;
    cout << endl;
    
    //SALVAR E LER FICHEIRO:
    ifstream is;
    ofstream os;

    os.open("data.txt");
    if(!os){
        cout << "ERRO: nao e possivel abrir o ficheiro data.txt" << endl;
        exit(1);
    }
    defaultData.SaveFile(os);
    paramData.SaveFile(os);
    newData.SaveFile(os);
    os.close();

    is.open("data.txt");
    if(!is){
        cout << "ERRO: nao e possivel abrir o ficheiro data.txt" << endl;
        exit(1);
    }
    defaultData.ReadFile(is);
    paramData.ReadFile(is);
    newData.ReadFile(is);
    is.close();

    system("pause");
    return 0;
}
#include <iostream> // Input/Output
#include <iomanip> // Formatting
#include <fstream > // Filestreams

using namespace std;


// ABSTRATO, NAO O QUE ERA PEDIDO EM SI


// 3. Classes

// 3a - Implemente dois construtores para a classe Data. Um construtor por defeito (sem parâmetros)
//      e um construtor com parâmetros definidos pelo utilizador.
class Data{
private:
   int dia;
   int mes;
   int ano;

public:
    //Responsavel por

    //Construtor padrão (sem parametros)
    Data() : dia{1}, mes{1}, ano{2023} {cout << "Data sem parametro: " << dia << "/" << mes << "/"<< ano << endl;};

    //Construtor com parametrização
    Data(int d, int m, int a) : dia(d), mes(m), ano(a) {cout << "Data parametrizada: " << d << "/" << m << "/"<< a << endl;};
    
    // Destructor
    //virtual ~Data();

    //inline: -> que vai estar definido e implementado diretamente (ajuda na performance, nao necessario)
    //no .h. quando os métodos são bastante simples
    inline void SetDia (int d){
        dia = d;
    }
    inline void SetMes (int m){
        mes = m;
    }
    inline void SetAno (int a){
            ano = a;
        }
    inline int GetDia (int d){
            return dia;
        }
    inline int GetMes (int m){
            return mes;
        }
    inline int GetAno (int a){
            return ano;
        }

    void Show(int d, int m, int a){
        // era para escrever mas armei me em mitra
    }
    
    void Update(int d, int m, int a){
        SetDia(d);
        SetMes(m);
        SetAno(a);
    }
};


int main(){
    Data();
    Data(5,10,15);

    system("pause");
    return 0;
}
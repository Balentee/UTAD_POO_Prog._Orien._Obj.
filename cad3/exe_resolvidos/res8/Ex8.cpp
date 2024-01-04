#include <iostream>
#include <locale>
#include"Gestor_Func.h"
int main() {
	setlocale(LC_ALL, "");//resolve o problema dos acentos

	//8.3 a)
	Gestor_Func gestor;

	gestor.ReadFile();


	//8.3 c
	gestor.Show();


	//8.3 -b
	/*O: Zeca Estacionancio;1/1/1985;Rua A n9;25050;Pintura;1100;15;nao; 
	  A:Adrusila Lopes;6/6/1996;Rua E n6;25051;RecHumanos;900;0; */

	Operario *op = new Operario(25050, "Pintura", "Zeca Estacionâncio", 
							"Rua A n9", 1, 1, 1985, 1100, 15, false);
	gestor.AdicionarFunc(op);

	Administrativo *adm = new Administrativo(25051, "RecHumanos",
						"Adrusila Lopes", "Rua E n6", 6, 6, 1996, 900, 0);
	gestor.AdicionarFunc(adm);

	//8.3 c
	gestor.Show();

	//8-d
	gestor.RemoverFunc(25024); //remover o Joni pelo numero;
	gestor.RemoverFunc("Joni Rato");

	//ler do teclado /8.2 -d
	cin >> gestor;
	//mostrar no teclado 8.2 b
	cout << gestor;


	//ou 
	gestor.Show();

	//8-e
	gestor.SaveFile();

	

	getchar(); // para não fechar a consola
	return 0;
}
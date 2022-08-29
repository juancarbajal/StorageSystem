#include<iostream>
#include<cmath>
#include<string>
#include <iomanip>
using namespace std;

const int MAXIMO = 100;
int main() {
	int n = 0;
	float mantenimiento;
	string  nombre[MAXIMO];
	float producto[MAXIMO][2];
	string strNombre,strPrecio;
	system("clear");
	//numero de elementos para el arreglo
	cout << "SISTEMA DE INVENTARIO" << "\n";
	cout << "---------------------" << "\n";
	cout << "Digite el numero de productos a registrar (max " << MAXIMO << " )...: " << endl;
	cin >> n;
	if ((n < 0) || (n > MAXIMO)) {
		cout << "No se registro ningun elemento, el numero introducido no es valido" << endl;
		return 0;
	}
	cout << endl << "INGRESO DE PRODUCTOS" << endl;
	for(int i=0; i<n; i++) {
		cout << "\n" << "Producto " << i+1 << endl;
		cout << "Ingrese el nombre del producto...:" << endl;
		cin >> strNombre;
		cout << "Ingrese el precio del producto...:" << endl;
		cin >> strPrecio;

		nombre[i] = strNombre;
		producto[i][0] = stof(strPrecio);
		
		//Calculo del nuevo campo
		float cambio = producto[i][0];
		float precio = cambio * 10;
		if (precio<10) 
			mantenimiento=0;
		else if (precio>=10 && precio<=35) 
			mantenimiento = precio*0.20;
		else if (precio>=36 && precio<=55) 
			mantenimiento = precio*0.28;
		else if (precio>=56 && precio<=100) 
			mantenimiento = precio*0.45;
		else 
			mantenimiento = precio*0.6;
		producto[i][1] = round((mantenimiento+precio) *100)/100;
		producto[i][0] = round(producto[i][0] *100) /100;
		cout << "Mantenimiento ..:" << producto[i][1] << endl;
	}

	cout <<endl <<"El nombre y el precio final a pagar por el articulo es...: "<<endl;

	cout << setw(3)<< "Id" << setw(30) << "Producto " <<setw(10)<< "Precio" << setw(20)<< "Mantenimiento" << "\n";

	for (int i = 0; i < n; i++){
		cout << setw(3)<< i+1 << setw(30)<< nombre[i]  << setw(10) << producto[i][0] << setw(20)<< producto[i][1] << endl;
	}
	cout << "Termino del programa" << endl;

}

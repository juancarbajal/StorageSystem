#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n = 0;
    float mantenimiento;
    string opcion;

    do {
        //numero de elementos para el arreglo
        cout << "Digite el numero de productos a registrar(maximo 100): "<<endl;
        cin >> n;

        string productos[n][2];

        if(n != 0 && n <= 100){
            //llenar el arreglo
            cout<<"Digite el nombre y el peso del articulo:"<<endl;
            for(int i=0; i<n; i++) {
                for(int j=0; j<2; j++) {
                    cout<<"Digite un elemento ["<<i<<"]["<<j<<"]: "<<endl;
                    cin>>productos[i][j];
                }
            }
        }else{
            cout<<"No se registro ningun elemento, el numero introducido no es valido"<<endl;
            return 0;
        }

        //calcular el precio dependiendo del peso
        for(int i=0;i<n;i++){
            float cambio = stof(productos[i][1]);
            float precio = cambio * 10;

            //sacarle el mantenimiento al producto
            if (precio<10) {
                mantenimiento=0;
            } else {
                if (precio>=10 && precio<=35) {
                    mantenimiento = precio*0.20;
                } else {
                    if (precio>=36 && precio<=55) {
                        mantenimiento = precio*0.28;
                    } else {
                        if (precio>=56 && precio<=100) {
                            mantenimiento = precio*0.45;
                        } else {
                            mantenimiento = precio*0.6;
                        }
                    }
                }
            }
            productos[i][1] = to_string(round(mantenimiento+precio));
        }

        cout<<"El nombre y el precio final a pagar por el articulo es: "<<endl;

        //mostrar el arreglo
        for(int i=0; i<n; i++) {
            cout<<" "<<i+1<<"|";
            for(int j=0; j<2; j++) {
                cout<<productos[i][j]<<"  ";
            }
            cout<<endl;
        }

        do {
            cout<<"¿Desea añadir mas articulos? si(s) o no (n)"<<endl;
            cin>>opcion;

            if (opcion == "n" || opcion == "N"){
                cout<<"No se va a ingresar mas datos. Fin"<<endl;
                return 0;
            }else if (opcion != "s" && opcion != "S"){
                cout<<"Dijito no valido"<<endl;
            }
        } while (opcion != "s" && opcion != "S");

    } while ( opcion == "s" || opcion == "S");
}
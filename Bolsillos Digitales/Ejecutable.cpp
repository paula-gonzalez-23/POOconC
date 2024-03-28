#include <iostream>
#include "Nequi.cpp"
using namespace std;

int main (){

    int opcion;

    Nequi user;

    user.llenarUsuarios();

    do {
        
        user.menu();

        cout << "Elija la opcion que quiere realizar el dia de hoy" << endl;
        cin >> opcion;

        switch (opcion){
            case 1:
                user.recargarNequi();
                break;
            case 2:
                user.colchon();
                break;
            case 3:
                user.meta();
                break;
            case 4: 
                user.bolsillos();
                break;
            case 5:
                user.sacarPlata();
                break;
            case 6:
                user.verMovimientos();
                break;
            case 7:
                cout << "Gracias por usar Nequi. Nos vemos pronto" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }

    } while (opcion != 7);

    return 0;


}
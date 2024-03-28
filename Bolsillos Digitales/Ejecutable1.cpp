#include <iostream>
#include "Daviplata.cpp"
using namespace std;

int main (){

    int opcion;

    Daviplata user;

    if (!user.llenarUsuarios()){
        cout << "El acceso fue denegado. Las credenciales no coinciden" << endl;
        return 1;
    }

    do {
        
        user.menu();

        cout << "Elija la opcion que quiere realizar el dia de hoy" << endl;
        cin >> opcion;

        switch (opcion){
            case 1:
                user.recargarDaviplata();
                break;
            case 2:
                user.realizarPagos();
                break;
            case 3:
                user.verMovimientos();
                break;
            case 4:
                cout << "Gracias por usar Daviplata. Nos vemos pronto" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }

    } while (opcion != 4);

    return 0;


}
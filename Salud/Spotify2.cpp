#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main () {

    list<string>listaGeneral;

    string nuevaCancion;

    cout<<"Ingresa el nombre de las canciones que quieres agregar a la lista general: (pon 0 para salir)"<<endl;
    cin>>nuevaCancion;

    while (nuevaCancion != "0"){

        listaGeneral.push_back(nuevaCancion);
        cin>>nuevaCancion;
    }

    cout<<"La lista General de canciones es: ";
    for (string cancion : listaGeneral){
        cout<<cancion<<", ";
    }
    cout<<endl;

    list<string>listaPaula;

    string newSong;

    cout<<"Ingresa el nombre de las canciones que quieres agregar a la lista de Paula: (pon 0 para salir)"<<endl;
    cin>>newSong;

    while (newSong != "0"){

        if (find(listaGeneral.begin(), listaGeneral.end(), newSong) != listaGeneral.end()) {
            listaPaula.push_back(newSong);
            cout << newSong <<" - La cancion se ha agregado satisfactoriamente a la Lista Paula" << endl;
        } else {
            cout << newSong <<" - La cancion no existe en la lista general" << endl;
        }

        cin>>newSong;
    }

    cout<<"La lista Paula es: ";
    for (string cancion : listaPaula){
        cout<<cancion<<", ";
    }
    cout<<endl;

    return 0;
}
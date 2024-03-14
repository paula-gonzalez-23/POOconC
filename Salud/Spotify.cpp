#include <iostream>
#include <list>
using namespace std;

int main (){

    
    int contador = 0;

    list<list<string>>canciones = {

        {"Reggaeton"}, //Categoria 0
        {"Salsa"}, //Categoria 1
        {"Vallenato"}, //Categoria 2
        {"Musica Popular"}, //Categoria 3
        {"Rock"} //Categoria 4

    };

    cout<<"Categorias Disponibles"<<endl;

    for (const auto & categoria : canciones){
        cout<<contador<<". ";
        for (const auto & cancion : categoria){
            cout<<cancion<<" ";
        }

        cout<<endl;
        
        contador ++;
    }

    return 0;

}
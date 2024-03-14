#include <iostream>
#include <list>
using namespace std;


int main(){

    

    list<string>frutas;
    frutas.push_back("manzana");
    frutas.push_back("pera");
    frutas.push_back("uvas");
    frutas.push_back("melon");
    frutas.push_back("fresa");

    //auto es el iterador 

    for (const auto & elemento: frutas){

        cout<<elemento<<"";

    }

    auto it = next(frutas.begin(),2);
    
    frutas.insert(it,"arandanos");

    for (const auto & elemento: frutas){

        cout<<elemento<<"";

    }

    //elimina el primer elemento pop_front
    //elimina el ultimo elemento pop_back

    frutas.pop_front();

    //erase es la posicion
    //remove es cuando conozco el elemento 

    auto it1 = next(frutas.begin(),2);

    frutas.erase(it1);
    frutas.remove("uvas");

    //front imprime el primer valor
    //back imprime el ultimo valor

    frutas.front();
    frutas.back();
    
    auto it2 = next(frutas.begin(),4);

    cout<<*it2;

    //referencia de memoria de la lista
    frutas.get_allocator();

    //lista vacia
    frutas.clear();

    //si esta vacia o no
    frutas.empty();

    //tamanio de la lista
    frutas.size();

    //numero maximo de elementos que puedo agregar a la lista
    frutas.max_size();

    //crear una lista como spotify, lista de diferentes generos 
    //el usuario puede crear una lista de reproduccion basada en la lista general
    //lista enlazada con un amigo 


    return 0;
}




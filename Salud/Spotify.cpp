#include <iostream>
#include <list>
using namespace std;

class Cancion {

    //Determinamos los atributos 

    private:

    string titulo;
    Cancion* siguiente;

    //Determinamos el constructor, accesores y metodos

    public:

    //Constructor con parametros

    Cancion (string _titulo){

        titulo = _titulo;
        siguiente = nullptr;
        
    }

    //Metodos

    //Metodo para establecer la siguiente cancion de la lista

    void asignarSiguiente(Cancion* siguienteCancion){

        siguiente = siguienteCancion;
    }
};

class ListaCanciones{

    //Determinamos los atributos

    private:

    Cancion* primerCancion;
    Cancion* ultimaCancion;

    //Determinamos el constructor, accesores y metodos

    public:

    //Constructor 

    ListaCanciones(){

        primerCancion = nullptr;
        ultimaCancion = nullptr;
    }

    //Metodos

    void agregarCancion(const Cancion& cancion){
        //Se crea una instancia de la clase cancion, llamando al constructor de copia 
        Cancion* nuevaCancion = new Cancion(cancion);
        //Se verifica si la lista esta vacia 
        if (!primerCancion){
            //Si esta vacia, se establece la nueva cancion como la primera y la ultima
            primerCancion = nuevaCancion;
            ultimaCancion = nuevaCancion;
        }else {
            //Si no esta vacia, se agrega al final de la lista
            //Se establece la nueva cancion como la siguiente de la ultima cancion actual
            ultimaCancion -> asignarSiguiente(nuevaCancion);
            //Se actualiza el puntero de la ultima cancion para que apunte a la nueva cancion
            ultimaCancion = nuevaCancion;
        }
    }


}

int main (){

    return 0;

}
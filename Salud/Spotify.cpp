#include <iostream>
#include <list>
using namespace std;

//Este spotify es el que yo habia hecho antes de la clase 

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

    //Setter para establecer el titulo de la cancion
    void establecerTitulo(const string& nuevoTitulo){
        titulo = nuevoTitulo;
    }

    //Getter para obtener el titulo de la cancion
    string obtenerTitulo() const { 
        return titulo;
    }

    //Setter para establecer la siguiente cancion en la lista
    void establecerSiguiente(Cancion* nuevaSiguiente){
        siguiente = nuevaSiguiente;
    }

    //Getter para obtener la siguiente cancion en la lista
    Cancion* obtenerSiguiente() const {
        return siguiente;
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

    void mostrarCanciones() const {
        //Se define un puntero que apunta a la primera cancion de la lista
        Cancion* actual = primerCancion;
        while(actual){
            //Accedemos directamente al atributo titulo
            cout<<"- "<<actual->obtenerTitulo()<<endl;
            //Accedemos directamente al puntero siguiente
            actual = actual->obtenerSiguiente();
        }
    }

    bool contiene(const string& titulo) const{
        Cancion* actual = primerCancion;
        while (actual){
            if (actual->obtenerTitulo() == titulo)
                return true;
            actual = actual->obtenerSiguiente();
        }
        return false;
    }

    void imprimirLista() const {
        cout<<"Lista General de Canciones: "<<endl;
        mostrarCanciones();
    }
};

class Usuario {

    private:

    string nombre;
    ListaCanciones* listaCanciones;

    public:

    //Constructor

    Usuario (string _nombre){

        nombre = _nombre;
        listaCanciones = nullptr;
    }

    void agregarCancion(ListaCanciones& listaGeneral, const string& titulo){
        if (listaGeneral.contiene(titulo)){
            if(!listaCanciones)
                listaCanciones = new ListaCanciones();
            listaCanciones->agregarCancion(Cancion(titulo));
        }else {
            cout <<"La cancion "<<titulo<<" no se encuentra en la lista general"<<endl;
        }
    }

    void mostrarListaCanciones() const {
        if (listaCanciones){
            cout<<"Lista de canciones de "<<nombre<< ":"<<endl;
            listaCanciones->mostrarCanciones();
        }else {
            cout<<"No se ha creado ninguna lista de canciones para "<<nombre<<endl;
        }
    }    
};

int main (){

    //Crear lista general de canciones
    ListaCanciones listaGeneral;
    listaGeneral.agregarCancion(Cancion("Amargura"));
    listaGeneral.agregarCancion(Cancion("Bubalu"));
    listaGeneral.agregarCancion(Cancion("Lolipop"));

    listaGeneral.imprimirLista();
    
    //Crear usuario 1 con una lista que contiene canciones seleccionadas de la lista general
    Usuario usuario1("Paula Gonzalez");
    usuario1.agregarCancion(listaGeneral, "Amargura");
    usuario1.agregarCancion(listaGeneral, "Lolipop");

    Usuario usuario2("Paula y Mafe");
    usuario2.agregarCancion(listaGeneral, "Amargura");
    usuario2.agregarCancion(listaGeneral, "Bubalu");

    usuario1.mostrarListaCanciones();
    usuario2.mostrarListaCanciones();

    return 0;

}
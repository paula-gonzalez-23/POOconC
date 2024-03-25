#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

//Este spotify es el que hice de acuerdo a la clase, arregle lo que estaba mal y agregue lo indicado

class ListaEnlazada {

    private:

    struct Node {

        string data;
        Node* next;

        Node(string val) : data(val), next(nullptr){}
    };

    Node* head;

    public:

    ListaEnlazada() {

        head = nullptr;
    }

    void insertarNodo(string val){

        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void imprimirLista(){

        Node* current = head;
        while (current != nullptr){
            cout<<current->data<<", ";
            current = current->next;
        }

        cout << endl;
    }

    void construirListaEnlazada(const list<string>& listaPaula, const list<string>& listaPaula2){
        for (auto it = listaPaula2.rbegin(); it != listaPaula2.rend(); ++it){
            insertarNodo(*it);
        }

        for (auto it = listaPaula.rbegin(); it != listaPaula.rend(); ++it){
            insertarNodo(*it);
        }
        
    }

};

class Spotify2 {

    //Atributos

    private:
    
    list<string>listaGeneral;
    list<string>listaPaula;
    list<string>listaPaula2;

    public:

    //Constructor
    Spotify2(){

    }

    //Accesores set para modificar y get para mostrar 

    void agregarCancionGeneral(const string& cancion){
        listaGeneral.push_back(cancion);
    }

    const list<string>& getlistaGeneral() const{
        return listaGeneral;
    }

    void agregarCancionPaula(const string& cancion){
        listaPaula.push_back(cancion);
    }

    const list<string>& getlistaPaula() const{
        return listaPaula;
    }

    void agregarCancionPaula2(const string& cancion){
        listaPaula2.push_back(cancion);
    }

    const list<string>& getlistaPaula2() const{
        return listaPaula2;
    }

    //Metodos

    void llenarListaGeneral(){
        string cancion;
        cout << "ingrese las canciones para la lista general (escriba 'fin' para terminar)" << endl;
        while (true){
            cin >> cancion;
            if (cancion == "fin"){
                break;
            }
            agregarCancionGeneral(cancion);
        }
    }

    void llenarListaPaula(){
        string cancion;
        cout << "ingrese las canciones para la lista Paula(escriba 'fin' para terminar)" << endl;
        while (true){
            cin >> cancion;
            if (cancion == "fin"){
                break;
            }
            
            auto it = find(listaGeneral.begin(), listaGeneral.end(), cancion);
            if (it != listaGeneral.end()){
                listaPaula.push_back(cancion);
                cout << cancion << " - La cancion se ha agregado satisfactoriamente a la lista Paula" << endl;
            }else {
                cout << cancion <<" - La cancion no existe en la lista general" << endl;
                cout <<"Desea agregar la cancion a la lista general?" << endl;
                cout <<"1. Si" << endl;
                cout <<"2. No" << endl;
                int seleccion;
                cin >>seleccion;

                if (seleccion == 1){
                    agregarCancionGeneral(cancion);
                    cout << "La cancion se ha agregado satisfactoriamente a la Lista General" << endl;
                    cout <<"Siga ingresando las canciones que quiere agregar a la Lista Paula" << endl;
                }else if (seleccion == 2){
                    cout << "La cancion no se puede agregar a  Lista Paula porque no existe en Lista General" << endl;
                }
            }
        }

        listaPaula.sort();
    }

    void llenarListaPaula2(){
        string cancion;
        cout << "ingrese las canciones para la lista Paula2 (escriba 'fin' para terminar)" << endl;
        while (true){
            cin >> cancion;
            if (cancion == "fin"){
                break;
            }
            agregarCancionPaula2(cancion);
        }
    }
    
};

int main() {

    Spotify2 spotify;

    spotify.llenarListaGeneral();
    spotify.llenarListaPaula();
    spotify.llenarListaPaula2();

    const list<string>& listaGeneral = spotify.getlistaGeneral();
    const list<string>& listaPaula = spotify.getlistaPaula();
    const list<string>& listaPaula2 = spotify.getlistaPaula2();

    ListaEnlazada user1;

    user1.construirListaEnlazada(listaPaula, listaPaula2);


    cout<<"La lista General de canciones es: ";
    for (string cancion : listaGeneral){
        cout<<cancion<<", ";
    }
    cout<<endl;

    cout<<"La lista Paula Ordenada es: ";
    for (string cancion : listaPaula){
        cout<<cancion<<", ";
    }
    cout<<endl;

    cout<<"La lista Paula2 es: ";
    for (string cancion : listaPaula2){
        cout<<cancion<<", ";
    }
    cout<<endl;

    cout<< "La lista enlazada es: ";
    user1.imprimirLista();

    return 0;
}
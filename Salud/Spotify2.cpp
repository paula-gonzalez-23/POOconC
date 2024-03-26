#include <iostream>
#include <list>
#include <algorithm>
#include <string>
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

    void ordenarListaPaula2(list<string>& listaPaula2){
        listaPaula2.sort([](const string& cancion1, const string& cancion2){
            string artista1 = cancion1.substr(cancion1.find_last_of("-") + 1);
            string artista2 = cancion2.substr(cancion2.find_last_of("-") + 1);
            return artista1 > artista2;
        });
    }

};

class Spotify2 {

    //Atributos

    private:
    
    list<pair<string, int>>listaGeneral; 
    list<string>listaPaula;
    list<string>listaPaula2;

    public:

    //Constructor
    Spotify2(){

    }

    //Accesores set para modificar y get para mostrar 

    void agregarCancionGeneral(const pair<string, int>& cancion){
        listaGeneral.push_back(cancion);
    }

    const list<pair<string, int>>& getlistaGeneral() const{
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
        int duracion;
        cout << "Ingrese las canciones para la lista general (ejemplo: Cancion - Artista - Duracion):" << endl;
        while (true){
            getline(cin,cancion);
            if (cancion == "0"){
                break;
            }
            size_t pos1 = cancion.find("-");
            if (pos1 != string::npos){
                size_t pos2 = cancion.find("-",pos1 + 1);
                if (pos2 != string::npos){
                    string nombreCancion = cancion.substr(0,pos1);
                    string nombreArtista = cancion.substr(pos1 + 1, pos2 - pos1 -1);
                    duracion = stoi(cancion.substr(pos2 + 1));
                    agregarCancionGeneral(make_pair(nombreCancion + " - " + nombreArtista, duracion));
                }else {
                    cout<<"Formato de entrada incorrecto. Debe ingresar el nombre de la cancion, el nombre del artista y la duracion separados por guiones (-)"<<endl;
                }
            }else{
                cout<<"Formato de entrada incorrecto. Debe ingresar el nombre de la cancion, el nombre del artista y la duracion separados por guiones (-)"<<endl;
            }
        }

        listaGeneral.sort([](const pair<string, int>& cancion1, const pair<string, int>& cancion2){
            return cancion1.second < cancion2.second;
        });
    }

    void llenarListaPaula(){
        string cancion;
        cout << "Ingrese las canciones para la lista Paula (ejemplo: Cancion - Artista - Duracion):" << endl;
        while (true){
            getline(cin, cancion);
            if (cancion == "0"){
                break;
            }

            //Verificar el formato de entrada
            size_t pos1 = cancion.find("-");
            size_t pos2 = cancion.find("-",pos1 + 1);
            if (pos1 == string::npos || pos2 == string::npos){
                cout<<"Formato de entrada incorrecto. Debe ingresar el nombre de la cancion, el nombre del artista y la duracion separados por guiones (-)"<< endl;
                continue;
            }

            //Extraer la duracion y verificar si es un numero valido
            string duracionStr = cancion.substr(pos2 + 1);
            int duracion;
            try {
                duracion = stoi(duracionStr);
            } catch (const invalid_argument& e) {
                cout << "Formato de duracion incorrecto. La duracion debe ser un numero entero" << endl;
                continue;
            }


            string nombreCancion = cancion.substr(0, pos1);
            string nombreArtista = cancion.substr(pos1 + 1, pos2 - pos1 - 1);
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
                    agregarCancionGeneral(make_pair(nombreCancion + " - " + nombreArtista, duracion));
                    cout << "La cancion se ha agregado satisfactoriamente a la Lista General" << endl;
                    cout <<"Siga ingresando las canciones que quiere agregar a la Lista Paula" << endl;
                }else if (seleccion == 2){
                    cout << "La cancion no se puede agregar a  Lista Paula porque no existe en Lista General" << endl;
                }else{
                    cout << "Opcion no valida. Por favor, seleccione 1 o 2" << endl;
                }
            }
        }

        listaPaula.sort();
    }

    void llenarListaPaula2(){
        string cancion;
        cout << "Ingrese el nombre de la cancion y el artista para la lista de Paula2 (ejemplo: Cancion - Artista): "<< endl;
        while (true){
            getline(cin, cancion);
            if (cancion == "0"){
                break;
            }
            size_t pos = cancion.find("-");
            if (pos != string::npos){
                listaPaula2.push_back(cancion);
            }else {
                cout << "Formato de entrada incorrecto. Debe ingresar el nombre de la cancion seguido del artista separados por un guion (-)" << endl;
            }
        }

        listaPaula2.sort([](const string& cancion1, const string& cancion2) {
            string artista1 = cancion1.substr(cancion1.find_last_of("-") + 1);
            string artista2 = cancion2.substr(cancion2.find_last_of("-") + 1);
            return artista1 > artista2;
        });
    }

    
};

int main() {

    Spotify2 spotify;

    spotify.llenarListaGeneral();
    spotify.llenarListaPaula();
    spotify.llenarListaPaula2();

    const list<pair<string, int>>& listaGeneral = spotify.getlistaGeneral();
    const list<string>& listaPaula = spotify.getlistaPaula();
    const list<string>& listaPaula2 = spotify.getlistaPaula2();

    ListaEnlazada user1;

    user1.construirListaEnlazada(listaPaula, listaPaula2);

    cout<<"La lista General de canciones es: ";
    for (const auto& cancion : listaGeneral){
        cout << cancion.first << " - Duracion: " << cancion.second << "minutos" << endl;
    }
    cout<<endl;

    cout<<"La lista Paula Ordenada es: ";
    for (string cancion : listaPaula){
        cout<<cancion<<", ";
    }
    cout<<endl;

    cout<<"La lista Paula2 Original es: ";
    for (string cancion : listaPaula2){
        cout<<cancion<<", ";
    }
    cout<<endl;

    cout<< "La lista enlazada es: ";
    user1.imprimirLista();


    return 0;
}
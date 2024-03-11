#include <iostream>
#include <vector>
using namespace std;

class Daviplata {

    //Atributos

    private:

    string usuario;
    double saldo;
    vector <string> movimientos;

    public:

    //Constructor

    Daviplata (){

    }

    //Accesores set para modificar y get para mostrar

    void setusuario(string _usuario){

        usuario = _usuario;

    }

    string getusuario(){

        return usuario;

    }

    void setsaldo(double _saldo){

        saldo = _saldo;

    }

    double getsaldo(){

        return saldo;

    }

    //Falta get y set para movimientos

    //Metodos

    void recargar (){

    }

    void pagos (){

    }

    void movimientos (){
        
    }

};
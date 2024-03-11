#include <iostream>
#include <vector>
using namespace std;

class Nequi {

    //Atributos

    private:

    string usuario;
    double saldo;
    vector <string> movimientos;

    public:

    //Constructor

    Nequi (){

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

    void acceso(){

    }

    void recarga(){

    }

    void colchon(){

    }

    void meta(){

    }

    void bolsillos(){

    }

    void sacarPlata(){

    }

    void movimientos(){

    }

    
};
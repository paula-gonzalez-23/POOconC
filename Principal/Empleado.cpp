#include <iostream>
#include "../Salud/Persona.cpp"
using namespace std;

class Empleado : private Persona {

    //Atributos

    private :

    string cargo;
    int valorHora;
    int horasTrabajadas;
    string departamento;

    public:

    //Constructor 

    Empleado (){

    }

    //Accesores set para modificar y get para mostrar 

    void setcargo(string _cargo){

        cargo = _cargo;

    }

    string getcargo (){

        return cargo;

    }

    void setvalorHora(int _valorHora){

        valorHora = _valorHora;

    }

    int getvalorHora (){

        return valorHora;

    }

    void sethorasTrabajadas(int _horasTrabajadas){

        horasTrabajadas = _horasTrabajadas;

    }

    int gethorasTrabajadas (){

        return horasTrabajadas;
        
    }


    

};
#include <iostream>
#include "../Salud/Persona.cpp"
#include "../Salud/Empleado.cpp"
using namespace std;


class Inicio{

    Persona usuario;

};

int main(){

    Persona usuario;
    
    usuario.pedirDatos();
   
    cout<<"Los datos ingresados anteriormente son: "<<endl;

    usuario.mostrarPersona();
    usuario.calcularImc();

    double pesoActual = usuario.getpesoActual();

    cout<<"Su IMC es: "<<pesoActual<<endl;

    if (pesoActual<20){
        cout<<"Peso bajo"<<endl;
    }else if(20<= pesoActual && pesoActual <=25){
        cout<<"Peso ideal"<<endl;
    }else {
        cout<<"Sobrepeso"<<endl;
    }

    usuario.mayorEdad();
    
    return 0;
}
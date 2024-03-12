#include <iostream>
#include "../Salud/Persona.cpp"
#include "../Salud/Empleado.cpp"
using namespace std;


class Inicio{

    Persona usuario;
    Empleado usuario1;

};

int main(){

    Persona usuario;
    Empleado usuario1;

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
    
    usuario1.pedirDatos();
    usuario1.calcularHonorarios();
    usuario1.mayorEdad(2006,2023);
    usuario1.mostrarPersona();


    return 0;
}
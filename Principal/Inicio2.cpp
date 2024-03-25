#include <iostream>
#include "../Salud/Persona.cpp"
#include "../Salud/Empleado.cpp"
using namespace std;


class Inicio{

    Empleado usuario1;

};

int main(){

    Empleado usuario1;
    
    usuario1.pedirDatos();
   
    cout<<"Los datos ingresados anteriormente son: "<<endl;

    usuario1.calcularHonorarios();
    usuario1.mayorEdad(2006,2024);
    usuario1.mostrarPersona();
    
    return 0;
}
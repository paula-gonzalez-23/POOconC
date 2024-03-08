#include <iostream>
using namespace std;

class Persona {

    //Atributos 

    private:

    string tipoDoc;
    int documento;
    string nombre;
    string apellido;
    double peso;
    double estatura;
    int edad;
    string sexo;

    //Constructor

    Persona(){

    }

     //Accesores set para modificar y get para mostrar 

    void settipoDoc(string _tipoDoc){

        tipoDoc = _tipoDoc;

    }

    string gettipoDoc(){

        return tipoDoc;

    }

    //Metodos 

    void pedirDatos(){

        cout<<"Ingrese su tipo de documento: "<<endl;
        cin>>tipoDoc;

        cout<<"Ingrese su numero de documento: "<<endl;
        cin>>documento;

        cout<<"Ingrese su nombre: "<<endl;
        cin>>nombre;

        cout<<"Ingrese su apellido: "<<endl;
        cin>>apellido;

        cout<<"Ingrese su peso en kg: "<<endl;
        cin>>peso;

        cout<<"Ingrese su estatura en cm: "<<endl;
        cin>>estatura;

        cout<<"Ingrese su edad: "<<endl;
        cin>>edad;

        cout<<"Ingrese su sexo: "<<endl;
        cin>>sexo;
    }

    void mostrarPersona(){

        cout <<"El tipo de documento es: "<<tipoDoc<<endl;
        cout <<"El numero de documento es: "<<documento<<endl;
        cout <<"El nombre es: "<<nombre<<endl;
        cout <<"El apellido es: "<<apellido<<endl;
        cout <<"El peso en kg es: "<<peso<<endl;
        cout <<"La estatura es: "<<estatura<<endl;
        cout <<"La edad es: "<<edad<<endl;
        cout <<"El sexo es: "<<sexo<<endl;

    }

    void calcularImc(){

        double pesoActual;

        pesoActual = (peso/estatura/estatura);

        if (pesoActual<20){
            cout<<"El peso esta por debajo de lo ideal"<<endl;
        }else if(20<=pesoActual>=25){
            cout<<"El peso es ideal"<<endl;
        }else if(pesoActual>25){
            cout<<"Sobrepeso"<<endl;
        }
    }

    void mayorEdad(){

        if (edad<18){
            cout<<"Es menor de edad"<<endl;
        }else{
            cout<<"Es mayor de edad"<<endl;
        }

    }
};
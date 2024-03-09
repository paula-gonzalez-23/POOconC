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
    double pesoActual;
    

    public:

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

    void setdocumento(int _documento){

        documento = _documento;

    }

    int getdocumento(){

        return documento;

    }

    void setnombre(string _nombre){

        nombre = _nombre;

    }

    string getnombre(){

        return nombre;

    }

    void setapellido(string _apellido){

        apellido = _apellido;

    }

    string getapellido(){

        return apellido;

    }

    void setpeso(double _peso){

        peso = _peso;

    }

    double getpeso(){

        return peso;

    }

    void setestatura(double _estatura){

        estatura = _estatura;

    }

    double getestatura(){
        
        return estatura;

    }

    void setedad(int _edad){

        edad = _edad;

    }

    int getedad(){

        return edad;
    }

    void setsexo(string _sexo){

        sexo = _sexo;

    }

    string getsexo(){

        return sexo;

    }

    void setpesoActual(double _pesoActual){

        pesoActual = _pesoActual;
    
    }

    double getpesoActual(){

        return pesoActual;
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
     
        pesoActual = peso / ((estatura / 100.0) * (estatura / 100.0)); 

    }

    void mayorEdad(){

        if (edad<18){
            cout<<"Es menor de edad"<<endl;
        }else{
            cout<<"Es mayor de edad"<<endl;
        }

    }
};
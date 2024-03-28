#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Usuario {
    string numcel;
    int clave;
};

class Daviplata {

    private:

    vector<Usuario> usuarios;

    bool usuarioExiste(const string& numcel, int clave) const{
        for (const Usuario& usuario : usuarios){
            if (usuario.numcel == numcel && usuario.clave == clave){
                return true;
            }
        }
        return false;
    }

    list<pair<string, double>>Movimientos;
    double saldo = 0;

    public:

    Daviplata (){

    }

    void agregarMovimiento (const string& movimiento, double monto){
        Movimientos.push_back(make_pair(movimiento, monto));
    }

    void setsaldo(double _saldo){

        saldo = _saldo;
    }

    double getsaldo(){

        return saldo;
    }

    void menu(){

        cout << "Menu" << endl;
        cout << "1. Recargar Daviplata" << endl;
        cout << "2. Realizar pagos" << endl;
        cout << "3. Ver movimientos" << endl;
        cout << "4. Salir" << endl;
        cout << "Saldo disponible $: " << saldo << endl;
    }

    bool llenarUsuarios(){

        usuarios.push_back({"3128991399", 1234});

        string entrada, numcel;
        int clave;

        cout << "Ingrese el numero de celular y clave (ejemplo numero de celular-clave), escriba fin para salir" << endl;
        while (true){
            getline(cin,entrada);

            if (entrada == "fin"){
                break;
            }

            size_t pos = entrada.find('-');
            if (pos == string::npos){
                cout << "Formato de entrada incorrecto. Debe ser 'numero de celular-clave'. Intente de nuevo" << endl;
                continue;
            }

            numcel = entrada.substr(0,pos);
            clave = stoi(entrada.substr(pos + 1));

            if (numcel.length() != 10){
                cout << "El numero de celular debe tener 10 digitos. Intente de nuevo" << endl;
                continue;
            }

            if (entrada.substr(pos + 1).length() != 4){
                cout << "La clave debe tener 4 digitos. Intente de nuevo" << endl;
                continue;
            }

            if (usuarioExiste(numcel,clave)){
                cout << "Acceso otorgado" << endl;
                return true;
            } else {
                cout << "El usuario no existe" << endl;
            }
        }
        return false;
    }

    void recargarDaviplata (){
        
        int opcion;

        cout << "Seleccione una opcion para recargar saldo en daviplata" <<endl;
        cout << "1. Recargar con efectivo" << endl;
        cout << "2. Recargar desde otros bancos" << endl;
        cout << "Ingrese su opcion" << endl;
        cin >> opcion;

        switch (opcion){
            case 1:
                recargarEfectivo();
                break;
            case 2: 
                recargarOtrosBancos();
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }

    void recargarEfectivo (){

        double monto;
        string numerocel;

        cout << "Ingrese el numero de celular al que quiere recargar" << endl;
        cin >> numerocel;
        cout << "Ingrese el monto que desea recargar con efectivo" << endl;
        cin >> monto;
        saldo += monto;
        cout << "Recarga con efectivo exitosa. Saldo actual $: " << saldo << endl;

        agregarMovimiento("Recarga con efectivo $: ", monto);
    }

    void recargarOtrosBancos(){

        int opcion, opcion1, banco;
        string numerocel, renumerocel;
        double monto;

        cout << "Si deseas recargar tu nequi desde pse, seleccione una opcion: " << endl;
        cout << "1. Siguiente" << endl;
        cout << "2. Salir" << endl;
        cout << "Ingrese su opcion: " << endl;
        cin >> opcion;

        switch (opcion){
            case 1:
                cout << "Ingrese el numero de celular: " << endl;
                cin >> numerocel;
                cout << "Confirma el numero de ceular: " << endl;
                cin >> renumerocel;
                cout << "Ingresa la cantidad que deseas recargar: " << endl;
                cin >> monto;
                saldo += monto;
                cout << "Elige el tipo de persona: " << endl;
                cout << "1. Natual" << endl;
                cout << "2. Juridica" << endl;
                cout << "Ingresa tu opcion" << endl;
                cin >> opcion1;
                cout << "Elige el banco desde donde deseas hacer la recarga: " << endl;
                cout << "1. Banco AV Villas" << endl;
                cout << "2. Banco BBVA Colombia SA" << endl;
                cout << "3. Bancolombia" << endl;
                cout << "4. Nequi" << endl;
                cout << "5. Rappipay" << endl;
                cout << "Ingresa tu opcion" << endl;
                cin >> banco;

                if (numerocel == renumerocel){
                    cout << "La recarga se ha realizado con exito. Saldo actual $: " << saldo << endl;
                    agregarMovimiento("Recarga desde otos bancos $: ", monto);
                }else {
                    cout << "El numero de confirmacion no coincide con el ingresado" << endl;
                    cout << "Por su seguridad vuelva a ingresar todos los datos" << endl;
                }
                break;

            case 2:
                cout << "A la proxima dale una oportunidad a Nequi" << endl; 
                break;

            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
    }

    void realizarPagos(){

        int opcion, opcion1, opcion2, opcion3, opcion4;
        string referencia, codigobarras;
        double valor, valor1, valor2, valor3;

        cout << "Elige la opcion de pago que deseas realizar: " << endl;
        cout << "1. Pagar recibos publicos" << endl;
        cout << "2. Pagar con codigo de barras" << endl;
        cout << "Ingrese su opcion" << endl;
        cin >> opcion;

        switch(opcion){
            case 1:
                cout << "Elige el recibo publico que deseas pagar: " << endl;
                cout << "1. Pagar energia" << endl;
                cout << "2. Pagar gas" << endl;
                cout << "3. Pagar agua" << endl;
                cout << "Ingrese su opcion: " << endl;
                cin >> opcion1;

                switch (opcion1){
                    case 1:
                        cout << "Elige la empresa a la que vas a pagar: " << endl;
                        cout << "1. Enel Codensa" << endl;
                        cout << "2. EPM" << endl;
                        cout << "3. Electricaribe" << endl;
                        cout << "Ingrese su opcion" << endl;
                        cin >> opcion2;

                        if (opcion2 == 1 || opcion2 == 2 || opcion2 == 3){
                            cout << "Ingresa el numero de referencia de su recibo: " << endl;
                            cin >> referencia;
                            cout << "Ingresa el valor del recibo: " << endl;
                            cin >> valor;

                            if (valor > saldo){
                                cout << "Fondos insuficientes" << endl;
                            } else {
                                saldo -= valor;
                                cout << "Pago exitoso. Saldo actual: " << saldo << endl;
                                agregarMovimiento("Pago de energia $: ",valor);
                            }
                        } else {
                            cout << "Opcion no valida" << endl;
                        }
                        break;
                    
                    case 2:
                        cout << "Elige la empresa a la que vas a pagar: " << endl;
                        cout << "1. Vanti" << endl;
                        cout << "2. Promigas" << endl;
                        cout << "3. Gases del caribe" << endl;
                        cout << "4. Alcanos" << endl;
                        cout << "Ingrese su opcion: " << endl;
                        cin >> opcion3;

                        if (opcion3 == 1 || opcion3 == 2 || opcion3 == 3 || opcion3 ==4){
                            cout << "Ingresa el numero de referencia de su recibo: " << endl;
                            cin >> referencia;
                            cout << "Ingresa el valor del recibo: " << endl;
                            cin >> valor1;

                            if (valor1 > saldo){
                                cout << "Fondos insuficientes" << endl;
                            } else {
                                saldo -= valor1;
                                cout << "Pago exitoso. Saldo actual: " << saldo << endl;
                                agregarMovimiento("Pago de gas $: ",valor1);
                            }
                        } else {
                            cout << "Opcion no valida" << endl;
                        }
                        break;
                    
                    case 3: 
                        cout << "Elige la empresa a la que vas a pagar: " << endl;
                        cout << "1. Empresa de acueducto y alcantarillado de bogota (EAAB)" << endl;
                        cout << "2. EPM" << endl;
                        cout << "3. Acueducto de Bucaramanga" << endl;
                        cout << "4. Emcali" << endl;
                        cout << "Ingrese su opcion: " << endl;
                        cin >> opcion4;

                        if (opcion4 == 1 || opcion4 == 2 || opcion4 == 3 || opcion4 ==4){
                            cout << "Ingresa el numero de referencia de su recibo: " << endl;
                            cin >> referencia;
                            cout << "Ingresa el valor del recibo: " << endl;
                            cin >> valor2;

                            if (valor2 > saldo){
                                cout << "Fondos insuficientes" << endl;
                            } else {
                                saldo -= valor2;
                                cout << "Pago exitoso. Saldo actual: " << saldo << endl;
                                agregarMovimiento("Pago de agua $: ",valor2);
                            }
                        } else {
                            cout << "Opcion no valida" << endl;
                        }
                        break;

                    default:
                        cout << "Ingrese una opcion valida" << endl;
                        break;
                }
                break;
            
            case 2:
                cout << "Ingrese el numero (ejemplo code128): " << endl;
                cin >> codigobarras;

                cout << "Ingresa el valor que vas a pagar: " << endl;
                cin >> valor3;

                if (valor3 > saldo){
                    cout << "Fondos insuficientes" << endl;
                } else {
                    saldo -= valor3;
                    cout << "Pago exitoso. Saldo actual $: " << saldo << endl;
                    agregarMovimiento("Pago por codigo de barras $: ",valor3);
                }
                break;

            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }

    void verMovimientos() const {
        cout << "Movimientos:" << endl;
        for (const auto& movimiento : Movimientos){
            cout << movimiento.first << ": $" << movimiento.second << endl;
        }
    }

};
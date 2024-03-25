#include <iostream>
#include <vector>
using namespace std;

//Ordenamiento de array

void ordBur(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            int temp = arr[j];
            arr[j]=arr[j+1];
            arr[j+1=temp;]
        }
    }
}

void vectorOrd(int arr[], int tamanio){
    for(int i=0; i<tamanio; i++){
        cout<<arr[i]<<" ";
        cout<< endl;
    }
}

int main (){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"El vector original es: "<< " ";
    vectorOrd(arr, n);
    ordBur(arr, n);
    cout<<"El vector ordenado es: "<< " ";
    vectorOrd(arr, n);

    return 0;
}

//Ordenamiento de listas

struct Node{
    int dato;
    Node* next;
    Node(int val) : dato(val), next(nullptr){}

};

//Funcion para insertar un nodo al principio de la lista

void insertarInicioLista(Node* &head, int val){
    Node* nuevoNodo = new Node(val);
    nuevoNodo->next=head;
    head = nuevoNodo;
};

//Funcion para imprimir la lista

void imprimirLista(Node* head){
    while(head != nullptr){
        cout << head->dato << " ";
        head = head->next;
    }
    cout << endl;
};

//Funcion para ordenar la lista

void ordenarLista(Node* &head){
    if (head==nullptr || head->next==nullptr)
    return;
    Node* sorted = nullptr;
    Node* current = head;
    while (current != nullptr){
        Node* nextNode = current->next;
        if (sorted == nullptr || sorted->dato>=current->dato){ 
            current->next=sorted;
            sorted=current;
        }else {
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->dato < current->dato){
                temp = temp->next;
            }

            current->next=temp->next;
            temp->next=current;
        }
    }
};

int main{

    Node* head = nullptr;
    
    insertarInicioLista(head,50);
    insertarInicioLista(head,160);
    insertarInicioLista(head,5);
    insertarInicioLista(head,1);

    cout << "La lista original es: "<<endl;
    imprimirLista(head);
    ordenarLista(head);
    cout << "La lista ordenada es: "<<endl;
    imprimirLista(head);

    retunr 0;

}

//Poker, crear un vector el usuario ingresa las cartas del poker y se tienen que organizar de mayor a menor y ordenar por pinta (corazon, diamante, picas,treboles)

//Buscar metodos de busqueda 
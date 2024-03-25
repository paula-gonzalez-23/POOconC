#include <iostream>
#include <vector>
using namespace std;

//Metodos de busqueda
//Lineal

bool busquedaLineal(const vector <int>& array,int target){

    for (int element : array){
        if (element == target){
            return true;
        }
    }

    return false;

};

int main(){

    vector <int> numbers={1,2,3,4,5};

    int target = 3;

    if(busquedaLineal(numbers,target)){
        cout<<"El elemento "<<target<<" esta en el vector"<<endl;
    }else {
        cout<<"El elemento "<<target<<" no esta en el vector"<<endl;
    }

    return 0;

}

//arbol binario BST

struct Node{

    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value),left(nullptr),right(nullptr){

    };

    Node* buscar(Node* root, int key){
        if (root == nullptr || root -> data == key){
            return root;
        }
            if (root -> data<key){
                return buscar()
            }
    }
};
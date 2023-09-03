#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
} *inicio, *final;

Nodo *lista=NULL;

void insertarElementos(Nodo *&lista, int numero){
    char continuar;
    do{
        cout<<"Digite un numero: ";
        cin>>numero;

        Nodo *nuevoNodo = new Nodo();
        nuevoNodo->dato = numero;

        if (lista == NULL) {
            lista = nuevoNodo;
            nuevoNodo->siguiente = lista; 
        } else {
            Nodo *ultimo = lista;
            while (ultimo->siguiente != lista) {
                ultimo = ultimo->siguiente;
            }

            nuevoNodo->siguiente = lista; 
            ultimo->siguiente = nuevoNodo;
        }

        cout<<"\tElemento "<<numero<<" insertado a lista correctamente. \nDesea agregar otro elemento? (s/n): ";
        cin>>continuar;
    } while (continuar == 's' || continuar == 'S');
}

void mostrarLista(Nodo *&lista){
     Nodo *actual = new Nodo();
     
    if (lista != NULL){
        actual = lista;
        do{
            cout<<actual->dato<<" -> ";
            actual = actual->siguiente;
        } while (actual != lista);

        cout<<" (Lista circular)\n";
        cout<<"Nodo inicial: "<<lista->dato;
    }else{
        cout<<"La lista se encuentra vacia";
    } 
}

void buscarElementos(Nodo *&lista, int numero){
    cout<<"Digite elemento a buscar: ";
    cin>>numero;
    

    if (lista != NULL){
        Nodo *actual = lista;
        bool elementoEncontrado = false;

        do{
            if (actual->dato == numero)
            {
                elementoEncontrado = true;
                break;
            }
            actual = actual->siguiente;
        } while (actual != lista);
        
        if (elementoEncontrado){
            cout<<"Elemento "<<numero<<" SI ha sido encontrado en lista";
        }else{
            cout<<"Elemento "<<numero<<" NO ha sido encontrado en lista";
        }
        
    }else{
        cout<<"La lista se encuentra vacia";
    }
}

void eliminarElementos(Nodo *&lista, int numero) {
    cout << "Digite el elemento a eliminar: ";
    cin >> numero;

    if (lista != NULL) {
        Nodo *auxBorrar = lista;
        Nodo *auxAnterior = NULL;
        bool elementoEncontrado = false;

        do {
            if (auxBorrar->dato == numero) {
                elementoEncontrado = true;
                break;
            }
            auxAnterior = auxBorrar;
            auxBorrar = auxBorrar->siguiente;
        } while (auxBorrar != lista);

        if (elementoEncontrado) {
            if (auxBorrar == inicio) { // Elemento a borrar es el inicio
                inicio = inicio->siguiente;
            }
            if (auxAnterior != NULL) { // Elemento a borrar segundo o mayor
                auxAnterior->siguiente = auxBorrar->siguiente;
            }
            delete auxBorrar;
            cout << "Elemento eliminado de manera exitosa\n";
        } else {
            cout << "Elemento no encontrado en la lista\n";
        }
    } else {
        cout << "La lista se encuentra vacia\n";
    }
}


void actualizarElementos(Nodo *&lista, int numero){
    Nodo *actual = lista;
    int numeroActualizar;

    cout<<"Digite elemento a actualizar: ";
    cin>>numero;

    if (actual != NULL){
        bool elementoEncontrado = false;
        do{
            if (actual->dato == numero)
            {
                elementoEncontrado = true;
                cout<<"Digite el nuevo elemento: ";
                cin>>numeroActualizar;
                actual->dato = numeroActualizar;
                cout<<"Dato actualizado exitosamente";
            }
            actual = actual->siguiente;
        } while (actual != lista);
        
        if (elementoEncontrado == false){
            cout<<"Elemento "<<numero<<" NO ha sido encontrado en lista\n";
        }
    }else{
        cout<<"La lista se encuentra vacia";
    }
}

void menu(){
    int opcion, dato;

    do{
        cout<<"\tLISTA CIRCULAR\n";
        cout<<"----------MENU:---------\n";
        cout<<"OPCION 1. Insertar elementos\n";
        cout<<"OPCION 2. Mostrar elementos\n";
        cout<<"OPCION 3. Buscar elementos\n";
        cout<<"OPCION 4. Eliminar elementos\n";
        cout<<"OPCION 5. Actualizar elementos\n";
        cout<<"OPCION 6. Salir\n";
        cout<<"Opcion: ";
        cin>>opcion;

        switch (opcion){
            case 1:
                insertarElementos(lista, dato);
                cout<<"\n";
                system("pause");
            break;
            case 2:
                mostrarLista(lista);
                cout<<"\n";
                system("pause");
            break;
            case 3:
                buscarElementos(lista, dato);
                cout<<"\n";
                system("pause");
            break;
            case 4:
                eliminarElementos(lista, dato);
                cout<<"\n";
                system("pause");
            break;
            case 5:
                actualizarElementos(lista, dato);
                cout<<"\n";
                system("pause");
            break;
        default:
            break;
        }
        system("cls");
    } while (opcion != 6);
}

int main(){
    menu();

    getch();
    return 0;
}
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
    Nodo *anterior;
} *inicio, *final; 

void insertarElementos(Nodo *&inicio, Nodo *&final){
    int numero;
    char continuar;
    do
    {
        cout<<"Digite un numero: ";
        cin>>numero;

        Nodo *nuevoNodo = new Nodo();
        nuevoNodo->dato = numero;
        nuevoNodo->siguiente = NULL;
        nuevoNodo->anterior = final;


        if (inicio == NULL) {
            inicio = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
        }

        final = nuevoNodo;

        cout<<"\tElemento "<<numero<<" insertado a lista correctamente. \nDesea agregar otro elemento? (s/n): ";
        cin>>continuar;
    } while (continuar == 's' || continuar == 'S');
}

void mostrarLista(){
    Nodo *actual = new Nodo();
    actual = inicio;
    if (inicio != NULL){
        while (actual != NULL){
            cout<<actual->dato<<" -> ";
            actual = actual->siguiente;
        } 
    }else{
        cout<<"La lista se encuentra vacia";
    }
}

void mostrarListaInversa(){
    Nodo *actual = new Nodo();
    actual = final;
    cout<<"\nLista inversa\n";
    if (inicio != NULL){
        while (actual != NULL){
            cout<<actual->dato<<" -> ";
            actual = actual->anterior;
        } 
    }else{
        cout<<"La lista se encuentra vacia";
    }
}

void buscarElementos(Nodo *&inicio, int numero){
    Nodo *actual = inicio;

    cout<<"Digite elemento a buscar: ";
    cin>>numero;

    if (inicio != NULL){
        bool elementoEncontrado = false;
        do{
            if (actual->dato == numero)
            {
                elementoEncontrado = true;
                break;
            }
            actual = actual->siguiente;
        } while (actual != NULL);
        
        if (elementoEncontrado){
            cout<<"Elemento "<<numero<<" SI ha sido encontrado en lista\n";
        }
        else{
            cout<<"Elemento "<<numero<<" NO ha sido encontrado en lista\n";
        }
    }else{
        cout<<"La lista se encuentra vacia";
    }
}

void eliminarElementos(){
    Nodo *actual = new Nodo();
    actual = inicio;
    Nodo *anterior = new Nodo();
    anterior = NULL;
    bool elementoEncontrado = false;
    int nodoBuscar = 0;

    cout<<"Ingrese el elemento a eliminar: "; 
    cin>>nodoBuscar;

    if (inicio != NULL){
        
        while (actual != NULL && elementoEncontrado != true){
            
            if (actual->dato == nodoBuscar){

                if (actual == inicio){
                    inicio = inicio->siguiente;
                    inicio->anterior = NULL;
                }else if (actual == final){
                    anterior->siguiente = NULL;
                    final = anterior;
                }else{
                    anterior->siguiente = actual->siguiente;
                    actual->siguiente->anterior = anterior;
                }
                
                cout<<"Elemento eliminado de manera exitosa";
                elementoEncontrado = true;
            }
            
            anterior = actual;
            actual = actual->siguiente;
        }

        if (elementoEncontrado == false){
            cout<<"Elemento no encontrado en la lista\n";
        }  
    }else{
        cout<<"La lista se encuentra vacia";
    }
}

void actualizarElementos(Nodo *&inicio, int numero){
    Nodo *actual = inicio;
    int numeroActualizar;

    cout<<"Digite elemento a actualizar: ";
    cin>>numero;

    if (inicio != NULL){
        bool elementoEncontrado = false;
        do{
            if (actual->dato == numero){

                elementoEncontrado = true;
                cout<<"Digite el nuevo elemento: ";
                cin>>numeroActualizar;
                actual->dato = numeroActualizar;
                cout<<"Dato actualizado exitosamente";
            }

            actual = actual->siguiente;
        } while (actual != NULL);
        
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
        cout<<"\tLISTA DOBLE\n";
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
                insertarElementos(inicio, final);
                cout<<"\n";
                system("pause");
            break;
            case 2:
                mostrarLista();
                mostrarListaInversa();
                cout<<"\n";
                system("pause");
            break;
            case 3:
                buscarElementos(inicio, dato);
                cout<<"\n";
                system("pause");
            break;
            case 4:
                eliminarElementos();
                cout<<"\n";
                system("pause");
            break;
            case 5:
                actualizarElementos(inicio, dato);
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

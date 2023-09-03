#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

Nodo *lista = NULL; 

void insertarElementos(Nodo *&lista, int numero){
    char continuar;
    do{
        cout<<"Digite un numero: ";
        cin>>numero;

        Nodo *nuevoNodo = new Nodo();
        nuevoNodo->dato = numero;
        nuevoNodo->siguiente = NULL;

        if (lista == NULL){
            lista = nuevoNodo; //Lista vacia, creacion primer nodo
        }else{
            Nodo *aux = lista;
            while (aux->siguiente != NULL){
                aux = aux->siguiente; //Crear nodo al final
            }
            aux->siguiente = nuevoNodo;
        }

        cout<<"\tElemento "<<numero<<" insertado a lista correctamente. \nDesea agregar otro elemento? (s/n): ";
        cin>>continuar;
    } while (continuar == 's' || continuar == 'S');
}

void mostrarLista(Nodo *lista){
    Nodo *actual = new Nodo();
    actual = lista;

    if (actual != NULL){
        do{
            cout<<actual->dato<<" -> ";
            actual = actual->siguiente;
        } while (actual != NULL); // Continuar mientras haya más nodos en la lista
    }else{
        cout<<"La lista se encuentra vacia";
    }
}

void buscarElementos(Nodo *lista, int numero){
    bool band = false;
    Nodo *actual = new Nodo();
    actual = lista; 

    if (actual != NULL){
        while ((actual != NULL) && (actual->dato <= numero)){
            if (actual->dato == numero){
                band = true;
            }
            actual = actual->siguiente; 
        }

        if (band == true){
            cout<<"Elemento "<<numero<<" SI ha sido encontrado en lista\n";
        }else{
            cout<<"Elemento "<<numero<<" NO ha sido encontrado en lista\n";
        } 
    }else{
        cout<<"La lista se encuentra vacia";
    }
}

void eliminarElementos(Nodo *&lista, int numero){
    Nodo *auxBorrar;
    Nodo *auxAnterior = NULL;
    auxBorrar = lista;

    if (lista != NULL){

        while ((auxBorrar != NULL) && (auxBorrar->dato != numero)){
            auxAnterior = auxBorrar;
            auxBorrar = auxBorrar->siguiente;
        }
        
        if (auxBorrar == NULL){ //Elemento no encontrado
            cout<<"Elemento no encontrado en la lista\n";
        }else if (auxAnterior == NULL){ //Elemento a borrar primero en la lista
            lista = lista->siguiente;
            delete auxBorrar;
            cout<<"Elemento eliminado de manera exitosa\n";
        }else{ //Elemento a borrar segundo o mayor
            auxAnterior->siguiente = auxBorrar->siguiente;
            delete auxBorrar;
            cout<<"Elemento eliminado de manera exitosa";
        }
    }else{
        cout<<"La lista se encuentra vacia";
    }
}

void actualizarElementos(Nodo *&lista, int numero, int numeroActualizar){
    Nodo *auxBusqueda = lista;

    if (lista != NULL)
    {
        while (auxBusqueda != NULL){
        if (auxBusqueda->dato == numero){
            auxBusqueda->dato = numeroActualizar;
            cout<<"Dato actualizado exitosamente";
            return;
        }
        auxBusqueda = auxBusqueda->siguiente;
    } 
        cout<<"Dato no encontrado en la lista";
    }else{
        cout<<"La lista se encuentra vacia";
    }
}

void menu(){
    int opcion, dato;

    do{
        cout<<"\tLISTA SIMPLE\n";
        cout<<"----------MENU:-------------\n";
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
                cout<<"Digite elemento a buscar: ";
                cin>>dato;
                buscarElementos(lista, dato);
                cout<<"\n";
                system("pause");
            break;
            case 4:
                cout<<"Digite el elemento a eliminar: ";
                cin>>dato;
                eliminarElementos(lista, dato);
                cout<<"\n";
                system("pause");
            break;
            case 5:
                int datoActualizar;
                cout<<"Digite elemento a actualizar: ";
                cin>>dato;
                cout<<"Digite el nuevo elemento: ";
                cin>>datoActualizar;
                actualizarElementos(lista, dato, datoActualizar);
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

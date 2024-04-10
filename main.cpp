#include <iostream>
#include <time.h>
#include <string>
#include <stdexcept>
#include <limits>
#include "stdlib.h"
#include "Pila.h"
#include "Cola.h"
#include "Nodo.h"

using namespace std;
void escribeMenu(void);
void opcion1(Cola *cReservas);
void opcion3(Cola *cReservas);
void opcion4(Pila *pMesas);
void opcion5(Pila *pMesas);
void opcion6(Pila *pMesas);
void opcion7(Cola *cReservas, Cola *cPendientes, Pila *pMesas, ColaPedidos *cPedidos);
void opcion8(Cola *cReservas, Cola *cPendientes, Pila *pMesas, ColaPedidos *cPedidos);
void opcion9(Cola *cReservas, Cola *cPendientes, Pila *pMesas, ColaPedidos *cPedidos);

int main() {
    Pila *pMesas = new Pila();
    Cola *cReservas = new Cola();
    Cola *cPendientes = new Cola();
    ColaPedidos *cPedidos = new ColaPedidos();
    srand(time(NULL)); // Inicializa los números
    int opc;

    while (true) {
        escribeMenu();

        if (cin >> opc && opc >= 0 && opc <= 9) {
            switch (opc) {
                case 1: opcion1(cReservas); break;
                case 2: cReservas->mostrarCola(); break;
                case 3: opcion3(cReservas); break;
                case 4: opcion4(pMesas); break;
                case 5: opcion5(pMesas); break;
                case 6: opcion6(pMesas); break;
                case 7: opcion7(cReservas, cPendientes, pMesas, cPedidos); break;
                case 8: opcion8(cReservas, cPendientes, pMesas, cPedidos); break;
                case 9: opcion9(cReservas, cPendientes, pMesas, cPedidos); break;
                case 0: return 0;
            }
        } else {
            cout << "\n Introduce un numero del 0 al 9\n";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}

void escribeMenu(void){
    cout<<"\n Menu: \n\t";
    cout<<"1. Generar aleatoriamente la cola de reservas realizadas por los clientes antes de la apertura del restaurante.\n\n\t";
    cout<<"2. Mostrar en pantalla los datos de la cola de reservas realizadas por los clientes, cReservas. \n\n\t";
    cout<<"3. Borrar la cola de reservas realizadas por los clientes, cReservas. \n\n\t";
    cout<<"4. Generar aleatoriamente la pila pMesas, con veinte mesas libres. \n\n\t";
    cout<<"5. Mostrar en pantalla los datos de la pila de mesas libres, pMesas. \n\n\t";
    cout<<"6. Borrar la pila de mesas libres, pMesas. \n\n\t";
    cout<<"7. Simular la gestion de la primera reserva.\n\n\t";
    cout<<"8. Simular la gestion de las reservas y creacion de pedidos de todas las reservas para la misma hora.\n\n\t";
    cout<<"9. Simular la gestion de todas las reservas del restaurante.\n\n\t";
    cout<<"0.- Salir.\n\t";
    cout<<"\nPulsa la opcion a realizar:\n\t";

}

/*void generarCola(Cola *cReservas, Reserva reserva) {

    Cola auxiliar;
    // Verifica si la cola cReservas está vacía
    if (cReservas->estaVacia()) {
        cReservas->encolar(reserva); // Si está vacía, agrega la reserva a la cola principal
    } else {
        // Transfiere elementos de la cola cReservas a la cola auxiliar
        while (!cReservas->estaVacia()) {
            Reserva reserva = cReservas->desencolar();
            auxiliar.encolar(reserva);
        }
        cReservas->encolar(reserva); // Agrega la nueva reserva a la cola principal
        // Transfiere elementos nuevamente a la cola cReservas desde la cola auxiliar
        while (!auxiliar.estaVacia()) {
            Reserva reserva = auxiliar.desencolar();
            cReservas->encolar(reserva);
        }
    }
}*/
/*void generarPila(Pila *pMesas, Mesa mesa){
    Pila auxiliar;
        pMesas->apilar(mesa);

}*/

void opcion1(Cola *cReservas){
    //genera 4 reservas a las 13:00
     for (int i = 0; i < 4; i++) {
        Reserva reserva;
        reserva = generarReserva();
        reserva.horaReserva = "13:00";
        cReservas->encolar(reserva);
     }
     //genera 4 reservas a las 14:00
     for (int i = 0; i < 4; i++) {
        Reserva reserva14;
        reserva14 = generarReserva();
        reserva14.horaReserva = "14:00";
        cReservas->encolar(reserva14);
     }
     //genera 4 reservas a las 15:00
     for (int i = 0; i < 4; i++) {
        Reserva reserva15;
        reserva15 = generarReserva();
        reserva15.horaReserva = "15:00";
        cReservas->encolar(reserva15);
    }
    //genera 4 reservas aleatorias
     for (int i = 0; i < 4; i++) {
        Reserva reserva;
        reserva = generarReserva();
        cReservas->encolar(reserva);
     }
}

void opcion3(Cola *cReservas){
    if(cReservas->estaVacia()){
        cout<<"La cola esta vacia, no hay nada que borrar";
    }else{
        while(!cReservas->estaVacia()){
            cReservas->desencolar();
        }
        cout<<"La cola se ha eliminado correctamente"<<endl;
    }
}

void opcion4(Pila *pMesas){
    if(pMesas->estaVacia()){
        for (int i = 0; i < 8; i++) {
            Mesa mesa;
            mesa = generarMesas(i+1);
            mesa.situacion = "Terraza";
            pMesas->apilar(mesa);
        }
        for (int i = 8; i < 20; i++) {
            Mesa mesa;
            mesa = generarMesas(i+1);
            pMesas->apilar(mesa);
        }
    }
    else{
        cout<<"\n\nLa cola de mesas ya esta creada"<<endl;

    }


}
void opcion5(Pila *pMesas){
    if(!pMesas->estaVacia()){
        pMesas->mostrarPila();
    }else{cout<<"\n\nTodavia no se ha creado la pila de mesas\n\n";}
}

void opcion6(Pila *pMesas){
    while(!(pMesas->estaVacia())){
        pMesas->desapilar();
    }
    cout<<"\n\nLa pila se ha eliminado correctamente\n\n"<<endl;
}

void opcion7(Cola *cReservas, Cola *cPendientes, Pila *pMesas, ColaPedidos *cPedidos){
    // Comprobar si cReservas está vacía

    if (!cReservas->estaVacia()) {
        // Desencolar la primera reserva de cReservas
        Reserva reserva = cReservas->desencolar();

        // Intentar asignar una mesa a la reserva
        Mesa mesaAsignada;
        bool mesaEncontrada = false;
        Pila auxiliar;

        // Buscar una mesa coincidente en pMesas
        while (!pMesas->estaVacia() && !mesaEncontrada) {
            Mesa mesa = pMesas->desapilar();
            auxiliar.apilar(mesa);
            if (mesa.capacidad >= reserva.numPersonas && mesa.situacion == reserva.situacionMesa) {
                // Mesa coincidente encontrada
                mesaAsignada = mesa;
                mesaEncontrada = true;
            }
        }
        //Volver a apilar las mesas en pMesas menos la que se acaba de asignar
        while (!auxiliar.estaVacia()) {
            Mesa mesa = auxiliar.desapilar();
            if (!(mesa.capacidad >= reserva.numPersonas && mesa.situacion == reserva.situacionMesa)) {
                pMesas->apilar(mesa);
            }
        }
        if (mesaEncontrada) {
            // Generar el pedido del cliente
            Pedido pedido;
            pedido.numeroMesa = mesaAsignada.numeroMesa;
            pedido.nombreCliente = reserva.nombreCliente;
            pedido.numPersonas = reserva.numPersonas;
            pedido.preferenciaMenu = reserva.preferenciaMenu;
            pedido.situacionMesa = reserva.situacionMesa;
            pedido.horaReserva = reserva.horaReserva;
            pedido.finalizado = false;

            // Encolar el pedido en cPedidos
            cPedidos->encolarPedido(pedido);
        } else {
            // La reserva no pudo ser asignada a una mesa, así que se almacena en cPendientes
            cPendientes->encolar(reserva);
        }

        cout << "Reservas Pendientes (cPendientes): \n\n";
        cPendientes->mostrarCola();

        cout << "Pedidos (cPedidos): \n\n";
        cPedidos->mostrarColaPedidos();
    } else {
        cout << "No hay reservas para gestionar en cReservas. \n\n";
    }

}

void opcion8 (Cola *cReservas, Cola *cPendientes, Pila *pMesas, ColaPedidos *cPedidos){

    Cola auxReservas;
    string hora;
    cout<<"Dime una hora para gestionar sus reservas"<<endl;
    cin>>hora;
    // Comprobar si cReservas está vacía
    while (!cReservas->estaVacia()) {

        // Desencolar la primera reserva de cReservas
        Reserva reserva = cReservas->desencolar();
        if (reserva.horaReserva==hora){

            // Intentar asignar una mesa a la reserva
            Mesa mesaAsignada;
            bool mesaEncontrada = false;
            Pila auxiliar;

            // Buscar una mesa coincidente en pMesas
            while (!pMesas->estaVacia() && !mesaEncontrada) {
                Mesa mesa = pMesas->desapilar();

                if (mesa.capacidad >= reserva.numPersonas && mesa.situacion == reserva.situacionMesa ) {
                    //Mesa coincidente encontrada
                    mesaAsignada = mesa;
                    mesaEncontrada = true;
                }else{
                    auxiliar.apilar(mesa);
                }
            }
            //Volver a apilar las mesas en pMesas menos la que se acaba de asignar
            while (!auxiliar.estaVacia()) {
                Mesa mesa = auxiliar.desapilar();
                pMesas->apilar(mesa);

            }
            if (mesaEncontrada) {
                // Generar el pedido del cliente
                Pedido pedido;
                pedido.numeroMesa = mesaAsignada.numeroMesa;
                pedido.nombreCliente = reserva.nombreCliente;
                pedido.numPersonas = reserva.numPersonas;
                pedido.preferenciaMenu = reserva.preferenciaMenu;
                pedido.situacionMesa = reserva.situacionMesa;
                pedido.horaReserva = reserva.horaReserva;
                pedido.finalizado = false;

                // Encolar el pedido en cPedidos
                cPedidos->encolarPedido(pedido);
            } else {
                // La reserva no pudo ser asignada a una mesa, así que se almacena en cPendientes
                cPendientes->encolar(reserva);
            }
        }
        else{
            auxReservas.encolar(reserva);
        }
    }
    while (!auxReservas.estaVacia()){
        cReservas->encolar(auxReservas.desencolar());
    }

    ColaPedidos aux;
    Mesa mesa;
    Pedido pedido;

   // Mostrar el contenido de las estructuras de datos relevantes

    cout << "\n\nReservas Pendientes (cPendientes): \n\n";
    cPendientes->mostrarCola();

    cout << "\n\nPedidos (cPedidos): \n\n";
    cPedidos->mostrarColaPedidos();

    cout<<"\n\n\tSe finalizaron las reservas de las: "<< hora<<"\n\n";
    //Finalizan la mitad de los pedidos
    while(!cPedidos->estaVaciaPedidos()){

        pedido=cPedidos->desencolarPedido();
        if(pedido.finalizado==false){
            pedido.finalizado = (rand() % 2 == 0 ? true : false);
            if(pedido.finalizado==true){
                cout<<"La mesa "<<pedido.numeroMesa<<" queda libre.\n";
                mesa.numeroMesa = pedido.numeroMesa;
                if(pedido.numPersonas<=4){
                    mesa.capacidad = 4;
                }else{mesa.capacidad = 8;}
                mesa.situacion = pedido.situacionMesa;
                pMesas->apilar(mesa);
            }
        }
        aux.encolarPedido(pedido);
    }
    while(!aux.estaVaciaPedidos()){
        pedido=aux.desencolarPedido();
        cPedidos->encolarPedido(pedido);
    }
}

void opcion9 (Cola *cReservas, Cola *cPendientes, Pila *pMesas, ColaPedidos *cPedidos){

    Cola auxReservas;
    string horas[] = {"13:00", "14:00", "15:00"};
    int numElementos = sizeof(horas) / sizeof(horas[0]);
    string hora;

    if (pMesas->estaVacia() && cPedidos->estaVaciaPedidos()){
        cout<< "\nLa pila de mesas no ha sido creada\n";
    }
    else if (!cReservas->estaVacia()) {
        for (int i= 0; i< numElementos; i++){

            hora = horas[i];
            // Comprobar si cReservas está vacía
            while (!cReservas->estaVacia()) {

                // Desencolar la primera reserva de cReservas
                Reserva reserva = cReservas->desencolar();

                if (reserva.horaReserva==hora){
                    // Intentar asignar una mesa a la reserva
                    Mesa mesaAsignada;
                    bool mesaEncontrada = false;

                    Pila auxiliar;
                    // Buscar una mesa coincidente en pMesas
                    while (!pMesas->estaVacia() && !mesaEncontrada) {
                        Mesa mesa = pMesas->desapilar();

                        if (mesa.capacidad >= reserva.numPersonas && mesa.situacion == reserva.situacionMesa ) {
                            // Mesa coincidente encontrada
                            mesaAsignada = mesa;
                            mesaEncontrada = true;
                        }else{
                            auxiliar.apilar(mesa);
                        }
                    }
                    //Volver a apilar las mesas en pMesas menos la que se acaba de asignar
                    while (!auxiliar.estaVacia()) {
                        Mesa mesa = auxiliar.desapilar();
                        pMesas->apilar(mesa);

                    }
                    //Si se encuentra una mesa generar el pedido del cliente
                    if (mesaEncontrada) {
                        Pedido pedido;
                        pedido.numeroMesa = mesaAsignada.numeroMesa;
                        pedido.nombreCliente = reserva.nombreCliente;
                        pedido.numPersonas = reserva.numPersonas;
                        pedido.preferenciaMenu = reserva.preferenciaMenu;
                        pedido.situacionMesa = reserva.situacionMesa;
                        pedido.horaReserva = reserva.horaReserva;
                        pedido.finalizado = false;

                        // Encolar el pedido en cPedidos
                        cPedidos->encolarPedido(pedido);
                    } else {
                        // La reserva no pudo ser asignada a una mesa, así que se almacena en cPendientes
                        cPendientes->encolar(reserva);
                    }
                }
                else{
                    auxReservas.encolar(reserva);
                }

            }
            while (!auxReservas.estaVacia()){
                cReservas->encolar(auxReservas.desencolar());
            }

            cout << "\nReservas Pendientes (cPendientes): \n\n";
            cPendientes->mostrarCola();

            cout << "\nPedidos (cPedidos): \n\n";
            cPedidos->mostrarColaPedidos();

            cout<<"\n\n\tSe finalizaron las reservas de las:"<< hora<<"\n\n";

            //Finalizan todos los pedidos de esa hora

            ColaPedidos aux;
            Mesa mesa;
            Pedido pedido;
            while(!cPedidos->estaVaciaPedidos()){

            pedido=cPedidos->desencolarPedido();
            if(pedido.finalizado==false){
                pedido.finalizado = true;
                cout<<"La mesa "<<pedido.numeroMesa<<" queda libre.\n";
                mesa.numeroMesa = pedido.numeroMesa;
                if(pedido.numPersonas<=4){
                    mesa.capacidad = 4;
                }else{mesa.capacidad = 8;}
                mesa.situacion = pedido.situacionMesa;
                pMesas->apilar(mesa);

            }
                aux.encolarPedido(pedido);
            }
            while(!aux.estaVaciaPedidos()){
                pedido=aux.desencolarPedido();
                cPedidos->encolarPedido(pedido);
            }
            //Comprobar si se puede asignar una mesa a la cola de cPendientes
            if (!cPendientes->estaVacia()){
                cout<<" Se inicia la gestion de Reservas Pendientes ";
                Cola auxiliar;
                int numPendientes = 0;

                while (!cPendientes->estaVacia()) {
                    Reserva reserva = cPendientes->desencolar();
                    numPendientes++;
                    auxiliar.encolar(reserva);  // Puedes almacenar los elementos desencolados en una cola auxiliar si deseas restaurar la cola original.
                }

                // Restaurar la cola original
                while (!auxiliar.estaVacia()) {
                    cPendientes->encolar(auxiliar.desencolar());
                }
                for (int i=0; i <numPendientes ; i++) {

                    // Desencolar la primera reserva de Pendientes
                    Reserva reserva = cPendientes->desencolar();

                    if (reserva.horaReserva==hora){
                            // Intentar asignar una mesa a la reserva
                            Mesa mesaAsignada;
                            bool mesaEncontrada = false;
                            Pila auxiliar;

                            // Buscar una mesa coincidente en pMesas
                            while (!pMesas->estaVacia() && !mesaEncontrada) {
                                Mesa mesa = pMesas->desapilar();

                                if (mesa.capacidad >= reserva.numPersonas && mesa.situacion == reserva.situacionMesa ) {
                                    // Mesa coincidente encontrada
                                    mesaAsignada = mesa;
                                    mesaEncontrada = true;
                                }else{
                                    auxiliar.apilar(mesa);
                                }
                            }
                            //Volver a apilar las mesas en pMesas menos la que se acaba de asignar
                            while (!auxiliar.estaVacia()) {
                                Mesa mesa = auxiliar.desapilar();
                                pMesas->apilar(mesa);

                            }
                            if (mesaEncontrada) {
                                // Generar el pedido del cliente
                                Pedido pedido;
                                pedido.numeroMesa = mesaAsignada.numeroMesa;
                                pedido.nombreCliente = reserva.nombreCliente;
                                pedido.numPersonas = reserva.numPersonas;
                                pedido.preferenciaMenu = reserva.preferenciaMenu;
                                pedido.situacionMesa = reserva.situacionMesa;
                                pedido.horaReserva = reserva.horaReserva;
                                pedido.finalizado = false;

                                // Encolar el pedido en cPedidos
                                cPedidos->encolarPedido(pedido);
                            }
                        }
                        else{
                            auxReservas.encolar(reserva);
                        }
                    }
                    while (!auxReservas.estaVacia()){
                        cPendientes->encolar(auxReservas.desencolar());

                    }

                    cout << "\n\nPedidos (cPedidos): \n\n";
                    cPedidos->mostrarColaPedidos();
                    cout << "\n\nSe finalizo la gestion de las Reservas Pendientes \n\n";

                }
                else {cout<<"\n No hay reservas pendientes que gestionar \n";}
                cout<< "\n===================================================================================================================================\n\n";
        }

    }
    else {
        cout<<"\nNo hay reservas que gestionar";
    }

}


/*
 * Utils.c
 *
 *  Created on: 6 abr. 2020
 *      Author: ripped dinos
 */


#include "Utils.h"

/* Crea un socket de escucha para un servidor en X puerto
 * RECORDAR HACER EL CLOSE DEL LISTENNING SOCKET EN LA FUNCION CORRESPONDIENTE
 * */
int crearConexion(char * puerto){
	    struct addrinfo hints;
		struct addrinfo *serverInfo;

		memset(&hints, 0, sizeof(hints));
		hints.ai_family = AF_UNSPEC;
		hints.ai_flags = AI_PASSIVE;
		hints.ai_socktype = SOCK_STREAM;

		getaddrinfo(NULL, puerto, &hints, &serverInfo);


		int listenningSocket;
		listenningSocket = socket(serverInfo->ai_family, serverInfo->ai_socktype, serverInfo->ai_protocol);


		bind(listenningSocket,serverInfo->ai_addr, serverInfo->ai_addrlen);
		freeaddrinfo(serverInfo);
		return listenningSocket;
}


/* Espera un cliente y cuando recibe una conexion, devuelve el socket correspondiente al cliente conectado.
 * RECORDAR HACER EL FREE AL PUNTERO SOCKETCLIENTE EN LA FUNCIÓN CORRESPONDIENTE Y EL CLOSE AL SOCKET
 */
int * esperarCliente(int listenningSocket, int backlog)
{
	struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    int *socketCliente = (int*)malloc(sizeof(int));
	*socketCliente=accept(listenningSocket, (struct sockaddr *) &addr, &addrlen);
    return socketCliente;
}

void inicializarColas(){
	  NEW_POKEMON=queue_create();
	  APPEARED_POKEMON=queue_create();
	  CATCH_POKEMON=queue_create();
	  CAUGHT_POKEMON=queue_create();
	  GET_POKEMON=queue_create();
	  LOCALIZED_POKEMON=queue_create();
}

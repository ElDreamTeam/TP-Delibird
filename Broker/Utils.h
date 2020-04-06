/*
 * Utils.h
 *
 *  Created on: 6 abr. 2020
 *      Author: ripped dinos
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdint.h>
#include <pthread.h>
#include <commons/log.h>
#include <commons/collections/list.h>
#include <commons/collections/queue.h>

t_queue * NEW_POKEMON;
t_queue * APPEARED_POKEMON;
t_queue * CATCH_POKEMON;
t_queue * CAUGHT_POKEMON;
t_queue * GET_POKEMON;
t_queue * LOCALIZED_POKEMON;

int crearConexion(char * puerto);
int * esperarCliente(int listenningSocket, int backlog);
void inicializarColas();

#endif /* UTILS_H_ */

/*
Simular una batalla entre dos gladiadores, uno será el usuario y el otro la máquina.

Cada gladiador tiene un nombre (hasta 10 caracteres), un tipo de arma, una fuerza y una salud. -> Estructura

Los ataques dependerán de la fuerza del gladiador y del tipo de arma, restarán salud a su contrincante.

Deberá haber dos tipos de arma: -> Estruct
	• Espada: el ataque será la fuerza del gladiador.
	• Lanza: en este caso será el doble de la fuerza del gladiador.

El programa deberá permitir al usuario ingresar los nombres de los dos gladiadores y datos de juego desde
la terminal. 

Al ejecutar el programa se le pasarán los datos de dos gladiadores (usuario y cpu en ese orden).

Deberá pasarle los siguientes parámetros (Espartaco será el usuario, Marcus la máquina):
./gladiadores.exe Espartaco,20,espada Marcus,10,lanza

Al inicio del programa, ambos jugadores tienen una salud de 100 unidades. 

Durante la batalla, el usuario tendrá la oportunidad de atacar o defenderse en cada turno mediante un menú. En el caso de la máquina
atacará con una probabilidad del 50% aleatorio.

La batalla se desarrollará por turnos hasta que uno de los gladiadores quede sin salud.

Al finalizar la batalla, el programa deberá mostrar el resultado y mostrar los datos del ganador de la batalla.
*/

#include <stdio.h>
#include <string.h>

typedef enum {
	ARMA_ESPADA, ARMA_LANZA	//Revisar daño
} Arma_e;

typedef struct {
	char nombre [10];
	char arma [10]; //Revisar con enum
	int fuerza;
	int salud;
} Gladiador_t;



int main(int argc, char *argv []){
	
	Gladiador_t gladiadorUsuario;
	Gladiador_t gladiadorMaquina;
	
	char bufferGladiadorUsuario [100];
	char bufferGladiadorMaquina [100];
	
	strncpy(bufferGladiadorUsuario, argv[1], sizeof(bufferGladiadorUsuario));
	strncpy(bufferGladiadorMaquina, argv[2], sizeof(bufferGladiadorMaquina));
	
	char *pGladiadorUsuario = strtok(bufferGladiadorUsuario, ",");
	while(pGladiadorUsuario != NULL){
		printf("Token: %s\n", pGladiadorUsuario);
		pGladiadorUsuario = strtok(NULL, ",");
	}
	
	strcpy(gladiadorUsuario.nombre,"Sergio");
	strcpy(gladiadorUsuario.arma, "Espada");
	gladiadorUsuario.fuerza = 100;
	gladiadorUsuario.salud = 100;
	
	//printf("Los datos del gladiador son: nombre -> %s, arma -> %s, fuerza -> %d, salud -> %d", prueba, gladiadorUsuario.arma, gladiadorUsuario.fuerza, gladiadorUsuario.salud);
	
	
	return 0;
}

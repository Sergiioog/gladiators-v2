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
	ARMA_ESPADA, ARMA_LANZA, ARMA_PROHIBIDA	//Revisar daño
} Arma_e;

typedef struct {
	char nombre [10];
	Arma_e arma;
	int fuerza;
	int salud;
} Gladiador_t;

Arma_e convierteStringArma(char *armaGladiador);

int main(int argc, char *argv []){
	
	Gladiador_t gladiadorUsuario;
	Gladiador_t gladiadorMaquina;
	
	char bufferGladiadorUsuario [100];
	char bufferGladiadorMaquina [100];
	char *armaU;
	char *armaM;
	
	if(argc != 3){
		printf("Error, numero de parametros incorrectos (Gld1,danio,arma Gld2,danio,arma)\n");
		return 0;
	}
	
	strncpy(bufferGladiadorUsuario, argv[1], sizeof(bufferGladiadorUsuario));
	strncpy(bufferGladiadorMaquina, argv[2], sizeof(bufferGladiadorMaquina));
	
	char *pGladiadorUsuario = strtok(bufferGladiadorUsuario, ",");
	while(pGladiadorUsuario != NULL){
		printf("Token: %s\n", pGladiadorUsuario);
		armaU = pGladiadorUsuario;
		pGladiadorUsuario = strtok(NULL, ",");
	}
	
	char *pGladiadorMaquina = strtok(bufferGladiadorMaquina, ",");
	while(pGladiadorMaquina != NULL){
		printf("Token maquina: %s\n", pGladiadorMaquina);
		armaM = pGladiadorMaquina;
		pGladiadorMaquina = strtok(NULL, ",");
	}
	
	Arma_e armaFinalUsuario = convierteStringArma(armaU);
	Arma_e armaFinalMaquina = convierteStringArma(armaM);
	
	if(armaFinalUsuario == ARMA_ESPADA && armaFinalMaquina == ARMA_ESPADA){
		printf("Ambos seleccionaron la espada \n");
	}else if(armaFinalUsuario == ARMA_LANZA && armaFinalMaquina == ARMA_LANZA){
		printf("Ambos seleccionaron la lanza\n");
	}else if(armaFinalUsuario == ARMA_ESPADA && armaFinalMaquina == ARMA_LANZA){
		printf("El usuario escogio la espada, mientras que el otro la lanza\n");
	}else if(armaFinalUsuario == ARMA_LANZA && armaFinalMaquina == ARMA_ESPADA){
		printf("El usuario escogio la lanza, mientras que el otro la espada\n");
	}else{
		printf("Arma final seleccionada desconocida, introduza espada o lanza\n");
		return 0;
	}
	
	//Seguir con la fuerza de las armas y los valores de los datos de los gladiadores
	
	return 0;
}

Arma_e convierteStringArma(char *armaGladiador){
	
	printf("El arma pasada es: %s\n", armaGladiador);
	
	if(strcmp(armaGladiador, "espada") == 0) return ARMA_ESPADA;
	if(strcmp(armaGladiador, "lanza") == 0) return ARMA_LANZA;
	
	return ARMA_PROHIBIDA;
}
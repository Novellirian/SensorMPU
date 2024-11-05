#ifndef _PILHASENSOR_H
#define _PILHASENSOR_H

#include "mpuTAD.h"

#define LIMITE_SENSORES 100  // Limite máximo de sensores na pilha

// Tipo de dado abstrato para representar a pilha de sensores MPU
typedef struct st_PilhaSensor *PilhaSensor;

/**
 * Cria e inicializa uma pilha para armazenar sensores MPU.
 * retorna Ponteiro para a pilha criada.
 */
PilhaSensor criarPilhaSensor(void);

/**
 * Libera a memória alocada para a pilha e todos os sensores MPU armazenados.
 * pilha Ponteiro para a pilha a ser liberada.
 */
void liberarPilhaSensor(PilhaSensor pilha);

/**
 * Adiciona um sensor MPU no topo da pilha.
 * pilha Ponteiro para a pilha onde o sensor será adicionado.
 * sensor Ponteiro para o sensor MPU a ser adicionado.
 * retorna 1 se o sensor foi adicionado com sucesso, 0 se a pilha estiver cheia.
 */
int empilharSensor(PilhaSensor pilha, Mpu sensor);

/**
 * Remove o sensor MPU do topo da pilha.
 * pilha Ponteiro para a pilha de onde o sensor será removido.
 * retorna Ponteiro para o sensor removido ou NULL se a pilha estiver vazia.
 */
Mpu desempilharSensor(PilhaSensor pilha);

/**
 * Verifica se a pilha está vazia.
 * pilha Ponteiro para a pilha a ser verificada.
 * retorna 1 se a pilha estiver vazia, 0 caso contrário.
 */
int pilhaSensorVazia(PilhaSensor pilha);

/**
 * Verifica se a pilha está cheia.
 * pilha Ponteiro para a pilha a ser verificada.
 * retorna 1 se a pilha estiver cheia, 0 caso contrário.
 */
int pilhaSensorCheia(PilhaSensor pilha);

#endif

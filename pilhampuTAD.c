#include "pilhampuTAD.h"
#include <stdlib.h>
#include <stdio.h>

struct st_PilhaSensor {
    Mpu sensores[LIMITE_SENSORES];
    int indiceTopo;
};

PilhaSensor criarPilhaSensor(void) {
    PilhaSensor novaPilha = (PilhaSensor)malloc(sizeof(struct st_PilhaSensor));
    if (novaPilha != NULL) {
        novaPilha->indiceTopo = -1;  // Inicializa o topo como -1, indicando pilha vazia
    }
    return novaPilha;
}

void liberarPilhaSensor(PilhaSensor pilha) {
    if (pilha != NULL) {
        for (int i = 0; i <= pilha->indiceTopo; i++) {
            free(pilha->sensores[i]);  // Libera cada sensor MPU na pilha
        }
        free(pilha);  // Libera a estrutura da pilha
    }
}

int empilharSensor(PilhaSensor pilha, Mpu sensor) {
    if (pilha == NULL || pilhaSensorCheia(pilha)) {
        return 0;  // Falha ao empilhar, pilha cheia ou inválida
    }
    pilha->sensores[++(pilha->indiceTopo)] = sensor;
    return 1;  // Sucesso ao empilhar
}

Mpu desempilharSensor(PilhaSensor pilha) {
    if (pilha == NULL || pilhaSensorVazia(pilha)) {
        return NULL;  // Falha ao desempilhar, pilha vazia ou inválida
    }
    return pilha->sensores[(pilha->indiceTopo)--];
}

int pilhaSensorVazia(PilhaSensor pilha) {
    return pilha != NULL && pilha->indiceTopo == -1;
}

int pilhaSensorCheia(PilhaSensor pilha) {
    return pilha != NULL && pilha->indiceTopo == LIMITE_SENSORES - 1;
}

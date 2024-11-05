#include "mpuTAD.h"
#include "pilhampuTAD.h"
#include <stdio.h>

void testarCriacaoPilha() {
    // Testa a criação da pilha de sensores
    printf("Teste de criação da pilha:\n");
    PilhaSensor pilha = criarPilhaSensor();
    if (pilha != NULL) {
        printf("Pilha criada com sucesso.\n");
    } else {
        printf("Erro ao criar a pilha.\n");
    }
    liberarPilhaSensor(pilha);
}

void testarEmpilhamentoDesempilhamento() {
    // Cria uma nova pilha
    PilhaSensor pilha = criarPilhaSensor();
    
    printf("Teste de empilhamento e desempilhamento:\n");
    Mpu sensor1 = criarMpu(100, 200, 300, 400, 500, 600, 250, 2);
    Mpu sensor2 = criarMpu(110, 210, 310, 410, 510, 610, 500, 4);

    // Empilha sensores
    empilharSensor(pilha, sensor1);
    empilharSensor(pilha, sensor2);
    
    // Desempilha e exibe valores
    Mpu sensorRemovido = desempilharSensor(pilha);
    if (sensorRemovido != NULL) {
        printf("Sensor desempilhado: Aceleracao Bruta (ax=%d, ay=%d, az=%d)\n",
               AdquirirAceleracaoBruta(sensorRemovido)[0],
               AdquirirAceleracaoBruta(sensorRemovido)[1],
               AdquirirAceleracaoBruta(sensorRemovido)[2]);
        free(sensorRemovido);
    } else {
        printf("Erro ao desempilhar.\n");
    }

    liberarPilhaSensor(pilha);
}

void testarPilhaCheia() {
    // Testa a condição de pilha cheia
    PilhaSensor pilha = criarPilhaSensor();
    printf("Teste de pilha cheia:\n");
    
    // Empilha até a pilha estar cheia
    for (int i = 0; i < LIMITE_SENSORES; i++) {
        Mpu sensor = criarMpu(i, i+1, i+2, i+3, i+4, i+5, 250, 2);
        empilharSensor(pilha, sensor);
    }
    
    // Tenta empilhar em uma pilha cheia
    Mpu sensorExtra = criarMpu(200, 200, 200, 300, 300, 300, 500, 4);
    if (!empilharSensor(pilha, sensorExtra)) {
        printf("Pilha cheia, não foi possível empilhar o sensor extra.\n");
    }
    
    // Limpa a pilha
    liberarPilhaSensor(pilha);
}

void testarPilhaVazia() {
    // Testa a condição de pilha vazia
    PilhaSensor pilha = criarPilhaSensor();
    printf("Teste de pilha vazia:\n");
    
    // Verifica desempilhamento de uma pilha vazia
    Mpu sensorRemovido = desempilharSensor(pilha);
    if (sensorRemovido == NULL) {
        printf("Pilha vazia, não foi possível desempilhar.\n");
    }
    
    liberarPilhaSensor(pilha);
}

void testarSensibilidadesInvalidas() {
    // Testa configuração de sensibilidades inválidas
    printf("Teste de sensibilidades inválidas:\n");
    Mpu sensor = criarMpu(0, 0, 0, 0, 0, 0, 250, 2);
    
    setSensibilidades(sensor, 3, 300);  // Valores inválidos
    printf("Sensibilidade de Aceleracao (esperado 2): %d\n", getsensA(sensor));
    printf("Sensibilidade de Rotacao (esperado 250): %d\n", getsensR(sensor));
    
    free(sensor);
}

int main() {
    testarCriacaoPilha();
    testarEmpilhamentoDesempilhamento();
    testarPilhaCheia();
    testarPilhaVazia();
    testarSensibilidadesInvalidas();

    return 0;
}

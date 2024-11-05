#include "mpuTAD.h"
#include <stdio.h>
#include <stdlib.h>

void testarCriacaoMpu() {
  Mpu mpu = criarMpu(14768, 26768, 10768, 5000, 531, 3853, 500, 4);
  printf("Teste de criação MPU:\n");
  printf("Aceleração final: %f, %f, %f\n", getAceleracaoResultado(mpu)[0],
         getAceleracaoResultado(mpu)[1], getAceleracaoResultado(mpu)[2]);
  printf("Rotação final: %f, %f, %f\n", getRotacaoResultado(mpu)[0],
         getRotacaoResultado(mpu)[1], getRotacaoResultado(mpu)[2]);
  free(mpu);
}

void testarSensibilidade() {
  Mpu mpu = criarMpu(0, 0, 0, 0, 0, 0, 250, 2);
  printf("Teste de sensibilidades:\n");
  setSensibilidades(mpu, 4, 500);
  printf("Sensibilidade A: %d, Sensibilidade R: %d\n", getsensA(mpu),
         getsensR(mpu));
  free(mpu);
}

void testarSetAceleracao() {
  Mpu mpu = criarMpu(0, 0, 0, 0, 0, 0, 500, 2);
  setAceleracao(mpu, 27683, 16384, 8192);
  printf("Teste de setAceleracao:\n");
  printf("Aceleração final: %f, %f, %f\n", getAceleracaoResultado(mpu)[0],
         getAceleracaoResultado(mpu)[1], getAceleracaoResultado(mpu)[2]);
  free(mpu);
}

void testarSetRotacao() {
  Mpu mpu = criarMpu(0, 0, 0, 0, 0, 0, 500, 2);
  setRotacao(mpu, 5000, 10000, 15000);
  printf("Teste de setRotacao:\n");
  printf("Rotação final: %f, %f, %f\n", getRotacaoResultado(mpu)[0],
         getRotacaoResultado(mpu)[1], getRotacaoResultado(mpu)[2]);
  free(mpu);
}

void testarValoresInvalidos() {
  Mpu mpu = criarMpu(0, 0, 0, 0, 0, 0, 250, 2);
  printf("Teste de sensibilidades inválidas:\n");
  setSensibilidades(mpu, 3, 300); // Valores inválidos
  printf("Sensibilidade A (deveria ser 2): %d\n", getsensA(mpu));
  printf("Sensibilidade R (deveria ser 250): %d\n", getsensR(mpu));
  free(mpu);
}

int main() {
  testarCriacaoMpu();
  testarSensibilidade();
  testarSetAceleracao();
  testarSetRotacao();
  testarValoresInvalidos();

  return 0;
}
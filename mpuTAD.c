#include "mpuTAD.h"
#include <stdio.h>
#include <stdlib.h>

struct st_Mpu {
  // Valores Brutos aceleração:
  signed short int ax;
  signed short int ay;
  signed short int az;
  // Valores corretos aceleração:
  float ax_resultado;
  float ay_resultado;
  float az_resultado;

  // Valores Brutos rotação:
  signed short int rx;
  signed short int ry;
  signed short int rz;
  // Valores corretos aceleração:
  float rx_resultado;
  float ry_resultado;
  float rz_resultado;

  short int sensA;
  short int sensR;
};

short int fatorEscalaA(short int sensA) {
  switch (sensA) {
  case 2:
    return 16384;
  case 4:
    return 8192;
  case 8:
    return 4096;
  case 16:
    return 2048;
  default:
    return 0;
  }
}

float fatorEscalaR(short int sensR) {
  switch (sensR) {
  case 250:
    return 131.0;
  case 500:
    return 65.5;
  case 1000:
    return 32.8;
  case 2000:
    return 16.4;
  default:
    return 0;
  }
}

Mpu criarMpu(short int ax, short int ay, short int az, short int rx,
             short int ry, short int rz, short int sensR,
             short int sensA) {
  Mpu temp = malloc(sizeof(struct st_Mpu));
  if (temp == NULL) {
    printf("Erro ao alocar: criarMpu()\n");
    exit(1);
  }
  temp->ax = ax;
  temp->ay = ay;
  temp->az = az;
  temp->rx = rx;
  temp->ry = ry;
  temp->rz = rz;

  temp->sensA = sensA;
  temp->sensR = sensR;
  calcularResultados(temp);
  return temp;
}

void calcularResultados(Mpu mpu) {
  float sensiA = fatorEscalaA(mpu->sensA);
  float sensiR = fatorEscalaR(mpu->sensR);

  // Aceleracao
  mpu->ax_resultado = mpu->ax / sensiA;
  mpu->ay_resultado = mpu->ay / sensiA;
  mpu->az_resultado = mpu->az / sensiA;
  // Rotação
  mpu->rx_resultado = mpu->rx / sensiR;
  mpu->ry_resultado = mpu->ry / sensiR;
  mpu->rz_resultado = mpu->rz / sensiR;
}

short int *AdquirirAceleracaoBruta(Mpu mpu) {
  short int *posicao = malloc(3 * sizeof(signed short int));
  if (posicao == NULL) {
    printf("Erro ao alocar: getAceleracaoBruta()\n");
    exit(1);
  }
  posicao[0] = mpu->ax;
  posicao[1] = mpu->ay;
  posicao[2] = mpu->az;

  return posicao;
}

short int *AdquirirRotacaoBruta(Mpu mpu) {
  short int *posicao = malloc(3 * sizeof(signed short int));
  if (posicao == NULL) {
    printf("Erro ao alocar: getRotacaoBruta()\n");
    exit(1);
  }
  posicao[0] = mpu->rx;
  posicao[1] = mpu->ry;
  posicao[2] = mpu->rz;

  return posicao;
}

float *getAceleracaoResultado(Mpu mpu) {
  float *posicao = malloc(3 * sizeof(signed short int));
  if (posicao == NULL) {
    printf("Erro ao alocar: getAceleracaoResultado()\n");
    exit(1);
  }
  posicao[0] = mpu->ax_resultado;
  posicao[1] = mpu->ay_resultado;
  posicao[2] = mpu->az_resultado;

  return posicao;
}

float *getRotacaoResultado(Mpu mpu) {
  float *posicao = malloc(3 * sizeof(signed short int));
  if (posicao == NULL) {
    printf("Erro ao alocar: getRotacaoResultado()\n");
    exit(1);
  }
  posicao[0] = mpu->rx_resultado;
  posicao[1] = mpu->ry_resultado;
  posicao[2] = mpu->rz_resultado;

  return posicao;
}

short int getsensA(Mpu mpu) { return mpu->sensA; }

short int getsensR(Mpu mpu) { return mpu->sensR; }

void setSensibilidades(Mpu mpu, short int sensA,
                       short int sensR) {

  if (sensA != 2 && sensA != 4 && sensA != 8 &&
      sensA != 16) {
    printf("sensA invalida, valor deve ser: 2, 4, 8, 16\n");
    return;
  }
  if (sensR != 250 && sensR != 500 &&
      sensR != 1000 && sensR != 2000) {
    printf("sensR invalida, valor deve ser: 250, 500, 1000, 2000\n");
    return;
  }

  mpu->sensA = sensA;
  mpu->sensR = sensR;
  calcularResultados(mpu);
}

void setAceleracao(Mpu mpu, short int x, short int y, short int z) {
  mpu->ax = x;
  mpu->ay = y;
  mpu->az = z;
  calcularResultados(mpu);
}

void setRotacao(Mpu mpu, short int x, short int y, short int z) {
  mpu->rx = x;
  mpu->ry = y;
  mpu->rz = z;
  calcularResultados(mpu);
}
#ifndef _MPUTAD_H
#define _MPUTAD_H

// Tipo de dado abstrato para representar um sensor MPU
typedef struct st_Mpu *Mpu;

/**
 * Calcula o fator de escala para aceleração baseado na sensibilidade.
 * sensibilidadeA Nível de sensibilidade (2, 4, 8, 16).
 * Retorna Fator de escala correspondente para a aceleração.
 */
short int fatorEscalaA(short int sensibilidadeA);

/**
 * Calcula o fator de escala para rotação baseado na sensibilidade.
 * sensibilidadeR Nível de sensibilidade (250, 500, 1000, 2000).
 * Retorna Fator de escala correspondente para a rotação.
 */
float fatorEscalaR(short int sensibilidadeR);

/**
 * Cria e inicializa uma estrutura Mpu com valores de aceleração e rotação.
 * ax, ay, az Valores brutos de aceleração.
 * rx, ry, rz Valores brutos de rotação.
 * sensibilidadeR Sensibilidade para rotação.
 * sensibilidadeA Sensibilidade para aceleração.
 * Retorna Ponteiro para a estrutura Mpu criada.
 */
Mpu criarMpu(short int ax, short int ay, short int az, short int rx,
             short int ry, short int rz, short int sensibilidadeR,
             short int sensibilidadeA);

/**
 * Calcula os valores finais de aceleração e rotação com base nos fatores de escala.
 * mpu Estrutura Mpu com os dados a serem calculados.
 */
void calcularResultados(Mpu mpu);

/**
 * Obtém os valores brutos de aceleração (ax, ay, az).
 * mpu Estrutura Mpu de onde os valores serão extraídos.
 * Retorna Ponteiro para um array contendo os valores brutos de aceleração.
 */
short int *AdquirirAceleracaoBruta(Mpu mpu);

/**
 * Obtém os valores brutos de rotação (rx, ry, rz).
 * mpu Estrutura Mpu de onde os valores serão extraídos.
 * Retorna Ponteiro para um array contendo os valores brutos de rotação.
 */
short int *AdquirirRotacaoBruta(Mpu mpu);

/**
 * Obtém os valores finais de aceleração ajustados pelos fatores de escala.
 * mpu Estrutura Mpu de onde os valores serão extraídos.
 * Retorna Ponteiro para um array contendo os valores finais de aceleração.
 */
float *getAceleracaoResultado(Mpu mpu);

/**
 * Obtém os valores finais de rotação ajustados pelos fatores de escala.
 * mpu Estrutura Mpu de onde os valores serão extraídos.
 * Retorna Ponteiro para um array contendo os valores finais de rotação.
 */
float *getRotacaoResultado(Mpu mpu);

/**
 * Retorna o valor da sensibilidade de aceleração configurada.
 * mpu Estrutura Mpu de onde o valor será extraído.
 * Retorna Valor da sensibilidade de aceleração.
 */
short int getsensA(Mpu mpu);

/**
 * Retorna o valor da sensibilidade de rotação configurada.
 * mpu Estrutura Mpu de onde o valor será extraído.
 * Retorna Valor da sensibilidade de rotação.
 */
short int getsensB(Mpu mpu);

/**
 * Configura os valores de sensibilidade para aceleração e rotação.
 * mpu Estrutura Mpu onde os valores serão configurados.
 * sensibilidadeA Nova sensibilidade para aceleração.
 * sensibilidadeR Nova sensibilidade para rotação.
 */
void setSensibilidades(Mpu mpu, short int sensibilidadeA,
                       short int sensibilidadeR);

/**
 * Define novos valores brutos de aceleração e atualiza os valores finais.
 * mpu Estrutura Mpu onde os valores serão atualizados.
 * x, y, z Novos valores brutos de aceleração.
 */
void setAceleracao(Mpu mpu, short int x, short int y, short int z);

/**
 * Define novos valores brutos de rotação e atualiza os valores finais.
 * mpu Estrutura Mpu onde os valores serão atualizados.
 * x, y, z Novos valores brutos de rotação.
 */
void setRotacao(Mpu mpu, short int x, short int y, short int z);

#endif

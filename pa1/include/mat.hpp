#ifndef MAT_HPP
#define MAT_HPP

/**
 * @file mat.hpp
 * @brief Definição de funções e estrutura para manipulação de matrizes.
 * 
 * Este arquivo contém as declarações necessárias para a criação e manipulação de matrizes.
 * Inclui funcionalidades para criar, inicializar, acessar, imprimir, e realizar operações
 * matemáticas (como soma, multiplicação e transposição) em matrizes, além de destruir
 * matrizes para liberar memória.
 */

#include <stdlib.h>
#include <stdio.h>

#define MAXTAM 5 // tamanho máximo da matriz

/**
 * @brief Estrutura que representa uma matriz.
 * 
 * Esta estrutura armazena os valores da matriz, as suas dimensões (número de linhas e colunas) e
 * um identificador único para cada matriz.
 */
typedef struct mat{
	double m[MAXTAM][MAXTAM];
	int tamx, tamy;
	int id;
} mat_tipo;

/**
 * @brief Cria uma matriz com dimensões tx x ty e um identificador id.
 * 
 * @param mat Ponteiro para a matriz a ser inicilizada.
 * @param tx Número de linhas da matriz.
 * @param ty Número de colunas da matriz.
 * @param id Identificador único da matriz.
 */
void criaMatriz(mat_tipo *mat, int tx, int ty, int id);

/**
 * @brief inicializa matriz com valores nulos 
 * 
 * @param mat Ponteiro para a matriz a ser inicializada.
 */
void inicializaMatrizNula(mat_tipo *mat);

/**
 * @brief Inicializa a matriz com valores aleatórios.
 * 
 * @param mat Ponteiro para a matriz a ser inicializada.
 */
void inicializaMatrizAleatoria(mat_tipo *mat);

/**
 * @brief Acessa um elemento da matriz para fins de registro de acesso.
 * 
 * @param mat Ponteiro para a matriz a ser acessada.
 * @return Soma de todos os valores da matriz.
 */
double acessaMatriz(mat_tipo *mat);

/**
 * @brief Imprime a matriz com a identificacao de linhas e colunas
 * 
 * @param mat Ponteiro para a matriz a ser impressa.
 */
void imprimeMatriz(mat_tipo *mat);

/**
 * @brief Salva a matriz em arquivo.
 * 
 * @param mat Ponteiro para a matriz a ser salva.
 * @param out Ponteiro para o arquivo onde a matriz será salva.
 */
void salvaMatriz(mat_tipo *mat, FILE *out);

/**
 * @brief Atribui o valor v ao elemento (x,y) da matriz mat
 * 
 * @param mat Ponteiro para a matriz.
 * @param x Índice da linha.
 * @param y Índice da coluna.
 * @param v Valor a ser atribuído ao elemento (x, y).
 */
void escreveElemento(mat_tipo *mat, int x, int y, double v);

/**
 * @brief Retorna o elemento (x,y) da matriz mat
 * 
 * @param mat Ponteiro para a matriz.
 * @param x Índice da linha.
 * @param y Índice da coluna.
 * @return Valor do elemento (x, y) da matriz.
 */
double leElemento(mat_tipo *mat, int x, int y);

/**
 * @brief Faz uma copia da matriz src em dst
 * 
 * @param src Ponteiro para a matriz fonte.
 * @param dst Ponteiro para a matriz destino.
 * @param dst_id Identificador da matriz destino.
 */
void copiaMatriz(mat_tipo *src, mat_tipo *dst, int dst_id);

/**
 * @brief Soma as matrizes a e b e armazena o resultado em c
 * 
 * @param a Ponteiro para a primeira matriz.
 * @param b Ponteiro para a segunda matriz.
 * @param c Ponteiro para a matriz onde o resultado da soma será armazenado.
 */
void somaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c);

/**
 * @brief Multiplica as matrizes a e b e armazena o resultado em c
 * 
 * @param a Ponteiro para a primeira matriz.
 * @param b Ponteiro para a segunda matriz.
 * @param c Ponteiro para a matriz onde o resultado da multiplicação será armazenado.
 */
void multiplicaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c);

/**
 * @brief Transpoe a matriz a
 * 
 * @param a Ponteiro para a matriz a ser transposta.
 */
void transpoeMatriz(mat_tipo *a);

/**
 * @brief Destroi a matriz a, que se torna inacessível
 * 
 * @param a Ponteiro para a matriz a ser destruída.
 */
void destroiMatriz(mat_tipo *a);

#endif
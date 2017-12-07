#ifndef BOARDLIB
#define BOARDLIB
#include "board.cpp"
#endif

#ifndef KINEMATICSLIB
#define KINEMATICSLIB
#include "kinematics.cpp"
#endif

const float TAMANHO_CASA = 5.5;
const float TABULEIRO_SEM_BORDA = TAMANHO_CASA * TAMANHO_TABULEIRO;
const float TAMANHO_BORDA = 2.0;
const float TABULERO_COM_BORDA = TABULEIRO_SEM_BORDA + TAMANHO_BORDA * 2.0;
const float DISTANCIA_TABULEIRO_EO_ROBO = 5.0;
const float ALTURA_CIMA = 10.0;
const float ALTURA_BAIXO = 5.0;
const float TEMPO_MAXIMO = 2.0;

const float X_INICIAL = 0;
const float Y_INICIAL = 14.0;
const float Z_INICIAL = 24.0;

const int FREQUENCIA = 10; //Hz

Coordenada localizar(Casa casa, bool isHigh);

Coordenada* intercalar(Coordenada origem, Coordenada destino, const double segundos);

void mover(Movimento movimento);
void executarTrajeto(Coordenada *trajeto, int tamanho, bool garra);
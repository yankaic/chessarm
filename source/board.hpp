#ifndef ROLESLIB
#define ROLESLIB
#include "chessroles.cpp"
#endif

// indices para o tabuleiro abaixo
#define BRANCO 	0
#define PRETO 	1
#define PEAO 		2
#define TORRE 	3
#define CAVALO 	4
#define BISPO 	5
#define RAINHA 	6
#define REI 		7
#define casasOcupadas ((pecas[BRANCO] | pecas[PRETO]))

Mapa pecas[8] = {
	0x000000000000FFFF,	//brancas
	0xFFFF000000000000,	//pretas
	0x00FF00000000FF00, //peoes
	0x8100000000000081,	//torres
	0x4200000000000042,	//cavalos
	0x2400000000000024,	//bispos
	0x0800000000000008,	//rainhas
	0x1000000000000010	//reis
};

struct Movimento{
	Casa origem;
	Casa destino;
};


void registrarMovimento(Movimento movimento); 

int tipoPeca(Casa Casa);
int corPeca(Casa casa);

char* boardString();
char* whiteString();
char* blackString();







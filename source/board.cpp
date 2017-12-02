#include "board.hpp"

void registrarMovimento(Movimento movimento){
	Mapa origem = mapear(movimento.origem);
	Mapa destino = mapear(movimento.destino);

	int atacante = tipoPeca(movimento.origem);
	int cor = corPeca(movimento.origem);

	pecas[atacante] |= destino;		//uniao
	pecas[cor] |= destino;				//uniao

	for(int tipo = BRANCO; tipo <= REI; tipo++){		
 		if(!(tipo == atacante || tipo == cor))
			pecas[tipo] &= ~destino;		// diferenca (A-B)
		pecas[tipo] &= ~origem;					// diferenca (A-B)
	}
}

int tipoPeca(Casa casa){
	int tipo;
	for(tipo = PEAO; tipo <= REI 
		&& !contem(pecas[tipo], mapear(casa)); tipo++) {}
	return tipo;
}

int corPeca(Casa casa){
	return contem(pecas[BRANCO], mapear(casa)) ? BRANCO : PRETO;
}

char* boardString(){	
	char* text = emptyString();
	toString	(pecas[PEAO] 	& pecas[BRANCO],	text,'p');
	toString	(pecas[TORRE] 	& pecas[BRANCO],	text,'r');
	toString	(pecas[CAVALO] & pecas[BRANCO],	text,'h');
	toString	(pecas[BISPO] & pecas[BRANCO],	text,'b');
	toString	(pecas[RAINHA] 	& pecas[BRANCO],	text,'q');
	toString	(pecas[REI] 	& pecas[BRANCO],	text,'k');

	toString	(pecas[PEAO] 	& pecas[PRETO],	text,'P');
	toString	(pecas[TORRE] 	& pecas[PRETO],	text,'R');
	toString	(pecas[CAVALO] & pecas[PRETO],	text,'H');
	toString	(pecas[BISPO] & pecas[PRETO],	text,'B');
	toString	(pecas[RAINHA] 	& pecas[PRETO],	text,'Q');
	toString	(pecas[REI] 	& pecas[PRETO],	text,'K');
	return text;	
}

char* whiteString(){
	char* text = emptyString();
	toString	(pecas[PEAO] 	& pecas[BRANCO],	text,'p');
	toString	(pecas[TORRE] 	& pecas[BRANCO],	text,'r');
	toString	(pecas[CAVALO] & pecas[BRANCO],	text,'h');
	toString	(pecas[BISPO] & pecas[BRANCO],	text,'b');
	toString	(pecas[RAINHA] 	& pecas[BRANCO],	text,'q');
	toString	(pecas[REI] 	& pecas[BRANCO],	text,'k');
	return text;
}

char* blackString(){
	char* text = emptyString();
	toString	(pecas[PEAO] 	& pecas[PRETO],	text,'P');
	toString	(pecas[TORRE] 	& pecas[PRETO],	text,'R');
	toString	(pecas[CAVALO] & pecas[PRETO],	text,'H');
	toString	(pecas[BISPO] & pecas[PRETO],	text,'B');
	toString	(pecas[RAINHA] 	& pecas[PRETO],	text,'Q');
	toString	(pecas[REI] 	& pecas[PRETO],	text,'K');
	return text;	
}

#include "movecontrol.hpp"

Coordenada localizar(Casa casa, bool high){
	Coordenada posicao; //colocando a peca na posicao a0
	posicao.x = TAMANHO_CASA * -3.5;
	posicao.y = DISTANCIA_TABULEIRO_EO_ROBO + TAMANHO_BORDA + TAMANHO_CASA / 2;
	posicao.z = high ? ALTURA_CIMA : ALTURA_BAIXO;

	//colocando na posicao de acordo com casa
	posicao.x += casa.coluna * TAMANHO_CASA;
	posicao.y += casa.fileira * TAMANHO_CASA;
	return posicao;
}	


Coordenada* intercalar(Coordenada origem, Coordenada destino, const double segundos){
	Coordenada diferenca;
	diferenca.x = destino.x - origem.x;
	diferenca.y = destino.y - origem.y;
	diferenca.z = destino.z - origem.z;

	Coordenada posicao;
	Coordenada *coordenadas = new Coordenada[(int)(FREQUENCIA * segundos)]; 

	double escala = 0, incremento = 1.0 / (FREQUENCIA * segundos);

	for(int i = 0; escala <= 1; escala += incremento, i++){
		posicao.x = origem.x + diferenca.x * escala;
		posicao.y = origem.y + diferenca.y * escala;
		posicao.z = origem.z + diferenca.z * escala;
		coordenadas[i] = posicao;
	}
	posicao.x = origem.x + diferenca.x * escala;
	posicao.y = origem.y + diferenca.y * escala;
	posicao.z = origem.z + diferenca.z * escala;
	coordenadas[(int)(FREQUENCIA * segundos) -1] = posicao;

	return coordenadas;
}

void movimento(Movimento movimento){
	Coordenada posicaoInicial, origem, origemAlta, destino, DestinoAlto;

	posicaoInicial.x = X_INICIAL;
	posicaoInicial.y = Y_INICIAL;
	posicaoInicial.z = Z_INICIAL;

	origem = localizar(movimento.origem, false);
	origemAlta = origem;
	origemAlta.z = ALTURA_CIMA;

	destino = localizar(movimento.destino, false);
	DestinoAlto = destino;
	DestinoAlto.z = ALTURA_CIMA;

	Coordenada *trajetoPrepararCaptura, *trajetoCaptura, *trajetoVoltarCaptura, 
		*trajetoPrepararAtaque, *trajetoAtaque, *trajetoVoltarAtaque, *trajetoVoltarInicial;

	const double prepareTakeSeconds = 2, takeSeconds = 1, returnTakeSeconds = 1, 
		prepareAttackSeconds = 2, attackSeconds = 1, returnAttackSeconds = 1, returnInitialSeconds = 3;

	trajetoPrepararCaptura 	= intercalar(posicaoInicial, 	origemAlta,				prepareTakeSeconds);
	trajetoCaptura 					= intercalar(origemAlta, 			origem, 					takeSeconds);
	trajetoVoltarCaptura 		= intercalar(origem, 					origemAlta, 			returnTakeSeconds);
	trajetoPrepararCaptura		= intercalar(origemAlta, 			DestinoAlto,	prepareTakeSeconds);
	trajetoAtaque 				= intercalar(DestinoAlto,	destino, 			attackSeconds);
	trajetoVoltarAtaque	= intercalar(destino, 			DestinoAlto, 	returnAttackSeconds);
	trajetoVoltarInicial = intercalar(DestinoAlto, 	posicaoInicial, 	returnInitialSeconds);

	const bool GARRA_ABERTA = true;
	const bool GARRA_FECHADA = !GARRA_ABERTA;

	executarTrajeto(trajetoPrepararCaptura,		prepareTakeSeconds * FREQUENCIA,		GARRA_ABERTA);
	executarTrajeto(trajetoCaptura, 					takeSeconds * FREQUENCIA,					GARRA_ABERTA);
	executarTrajeto(trajetoVoltarCaptura, 		returnTakeSeconds * FREQUENCIA,		GARRA_FECHADA);
	executarTrajeto(trajetoPrepararAtaque,	prepareAttackSeconds * FREQUENCIA,	GARRA_FECHADA);
	executarTrajeto(trajetoAtaque, 				attackSeconds * FREQUENCIA, 				GARRA_FECHADA);
	executarTrajeto(trajetoVoltarAtaque, 	returnAttackSeconds * FREQUENCIA, 	GARRA_ABERTA);
	executarTrajeto(trajetoVoltarInicial, 	returnInitialSeconds * FREQUENCIA,	GARRA_ABERTA);
}

void executarTrajeto(Coordenada *trajeto, int tamanho, bool garra){
	float  base,  ombro,  cotovelo,  pulso;
	for(int i = 0; i < tamanho; i++){
		base = anguloBase(trajeto[i]);
		ombro = anguloOmbro(trajeto[i]);
		cotovelo = anguloCotovelo(trajeto[i]);
		pulso = anguloPulso(trajeto[i]);
		executarAngulos(base, ombro, cotovelo, pulso, garra);
	}
}
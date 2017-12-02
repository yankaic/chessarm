#include "chessroles.hpp"


char* toString(Mapa mapa, char* text, char ch){
	int i = 63;	
	Mapa mostSig = 0x8000000000000000;

	for(int i = 0; i < 64; i++){
		text[i] = (mapa & mostSig) != 0 ? ch : text[i];
		mapa = mapa << 1;
	}
	return text;
}

char* emptyString(){
	char* text = new char[65];
	text[64] = '\0';
	for(int i = 0; i < 64; i++)
		text[i] = '0';
	return text;
}

char* toString(Mapa mapa){	
	return toString(mapa,emptyString(),'1');
}

Mapa mapear(int fileira, int coluna){
	Casa casa;
	casa.fileira = fileira;
	casa.coluna = coluna;
	return mapear(casa);
}

Mapa mapear(Casa casa){
	if(casa.fileira >= TAMANHO_TABULEIRO || casa.coluna >= TAMANHO_TABULEIRO || casa.fileira < 0 || casa.coluna < 0)
		return 0;
	int deslocamento = casa.fileira * TAMANHO_TABULEIRO + casa.coluna;
	Mapa bit = 0x1;
	return bit << deslocamento;
} 

bool contem(Mapa mapa1, Mapa mapa2){
	return (mapa1 & mapa2) != 0;
}

Casa localizacao(Mapa mapa){
	int contador = -1;
	while(mapa != 0){
		contador++;
		mapa = mapa >> 1;
	}
	Casa casa;
	casa.fileira = contador / TAMANHO_TABULEIRO;
	casa.coluna = contador % TAMANHO_TABULEIRO;
	return casa;
}

int contar(Mapa mapa){
	int contador = 0;
	Mapa bit = 0x1;
	while(mapa != 0){
		if(mapa & bit == bit)
			contador++;
		mapa =  mapa >> 1;
	}
	return contador;
}

Mapa ataquesNorte(Mapa ocupadas, Casa casa){	
	Vetor vector;
	vector.x = 0;
	vector.y = 1;
	return ataquesDirecionado(ocupadas, casa, vector);
}

Mapa ataquesNordeste(Mapa ocupadas, Casa casa){
	Vetor vector;
	vector.x = 1;
	vector.y = 1;
	return ataquesDirecionado(ocupadas, casa, vector);
}

Mapa ataquesLeste(Mapa ocupadas, Casa casa){
	Vetor vector;
	vector.x = 1;
	vector.y = 0;
	return ataquesDirecionado(ocupadas, casa, vector);
}

Mapa ataquesSudeste(Mapa ocupadas, Casa casa){
	Vetor vector;
	vector.x = 1;
	vector.y = -1;
	return ataquesDirecionado(ocupadas, casa, vector);
}

Mapa ataquesSul(Mapa ocupadas, Casa casa){
	Vetor vector;
	vector.x = 0;
	vector.y = -1;
	return ataquesDirecionado(ocupadas, casa, vector);
}

Mapa ataquesSudoeste(Mapa ocupadas, Casa casa){	
	Vetor vector;
	vector.x = -1;
	vector.y = -1;
	return ataquesDirecionado(ocupadas, casa, vector);
}

Mapa ataquesOeste(Mapa ocupadas, Casa casa){
	Vetor vector;
	vector.x = -1;
	vector.y = 0;
	return ataquesDirecionado(ocupadas, casa, vector);
}

Mapa ataquesNoroeste(Mapa ocupadas, Casa casa){
	Vetor vector;
	vector.x = -1;
	vector.y = 1;
	return ataquesDirecionado(ocupadas, casa, vector);
}

Mapa ataquesDirecionado	(Mapa ocupadas, Casa casa, Vetor vector){
	int escala = 1;
	Mapa proximoAtaque, ataques = 0;

	do{
		proximoAtaque = mapear(casa.fileira + vector.y * escala, casa.coluna + vector.x * escala);
		ataques |= proximoAtaque;
		escala++;
	}while((proximoAtaque & ocupadas) != proximoAtaque); //continua enquanto não encontrar obstaculo ou não sair do tabuleiro

	return ataques;	
}

Mapa ataquesPeao	(Mapa ocupadas, Casa casa, bool isWhite){
	int yGap = isWhite ? 1 : -1;
	Mapa ataques = mapear(casa.fileira + yGap, casa.coluna -1);
	ataques |= mapear(casa.fileira + yGap, casa.coluna +1);
	return ataques;
}

Mapa ataquesTorre(Mapa ocupadas, Casa casa){
	Mapa ataques = ataquesNorte(ocupadas, casa);
	ataques |= ataquesLeste(ocupadas, casa);
	ataques |= ataquesSul(ocupadas, casa);
	ataques |= ataquesOeste(ocupadas, casa);
	return ataques;
}

Mapa ataquesBispo(Mapa ocupadas, Casa casa){
	Mapa ataques = ataquesNordeste(ocupadas, casa);
	ataques |= ataquesSudeste(ocupadas, casa);
	ataques |= ataquesSudoeste(ocupadas, casa);
	ataques |= ataquesNoroeste(ocupadas, casa);
	return ataques;
}

Mapa ataquesCavalo(Mapa ocupadas, Casa casa){
	Vetor vect;
	Mapa ataques = 0, proximoAtaque;
	for(vect.x = -2; vect.x <= 2; vect.x++){
		for(vect.y = -2; vect.y <= 2; vect.y++){
			if(std::abs(vect.x) + std::abs(vect.y) == 3){
				proximoAtaque = mapear(casa.fileira + vect.y, casa.coluna + vect.x);
				ataques |= proximoAtaque;
			}
		}
	}
	return ataques;
}

Mapa ataquesRainha(Mapa ocupadas, Casa casa){
	Mapa ataques = ataquesTorre(ocupadas, casa);
	ataques |= ataquesBispo(ocupadas, casa);
	return ataques;
}

Mapa ataquesRei(Mapa ocupadas, Casa casa){
	Vetor vect;
	Mapa ataques = 0, proximoAtaque;
	for(vect.x = -1; vect.x < 2; vect.x++){
		for(vect.y = -1; vect.y < 2; vect.y++){
			proximoAtaque = mapear(casa.fileira + vect.y, casa.coluna + vect.x);
			ataques |= proximoAtaque;
		}
	}
	 Mapa casaRei = mapear(casa);
	 ataques -= casaRei;
	return ataques;
}
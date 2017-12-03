#include<iostream>

#ifndef BOARDLIB
#define BOARDLIB
#include "board.cpp"
#endif

#ifndef RECOGNIZERLIB
#define RECOGNIZERLIB
#include "recognizer.cpp"
#endif


#include "movecontrol.cpp"
#include "visao.cpp"

void printMap(char* text){	
	//std::cout << "linear: " << text << std::endl;
	for(int fileira = 0; fileira < TAMANHO_TABULEIRO; fileira++){
		for(int coluna = TAMANHO_TABULEIRO - 1; coluna >= 0; coluna--){
			char ch = text[fileira * TAMANHO_TABULEIRO + coluna];
			if(ch == '1')
				std::cout << " *";
			else if (ch == '0')				
				std::cout << " ·";
			else						
				std::cout << ' ' << ch;
		}		
		std::cout << std::endl;
	}
}

void testCount(){
	std::cout << "contador: " << contar(0) << std::endl;
}

void testLocation(){
	Casa sq = localizacao(mapear(9,7));
	std::cout << "fileira: " << sq.fileira << " coluna: " << sq.coluna << std::endl;
}

void testBitmap(){
	printMap(toString(~mapear(7,7)));
}

void testMap(){
	printMap(toString(casasOcupadas));
}

void northTest(){
	printMap(toString(ataquesNoroeste(0, localizacao(mapear(3,6)))));
}

void piecesTest(){
	printMap(toString(ataquesBispo(0, localizacao(mapear(3,3)))));
}

void pawnAttackTest(){
	printMap(toString(ataquesPeao(0, localizacao(mapear(1,6)),true)));
}

void boardPrintTest(){
	printMap(boardString());
}

void movementTest(){
	Movimento movimento;
	movimento.origem = localizacao(mapear(1,1));
	movimento.destino = localizacao(mapear(2,1));
	registrarMovimento(movimento);

	std::cout << std::endl << "Todas as peças: " << std::endl;
	printMap(boardString());
	std::cout << std::endl << "Peões: " << std::endl;
	printMap(toString(pecas[PEAO]));	
	std::cout << std::endl << "Peças brancas: " << std::endl;
	printMap(toString(pecas[BRANCO]));	
	std::cout << std::endl << "Peças pretas: " << std::endl;
	printMap(toString(pecas[PRETO]));
}

void testPointer(){
	printMap(toString(pecas[TORRE]));
}

void recognizeTest(){
	Movimento movimento;
	movimento.origem = localizacao(mapear(6,1));
	movimento.destino = localizacao(mapear(5,1));
	registrarMovimento(movimento);
	movimento.origem = localizacao(mapear(0,3));
	movimento.destino = localizacao(mapear(3,4));
	registrarMovimento(movimento);
	printMap(boardString());

	Mapa ataques = ataquesDisponiveis(movimento.destino);
	printMap(toString(ataques));
}

void recognTest(){
	Mapa novaOcupacao = 0xFFFF00000001FEFF;
	Mapa modificacoes = casasOcupadas ^ novaOcupacao;
	Mapa mapaOrigem = modificacoes & casasOcupadas;
	Mapa destinationmap = modificacoes ^ mapaOrigem;

	printMap(toString(casasOcupadas));
	printMap(toString(novaOcupacao));
	printMap(toString(modificacoes));
	printMap(toString(mapaOrigem));
	printMap(toString(destinationmap));
}

void kinematicsTest(){
	using namespace std;
	Coordenada posicao;
	posicao.x = 14;
	posicao.y = 60;
	posicao.z = 16;

	dimensoesSuportadas(posicao);
	cout << "x=" << posicao.x << " y=" << posicao.y << " z=" << posicao.z << endl;
	cout << "base: " << anguloBase(posicao) << endl;
	cout << "ombro: " << anguloOmbro(posicao) << endl;
	cout << "cotovelo: " << anguloCotovelo(posicao) << endl;
	cout << "pulso: " << anguloPulso(posicao) << endl;
}

void moveTest(){
	Casa casa;
	casa.fileira = 0;
	casa.coluna = 4;
	Coordenada posicao = localizar(casa, true);
	using namespace std;
	cout << "x=" << posicao.x << "\ty=" << posicao.y << "\tz=" << posicao.z << endl;
}

void moveArrayTest(){
	Casa origem = localizacao(mapear(0,0));
	Casa destino = localizacao(mapear(7,7));
	Coordenada from = localizar(origem, true);
	Coordenada to = localizar(destino, true);
	Coordenada *points = intercalar(from, to,2.0);

	using namespace std;
	for(int i = 0; i < 60; i++){
		Coordenada posicao = points[i];
		cout << "x=" << posicao.x << " y=" << posicao.y << " z=" << posicao.z << endl;
	}
}

void pointTest(){
	Coordenada point1, point2;
	point1.x= 5;
	point1.y = 5;
	point1.z = 5;

	point2 = point1;
	point2.x = 10;

	using namespace std;
	cout << "x=" << point1.x << " y=" << point1.y << " z=" << point1.z << endl;
	cout << "x=" << point2.x << " y=" << point2.y << " z=" << point2.z << endl;
}

int variable = 4;
void contextTest(){
	int variable = 5;
	using namespace std;
}

void imagemTest(){
	Mapa mapa = carregarImagem();
	printMap(toString(mapa));
}
int main(){
	imagemTest();
}

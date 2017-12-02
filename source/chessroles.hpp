typedef unsigned long Mapa;
#define TAMANHO_TABULEIRO 8 

#include <cmath>

struct Casa{
	int fileira;
	int coluna;
};

struct Vetor{
	int x;
	int y;
};

Mapa 		mapear(int fileira, int coluna); //ok
Mapa 		mapear(Casa casa);   //ok
Casa 	localizacao(Mapa mapa); //ok
char* 	toString(Mapa mapa, char* text, char ch);
char*		toString(Mapa mapa);   //ok
char* 	emptyString();
int 		contar(Mapa mapa);   //ok
bool 		contem(Mapa mapa1, Mapa mapa2);

Mapa ataquesNorte		(Mapa ocupadas, Casa casa);
Mapa ataquesNordeste(Mapa ocupadas, Casa casa);
Mapa ataquesLeste			(Mapa ocupadas, Casa casa);
Mapa ataquesSudeste(Mapa ocupadas, Casa casa); 
Mapa ataquesSul		(Mapa ocupadas, Casa casa);
Mapa ataquesSudoeste(Mapa ocupadas, Casa casa);
Mapa ataquesOeste			(Mapa ocupadas, Casa casa);
Mapa ataquesNoroeste(Mapa ocupadas, Casa casa);
Mapa ataquesDirecionado	(Mapa ocupadas, Casa casa, Vetor direction);

Mapa ataquesPeao			(Mapa ocupadas, Casa casa, bool isWhite);
Mapa ataquesTorre    	(Mapa ocupadas, Casa casa);
Mapa ataquesBispo  	(Mapa ocupadas, Casa casa); 
Mapa ataquesCavalo		(Mapa ocupadas, Casa casa); 
Mapa ataquesRainha   	(Mapa ocupadas, Casa casa);
Mapa ataquesRei   	(Mapa ocupadas, Casa casa);

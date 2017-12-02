
const float ALTURA_BASE = 18.0;
const float COMPRIMENTO_BRACO = 23.0;
const float COMPRIMENTO_ANTEBRACO = 23.25;
const float COMPRIMENTO_MAO = 15;

const float GARRA_ABERTA = 90;
const float GARRA_FECHADA = 90;

float BASE_ANTERIOR = 90;
float OMBRO_ANTERIOR = 90;
float COTOVELO_ANTERIOR = 90;
float PULSO_ANTERIOR = 90;
float GARRA_ANTERIOR = GARRA_ABERTA;

float base = BASE_ANTERIOR;
float ombro = OMBRO_ANTERIOR;
float cotovelo = COTOVELO_ANTERIOR;
float pulso = PULSO_ANTERIOR;
float garra = GARRA_ANTERIOR;

#ifndef POINT3D 
#define POINT3D 
struct P3D{
	double x;
	double y;
	double z;
};
typedef struct P3D Coordenada;
#endif

bool dimensoesSuportadas(Coordenada coordenada);

float anguloBase(Coordenada coordenada);

float anguloOmbro(Coordenada coordenada);

float anguloCotovelo(Coordenada coordenada);

float anguloPulso(Coordenada coordenada);

void executarAngulos(float base, float ombro, float cotovelo, float pulso, bool garra);
#include "kinematics.hpp"

bool dimensoesSuportadas (Coordenada posicao) {	  
	float modulo = sqrt(pow(posicao.x, 2) + pow(posicao.y,2));
	base = acos(posicao.x / modulo) * 180 / M_PI;

	float y = modulo; //front lenght	
	float alturaGarra = posicao.z + COMPRIMENTO_MAO;	
	float distancia = sqrt(pow(y, 2) + pow(alturaGarra - ALTURA_BASE, 2));	
	float distanciaBasePulso = sqrt(pow(alturaGarra, 2) + pow(y, 2)); //distancia base pulso.
	
	float complement1 = 
		acos(( -pow(COMPRIMENTO_ANTEBRACO,2) + pow(distancia, 2) + pow(COMPRIMENTO_BRACO, 2)) / (2 * distancia * COMPRIMENTO_BRACO));
	float complement2 = 
		acos((-pow(distanciaBasePulso, 2) + pow(distancia, 2) + pow(ALTURA_BASE, 2)) / (2 * distancia * ALTURA_BASE));
	
	ombro = (complement1 + complement2) * 180 / M_PI -90;
	
	float realHigh = posicao.z - (ALTURA_BASE - COMPRIMENTO_MAO);
	
	cotovelo = acos(
		(pow(COMPRIMENTO_BRACO, 2) + pow(COMPRIMENTO_ANTEBRACO, 2) - (pow(y,2) + pow(realHigh, 2)))
		/ (2 * COMPRIMENTO_BRACO * COMPRIMENTO_ANTEBRACO) ) * 180 / M_PI;
	pulso = 270 - ombro - cotovelo;
	
	return !(isnan(ombro) || isnan(cotovelo) || isnan(pulso) || isnan(base));
}

float anguloBase(Coordenada coordenada){
	if (dimensoesSuportadas(coordenada)) return BASE_ANTERIOR = base;
	else return base = BASE_ANTERIOR;
}

float anguloOmbro(Coordenada coordenada){
	if (dimensoesSuportadas(coordenada)) return OMBRO_ANTERIOR = ombro;
	else return ombro = OMBRO_ANTERIOR;
}

float anguloCotovelo(Coordenada coordenada){
	if (dimensoesSuportadas(coordenada)) return COTOVELO_ANTERIOR = cotovelo;
	else return cotovelo = COTOVELO_ANTERIOR;
}

float anguloPulso(Coordenada coordenada){
	if (dimensoesSuportadas(coordenada)) return PULSO_ANTERIOR = pulso;
	else return pulso = PULSO_ANTERIOR;
}

void executarAngulos(float base, float ombro, float cotovelo, float pulso, bool garra){

}
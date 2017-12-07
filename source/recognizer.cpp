Movimento descobrirMovimento(Mapa novaOcupacao){
	Mapa modificacoes = casasOcupadas ^ novaOcupacao;
	Mapa origem = modificacoes & casasOcupadas;
	Mapa destino;
	if(contar(modificacoes) == 2){
		destino = modificacoes & ~casasOcupadas;
	}
	else{		
		int cor = corPeca(origem);
		int oponente = 1 - cor;
		destino = ataquesDisponiveis(origem) & pecas[oponente];
	}

	Movimento movimento;
	movimento.origem = localizacao(origem);
	movimento.destino = localizacao(destino);
	return movimento;
}

Mapa ataquesDisponiveis(Casa origem){
	int tipo = tipoPeca(origem);
	int cor = corPeca(origem);
	int oponente = 1 - cor;

	Mapa ataques;
	switch(tipo){
		case PEAO:
			ataques = ataquesPeao(casasOcupadas, origem, cor == BRANCO);
			break;

		case TORRE:
			ataques = ataquesTorre(casasOcupadas, origem);
			break;

		case CAVALO:
			ataques = ataquesCavalo(casasOcupadas, origem);
			break;

		case BISPO:
			ataques = ataquesBispo(casasOcupadas, origem);
			break;

		case RAINHA:
			ataques = ataquesRainha(casasOcupadas, origem);
			break;

		case REI:
			ataques = ataquesRei(casasOcupadas, origem);
			break;

		default:
			ataques = 0;
	}
	return ataques & pecas[oponente];	//ataca apenas pecas do oponente
}
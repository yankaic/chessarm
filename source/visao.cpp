#ifndef OPENCVLIB
#define OPENCVLIB
#include <opencv2/opencv.hpp>
#include "opencv/highgui.h"
#include <sstream>
#include <iostream>
#include <dirent.h>
#endif


#include <string>

using namespace cv;
Mat enquadrarImagem(Mat imagem);
Mat dividirImagem(Mat imagem, int quantidade, int fileira, int coluna);
Vec3b corGeral(Mat imagem);
void carregarAmostras();
float distancia(Vec3b cor1, Vec3b cor2);
void printVetor(Vec3i cor);
void salvaCor(Mat imagem, const char* diretorio);
Mat imagemCor(Mat imagem);

const int BLUE = 0;
const int GREEN = 1;
const int RED = 2;

Vec3b corPecaClara;
Vec3b corPecaEscura;
Vec3b corCasaClara;
Vec3b corCasaEscura;

Mat pecaClara, pecaEscura, casaClara, casaEscura, aproximacao;

Mapa carregarImagem(){
	carregarAmostras();
	Mat imagem;
	imagem = imread("./resource/tabuleiro.jpg");
	imagem = enquadrarImagem(imagem);
	Mat casa, centro, tabuleiroCores, corquadrado, corAproximacao = casaEscura;
	Vec3b cor;
	Mapa mapa = 0;
	int dpc, dpe, dcc, dce;
	char dir[] = "./resource/pecas/pfc.jpg";
	resize(imagem, tabuleiroCores, Size(800, 800), 0, 0);
	resize(aproximacao, aproximacao, Size(800, 800), 0, 0);
	Rect quadrado;
	quadrado.width = 100;
	quadrado.height = 100;

	for(int fileira = 0; fileira < 8; fileira ++){
		for (int coluna = 0; coluna < 8; coluna++){
			casa = dividirImagem(imagem, 8, fileira, coluna);
			centro = dividirImagem(casa, 3, 1,1);
			cor = corGeral(centro);

			dpc = distancia(cor, corPecaClara);
			dpe = distancia(cor, corPecaEscura);
			dcc = distancia(cor, corCasaClara);
			dce = distancia(cor, corCasaEscura);
			int menor = min(min(min(dpc, dpe),dcc),dce);


	 		if(menor==dcc){
		 		corAproximacao = casaClara;
	 		}
	 		else if(menor==dce){
		 		corAproximacao = casaEscura;
	 		}
	 		else if(menor==dpc){
		 		mapa |= mapear(fileira, coluna);
		 		corAproximacao = pecaClara;
	 		}
	 		else if(menor==dpe){
		 		mapa |= mapear(fileira, coluna);
		 		corAproximacao = pecaEscura;
	 		}

	 		//salvando resultados
	 		dir[17] = 'a';
			dir[18] = '0'+7-fileira;
			dir[19] = '0'+coluna;
			imwrite(dir, casa);
			dir[17] = 'b';
			imwrite(dir, centro);

			corquadrado = imagemCor(centro);
			quadrado.x = coluna * 100;
			quadrado.y = (7- fileira) * 100;
			corquadrado.copyTo(tabuleiroCores(quadrado));
			corAproximacao.copyTo(aproximacao(quadrado));
		}
	}
	imwrite("./resource/tabuleiroCores.jpg",tabuleiroCores);
	imwrite("./resource/tabuleiroCoresAp.jpg",aproximacao);
	return mapa;
}

void treinar(){
	DIR *dir;
	struct dirent *lsdir;
	dir = opendir("./resource/treino");	
	const unsigned char isFile =0x8;

	int countCC, countCE, countPC, countPE;
	countPE = countPC = countCE = countCC = 0;
	Vec3i mediaCC, mediaCE, mediaPC, mediaPE;
	Mat amostra;


	while((lsdir = readdir(dir)) != NULL){
		if(strcmp(lsdir->d_name, ".")!=0 && strcmp(lsdir->d_name, "..")
		 &&  lsdir->d_type == isFile){
			std::string filename = "./resource/treino/";
			filename += lsdir->d_name;
    	amostra = imread(filename.c_str());
    	amostra = dividirImagem(amostra, 3, 1, 1);
    	Vec3b corint = corGeral(amostra);

    	if(lsdir->d_name[0]=='p' && lsdir->d_name[1]=='c'){
    		mediaPC += corint;
    		countPC++;
    	}
    	if(lsdir->d_name[0]=='p' && lsdir->d_name[1]=='e'){
    		mediaPE += corint;
    		countPE++;
    	}
    	if(lsdir->d_name[0]=='c' && lsdir->d_name[1]=='c'){
    		mediaCC += corint;
    		countCC++;
    	}
    	if(lsdir->d_name[0]=='c' && lsdir->d_name[1]=='e'){
    		mediaCE += corint;
    		countCE++;
    	}
		}
	}
	mediaCE /= countCE;
	mediaCC /= countCC;
	mediaPE /= countPE;
	mediaPC /= countPC;
	Mat imgReduzida;
	resize(amostra, imgReduzida, Size(1, 1), 0, 0);	

	imgReduzida.at<Vec3b>(0,0) = mediaCC;
	resize(imgReduzida, amostra, Size(100, 100), 0, 0);
	imwrite("./resource/casaClara.jpg",amostra);

	imgReduzida.at<Vec3b>(0,0) = mediaCE;
	resize(imgReduzida, amostra, Size(100, 100), 0, 0);
	imwrite("./resource/casaEscura.jpg",amostra);

	imgReduzida.at<Vec3b>(0,0) = mediaPC;
	resize(imgReduzida, amostra, Size(100, 100), 0, 0);
	imwrite("./resource/pecaClara.jpg",amostra);

	imgReduzida.at<Vec3b>(0,0) = mediaPE;
	resize(imgReduzida, amostra, Size(100, 100), 0, 0);
	imwrite("./resource/pecaEscura.jpg",amostra);
}

void printVetor(Vec3i cor){
	std::cout << " r= " << cor.val[RED];
	std::cout << " g= " << cor.val[GREEN];
	std::cout << " b= " << cor.val[BLUE] << std::endl;
}

void carregarAmostras(){
	Mat imagem;
	imagem = imread("./resource/pecaClara.jpg");
	corPecaClara = corGeral(imagem);
	pecaClara = imagemCor(imagem);

	imagem = imread("./resource/pecaEscura.jpg");
	corPecaEscura = corGeral(imagem);
	pecaEscura = imagemCor(imagem);

	imagem = imread("./resource/casaClara.jpg");
	corCasaClara = corGeral(imagem);
	casaClara = imagemCor(imagem);

	imagem = imread("./resource/casaEscura.jpg");
	corCasaEscura = corGeral(imagem);	
	casaEscura = imagemCor(imagem);

	aproximacao = imagemCor(imagem);
}

float distancia(Vec3b cor1, Vec3b cor2){
	float distancia = pow(cor2.val[RED] - cor1.val[RED], 2);
	distancia += pow(cor2.val[GREEN] - cor1.val[GREEN], 2);
	distancia += pow(cor2.val[BLUE] - cor1.val[BLUE], 2);
	return sqrt(distancia);
}

Mat enquadrarImagem(Mat imagem){
	Rect cropper;
  cropper.width = imagem.size().width;
  cropper.height = imagem.size().height;

  cropper.x = cropper.width - cropper.height ;
  cropper.x = max(cropper.x / 2, 0);
  cropper.y = cropper.height - cropper.width;
  cropper.y = max(cropper.y / 2, 0);

  cropper.width = min(imagem.size().width, imagem.size().height);
  cropper.height = min(imagem.size().width, imagem.size().height);
  return imagem(cropper);
}

Mat dividirImagem(Mat imagem, int quantidade, int fileira, int coluna){
	Rect cropper;
	fileira = quantidade - 1 - fileira;
	cropper.width = imagem.size().width / quantidade;
	cropper.height = imagem.size().height / quantidade;
	cropper.x = coluna * cropper.width;
	cropper.y = fileira * cropper.height;
	return imagem(cropper);
}

Vec3b corGeral(Mat imagem){
	Mat imgReduzida;
	resize(imagem, imgReduzida, Size(1, 1), 0, 0);
	return imgReduzida.at<Vec3b>(0, 0);
}

void salvaCor(Mat imagem,const char* diretorio){
	Mat imgReduzida;
	resize(imagem, imgReduzida, Size(1, 1), 0, 0);	
	resize(imgReduzida, imagem, Size(100, 100), 0, 0);
	imwrite(diretorio, imagem);
}

Mat imagemCor(Mat imagem){
	Mat imgReduzida;
	resize(imagem, imgReduzida, Size(1, 1), 0, 0);	
	resize(imgReduzida, imagem, Size(100, 100), 0, 0);
	return imagem;
}


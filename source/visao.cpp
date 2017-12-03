#ifndef OPENCVLIB
#define OPENCVLIB
#include <opencv2/opencv.hpp>
#include "opencv/highgui.h"
#endif

using namespace cv;
Mat enquadrarImagem(Mat imagem);
Mat dividirImagem(Mat imagem, int quantidade, int fileira, int coluna);
Vec3b corGeral(Mat imagem);
void carregarAmostras();
float distancia(Vec3b cor1, Vec3b cor2);
void printVetor(Vec3b cor);
void salvaCor(Mat imagem, const char* diretorio);

const int BLUE = 0;
const int GREEN = 1;
const int RED = 2;

Vec3b pecaClara;
Vec3b pecaEscura;
Vec3b casaClara;
Vec3b casaEscura;

Mapa carregarImagem(){
	carregarAmostras();
	Mat imagem;
	imagem = imread("./resource/input/tabuleiro.jpg");
	imagem = enquadrarImagem(imagem);
	Mat casa, centro;
	Vec3b cor;
	Mapa mapa = 0;
	float dpc, dpe, dcc, dce;
	char dir[] = "./resource/input/pecas/pfc.jpg";

	for(int fileira = 0; fileira < 8; fileira ++){
		for (int coluna = 0; coluna < 8; coluna++){
			casa = dividirImagem(imagem, 8, fileira, coluna);
			centro = dividirImagem(casa, 3, 1,1);
			cor = corGeral(centro);

			dpc = distancia(cor, pecaClara);
			dpe = distancia(cor, pecaEscura);
			dcc = distancia(cor, casaClara);
			dce = distancia(cor, casaEscura);
			float menor = min(min(min(dpc, dpe),dcc),dce);
			if(menor==dpc || menor==dpe){
			 	mapa |= mapear(fileira, coluna);
	 		}

	 		//salvando resultados
	 		dir[23] = 'p';
			dir[24] = '0'+7-fileira;
			dir[25] = '0'+coluna;
			imwrite(dir, casa);
			dir[23] = 'c';
			imwrite(dir, centro);
		}
	}
	return mapa;
}

void nada(){
	// 	using namespace std;
	// cout << "dpc= " << dpc << endl;
	// cout << "dpe= " << dpe << endl;
	// cout << "dcc= " << dcc << endl;
	// cout << "dce= " << dce << endl;

	// if(menor==dpc){
	// 	cout << "Peca clara" << endl;
	// }
	// if(menor==dpe){
	// 	cout << "Peca escura" << endl;
	// }
	// if(menor==dcc){
	// 	cout << "Casa clara" << endl;
	// }
	// if(menor==dce){
	// 	cout << "Casa escura" << endl;
	// }
}



void printVetor(Vec3b cor){
	std::cout << " r= " << cor.val[RED];
	std::cout << " g= " << cor.val[GREEN];
	std::cout << " b= " << cor.val[BLUE] << std::endl;
}

void carregarAmostras(){
	Mat imagem;
	imagem = imread("./resource/input/amostraPecaClara.jpg");
	imagem = dividirImagem(imagem, 3, 1,1);
	pecaClara = corGeral(imagem);
	salvaCor(imagem, "./resource/input/corPecaClara.jpg");

	imagem = imread("./resource/input/amostraPecaEscura.jpg");
	imagem = dividirImagem(imagem, 3, 1,1);
	pecaEscura = corGeral(imagem);
	salvaCor(imagem, "./resource/input/corPecaEscura.jpg");

	imagem = imread("./resource/input/amostraCasaClara.jpg");
	imagem = dividirImagem(imagem, 3, 1,1);
	casaClara = corGeral(imagem);
	salvaCor(imagem, "./resource/input/corCasaClara.jpg");

	imagem = imread("./resource/input/amostraCasaEscura.jpg");
	imagem = dividirImagem(imagem, 3, 1,1);
	casaEscura = corGeral(imagem);
	salvaCor(imagem, "./resource/input/corCasaEscura.jpg");
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
	Mat pixel;
	resize(imagem, pixel, Size(1, 1), 0, 0);
	return pixel.at<Vec3b>(0, 0);
}

void salvaCor(Mat imagem,const char* diretorio){
	Mat pixel;
	resize(imagem, pixel, Size(1, 1), 0, 0);	
	resize(pixel, imagem, Size(100, 100), 0, 0);
	imwrite(diretorio, imagem);
}
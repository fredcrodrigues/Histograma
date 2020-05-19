#include<opencv2/opencv.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include <opencv2\imgproC\imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std; 

int main() {
	
	Mat Imagem ;
	vector<Mat>channels;
	// calculo de histograma em 3 canais e 1 canal.	
	//cout << " A imagem tem " << Linhas << " e " << Colunas << "Colunas" << endl;
	//Variavei de calculo para o historgrama
	int  histosize = 256;// Frequencia de reptição
	float range[] = { 0 , 255 }; //  intervalo
	const float * ranges[] = { range  }; // peag intervalo completo
	
	
	Imagem = imread("Mario2.jpg");
	split(Imagem, channels);
	Mat Histo_A ,  Histo_v , Histo_V;
	calcHist( &channels[0], 1, 0 , Mat(), Histo_A, 1, &histosize, ranges, true, false);
	calcHist( &channels[1], 1, 0, Mat(), Histo_v, 1, &histosize, ranges, true, false);
	calcHist( &channels[2], 1, 0, Mat(), Histo_V, 1, &histosize, ranges, true, false);
	
	/*double total;
	total = Imagem.rows * Imagem.cols;*/

		int hist_w = 1012; int hist_h = 500; //tamanho do desenhoo plotado
		int bin_w = cvRound((double)hist_w / histosize);
	
		Mat histImage(hist_h, hist_w, CV_8UC3/*QUANTIDADE DE CANAIS*/, Scalar(0, 0, 0)); // desenho do histograma
		normalize(Histo_A/*imagem entrada*/, Histo_A/*pegar tamanho da imagem de entrada*/, 0/*limite inferior*/, histImage.rows /*limite superior frequencia vertical*/, NORM_MINMAX, -1, Mat());
		normalize(Histo_v/*imagem entrada*/, Histo_v/*pegar tamanho da imagem de entrada*/, 0/*limite inferior*/, histImage.rows /*limite superior frequencia vertical*/, NORM_MINMAX, -1, Mat());
		normalize(Histo_V/*imagem entrada*/, Histo_V/*pegar tamanho da imagem de entrada*/, 0/*limite inferior*/, histImage.rows /*limite superior frequencia vertical*/, NORM_MINMAX, -1, Mat());
		for (int i = 1; i < histosize; i++)
		{
			line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(Histo_A.at<float>(i - 1))),
				Point(bin_w * (i), hist_h - cvRound(Histo_A.at<float>(i))),
				Scalar(255, 0, 0), 2, 8, 0);
			line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(Histo_v.at<float>(i - 1))),
				Point(bin_w * (i), hist_h - cvRound(Histo_v.at<float>(i))),
				Scalar(0, 255, 0), 2, 8, 0);
			line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(Histo_V.at<float>(i - 1))),
				Point(bin_w * (i), hist_h - cvRound(Histo_V.at<float>(i))),
				Scalar(0, 0, 255), 2, 8, 0);
		}
	
		namedWindow("Result");   
		imshow("Result", histImage);

		waitKey(0);
		return 0;

	
	
/* FORMA MANUAL

	for (int lin = 0; lin < Linhas; lin++) {
		for (int col = 0; col < Colunas; col++) {

			ValorPixel = ImagemCnza.at<uchar>(lin, col);

			if ((ValorPixel > 0 )&& (ValorPixel < 15)) {
				
			//	cout << "Total de valores que estão entre 0 a 15 é " << repetido << endl;
				//cout << "A posição que variam de 0 a 15  a posição é  " << lin << "," << col << " valor -  " << ValorPixel << endl;
				repetido++;
			}
			if ((ValorPixel > 16) && (ValorPixel < 31)) {
				
				
				
			
				rep++;
			}
			

		}

	}

	
	cout << "Total de valores que estão entre 0 a 15 é " << repetido << endl;
	cout << " -----Total de valores que estão entre 16 a 31 é  ----" << rep << endl;

	*/

			

	waitKey(0);
	return 0;

}
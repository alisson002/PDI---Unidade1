#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat image, mask, imgalt;
	int width, height;
	int nobjt, nobjs, nobjc;

	CvPoint p;
	image = imread("solucao.png", CV_LOAD_IMAGE_GRAYSCALE);
	imgalt = image;
	if (!image.data) {
		std::cout << "imagem nao carregou corretamente\n";
		return(-1);
	}
	width = image.size().width;
	height = image.size().height;

	p.x = 0;	
	p.y = 0;

	nobjt = 0;
	nobjs = 0;
	nobjc = 0;
	// Procura e preenche os objetos que estejam tocando nas bordas da imagem
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || j == 0 || i == height - 1 || j == width - 1) {
				p.x = j;
				p.y = i;
				floodFill(imgalt, p, 0);
			}
		}
	}
	//Procura os objetos restantes
	for (int i = 0; i(i, j) == 255) {
				// achou um objeto
				nobjt++;
				p.x = j;
				p.y = i;
				floodFill(imgalt, p, nobjt);
			}
		}
	}
	p.x = 0;
	p.y = 0;
	// Invertemos o fundo da imagem para determinar o número de objetos com buracos
	floodFill(image, p, 255);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (image.at<uchar>(i, j) == 0) {
				// achou um objeto
				nobjc++;
				p.x = j;
				p.y = i;
				floodFill(image, p, nobjc);
			}
		}
	}
	nobjs = nobjt - nobjc;
	cout << "No Total de Objetos " << nobjt << endl;
	cout << "No de Objetos sem Buracos " << nobjs << endl;
	cout << "No de Objetos com Burados " << nobjc << endl;
	imshow("image", image);
	imwrite("labeling.png", image);
	waitKey();
	return 0;
}
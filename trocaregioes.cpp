#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int, char**){
  Mat image, image2, p1, p2, p3, p4;
  int width, height;

  image = imread("trocaregioes.cpp",CV_LOAD_IMAGE_GRAYSCALE);
  image2 = imread("trocaregioes.cpp",CV_LOAD_IMAGE_GRAYSCALE);

  width  = image.size().width;
  height = image.size().height;

  p1 = image(Rect(0,0,(width/2),(height/2)));
  p2 = image(Rect((width/2),0,(width/2),(height/2)));
  p3 = image(Rect(0,(height/2),(width/2),(height/2)));
  p4 = image(Rect((width/2),(height/2),(width/2),(height/2)));

  imshow("Original", image);
  waitKey();

  p1.copyTo(image2(Rect((width/2),(height/2),(width/2),(height/2))));
  p2.copyTo(image2(Rect(0,(height/2),(width/2),(height/2))));
  p3.copyTo(image2(Rect((width/2),0,(width/2),(height/2))));
  p4.copyTo(image2(Rect(0,0,(width/2),(height/2))));

  imshow("Imagem trocada", image2);
  waitKey();

  return 0;
}
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//haarcascade_frontalcatface   haarcascade_frontalcatface_extended
String fileName = "F:/opencv/OpenCV3.2/opencv/build/etc/haarcascades/haarcascade_frontalcatface.xml";
CascadeClassifier face_classifier;

/** 从图片猫脸检测 */
int main(int argc, char** argv) {
	if (!face_classifier.load(fileName)) {
		printf("could not load face feature data...\n");
		return -1;
	}

	Mat src = imread("F:/opencv/myimg/cat_dog_1.jpg");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	imshow("input image", src);

	Mat gray;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	equalizeHist(gray, gray);

	vector<Rect> cats;
	//一只猫
	//face_classifier.detectMultiScale(gray, cats, 1.1, 3, 0, Size(48, 48));//3的调整会影响检测效果，最小为48*48
	//猫和狗
	face_classifier.detectMultiScale(gray, cats, 1.4, 0, 0, Size(48, 48));
	for (size_t t = 0; t < cats.size(); t++) {
		rectangle(src, cats[static_cast<int>(t)], Scalar(0, 0, 255), 2, 8, 0);
	}

	namedWindow("Cat Face Detector Demo", CV_WINDOW_AUTOSIZE);
	imshow("Cat Face Detector Demo", src);
	waitKey(0);
	return 0;
}
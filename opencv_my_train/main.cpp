#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

String fileName = "F:/opencv/mytrain/face_train/cascade.xml";
CascadeClassifier face_classifier;

int main(int argc, char** argv) {
	if (!face_classifier.load(fileName)) {
		printf("could not load face feature data...\n");
		return -1;
	}

	Mat src = imread("F:/opencv/myimg/test.png");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	imshow("input image", src);
	Mat gray;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	equalizeHist(gray, gray);

	vector<Rect> faces;
	face_classifier.detectMultiScale(gray, faces, 1.3, 0, 0, Size(60, 60));
	for (size_t t = 0; t < faces.size(); t++) {
		rectangle(src, faces[static_cast<int>(t)], Scalar(0, 0, 255), 2, 8, 0);
	}

	imshow("detect faces", src);
	waitKey(0);
	return 0;
}
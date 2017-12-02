#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

CascadeClassifier face_cascader;
String haarfile = "F:/opencv/OpenCV3.2/opencv/build/etc/haarcascades/haarcascade_frontalface_alt.xml";
String lbpfile = "F:/opencv/OpenCV3.2/opencv/build/etc/lbpcascades/lbpcascade_frontalface.xml";

/** HAAR 和 LBP视频人脸检测对比 */
int main(int argc, char** argv) {
	if (!face_cascader.load(lbpfile)) {
		printf("could not load face feature data...\n");
	}
	namedWindow("haar_lbp", CV_WINDOW_AUTOSIZE);
	VideoCapture capture;
	Mat frame;
	Mat gray;
	vector<Rect> faces;
	capture.open("F:/opencv/myimg/IvankaTrump.mp4");

	while (capture.read(frame)) {
		cvtColor(frame, gray, COLOR_BGR2GRAY);
		equalizeHist(gray, gray);
		face_cascader.detectMultiScale(gray, faces, 1.2, 3, 0, Size(30, 30));
		for (size_t t = 0; t < faces.size(); t++) {
			rectangle(frame, faces[t], Scalar(255, 0, 0), 2, 8, 0);
		}
		imshow("haar_lbp", frame);
		char c = waitKey(50);
		if (c == 27) { // ESC
			break;
		}
	}

	capture.release();
	waitKey(0);
	return 0;
}
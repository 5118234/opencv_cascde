#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

CascadeClassifier face_cascader;
String haarfile = "F:/opencv/OpenCV3.2/opencv/build/etc/haarcascades/haarcascade_frontalface_alt.xml";
String lbpfile = "F:/opencv/OpenCV3.2/opencv/build/etc/lbpcascades/lbpcascade_frontalface.xml";

/** HAAR 和 LBP图片人脸检测对比 */
int main(int argc, char** argv) {
	if (!face_cascader.load(lbpfile)) {
		printf("could not load face feature data...\n");
	}
	namedWindow("haar_lbp", CV_WINDOW_AUTOSIZE);
	Mat src = imread("F:/opencv/myimg/test.png");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	imshow("input_image", src);

	Mat gray;
	vector<Rect> faces;
	cvtColor(src, gray, COLOR_BGR2GRAY);
	equalizeHist(gray, gray);
	int st = getTickCount();
	face_cascader.detectMultiScale(gray, faces, 1.1, 3, 0, Size(30, 30));
	int et = (getTickCount() - st);
	printf("time consume : %d", et);

	for (size_t t = 0; t < faces.size(); t++) {
		rectangle(src, faces[t], Scalar(255, 0, 0), 2, 8, 0);
	}
	imshow("haar_lbp", src);

	waitKey(0);
	return 0;
}
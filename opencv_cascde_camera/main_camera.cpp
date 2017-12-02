#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

String fileName = "F:/opencv/OpenCV3.2/opencv/build/etc/haarcascades/haarcascade_frontalface_alt.xml";
String eyefile = "F:/opencv/OpenCV3.2/opencv/build/etc/haarcascades/haarcascade_eye.xml";

CascadeClassifier face_cascader;
CascadeClassifier eye_cascader;

int main(int argc, char** argv) {
	if (!face_cascader.load(fileName)) {
		printf("could not load face feature data...\n");
		return -1;
	}
	if (!eye_cascader.load(eyefile)) {
		printf("could not load eye feature data...\n");
		return -1;
	}

	namedWindow("opencv_camera", CV_WINDOW_AUTOSIZE);
	VideoCapture capture(0);//打开摄像头
	Mat frame;
	Mat gray;
	vector<Rect> faces;
	vector<Rect> eyes;
	while (capture.read(frame)) {	
		cvtColor(frame, gray, COLOR_BGR2GRAY);
		equalizeHist(gray, gray);
		face_cascader.detectMultiScale(gray, faces, 1.2, 3, 0, Size(30, 30));

		for (size_t t = 0; t < faces.size() ; t++) {
			Rect roi;
			roi.x = faces[static_cast<int>(t)].x;
			roi.y = faces[static_cast<int>(t)].y;
			roi.width = faces[static_cast<int>(t)].width;
			roi.height = faces[static_cast<int>(t)].height / 2;
			Mat faceROI = frame(roi);
			eye_cascader.detectMultiScale(faceROI, eyes, 1.2, 3, 0, Size(20, 20));
			for (size_t k = 0; k < eyes.size(); k++) {
				Rect rect;
				rect.x = faces[static_cast<int>(t)].x + eyes[k].x;
				rect.y = faces[static_cast<int>(t)].y + eyes[k].y;
				rect.width = eyes[k].width;
				rect.height = eyes[k].height;
				rectangle(frame, rect, Scalar(0, 255, 0), 2, 8, 0);
			}
			rectangle(frame, faces[static_cast<int>(t)], Scalar(0, 0, 255), 2, 8, 0);
		}

		imshow("opencv_camera", frame);
		char c = waitKey(30);
		if (c == 27) { // 按ESC退出
			break;
		}
	}

	waitKey(0);
	return 0;
}
# Opencv 级联分类器
![](/opencv_cascde/opencv_image.jpg "从图片中检查人脸")
![](/opencv_cascde_camera/opencv_camera.jpg "从相机中检查人脸和眼睛")
![](/opencv_haar_lbp_video/haar_lbp_video.jpg "从本地视频中检查人脸")
#### 猫脸检测注意调整参数，特别是多动物时。
##### face_classifier.detectMultiScale(gray, cats, 1.4, 0, 0, Size(48, 48));1.4 0 48*48
![](/opencv_cat_image/cat_image.jpg "从图片中猫脸检测")
![](/opencv_cat_image/cat_dog.jpg "从猫和狗图片检测猫脸")
#### 视频中人脸检测与跟踪
##### 使用模板检测，首先检测出眼睛存入模板，再用过模板匹配检测眼睛，进行性能优化。
#### 自己用几百张图片训练的检测结果，数据太少，检测效果不理想
![](/opencv_my_train/mystrain_step_0.jpg "step_1")
![](/opencv_my_train/mystrain_step_1.jpg "step_2")
![](/opencv_my_train/mystrain_step_2.jpg "step_3")
![](/opencv_my_train/mystrain_step_3.jpg "step_4")
![](/opencv_my_train/mystrain_step_4.jpg "自己训练数据测试结果")
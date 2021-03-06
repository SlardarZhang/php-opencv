# PHP-OPENCV - PHP extension for Opencv



[![Build Status](https://camo.githubusercontent.com/cfcaf3a99103d61f387761e5fc445d9ba0203b01/68747470733a2f2f7472617669732d63692e6f72672f6477796c2f657374612e7376673f6272616e63683d6d6173746572)]() [![Minimum PHP Version](https://img.shields.io/badge/php-%3E%3D%207.0-8892BF.svg)](https://php.net/)



## Document
- [PHP OpenCV Document](https://doc.phpopencv.org)


## Requirements

- OpenCV 4.5.0
- PHP7.4.12



## Installation

### Use OpenCV docker(commendatory)

If you don't know how to install OpenCV, you can use my OpenCV docker image(only 300M, including opencv_contrib).

```bash
docker pull hihozhou/php-opencv
```

### Compile and install php-opencv extension

## You need rename the correct config file to config.w32 firstly

```bash
git clone https://github.com/hihozhou/php-opencv.git
cd php-opencv
phpize
./configure --with-php-config=your php-config path
make
make install
```

## Configure

php.ini

```
extension="your opencv.so path"
```
## Example

### LBPH face recognition

```php
use CV\Face\LBPHFaceRecognizer;
//use ...;

$src = imread('facePic.jpg');
$gray = cvtColor($src, COLOR_BGR2GRAY);
equalizeHist($gray, $gray);
$faceRecognizer = LBPHFaceRecognizer::create();
/* ... */ //get $images and $labels for train
$faceRecognizer->train($images, $labels);//How to get $image and $labels, see the document
/* ... */ //Face detection using CascadeClassifier
$faceLabel = $faceRecognizer->predict($gray);
/* ... */ //draw face and name
```

result:

![predict](https://raw.githubusercontent.com/hihozhou/php-opencv/master/tests/face_recognizer.jpg)


### Image Processing

```php
//Obama.php
use function CV\{ imread, imshow, waitkey, namedWindow};

$im = imread('Obama.png');//load image
namedWindow('This is Obama id card',WINDOW_FULLSCREEN);//create window
imshow('This is Obama id card',$im);//show image on window

waitkey(0);

```

result:

![Obama](https://raw.githubusercontent.com/hihozhou/php-opencv/master/tests/Obama.png)

Load image by gray

```php
$gray = imread('Obama.png',IMREAD_GRAYSCALE);
//or
use  function CV\{ cvtColor};
$gray = cvtColor($im, COLOR_BGR2GRAY);

```

![Obama_gray](https://raw.githubusercontent.com/hihozhou/php-opencv/master/tests/Obama_gray.png)


You can draw something.  
e.g:  

```php
use CV\{Mat,Scalar, Point, Size};
use function CV\{ellipse, imwrite, waitKey};
use const CV\{CV_8UC3};

$windowWidth = 600;
$thickness = 2;
$lineType = 8;
$matScalar = new Scalar(0,0,0);
$mat = new Mat($windowWidth, $windowWidth, CV_8UC3, $matScalar);
$point=new Point($windowWidth/2, $windowWidth/2);
$size=new Size($windowWidth/4, $windowWidth/16);
$scalar=new Scalar(255, 129, 0);
for($i = 0; $i <= 360; $i += 45){
    ellipse($mat,$point,$size,$i,0,360,$scalar,$thickness,$lineType);
}
imwrite('./tests/ellipse.png',$mat);

```

result:

![ellipse](https://raw.githubusercontent.com/hihozhou/php-opencv/master/tests/ellipse.png)



## Features
- [x] 1.[core](http://phpopencv.org/zh-cn/docs/mat.html)
- [x] 2.[imgproc](http://phpopencv.org/zh-cn/docs/gausian_median_blur_bilateral_filter.html)
- [x] 3.highgui
- [ ] 4.contrib
- [ ] 5.features2d
- [ ] 6.flann
- [ ] 7.gpu
- [ ] 8.calib3d
- [ ] 9.legacy
- [x] 10.ml
- [ ] 11.nonfree
- [x] 12.objdetect
- [ ] 13.ocl
- [ ] 14.photo
- [ ] 15.stitching
- [ ] 16.superres
- [ ] 17.ts
- [x] 18.video
- [ ] 19.Videostab



## Contributors

This project exists thanks to all the people who contribute. [[Contribute](https://github.com/hihozhou/php-opencv/graphs/contributors)].
    
## 感谢

感谢[韩天峰](https://github.com/matyhtf)老大的指导，  
感谢[韩天峰](https://github.com/matyhtf)老大的指导，
感谢[盘古大叔](https://github.com/pangudashu)的[php7-internal](https://github.com/pangudashu/php7-internal)项目以及平常的指导，
感谢`木桶技术升级交流群`和`黑夜路人技术群`、以及`PHP内核交流`的群友对技术的帮助。

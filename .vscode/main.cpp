#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
/*
int main()
{
    Mat img=imread("man.jpg");
    imshow("image",img);
    waitKey();
    return 0;
}*/


int main(int argc, char** argv){
    cv::namedWindow("Example3", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap;
    cap.open("test.mp4");
    cout<<cap.isOpened()<<endl;
    cv::Mat img; 
    cap >> img;
    std::cout << "image read: " << (img.empty()==true) << std::endl;
    cv::Mat frame;
    for(;;){
        cap >> frame;
        if(frame.empty()) break; // Ran out of film
        cv::imshow("Example3", frame);
        if(cv::waitKey(10) >= 0) break;
    }
    return 0;
}

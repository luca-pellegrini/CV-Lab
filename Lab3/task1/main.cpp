// Lab3 Task 1
#include <iostream>
#include <string>

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "myutils.h"

using namespace std;

void mouseHandler(int, int, int, int, void*);

int main(int argc, char *argv[])
{
    cv::CommandLineParser parser(argc, argv, "{@input | Robocup.jpg | input image}");
    string about_text = "Lab3 Task1: print BGR color value of pixels where the mouse clicked\n";
    parser.about(about_text);
    parser.printMessage();
    string input_image = parser.get<string>("@input");
    if (input_image.empty())
    {
        cerr << "Error: please provide a path to an image\n";
        return 1;
    }
    cv::Mat img = cv::imread(input_image);
    if (img.data == NULL)
    {
        cerr << "Error: missing file, improper permissions, unsupported or invalid format\n";
        return 1;
    }
    print_image_details(img);
    string winname = "image";
    cv::namedWindow(winname/*, cv::WINDOW_NORMAL*/);
    cv::setMouseCallback(winname, mouseHandler, &img);
    cv::imshow(winname, img);
    cv::waitKey(0);
    return 0;
}

void mouseHandler(int event, int x, int y, int flags, void* userdata)
{
    cv::Mat img = *static_cast<cv::Mat*>(userdata);
    if (event == cv::EVENT_LBUTTONDOWN)
    {
        cv::Vec3b BGR = img.at<cv::Vec3b>(y, x);
        string str = "Pixel (" + to_string(x) + ", " + to_string(y) + "), BGR = (" + to_string(BGR[0]) + ", " + to_string(BGR[1]) + ", " + to_string(BGR[2]) + ")";
        cout << str << endl;
    }
}

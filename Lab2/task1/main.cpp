// Lab2 Task 1
#include <iostream>
#include <string>

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "../include/myutils.h"

using namespace std;


int main(int argc, char** argv)
{
    if (argc < 2)
    {
        cerr << "Error: please provide a path to an image\n";
        return 1;
    }
    cv::Mat img = cv::imread(argv[1]);
    if (img.data == NULL)
    {
        cerr << "Error: missing file, improper permissions, unsupported or invalid format\n";
        return 1;
    }
    cv::namedWindow("image", cv::WINDOW_NORMAL);
    cv::imshow("image", img);
    cv::waitKey(0);

    cv::Mat img_g(img.rows, img.cols, CV_8U);
    
    int dst_chn = 1;
    cv::cvtColor(img, img_g, cv::COLOR_BGR2GRAY, dst_chn);
    
    string filename = remove_extension_from_filename(argv[1]);
    string ext = ".png";
    filename += "_grayscale" + ext;
    
    cout << "Saving grayscale image to " << filename << endl;
    cv::imwrite(filename, img_g);
    
    return 0;
}

// Lab2 Task 2
#include <iostream>
#include <string>

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "ImageFilters.h"
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

    cv::Mat img_min_f = img.clone();
    cv::Mat img_max_f = img.clone();

    int ksize = 3;
    min_filter(img, img_min_f, ksize);
    max_filter(img, img_max_f, ksize);

//    string filename = remove_extension_from_filename(argv[1]);
//    string filename_min = filename + "_min_filter.png";
//    string filename_max = filename + "_max_filter.png";

    cv::imshow("image", img);
    cv::imshow("min filter", img_min_f);
    cv::imshow("max filter", img_max_f);
    cv::waitKey(0);
    
//    cout << "Saving grayscale image to " << filename << endl;
//    cv::imwrite(filename, img);
    
    return 0;
}

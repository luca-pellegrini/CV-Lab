// Lab2 Task 3
#include <iostream>
#include <string>

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "ImageFilters.h"
#include "myutils.h"

using namespace std;


int main(int argc, char** argv)
{
    if (argc < 2)
    {
        cerr << "Error: please provide a path to an image\n";
        return 1;
    }
    cv::Mat img = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    if (img.data == NULL)
    {
        cerr << "Error: missing file, improper permissions, unsupported or invalid format\n";
        return 1;
    }

    cout << "Loaded image: " << argv[1] << endl;
    print_image_details(img);

    cv::Mat img_median_f(img.rows, img.cols, CV_8U);
//    cv::Mat img_m(img.rows, img.cols, CV_8U);

    int ksize = 5;
    cout << "Kernel size = " << ksize << endl;
    median_filter(img, img_median_f, ksize);
//    cv::medianBlur(img, img_m, ksize);

    string filename = remove_extension_from_filename(argv[1]);
    string ext = ".png";
    string filename_median = filename + "_median_filter_k" + to_string(ksize) + ext;

    cv::namedWindow("image", cv::WINDOW_NORMAL);
    cv::imshow("image", img);
    cv::namedWindow("median filter", cv::WINDOW_NORMAL);
    cv::imshow("median filter", img_median_f);
//    cv::namedWindow("opencv median filter", cv::WINDOW_NORMAL);
//    cv::imshow("opencv median filter", img_m);
    cv::waitKey(0);

    cout << "Saving images..." << endl;
    cv::imwrite(filename_median, img_median_f);

    return 0;
}

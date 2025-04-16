// Lab2 Task 2
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

    cv::Mat img_min_f(img.rows, img.cols, CV_8U);
    cv::Mat img_max_f(img.rows, img.cols, CV_8U);

    int ksize = 5;
    cout << "Kernel size = " << ksize << endl;
    min_filter(img, img_min_f, ksize);
    max_filter(img, img_max_f, ksize);

    string filename = remove_extension_from_filename(argv[1]);
    string ext = ".png";
    string filename_min = filename + "_min_filter_k" + to_string(ksize) + ext;
    string filename_max = filename + "_max_filter_k" + to_string(ksize) + ext;

    cv::namedWindow("image", cv::WINDOW_NORMAL);
    cv::imshow("image", img);
    cv::namedWindow("min filter", cv::WINDOW_NORMAL);
    cv::imshow("min filter", img_min_f);
    cv::namedWindow("max filter", cv::WINDOW_NORMAL);
    cv::imshow("max filter", img_max_f);
    cv::waitKey(0);

    cout << "Saving images..." << endl;
    cv::imwrite(filename_min, img_min_f);
    cv::imwrite(filename_max, img_max_f);
    
    return 0;
}

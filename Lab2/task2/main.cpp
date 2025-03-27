// Lab2 Task 1
#include <iostream>
#include <string>

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "ImageFilters.h"

using namespace std;


string remove_extension_from_filename(const string& s)
{
    string::size_type ext_pos = s.rfind(".");
    string r = s.substr(0, ext_pos);
    return r;
}


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

    cv::Mat img_min_filtered = img.clone();
//    cv::Mat img_max_filtered = img.clone();

    int ksize = 3;
    min_filter(img, img_min_filtered, ksize);
//    max_filter(img, img_max_filtered, ksize);

//    string filename = remove_extension_from_filename(argv[1]);
//    string filename_min = filename + "_min_filter.png";
//    string filename_max = filename + "_max_filter.png";

    cv::imshow("image", img);
    cv::imshow("min filter", img_min_filtered);
//    cv::imshow("max filter", img_max_filtered);
    cv::waitKey(0);
    
//    cout << "Saving grayscale image to " << filename << endl;
//    cv::imwrite(filename, img);
    
    return 0;
}

// Lab2 Task 4
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

    cv::Mat img_gauss_f(img.rows, img.cols, CV_8U);
    cv::Mat img_median_f(img.rows, img.cols, CV_8U);
    cv::Mat img_g_m_f(img.rows, img.cols, CV_8U);
    cv::Mat img_m_g_f(img.rows, img.cols, CV_8U);

    int g_ksize = 5;
    int m_ksize = 5;
    // Gaussian + median filters
    cv::GaussianBlur(img, img_gauss_f, cv::Size(g_ksize, g_ksize), 0);
    median_filter(img_gauss_f, img_g_m_f, m_ksize);

    // median + Gaussian filters
    median_filter(img, img_median_f, m_ksize);
    cv::GaussianBlur(img_median_f, img_m_g_f, cv::Size(g_ksize, g_ksize), 0);

    string filename = remove_extension_from_filename(argv[1]);
    string ext = ".png";
    string filename_gauss = filename + "_gauss_k" + to_string(g_ksize) + ext;
    string filename_median = filename + "_median_k" + to_string(m_ksize) + ext;
    string filename_g_m = filename + "_gauss_k" + to_string(g_ksize) +  "+median_k" + to_string(m_ksize) + ext;
    string filename_m_g = filename +  "_median_k" + to_string(m_ksize) + "+gauss_k" + to_string(g_ksize) + ext;

    cv::namedWindow("image", cv::WINDOW_NORMAL);
    cv::imshow("image", img);
    cv::namedWindow("Gaussian filter", cv::WINDOW_NORMAL);
    cv::imshow("Gaussian filter", img_gauss_f);
    cv::namedWindow("Gaussian + median filter", cv::WINDOW_NORMAL);
    cv::imshow("Gaussian + median filter", img_g_m_f);
    cv::waitKey(0);

    cout << "Saving images..." << endl;
    cv::imwrite(filename_gauss, img_gauss_f);
    cv::imwrite(filename_median, img_median_f);
    cv::imwrite(filename_g_m, img_g_m_f);
    cv::imwrite(filename_m_g, img_m_g_f);

    return 0;
}

// Lab1 Task 6
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

int main(int argc, char *argv[])
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
    cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
//    int num_channels = img.channels();
//    cout << "Channels in the image: " << num_channels << endl;
    int rows = img.rows;
    int cols = img.cols;
    cv::Mat img_avg = img.clone();
    cv::Mat img_sobel = img.clone();
    cv::Mat img_min = img.clone();
    cv::Mat img_max = img.clone();

    /* Averaging filter */
    auto avg_k_size = cv::Size(3, 3);
    cv::Mat avg_kernel = cv::Mat(avg_k_size, CV_32F, 1./9);
    cv::filter2D(img, img_avg, -1, avg_kernel);

    /* Sobel filter */
//    vector<int> sobel_k_size = {3, 3};
//    auto sobel_k_size = cv::Size(3, 3);
//    cv::Mat sobel_kernel = cv::Mat(sobel_k_size, CV_32F);
//    sobel_kernel.at<float>(0, 0) = -1.;
//    sobel_kernel.at<float>(1, 0) = -2.;
//    sobel_kernel.at<float>(2, 0) = -1.;
//    sobel_kernel.at<float>(0, 1) = 0.;
//    sobel_kernel.at<float>(1, 1) = 0.;
//    sobel_kernel.at<float>(2, 1) = 0.;
//    sobel_kernel.at<float>(0, 2) = 1.;
//    sobel_kernel.at<float>(1, 2) = 2.;
//    sobel_kernel.at<float>(2, 2) = 1.;
//    cv::filter2D(img, img_sobel, -1, sobel_kernel);
    cv::Sobel(img, img_sobel, -1, 1, 0, 3);

    /* Max filter */
    auto k = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::dilate(img, img_max, k);

    /* Min filter */
    cv::erode(img, img_min, k);

    cv::namedWindow("Grayscale");
    cv::imshow("Grayscale", img);
    cv::imshow("3x3 avg filter", img_avg);
    cv::imshow("3x3 Sobel filter", img_sobel);
    cv::imshow("3x3 max filter", img_max);
    cv::imshow("3x3 min filter", img_min);
    cv::waitKey(0);

    return 0;
}

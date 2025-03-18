// Lab1 Task 4
#include <iostream>

#include <opencv2/highgui.hpp>


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
    int num_channels = img.channels();
    cout << "Channels in the image: " << num_channels << endl;
    if (num_channels == 3)
    {
        cv::Mat img1 = cv::Mat(img.rows, img.cols, CV_8U);
        cv::Mat img2 = cv::Mat(img.rows, img.cols, CV_8U);
        cv::Mat img3 = cv::Mat(img.rows, img.cols, CV_8U);
        for (int i = 0; i < img.rows; i++)
        {
            for (int j = 0; j < img.cols; j++)
            {
                /* Copy values of each channel to the three new images */
                img1.at<unsigned char>(i, j) = img.at<cv::Vec3b>(i, j)[0];
                img2.at<unsigned char>(i, j) = img.at<cv::Vec3b>(i, j)[1];
                img3.at<unsigned char>(i, j) = img.at<cv::Vec3b>(i, j)[2];
            }
        }
        cv::imshow("img1", img1);
        cv::imshow("img2", img2);
        cv::imshow("img3", img3);
    }
    else
    {
        cv::namedWindow("Hello World");
        cv::imshow("Hello World", img);
    }
    int k = cv::waitKey(0);
    cout << "Pressed key: " << k << endl;
    return 0;
}

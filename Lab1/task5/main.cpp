// Lab1 Task 5
#include <iostream>
#include <opencv2/highgui.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    /* Vertical and horizontal gradients */
    int rows = 256;
    int cols = 256;
    cv::Mat img1 = cv::Mat(rows, cols, CV_8UC1);
    cv::Mat img2 = cv::Mat(rows, cols, CV_8UC1);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            img1.at<unsigned char>(i, j) = i; /* Vertical gradient */
            img2.at<unsigned char>(i, j) = j; /* Horizontal gradient */
        }
    }

    /* Chessboards */
    rows = cols = 300;
    cv::Mat img3 = cv::Mat(rows, cols, CV_8UC1);
    cv::Mat img4 = cv::Mat(rows, cols, CV_8UC1);

    int side3 = 20;
    int side4 = 50;
    int r, c;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            r = (i/side3) % 2;
            c = (j/side3) % 2;
            if ((r+c) % 2 == 0)
            {
                img3.at<unsigned char>(i, j) = 0;
            }
            else
            {
                img3.at<unsigned char>(i, j) = 255;
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            r = (i/side4) % 2;
            c = (j/side4) % 2;
            if ((r+c) % 2 == 0)
            {
                img4.at<unsigned char>(i, j) = 0;
            }
            else
            {
                img4.at<unsigned char>(i, j) = 255;
            }
        }
    }


    cv::imshow("Vertical gradient", img1);
    cv::imshow("Horizontal gradient", img2);
    cv::imshow("Chessboard 20px", img3);
    cv::imshow("Chessboard 50px", img4);
    cv::waitKey(0);

    return 0;
}

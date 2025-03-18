// Lab1 Task 3
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
        cv::Mat img1 = img.clone();
//        cv::Mat img2 = img.clone();
//        cv::Mat img3 = img.clone();
        for (int i = 0; i < img.rows; i++)
        {
            for (int j = 0; j < img.cols; j++)
            {
                /* set to 0 the first channel */
                img1.at<cv::Vec3b>(i, j)[0] = 0;
//                img2.at<cv::Vec3b>(i, j)[1] = 0;
//                img3.at<cv::Vec3b>(i, j)[2] = 0;
            }
        }
        cv::imshow("img1", img1);
//        cv::imshow("img2", img2);
//        cv::imshow("img3", img3);
    }

    int k = cv::waitKey(0);
    cout << "Pressed key: " << k << endl;
    return 0;
}

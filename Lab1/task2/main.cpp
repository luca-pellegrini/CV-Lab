// Lab1 Task 2
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
    cv::namedWindow("Hello World");
    cv::imshow("Hello World", img);
    int k = cv::waitKey(0);
    cout << "Pressed key: " << k << endl;
    return 0;
}

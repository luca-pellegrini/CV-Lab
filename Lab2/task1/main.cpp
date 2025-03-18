// Lab2 Task 1
#include <iostream>
#include <string>

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


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
    cv::namedWindow("image");
    cv::imshow("image", img);
    cv::waitKey(0);
    
    cv::cvtColor(img, img, cv::COLOR_BGR2GRAY);
    
    string filename = remove_extension_from_filename(argv[1]);
    filename += "_grayscale.png";
    
    cout << "Saving grayscale image to " << filename << endl;
    cv::imwrite(filename, img);
    
    return 0;
}

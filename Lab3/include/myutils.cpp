#include "myutils.h"

using std::cout;
using std::cerr;
using std::endl;

void print_image_details(const cv::Mat &img)
{
    std::string depth;
    switch (img.depth()) {
    case CV_8U:
        depth = "CV_8U - 8-bit unsigned integers";
        break;
    case CV_8S:
        depth = "CV_8S - 8-bit signed integers";
        break;
    case CV_16U:
        depth = "CV_16U - 16-bit unsigned integers";
        break;
    case CV_16S:
        depth = "CV_16S - 16-bit signed integers";
        break;
    case CV_32S:
        depth = "CV_32S - 32-bit signed integers";
        break;
    case CV_32F:
        depth = "CV_32F - 32-bit floating-point numbers";
        break;
    case CV_64F:
        depth = "CV_64F - 64-bit floating-point numbers";
        break;
    default:
        break;
    }

    cout << "Image details:" << endl;
    cout << "  - Dims: " << img.rows << " x " << img.cols << endl;
    cout << "  - Channels: " << img.channels() << endl;
    cout << "  - Depth: " << depth << endl;
    cout << endl;
}

std::string remove_extension_from_filename(const std::string &s)
{
    std::string::size_type ext_pos = s.rfind(".");
    std::string r = s.substr(0, ext_pos);
    return r;
}

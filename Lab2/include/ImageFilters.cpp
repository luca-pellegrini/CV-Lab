#include "ImageFilters.h"

using std::cout;
using std::cerr;
using std::endl;

void min_filter(const cv::Mat& src, cv::Mat& dst, int ksize)
{
    /* Kernel size must be an odd number */
    if (ksize % 2 == 0)
    {
        throw std::invalid_argument("Error: ksize: kernel size must be an odd number");
    }
    if (src.channels() != dst.channels())
    {
        throw std::invalid_argument("Error: src and dst must have the same number of channels");
    }
    int channels = src.channels();
//    cout << "Number of channels: " << channels << endl; // DEBUG
//    cout << "Kernel size: " << ksize << endl; // DEBUG
    if (channels != 1 && channels != 3)
    {
        throw std::invalid_argument("Error: unsupported number of channels in image");
    }
    std::vector<unsigned char> neighborhood[channels];
    int offset = (ksize - 1) / 2;
//    cout << "offset = " << offset << endl; // DEBUG

    for (int i = 0; i < src.rows; i++)
    {
        for (int j = 0; j < src.cols; j++)
        {
            /* Copy values around the current pixel */
            for (int c = 0; c < channels; c++)
            {
                for (int m = i - offset; m <= i + offset; m++)
                {
                    for (int n = j - offset; n <= j + offset; n++)
                    {
                        if (0 <= m && m < src.rows && 0 <= n && n < src.cols)
                        {
                            switch (channels)
                            {
                                case 1:
                                    neighborhood[c].push_back(src.at<unsigned char>(m, n));
                                    break;
                                case 3:
                                    neighborhood[c].push_back(src.at<cv::Vec3b>(m, n)[c]);
                                    break;
                            }
                        }
                    }
                }
                /* Compute the minimum, for every channel */
                unsigned char value = *std::min_element(neighborhood[c].begin(), neighborhood[c].end());
                switch (channels)
                {
                    case 1:
                        dst.at<unsigned char>(i, j) = value;
                        break;
                    case 3:
                        dst.at<cv::Vec3b>(i, j)[c] = value;
                        break;
                }
                neighborhood[c].clear();
            }
        }
    }

    return;
}

void max_filter(const cv::Mat& src, cv::Mat& dst, int ksize)
{
    /* Kernel size must be an odd number */
    if (ksize % 2 == 0)
    {
        throw std::invalid_argument("Error: ksize: kernel size must be an odd number");
    }
    if (src.channels() != dst.channels())
    {
        throw std::invalid_argument("Error: src and dst must have the same number of channels");
    }
    int channels = src.channels();
    if (channels != 1 && channels != 3)
    {
        throw std::invalid_argument("Error: unsupported number of channels in image");
    }
    std::vector<unsigned char> neighborhood[channels];
    int offset = (ksize - 1) / 2;

    for (int i = 0; i < src.rows; i++)
    {
        for (int j = 0; j < src.cols; j++)
        {
            /* Copy values around the current pixel */
            for (int c = 0; c < channels; c++)
            {
                for (int m = i - offset; m <= i + offset; m++)
                {
                    for (int n = j - offset; n <= j + offset; n++)
                    {
                        if (0 <= m && m < src.rows && 0 <= n && n < src.cols)
                        {
                            switch (channels)
                            {
                                case 1:
                                    neighborhood[c].push_back(src.at<unsigned char>(m, n));
                                    break;
                                case 3:
                                    neighborhood[c].push_back(src.at<cv::Vec3b>(m, n)[c]);
                                    break;
                            }
                        }
                    }
                }
                /* Compute the maximum, for every channel */
                unsigned char value = *std::max_element(neighborhood[c].begin(), neighborhood[c].end());
                switch (channels)
                {
                    case 1:
                        dst.at<unsigned char>(i, j) = value;
                        break;
                    case 3:
                        dst.at<cv::Vec3b>(i, j)[c] = value;
                        break;
                }
                neighborhood[c].clear();
            }
        }
    }

    return;
}

void median_filter(cv::Mat &src, cv::Mat &dst, int ksize)
{
    /* Kernel size must be an odd number */
    if (ksize % 2 == 0)
    {
        throw std::invalid_argument("Error: ksize: kernel size must be an odd number");
    }
    if (src.channels() != dst.channels())
    {
        throw std::invalid_argument("Error: src and dst must have the same number of channels");
    }
    int channels = src.channels();
    if (channels != 1 && channels != 3)
    {
        throw std::invalid_argument("Error: unsupported number of channels in image");
    }
    std::vector<unsigned char> neighborhood[channels];
    int offset = (ksize - 1) / 2;

    for (int i = 0; i < src.rows; i++)
    {
        for (int j = 0; j < src.cols; j++)
        {
            /* Copy values around the current pixel */
            for (int c = 0; c < channels; c++)
            {
                for (int m = i - offset; m <= i + offset; m++)
                {
                    for (int n = j - offset; n <= j + offset; n++)
                    {
                        if (0 <= m && m < src.rows && 0 <= n && n < src.cols)
                        {
                            switch (channels)
                            {
                                case 1:
                                    neighborhood[c].push_back(src.at<unsigned char>(m, n));
                                    break;
                                case 3:
                                    neighborhood[c].push_back(src.at<cv::Vec3b>(m, n)[c]);
                                    break;
                            }
                        }
                    }
                }
                /* Compute the median, for every channel
                 * Reference: https://en.cppreference.com/w/cpp/algorithm/nth_element
                 * (see example at the bottom of the page)
                 */
                auto sz = neighborhood[c].size();
                auto m = neighborhood[c].begin() + sz / 2;
                std::nth_element(neighborhood[c].begin(), m, neighborhood[c].end());
                unsigned char value = neighborhood[c][sz / 2];
                switch (channels)
                {
                    case 1:
                        dst.at<unsigned char>(i, j) = value;
                        break;
                    case 3:
                        dst.at<cv::Vec3b>(i, j)[c] = value;
                        break;
                }
                neighborhood[c].clear();
            }
        }
    }

    return;
}

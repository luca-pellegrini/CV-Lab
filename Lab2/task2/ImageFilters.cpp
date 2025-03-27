#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "ImageFilters.h"

void min_filter(cv::InputArray src, cv::InputArray dst, int ksize)
{
    /* Min filter
     *
     * This filter only supports images with either 1 or 3 channels,
     * with values codified as unsigned chars.
     * Kernel size must be an odd number.
     */
    if (ksize % 2 == 0)
    {
        throw std::invalid_argument("Error: ksize: kernel size must be an odd number");
    }
    if (src.channels() != dst.channels())
    {
        throw std::invalid_argument("Error: src and dst must have the same number of channels");
    }
    cv::Mat src_img = src.getMat();
    cv::Mat dst_img = dst.getMat();
    int channels = src_img.channels();
    std::vector<unsigned char> neighborhood[channels];
    int offset = (ksize - 1) / 2;

    for (int i = 0; i < src_img.rows; i++)
    {
        for (int j = 0; j < src_img.cols; j++)
        {
            /* Copy values around the current pixel */
            for (int c = 0; c < channels; c++)
            {
                for (int m = i - offset; m <= i + offset; m++)
                {
                    for (int n = j - offset; n <= j + offset; n++)
                    {
                        if (0 <= m && m < src_img.rows && 0 <= n && n < src_img.cols)
                        {
                            switch (channels)
                            {
                                case 1:
                                    neighborhood[c].push_back(src_img.at<unsigned char>(m, n));
                                    break;
                                case 3:
                                    neighborhood[c].push_back(src_img.at<cv::Vec3b>(m, n)[c]);
                                    break;
                                default:
                                    std::cerr << "Error: unsupported number of channels in image\n";
                                    throw std::exception();
                            }
                        }
                    }
                }
                /* Compute the minimum, for every channel */
                unsigned char value = *std::min_element(neighborhood[c].begin(), neighborhood[c].end());
                switch (channels)
                {
                    case 1:
                        dst_img.at<unsigned char>(i, j) = value;
                        break;
                    case 3:
                        dst_img.at<cv::Vec3b>(i, j)[c] = value;
                        break;
                }
            }
        }
    }

    return;
}

void max_filter(cv::InputArray src, cv::InputArray dst, int ksize)
{
    /* Max filter
     *
     * This filter only supports images with either 1 or 3 channels,
     * with values codified as unsigned chars.
     * Kernel size must be an odd number.
     */
    if (ksize % 2 == 0)
    {
        throw std::invalid_argument("Error: ksize: kernel size must be an odd number");
    }
    if (src.channels() != dst.channels())
    {
        throw std::invalid_argument("Error: src and dst must have the same number of channels");
    }
    cv::Mat src_img = src.getMat();
    cv::Mat dst_img = dst.getMat();
    int channels = src_img.channels();
    std::vector<unsigned char> neighborhood[channels];
    int offset = (ksize - 1) / 2;

    for (int i = 0; i < src_img.rows; i++)
    {
        for (int j = 0; j < src_img.cols; j++)
        {
            /* Copy values around the current pixel */
            for (int c = 0; c < channels; c++)
            {
                for (int m = i - offset; m <= i + offset; m++)
                {
                    for (int n = j - offset; n <= j + offset; n++)
                    {
                        if (0 <= m && m < src_img.rows && 0 <= n && n < src_img.cols)
                        {
                            switch (channels)
                            {
                                case 1:
                                    neighborhood[c].push_back(src_img.at<unsigned char>(m, n));
                                    break;
                                case 3:
                                    neighborhood[c].push_back(src_img.at<cv::Vec3b>(m, n)[c]);
                                    break;
                                default:
                                    std::cerr << "Error: unsupported number of channels in image\n";
                                    throw std::exception();
                            }
                        }
                    }
                }
                /* Compute the minimum, for every channel */
                unsigned char value = *std::max_element(neighborhood[c].begin(), neighborhood[c].end());
                switch (channels)
                {
                    case 1:
                        dst_img.at<unsigned char>(i, j) = value;
                        break;
                    case 3:
                        dst_img.at<cv::Vec3b>(i, j)[c] = value;
                        break;
                }
            }
        }
    }

    return;
}

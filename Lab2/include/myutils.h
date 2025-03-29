#ifndef MYUTILS_H
#define MYUTILS_H

#include <iostream>
#include <string>

#include <opencv2/core.hpp>


void print_image_details(const cv::Mat& img);

std::string remove_extension_from_filename(const std::string& s);

#endif // MYUTILS_H

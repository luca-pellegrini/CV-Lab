#ifndef MYUTILS_H
#define MYUTILS_H

#include <iostream>
#include <string>

#include <opencv2/core.hpp>

/**
 * @brief Print basic information about an image
 * @param img
 */
void print_image_details(const cv::Mat& img);

// Manipulation of pathnames and filenames

/**
 * @brief remove_extension_from_filename
 * @param str
 * @return
 */
std::string remove_extension_from_filename(const std::string& str);

#endif // MYUTILS_H

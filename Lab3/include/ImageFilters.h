#ifndef IMAGEFILTERS_H
#define IMAGEFILTERS_H

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

#include <opencv2/core.hpp>

/**
 * @brief My implementation of a min filter
 *
 * @param src Source 8-bit, 1-channel or 3-channel image.
 * @param dst Destination image of the same size and type as src.
 * @param ksize Kernel size; must be positive and odd.
 */
void min_filter(const cv::Mat& src, cv::Mat& dst, int ksize);
//void min_filter(cv::InputArray src, cv::InputArray dst, int ksize);

/**
 * @brief My implementation of a max filter
 *
 * @param src Source 8-bit, 1-channel or 3-channel image.
 * @param dst Destination image of the same size and type as src.
 * @param ksize Kernel size; must be positive and odd.
 */
void max_filter(const cv::Mat& src, cv::Mat& dst, int ksize);
//void max_filter(cv::InputArray src, cv::InputArray dst, int ksize);

/**
 * @brief My implementation of a median filter
 *
 * @param src Source 8-bit, 1-channel or 3-channel image.
 * @param dst Destination image of the same size and type as src.
 * @param ksize Kernel size; must be positive and odd.
 */
void median_filter(cv::Mat& src, cv::Mat& dst, int ksize);

#endif

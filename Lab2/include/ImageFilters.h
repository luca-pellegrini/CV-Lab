#ifndef IMAGEFILTERS_H
#define IMAGEFILTERS_H

#include <opencv2/imgproc.hpp>


//void min_filter(cv::InputArray src, cv::InputArray dst, int ksize);
void min_filter(const cv::Mat& src, cv::Mat& dst, int ksize);

//void max_filter(cv::InputArray src, cv::InputArray dst, int ksize);
void max_filter(const cv::Mat& src, cv::Mat& dst, int ksize);

void median_filter(cv::Mat& src, cv::Mat& dst, int ksize);

#endif

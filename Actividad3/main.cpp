#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <filesystem>

int main() {
    // Input image path
    std::string image_path;
    std::cout << "Enter the path to the image: ";
    std::cin >> image_path;

    // Check if the file exists
    if (!std::filesystem::exists(image_path)) {
        std::cout << "File does not exist at the specified path" << std::endl;
        return -1;
    }

    // Load the image
    cv::Mat originalImage = cv::imread(image_path);

    if (originalImage.empty()) {
        std::cout << "Error loading the image" << std::endl;
        return -1;
    }

    // Show the original image
    cv::imshow("Original Image", originalImage);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // Separate the image into its three channels
    cv::Mat bgr[3];
    cv::split(originalImage, bgr);

    // Show individual channels with their gray intensity
    cv::imshow("Gray Blue Channel", bgr[0]);
    cv::imshow("Gray Green Channel", bgr[1]);
    cv::imshow("Gray Red Channel", bgr[2]);
    cv::waitKey(0);
    cv::destroyAllWindows();

    // Modify images using color maps
    cv::Mat blueChannel, greenChannel, redChannel;
    cv::applyColorMap(bgr[0], blueChannel, cv::COLORMAP_BONE);
    cv::applyColorMap(bgr[1], greenChannel, cv::COLORMAP_COOL);
    cv::applyColorMap(bgr[2], redChannel, cv::COLORMAP_HSV);

    // Create modified image windows
    cv::imshow("Blue Channel", blueChannel);
    cv::imshow("Green Channel", greenChannel);
    cv::imshow("Red Channel", redChannel);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}

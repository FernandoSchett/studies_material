/*
File:           check_version.cpp
Last changed:   27/06/2023 23:15
Purpose:        check opencv version    
Authors:        Fernando Antonio Marques Schettini   
Usage: 
	HowToCompile:   cmake .. && make
	HowToExecute:   ./check_version       
*/


#include <opencv2/core/core.hpp>
#include <iostream>

int main() {
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;
    return 0;
}
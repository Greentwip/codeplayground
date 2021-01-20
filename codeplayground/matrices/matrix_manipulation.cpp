//
//  matrix_manipulation.cpp
//  codeplayground
//
//  Created by Greentwip on 19/01/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <ostream>
#include <algorithm>

#include "catch_amalgamated.hpp"

TEST_CASE( "Test matrix diagonals" ) {
    // get the sum of left and right diagonals of a given matrix
    
    auto matrix = std::vector<std::vector<int>>{
        {12, 1, 5},
        {15, 10, 0},
        {5, 4, 2}
    };
    
    int leftDiagonal = 0;
    int rightDiagonal = 0;
    
    for(int i = 0; i<matrix.size(); ++i){
        leftDiagonal += matrix[i][i];
    }
    
    for(int i = (int)(matrix.size() - 1); i>= 0; --i){
        rightDiagonal += matrix[i][(matrix.size() -1) - i];
    }
    
    INFO("Left diagonal is: " << std::to_string(leftDiagonal));
    INFO("Right diagonal is: " << std::to_string(rightDiagonal));
    
    INFO("Sum: " << std::to_string(leftDiagonal + rightDiagonal));
    
    
    INFO("Abs difference: " << std::to_string(std::abs(leftDiagonal - rightDiagonal)));
    
    CHECK(std::abs(leftDiagonal - rightDiagonal) == 4);
    
}

TEST_CASE( "Array ratios" ) {
    auto arr = std::vector<int>{-4, 3, -9, 0, 4, 1};
    int positives = 0;
    int negatives = 0;
    int zeros = 0;
    
    for(auto& number : arr){
        if(number > 0){
            positives++;
        } else if(number < 0){
            negatives++;
        } else {
            zeros++;
        }
    }
    
    double positiveRatio = (double)(positives) / (double)(arr.size()) ;
    double negativeRatio = (double)(negatives) / (double)(arr.size());
    double zeroRatio = (double)(zeros) / (double)(arr.size());
    
    std::ostringstream positiveResult;
    positiveResult << std::fixed << std::setprecision(6) << positiveRatio;
    
    std::ostringstream negativeResult;
    negativeResult << std::fixed << std::setprecision(6) << negativeRatio;
    
    std::ostringstream zeroResult;
    zeroResult << std::fixed << std::setprecision(6) << zeroRatio;
    
    INFO("Positives " << positiveResult.str());
    INFO("Negatives " << negativeResult.str());
    INFO("Zeros " << zeroResult.str());
    
    CHECK(positiveResult.str().compare("0.500000") == 0);
    CHECK(negativeResult.str().compare("0.333333") == 0);
    CHECK(zeroResult.str().compare("0.166667") == 0);
    
}

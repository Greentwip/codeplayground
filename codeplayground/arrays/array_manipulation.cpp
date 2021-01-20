//
//  array_manipulation.cpp
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

TEST_CASE( "Test 4 of 5" ) {
    
    auto array = std::vector<int>{1, 2, 3, 4, 5};
    
    long long minSum = 0;
    long long maxSum = 0;
    
    std::sort(array.begin(), array.end());
    

    
    for(int i = 0; i<array.size() - 1; i++){
        // print spaces
        
        minSum += array[i];
        
        if(i > 0){
            maxSum += array[i];
        }
        
    }
    
    maxSum += array[array.size() -1];
    
    CHECK(minSum == 10);
    CHECK(maxSum == 14);
    
}


TEST_CASE( "Test max candles" ) {
    
    auto candles = std::vector<int>{3, 2, 1, 3};
    int max_element = *std::max_element(candles.begin(), candles.end());
    
    long long max_candles = 0;
    
    for(auto& candle : candles){
        if(candle == max_element){
            max_candles++;
        }
    }
    
    return ;
    
    CHECK(max_candles == 2);
    
}


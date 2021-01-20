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
        
    CHECK(max_candles == 2);
    
}

TEST_CASE( "Test max min" ) {
    
    auto c =
    std::vector<int>{
        10,
        100,
        300,
        200,
        1000,
        20,
        30};
    int k = 3;
    
    auto& arr = c;
        
    std::sort(arr.begin(), arr.end());
   
    std::vector<std::vector<int>> fair_arrays;
    
    int min_fairness = std::numeric_limits<int>::max();
    
    for(int i = 0; i<arr.size() - k; i++){
        
        auto max_end = std::min((i+k), (int)arr.size());
        
        auto fair_array = std::vector<int>(arr.begin()+i, arr.begin()+max_end);
        
        auto fairness = fair_array[fair_array.size() - 1] - fair_array[0];
        
        if(fairness < min_fairness){
            min_fairness = fairness;
        }
    }
    
                                  
                                       
    CHECK(min_fairness == 20);
    
}



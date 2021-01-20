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

#include "catch_amalgamated.hpp"

TEST_CASE( "Test 4 of 5" ) {
    
    auto array = std::vector<int>{1, 2, 3, 4, 5};
    
    int minSum = 0;
    int maxSum = 0;
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

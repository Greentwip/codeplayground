//
//  samples.cpp
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

TEST_CASE( "Test products purchasen" ) {
    
    auto products = std::vector<int>{1, 12, 5, 111, 200, 1000, 10};
    
    std::sort(products.begin(), products.end());
    
    int budget = 50;
    int count = 0, sum = 0;
    
    for(auto& price : products){
        if(price + sum <= budget){
            count++;
            sum += price;
        }
    }
    
    
    CHECK(count == 4);
    
}



//
//  string_manipulation.cpp
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

std::string create_slope(int slope_position, int total_slopes){
    
    std::ostringstream oss;
    
    for(int times = 0; times < (total_slopes - 1) - slope_position; times++){
        oss << " ";
    }
    
    for(int times = 0; times < slope_position + 1; times++){
        oss << "#";
    }
    
    if(slope_position < total_slopes - 1){
        oss << std::endl;
    }
    
    return oss.str();
}

TEST_CASE( "Test staircase" ) {
    int n = 6;
    
    std::vector<std::string> slopes;
    
    for(int i = 0; i<n; i++){
        // print spaces
        
        slopes.push_back(create_slope(i, n));
        
    }
    
    CHECK(slopes[0].compare("     #\n") == 0);
    CHECK(slopes[1].compare("    ##\n") == 0);
    CHECK(slopes[2].compare("   ###\n") == 0);
    CHECK(slopes[3].compare("  ####\n") == 0);
    CHECK(slopes[4].compare(" #####\n") == 0);
    CHECK(slopes[5].compare("######") == 0);
}

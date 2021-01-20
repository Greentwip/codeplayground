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

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

std::vector<std::string> split(std::string str, char token){
    std::replace(str.begin(), str.end(), token, ' ');  // replace ':' by ' '

    std::vector<std::string> array;
    std::stringstream ss(str);
    std::string temp;
    
    while (ss >> temp){
        array.push_back(temp);
    }
    
    return array;

}

TEST_CASE( "Test time conversion" ) {
    std::string input = "02:34:50PM";

    bool is_pm = false;
    if(replace(input, "PM", "")){
        is_pm = true;
    } else{
        replace(input, "AM", "");
        is_pm = false;
    }
    
    std::vector<std::string> time_chunks = split(input, ':');
    
    int hour = std::atoi(time_chunks[0].c_str());
    
    if(is_pm){
        if(hour != 12){
            hour += 12;
        }
    }
    
    if(!is_pm){
        if(hour == 12){
            hour = 0;
        }
    }
    
    std::string final_hour;
    
    if(std::to_string(hour).length() == 1){
        final_hour = "0" + std::to_string(hour);
    } else {
        final_hour = std::to_string(hour);
    }
    
    std::ostringstream oss;
    
    oss << final_hour;
    oss << ":";
    oss << time_chunks[1];
    oss << ":";
    oss << time_chunks[2];
    
    CHECK(oss.str().compare("14:34:50") == 0);
    
}

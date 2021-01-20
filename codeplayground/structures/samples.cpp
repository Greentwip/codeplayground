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

TEST_CASE( "Test greedy florist" ) {
    
    auto c = std::vector<int>{1, 3, 7, 5, 9};
    int k = 3;
    
    std::sort(c.begin(), c.end(), std::greater<int>());
    
    unsigned int count = (unsigned int)c.size();
    int price = 0;
    int previous_price = 0;
    int customers = k;
    
    for(int purchasen = 0, purchasen_flower_index=customers-1;
        purchasen<count;
        ++purchasen){
        price += c[purchasen] * (previous_price + 1);
        
        if(purchasen == purchasen_flower_index){
            previous_price++;
            purchasen_flower_index+=customers;
        }
        
    }
    
    
    CHECK(price == 29);
    
}



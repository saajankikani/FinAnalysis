//
//  DataWrangle.hpp
//  FinAnalysis
//
//  Created by Saajan Kikani on 2/14/23.
//

#ifndef DataWrangle_hpp
#define DataWrangle_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class DataWrangle{
private:
    std::vector<double> close_price;
    std::vector<double> open_price;
    std::vector<std::string> dates;
    std::vector<int> volumes;
    std::vector<double> trading_range;
    
    std::string filename;
    std::string ticker;
    
    std::string time_range;
    
public:
    DataWrangle(std::string filename_in);
    
    void process();
    
    void form();
    
    std::vector<double> get_close();
    
    std::vector<double> get_open();
    
};
#endif /* DataWrangle_hpp */

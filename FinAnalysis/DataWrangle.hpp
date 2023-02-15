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

class DataWrangle{
private:
    std::vector<double> close_price;
    std::vector<double> open_price;
    
    std::string filename;
    std::string ticker;
    
public:
    DataWrangle(std::string filename_in);
    
    void process();
    
    void form();
    
    std::vector<double> get_close();
    
    std::vector<double> get_open();
    
    
};
#endif /* DataWrangle_hpp */

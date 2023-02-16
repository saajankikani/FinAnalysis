//
//  DataWrangle.cpp
//  FinAnalysis
//
//  Created by Saajan Kikani on 2/14/23.
//

#include "DataWrangle.hpp"

DataWrangle::DataWrangle(std::string filename_in){
    filename = filename_in;
    size_t sz = filename_in.size();
    
    for(size_t i = 0; i < sz - 4; ++i){
        ticker = ticker + filename[i];
    }
}

void DataWrangle::process(){
    
    std::ifstream fin(filename);
    
    if(!fin.is_open()){
        std::cout<<"No filename: "<<filename<<"found "<<'\n';
    }
    
    //Date,Open,High,Low,Close,Adj Close,Volume
    std::string date_in;
    double open_in = 0.0;
    double high_in = 0.0;
    double low_in = 0.0;
    double close_in = 0.0;
    double adj_close = 0.0;
    int volume = 0;
    std::string junk;
    
    std::cin >> junk >> junk >> junk >> junk >> junk
    >> junk >> junk;
    
    while(std::cin >> date_in >> open_in >> high_in
            >> low_in >> close_in >> adj_close >> volume){
       
        //Build a bunch of parallel vectors that can be used in the indicators section
        dates.push_back(date_in);
        open_price.push_back(open_in);
        trading_range.push_back(high_in - low_in);
        close_price.push_back(close_in);
        volumes.push_back(volume);
    }
    
    if(open_price.size() > 60){
        time_range = "daily";
        
    }else if(open_price.size() > 20){
        time_range = "weekly";
    }else{
        time_range = "monthly";
    }
}

std::vector<double> DataWrangle::get_open(){
    return open_price;
    
}
std::vector<double> DataWrangle::get_close(){
    return close_price;
}

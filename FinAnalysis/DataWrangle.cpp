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
    
    io::CSVReader<7> fin(filename);
    
    //Date,Open,High,Low,Close,Adj Close,Volume
    std::string date_in;
    double open_in = 0.0;
    double high_in = 0.0;
    double low_in = 0.0;
    double close_in = 0.0;
    double adj_close = 0.0;
    int volume = 0;
    
    fin.read_header(io::ignore_extra_column, "Date", "Open", "High", "Low", "Close", "Adj Close", "Volume");
    
    
    while(fin.read_row(date_in, open_in, high_in, low_in, close_in, adj_close, volume)){
       
        //Build a bunch of parallel vectors that can be used in the indicators section
        dates.push_back(date_in);
        open_price.push_back(open_in);
        trading_range.push_back(high_in - low_in);
        close_price.push_back(close_in);
        volumes.push_back(volume);
    }
    
    if(open_price.size() == 251){
        time_range = "daily";
        
    }else{
        time_range = "other";
    }
    
}

size_t DataWrangle::open_sz(){
    return open_price.size();
    
}
size_t DataWrangle::close_sz(){
    return close_price.size();
}

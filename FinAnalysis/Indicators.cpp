//
//  Indicators.cpp
//  FinAnalysis
//
//  Created by Saajan Kikani on 2/14/23.
//

#include "Indicators.hpp"

std::vector<double> dcf(std::vector<double> fcf, double wacc){
    std::vector<double> res;
    
    for(size_t i = 0; i < fcf.size(); ++i){
        
        res.push_back(fcf.at(i)/(pow(1 + wacc, i)));
    }
    
    return res;
}

double sharpe(DataWrangle data){
    //split the period into segments
    //calculate the return based on the segment
    //find the variance of each segment
    //average the variances
    //sqrt the variances
    
    int split = 0;
    
    if(data.time_range == "daily"){
        split = 73; //(365/5)
        
        std::vector<twin> values;
        
    }else if(data.time_range == "monthly"){
        split = 3; //(12/4)
        
    }else{
        split = 13; //(52/4)
        
    }
    
    return 0.0;
}

double simple_mov_avg(DataWrangle data, int roll){
    
    //rolling average that changes based on the specified value
    if(roll != 50 && roll != 100 && roll != 200){
        std::cout << "Choose a parameter for SMA [50, 100, or 200]: ";
        std::cin >> roll;
    }
    
    double sma = 0.0;
    
    double denom = 1;
    
    for(size_t i = data.open_sz() - roll; i < data.open_sz(); ++i){
        sma = (sma + data.close_price[i]) / denom ;
        denom = denom + 1;
    }
    
    return sma;
}

double exp_mov_avg(DataWrangle data, int smooth, int roll){
    double ema = data.close_price[data.close_sz() - roll];
    
    for(size_t i = data.close_sz() - roll + 1; i < data.close_sz(); ++i){
        ema = (ema * (1 - (smooth/(1 + roll)))) +
               (data.close_price[i] + (smooth/ 1 + roll));
    }
    
    return ema;
}

double disc_resid_inc(){
    return 0.0;
}


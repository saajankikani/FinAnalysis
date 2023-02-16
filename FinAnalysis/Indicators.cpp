//
//  Indicators.cpp
//  FinAnalysis
//
//  Created by Saajan Kikani on 2/14/23.
//

#include "Indicators.hpp"

std::vector<double> dcf(int years, double init_fcf, double rate){
    std::vector<double> res;
    
    return res;
}

double sharpe(){
    return 0.0;
}

double simple_mov_avg(DataWrangle data, int roll){
    
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
}

double exp_mov_avg(int roll){
    return 0.0;
}

double disc_resid_inc(){
    return 0.0;
}

double obv(){
    return 0.0;
}

double rsi(){
    return 0.0;
}

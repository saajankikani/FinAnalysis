//
//  Indicators.hpp
//  FinAnalysis
//
//  Created by Saajan Kikani on 2/14/23.
//

#ifndef Indicators_hpp
#define Indicators_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include "DataWrangle.hpp"
#include <cmath>
#include <numeric>

struct twin{
    double prcent = 0.0;
    double standard_dev = 0.0;
};

std::vector<double> dcf(std::vector<double> fcf, double wacc);

double sharpe(DataWrangle data);

double simple_mov_avg(DataWrangle data, int roll);

double exp_mov_avg(DataWrangle data, double smooth, int roll);

double disc_resid_inc(double bv, double coe, std::vector<double> inc_forecast, std::vector<double> eq_forecast);


#endif /* Indicators_hpp */

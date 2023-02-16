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

std::vector<double> dcf(int years, double init_fcf, double rate);

double sharpe();

double simple_mov_avg(DataWrangle data, int roll);

double exp_mov_avg(int roll);

double disc_resid_inc();

double obv();

double rsi();

#endif /* Indicators_hpp */

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

void sharpe_calc(DataWrangle data, double split, int segments, std::vector<twin> &val){
        double split_count = 0.0;

        for(int i = 0; i < segments; ++i){
            double percent = (data.close_price[split_count] + 
                    data.close_price[split + split_count])/split;
            
            twin input;
            input.prcent = percent;
            val.push_back(input);
            
            double variance = 0.0;

            double mean = std::accumulate(data.close_price.begin() + split_count, 
                            data.close_price.begin() + split + split_count, 0.0)/data.close_sz();

            for(size_t i = split_count; i < split_count + split; ++i){
                variance = variance + pow(mean - data.close_price[i], 2);

            }

            val.at(i).standard_dev = sqrt(variance);

            split_count = split + split_count;
        }
}

double sharpe(DataWrangle data){
    //split the period into segments
    //calculate the return based on the segment
    //find the variance of each segment
    //average the variances
    //sqrt the variances
    
    double split = 0.0;

    //Return of a Treasury Bond
    const double risk_free_rate = 0.03;
    std::vector<twin> values;
    
    if(data.time_range == "daily"){
        split = 72; //(365/5) and then consider the indeces
        sharpe_calc(data, split, 5, values);
        
    }else if(data.time_range == "monthly"){
        split = 2; //(12/4) and then consider the indices
        sharpe_calc(data, split, 4, values);
        
    }else{
        split = 12; //(52/4) and then consider the indices
        sharpe_calc(data, split, 12, values);
        
    }
    double portfolio_return = 0.0;
    double std_dev = 0.0;

    for(size_t i = 0; i < values.size(); ++i){
        portfolio_return = (values.at(i).prcent + portfolio_return)/ (i + 1);
        std_dev = (values.at(i).standard_dev + std_dev)/ (i + 1);
    }
    
    return (portfolio_return - risk_free_rate)/ std_dev;
}

double simple_mov_avg(DataWrangle data, int roll){
    
    //rolling average that changes based on the specified value
    if(roll != 50 && roll != 100 && roll != 200){
        std::cout << "Choose a parameter for SMA [50, 100, or 200]: ";
        std::cin >> roll;
    }
    
    double sma = 0.0;
    double sma_numerator = 0.0;
    
    double denom = 1.0;
    
    for(size_t i = data.open_sz() - roll; i < data.open_sz(); ++i){
        sma_numerator = sma_numerator + data.close_price[i];
        sma = sma_numerator / denom ;
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

double disc_resid_inc(double bv, double coe, std::vector<double> inc_forecast, std::vector<double> eq_forecast){
    
    std::vector<double> resid_inc;

    if(inc_forecast.size() != eq_forecast.size()){
        std::cout<<"Fix vector lengths"<<'\n';
        return 0.0;

    }

    for(size_t i = 0; i < inc_forecast.size(); ++i){
        resid_inc.push_back(inc_forecast.at(i) - (eq_forecast.at(i) * coe));
    }

    double val = 0.0;
    const double risk_free_return = 0.03;
    for(size_t i = 0; i < resid_inc.size(); ++i){
        val = resid_inc.at(i) / pow(1 + risk_free_return, i + 1);

    }
    return val + bv;
}


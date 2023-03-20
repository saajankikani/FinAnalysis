//
//  main.cpp
//  FinAnalysis
//
//  Created by Saajan Kikani on 2/14/23.
//

#include <iostream>
#include "Indicators.hpp"
#include "DataWrangle.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout<<"Enter USERID: ";
    std::string username;
    std::cin >> username;

//    std::cout<<"Input filename: ";
//    std::string file_in;
//    std::cin >> file_in;

    DataWrangle data(argv[2]);
    std::cout<<"Processing..."<<'\n';
    data.process();

    std::cout<<"Run Entire package? [y/n]: ";
    char answer;
    std::cin >> answer;

    if(answer == 'y'){
        std::cout<<"Simple Moving Average: "<< simple_mov_avg(data, 50)<<'\n';
        std::cout<<"Exponential Moving Average: "<< exp_mov_avg(data, 2, 50)<<'\n';
        std::cout<<"Sharpe Ratio: "<<sharpe(data)<<'\n';
    }else{
        std::cout<<"Which packages would you like to see?"<<'\n';
        std::cout<<'\t'<<"[1] Simple Moving Average"<<'\n';
        std::cout<<'\t'<<"[2] Exponential Moving Average"<<'\n';
        std::cout<<'\t'<<"[3] Sharpe Ratio"<<'\n';
        
        std::cout<<"Enter Choice here -> "<<'\n';
        std::string answer;
        std::cin>>answer;

        if(answer == "1" || answer == "Simple Moving Average"){
        
            std::cout<<"Simple Moving Average: "<< simple_mov_avg(data, 50)<<'\n';

        }else if(answer == "2" || answer == "Exponential Moving Average"){

            std::cout<<"Exponential Moving Average: "<< exp_mov_avg(data, 2.0, 50)<<'\n';
      
        }else if(answer == "3" || answer == "Sharpe Ratio"){
        
            std::cout<<"Sharpe Ratio: "<<sharpe(data)<<'\n';
        }
    }

    return 0;
}

#include<iostream>
#include "header_files/stock10.h"

// Default constructor.
Stock::Stock(){
    std::cout<<"Default constructor called!"<<std::endl;
    company="Null";
    shares=0;
    share_val=0.0;
    total_val=0.0;
}

Stock::Stock(const std::string & co,long n,double pr){
    company=co;
    if (n < 0)
    {
        std::cout<<"Number of shares can't be negative; "<<company<<" shares set to 0."<<std::endl;
    }
    else shares=n;
    share_val=pr;
    set_tot();
}

// Default destructor.
Stock::~Stock(){
    std::cout<<"Default destructor called! Bye!"<<std::endl;
}

void Stock::buy(long num,double price){
    if (num < 0) std::cout<<"Number of shares purchased can't be negative. Transaction is aborted."<<std::endl;
    else
    {
        shares+=num;
        share_val=price;
        set_tot();
    }
}

void Stock::sell(long num,double price){
    if (num < 0) std::cout<<"Number of shares sold can't be negative. Transaction is aborted."<<std::endl;
    else if (num > shares) std::cout<<"You can't sell more than you have! Transaction is aborted."<<std::endl;
    else
    {
        shares-=num;
        share_val=price;
        set_tot();
    }
}

void Stock::update(double price){
    share_val=price;
    set_tot();
}

void Stock::show(){
    std::ios_base::fmtflags orig=std::cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
    std::streamsize prec=std::cout.precision(3);
    
    std::cout<<"Company: "<<company<<std::endl;
    std::cout<<"  Shares: "<<shares<<std::endl;
    std::cout<<"  Share Price: $"<<share_val<<std::endl;
    std::cout.precision(3);
    std::cout<<"  Total Worth: $"<<total_val<<std::endl;

    std::cout.setf(orig,std::ios_base::floatfield);
    std::cout.precision(prec);
}
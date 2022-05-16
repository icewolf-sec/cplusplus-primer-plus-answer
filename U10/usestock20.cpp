#include<iostream>
#include "header_files/stock20.h"
using namespace std;
const int STKS=4;

int main(){
    int st;
    Stock stock[STKS]={
        Stock("NanoSmart",12,20.0),
        Stock("Boffo Objects",200,2.0),
        Stock("Monolithic Obelisks",130,3.25),
        Stock("Fleep Enterprises",60,6.5)
    };

    cout<<"Stock holdings:"<<endl;
    for (st = 0; st < STKS; st++) stock[st].show();
    const Stock * top=&stock[0];
    for (st = 1; st < STKS; st++) top=&top->topval(stock[st]);
    cout<<"Most valuable holding:"<<endl;
    top->show();

    system("pause");
    return 0;
}
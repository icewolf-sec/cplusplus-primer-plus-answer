#include "exec4.h"

Time::Time(){
    hours=minutes=0;
}

Time::Time(int h,int m){
    hours=h;
    minutes=m;
}

Time::~Time(){
    // Default destructor.
}

void Time::addMin(int m){
    minutes+=m;
    hours+=minutes/60;
    minutes%=60;
}

void Time::addHr(int h){
    hours+=h;
}

void Time::Reset(int h,int m){
    hours=h;
    minutes=m;
}

Time operator+(const Time & s,const Time & t){
    Time sum;
    sum.minutes=s.minutes+t.minutes;
    sum.hours=s.hours+t.hours+sum.minutes/60;
    sum.minutes%=60;
    return sum;
}

Time operator-(const Time & s,const Time & t){
    Time diff;
    int tot1;
    int tot2;
    tot1=t.minutes+60*t.hours;
    tot2=s.minutes+60*s.hours;
    diff.minutes=(tot2-tot1)%60;
    diff.hours=(tot2-tot1)/60;
    return diff;
}

Time operator*(const Time & s,double n){
    Time result;
    long totalminutes=s.hours*n*60+s.minutes*n;
    result.hours=totalminutes/60;
    result.minutes=totalminutes%60;
    return result;
}

std::ostream & operator<<(std::ostream & os,const Time & t){
    os<<t.hours<<" hours, "<<t.minutes<<" minutes"<<std::endl;
    return os;
}
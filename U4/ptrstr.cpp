#include<iostream>
#include<cstring>
using namespace std;
const char * bird="wren";
int main(){
    char animal[20]="bear";
    char * ps;

    cout<<animal<<" and "<<bird<<endl;
    cout<<"Enter a kind of animal: ";
    cin>>animal;
    ps=animal;
    cout<<ps<<"!"<<endl;
    cout<<"Before using strcpy():"<<endl;
    cout<<animal<<" at "<<(int *)animal<<endl;
    cout<<ps<<" at "<<(int *)ps<<endl;

    ps=new char[strlen(animal)+1];
    strcpy(ps,animal);
    cout<<"After using strcpy():"<<endl;
    cout<<animal<<" at "<<(int *)animal<<endl;
    cout<<ps<<" at "<<(int *)ps<<endl;
    delete [] ps;

    system("pause");
    return 0;
}
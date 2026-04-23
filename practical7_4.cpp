#include<iostream>
using namespace std;
class Calculator{
    public:
    float add(int a,float b);
    float add(float b,float c);
    int add(int a,int b);

};
int main(){
    Calculator c1;
    cout<<c1.add(5.3f,2.4f)<<endl;
    cout<<c1.add(2,6)<<endl;
    cout<<c1.add(1,4.7f);
}
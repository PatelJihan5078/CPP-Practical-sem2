#include<iostream>
#include<string>
using namespace std;
class Fuel
{
    string type;
public:
    Fuel(string n){
        type=n;
    }
    string fuel(){
        return type;
    }
};

class Brand{
    string name;
public:
  Brand(string n){
        name=n;
    }
    string brand(){
        return name;
    }
};

class Car:public Brand,public Fuel{
    string details;
public:
    Car(string t,string n):Fuel(t),Brand(n){}
    void mix(){
        details+=fuel();
        details+=" ";
        details+=brand();
    }
    void display(){
        cout<<"The Details of the car"<<endl;
        cout<<"Is as folllowing"<<endl;
        cout<<details;
    }
};
int main(){
    Car c1("Petrol","Rolls-Royce");
    c1.mix();
    c1.display();
    return 0;
}
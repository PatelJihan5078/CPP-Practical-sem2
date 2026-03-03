#include<iostream>
using namespace std;
class student
{
    int rollno;
    int marks[3];
    string name;
    public:
    student(){
        rollno=0;   
        name =" ";
        for(int i=0;i<3;i++){
            marks[i]=0;
        }
    }
    
    void getdetails();
    void showdetails();
    
};
   void student::getdetails(){
        cout<<"Enter the name of the student: ";
        cin>>name;
        cout<<"Enter the roll number: ";
        cin>>rollno;
        cout<<"Enter the marks of 3 subjects: ";
        for(int i=0;i<3;i++){
            cin>>marks[i];
        }
    }
    void student::showdetails(){
        int total=0;
        cout<<"Name: "<<name<<endl;
        cout<<"Roll No: "<<rollno<<endl;
        cout<<"Marks: ";
        for(int i=0;i<3;i++){
            cout<<marks[i]<<" ";
           
            total+=marks[i];
        }
        int avg = total/3;
        cout<<"\nAverage Marks: "<<avg;

        cout<<endl;
    }

int main(){
    student s1;
    s1.getdetails();
    s1.showdetails();
    return 0;
}
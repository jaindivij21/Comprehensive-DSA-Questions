#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

//Program to demonstrate objects and classes

class Students{
public:
    int roll;
    string name;
    int marks;

    void setStudent(int roll, string name, int marks){
        this->roll=roll;
        this->name=name;
        this->marks=marks;
    }

    void getStudent(){
        cout<<"Roll:" <<roll <<"\n" <<"Name:" <<name <<" " <<"Marks:" <<marks <<" " <<endl;
    }


};

int main() {
    Students s1;
    Students s2;

    s1.setStudent(1,"Divij",100);
    s2.setStudent(2,"Yatin",60);

    s1.getStudent();
    s2.getStudent();


    return 0;
}


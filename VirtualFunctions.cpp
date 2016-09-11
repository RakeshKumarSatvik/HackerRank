#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Current ID required to print the count of objects
static int professor_id = 1, student_id = 1;

//Parent Class
class Person {
public:
    virtual void getdata() {};
    virtual void putdata() {};

protected:    
    string name;
    int age;
};

//Derived Class
class Professor: public Person {
public:
    void getdata() {
        //Read name, age and publications for the derived class
        cin >> name >> age >> publications;
        
        //Assigning the current ID
        cur_id = professor_id;
        professor_id++;
    }
    
    void putdata() {
        //Print name, age and publications for the derived class
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
private:    
    int publications, cur_id;
};

//Derived Class
class Student: public Person {
public:
    void getdata() {
        sum = 0;
        
        //Read name and age for the derived class
        cin >> name >> age;
        
        //Calculate the sum of six subjects and read the inputs
        for(int i = 0; i < 6; i++) {
            cin >> marks[i];
            sum += marks[i];
        }
        
        //Assigning the current ID
        cur_id = student_id;
        student_id++;
    }
    
    void putdata() {
        //Print name, age and sum for the derived class
        cout << name << " " << age << " " << sum << " " << cur_id << endl;
    }
    
private:    
    int marks[6], cur_id, sum;
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
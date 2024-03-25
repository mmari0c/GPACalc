#include <iostream>
#include <vector>
#include <fstream>
#include "CGPACalc.h"

using namespace std;

int main() {

    vector<course> courses;
    char userOpt;

    loadCourses(courses);
     
    ofstream fout("courses.txt", ios::app);
    if(!fout.is_open()) {
        cout << "Error, could not open text file." << endl; 
        return 0;
    }

    greet();

    while(true) {
        calculateGPA(courses);

        cout << "a. Add Course" << endl;
        cout << "b. Display Courses" << endl;
        cout << "c. Edit Course" << endl;
        cout << "d. Clear Data" << endl;
        cout << "e. Exit" << endl;
        cout << "Enter option: ";
        cin >> userOpt;
        cout << endl;
        
        if(userOpt == 'a') {
            course courseInfo;

            cin.ignore();
            cout << "Enter course name: ";
            getline(cin, courseInfo.name);

            cout << "Enter final grade for " << courseInfo.name << ": ";
            cin >> courseInfo.grade;

            if(courseInfo.grade >= 90) {
                courseInfo.points = 4;
            }
            else if(courseInfo.grade >= 80) {
                courseInfo.points = 3; 
            }
            else if(courseInfo.grade >= 70) {
                courseInfo.points = 2;
            }
            else if(courseInfo.grade >= 60) {
                courseInfo.points = 1;
            }
            else {
                courseInfo.points = 0;
            }

            cout << "Enter credit hours for " << courseInfo.name << ": ";
            cin >> courseInfo.hours;
            cout << endl;

            courseInfo.qp = courseInfo.hours * courseInfo.points;
            fout << courseInfo.name << endl << courseInfo.grade << " " << courseInfo.points << " " << courseInfo.hours << " " << courseInfo.qp << endl;

            courses.push_back(courseInfo);
        }
        
        else if(userOpt == 'b') {
            displayCourses(courses);
        }
    
        else if(userOpt == 'c') {
            editCourses(courses);
        }

        else if(userOpt == 'd') {
            cout << "Clearing data..." << endl;
            courses.clear();            
            ofstream fout("courses.txt");
        }
        
        else if(userOpt == 'e') {
            cout << "See ya next time!" << endl << endl;
            break;
        }

        else {
            cout << "Please input a valid option." << endl << endl;
        }

    }




    




    

    

}
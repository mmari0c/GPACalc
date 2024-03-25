#include <iostream>
#include <fstream>
#include <vector>
#include "CGPACalc.h"

using namespace std;

void greet() {
    cout << endl;
    cout << "=========================" << endl;
    cout << "Cumulative GPA Calculator" << endl;
    cout << "=========================" << endl;
    cout << endl;
    cout << "Track your CGPA by entering course grades and credit hours." << endl;
    cout << "Let the program do the math and simplify your academic journey!" << endl;
    cout << endl;
}

void calculateGPA(vector<course>courses) {

    int totalHours = 0;
    int totalQp = 0;
    double gpa;

    for(int i = 0; i < courses.size(); ++i) {
        totalHours+=courses.at(i).hours;
        totalQp+=courses.at(i).qp;
    }
    gpa = totalQp / static_cast<double>(totalHours);
    cout << "Current GPA = " << gpa << endl;
}

void displayCourses(vector<course>courses) {

    if(courses.size()== 0) {
        cout << "No courses to display!" << endl << endl;
        return;
    }

    for(int i = 0; i < courses.size(); ++i) {
        cout << "Course #" << i + 1 << endl;
        cout << "Name: " << courses.at(i).name << endl;
        cout << "Grade: " << courses.at(i).grade << endl;
        cout << "Credit hours: "  << courses.at(i).hours << endl;
        cout << "QP: " << courses.at(i).qp << endl;
        cout << endl;
    }
}

void loadCourses(vector<course>&courses) {

    ifstream fin("courses.txt");
    if(!fin.is_open()) {
        cout << "No existing data found." << endl;
    }

    courses.clear();

    course courseInfo;
    while (getline(fin, courseInfo.name)) {
        fin >> courseInfo.grade >> courseInfo.points >> courseInfo.hours >> courseInfo.qp;   
        courses.push_back(courseInfo);
        fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }

    fin.close();

}

void editCourses(vector<course>&courses) {
    
    int course;
    char userOpt;

    while(true) {

    displayCourses(courses);
    cout << "Which # course you wish to edit?: ";
    cin >> course;

    // while(true) {

    if(course <= courses.size() && course != 0) {
        cout << "a. Edit Name" << endl;
        cout << "b. Edit Grade" << endl;
        cout << "c. Edit Credit hours" << endl;
        cout << "d. Delete Course" << endl;
        cout << "Enter option: ";
        cin >> userOpt;
        
        if(userOpt == 'a') {
            cout << "Enter new course name: ";
            cin.ignore();
            getline(cin, courses.at(course - 1).name);
        }
        else if(userOpt == 'b') {
            cout << "Enter new grade: ";
            cin >> courses.at(course - 1).grade;

            if(courses.at(course - 1).grade >= 90) {
            courses.at(course - 1).points = 4;
            }
            else if(courses.at(course - 1).grade >= 80) {
                courses.at(course - 1).points = 3; 
            }
            else if(courses.at(course - 1).grade >= 70) {
                courses.at(course - 1).points = 2;
            }
            else if(courses.at(course - 1).grade >= 60) {
                courses.at(course - 1).points = 1;
            }
            else {
                courses.at(course - 1).points = 0;
            }
            courses.at(course - 1).qp = courses.at(course - 1).hours * courses.at(course - 1).points;
        }
        else if(userOpt == 'c') {
            cout << "Enter new credit hours: ";
            cin >> courses.at(course - 1).hours;
            courses.at(course - 1).qp = courses.at(course - 1).hours * courses.at(course - 1).points;
        }
        else if(userOpt == 'd') {
            cout << endl << "Deleting course #" << course - 1 << "..." << endl;
            courses.erase(courses.begin() + course - 1);
        }
        cout << endl;

        cout << "a. Yes" << endl;
        cout << "b. No" << endl;
        cout << "Do you wish to continue making changes?: ";                                                                                                                                    
        cin >> userOpt;
        cout << endl;

        if(userOpt == 'b') {  
            cout << "Updating information..." << endl << endl;
            ofstream fout("courses.txt");

            for(int i = 0; i < courses.size(); ++i) {
            fout << courses.at(i).name << endl << courses.at(i).grade << " " << courses.at(i).points << " " << courses.at(i).hours << " " << courses.at(i).qp << endl;
            }

            break;
        }
        
    

       

        
    }
    else {
        cout << endl << "Please enter a valid option." << endl << endl;
    }

    }

    
    
}
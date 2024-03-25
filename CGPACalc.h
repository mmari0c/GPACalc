#include <iostream>

using namespace std;

struct course {
    string name;
    int grade;
    int hours;
    int points;
    int qp;
};

void greet();
// void saveCourses(course courseInfo, ofstream fout);
void loadCourses(vector<course>&courses);
void calculateGPA(vector<course>courses);
void displayCourses(vector<course>courses);
void editCourses(vector<course>&courses);


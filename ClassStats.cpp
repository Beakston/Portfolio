//
//  ClassStats.cpp
//  Pass6
//
//  Created by Tucker Beals on 10/3/18.
//  Copyright © 2018 Tucker Beals. All rights reserved.
//

#include "ClassStats.hpp"
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

//function prototypes

StudentInfo readStudent(StudentInfo student);

AcademHistory readCourseArray(const int, AcademHistory course[]);

StudentInfo computeGPA(const int, StudentInfo student, AcademHistory []);

void printSummary(const int, StudentInfo student, AcademHistory []);



int main()
{
    //create an object of StudentInfo
    StudentInfo student;
    
        student = readStudent(student);
    
    //Declare a constant variable to count how many classes are being entered
    //for following functions
    const int NumOfCourse = student.getNumOfCourses();
    
    //Dynamically allocate a AcademHistory array object to
    //hold the course information for multiple courses
    AcademHistory *CArray = new AcademHistory[NumOfCourse];
    
    //Return passed array back into main function to be
    //used by other functions
        *CArray = readCourseArray(NumOfCourse, CArray);
        student = computeGPA(NumOfCourse, student, CArray);
    
    //Used to print out a summary of the student and course
    //information given by the user
        printSummary(NumOfCourse, student, CArray);
    
    return 0;
}

//This function intakes the users information and returns the class object
StudentInfo readStudent(StudentInfo studentdeets)
{
    string firstName;
    string lastName;
    string aNumber;
    int NumOfCourse;

    cout << "- - - APSU's GPA Tool - - -\n\n";
    
    cout << "Enter student A-Number: ";
    cin >> aNumber;
    studentdeets.setaNum(aNumber);
    
    cout << "Enter student first name: ";
    cin >> firstName;
    studentdeets.setfirstName(firstName);
    
    cout << "Enter student last name: ";
    cin >> lastName;
    studentdeets.setlastName(lastName);
    
    cout << "Enter student number of courses: ";
    cin >> NumOfCourse;
    cout << endl;
    studentdeets.setNumOfCourses(NumOfCourse);
    
    return studentdeets;
}

//This function reads in the previously defined amount of courses
//The user wishes to provide information for
AcademHistory readCourseArray(int num, AcademHistory course[])
{
    int courseNum;
    string courseName;
    int credHrs;
    char grade;

    
    for (int x = 0; x < num; x++)
    {
        //Intake course ID number
        cout << "Enter class " << x+1 << " number: ";
        cin >> courseNum;
        course[x].setcourseNum(courseNum);
    
        cin.ignore();
        
        //Intake course title
        cout << "Enter class " << x+1 << " name: ";
        getline(cin,courseName);
        course[x].setcourseName(courseName);
        
        //Intake number of credit hours the class is worth
        cout << "Enter class " << x+1 << " hours: ";
        cin >> credHrs;
        course[x].setcredHrs(credHrs);
        
        //Enter the final grade the user received from this course
        cout << "Enter class " << x+1 << " letter grade: ";
        cin >> grade;
        course[x].setgrade(grade);
        cout << endl;
    }
    return *course;
}

//This function takes the final grades from the previous function,
//takes into account how many credit hours each letter grade is worth,
//and does the calculation to get the final GPA for the courses provided
StudentInfo computeGPA(const int num, StudentInfo student, AcademHistory courseInfo[])
{
    double cgrade = 0;
    double totcredhr = 0;
    double totalpoints = 0;
    double gpa = 0;
    
    for (int x = 0; x < num; x++)
    {
        if (courseInfo[x].getgrade() == 'A')
            cgrade = 4;
        else if (courseInfo[x].getgrade() == 'B')
                cgrade = 3;
        else if (courseInfo[x].getgrade() == 'C')
                cgrade = 2;
        else if (courseInfo[x].getgrade() == 'D')
                cgrade = 1;
        else if (courseInfo[x].getgrade() == 'F')
                cgrade = 0;
            else
            {
                cgrade = 0;
            }
        
        totcredhr = totcredhr + courseInfo[x].getcredHrs();
        
        totalpoints += cgrade * (courseInfo[x].getcredHrs());
        
        cgrade = 0;
    }
    gpa = (totalpoints/totcredhr);
    
    student.setGPA(gpa);
    
    return student;
 }


//This function outputs all the data that was requested of the user
//as well as the calculated GPA in an organised form
void printSummary(const int num, StudentInfo student, AcademHistory course[])
{
    cout << "- - - - - - - - - - - - - - - - - -\n";
    cout  << "GRADE REPORT\n\n";
    cout << "STUDENT\n";
    cout << "A-NUMBER\tNAME\t\t\t\tNUM COURSES\tGPA\n";
    cout << student.getANum() << "\t";
    cout << student.getfirstName() << " ";
    cout << student.getlastName() << "\t\t";
    cout << student.getNumOfCourses() << "\t\t\t";
    cout << setprecision(3) << student.getGPA() << endl << endl;
    
    cout << "COURSES\n";
    cout << "NUMBER\tNAME\t\t\t\t\tHOURS\tGRADE\tPOINTS\n";
    int cgrade = 0;
    for (int x = 0; x < num; x++)
    {
        cout << course[x].getcourseNum() <<"\t";
        cout << left;
        cout << setw(22)<< course[x].getcourseName() <<"\t";
        cout << course[x].getcredHrs() <<"\t\t";
        cout << course[x].getgrade() <<"\t\t";
        
        if (course[x].getgrade() == 'A')
            cgrade = 4;
        else if (course[x].getgrade() == 'B')
            cgrade = 3;
        else if (course[x].getgrade() == 'C')
            cgrade = 2;
        else if (course[x].getgrade() == 'D')
            cgrade = 1;
        else if (course[x].getgrade() == 'F')
            cgrade = 0;
        else
        {
            cgrade = 0;
        }
        cout << cgrade << endl << endl;
    }
    
    cout << "END OF GRADE REPORT\n- - - - - - - - - - - - - - - - - - -" << endl << endl;
    cout << "For additional software development services, contact Tucker Beals, CEO, Awesome Software, LLC 1-800-657-5309";
    
}
//Deconstructor
StudentInfo::~StudentInfo()
{
    
}

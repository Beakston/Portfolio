//
//  ClassStats.hpp
//  Pass6
//
//  Created by Tucker Beals on 10/3/18.
//  Copyright © 2018 Tucker Beals. All rights reserved.
//

#ifndef ClassStats_hpp
#define ClassStats_hpp

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class AcademHistory;

class StudentInfo
{
private:
    string firstName;
    string lastName;
    string aNumber;
    int NumOfCourse;
    double Gpa;
public:
        
   int *courses;
    
    string getfirstName()
    {
        return firstName;
    }
    string getlastName()
    {
        return lastName;
    }
    string getANum()
    {
        return aNumber;
    }
    int getNumOfCourses()
    {
        return NumOfCourse;
    }
    double getGPA()
    {
        return Gpa;
    }
    
    StudentInfo()
    {
        firstName = " ";
        lastName = " ";
        aNumber = " ";
        Gpa = 0;
    }
    
    ~StudentInfo();
    
    void setfirstName(string fname)
    {
        firstName = fname;
    }
    void setlastName(string lname)
    {
        lastName = lname;
    }
    void setaNum(string anum)
    {
        aNumber = anum;
    }
   
    void setGPA(double gpa)
    {
        Gpa = gpa;
    }
    void setNumOfCourses(int Nums)
    {
        NumOfCourse = Nums;
    }
   

    
};
    class AcademHistory
{
private:
    int courseNum;
    string courseName;
    int credHrs;
    char grade;
    
public:
    friend class StudentInfo;
    int getcourseNum()
    {
        return courseNum;
    }
    string getcourseName()
    {
        return courseName;
    }
    int getcredHrs()
    {
        return credHrs;
    }
    char getgrade()
    {
        return grade;
    }
    
    AcademHistory()
    {
        courseNum =0;
        courseName = "a";
        credHrs = 0;
        grade = 'E';
    }
    void setcourseNum(int num)
    {
        courseNum = num;
    }
    void setcourseName(string cname)
    {
        courseName = cname;
    }
    void setcredHrs(int hr)
    {
        credHrs = hr;
    }
    void setgrade(char grd)
    {
        grade = grd;
    }
   
    ~AcademHistory()
    {
        
    }
};


#endif /* ClassStats_hpp */

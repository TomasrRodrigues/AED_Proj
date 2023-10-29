//
// Created by Tomás Rodrigues on 29/10/2023.
//

#ifndef PROJETO_AED_STUDENTS_H
#define PROJETO_AED_STUDENTS_H


#include <string>
#include <vector>
#include "Classes.h"

//Definition of class Students
//This class has as arguments the Student's name, code and the classes he's in
//All the functions to change, add, remove UCs (management) are going to be defined here.

class Students {
private:
    std::string StudentName;
    std::string StudentCode;
    std::vector<Classes> Classes;
public:
    //Constructors Definition
    Students();
    Students(std::string studentCode, std::string studentName);

    //Getters Definition
    std::string getStudentName();
    std::string getStudentCode();
    std::vector<Classes> getClasses();


    //Managing functions definition
    void AddClass(Classes newClass);
    Classes ChangeClass(Classes newClass);

    void RemoveUC(std::string ucCode);
    void addUC(Classes newClass);

    bool IsInClass(std::string UCCode);
    Classes FindClass(std::string UCCode);
};


#endif //PROJETO_AED_STUDENTS_H

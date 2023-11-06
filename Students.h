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
    std::vector<Classes> classes;
public:
    //Constructors Definition
    Students();

    Students(const std::string &studentCode, const std::string &studentName);

    //Getters Definition
    std::string getStudentName() const;
    std::string getStudentCode() const;
    std::vector<Classes> getClasses() const;


    //Managing functions definition
    void AddClass(const Classes &newClass);
    Classes ChangeClass(const Classes &newClass);

    void RemoveUC(const std::string &ucCode);
    void addUC(const Classes &newClass);

    bool IsInClass(const std::string &UCCode) const;
    Classes FindClass(const std::string &UCCode) const;

    bool operator == (const Students &other) const;
    bool operator < (const Students &other) const;
    bool operator > (const Students &other) const;

};


#endif //PROJETO_AED_STUDENTS_H

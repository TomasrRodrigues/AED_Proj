//
// Created by Tomás Rodrigues on 29/10/2023.
//

#include "ClassSchedule.h"

#include "Classes.h"

#include <iostream>
#include <algorithm>
#include <set>

ClassSchedule::ClassSchedule(){this->classes = Classes(); this->ClassTime = std::vector<ClassTimeBlock>();}

ClassSchedule::ClassSchedule(const Classes &ucclass){this->classes=ucclass; this->ClassTime=std::vector<ClassTimeBlock>();}
ClassSchedule::ClassSchedule(const std::string &ucCode, const std::string &classCode){this->classes=Classes(ucCode, classCode); this->ClassTime=std::vector<ClassTimeBlock>();}


Classes ClassSchedule::getClasses() const {return classes;}
const std::vector<ClassTimeBlock> &ClassSchedule::getClassTime() const{return ClassTime;}
std::set<Students> ClassSchedule::getStudents() const{return StudentsSet;}
int ClassSchedule::getStudentsNumber() const {return StudentsSet.size();}


void ClassSchedule::addClassTimeBlock(const ClassTimeBlock &classtimeblock){ClassTime.push_back(classtimeblock);}
void ClassSchedule::addStudent(const Students &student){StudentsSet.insert(student);}
void ClassSchedule::removeStudent(const Students &student){StudentsSet.erase(student);}
bool ClassSchedule::sameUcId(const ClassSchedule &other) const{return classes.SameUC(other.getClasses());}

bool ClassSchedule::operator < (const ClassSchedule &other) const {
    return this->classes < other.getClasses();
}

bool ClassSchedule::operator == (const ClassSchedule &other) const {
    return this->classes == other.getClasses();
}

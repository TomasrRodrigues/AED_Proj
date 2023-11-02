//
// Created by Tomás Rodrigues on 29/10/2023.
//

#include "ClassSchedule.h"
#include <iostream>
#include <algorithm>
#include <set>

ClassSchedule::ClassSchedule(){this->classes = Classes(); this->ClassTime = std::vector<ClassTimeBlock>();}
ClassSchedule::ClassSchedule(Classes ucclass){this->classes=ucclass; this->ClassTime=std::vector<ClassTimeBlock>();}
ClassSchedule::ClassSchedule(std::string ucCode, std::string classCode){this->classes=Classes(ucCode, classCode); this->ClassTime=std::vector<ClassTimeBlock>();}


Classes ClassSchedule::getClasses(){return classes;}
std::vector<ClassTimeBlock> ClassSchedule::getClassTime(){return ClassTime;}
std::set<Students> ClassSchedule::getStudents(){return StudentsSet;}
int ClassSchedule::getStudentsNumber(){return StudentsSet.size();}


void ClassSchedule::addClassTimeBlock(ClassTimeBlock classtimeblock){ClassTime.push_back(classtimeblock);}
void ClassSchedule::addStudent(Students student){StudentsSet.insert(student);}
void ClassSchedule::removeStudent(Students student){StudentsSet.erase(student);}
bool ClassSchedule::sameUcId(ClassSchedule other){return classes.SameUC(other.getClasses());}
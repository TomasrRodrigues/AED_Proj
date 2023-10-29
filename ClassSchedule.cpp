//
// Created by Tomás Rodrigues on 29/10/2023.
//

#include "ClassSchedule.h"

ClassSchedule::ClassSchedule(){this->classes = Classes(); this->ClassTime = vector<ClassTimeBlock>();}
ClassSchedule::ClassSchedule(Classes ucclass){this->classes=ucclass; this->ClassTime=vector<ClassTimeBlock>();}
ClassSchedule::ClassSchedule(std::string ucCode, std::string classCode){this->classes=Classes(ucCode, classCode); this->ClassTime=vector<ClassTimeBlock>();}


Classes ClassSchedule::getClasses(){return classes;}
std::vector<ClassTimeBlock> ClassSchedule::getClassTime(){return ClassTime;}
std::set<Students> ClassSchedule::getStudents(){return Students;}
int ClassSchedule::getStudentsNumber(){return Students.size();}


void ClassSchedule::addClassTimeBlock(ClassTimeBlock classtimeblock){ClassTime.push_back(classtimeblock);}
void ClassSchedule::addStudent(Students student){Students.insert(student);}
void ClassSchedule::removeStudent(Students student){Students.erase(student);}
bool ClassSchedule::sameUcId(ClassSchedule other){return classes.SameUC(other.getClasses());}
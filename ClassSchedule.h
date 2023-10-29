//
// Created by Tomás Rodrigues on 29/10/2023.
//

#ifndef PROJETO_AED_CLASSSCHEDULE_H
#define PROJETO_AED_CLASSSCHEDULE_H

#include <vector>
#include <set>
#include "ClassTimeBlock.h"
#include "Classes.h"
#include "Students.h"

class ClassSchedule {
private:
    Classes classes;
    std::vector<ClassTimeBlock> ClassTime;
    std::set<Students> Students;
public:
    ClassSchedule();
    ClassSchedule(Classes ucclass);
    ClassSchedule(std::string ucCode, std::string classCode);


    Classes getClasses();
    std::vector<ClassTimeBlock> getClassTime();
    std::set<Students> getStudents();
    int getStudentsNumber();


    void addClassTimeBlock(ClassTimeBlock classtimeblock);
    void addStudent(Students student);
    void removeStudent(Students student);
    bool sameUcId(ClassSchedule other);
};


#endif //PROJETO_AED_CLASSSCHEDULE_H

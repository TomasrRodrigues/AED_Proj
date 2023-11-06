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
    std::set<Students> StudentsSet;
public:
    ClassSchedule();

    ClassSchedule(const Classes &ucclass);
    ClassSchedule(const std::string &ucCode,const std::string &classCode);


    Classes getClasses() const;
    const std::vector<ClassTimeBlock> &getClassTime() const;
    std::set<Students> getStudents() const;
    int getStudentsNumber() const;


    void addClassTimeBlock(const ClassTimeBlock &classtimeblock);
    void addStudent(const Students &student);
    void removeStudent(const Students &student);
    bool sameUcId(const ClassSchedule &other) const;

    bool operator < (const ClassSchedule &other) const;
    bool operator == (const ClassSchedule &other) const;
};


#endif //PROJETO_AED_CLASSSCHEDULE_H

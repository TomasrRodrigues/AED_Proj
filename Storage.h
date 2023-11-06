//
// Created by Tomás Rodrigues on 05/11/2023.
//

#ifndef PROJETO_AED_STORAGE_H
#define PROJETO_AED_STORAGE_H
#include "Students.h"
#include "ClassSchedule.h"
#include "Requests.h"


class Storage {
private:
    std::set<Students> allStudents;
    std::vector<ClassSchedule> allClassSchedules;
public:
    Storage();

    void readFiles();
    void createSchedules();
    void setSchedules();
    void createStudents();


    unsigned long searchSchedules(const Classes &desiredUcClass) const;
    Students* findStudent(const std::string &studentcode) const;
    ClassSchedule* findClassSchedule(const Classes &ucclass) const;
    std::vector<ClassSchedule> ClassesOfUC(const std::string &ucID) const;
    std::vector<Students> StudentsOfUC(const std::string &ucID) const;
    int GetNumberOfStudentsUc(const std::string &ucID) const;
    int getNumberOfStudentsClass(const Classes &ucclass) const;
    Classes getPreviousClass(const Requests &request) const;
    void WriteFiles();


};


#endif //PROJETO_AED_STORAGE_H

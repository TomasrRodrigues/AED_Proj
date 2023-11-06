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

    unsigned long searchSchedules(Classes desiredUcClass);
    Students findStudent(std::string studentcode);
    ClassSchedule* findClassSchedule(Classes ucclass);
    std::vector<ClassSchedule> ClassesOfUC(std::string ucID);
    std::vector<Students> StudentsOfUC(std::string ucID);
    int GetNumberOfStudentsUc(std::string ucID);
    int getNumberOfStudentsClass(Classes ucclass);
    Classes getPreviousClass(Requests request);
    void WriteFiles();


};


#endif //PROJETO_AED_STORAGE_H

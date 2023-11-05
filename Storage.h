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
    std::set<ClassSchedule> allClassSchedules;
public:
    Storage();

    void readFiles();
    void createSchedules();
    void setSchedules();
    void createStudents();

    void searchSchedules(Classes desiredUcClass);
    Students findStudent(std::string studentcode);
    ClassSchedule fincClassSchedule(std::string ucclass);
    std::vector<ClassSchedule> ClassesOfUC(std::string ucID);
    std::vector<Students> StudentsOfUC(std::string ucID);
    int GetNumberOfStudentsUc(std::string ucID);
    int getNumberOfStudentsClass(std::string ucclassCode);
    Classes getPreviousClass(Requests request);


};


#endif //PROJETO_AED_STORAGE_H

//
// Created by Tomás Rodrigues on 05/11/2023.
//

#include "Storage.h"
#include <iostream>
#include <fstream>
#include <sstream>

Storage::Storage(){
    this->allStudents=std::set<Students>();
    this->allClassSchedules=std::set<ClassSchedule>();
}

void Storage::readFiles(){
    createSchedules();
    setSchedules();
    createStudents();
}

void Storage::createSchedules(){
    fstream file("../Excel_DATA/classes_per_uc.csv");
    file.ignore(1000,'\n');
    std::vector<std::string> row;
    std::string line, word;
    while (getline(file, line)){
        if(line[line.size()-1]=='\r')
            line.resize(line.size()-1);
        row.clear()
        stringstream str(line);
        while (getline(str, word, ','))
            row.push_back(word);
        Classes Classe(row[0], row[1]);
        ClassSchedule cs(Classe);
        allClassSchedules.push_back(cs);
    }
}

void Storage::setSchedules(){
    fstream file("../Excel_DATA/classes.csv");
    file.ignore(1000,'\n');
    std::vector<std::string> row;
    std::string line, word;
    while (getline(file, line)){
        if(line[line.size()-1]=='\r')
            line.resize(line.size()-1);
        stringstream str(line);
        while (getline(str, word, ','))
            row.push_back(word);
        std::string classid=row[0], ucid=row[1], weekday=row[2], starttime=row[3], duration=row[4], type=row[5];
        Classes classese (ucid, classid);
        ClassTimeBlock classtimeblock(weekday, std::stof(starttime), std::stof(duration), type);
        unsigned long scheduleind = searchSchedules(classese);
        if (scheduleind!=-1){
            schedules[scheduleind].addClassTimeBlock(slot);
        }
    }
}

void Storage::createStudents();

void Storage::searchSchedules(Classes desiredUcClass);
Students Storage::findStudent(std::string studentcode);
ClassSchedule Storage::fincClassSchedule(std::string ucclass);
std::vector<ClassSchedule> Storage::ClassesOfUC(std::string ucID);
std::vector<Students> Storage::StudentsOfUC(std::string ucID);
int Storage::GetNumberOfStudentsUc(std::string ucID);
int Storage::getNumberOfStudentsClass(std::string ucclassCode);
Classes Storage::getPreviousClass(Requests request);
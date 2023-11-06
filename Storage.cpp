//
// Created by Tomás Rodrigues on 05/11/2023.
//

#include "Storage.h"
#include <iostream>
#include <fstream>
#include <sstream>


Storage::Storage(){
    this->allStudents = std::set<Students>();
    this->allClassSchedules = std::vector<ClassSchedule>();
}



void Storage::readFiles(){
    createSchedules();
    setSchedules();
    createStudents();
}



void Storage::createSchedules(){
    std::fstream file("../Excel_DATA/classes_per_uc.csv");
    file.ignore(1000,'\n');
    std::vector<std::string> row;
    std::string line, word;
    while (getline(file, line)){
        if(line[line.size()-1]=='\r')
            line.resize(line.size()-1);
        row.clear();
        std::stringstream str(line);
        while (getline(str, word, ','))
            row.push_back(word);
        Classes Classe(row[0], row[1]);
        ClassSchedule cs(Classe);
        allClassSchedules.push_back(cs);
    }
}



void Storage::setSchedules(){
    std::fstream file("../Excel_DATA/classes.csv");
    file.ignore(1000,'\n');
    std::vector<std::string> row;
    std::string line, word;
    while (getline(file, line)){
        if(line[line.size()-1]=='\r')
            line.resize(line.size()-1);
        std::stringstream str(line);
        while (getline(str, word, ','))
            row.push_back(word);
        std::string classid=row[0], ucid=row[1], weekday=row[2], starttime=row[3], duration=row[4], type=row[5];
        Classes classese (ucid, classid);
        ClassTimeBlock classtimeblock(weekday, std::stof(starttime), std::stof(duration), type);
        unsigned long scheduleind = searchSchedules(classese);
        if (scheduleind!=-1){
            allClassSchedules[scheduleind].addClassTimeBlock(classtimeblock);
        }
    }
}



void Storage::createStudents(){
    std::fstream file("../Excel_DATA/students_classes.csv");
    file.ignore(1000,'\n');
    std::vector<std::string> row;
    std::string line, word;
    while (getline(file, line)) {
        row.clear();
        if (line[line.size() - 1] == '\r')
            line.resize(line.size() - 1);
        std::stringstream str(line);
        while (getline(str, word, ','))
            row.push_back(word);
        std::string id= row[0], name= row[1];

        Classes newClass = Classes(row[2], row[3]);
        unsigned long i = searchSchedules(newClass);
        Students students(id, name);

        if(allStudents.find(students)==allStudents.end()){
            students.AddClass(this->allClassSchedules[i].getClasses());
            allStudents.insert(students);
        }
        else{
            auto loc = allStudents.find(students);
            Students modStudent = *loc;
            allStudents.erase(loc);
            modStudent.AddClass(this->allClassSchedules[i].getClasses());
            allStudents.insert(modStudent);
        }
        this->allClassSchedules[i].addStudent(students);
    }
}



unsigned long Storage::searchSchedules(const Classes &desiredUcClass) const{
    unsigned long left=0, right=allClassSchedules.size()-1, middle=(allClassSchedules.size()-1)/2;
    while (left<=right){
        if (allClassSchedules[middle].getClasses() == desiredUcClass){
            return middle;
        } else if(allClassSchedules[middle].getClasses()<desiredUcClass){
            left=middle+1;
        } else{
            right=middle-1;
        }
        middle=(left+right)/2;
    }
    return -1;
}




Students* Storage::findStudent(const std::string &studentcode) const{
    auto student = allStudents.find(Students(studentcode, ""));
    if (student == allStudents.end()) {
        return nullptr;
    } else {
        return const_cast<Students*>(&(*student));
    }
}




ClassSchedule* Storage::findClassSchedule(const Classes &ucclass) const{
    unsigned long index= searchSchedules(ucclass);
    if (index==-1) return nullptr;
    return const_cast<ClassSchedule*>(&allClassSchedules[index]);
}




std::vector<ClassSchedule> Storage::ClassesOfUC(const std::string &ucID) const{
    std::vector<ClassSchedule> classese;
    for (ClassSchedule cs : allClassSchedules){
        if (cs.getClasses().getUCCode() == ucID){
            classese.push_back(cs);
        }
    }
    return classese;
}




std::vector<Students> Storage::StudentsOfUC(const std::string &ucID) const{
    std::vector<Students> ucstudents;
    std::vector<ClassSchedule> ucclasses= ClassesOfUC(ucID);
    for(ClassSchedule &cs : ucclasses){
        for(const Students &student : cs.getStudents()){
            ucstudents.push_back(student);
        }
    }
    return ucstudents;
}




int Storage::GetNumberOfStudentsUc(const std::string &ucID) const{return StudentsOfUC(ucID).size();}



int Storage::getNumberOfStudentsClass(const Classes &ucclass) const{return findClassSchedule(ucclass)->getStudents().size();}



Classes Storage::getPreviousClass(const Requests &request) const{return request.getStudent().FindClass(request.getDesiredClass().getUCCode());}


void Storage::WriteFiles() {
    std::ofstream file;
    file.open("../Excel_DATA/students_classes.csv");
    file << "StudentCode,StudentName,UcCode,ClassCode"<<std::endl;
    for (Students s: allStudents){
        for(Classes c : s.getClasses()){
            file << s.getStudentCode() << "," << s.getStudentName() << "," << c.getUCCode() << "," << c.getClassCode() << std::endl;
        }
    }
    file.close();
}
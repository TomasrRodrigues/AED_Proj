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



void Storage::createStudents(){
    fstream file("../Excel_DATA/students_classes.csv");
    file.ignore(1000,'\n');
    std::vector<std::string> row;
    std::string line, word;
    while (getline(file, line)) {
        row.clear()
        if (line[line.size() - 1] == '\r')
            line.resize(line.size() - 1);
        stringstream str(line);
        while (getline(str, word, ','))
            row.push_back(word);
        std::string id= row[0], name= row[1];

        Classes newClass = Classes(row[2], row[3]);
        unsigned long i = searchSchedules(newClass);
        Students students(id, name);

        if(allStudents.find(student)==allStudents.end()){
            students.AddClass(this->allClassSchedules[i].getClasses());
            allStudents.insert(student);
        }
        else{
            auto loc = allStudents.find(student);
            Students modStudent = *loc;
            students.erase(loc);
            modStudent.AddClass(this->allClassSchedules[i].getClasses());
            allStudents.insert(modStudent);
        }
        this->allClassSchedules[i].addStudent(student);
    }
}



unsigned long Storage::searchSchedules(Classes desiredUcClass){
    unsigned long left=0, right=allClassSchedules.size()-1, middle=(allClassSchedules.size()-1)/2;
    while (left<=right){
        if (schedules[middle].getClasses()==desiredUcClass){
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



Students Storage::findStudent(std::string studentcode){
    auto student = allStudents.find(Student(studentcode, ""));
    return student = students.end() ? nullptr : const_cast<Student*>(&(*student));
}



ClassSchedule Storage::findClassSchedule(std::string ucclass){
    unsigned long index= searchSchedules(ucclass);
    if (index==-1) return nullptr;
    return const_cast<ClassSchedule*>(&allClassSchedules[index]);
}



std::vector<ClassSchedule> Storage::ClassesOfUC(std::string ucID){
    std::vector<ClassSchedule> classese;
    for (const ClassSchedule &cs : allClassSchedules){
        if (cs.getClasses().getUcCode() == ucID){
            classese.push_back(cs);
        }
    }
    return classese;
}



std::vector<Students> Storage::StudentsOfUC(std::string ucID){
    std::vector<Students> ucstudents;
    std::vector<ClassSchedule> ucclasses= ClassesOfUC(ucID);
    for(const ClassSchedule &cs : ucclasses){
        for(const Student &student : cs.getStudents()){
            ucstudents.push_back(student);
        }
    }
    return ucstudents;
}

int Storage::GetNumberOfStudentsUc(std::string ucID){return StudentsOfUC(ucID).size();}



int Storage::getNumberOfStudentsClass(std::string ucclassCode){return findClassSchedule(ucclassCode)->getStudents().size();}



Classes Storage::getPreviousClass(Requests request){return request.getStudent().findClass(request.getDesiredClass().getUCCode());}

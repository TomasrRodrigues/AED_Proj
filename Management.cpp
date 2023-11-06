//
// Created by Tomás Rodrigues on 05/11/2023.
//

#include "Management.h"
#include "ClassSchedule.h"
#include "Storage.h"
#include "ClassTimeBlock.h"
#include "Students.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <unordered_map>
#include <cmath>
#include <csignal>

Management::Management(){
    this->pendingRequests = std::queue<Requests>();
    this->rejectedRequests =  std::vector<std::pair<Requests, std::string>>();
    this->successfulChanges = std::vector<Requests>();
}

void Management::addRequest(Requests request){pendingRequests.push(request);}

bool Management::ClassesOverlap(Classes c1, Classes c2, Storage storage){
    if (c1.SameUC(c2)) return false;
    ClassSchedule *cs1 = storage.findClassSchedule(c1);
    ClassSchedule *cs2 = storage.findClassSchedule(c2);
    for (ClassTimeBlock ctm1: cs1->getClassTime()){
        for (ClassTimeBlock ctm2: cs2->getClassTime()){
            if(ctm1.Overlapping(ctm2)) return true;
        }
    }
    return false;
}

bool Management::requestCollision(Requests request, Storage storage){
    Students student = request.getStudent();
    Classes desiredclass = request.getDesiredClass();
    std::vector<Classes> studentclasses = student.getClasses();
    for (Classes classese : studentclasses){
        if (ClassesOverlap(classese, desiredclass, storage)) return true;
    }
    return false;
}

bool Management::requestExceedsCap(Requests request, Storage storage){
    std::vector<ClassSchedule> classesuc = storage.ClassesOfUC(request.getDesiredClass().getUCCode());
    std::sort(classesuc.begin(), classesuc.end(), [](ClassSchedule c1, ClassSchedule c2){return c1.getStudents().size() < c2.getStudents().size();});
    int cap = classesuc.back().getStudentsNumber();
    if (classesuc[0].getStudentsNumber()==cap) cap++;
    return cap < storage.getNumberOfStudentsClass(request.getDesiredClass())+1;
}

bool Management::requestDisequilibrium(Requests request, Storage storage){
    int studentsnumPREVclass = storage.getNumberOfStudentsClass(storage.getPreviousClass(request)) -1;
    int studentsnumNEWclass = storage.getNumberOfStudentsClass(request.getDesiredClass()) +1;
    return (studentsnumNEWclass)- (studentsnumPREVclass)>=4;
}

void Management::ChangeRequest(Requests request, Storage storage){
    if (requestCollision(request, storage)){rejectedRequests.emplace_back(request, "Schedule collision");}
    else if (requestExceedsCap(request, storage)){rejectedRequests.emplace_back(request, "Cap Exceeded");}
    else if (requestDisequilibrium(request, storage)){rejectedRequests.emplace_back(request, "Classes Disequilibrium");}
    else{
        Students* student = storage.findStudent(request.getStudent().getStudentCode());
        Classes classese = storage.findClassSchedule(request.getDesiredClass())->getClasses();
        Classes oldclass = student->ChangeClass(classese);
        storage.findClassSchedule(request.getDesiredClass())->addStudent(*student);
        storage.findClassSchedule(oldclass)->removeStudent(*student);
        successfulChanges.push_back(request);
    }
}


void Management::RemoveRequest(Requests request, Storage storage){
    Students* student=storage.findStudent(request.getStudent().getStudentCode());
    Classes classese = storage.findClassSchedule(request.getDesiredClass())->getClasses();
    student->RemoveUC(classese.getUCCode());
    storage.findClassSchedule(classese)->removeStudent(*student);
    successfulChanges.push_back(request);
}


void Management::EnrollmentRequest(Requests request, Storage storage){
    if (requestCollision(request, storage)){rejectedRequests.emplace_back(request, "Schedule collision");}
    else if (requestExceedsCap(request, storage)){rejectedRequests.emplace_back(request, "Cap Exceeded. Choose another class");}
    else{
        Students* student = storage.findStudent(request.getStudent().getStudentCode());
        Classes classes = storage.findClassSchedule(request.getDesiredClass())->getClasses();
        student->addUC(classes);
        storage.findClassSchedule(classes)->addStudent(*student);
        successfulChanges.push_back(request);
    }
}


//void Management::processRequest(){}

//void Management::WriteFiles();
void Management::printSuccessfulRequests(){
    std::cout << "Succesful Requests: " << std::endl;
    for (Requests request : successfulChanges){
        std::cout << "Name: " << request.getStudent().getStudentName() << std::endl;
        std::cout << "Request Type: " << request.getType() << std::endl;
        std::cout << "Class: " << request.getDesiredClass().getClassCode() << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}


void Management::printRejectedRequests(){
    std::cout << "Rejected Requests: " << std::endl;
    for (std::pair<Requests, std::string> request: rejectedRequests){
        std::cout << "Name: " << request.first.getStudent().getStudentName() << std::endl;
        std::cout << "Request Type: " << request.first.getType() << std::endl;
        std::cout << "Class: " << request.first.getDesiredClass().getClassCode() << std::endl;
        std::cout << "Reason: " << request.second << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

std::string decimalToHours(int decimal){
    double time= decimal;
    int timeMins =(int) floor(time*60.0);
    int hours = timeMins/60;
    int minutes =timeMins%60;
    std::string hoursStr = std::to_string(hours);
    std::string minutesSTr = std::to_string(minutes);
    if (hours<10) hoursStr="0"+hoursStr;
    if (minutes<10) minutesSTr="0"+minutesSTr;
    return hoursStr+":"+minutesSTr;
}




std::string ucIdToString(const std::string ucID){
    std::map<std::string, std::string> name = {{"L.EIC001", "ALGA"}, {"L.EIC002", "AM I"}, {"L.EIC003", "FP"}, {"L.EIC004", "FSC"}, {"L.EIC005", "MD"}, {"L.EIC011", "AED"}, {"L.EIC012", "BD"}, {"L.EIC013", "F II"}, {"L.EIC014", "LDTS"}, {"L.EIC015", "SO"}, {"L.EIC021", "FSI"}, {"L.EIC022", "IPC"}, {"L.EIC023", "LBAW"}, {"L.EIC024", "PFL"}, {"L.EIC025", "RC"}};
    return name[ucID];
}



struct compareDayWeek{
    bool operator()(const std::string d1, const std::string d2) const{
        std::map<std::string,int> days = {{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}, {"Saturday", 6}, {"Sunday", 7}};
        return days[d1] < days[d2];
    }
};




void Management::printStudentSchedule(const std::string studentid, Storage storage) const{
    Students* student = storage.findStudent(studentid);
    if (student == nullptr){
        std::cout << "Student not found!" << std::endl;
        return;
    }

    std::map<std::string, std::map<ClassTimeBlock, std::vector<std::string>>, compareDayWeek> weekdayClassTimeBlock;

    std::vector<Classes> studentClasses = student->getClasses();

    for (const Classes &classes : studentClasses){
        ClassSchedule *cs = storage.findClassSchedule(classes);
        for(const ClassTimeBlock &ctb: cs->getClassTime()){
            weekdayClassTimeBlock[ctb.getWeekDay()][ctb].push_back(classes.getUCCode());
        }
    }

    /*std::cout << std::endl << "The student " << student.getStudentName() << " (UP" << student.getStudentCode() << ") is enrolled in classes:" << std::endl << "   ";
    student->printClasses();*/

    for (auto weekday : weekdayClassTimeBlock){
        std::cout << "   >> " << weekday.first << ": " << std::endl;
        for (const auto &ctb: weekday.second){
            std::cout << "     " << decimalToHours(ctb.first.getStartTime()) << " to " << decimalToHours(ctb.first.getEndTime()) << "\t" << ctb.first.getType() << "\t";
            for (std::string classid : ctb.second){
                std::cout << ucIdToString(classid) << " - " << classid <<" ";
            }
            std::cout << std::endl;
        }
    }
}


void Management::processRequest(Storage storage){

    while(!pendingRequests.empty()){
        Requests request=pendingRequests.front();
        if (request.getType()=="Change"){
            ChangeRequest(request, storage);
        }
        else if (request.getType()=="Remove"){
            RemoveRequest(request, storage);
        }
        else if (request.getType()=="Enrollment"){
            EnrollmentRequest(request, storage);
        }
        else{
            printStudentSchedule(request.getStudent().getStudentCode(), storage);
        }
        pendingRequests.pop();
    }
}



/*
void Management::printClassSchedule(std::string classid, Storage storage){
    std::map<std::string, std::map<ClassTimeBlock, std::vector<std::string>>, compareDayWeek> weekdaySlot;
    std::vector<ClassSchedule> schedules=storage.ClassesOfUC();
    for (ClassSchedule cs: schedules)
}
void Management::printUcSchedule(std::string &ucId, Storage storage);
void Management::printClassStudents(Classes classes, std::string orderType, Storage storage);
void Management::printUcStudents(std::string ucId, std::string sortType, Storage storage);*/
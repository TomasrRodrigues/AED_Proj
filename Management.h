//
// Created by Tomás Rodrigues on 05/11/2023.
//

#ifndef PROJETO_AED_MANAGEMENT_H
#define PROJETO_AED_MANAGEMENT_H

#include "Requests.h"
#include "Storage.h"
#include <queue>
#include <vector>
#include <set>
#include <string>

class Management {
private:
    std::queue<Requests> pendingRequests;
    std::vector<std::pair<Requests, std::string>> rejectedRequests;
    std::vector<Requests> successfulChanges;
    /*std::queue<Requests> changingRequests;
    std::queue<Requests> changingRequests;*/
public:
    Management();
    void addRequest(Requests request);
    bool ClassesOverlap(Classes c1, Classes c2, Storage storage);
    bool requestCollision(Requests request, Storage storage);
    bool requestExceedsCap(Requests request, Storage storage);
    bool requestDisequilibrium(Requests request, Storage storage);
    void ChangeRequest(Requests request, Storage storage);
    void RemoveRequest(Requests request, Storage storage);
    void EnrollmentRequest(Requests request, Storage storage);
    //void processRequest();
    //void WriteFiles();
    void printSuccessfulRequests();
    void printRejectedRequests();

    void printStudentSchedule(std::string studentid, Storage storage);

    /*
    void printClassSchedule(std::string classid, Storage storage);
    void printUcSchedule(std::string &ucId, Storage storage);
    void printClassStudents(Classes classes, std::string orderType, Storage storage);
    void printUcStudents(std::string ucId, std::string sortType, Storage storage);*/
};


#endif //PROJETO_AED_MANAGEMENT_H

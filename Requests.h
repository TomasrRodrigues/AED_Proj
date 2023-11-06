//
// Created by Tomás Rodrigues on 05/11/2023.
//

#ifndef PROJETO_AED_REQUESTS_H
#define PROJETO_AED_REQUESTS_H

#include "Students.h"
#include <string>

class Requests {
private:
    Students student;
    Classes Class;
    std::string Type;
public:
    Requests(Students student, Classes desiredClass, std::string type);
    Students getStudent();
    Classes getDesiredClass();
    std::string getType();


};


#endif //PROJETO_AED_REQUESTS_H

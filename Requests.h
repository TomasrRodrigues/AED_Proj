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
    Classes Classe;
    std::string Type;
public:
    Requests(const Students &student,const Classes &desiredClass,const std::string &type);
    Students getStudent() const;
    Classes getDesiredClass() const;
    std::string getType() const;


};


#endif //PROJETO_AED_REQUESTS_H

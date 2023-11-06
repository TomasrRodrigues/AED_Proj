//
// Created by Tomás Rodrigues on 05/11/2023.
//

#include "Requests.h"

Requests::Requests(Students studente, Classes desiredclass, std::string type){
    if (type!= "Change" && type!="Remove" && type!="Enrollment") return;
    this->student= studente;
    this->Class=desiredclass;
    this->Type= type;
}
Students Requests::getStudent(){return student;};
Classes Requests::getDesiredClass(){return Class;};
std::string Requests::getType(){return Type;};

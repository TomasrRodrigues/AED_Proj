//
// Created by Tomás Rodrigues on 05/11/2023.
//

#include "Requests.h"


Requests::Requests(const Students &student,const Classes &desiredClass,const std::string &type){
    if (type!= "Change" && type!="Remove" && type!="Enrollment") return;
    this->student= student;
    this->Classe = desiredClass;
    this->Type= type;
}

Students Requests::getStudent() const {return student;};
Classes Requests::getDesiredClass() const {return Classe;};
std::string Requests::getType() const {return Type;};

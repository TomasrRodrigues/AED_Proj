//
// Created by Tomás Rodrigues on 29/10/2023.
//

#include "Classes.h"
#include <map>

//Constructors Definition
Classes::Classes(){this->UCCode=""; this->ClassCode="";}

Classes::Classes(const std::string &uccode, const std::string &classcode){this->UCCode=uccode; this->ClassCode=classcode;}

//Getters Definition
std::string Classes::getUCCode() const{return UCCode;}
std::string Classes::getClassCode() const{return ClassCode;}

//std::string Classes::UCCodetoString() const {}
//Other functions
bool Classes::SameUC(const Classes &otherClass) const{return this->UCCode==otherClass.UCCode;}

bool Classes::operator == (const Classes &other) const {
    return this->UCCode == other.UCCode && this->ClassCode == other.ClassCode;
}



bool Classes::operator < (const Classes &other) const {
    if(this->UCCode == other.UCCode) return this->ClassCode < other.ClassCode;
    return this->UCCode < other.UCCode;
}



bool Classes::operator > (const Classes &other) const {
    if(this->UCCode == other.UCCode) return this->ClassCode > other.ClassCode;
    return this->UCCode > other.UCCode;
}

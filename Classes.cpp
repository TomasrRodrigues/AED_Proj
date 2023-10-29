//
// Created by Tomás Rodrigues on 29/10/2023.
//

#include "Classes.h"
#include <map>

//Constructors Definition
Classes::Classes(){this->UCCode=""; this->ClassCode="";}
Classes::Classes(std::string uccode, std::string classcode){this->UCCode=uccode; this->ClassCode=classcode;}

//Getters Definition
std::string Classes::getUCCode(){return UCCode;}
std::string Classes::getClassCode(){return ClassCode;}

//Other functions
bool Classes::SameUC(Classes otherClass){return this->UCCode==otherClass.UCCode;}

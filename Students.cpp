//
// Created by Tomás Rodrigues on 29/10/2023.
//

#include "Students.h"
#include <iostream>
#include<algorithm>


//Constructors definition
Students::Students(){StudentCode=""; StudentName=""; classes=std::vector<Classes>();}
Students::Students(std::string studentCode, std::string studentName){StudentCode=studentCode; StudentName=studentName; classes=std::vector<Classes>();}


//Getters Definition
std::string Students::getStudentName(){return StudentName;}
std::string Students::getStudentCode(){return StudentCode;}
std::vector<Classes> Students::getClasses(){return classes;}


//Managing functions
void Students::AddClass(Classes newClass){classes.push_back(newClass);}

Classes Students::ChangeClass(Classes newClass){
    for (int i=0; i<classes.size(); i++){
        if (classes.at(i).getUCCode()==newClass.getUCCode()){
            Classes OldClass=classes.at(i);
            classes.at(i)=newClass;
            return OldClass;
        }
    }
    return {};
}

void Students::RemoveUC(std::string ucCode){
    for(int i=0; i<classes.size(); i++){
        if(classes.at(i).getUCCode()==ucCode){
            classes.erase(classes.begin() + i);
            break;
        }
    }
}


void Students::addUC(Classes newClass){classes.push_back(newClass); std::sort(classes.begin(), classes.end());}

bool Students::IsInClass(std::string UCCode){
    for (int i=0; i<classes.size(); i++){
        if(classes.at(i).getUCCode()==UCCode){
            return true;
        }
    }
    return false;
}


Classes Students::FindClass(std::string UCCode){
    for (Classes i : classes){
        if (i.getUCCode()==UCCode){
            return i;
        }
    }
    return {};
}


bool Students::operator==(Students other) const{
    return this->StudentCode == other.getStudentCode();
}

bool Students::operator<(Students other) const {
    return this->StudentCode < other.getStudentCode();
}

bool Students::operator>(Students other) const {
    return this->StudentCode > other.getStudentCode();
}
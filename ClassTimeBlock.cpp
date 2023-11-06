//
// Created by Tomás Rodrigues on 29/10/2023.
//

#include "ClassTimeBlock.h"

#include <map>



ClassTimeBlock::ClassTimeBlock(){
    WeekDay="";
    StartTime=0;
    EndTime=0;
    Duration=0;
    Type="";
}


ClassTimeBlock::ClassTimeBlock(const std::string weekday,const float starttime,const float duration,const std::string type){

    WeekDay=weekday;
    StartTime=starttime;
    EndTime=starttime+duration;
    Duration=duration;
    Type=type;
}




std::string ClassTimeBlock::getWeekDay() const{return WeekDay;}
float ClassTimeBlock::getStartTime() const{return StartTime;}
float ClassTimeBlock::getDuration() const{return Duration;}
float ClassTimeBlock::getEndTime() const{return EndTime;}
std::string ClassTimeBlock::getType() const{return Type;}



bool ClassTimeBlock::Overlapping(ClassTimeBlock other){
    if (this->WeekDay != other.getWeekDay()){return false;}
    else if (this->StartTime >= other.getStartTime() || this->EndTime <= other.getStartTime()){return false;}
    else if (this->Type=="T" || other.getType()=="T"){return false;}
    return true;

}

bool ClassTimeBlock::operator!=(const ClassTimeBlock &other) const {
    return this->WeekDay != other.getWeekDay() && this->StartTime != other.getStartTime() && this->EndTime != other.getEndTime() && this->Type != other.getType();
}



bool ClassTimeBlock::operator==(const ClassTimeBlock &other) const {
    return this->WeekDay==other.getWeekDay() && this->StartTime == other.getStartTime() && this->EndTime == other.getEndTime() && this->Type == other.getType();
}



bool ClassTimeBlock::operator<(const ClassTimeBlock &other) const {
    if(this->WeekDay != other.getWeekDay()) {
        std::map <std::string, int> days = {{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}, {"Saturday", 6}, {"Sunday", 7}};
        return days[WeekDay] < days[other.getWeekDay()];
    }

    if(this->StartTime == other.getStartTime()){
        if(this->EndTime == other.getEndTime()){
            return this->Type < other.getType();
        }
        return this->EndTime < other.getEndTime();
    }
    return this->StartTime < other.getStartTime();
}
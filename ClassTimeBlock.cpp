//
// Created by Tomás Rodrigues on 29/10/2023.
//

#include "ClassTimeBlock.h"


ClassTimeBlock::ClassTimeBlock(){
    WeekDay="";
    StartTime=0;
    EndTime=0;
    Duration=0;
    Type="";
}

ClassTimeBlock::ClassTimeBlock(std::string weekday, float starttime, float duration, std::string type){
    WeekDay=weekday;
    StartTime=starttime;
    EndTime=starttime+duration;
    Duration=duration;
    Type=type;
}



std::string ClassTimeBlock::getWeekDay(){return WeekDay;}
float ClassTimeBlock::getStartTime(){return StartTime;}
float ClassTimeBlock::getDuration(){return Duration;}
float ClassTimeBlock::getEndTime(){return EndTime;}
std::string ClassTimeBlock::getType(){return Type;}


bool ClassTimeBlock::Overlapping(ClassTimeBlock other){
    if (this->WeekDay != other.getWeekDay()){return false;}
    else if (this->StartTime >= other.getStartTime() || this->EndTime <= other.getStartTime()){return false;}
    else if (this->Type=="T" || other.getType()=="T"){return false;}
    return true;
}
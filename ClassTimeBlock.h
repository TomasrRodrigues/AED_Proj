//
// Created by Tomás Rodrigues on 29/10/2023.
//

#ifndef PROJETO_AED_CLASSTIMEBLOCK_H
#define PROJETO_AED_CLASSTIMEBLOCK_H

#include <string>
#include <vector>

class ClassTimeBlock {
private:
    std::string WeekDay;
    float StartTime;
    float Duration;
    float EndTime;
    std::string Type;
public:
    ClassTimeBlock();
    ClassTimeBlock(std::string weekday, float starttime, float duration, std::string type);
    std::string getWeekDay();
    float getStartTime();
    float getDuration();
    float getEndTime();
    std::string getType();

    bool Overlapping(ClassTimeBlock other);
};


#endif //PROJETO_AED_CLASSTIMEBLOCK_H

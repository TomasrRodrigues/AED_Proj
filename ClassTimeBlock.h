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

    ClassTimeBlock(const std::string weekday, const float starttime, const float duration, const std::string type);
    std::string getWeekDay() const;
    float getStartTime() const;
    float getDuration() const;
    float getEndTime() const;
    std::string getType() const;

    bool Overlapping(ClassTimeBlock other);

    bool operator !=(const ClassTimeBlock &other) const;
    bool operator ==(const ClassTimeBlock &other) const;
    bool operator < (const ClassTimeBlock &other) const;
};


#endif //PROJETO_AED_CLASSTIMEBLOCK_H

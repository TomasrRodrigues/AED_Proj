//
// Created by Tomás Rodrigues on 29/10/2023.
//

#ifndef PROJETO_AED_CLASSES_H
#define PROJETO_AED_CLASSES_H

#include <string>


//Class defined and implemented

class Classes {
private:
    std::string UCCode;
    std::string ClassCode;
public:
    //Constructors definition
    Classes();

    Classes(const std::string &uccode, const std::string &classcode);

    //Getters
    std::string getUCCode() const;
    std::string getClassCode() const;
    //std::string UCCodetoString() const;

    //verify equality between UC's
    bool SameUC(const Classes &otherClass) const;

    bool operator ==( const Classes &other) const;
    bool operator < (const Classes &other) const;
    bool operator > (const Classes &other) const;
};


#endif //PROJETO_AED_CLASSES_H

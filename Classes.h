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
    Classes(std::string uccode, std::string classcode);

    //Getters
    std::string getUCCode();
    std::string getClassCode();

    //verify equality between UC's
    bool SameUC(Classes otherClass);

};


#endif //PROJETO_AED_CLASSES_H

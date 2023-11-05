//
// Created by Tomás Rodrigues on 05/11/2023.
//

#ifndef PROJETO_AED_MANAGEMENT_H
#define PROJETO_AED_MANAGEMENT_H

#include "Requests.h"
#include <queue>
#include <vector>
#include <set>
#include <string>

class Management {
private:
    std::queue<Requests> pendingRequests;
    std::vector<std::pair<Requests, std::string>> rejectedRequests;
    std::vector<Requests> successfulChanges;
    /*std::queue<Requests> changingRequests;
    std::queue<Requests> changingRequests;*/
public:
    Management();

};


#endif //PROJETO_AED_MANAGEMENT_H

#include <iostream>


#include <string>
#include <vector>
#include "Classes.h"
#include "ClassSchedule.h"
#include "ClassTimeBlock.h"
#include "Management.h"
#include "Requests.h"
#include "Students.h"

int main() {
    Storage storage; storage.readFiles();
    Management management;
    bool loopExit = true;
    std::string desiredclassuccode; std::string desiredclassclasscode; std::string studentcode; std::string requesttype; std::string check; std::string check2;
    Classes desiredclass;
    while (loopExit){
        bool addingRequests=true;
        while (addingRequests) {
            std::cout
                    << "Explicit the request by first entering the type of request ('Change', 'Remove', 'Enrollment', 'SeeSchedule') that you want and then the student code and (if it is the case) the desired class."
                    << std::endl;
            std::cout << "Enter the type of request('Change', 'Remove', 'Enrollment', 'SeeSchedule'): ";

            while (true) {
                std::cin >> requesttype;
                std::cout << std::endl;
                if (requesttype == "Change" or requesttype == "Remove" or requesttype == "Enrollment" or requesttype=="SeeSchedule") {
                    break;
                }
            }
            std::cout << "Enter the Student Code (UP*********): ";
            while (true) {
                std::cin >> studentcode;
                std::cout << std::endl;
                if(storage.findStudent(studentcode)!= nullptr) break;
                else {std::cout << "Student Code not found!" << std::endl;}
            }

            if (requesttype != "SeeSchedule") {
                while (true) {
                    std::cout << "Enter the UC Code and then the Class Code of the desired class: ";
                    std::cin >> desiredclassuccode;
                    std::cout << std::endl;
                    std::cin >> desiredclassclasscode;
                    std::cout << std::endl;
                    desiredclass = Classes(desiredclassuccode, desiredclassclasscode);
                    if(storage.findClassSchedule(desiredclass)!=nullptr) break;
                    else{std::cout << "Class not found!" << std::endl;}
                }
                Students student = *storage.findStudent(studentcode);
                Requests request = Requests(student, desiredclass, requesttype);
                management.addRequest(request);
            }
            else{
                Students student = *storage.findStudent(studentcode);
                Classes nullClass=Classes("", "");
                Requests request =Requests(student, nullClass, requesttype);
                management.addRequest(request);
            }


            std::cout <<"Do you want to make any more requests?(y/n): ";
            while(true) {
                std::cin >> check;
                if ((check=="y") or (check=="n")){
                    break;
                }
            }
            if (check=="n") addingRequests=false;
        }
        management.processRequest(storage);
        storage.WriteFiles();
        management.printSuccessfulRequests();
        std::cout << std::endl;
        std::cout << std::endl;
        management.printRejectedRequests();

        std::cout << std::endl;
        std::cout << std::endl;

        std::cout<< "Do you want to make more requests?(y/n): ";
        while (check2!="y" or check2!="n") std::cin >> check2;
        if (check2=="y") loopExit=false;
    }
    return 0;
}

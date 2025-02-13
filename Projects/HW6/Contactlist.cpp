#include "ContactList.h";
std::list<std::string> ContactList::getPhoneList(int category){
    std::list<std::string> returnList;
    for(Contact Cont: contactList){
        if(Cont.category == category){
            std::string TempString = Cont.firstName + " " + Cont.lastName + "\t" + Cont.phoneNumber;
            returnList.push_back(TempString);
        }
    }
    return returnList;
}
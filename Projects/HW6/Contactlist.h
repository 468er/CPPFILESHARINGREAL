
#include <iostream>
#include <list>
class Contact {
    public: 
    int category;
    std::string firstName;
    std::string lastName;
    std::string streetAddress;
    std::string zipCode;
    std::string city;
    std::string phoneNumber;
    Contact(int category, std::string firstName, std::string lastName, std::string streetAddress, std::string zipCode, std::string city, std::string phoneNumber);
    std::string toString();
};
class ContactList{
    public:
        ContactList();
        void add(Contact c);
        void remove(Contact c);
        std::list<std::string>  getPhoneList(int category);
        std::list<std::string> getMailingList(int category);
    private:
        std::list<Contact> contactList;
};

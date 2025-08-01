#include "contact.h"


Contact::Contact(const std::string& _name,const std::string& _phone) : name(_name), phone(_phone) {}

const std::string& Contact::getName() const{
    return name;
}

const std::string& Contact::getPhone() const{

    return phone;
}

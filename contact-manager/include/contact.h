#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact{

    private:
        std::string name;
        std::string phone;

    public:
        Contact(const std::string& _name,const std::string& _phone);
        const std::string& getName() const;
        const std::string& getPhone() const;

};

#endif



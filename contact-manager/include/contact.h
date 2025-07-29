#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact{

    private:
        std::string name;
        std::string phone;

    public:
        const std::string& getName() const;
        const std::string& getPhone() const;

};

#endif



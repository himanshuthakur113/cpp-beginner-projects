#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include "contact.h"
#include <vector>
#include <string>

class ContactManger{

    private:
        std::vector<Contact> contacts;

    public:
        void addContact();
        void viewContacts() const;
        void searchContacts() const;
        void updateContacts();
        void deleteContacts();
        
        void run();
};

#endif

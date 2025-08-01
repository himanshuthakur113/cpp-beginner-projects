#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include "contact.h"
#include <vector>
#include <string>

class ContactManager{

    private:
        std::vector<Contact> contacts;

        void displayMenu() const;

    public:


        void addContact();
        void viewContacts() const;
        void searchContact() const;
        void updateContact();
        void deleteContact();
        
        void run();
};

#endif

#include "contact_manager.h"
#include <iostream>
#include <limits>
#include <cctype>
#include <fstream>


void ContactManager::displayMenu() const {
    std::cout << "\n📞 Contact Manager Menu:" << std::endl;
    std::cout << "1. Add a Contact" << std::endl;
    std::cout << "2. View Contacts" << std::endl;
    std::cout << "3. Search for a Contact" << std::endl;
    std::cout << "4. Update a Contact" << std::endl;
    std::cout << "5. Delete a Contact" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Choose an option (1-6): ";
}


void ContactManager::addContact() {

    std::string name, phone;

    std::cout << "Enter contact name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);

    std::cout << "Enter phone number (10 digits): ";
    std::getline(std::cin, phone);

    if (name.empty()) {
        std::cout << "Error: Contact name cannot be empty." << std::endl;
        return;
    }
    if (phone.size() != 10) {
        std::cout << "Error: Phone number must be exactly 10 digits." << std::endl;
        return;
    }
    for (char c : phone) {
        if (!std::isdigit(c)) {
            std::cout << "Error: Phone number must contain only digits." << std::endl;
            return;
        }
    }

    for (const Contact& c : contacts) { 
        if (c.getName() == name) {
            std::cout << "Error: Contact with name '" << name << "' already exists!" << std::endl;
            return;
        }
    }

    contacts.push_back(Contact(name, phone));
    std::cout << "Contact '" << name << "' added successfully!" << std::endl;
}


void ContactManager::viewContacts() const {
    if (contacts.empty()) {
        std::cout << "No contacts available!" << std::endl;
        return;
    }

    std::cout << "\n--- Contact List ---" << std::endl;
    for (size_t i = 0; i < contacts.size(); ++i) {
        std::cout << i + 1 << ". " << contacts[i].getName() << ": " << contacts[i].getPhone() << std::endl;
    }
    std::cout << "--------------------" << std::endl;
}

void ContactManager::searchContact() const {
    std::string name_to_search;
    std::cout << "Enter the name to search: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name_to_search);

    bool found = false;
    for (const Contact& c : contacts) {
        if (c.getName() == name_to_search) {
            std::cout << "Found: " << c.getName() << ": " << c.getPhone() << std::endl;
            found = true;
            break; 
        }
    }

    if (!found) {
        std::cout << "Contact '" << name_to_search << "' not found!" << std::endl;
    }
}


void ContactManager::updateContact() {
    std::string old_name, new_name, new_phone;
    std::cout << "Enter the contact name to update: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, old_name);

    int found_index = -1; 
    for (size_t i = 0; i < contacts.size(); ++i) {
        if (contacts[i].getName() == old_name) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        std::cout << "Contact found. Enter new details (press Enter to keep current value):" << std::endl;
        std::cout << "Current Name: " << contacts[found_index].getName() << std::endl;
        std::cout << "Enter new name: ";
        std::getline(std::cin, new_name);

        std::cout << "Current Phone: " << contacts[found_index].getPhone() << std::endl;
        std::cout << "Enter new phone number (10 digits): ";
        std::getline(std::cin, new_phone);

        if (!new_name.empty()) {
            std::cout << "Contact '" << old_name << "' updated successfully!" << std::endl;
            std::string final_name = new_name.empty() ? contacts[found_index].getName() : new_name;
            std::string final_phone = new_phone.empty() ? contacts[found_index].getPhone() : new_phone;

            if (!new_phone.empty()) {
                if (new_phone.size() != 10) {
                    std::cout << "Invalid new phone number! Must be 10 digits. Update failed." << std::endl;
                    return;
                }
                for (char c : new_phone) {
                    if (!std::isdigit(c)) {
                        std::cout << "Invalid new phone number! Must contain only digits. Update failed." << std::endl;
                        return;
                    }
                }
            }
            contacts[found_index] = Contact(final_name, final_phone);
            std::cout << "Contact '" << old_name << "' updated successfully to '" << final_name << "'." << std::endl;

        } else {
            std::cout << "Invalid input. No changes made." << std::endl;
        }
    } else {
        std::cout << "Contact '" << old_name << "' not found!" << std::endl;
    }
}


void ContactManager::deleteContact() {
    std::string name_to_delete;
    std::cout << "Enter the name of the contact to delete: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name_to_delete);

    int found_index = -1;
    for (size_t i = 0; i < contacts.size(); ++i) {
        if (contacts[i].getName() == name_to_delete) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        contacts.erase(contacts.begin() + found_index);
        std::cout << "Contact '" << name_to_delete << "' deleted successfully!" << std::endl;
    } else {
        std::cout << "Contact '" << name_to_delete << "' not found!" << std::endl;
    }
}

void ContactManager::run() {
    std::string choice;
    while (true) {
        displayMenu();
        std::getline(std::cin, choice);
        if (choice == "1") {
            addContact();
        } else if (choice == "2") {
            viewContacts();
        } else if (choice == "3") {
            searchContact();
        } else if (choice == "4") {
            updateContact();
        } else if (choice == "5") {
            deleteContact();
        } else if (choice == "6") {
            exitAndSave();
            std::cout << "Exiting Contact Manager. Goodbye!" << std::endl;
        } else {
            std::cout << "Invalid choice! Please enter a number between 1 and 6." << std::endl;
        }
    }
}


void ContactManager::saveContactsToFile() const{

    std::ofstream outputFile("contact.txt");

    if (!outputFile.is_open()){

        std::cout << "File not opened" <<std::endl;

    }else{

        for(auto &i:contacts){
            
            outputFile << i.getName() << "," << i.getPhone() << std::endl;

        }
     
        outputFile.close();
    }
}



void ContactManager::exitAndSave(){
    saveContactsToFile();
    std::cout << "Good BYe!" <<std::endl;
}









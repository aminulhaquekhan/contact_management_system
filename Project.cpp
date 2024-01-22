#include <iostream>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
    Contact* next;
};

class ContactManager {
private:
    Contact* head;

public:
    ContactManager() : head(nullptr) {}

    void addContact(string name, string phoneNumber) {
        Contact* newContact = new Contact;
        newContact->name = name;
        newContact->phoneNumber = phoneNumber;
        newContact->next = head;
        head = newContact;
        cout << "Contact added successfully.\n";
    }

    void displayContacts() {
        Contact* current = head;
        cout << "Contact List:\n";
        while (current != nullptr) {
            cout << "Name: " << current->name << ", Phone Number: " << current->phoneNumber << "\n";
            current = current->next;
        }
        cout << "End of Contact List\n";
    }

    void searchContact(string name) {
        Contact* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                cout << "Contact found - Name: " << current->name << ", Phone Number: " << current->phoneNumber << "\n";
                return;
            }
            current = current->next;
        }
        cout << "Contact not found.\n";
    }


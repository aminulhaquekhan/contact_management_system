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
        }
        cout << "Contact not found.\n";
    }
   void deleteContact(string name) {
        Contact* current = head;
        Contact* prev = nullptr;

        while (current != nullptr) {
            if (current->name == name) {
                if (prev != nullptr) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }

                delete current;
                cout << "Contact deleted successfully.\n";
                return;
            }

            prev = current;
            current = current->next;
        }

        cout << "Contact not found. Deletion failed.\n";
    }


    void editContact(string name, string newPhoneNumber) {
        Contact* current = head;

        while (current != nullptr) {
            if (current->name == name) {
                current->phoneNumber = newPhoneNumber;
                cout << "Contact edited successfully.\n";
                return;
            }

            current = current->next;
        }

        cout << "Contact not found. Edit failed.\n";
    }
};

int main() {
    ContactManager contactManager;

    int choice;
    string name, phoneNumber;

    do {
        cout << "\nContact Management System\n";
        cout << "1. Add a new contact\n";
        cout << "2. List all contacts\n";
        cout << "3. Search for a contact\n";
        cout << "4. Delete a contact\n";
        cout << "5. Edit a contact\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter contact name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter phone number: ";
                getline(cin, phoneNumber);
                contactManager.addContact(name, phoneNumber);
                break;
            case 2:
                contactManager.displayContacts();
                break;
            case 3:
                cout << "Enter contact name to search: ";
                cin.ignore();
                getline(cin, name);
                contactManager.searchContact(name);
                break;
            case 4:
                cout << "Enter contact name to delete: ";
                cin.ignore();
                getline(cin, name);
                contactManager.deleteContact(name);
                break;
            case 5:
                cout << "Enter contact name to edit: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter new phone number: ";
                getline(cin, phoneNumber);
                contactManager.editContact(name, phoneNumber);
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}



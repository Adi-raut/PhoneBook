#include <iostream>
#include <string>
#include <map>

using namespace std;

class Contact {
public:
    string name;
    string phone;
    string email;
};

class Phonebook {
private:
    map<string, Contact> contacts;

public:
    void addContact(const Contact& contact) {
        contacts[contact.name] = contact;
    }

    void removeContact(const string& name) {
        contacts.erase(name);
    }

    void searchContact(const string& name) {
        if (contacts.count(name) > 0) {
            Contact& contact = contacts[name];
            cout << "Name: " << contact.name << endl;
            cout << "Phone: " << contact.phone << endl;
            cout << "Email: " << contact.email << endl;
        } else {
            cout << "Contact not found." << endl;
        }
    }

    void displayAllContacts() {
        for (const auto& pair : contacts) {
            const Contact& contact = pair.second;
            cout << "Name: " << contact.name << endl;
            cout << "Phone: " << contact.phone << endl;
            cout << "Email: " << contact.email << endl;
            cout << endl;
        }
    }
};

int main() {
    Phonebook phonebook;
    int choice;

    do {
        cout << "Phonebook Management System" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Remove Contact" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Display All Contacts" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Contact newContact;
                cout << "Enter name: ";
                cin >> newContact.name;
                cout << "Enter phone: ";
                cin >> newContact.phone;
                cout << "Enter email: ";
                cin >> newContact.email;
                phonebook.addContact(newContact);
                cout << "Contact added successfully." << endl;
                break;
            }
            case 2: {
                string name;
                cout << "Enter name: ";
                cin >> name;
                phonebook.removeContact(name);
                cout << "Contact removed successfully." << endl;
                break;
            }
            case 3: {
                string name;
                cout << "Enter name: ";
                cin >> name;
                phonebook.searchContact(name);
                break;
            }
            case 4:
                phonebook.displayAllContacts();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);
    return 0;
}

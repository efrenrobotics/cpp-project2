#include <iostream>
#include <fstream>

#include "PasswordManager.h"

using namespace std;

const static int NUM_PASSWORDS = 3;

PasswordManager *readFile(ifstream &passwordsFile) {
    PasswordManager *passwords = new PasswordManager[NUM_PASSWORDS];
    for (int index = 0; index < NUM_PASSWORDS; index++) {
        string input;
        getline(passwordsFile, input);
        int spaceIndex = input.find(" ");
        string username = input.substr(0, spaceIndex);
        string password = input.substr(spaceIndex + 1);
        PasswordManager *manager = passwords + index;
        manager->setUsername(username);
        manager->setEncryptedPassword(password);
    }
    return passwords;
}

void displayCriteria() {
    cout << "New passwords must have all of the following." << endl;
    cout << "At least 8 characters long." << endl;
    cout << "At least 1 uppercase letter." << endl;
    cout << "At least 1 lowercase letter." << endl;
    cout << "At least 1 digit." << endl;
}

PasswordManager *getManager(PasswordManager *passwords, string username) {
    for (int index = 0; index < NUM_PASSWORDS; index++) {
        PasswordManager *manager = passwords + index;
        if (username.compare(manager->getUsername()) == 0) {
            return manager;
        }
    }
    return nullptr;
}

void processNewPassword(ifstream &passwordsFile, PasswordManager *passwords) {
    string username, oldPassword, newPassword;
    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter your old password: ";
    cin >> oldPassword;
    cout << "Please enter your new password: ";
    cin >> newPassword;
    PasswordManager *manager = getManager(passwords, username);
    if (manager == nullptr) {
        cout << "Username is invalid, password not changed." << endl;
    } else if (!manager->authenticate(oldPassword)) {
        cout << "Old password is incorrect." << endl;
    } else if (!manager->setNewPassword(newPassword)) {
        cout << "New password does not meet criteria." << endl;
    } else {
        cout << "Password has been changed for username: " << username << endl;
    }
}

void writeNewPassword(PasswordManager *passwords) {
    ofstream passwordsFile;
    passwordsFile.open("passwords.txt", ios::trunc);
    for (int index = 0; index < NUM_PASSWORDS; index++) {
        PasswordManager *manager = passwords + index;
        passwordsFile << manager->getUsername() << " " << manager->getEncryptedPassword() << endl;
    }
    passwordsFile.close();
}

int main() {
    ifstream passwordsFile;
    passwordsFile.open("passwords.txt");
    if (passwordsFile.fail()) {
        cout << "Input file does not exist." << endl;
        return 1;
    }
    PasswordManager *passwords = readFile(passwordsFile);
    passwordsFile.close();
    displayCriteria();
    processNewPassword(passwordsFile, passwords);
    writeNewPassword(passwords);
    delete [] passwords;
    return 0;
}

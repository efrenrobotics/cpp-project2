#include "PasswordManager.h"
#include <iostream>

using namespace std;

// Class to manage a user's password, set a new password and encrypt the password

// Username setter function
// efren
void PasswordManager::setUsername(string user) {
    username = user;
}

// Password setter function
// efren
void PasswordManager::setEncryptedPassword(string pwd) {
    password = pwd;
}

// username getter function
// Angel drove here
string PasswordManager::getUsername() {
    return username;
}

// password getter functino
// Angel drove here
string PasswordManager::getEncryptedPassword() {
    return password;
}

// encrypt and set a new password
// Angel drove here
bool PasswordManager::setNewPassword(string pwd) {
    if (meetsCriteria(pwd)) {
        password = encrypt(pwd);
        return true;
    }
    return false;
}

// check if the password entered is correct
// Angel drove here
bool PasswordManager::authenticate(string pwd) {
    string encryptedPassword = encrypt(pwd);
    return password.compare(encryptedPassword) == 0;
}

// encrypt a password using the encryption algorithm
// Angel drove here
string PasswordManager::encrypt(string pwd) {
    string encryptedPassword = "";
    for (int index = 0; index < pwd.length(); index++) {
        char character = ((pwd[index] - 33)  + 25) % 94 + 33;
        encryptedPassword += character;
    }
    return encryptedPassword;
}

// check if the password meets the criteria for a good password
// Angel drove here
bool PasswordManager::meetsCriteria(string pwd) {
    static int MIN_LENGTH = 8;
    if (pwd.length() < MIN_LENGTH) {
        return false;
    }
    bool upper, lower, digit = false;
    for (int index = 0; index < pwd.length(); index++) {
        if (isupper(pwd[index])) {
            upper = true;
        }
        if (islower(pwd[index])) {
            lower = true;
        }
        if (isdigit(pwd[index])) {
            digit = true;
        }
    }
    return upper && lower && digit;
}

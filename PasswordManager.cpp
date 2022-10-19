#include "PasswordManager.h"

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
    string encryptedPassword = encrypt(password);
    return pwd.compare(encryptedPassword) == 0;
}

// encrypt a password using the encryption algorithm
// Angel drove here
string PasswordManager::encrypt(string password) {
    string encryptedPassword = "";
    for (int index = 0; index < password.length(); index++) {
        char character = ((password[index] - 33)  + 25) % 94 + 33;
        encryptedPassword += character;
    }
    return encryptedPassword;
}

// check if the password meets the criteria for a good password
// Angel drove here
bool PasswordManager::meetsCriteria(string password) {
    static int MIN_LENGTH = 8;
    if (password.length() < MIN_LENGTH) {
        return false;
    }
    int index = 0;
    bool end = false;
    while (index < password.length() && !end) {
        if (isupper(password[index])) {
            end = true;
        }
        index++;
    }
    if (index == password.length() && !end) {
        return false;
    }
    index = 0;
    end = false;
    while (index < password.length() && !end) {
        if (islower(password[index])) {
            end = true;
        }
        index++;
    }
    if (index == password.length() && !end) {
        return false;
    }
    index = 0;
    end = false;
    while (index < password.length() && !end) {
        if (isdigit(password[index])) {
            end = true;
        }
        index++;
    }
    if (index == password.length() && !end) {
        return false;
    }
    return true;
}

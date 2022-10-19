#include "PasswordManager.h"

// Username setter function
// efren
void PasswordManager::setUsername(string user)
{
    username = user;
}

// Password setter function
// efren
void PasswordManager::setEncryptedPassword(string pwd) {
    password = pwd;
}

string PasswordManager::getUsername(string username) {}
string PasswordManager::getEncryptedPassword(string password) {}
bool PasswordManager::setNewPassword(string password) {}
bool PasswordManager::authenticate(string password) {}
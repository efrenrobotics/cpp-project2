#include <string>
#include <iostream>

using namespace std;

class PasswordManager{
    string username, password;

    public: 
        void setUsername(string user);
        void setEncryptedPassword(string pwd);
        string getUsername(string username);
        string getEncryptedPassword(string password);
        bool setNewPassword(string password);
        bool authenticate(string password);
    private: 
        string encrypt(string password);
        bool  meetsCriteria(string password);
};
#include <string>
#include <iostream>

using namespace std;

class PasswordManager {
    string username, password;

    public: 
        void setUsername(string user);
        void setEncryptedPassword(string pwd);
        string getUsername();
        string getEncryptedPassword();
        bool setNewPassword(string pwd);
        bool authenticate(string pwd);
    
    private: 
        string encrypt(string password);
        bool meetsCriteria(string password);
};
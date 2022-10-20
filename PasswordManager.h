#include <string>

class PasswordManager {
    private:
        std::string username, password;
        std::string encrypt(std::string password);
        bool meetsCriteria(std::string password);

    public: 
        void setUsername(std::string user);
        void setEncryptedPassword(std::string pwd);
        std::string getUsername();
        std::string getEncryptedPassword();
        bool setNewPassword(std::string pwd);
        bool authenticate(std::string pwd);
};
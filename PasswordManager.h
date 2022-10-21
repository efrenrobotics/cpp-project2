#include <string>

// header file for password manager class
class PasswordManager {
    private:
        std::string username, password;
        std::string encrypt(std::string pwd);
        bool meetsCriteria(std::string pwd);

    public:
        void setUsername(std::string user);
        void setEncryptedPassword(std::string pwd);
        std::string getUsername();
        std::string getEncryptedPassword();
        bool setNewPassword(std::string pwd);
        bool authenticate(std::string pwd);
};
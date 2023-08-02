#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>
#include <vector>

class UserManager {
private:
    std::string filename;
    std::vector<std::string> usernames;
public:
    UserManager(const std::string& file);

    void clearConsole();
    void displayMenu();
    void login();
    void registration();
    void forgot();
    void listUsernames();
    bool admin();
    void menu();
};

#endif // USERMANAGER_H

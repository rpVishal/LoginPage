 #include "UserManager.h"
#include <iostream>
#include <fstream>

//Constructor for the UserManager class. This constructor initializes the class instance and assigns the provided file name or path to the 'filename' that has been given in the main.cpp.
UserManager::UserManager(const std::string& file) : filename(file) {}



void UserManager::clearConsole() {
    // For clearing the console screen in Windows
    if (_WIN32) {
        system("cls");
    }
    // or clearing the console screen in Linux, macOS.
    else {
        system("clear");
    }
}

//The function UserManager::displayMenu(), presents a menu to the user with various options related to user management.
void UserManager::displayMenu() {
    int c;
    clearConsole();
    std::cout << "\t----------------------------------------Welcome To Login Page----------------------------------------\n\n\n\n";
    std::cout << "\t\t\t\t\t\t1. Login\n";
    std::cout << "\t\t\t\t\t\t2. Register\n";
    std::cout << "\t\t\t\t\t\t3. Forgot password\n";
    std::cout << "\t\t\t\t\t\t4. List Usernames\n";
    std::cout << "\t\t\t\t\t\t5. Exit\n";


    while (true) {
        std::cout << "\t\t\t\t\t\tEnter your choice: ";

        try {
            std::cin >> c;
            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input. Please enter a valid integer between 1 and 5.");
            }

            if (c < 1 || c > 5) {
                throw std::out_of_range("Invalid integer. Please enter a valid integer between 1 and 5.");
            }
            break;
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << "\n";
            std::cin.clear();

        }
        catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << "\n";
            std::cin.clear();

        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//Used to discard any remaining characters in the input buffer up to the next newline character. 
    }
    switch (c) {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;

    case 3:
        forgot();
        break;

    case 4:
        //Case 4 ensures that only admin users can access and view the list of usernames.
        if (admin()) {
            listUsernames();
        }
        else {
            std::cout << "Access denied. This option is for admins only.\n";
        }
        break;

    case 5:
        std::cout << "Thank you. Exiting...\n";
        break;

    default:
        std::cout << "Please select a valid option.\n";

    }
}

//The function UserManager::login() allows a user to log in by providing a username and password.
void UserManager::login() {
    int count = 0;
    std::string userID, password, id, pass;
    clearConsole();
    std::cout << "\t\t\t\t\tPlease enter username and password:\n";
    std::cout << "\t\t\t\t\tUSERNAME: ";
    std::cin >> userID;
    std::cout << "\t\t\t\t\tPASSWORD: ";
    std::cin >> password;
    std::ifstream input(filename);//Used to open a file with the name specified by the filename and to read data from the file.
    while (input >> id >> pass) {
        if (id == userID && pass == password) {
            count = 1;
            break;
        }
    }
    input.close();//To close the file after reading is completed.
    if (count == 1) {
        std::cout << "\nLogin successful. Welcome, " << userID << "!\n";
    }
    else {
        std::cout << "\nLogin Error. Invalid username or password.\n";
    }
}

//The function UserManager::registration() enables a user to register by creating a new account. 
void UserManager::registration() {
    std::string ruserID, rpassword;
    clearConsole();
    std::cout << "\t\t\t\t\tEnter the username: ";
    std::cin >> ruserID;

    //Check if the username already exists
    std::ifstream fcheck(filename);
    std::string existingID;
    bool userExists = false;
    while (fcheck >> existingID >> rpassword) {
        if (existingID == ruserID) {
            userExists = true;
            break;
        }
    }
    fcheck.close();

    if (userExists) {
        std::cout << "\n\t\tUsername already exists. Please choose a different username.\n";
        return;
    }

    std::cout << "\t\t\t\t\tEnter the password: ";
    std::cin >> rpassword;

    //The f1 stream will be associated with the file, allowing the program to write data to the file. 
    std::ofstream f1(filename, std::ios::app);
    f1 << ruserID << ' ' << rpassword << std::endl;
    f1.close();
    clearConsole();
    std::cout << "\n\t\tRegistration successful.\n";
}

//The UserManager::forgot() function is used for handling the "Forgot Password" feature. It allows users to get their forgotten password by searching for their account using their username.
void UserManager::forgot() {
    int option;
    clearConsole();
    std::cout << "\t\t\t\t\tForgot Password?\n";
    std::cout << "Press 1 to search your id by username\n";
    std::cout << "Press 2 to go back to the main menu\n";
    while (true) {
        std::cout << "Enter your choice: ";
        try {
            std::cin >> option;
            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid input. Please enter an integer either 1 or 2.");
            }
            if (option < 1 || option > 2) {
                throw std::out_of_range("Invalid integer. Please enter either 1 or 2: ");
            }


            break;
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << std::endl;
            std::cin.clear();

        }
        catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << std::endl;
            std::cin.clear();

        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    switch (option) {
    case 1: {
        int count = 0;
        std::string suserID, sid, spass;
        std::cout << "\n\t\tEnter the username which you remember: ";
        std::cin >> suserID;
        std::ifstream f2(filename);
        while (f2 >> sid >> spass) {
            if (sid == suserID) {
                count = 1;
                break;
            }
        }
        f2.close();
        if (count == 1) {
            std::cout << "\n\nYour account is found!\n";
            std::cout << "Your password is: " << spass << "\n";
        }
        else {
            std::cout << "Sorry, your account was not found.\n";
        }
        break;
    }
    case 2:
        break;
    default:
        std::cout << "Wrong choice. Please try again.\n";
    }

}
//The listUsernames function is used to read the usernames from the file specified by the filename member variable and displays them if the admin password is entered correctly.
void UserManager::listUsernames() {
    clearConsole();
    std::ifstream fcheck(filename);
    std::string existingID, password;
    usernames.clear();
    while (fcheck >> existingID >> password) {
        usernames.push_back(existingID);
    }
    fcheck.close();

    if (usernames.empty()) {
        std::cout << "\nNo users found.\n";
        return;
    }

    std::cout << "\n--- Usernames List ---\n";
    for (const auto& username : usernames) {
        std::cout << username << std::endl;
    }
}

//The admin function is used for obtaining the admin password from the user and checking if it matches the expected admin password.
bool UserManager::admin()
{
    std::string adminPassword;
    std::cout << "Enter admin password: ";
    std::cin >> adminPassword;

    return (adminPassword == "admin123");
}

//The menu function in the UserManager class is used to display the main menu options and allow the user to interact with the program by entering their choice. 
void UserManager::menu() {

    char choice;

    do {
        displayMenu();

        std::cout << "If you want to continue press(Y/y):  ";
        std::cin >> choice;

    } while (choice == 'Y' || choice == 'y');
}

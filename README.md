# Login Page 

### Introduction
The login page is an essential part of any application that requires user authentication and access control. It allows users to log in to the system using their unique credentials, such as  __username__ and __password__.

## <a href = "https://github.com/rpVishal/LoginPage/blob/main/Install%20Instructions/Install_Instruction.md" target = "_blank">Install Instructions</a>



### Functionality
The login page offers the following main functionalities:

1) __Login__: Users can enter their username and password to log in to the system. Upon successful authentication, they will be granted access to the application.
2) __Registration__: New users can register themselves by creating a unique username and password. The system will store their credentials for future logins. 
3) __Forgot Password__: In case a user forgets their password, they can use the "Forgot Password" option to recover it. The system will provide the user's password when the user will provide their valid username.
4) __List Usernames__: An admin feature that allows authorized users to view a list of all registered usernames.
5) __Exit__: Users can exit the application when they are done using it.


### Usage of Functions

__1. Displaying the Menu__

The displayMenu() function presents a menu to the user with the following options:

1) Login
2) Register
3) Forgot password
4) List Usernames
5) Exit

The user can choose an option by entering the corresponding number. If an invalid option is entered, the program will prompt the user to enter a valid choice.

__2. Logging In__

The __login()__ function allows users to log in by providing their username and password. It verifies the credentials against the stored user data in the "records.txt" file. If the login is successful, the user is greeted with a welcome message. Otherwise, an error message is displayed, and the user can try again or go back to the main menu.

__3. Registering__

The __registration()__ function allows new users to register by providing a unique username and a password. It checks if the username is already taken then the user is prompted to choose a different username. If the username is available, the new user is registered and added to the "records.txt" file.

__4. Password Recovery__

The __forgot()__ function allows users to recover their passwords by entering their username. If the username is found in the system, the corresponding password is displayed. If the username is not found, the user get a prompt message that the account not found.

__5. Listing Usernames__

The __listUsernames()__ function displays a list of all registered usernames in the system. This option is available only for the admin. The list of usernames is read from the "records.txt" file, and each username is displayed.

__6. Exiting the Program__

The user can exit the program by selecting the __Exit__ option from the menu.


## [__Unit Test 1 and problem associated__](https://github.com/rpVishal/LoginPage/blob/main/unittest/Unittest1.md)
## [__Unit Test 2 and problem associated__](https://github.com/rpVishal/LoginPage/blob/main/unittest/Unittest2.md)


## Conclusion
This document provided an overview of the implementation of a simple login page using C++ classes and functions. The UserManager class effectively manages user-related operations, and the program offers a user-friendly interface for users to log in, register, recover passwords, and view registered usernames.

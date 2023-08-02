# Unit Test | LoginPage | Document prepared by Vishal Rajput
## Module Name : Login | Location : UserManager.h
### Function Name : displayMenu()
### ID : LoginTest001


unit test to check behaviour of the function using different inputs.

### Function Behaviour
The function takes a int "c" as a choice from the user.

### Problems associated
1) If a user is pasing any character, float, double, etc. value in the display menu output screen then the program terminates. And default is only handling the integer value.
### Solution
1) An exception handler is added to the function of displayMenu(), Whenever the function will throw an error i.e __if out_of_range__ or __invalid_argument__ whenever these situation arises then exception handler can easily handle them.
```
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
            std::cout << "Error: "<< e.what() << "\n";
            std::cin.clear();
 
        }
        catch (const std::out_of_range& e) {
            std::cout <<"Error: "<< e.what() << "\n";
            std::cin.clear();
     
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }
     
```

# Unit Test | LoginPage | Document prepared by Vishal Rajput
## Module Name : Login | Location : UserManager.h
### Function Name : forgot()
### ID : LoginTest002


unit test to check behaviour of the function using different inputs.

### Function Behaviour
The function takes a int "option" as a choice from the user.

### Problems associated
1) If a user is passing any character, float, double, etc. value in the forgot menu output screen then the program terminates. And default() is only handling the integer value.

### Solution
1) An exception handler is added to the function of forgot(), Whenever the function will throw an error i.e __if out_of_range__ or __invalid_argument__ whenever these situation arises then exception handler can easily handle them.

```
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
```

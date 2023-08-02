#include <iostream>
#include <fstream>
#include "UserManager.h"

int main() {
    UserManager userManager("records.txt");
    userManager.menu();

    return 0;

}
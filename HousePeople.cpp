#include <iostream>
#include "person.h"

int main() {
    // Create a house
    House house("123 Main Street");

    // Create a person with a home
    Person person("John Doe", 30, house);

    // Access and print the person's information, including their home address
    std::cout << "Name: " << person.getName() << std::endl;
    std::cout << "Age: " << person.getAge() << std::endl;
    std::cout << "Home Address: " << person.getHome().getAddress() << std::endl;

    return 0;
}

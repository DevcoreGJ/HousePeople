#include <iostream>
#include "person.h"
#include "house.h"

int main() {
    // Create a house
    House house("123 Main Street");

    // Create a person
    Person person("John Doe", 30);

    // Check if the person has a home
    if (person.hasHouse() && person.getHouse() != nullptr) {
        House* home = person.getHouse();
        std::cout << "Person has a home at: " << home->getAddress() << std::endl;
    }
    else {
        std::cout << "Person is homeless." << std::endl;
    }

    // Assign a home to the person
    person.setHome(&house);

    // Check again if the person has a home
    if (person.hasHouse() && person.getHouse() != nullptr) {
        House* home = person.getHouse();
        std::cout << "Person has a home at: " << home->getAddress() << std::endl;
    }
    else {
        std::cout << "Person is homeless." << std::endl;
    }

    return 0;
}

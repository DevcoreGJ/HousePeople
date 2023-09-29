// person.cpp

#include "person.h"
#include "house.h"

// Constructor definition
Person::Person(const std::string& name, int age)
    : name(name), age(age), home(nullptr) {  // Initialize home pointer to nullptr
}

// Getter method definitions
std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

bool Person::hasHouse() const {
    return (home != nullptr);  // Check if home is not nullptr
}

// Getter methods
House* Person::getHouse()
{
    return home;
}

// Set the person's home
void Person::setHome(House* house) {
    home = house;
}

// person.cpp (Implementation file)

#include "person.h"

// Constructor definition
Person::Person(const std::string& name, int age) {
    this->name = name;
    this->age = age;
}

// Getter method definitions
std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

// Setter method definitions
void Person::setName(const std::string& name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

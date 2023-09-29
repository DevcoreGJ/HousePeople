// person.cpp

#include "person.h"

// Constructor definition
Person::Person(const std::string& name, int age, const std::string& homeAddress)
    : name(name), age(age), home(homeAddress) {
}

// Getter method definitions
std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

House Person::getHome() const {
    return home;
}

// Setter method definitions
void Person::setName(const std::string& name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

// person.h (Updated Header file)

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "house.h"

class Person {
private:
    std::string name;
    int age;
    House home; // Add a House object as a private attribute

public:
    // Constructor
    Person(const std::string& name, int age, const std::string& homeAddress);

    // Getter methods
    std::string getName() const;
    int getAge() const;
    House getHome() const;

    // Setter methods
    void setName(const std::string& name);
    void setAge(int age);
};

#endif

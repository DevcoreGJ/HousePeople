// person.h

#ifndef PERSON_H
#define PERSON_H

#include <string>

class House;  // Forward declaration of House class

class Person {
private:
    std::string name;
    int age;
    House* home;  // Pointer to House object

public:
    // Constructor
    Person(const std::string& name, int age);

    // Getter methods
    std::string getName() const;
    int getAge() const;
    bool hasHouse() const;
    House* getHouse();

    // Set the person's home
    void setHome(House* house);
};

#endif

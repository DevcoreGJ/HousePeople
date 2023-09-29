#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Constructor
    Person(const std::string& name, int age);

    // Getter methods
    std::string getName() const;
    int getAge() const;

    // Setter methods
    void setName(const std::string& name);
    void setAge(int age);
};

#endif
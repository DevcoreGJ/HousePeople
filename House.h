// house.h (Header file)

#ifndef HOUSE_H
#define HOUSE_H

#include <string>

class House {
private:
    std::string address;

public:
    // Constructor
    House(const std::string& address);

    // Getter method
    std::string getAddress() const;
};

#endif

// house.cpp

#include "house.h"

// Constructor definition
House::House(const std::string& address) {
    this->address = address;
}

// Getter method definition
std::string House::getAddress() const {
    return address;
}

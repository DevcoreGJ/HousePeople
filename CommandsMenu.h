#ifndef COMMANDSMENU_H
#define COMMANDSMENU_H

#include <iostream>
#include <string>

class CommandsMenu {
public:
    CommandsMenu(); // Constructor to initialize the CommandsMenu

    void displayMenu(); // Display the commands menu
    void processCommand(const std::string& command); // Process player's command
};

#endif // COMMANDSMENU_H

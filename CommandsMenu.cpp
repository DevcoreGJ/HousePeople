#include "CommandsMenu.h"
#include <iostream>
#include <string>
#include <cstdlib> // Include cstdlib for exit()

// Display the help/commands menu
void CommandsMenu::displayMenu() {
    std::cout << "===== Commands Menu =====\n";
    std::cout << "1. Look around (inspect the room)\n";
    std::cout << "2. Move (choose a direction: n, s, e, w)\n";
    std::cout << "3. Open (interact with objects)\n";
    std::cout << "4. Use key item (if you have any)\n";
    std::cout << "5. Check inventory\n";
    std::cout << "6. Quit game (exit the game)\n";
    std::cout << "7. Display this menu (show available commands)\n";
    std::cout << "==========================\n";
}

// Process player's command
void CommandsMenu::processCommand(const std::string& command) {
    if (command == "1") {
        std::cout << "You look around the room.\n";
        // Implement room inspection logic here
    }
    else if (command == "2") {
        std::cout << "Choose a direction (n, s, e, w): ";
        // Implement movement logic here
        // For example, you can take input for the direction and handle movement.
        std::string direction;
        std::cin >> direction;

        // Implement movement logic based on the direction chosen.
        if (direction == "n") {
            std::cout << "You move north.\n";
            // Implement logic to move to the north room.
        }
        // Handle other directions similarly.
    }
    else if (command == "3") {
        std::cout << "You try to open something.\n";
        // Implement object interaction logic here
    }
    else if (command == "4") {
        std::cout << "You attempt to use a key item.\n";
        // Implement key item usage logic here
    }
    else if (command == "5") {
        std::cout << "You check your inventory.\n";
        // Implement inventory display logic here
    }
    else if (command == "6") {
        std::cout << "Thanks for playing!\n";
        exit(0); // Exit the game
    }
    else if (command == "7") {
        CommandsMenu::displayMenu(); // Display the commands menu
    }
    else {
        std::cout << "Invalid command. Type '7' to see available commands.\n";
    }
}

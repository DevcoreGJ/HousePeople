#include "Character.h"
#include "GameModule.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>

int main() {
    Character character;
    character.inputName();

    char allocationChoice;
    std::cout << "Choose stat allocation method:\n";
    std::cout << "1. Manual allocation\n";
    std::cout << "2. Random allocation\n";
    std::cin >> allocationChoice;

    if (allocationChoice == '1') {
        character.allocateStatsManually();
    }
    else if (allocationChoice == '2') {
        character.allocateStatsRandomly();
    }
    else {
        std::cout << "Invalid choice. Exiting." << std::endl;
        return 1;
    }

    character.displaySummary();

    char choice;
    do {
        std::cout << "\nAre you happy with your character? (Y/N): ";
        std::cin >> choice;

        if (choice == 'N' || choice == 'n') {
            std::cout << "What would you like to do?\n";
            std::cout << "1. Change name\n";
            std::cout << "2. Re-allocate stats\n";
            std::cout << "3. Exit\n";

            int option;
            std::cin >> option;

            switch (option) {
            case 1:
                character.inputName();
                break;
            case 2:
                if (allocationChoice == '1') {
                    character.allocateStatsManually();
                }
                else {
                    character.allocateStatsRandomly();
                }
                break;
            case 3:
                return 0;
            default:
                std::cout << "Invalid option. Please choose a valid option (1-3)." << std::endl;
            }
        }
    } while (choice != 'Y' && choice != 'y');

    character.displaySummary();

    // Initialize the game world (create rooms and doors) from GameModule.cpp.
    Room centralRoom("Central Room");
    Room northRoom("North Room");
    Room eastRoom("East Room");
    Door centralToNorth(&centralRoom, &northRoom);
    Door centralToEast(&centralRoom, &eastRoom);
    centralRoom.setDoor(&centralToNorth);
    northRoom.setDoor(&centralToNorth);
    centralRoom.setDoor(&centralToEast);
    eastRoom.setDoor(&centralToEast);

    // Set the initial room for the player.
    Room* currentRoom = &centralRoom;

    std::cout << "\nWelcome to the Doors and Rooms text-based adventure game!\n";
    std::cout << "You are currently in the " << currentRoom->getName() << ".\n";

    while (true) {
        std::cout << "Choose a direction (n, e, s, w) or press 'q' to quit: ";
        std::cin >> choice;

        if (choice == 'q') {
            std::cout << "Thanks for playing!\n";
            break;
        }

        switch (choice) {
        case 'n':
            currentRoom = currentRoom->enter();
            break;
        case 'e':
            currentRoom = currentRoom->enter();
            break;
        case 's':
            currentRoom = currentRoom->enter();
            break;
        case 'w':
            currentRoom = currentRoom->enter();
            break;
        default:
            std::cout << "Invalid choice. Please choose a valid direction.\n";
        }
    }

    return 0;
}

#include "GameModule.h"
#include "Character.h"
#include "CommandsMenu.h" // Include the CommandsMenu header
#include <iostream>

// Room Class Implementation
Room::Room(const std::string& roomName)
    : name(roomName), currentRoom(false) {}

void Room::addDoor(Door* door) {
    doors.push_back(door);
}

const std::string& Room::getName() const {
    return name;
}

Room* Room::enter(char choice) {
    for (Door* door : doors) {
        if (door->getDirection() == choice) {
            return door->enter();
        }
    }
    return nullptr; // No door in that direction
}

bool Room::isCurrentRoom() const {
    return currentRoom;
}

void Room::setCurrentRoom(bool isCurrent) {
    currentRoom = isCurrent;
}

// Door Class Implementation
Door::Door(Room* room, char dir)
    : connectedRoom(room), direction(dir) {}

char Door::getDirection() const {
    return direction;
}

Room* Door::enter() {
    if (!connectedRoom->isCurrentRoom()) {
        connectedRoom->setCurrentRoom(true);
        return connectedRoom;
    }
    return nullptr; // Current room is already set
}

// GameModule Class Implementation
GameModule::GameModule() {
    // Initialize the game world here (create rooms and doors).
    Room* centralRoom = new Room("Central Room");
    Room* northRoom = new Room("North Room");
    Room* southRoom = new Room("South Room");
    Room* eastRoom = new Room("East Room");
    Room* westRoom = new Room("West Room");

    Door* centralToNorth = new Door(northRoom, 'n');
    Door* centralToSouth = new Door(southRoom, 's');
    Door* centralToEast = new Door(eastRoom, 'e');
    Door* centralToWest = new Door(westRoom, 'w');

    centralRoom->addDoor(centralToNorth);
    centralRoom->addDoor(centralToSouth);
    centralRoom->addDoor(centralToEast);
    centralRoom->addDoor(centralToWest);

    centralRoom->setCurrentRoom(true); // Initialize the first room as the current room
    currentRoom = centralRoom;
}

void GameModule::runGame() {
    char choice;

    std::cout << "\nWelcome to the Doors and Rooms text-based adventure game!\n";

    while (true) {
        std::cout << "You are currently in the " << currentRoom->getName() << ".\n";
        std::cout << "Choose a direction (n, s, e, w), 'q' to quit, or 'h' for help: ";
        std::cin >> choice;

        if (choice == 'q') {
            std::cout << "Thanks for playing!\n";
            break;
        }
        else if (choice == 'h') {
            // Create an instance of the CommandsMenu class and display the menu
            CommandsMenu commandsMenu;
            commandsMenu.displayMenu();
        }
        else {
            Room* newRoom = currentRoom->enter(choice);

            if (!newRoom) {
                std::cout << "There is no path in that direction. Try another way!\n";
            }
            else {
                currentRoom = newRoom;
            }
        }
    }
}

Room* GameModule::getCurrentRoom() const {
    return currentRoom;
}

CommandsMenu* GameModule::getCommandsMenu() {
    // You can create and return an instance of the CommandsMenu class here
    return new CommandsMenu();
}

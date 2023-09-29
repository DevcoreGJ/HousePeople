#ifndef GAMEMODULE_H
#define GAMEMODULE_H

#include <string>
#include <vector>

class Door;
class CommandsMenu; // Forward declaration of CommandsMenu class

class Room {
private:
    std::string name;                // The name of the room
    std::vector<Door*> doors;        // A vector to store pointers to doors connected to this room dynamically
    bool currentRoom;                // Indicates if this is the current room the player is in

public:
    Room(const std::string& roomName);  // Constructor to initialize a room with a name

    void addDoor(Door* door);        // Method to add a door to the room
    const std::string& getName() const;  // Getter to retrieve the room's name
    Room* enter(char choice);        // Method to enter a door based on the player's choice
    bool isCurrentRoom() const;      // Method to check if this is the current room
    void setCurrentRoom(bool isCurrent); // Method to set/unset this room as the current room
};

class Door {
private:
    Room* connectedRoom;             // The room connected to this door
    char direction;                  // The direction this door leads (e.g., 'n' for north)

public:
    Door(Room* room, char dir);      // Constructor to create a door with a connected room and direction

    Room* enter();                   // Method to enter through this door to the connected room
    char getDirection() const;       // Getter to retrieve the direction of this door
};

class GameModule {
private:
    Room* currentRoom;               // The currently active room in the game

public:
    GameModule();                    // Constructor to initialize the game world

    void runGame();                  // Method to start and run the game

    Room* getCurrentRoom() const;    // Getter to retrieve the current room in the game
    CommandsMenu* getCommandsMenu(); // Declaration of getCommandsMenu function
};

#endif // GAMEMODULE_H

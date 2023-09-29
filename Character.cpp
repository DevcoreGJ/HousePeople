#include "Character.h"
#include <iostream>
#include <random>
#include <ctime>

Character::Character() : stats{ "", 0, 0, 0 } {}

void Character::inputName() {
    std::cout << "Enter the character's name: ";
    std::cin >> stats.name;
}

void Character::allocateStatsManually() {
    int remainingPoints = totalAvailablePoints;

    while (remainingPoints > 0) {
        std::cout << "Available points: " << remainingPoints << std::endl;
        std::cout << "Enter points for Strength (max 5): ";
        std::cin >> stats.strength;

        std::cout << "Enter points for Constitution (max 5): ";
        std::cin >> stats.constitution;

        std::cout << "Enter points for Intelligence (max 5): ";
        std::cin >> stats.intelligence;

        if (stats.strength < 0 || stats.strength > maxStatValue ||
            stats.constitution < 0 || stats.constitution > maxStatValue ||
            stats.intelligence < 0 || stats.intelligence > maxStatValue) {
            std::cout << "Invalid input. Points should be between 0 and 5 for each stat." << std::endl;
            continue;
        }

        int totalStats = stats.strength + stats.constitution + stats.intelligence;
        if (totalStats != totalAvailablePoints) {
            std::cout << "Total points allocated must be exactly 8." << std::endl;
            continue;
        }

        break;
    }
}

void Character::allocateStatsRandomly() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, maxStatValue);

    stats.strength = dist(gen);
    stats.constitution = dist(gen);
    stats.intelligence = dist(gen);

    while (stats.strength + stats.constitution + stats.intelligence != totalAvailablePoints) {
        stats.strength = dist(gen);
        stats.constitution = dist(gen);
        stats.intelligence = dist(gen);
    }
}

int Character::calculateHP() const {
    return 3 + stats.constitution / 2;
}

int Character::calculateMana() const {
    return 3 + stats.intelligence / 2;
}

void Character::displaySummary() const {
    std::cout << "\nCharacter Summary:\n";
    std::cout << "Name: " << stats.name << std::endl;
    std::cout << "Strength: " << stats.strength << std::endl;
    std::cout << "Constitution: " << stats.constitution << std::endl;
    std::cout << "Intelligence: " << stats.intelligence << std::endl;
    std::cout << "HP: " << calculateHP() << std::endl;
    std::cout << "Mana: " << calculateMana() << std::endl;
}

void Character::reset() {
    stats = CharacterStats{ "", 0, 0, 0 };
}

const Character::CharacterStats& Character::getStats() const {
    return stats;
}

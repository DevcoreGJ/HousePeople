#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
private:
    struct CharacterStats {
        std::string name;
        int strength;
        int constitution;
        int intelligence;
    };

    CharacterStats stats;

    static const int maxStatValue = 5;
    static const int totalAvailablePoints = 8;

public:
    Character();

    void inputName();
    void allocateStatsManually();
    void allocateStatsRandomly();
    int calculateHP() const;
    int calculateMana() const;
    void displaySummary() const;
    void reset();
    const CharacterStats& getStats() const;
};

#endif // CHARACTER_H


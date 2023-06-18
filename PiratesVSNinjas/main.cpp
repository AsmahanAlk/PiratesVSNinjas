#include <iostream>
#include <string>

using namespace std;

// GameStructure class
class GameStructure {
public:
    virtual void Help() = 0; // Pure virtual method
};

// Character class (base class)
class Character : public GameStructure {
protected:
    string Name;
    int Health;

public:
    // Constructor
    Character(string name, int health) : Name(name), Health(health) {}

    // Getter for Name
    string GetName() {
        return Name;
    }

    // Setter and getter for Health
    void SetHealth(int health) {
        if (health < 0) {
            Health = 0;
            cout << "Character has expired..." << endl;
        }
        else {
            Health = health;
        }
    }

    int GetHealth() {
        return Health;
    }

    // Talk methods using Overloading Polymorphism
    void Talk(string stuffToSay) {
        cout << Name << ": " << stuffToSay << endl;
    }

    void Talk(string name, string stuffToSay) {
        cout << name << ": " << stuffToSay << endl;
    }

    // Virtual attack method
    virtual int Attack() {
        return 10;
    }

    // Help method (overridden from GameStructure)
    void Help() {
        cout << "Characters are the main entities in the game." << endl;
    }
};

// Ninja class (subclass of Character)
class Ninja : public Character {
public:
    // Constructor
    Ninja(string name, int health) : Character(name, health) {}

    // ThrowStars method
    void ThrowStars() {
        cout << "I am throwing stars!" << endl;
    }

    // Override attack method
    int Attack() override {
        return 25;
    }

    // Help method (overridden from Character)
    void Help() {
        cout << "Ninjas are skilled fighters. They can throw stars!" << endl;
    }
};

// Pirate class (subclass of Character)
class Pirate : public Character {
public:
    // Constructor
    Pirate(string name, int health) : Character(name, health) {}

    // UseSword method
    void UseSword() {
        cout << "I am swooshing my sword!" << endl;
    }

    // Override attack method
    int Attack() override {
        return 25;
    }

    // Help method (overridden from Character)
    void Help() {
        cout << "Pirates are fierce fighters. They can use swords!" << endl;
    }
};

int main() {
    cout << "Welcome to Pirates vs Ninjas Game!" << endl;

    // Create a ninja and a pirate
    Ninja ninja("Ninja", 100);
    Pirate pirate("Pirate", 100);

    // Game loop
    bool gameRunning = true;
    while (gameRunning) {
        cout << "Choose an action:" << endl;
        cout << "1. Ninja's action" << endl;
        cout << "2. Pirate's action" << endl;
        cout << "3. Help" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            ninja.Talk("I'm ready for action!");
            ninja.ThrowStars();
            cout << "Ninja's attack power: " << ninja.Attack() << " hit points" << endl;
            break;

        case 2:
            pirate.Talk("Avast, me hearties!");
            pirate.UseSword();
            cout << "Pirate's attack power: " << pirate.Attack() << " hit points" << endl;
            break;

        case 3:
            ninja.Help();  // Display ninja's help message
            pirate.Help(); // Display pirate's help message
            break;

        case 4:
            gameRunning = false; // Exit the game loop
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    cout << "Thank you for playing Pirates vs Ninjas Game!" << endl;

    return 0;
}
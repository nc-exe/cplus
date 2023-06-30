#include <iostream>
#include <string>

class Person {
    friend std::ostream& operator<<(std::ostream& out, const Person& person);
public:
    Person() = default;
    Person(std::string_view first_name, std::string_view last_name)
        : first_name(first_name), last_name(last_name) {}

private:
    std::string first_name{"Mysterious"};
    std::string last_name{"Person"};
};

std::ostream& operator<<(std::ostream& out, const Person& person) {
    return out << "Person [" << person.first_name << ' ' << person.last_name << ']';
}

class Player : public Person {
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
public:
    Player() = default;
    Player(std::string_view first_name, std::string_view last_name, std::string_view game)
        : Person(first_name, last_name), game(game) {}

private:
    std::string game{"None"};
};

std::ostream& operator<<(std::ostream& out, const Player& player) {
    return out << "Player: [game: " << player.game
               << ", name: " << player.get_first_name() << ' ' << player.get_last_name() << ']';
}

int main() {
    Player p1("John", "Snow", "Basketball");
    std::cout << "Player: " << p1 << std::endl;
    return 0;
}

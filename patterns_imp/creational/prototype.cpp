#include <print>
#include <string>
#include <cstddef>
#include <unordered_map>
#include <memory>

class Character {
    protected:
        std::string name;
        std::string classType;
        std::size_t level;
        int health;
        int mana;
        std::size_t attack;
        std::size_t defense;
    public:
        virtual std::unique_ptr<Character> clone() const = 0;

        Character(const std::string& type, std::size_t lvl,
            int hp, int mp, std::size_t atk, std::size_t def)
            : classType(type),level(lvl), health(hp),
            mana(mp), attack(atk), defense(def) {}

        Character(const Character&) = default;

        void setName(const std::string& name) {
            this->name = name;
        }

        void setLevel(std::size_t lv) {
            level = lv;
        }

        void printc() const {
            std::println("== {} ==", classType);
            std::println("Name: {}", name);
            std::println("Level: {}", level);
            std::println("Health: {}", health);
            std::println("Mana: {}", mana);
            std::println("Attack: {}", attack);
            std::println("Defense: {}", defense);
        }

        virtual ~Character() = default;
};

class Warrior : public Character {
    public:
        Warrior() : Character("Warrior", 1, 250, 20, 40, 30) {}
        
        std::unique_ptr<Character> clone() const override {
            return std::make_unique<Warrior>(*this);
        }
};

class Mage : public Character {
    public:
        Mage() : Character("Mage", 1, 120, 250, 60, 10) {}

        std::unique_ptr<Character> clone() const override {
            return std::make_unique<Mage>(*this);
        }
};

class Archer : public Character {
    public:
        Archer() : Character("Archer", 1, 170, 80, 45, 20) {}

        std::unique_ptr<Character> clone() const override {
            return std::make_unique<Archer>(*this);
        }
};

class CharacterRegistry {
    private:
        std::unordered_map<std::string, std::unique_ptr<Character>> chmap;
    public:
        CharacterRegistry() {
            chmap.emplace("Warrior", std::make_unique<Warrior>());
            chmap.emplace("Mage", std::make_unique<Mage>());
            chmap.emplace("Archer", std::make_unique<Archer>());
        }

        void addPrototype(const std::string& type, std::unique_ptr<Character> prototype) {
            chmap[type] = std::move(prototype);
        }

        std::unique_ptr<Character> createCharacter(const std::string& type) {
            auto It = chmap.find(type);

            if(It != chmap.end())
                return It->second->clone();

            return nullptr;
        }
};

int main () {
    CharacterRegistry registery;

    auto warrior = registery.createCharacter("Warrior");
    auto mage = registery.createCharacter("Mage");
    auto archer = registery.createCharacter("Archer");

    warrior->setName("Arthur");
    warrior->setLevel(10);

    mage->setName("Merlin");
    mage->setLevel(30);

    archer->setName("Leon");
    archer->setLevel(15);

    warrior->printc();
    std::println();
    mage->printc();
    std::println();
    archer->printc();

    return 0;
}

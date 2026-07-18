#include <string>
#include <print>

class Meal {
    private:
        std::string mainCourse;
        std::string drink;
        std::string dessert;
        std::string sideDish;

    public:
        Meal() = default;

        void setMainCourse(const std::string& mainCourse) {
            this->mainCourse = mainCourse;
        }

        const std::string& getMainCourse() const {
            return mainCourse;
        }


        void setDrink(const std::string& drink) {
            this->drink = drink;
        }

        const std::string& getDrink() const {
            return drink;
        }


        void setDessert(const std::string& dessert) {
            this->dessert = dessert;
        }

        const std::string& getDessert() const {
            return dessert;
        }


        void setSideDish(const std::string& sideDish) {
            this->sideDish = sideDish;
        }

        const std::string& getSideDish() const {
            return sideDish;
        }

        void printm() const {
            std::println("Main Course: {}", mainCourse);
            std::println("Drink: {}", drink);
            std::println("Dessert: {}", dessert);
            std::println("Side Dish: {}", sideDish);
        }
};

class MealBuilder {
    protected:
        Meal meal;

    public:
        virtual void buildMainCourse() = 0;

        virtual void buildDrink() = 0;

        virtual void buildDessert() = 0;

        virtual void buildSideDish() = 0;

        virtual Meal getMeal() = 0;

        virtual ~MealBuilder() = default;
};

class KidsMealBuilder : public MealBuilder {
    public:
        void buildMainCourse() override {
            meal.setMainCourse("Chicken Nuggets");
        }

        void buildDrink() override {
            meal.setDrink("Apple Juice");
        }

        void buildDessert() override {
            meal.setDessert("Ice Cream");
        }

        void buildSideDish() override {
            meal.setSideDish("French Fries");
        }

        Meal getMeal() override {
            return meal;
        }
};

class VegetarianMealBuilder : public MealBuilder {
    public:
        void buildMainCourse() override {
            meal.setMainCourse("Veggie Burger");
        }

        void buildDrink() override {
            meal.setDrink("Orange Juice");
        }

        void buildDessert() override {
            meal.setDessert("Fruit");
        }

        void buildSideDish() override {
            meal.setSideDish("Salad");
        }

        Meal getMeal() override {
            return meal;
        }
};

class LuxuryMealBuilder : public MealBuilder {
    public:
        void buildMainCourse() override {
            meal.setMainCourse("Steak");
        }

        void buildDrink() override {
            meal.setDrink("Wine");
        }

        void buildDessert() override {
            meal.setDessert("Cheesecake");
        }

        void buildSideDish() override {
            meal.setSideDish("Grilled Vegetables");
        }

        Meal getMeal() override {
            return meal;
        }
};

class MealDirector {
    public:
        Meal createMeal(MealBuilder& builder) {
            builder.buildMainCourse();
            builder.buildDrink();
            builder.buildDessert();
            builder.buildSideDish();
            return builder.getMeal();
        }
};

int main () {
    MealDirector Director;
    KidsMealBuilder Kids;
    VegetarianMealBuilder Vegetar;
    LuxuryMealBuilder Luxury;

    Meal KidsMeal = Director.createMeal(Kids);
    Meal VegetarMeal = Director.createMeal(Vegetar);
    Meal LuxuryMeal = Director.createMeal(Luxury);

    KidsMeal.printm();
    std::println();
    VegetarMeal.printm();
    std::println();
    LuxuryMeal.printm();

    return 0;
}

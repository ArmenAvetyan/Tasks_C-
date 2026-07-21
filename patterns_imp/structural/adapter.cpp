#include <print>
#include <vector>

class TemperatureSensor {
    public:
        virtual double getTemperatureCelsius() const = 0;
        virtual ~TemperatureSensor() = default;
};

class OldFahrenheitSensor {
    public:
        double getTemperatureFahrenheit() {
            return 98.6;
        }
};

class FahrenheitToCelsiusAdapter : public TemperatureSensor {
    private:
        OldFahrenheitSensor* fahrenheit;

    public:
        FahrenheitToCelsiusAdapter(OldFahrenheitSensor* oldfahr) : fahrenheit(oldfahr) {}

        double getTemperatureCelsius() const override {
            return (fahrenheit->getTemperatureFahrenheit() - 32) * 5 / 9;
        }
};

class ModernCelsiusSensor : public TemperatureSensor {
    public:
        double getTemperatureCelsius() const override {
            return 22.5;
        }
};

int main () {
    OldFahrenheitSensor oldSensor;
    FahrenheitToCelsiusAdapter adapter (&oldSensor);

    ModernCelsiusSensor modern;

    std::vector<TemperatureSensor*> vec;
    vec.push_back(&adapter);
    vec.push_back(&modern);

    for(auto x : vec)
        std::println("Temperature in Celsius: {}°C", x->getTemperatureCelsius());

    return 0;
}

#include <string>
#include <print>

class Logger {
    private:
        Logger() = default;
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;

    public:
        static Logger& getInstance() {
            static Logger instance;
            return instance;
        }

        void log(const std::string& message) {
            std::println("[LOG]: {}", message);
        }
};

int main () {
    Logger& i1 {Logger::getInstance()};
    Logger& i2 {Logger::getInstance()};
    if(&i1 == &i2) std::println("Singleton works!");
    Logger::getInstance().log("Application started");
    Logger::getInstance().log("Performing some operation...");
    Logger::getInstance().log("Application exiting");

    return 0;
}

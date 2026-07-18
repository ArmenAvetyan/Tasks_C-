#include <iostream>
#include <print>
#include <string>
#include <memory>
#include <unordered_map>
#include <functional>

class Notification {
    public:
        virtual void notify() const = 0;
        virtual ~Notification() = default;
};

class EmailNotification : public Notification {
    public:
        void notify() const override {
            std::println("Sending Email Notification");
        }
};

class SMSNotification : public Notification {
    public:
        void notify() const override {
            std::println("Sending SMS Notification");
        }
};

class PushNotification : public Notification {
    public:
        void notify() const override {
            std::println("Sending Push Notification");
        }
};

class NotificationFactory {
    public:
        static std::unique_ptr<Notification> createNotification(const std::string& type) {
            static const std::unordered_map<std::string,
                         std::function<std::unique_ptr<Notification>()>> creators = 
                         {
                            {"email", [] {return std::make_unique<EmailNotification>(); }},
                            {"sms", [] {return std::make_unique<SMSNotification>(); }},
                            {"push", [] {return std::make_unique<PushNotification>(); }}
                         };

            auto it = creators.find(type);
            if(it != creators.end())
                return it->second();
        
            return nullptr;
        }
};

int main () {
    std::string type;
    std::print("Enter notification type (email/sms/push): ");
    std::cin >> type;

    std::unique_ptr<Notification> notification = NotificationFactory::createNotification(type);

    if(notification)
        notification->notify();
    else
        std::println("Invalid notification type!");

    return 0;
}

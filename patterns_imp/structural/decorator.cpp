#include <print>
#include <string>
#include <unordered_map>

class Message {
    public:
        virtual std::string getText(const std::string& message) const = 0;
        
        virtual ~Message() = default;
};

class PlainMessage : public Message {
    public:
        std::string getText(const std::string& message) const override {
            return message;
        }
};

class UpperCaseDecorator : public Message {
    private:
        Message* message;
    public:
        UpperCaseDecorator(Message* msg) : message(msg) {}

        std::string getText(const std::string& msg) const override {
            std::string text {message->getText(msg)};

            for (char& c : text)
                c = std::toupper(c);

            return text;
        }
};

class LowerCaseDecorator : public Message {
    private:
        Message* message;
    public:
        LowerCaseDecorator(Message* msg) : message(msg) {}

        std::string getText(const std::string& msg) const override {
            std::string text {message->getText(msg)};

            for (char& c : text)
                c = std::tolower(c);

            return text;
        }
};

class EncryptedMessageDecorator : public Message {
    private:
        Message* message;
        std::unordered_map<char, char> cipher;
    public:
        EncryptedMessageDecorator(Message* msg, const std::unordered_map<char, char>& c)
            : message(msg), cipher(c) {}

        std::string getText(const std::string& msg) const override {
            std::string text {message->getText(msg)};

            for (char& c : text) {
                auto It = cipher.find(c);

                if(It != cipher.end())
                    c = It->second;
            }
            return text;
        }
};

class DecryptedMessageDecorator : public Message {
    private:
        Message* message;
        std::unordered_map<char, char> rcipher;
    public:
        DecryptedMessageDecorator(Message* msg,
            const std::unordered_map<char, char>& c) : message(msg) {
                for (auto& p : c)
                    rcipher[p.second] = p.first;
        }

        std::string getText(const std::string& msg) const override {
            std::string text {message->getText(msg)};

            for (char& c : text) {
                auto It = rcipher.find(c);

                if(It != rcipher.end())
                    c = It->second;
            }
            return text;
        }
};

int main () {
    PlainMessage plain;

    UpperCaseDecorator upper(&plain);
    LowerCaseDecorator lower(&plain);

    std::unordered_map<char, char> cipher = {
        {'A','Q'}, {'B','W'}, {'C','E'}, {'D','R'}, {'E','T'}, {'F','Y'},
        {'G','U'}, {'H','I'}, {'I','O'}, {'J','P'}, {'K','A'}, {'L','S'},
        {'M','D'}, {'N','F'}, {'O','G'}, {'P','H'}, {'Q','J'}, {'R','K'},
        {'S','L'}, {'T','Z'}, {'U','X'}, {'V','C'}, {'W','V'}, {'X','B'},
        {'Y','N'}, {'Z','M'},
        // Lowercase letters
        {'a','q'}, {'b','w'}, {'c','e'}, {'d','r'}, {'e','t'}, {'f','y'},
        {'g','u'}, {'h','i'}, {'i','o'}, {'j','p'}, {'k','a'}, {'l','s'},
        {'m','d'}, {'n','f'}, {'o','g'}, {'p','h'}, {'q','j'}, {'r','k'},
        {'s','l'}, {'t','z'}, {'u','x'}, {'v','c'}, {'w','v'}, {'x','b'},
        {'y','n'}, {'z','m'}
    };

    EncryptedMessageDecorator encrypted(&upper, cipher);
    DecryptedMessageDecorator decrypted(&encrypted, cipher);

    std::string text = "Hello, World!";

    std::println("Original: {}", plain.getText(text));
    std::println("Uppercase: {}", upper.getText(text));
    std::println("Encrypted: {}", encrypted.getText(text));
    std::println("Decrypted: {}", decrypted.getText(text));
    std::println("Lowercase: {}", lower.getText(text));

    return 0;
}

#include <print>

class Device {
    public:
        virtual bool isEnabled() const = 0;
        virtual void enable() = 0;
        virtual void disable() = 0;
        virtual int getVolume() const = 0;
        virtual void setVolume(int lv) = 0;

        virtual ~Device() = default;
};

class TV : public Device {
    private:
        bool enabled {false};
        int volume {};

    public:
        bool isEnabled() const override {
            return enabled;
        }

        void enable() override {
            enabled = true;
            std::println("TV is now ON");
        }

        void disable() override {
            enabled = false;
            std::println("TV is now OFF");
        }

        int getVolume() const override {
            return volume;
        }

        void setVolume(int lv) override {
            volume = lv;
            std::println("TV volume: {}", volume);
        }
};

class Radio : public Device {
    private:
        bool enabled {false};
        int volume {};

    public:
        bool isEnabled() const override {
            return enabled;
        }

        void enable() override {
            enabled = true;
            std::println("Radio is now ON");
        }

        void disable() override {
            enabled = false;
            std::println("Radio is now OFF");
        }

        int getVolume() const override {
            return volume;
        }

        void setVolume(int lv) override {
            volume = lv;
            std::println("TV volume: {}", volume);
        }
};

class RemoteControl {
    protected:
        Device* device;
    public:
        RemoteControl(Device* d) : device(d) {}

        virtual void togglePower() = 0;
        virtual void volumeUp(int l = 1) = 0;
        virtual void volumeDown(int l = 1) = 0;

        virtual ~RemoteControl() = default;
};

class AdvancedRemoteControl : public RemoteControl {
    public:
        AdvancedRemoteControl(Device* d) : RemoteControl(d) {}

        void togglePower() override {
            if(device->isEnabled())
                device->disable();
            else
                device->enable();
        }

        void volumeUp(int l = 1) override {
            device->setVolume(device->getVolume() + l);
        }

        void volumeDown(int l = 1) override {
            device->setVolume(device->getVolume() - l);
        }

        void mute() {
            device->setVolume(0);
            std::println("Device is muted");
        }
};

int main () {
    TV tv;
    Radio radio;

    AdvancedRemoteControl remc(&tv);
    AdvancedRemoteControl aremc(&radio);

    remc.togglePower();
    remc.volumeUp(50);
    remc.volumeDown();
    remc.mute();

    std::println();

    aremc.togglePower();
    aremc.volumeUp(30);
    aremc.volumeDown(5);
    aremc.mute();

    return 0;
}

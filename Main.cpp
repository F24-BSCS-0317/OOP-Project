#include <iostream>
#include <string>
using namespace std;

class SmartDevice {
protected:
    string name;
    bool isOn;
    string deviceType;

public:
    SmartDevice(string deviceName, string type) : name(deviceName), isOn(false), deviceType(type) 
    {

    }

    virtual ~SmartDevice() 
    {
        cout << "Device [" << name << "] removed from system." << endl;
    }

    virtual void turnOn()
    {
        if (isOn)
        {
            cout << name << " is already ON!" << endl;
        }
        else
        {
            isOn = true;
            cout << name << " turned ON." << endl;
        }
    }

    virtual void turnOff() 
    {
        if (!isOn) 
        {
            cout << name << " is already OFF!" << endl;
        }
        else 
        {
            isOn = false;
            cout << name << " turned OFF." << endl;
        }
    }

    virtual int powerUsage() = 0;
    virtual void display() = 0;

    string getName() const
    { 
        return name;
    }
    bool getStatus() const
    { 
        return isOn;
    }
    string getType() const
    { 
        return deviceType;
    }

    virtual void increaseValue(int value) 
    {
        cout << "Operation not supported for this device!" << endl;
    }

    virtual void decreaseValue(int value)
    {
        cout << "Operation not supported for this device!" << endl;
    }

    friend ostream& operator<<(ostream& out, SmartDevice* device) 
    {
        device->display();
        return out;
    }
};

class Light : public SmartDevice
{
private:
    int brightness;

public:
    Light(string name) : SmartDevice(name, "Light"), brightness(0) 
    {

    }

    void turnOn() override
    {
        if (isOn)
        {
            cout << name << " is already ON!" << endl;
        }
        else 
        {
            SmartDevice::turnOn();
            brightness = 50;
        }
    }

    void turnOff() override 
    {
        if (!isOn) 
        {
            cout << name << " is already OFF!" << endl;
        }
        else 
        {
            SmartDevice::turnOff();
            brightness = 0;
        }
    }

    int powerUsage() override
    {
        return isOn ? (brightness * 10) : 0;
    }

    void display() override
    {
        cout << "Light [" << name << "] " << (isOn ? "ON" : "OFF")
            << " | Brightness: " << brightness << "%" << endl;
    }

    Light& operator+(int value) 
    {
        if (isOn && brightness + value <= 100)
        {
            brightness += value;
            cout << "Brightness increased to " << brightness << "%" << endl;
        }
        else if (!isOn)
        {
            cout << "Turn on the light first!" << endl;
        }
        else
        {
            cout << "Maximum brightness reached!" << endl;
        }
        return *this;
    }

    Light& operator-(int value) 
    {
        if (isOn && brightness - value >= 0) 
        {
            brightness -= value;
            cout << "Brightness decreased to " << brightness << "%" << endl;
        }
        else if (!isOn)
        {
            cout << "Turn on the light first!" << endl;
        }
        else
        {
			brightness = 0;
            cout << "Minimum brightness reached!" << endl;
        }
        return *this;
    }

    int getBrightness() const
    { 
        return brightness; 
    }

    void increaseValue(int value) override 
    {
        if (isOn && brightness + value <= 100) 
        {
            brightness += value;
            cout << "Brightness increased to " << brightness << "%" << endl;
        }
        else if (!isOn) 
        {
            cout << "Turn on the light first!" << endl;
        }
        else 
        {
			brightness = 100;
            cout << "Maximum brightness reached!" << endl;
        }
    }

    void decreaseValue(int value) override
    {
        if (isOn && brightness - value >= 0) 
        {
            brightness -= value;
            cout << "Brightness decreased to " << brightness << "%" << endl;
        }
        else if (!isOn)
        {
            cout << "Turn on the light first!" << endl;
        }
        else 
        {
            brightness = 0;
            cout << "Minimum brightness reached!" << endl;
        }
    }
};

class AC : public SmartDevice {
private:
    int temperature;

public:
    AC(string name) : SmartDevice(name, "AC"), temperature(24) 
    {
    
    }

    void turnOn() override 
    {
        if (isOn) 
        {
            cout << name << " is already ON!" << endl;
        }
        else 
        {
            SmartDevice::turnOn();
            temperature = 24;
        }
    }

    void turnOff() override 
    {
        if (!isOn)
        {
            cout << name << " is already OFF!" << endl;
        }
        else
        {
            SmartDevice::turnOff();
        }
    }

    int powerUsage() override
    {
        return isOn ? (1500 - (temperature * 20)) : 0;
    }

    void display() override
    {
        cout << "AC [" << name << "] " << (isOn ? "ON" : "OFF")
            << " | Temperature: " << temperature << " C" << endl;
    }

    AC& operator+(int value) 
    {
        if (isOn && temperature + value <= 30)
        {
            temperature += value;
            cout << "Temperature increased to " << temperature << " C" << endl;
        }
        else if (!isOn) 
        {
            cout << "Turn on the AC first!" << endl;
        }
        else 
        {
            cout << "Maximum temperature reached!" << endl;
        }
        return *this;
    }

    AC& operator-(int value) 
    {
        if (isOn && temperature - value >= 16)
        {
            temperature -= value;
            cout << "Temperature decreased to " << temperature << " C" << endl;
        }
        else if (!isOn)
        {
            cout << "Turn on the AC first!" << endl;
        }
        else
        {
            cout << "Minimum temperature reached!" << endl;
        }
        return *this;
    }

    int getTemperature() const
    {
        return temperature;
    }

    void increaseValue(int value) override 
    {
        if (isOn && temperature + value <= 30)
        {
            temperature += value;
            cout << "Temperature increased to " << temperature << " C" << endl;
        }
        else if (!isOn)
        {
            cout << "Turn on the AC first!" << endl;
        }
        else 
        {
            cout << "Maximum temperature reached!" << endl;
        }
    }

    void decreaseValue(int value) override 
    {
        if (isOn && temperature - value >= 16) 
        {
            temperature -= value;
            cout << "Temperature decreased to " << temperature << " C" << endl;
        }
        else if (!isOn) 
        {
            cout << "Turn on the AC first!" << endl;
        }
        else 
        {
            cout << "Minimum temperature reached!" << endl;
        }
    }
};

class TV : public SmartDevice {
private:
    int volume;

public:
    TV(string name) : SmartDevice(name, "TV"), volume(0)
    {

    }

    void turnOn() override
    {
        if (isOn) 
        {
            cout << name << " is already ON!" << endl;
        }
        else 
        {
            SmartDevice::turnOn();
            volume = 20;
        }
    }

    void turnOff() override
    {
        if (!isOn) 
        {
            cout << name << " is already OFF!" << endl;
        }
        else
        {
            SmartDevice::turnOff();
            volume = 0;
        }
    }

    int powerUsage() override
    {
        return isOn ? 200 : 0;
    }

    void display() override 
    {
        cout << "TV [" << name << "] " << (isOn ? "ON" : "OFF")
            << " | Volume: " << volume << endl;
    }

    TV& operator+(int value)
    {
        if (isOn && volume + value <= 100)
        {
            volume += value;
            cout << "Volume increased to " << volume << endl;
        }
        else if (!isOn)
        {
            cout << "Turn on the TV first!" << endl;
        }
        else
        {
            cout << "Maximum volume reached!" << endl;
        }
        return *this;
    }

    TV& operator-(int value)
    {
        if (isOn && volume - value >= 0)
        {
            volume -= value;
            cout << "Volume decreased to " << volume << endl;
        }
        else if (!isOn) 
        {
            cout << "Turn on the TV first!" << endl;
        }
        else
        {
            cout << "Minimum volume reached!" << endl;
        }
        return *this;
    }

    int getVolume() const
    { 
        return volume;
    }

    void increaseValue(int value) override 
    {
        if (isOn && volume + value <= 100) 
        {
            volume += value;
            cout << "Volume increased to " << volume << endl;
        }
        else if (!isOn)
        {
            cout << "Turn on the TV first!" << endl;
        }
        else
        {
            cout << "Maximum volume reached!" << endl;
        }
    }

    void decreaseValue(int value) override 
    {
        if (isOn && volume - value >= 0)
        {
            volume -= value;
            cout << "Volume decreased to " << volume << endl;
        }
        else if (!isOn) 
        {
            cout << "Turn on the TV first!" << endl;
        }
        else 
        {
            cout << "Minimum volume reached!" << endl;
        }
    }
};

class Door : public SmartDevice {
private:
    bool locked;

public:
    Door(string name) : SmartDevice(name, "Door"), locked(true) 
    {

    }

    void turnOn() override 
    {
        cout << "Doors don't have ON/OFF state. Use lock/unlock instead." << endl;
    }

    void turnOff() override 
    {
        cout << "Doors don't have ON/OFF state. Use lock/unlock instead." << endl;
    }

    void lock() 
    {
        if (locked)
        {
            cout << name << " is already locked!" << endl;
        }
        else 
        {
            locked = true;
            cout << name << " locked." << endl;
        }
    }

    void unlock()
    {
        if (!locked)
        {
            cout << name << " is already unlocked!" << endl;
        }
        else
        {
            locked = false;
            cout << name << " unlocked." << endl;
        }
    }

    int powerUsage() override
    {
        return 0;
    }

    void display() override
    {
        cout << "Door [" << name << "] " << (locked ? "Locked" : "Unlocked") << endl;
    }

    bool isLocked() const { return locked; }
};

class SmartHome {
private:
    SmartDevice* devices[10];
    int deviceCount;

public:
    SmartHome() : deviceCount(0)
    {
        for (int i = 0; i < 10; i++)
        {
            devices[i] = nullptr;
        }
    }

    ~SmartHome()
    {
        cout << "\n--- Cleaning up Smart Home ---" << endl;
        for (int i = 0; i < deviceCount; i++)
        {
            delete devices[i];
        }
    }

    void addDevice(SmartDevice* device)
    {
        if (deviceCount < 10) 
        {
            devices[deviceCount++] = device;
            cout << "Device added: " << device->getName() << endl;
        }
        else
        {
            cout << "Maximum device limit reached!" << endl;
        }
    }

    void showStatus()
    {
        cout << "\n--- SMART HOME STATUS ---" << endl;
        for (int i = 0; i < deviceCount; i++)
        {
            cout << devices[i];
        }
    }

    int totalPowerUsage()
    {
        int total = 0;
        for (int i = 0; i < deviceCount; i++)
        {
            total += devices[i]->powerUsage();
        }
        return total;
    }

    SmartDevice* getDevice(int index)
    {
        if (index >= 0 && index < deviceCount) 
        {
            return devices[index];
        }
        return nullptr;
    }

    int getDeviceCount() const
    {
        return deviceCount;
    }
};

class User {
private:
    string name;

public:
    User(string userName) : name(userName)
    {
    
    }

    void controlHome(SmartHome& home) 
    {
        int choice, index, value;
        bool running = true;
		cout << "User Logged in: " << name << endl;
        while (running)
        {
            cout << "\n====== SMART HOME MENU ======" << endl;
            cout << "1. Turn ON device" << endl;
            cout << "2. Turn OFF device" << endl;
            cout << "3. Increase value (+)" << endl;
            cout << "4. Decrease value (-)" << endl;
            cout << "5. Lock/Unlock Door" << endl;
            cout << "6. Show status" << endl;
            cout << "7. Show total power usage" << endl;
            cout << "0. Exit" << endl;
            cout << "=============================" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "1. Living Room Light" << endl;
                cout << "2. Bedroom AC" << endl;
                cout << "3. Hall TV" << endl;
                cout << "4. Main Door" << endl;
                cout << "Select a device to control (1-4): ";
                cin >> index;
                index--;
                if (home.getDevice(index) != nullptr) 
                {
                    home.getDevice(index)->turnOn();
                }
                else
                {
                    cout << "Invalid device index!" << endl;
                }
                break;

            case 2:
                cout << "1. Living Room Light" << endl;
                cout << "2. Bedroom AC" << endl;
                cout << "3. Hall TV" << endl;
                cout << "4. Main Door" << endl;
                cout << "Select a device to control (1-4): ";
                cin >> index;
                index--;
                if (home.getDevice(index) != nullptr) 
                {
                    home.getDevice(index)->turnOff();
                }
                else 
                {
                    cout << "Invalid device index!" << endl;
                }
                break;

            case 3:
                cout << "1. Living Room Light" << endl;
                cout << "2. Bedroom AC" << endl;
                cout << "3. Hall TV" << endl;
                cout << "4. Main Door" << endl;
                cout << "Select a device to control (1-4): ";
                cin >> index;
                index--;
                cout << "Enter value to increase: ";
                cin >> value;

                if (home.getDevice(index) != nullptr) 
                {
                    home.getDevice(index)->increaseValue(value);
                }
                else 
                {
                    cout << "Invalid device index!" << endl;
                }
                break;

            case 4:
                cout << "1. Living Room Light" << endl;
                cout << "2. Bedroom AC" << endl;
                cout << "3. Hall TV" << endl;
                cout << "4. Main Door" << endl;
                cout << "Select a device to control (1-4): ";
                cin >> index;
                index--;
                cout << "Enter value to decrease: ";
                cin >> value;

                if (home.getDevice(index) != nullptr)
                {
                    home.getDevice(index)->decreaseValue(value);
                }
                else 
                {
                    cout << "Invalid device index!" << endl;
                }
                break;

            case 5:
				index = 3; 
                if (home.getDevice(index) != nullptr && home.getDevice(index)->getType() == "Door") 
                {
                    int lockChoice;
                    cout << "1. Lock | 2. Unlock: ";
                    cin >> lockChoice;
                    Door* door = (Door*)home.getDevice(index);
                    if (lockChoice == 1)
                    {
                        door->lock();
                    }
                    else if (lockChoice == 2)
                    {
                        door->unlock();
                    }
                }
                else
                {
                    cout << "This is not a door!" << endl;
                }
                break;

            case 6:
                home.showStatus();
                break;

            case 7:
                cout << "\nTotal Power Usage: " << home.totalPowerUsage() << " watts" << endl;
                break;

            case 0:
                cout << "\nExiting Smart Home System..." << endl;
                running = false;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        }
    }
};

int main()
{
    cout << "=====================================================" << endl;
    cout << "      Smart Home Simulator – C++ OOP Project        " << endl;
    cout << "=====================================================" << endl;

    SmartHome myHome;

    myHome.addDevice(new Light("Living Room Light"));
    myHome.addDevice(new AC("Bedroom AC"));
    myHome.addDevice(new TV("Hall TV"));
    myHome.addDevice(new Door("Main Door"));

    cout << "\nWelcome to Smart Home Simulator!" << endl;

    string userName;
	cout << "Enter your Name: ";
	getline(cin, userName);
    User user(userName);
    user.controlHome(myHome);

    return 0;
}

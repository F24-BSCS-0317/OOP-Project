#include<iostream>
#include<string>
#include"SmartHome.h"

using namespace std;

SmartDevice::SmartDevice(string deviceName, string type) : name(deviceName), isOn(false), deviceType(type)
{
}

SmartDevice::~SmartDevice()
{
	cout << "Device [" << name << "] removed from system." << endl;
}

void SmartDevice::turnOn()
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

void SmartDevice::turnOff()
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

string SmartDevice::getName() const
{
	return name;
}

bool SmartDevice::getStatus() const
{
	return isOn;
}

string SmartDevice::getType() const
{
	return deviceType;
}

void SmartDevice::increaseValue(int value)
{
	cout << "Operation not supported for this device!" << endl;
}

void SmartDevice::decreaseValue(int value)
{
	cout << "Operation not supported for this device!" << endl;
}

ostream& operator<<(ostream& out, SmartDevice* device)
{
	device->display();
	return out;
}

Light::Light(string name) : SmartDevice(name, "Light"), brightness(0)
{
}

void Light::turnOn()
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

void Light::turnOff()
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

int Light::powerUsage()
{
	return isOn ? (brightness * 2) : 0;
}

void Light::display()
{
	cout << "Device: " << name << " | Type: " << deviceType << " | Status: " << (isOn ? "ON" : "OFF") << " | Brightness: " << brightness << "%" << " | Power Usage: " << powerUsage() << "W" << endl;
}

int Light::getBrightness() const
{
	return brightness;
}

void Light::increaseValue(int value)
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

void Light::decreaseValue(int value)
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

AC::AC(string name) : SmartDevice(name, "AC"), temperature(24)
{
}

void AC::turnOn()
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

void AC::turnOff()
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

int AC::powerUsage()
{
	return isOn ? 1500 : 0;
}

void AC::display()
{
	cout << "Device: " << name << " | Type: " << deviceType << " | Status: " << (isOn ? "ON" : "OFF") << " | Temperature: " << temperature << " C" << " | Power Usage: " << powerUsage() << "W" << endl;
}

int AC::getTemperature() const
{
	return temperature;
}

void AC::increaseValue(int value)
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

void AC::decreaseValue(int value)
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

TV::TV(string name) : SmartDevice(name, "TV"), volume(0)
{
}

void TV::turnOn()
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

void TV::turnOff()
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

int TV::powerUsage()
{
	return isOn ? 100 : 0;
}

void TV::display()
{
	cout << "Device: " << name << " | Type: " << deviceType << " | Status: " << (isOn ? "ON" : "OFF") << " | Volume: " << volume << "%" << " | Power Usage: " << powerUsage() << "W" << endl;
}

int TV::getVolume() const
{
	return volume;
}

void TV::increaseValue(int value)
{
	if (isOn && volume + value <= 100)
	{
		volume += value;
		cout << "Volume increased to " << volume << "%" << endl;
	}
	else if (!isOn)
	{
		cout << "Turn on the TV first!" << endl;
	}
	else
	{
		volume = 100;
		cout << "Maximum volume reached!" << endl;
	}
}

void TV::decreaseValue(int value)
{
	if (isOn && volume - value >= 0)
	{
		volume -= value;
		cout << "Volume decreased to " << volume << "%" << endl;
	}
	else if (!isOn)
	{
		cout << "Turn on the TV first!" << endl;
	}
	else
	{
		volume = 0;
		cout << "Minimum volume reached!" << endl;
	}
}

Door::Door(string name) : SmartDevice(name, "Door"), locked(true)
{
}

void Door::turnOn()
{
	cout << "Operation not supported for Door!" << endl;
}

void Door::turnOff()
{
	cout << "Operation not supported for Door!" << endl;
}

int Door::powerUsage()
{
	return 0;
}

void Door::display()
{
	cout << "Device: " << name << " | Type: " << deviceType << " | Status: " << (isOn ? "ON" : "OFF") << " | Locked: " << (locked ? "Yes" : "No") << " | Power Usage: " << powerUsage() << "W" << endl;
}

bool Door::isLocked() const
{
	return locked;
}

void Door::lock()
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

void Door::unlock()
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

SmartHome::~SmartHome()
{
	cout << "\n--- Cleaning up Smart Home ---" << endl;
	for (int i = 0; i < deviceCount; i++)
	{
		delete devices[i];
	}
}

SmartHome::SmartHome() : deviceCount(0)
{
	for (int i = 0; i < 10; i++)
	{
		devices[i] = nullptr;
	}
}

void SmartHome::addDevice(SmartDevice* device)
{
	if (deviceCount < 10)
	{
		devices[deviceCount++] = device;
		cout << "Device [" << device->getName() << "] added to Smart Home." << endl;
	}
	else
	{
		cout << "Cannot add more devices. Maximum limit reached!" << endl;
	}
}

void SmartHome::showStatus()
{
	cout << "\n--- SMART HOME STATUS ---" << endl;
	for (int i = 0; i < deviceCount; i++)
	{
		cout << devices[i];
	}
}

SmartDevice* SmartHome::getDevice(int index)
{
	if (index >= 0 && index < deviceCount)
	{
		return devices[index];
	}
	return nullptr;
}

int SmartHome::totalPowerUsage()
{
	int total = 0;
	for (int i = 0; i < deviceCount; i++)
	{
		total += devices[i]->powerUsage();
	}
	return total;
}

User::User(string userName) : name(userName)
{
}

void User::controlHome(SmartHome& home)
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


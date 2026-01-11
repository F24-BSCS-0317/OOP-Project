#include<iostream>
#ifndef SMARTHOME_H
#define SMARTHOME_H

using namespace std;

class SmartDevice {
protected:
	string name;
	bool isOn;
	string deviceType;
public:
	SmartDevice(string deviceName, string type);
	virtual ~SmartDevice();
	virtual void turnOn();
	virtual void turnOff();
	virtual int powerUsage() = 0;
	virtual void display() = 0;
	string getName() const;
	bool getStatus() const;
	string getType() const;
	virtual void increaseValue(int value);
	virtual void decreaseValue(int value);
	friend ostream& operator<<(ostream& out, SmartDevice* device);
};

class Light : public SmartDevice {
private:
	int brightness;
public:
	Light(string name);
	void turnOn() override;
	void turnOff() override;
	int powerUsage() override;
	void display() override;
	int getBrightness() const;
	void increaseValue(int value) override;
	void decreaseValue(int value) override;
};

class AC : public SmartDevice {
private:
	int temperature;
public:
	AC(string name);
	void turnOn() override;
	void turnOff() override;
	int powerUsage() override;
	void display() override;
	int getTemperature() const;
	void increaseValue(int value) override;
	void decreaseValue(int value) override;
};

class TV : public SmartDevice {
private:
	int volume;
public:
	TV(string name);
	void turnOn() override;
	void turnOff() override;
	int powerUsage() override;
	void display() override;
	int getVolume() const;
	void increaseValue(int value) override;
	void decreaseValue(int value) override;
};

class Door : public SmartDevice {
private:
	bool locked;
public:
	Door(string name);
	void turnOn() override;
	void turnOff() override;
	int powerUsage() override;
	void display() override;
	bool isLocked() const;
	void lock();
	void unlock();
};

class SmartHome {
private:
	SmartDevice* devices[10];
	int deviceCount;
public:
	SmartHome();
	~SmartHome();
	void addDevice(SmartDevice* device);
	void showStatus();
	SmartDevice* getDevice(int index);
	int totalPowerUsage();
	int getDeviceCount() const;
};

class User {
private:
	string name;
public:
	User(string userName);
	void controlHome(SmartHome& home);
};


#endif 

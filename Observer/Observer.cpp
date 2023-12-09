#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Observer() = default;
};


class Subject {
private:
    std::vector<Observer*> observers;
    std::string state;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update(state);
        }
    }

    void setState(const std::string& newState) {
        state = newState;
        notifyObservers();
    }
};


class ConcreteObserver : public Observer {
private:
    std::string observerName;

public:
    ConcreteObserver(const std::string& name) : observerName(name) {}

    void update(const std::string& message) override {
        std::cout << "Спостерігач " << observerName << " отримав повідомлення: " << message << std::endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Subject subject;

    ConcreteObserver observer1("Спостерігач 1");
    ConcreteObserver observer2("Спостерігач 2");

    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    subject.setState("Новий стан для спостерігачів!");

    return 0;
}
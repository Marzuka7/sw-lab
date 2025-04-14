// NotificationFactory.cpp

#include <iostream>
#include <memory>
using namespace std;

// Product interface
class Notification {
public:
    virtual void send() = 0;
    virtual ~Notification() = default;
};

// Concrete Products
class EmailNotification : public Notification {
public:
    void send() override {
        cout << "Sending Email Notification" << endl;
    }
};

class SMSNotification : public Notification {
public:
    void send() override {
        cout << "Sending SMS Notification" << endl;
    }
};

class PushNotification : public Notification {
public:
    void send() override {
        cout << "Sending Push Notification" << endl;
    }
};

// Creator (Factory)
class NotificationFactory {
public:
    virtual unique_ptr<Notification> createNotification() = 0;
    virtual ~NotificationFactory() = default;
};

// Concrete Factories
class EmailNotificationFactory : public NotificationFactory {
public:
    unique_ptr<Notification> createNotification() override {
        return make_unique<EmailNotification>();
    }
};

class SMSNotificationFactory : public NotificationFactory {
public:
    unique_ptr<Notification> createNotification() override {
        return make_unique<SMSNotification>();
    }
};

class PushNotificationFactory : public NotificationFactory {
public:
    unique_ptr<Notification> createNotification() override {
        return make_unique<PushNotification>();
    }
};

// For running manually (optional)
int main() {
    unique_ptr<NotificationFactory> factory = make_unique<EmailNotificationFactory>();
    auto notification = factory->createNotification();
    notification->send();
    return 0;
}

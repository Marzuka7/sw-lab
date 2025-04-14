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



#include "gtest/gtest.h"
#include "NotificationFactory.cpp" // Include your implementation

TEST(NotificationFactoryTest, EmailNotificationTest) {
    EmailNotificationFactory factory;
    auto notification = factory.createNotification();
    testing::internal::CaptureStdout();
    notification->send();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Sending Email Notification\n");
}

TEST(NotificationFactoryTest, SMSNotificationTest) {
    SMSNotificationFactory factory;
    auto notification = factory.createNotification();
    testing::internal::CaptureStdout();
    notification->send();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Sending SMS Notification\n");
}

TEST(NotificationFactoryTest, PushNotificationTest) {
    PushNotificationFactory factory;
    auto notification = factory.createNotification();
    testing::internal::CaptureStdout();
    notification->send();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Sending Push Notification\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

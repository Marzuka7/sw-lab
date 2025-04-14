// NotificationFactoryTest.cpp

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

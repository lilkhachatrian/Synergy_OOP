#pragma once

#include <chrono>
#include <string>
#include "user.h"
#include "conversation.h"

class Message {
public:
    // Message() = default;
    Message(User * sender, Conversation * conversation, std::chrono::time_point<std::chrono::system_clock> timestamp);
    Message(const Message& rhs);
    Message(Message&& rhs);
    Message& operator= (const Message& rhs);
    Message& operator=(Message&& rhs);

    virtual void clear();
    virtual void display_content() const = 0;
    virtual std::string get_message_type() const = 0;
    virtual ~Message();

protected:
    User* m_sender;
    Conversation* m_conversation;
    std::chrono::time_point<std::chrono::system_clock> m_timestamp;
};
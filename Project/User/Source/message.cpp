#include "message.h"

Message::Message(User* sender, Conversation* conversation, std::chrono::time_point<std::chrono::system_clock> timestamp)
 : m_sender(sender), m_conversation(conversation), m_timestamp(timestamp) {}

Message::Message(const Message& rhs)
 : m_sender(rhs.m_sender), m_conversation(rhs.m_conversation), m_timestamp(rhs.m_timestamp) {}

Message::Message(Message&& rhs)
 : m_sender(rhs.m_sender), m_conversation(rhs.m_conversation), m_timestamp(rhs.m_timestamp) {
    m_sender = nullptr;
    m_conversation = nullptr;
 }

Message& Message::operator= (const Message& rhs) {
    if(this != &rhs){
        clear();
        m_sender = rhs.m_sender;
        m_conversation = rhs.m_conversation;
        m_timestamp = rhs.m_timestamp;
    }
    return *this;
}

Message& Message::operator=(Message&& rhs)
 {
    if(this != &rhs){
        clear();
        m_sender = rhs.m_sender;
        m_conversation = rhs.m_conversation;
        m_timestamp = rhs.m_timestamp;

        m_sender = nullptr;
        m_conversation = nullptr;
    }
    return *this;
}

Message::~Message(){}

void Message::clear() {
    m_sender = nullptr;
    m_conversation = nullptr;
}

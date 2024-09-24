#pragma once

#include <vector>
#include <iostream>

#include "user.h"
#include "message.h"
#include "messagingmanager.h"

class Conversation : public MessagingManager {
public:
    Conversation() = default;
    Conversation(User* user);
    Conversation(User* user, Message* message);
    Conversation(User* user1, User* user2);
    Conversation(const Conversation& rhs) = delete;
    Conversation(Conversation&& rhs) noexcept;
    Conversation& operator=(const Conversation& rhs) = delete;
    Conversation& operator=(Conversation&& rhs) noexcept;
    ~Conversation();

    void addMessage(Message* message);
    void addUser(User* user);
    std::vector<Message*> getMessages() const;
    std::vector<Message*> viewConversationHistory(Conversation* conversation) const override;
    void sendMessage(Message* message) override;
    void receiveMessage(Message* message) override;
    void clear();

private:
    std::vector<User*> m_participants;
    std::vector<Message*> m_message_history;
};

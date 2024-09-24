#pragma once

#include <string>
#include <vector>

#include "messagingmanager.h"

class Message;
class Conversation;

class User : public MessagingManager {
public:
    User() = default;
    User(const std::string& fullName, const std::string& contact);
    User(const User& other) = delete;
    User& operator=(const User& other) = delete;
    User(User&& other) noexcept;
    User& operator=(User&& other) noexcept;
    virtual ~User();

    void createConversation(User& user);
    void sendMessage(Message* message) override;
    void receiveMessage(Message* message) override;
    std::vector<Conversation*> getConversations() const;
    virtual std::vector<Message*> viewConversationHistory(Conversation* conversation) const override;
    void clear();

private:
    std::string m_name;
    std::string m_contact_info;
    std::vector<Conversation*> m_conversations;
};

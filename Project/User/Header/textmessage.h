#pragma once

#include "message.h"
#include "conversation.h"

class TextMessage : public Message {
public:
    TextMessage(const std::string& content, User* sender, Conversation* convo);
    TextMessage(const TextMessage& rhs);
    TextMessage(TextMessage&& rhs) noexcept;
    TextMessage& operator=(const TextMessage& rhs);
    TextMessage& operator=(TextMessage&& rhs) noexcept;
    ~TextMessage();

    void display_content() const override;
    std::string get_message_type() const override;

private:
    std::string m_content;
};
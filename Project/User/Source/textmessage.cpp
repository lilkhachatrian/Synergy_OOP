#include <iostream>

#include "textmessage.h"

TextMessage::TextMessage(const std::string& content, User* sender, Conversation* convo)
 : Message(sender, convo, std::chrono::system_clock::now()), m_content(content) {}

TextMessage::TextMessage(const TextMessage& rhs)
 : Message(rhs), m_content(rhs.m_content) {}

TextMessage::TextMessage(TextMessage&& rhs) noexcept
 : Message(std::move(rhs)), m_content(std::move(rhs.m_content)) {}

TextMessage& TextMessage::operator=(const TextMessage& rhs) {
    if(this != &rhs){
        Message::operator=(rhs);
        m_content = rhs.m_content;
    }
    return *this;
} 

TextMessage& TextMessage::operator=(TextMessage&& rhs) noexcept {
    if(this != &rhs){
        Message::operator=(std::move(rhs));
        m_content = std::move(rhs.m_content);
    }
    return *this;
}

TextMessage::~TextMessage(){
    Message::clear();
}

void TextMessage::display_content() const {
    std::cout << m_content << std::endl;
}

std::string TextMessage::get_message_type() const {
    std::string type = "Text Message";
    return type;
}

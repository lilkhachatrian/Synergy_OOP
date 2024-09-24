#include "conversation.h"

Conversation::Conversation(User* user){
    m_participants.push_back(user);
}

Conversation::Conversation(User* user, Message* message)
    : m_participants(), m_message_history() { 
    m_participants.push_back(user);
    m_message_history.push_back(message);
}

Conversation::Conversation(User* user1, User* user2) : m_participants(), m_message_history() {
    m_participants.push_back(user1);
    m_participants.push_back(user2);
}

Conversation::Conversation(Conversation&& rhs) noexcept
    : m_participants(std::move(rhs.m_participants)),
    m_message_history(std::move(rhs.m_message_history)) {}

Conversation& Conversation::operator=(Conversation&& rhs) noexcept {
    if(this != &rhs){
        clear();
        m_participants = std::move(rhs.m_participants);
        m_message_history = std::move(rhs.m_message_history);
    }
    return *this;
}
Conversation::~Conversation(){
    clear();
}

void Conversation::clear(){
    for(User* user : m_participants){
        delete user;
    }
    m_participants.clear();

    for(Message* message : m_message_history){
        delete message;
    }
    m_message_history.clear();
}

void Conversation::addMessage(Message* message){
    if(message){
        m_message_history.push_back(message);
        std::cout << "Message added." << std::endl;
    }
    else {
        std::cout << "Invalid message." << std::endl;
    }
}

void Conversation::addUser(User* user){
    if(user){
        m_participants.push_back(user);
        std::cout << "User successfully added." << std::endl;
    }
    else {
        std::cout << "User not found." << std::endl;
    }
}

std::vector<Message*> Conversation::getMessages() const {
    return m_message_history;
}

void Conversation::sendMessage(Message* message){
    if(message){
        message->display_content();
        for(User* participant : m_participants){
            participant->receiveMessage(message);
        }
    }
}

void Conversation::receiveMessage(Message* message){
    if(message){
        message->display_content();
        m_message_history.push_back(message);
    }
    else {
        std::cout << "Invalid message." << std::endl;
    }
}

std::vector<Message*> Conversation::viewConversationHistory(Conversation* conversation) const {
    return conversation->getMessages();
}

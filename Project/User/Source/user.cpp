#include "user.h"

#include <iostream>

#include "conversation.h"

User::User(const std::string& fullName, const std::string& contact) 
    : m_name(fullName), m_contact_info(contact) {
        m_conversations.push_back(new Conversation());
    }

User::User(User&& other) noexcept 
    : m_name(std::move(other.m_name)), 
    m_contact_info(std::move(other.m_contact_info)), 
    m_conversations(std::move(other.m_conversations)) {}

User& User::operator=(User&& other) noexcept {
    if(this != &other) {
        for(Conversation* conversation : m_conversations) {
            delete conversation;
        }
        m_name = std::move(other.m_name);
        m_contact_info = std::move(other.m_contact_info);
        m_conversations = std::move(other.m_conversations);
    }
    return *this;
}

void User::clear(){
    for(Conversation* convo : m_conversations){
        delete convo;
    }
    m_conversations.clear();
}

User::~User(){
    clear();
}

void User::createConversation(User& user){
    m_conversations.push_back(new Conversation(this, &user));
}

void User::sendMessage(Message* message){
    if(!m_conversations.empty()){
        m_conversations[0]->addMessage(message);
        std::cout << "Message sent!" << std::endl;
    }
    else {
        std::cout << "Invalid conversation!" << std::endl;
    }
}

void User::receiveMessage(Message* message){
    if(message){
        message->display_content();
    }
}

std::vector<Conversation*> User::getConversations() const {
    return m_conversations;
}

std::vector<Message*> User::viewConversationHistory(Conversation* conversation) const {
    conversation->getMessages();
}

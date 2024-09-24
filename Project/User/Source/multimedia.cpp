#include <iostream>

#include "multimedia.h"

Multimedia::Multimedia(User* sender, Conversation* conversation, const std::string& file_path, MediaType type)
 : Message(sender, conversation, std::chrono::system_clock::now()) {
    m_media_type = type;
    m_file_path = file_path;
 }

Multimedia::Multimedia(const Multimedia& rhs)
 : Message(rhs), m_file_path(rhs.m_file_path), m_media_type(rhs.m_media_type) {}

Multimedia::Multimedia(Multimedia&& rhs)
 : Message(std::move(rhs)), m_file_path(std::move(rhs.m_file_path)), m_media_type(rhs.m_media_type) {}

Multimedia& Multimedia::operator=(const Multimedia& rhs) {
    if(this != &rhs){
        Message::operator=(rhs);
        m_file_path = rhs.m_file_path;
        m_media_type = rhs.m_media_type;
    }
    return *this;
} 

Multimedia& Multimedia::operator=(Multimedia&& rhs){
    if(this != &rhs){
        Message::operator=(std::move(rhs));
        m_file_path = std::move(rhs.m_file_path);
        m_media_type = rhs.m_media_type;
    }
    return *this;
}

void Multimedia::display_content() const {
    std::cout << "See file location: " << m_file_path << std::endl;
}

std::string Multimedia::get_message_type() const {
    switch (m_media_type) {
        case MediaType::Image:
            return "Image";
        case MediaType::Video:
            return "Video";
        case MediaType::File:
            return "File";
        case MediaType::Audio:
            return "Audio";
    }
    return "Unknown";
}
#pragma once
#include "message.h"
#include "conversation.h"
#include <string>

enum MediaType {
    Image,
    Video,
    File,
    Audio
};

class Multimedia : public Message {
public:
    Multimedia(User* sender, Conversation* conversation, const std::string& file_path, MediaType type);
    Multimedia(const Multimedia& rhs);
    Multimedia(Multimedia&& rhs);
    Multimedia& operator= (const Multimedia& rhs);
    Multimedia& operator=(Multimedia&& rhs);

    void display_content() const;
    std::string get_message_type() const;

private:
    std::string m_file_path;
    MediaType m_media_type;
};
#ifndef CHAT_MANAGER_H
#define CHAT_MANAGER_H
#include <chat.h>

namespace chat_manager {
    std::string insert_message(const chat::message&);
    std::string get_messages_after(int id);
    std::string get_all_messages();
    std::string get_article(int id);
};

#endif // CHAT_MANAGER_H

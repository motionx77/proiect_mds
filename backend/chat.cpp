#include "chat.h"
#include <algorithm>
#include <utility>
#include <mutex>
#include <iostream>
std::vector<chat::message> chat::get_messages_after(int id)
{
    std::vector<chat::message> msgs;
    auto it = messages.find(id);
    while(it != messages.end())
        msgs.push_back(it++->second);

    return msgs;
}
std::pair<chat::log::const_iterator, chat::log::const_iterator> chat::get_all_messages()
{
    return {messages.cbegin(), messages.cend()};
}

std::pair<chat::log::const_iterator, chat::log::const_iterator> chat::insert_message(chat::message msg)
{
    static int id;
    msg.id = id++;
    auto it = messages.insert({msg.id, msg});

    return {it.first, messages.cend()};
}

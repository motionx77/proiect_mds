#include "chat.h"
#include <algorithm>
#include <utility>
#include <mutex>
#include <iostream>

chat::iterator_pair chat::get_messages_after(int id)
{
    return {messages.find(id), messages.cend()};
}
chat::iterator_pair chat::get_all_messages()
{
    return {messages.cbegin(), messages.cend()};
}

chat::iterator_pair chat::insert_message(chat::message msg)
{
    static int id;
    msg.id = id++;
    auto it = messages.insert({msg.id, msg});

    return {it.first, messages.cend()};
}

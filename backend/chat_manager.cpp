#include "chat_manager.h"
#include <json/json.h>
static chat chat_room;

std::string to_string(const chat::timestamp_t& ts) {
    std::time_t ct = std::chrono::system_clock::to_time_t(ts);
    std::ostringstream stream;
    stream << ct;
    return stream.str();
    // sau std::ctime(&ct);
}

template<typename It>
static std::string serialize_messages(It first, It end) {
    Json::Value messages(Json::arrayValue);
    for(auto it = first; it != end; ++it) {
        Json::Value msg_entry(Json::arrayValue);
        chat::message message = it->second;

        Json::Value id = std::to_string(message.id);
        Json::Value timestamp = to_string(message.timestamp);
        Json::Value sender = message.sender;
        Json::Value msg = message.msg;

        msg_entry.append(id);
        msg_entry.append(timestamp);
        msg_entry.append(sender);
        msg_entry.append(msg);
        messages.append(msg_entry);
    }
    return messages.toStyledString();
}

std::string chat_manager::insert_message(const chat::message &msg)
{
    auto iterators = chat_room.insert_message(msg);
    return serialize_messages(iterators.first, iterators.second);
}

std::string chat_manager::get_messages_after(int id)
{
    auto iterators = chat_room.get_messages_after(id);
    return serialize_messages(iterators.first, iterators.second);
}


std::string chat_manager::get_all_messages()
{
    auto iterators = chat_room.get_all_messages();
    return serialize_messages(iterators.first, iterators.second);
}

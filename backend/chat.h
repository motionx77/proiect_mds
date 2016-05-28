#ifndef CHAT_H
#define CHAT_H

#include <string>
#include <vector>
#include <chrono>
#include <set>
#include <map>
#include <functional>
class chat
{
public:
    typedef std::chrono::system_clock::time_point timestamp_t;
    struct message {
        int id;
        timestamp_t timestamp;
        std::string sender, msg;
        message() = default;
        message(int id, timestamp_t t, const std::string &sender, const std::string& msg) : id(id), timestamp(t), sender(sender), msg(msg) {}
    };
    typedef std::map<int, message> log;
    std::vector<message> get_messages_after(int);
    std::pair<log::const_iterator, log::const_iterator> get_all_messages();
    std::pair<log::const_iterator, log::const_iterator> insert_message(message);
private:
    log messages;
};


#endif // CHAT_H

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
    typedef std::pair<log::const_iterator, log::const_iterator> iterator_pair;

    iterator_pair get_messages_after(int);
    iterator_pair get_all_messages();
    iterator_pair insert_message(message);
private:
    log messages;
};


#endif // CHAT_H

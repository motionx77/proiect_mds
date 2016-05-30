#include "routes.h"

#include <http/request.h>
#include <http/resolution.h>
#include <json/json.h>
#include <iostream>
#include "chat_manager.h"

static http::response get_all_messages(http::request r) {
    auto text = chat_manager::get_all_messages();
    return {r, text};
}

static http::response insert_message(http::request r) {
    Json::Value root;
    Json::Reader reader;
    if(reader.parse(r.body.c_str(), root)) {
        chat::message msg;
        msg.timestamp = std::chrono::high_resolution_clock::now();
        msg.sender = root.get("sender", "").asString();
        msg.msg = root.get("message", "").asString();

        return msg.sender != "" && msg.msg != "" ?
                    http::response{r, chat_manager::insert_message(msg)} :
                    http::response{r, http::InternalServerError};
    }

    return {r, http::InternalServerError};
}

static http::response get_messages_after_id(http::request r) {
    auto components = r.split_url();
    if(components.size() >= 3) {
        auto id = std::atoi(components[2].c_str());
        return {r, chat_manager::get_messages_after(id)};
    } else {
        return {r, http::InternalServerError};
    }
}

static http::response fetch_article(http::request r) {
    auto components = r.split_url();
    if(components.size() >= 2) {
        auto id = std::atoi(components[1].c_str());
        return {r, chat_manager::get_article(id)};
    } else {
        return {r, http::InternalServerError};
    }
}


void add_routes(web::server &server)
{
    server.add_route(http::method::Get, std::regex{"\\/$"}, [](http::request req) {
        http::response response{req, http::Found};
        response.set("Location", "index.html");
        return response;
    });
    server.add_route(http::method::Get, std::regex{"\\/chat\\/get_all_messages$"}, ::get_all_messages);
    server.add_route(http::method::Get, std::regex{"\\/chat\\/get_messages_after\\/(\\d+)$"}, ::get_messages_after_id);
    server.add_route(http::method::Post, std::regex{"\\/chat\\/insert_message$"}, ::insert_message);
    server.add_route(http::method::Get, std::regex{"\\/articles\\/(\\d+)$"}, ::fetch_article);
}

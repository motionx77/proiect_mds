#include <server/server.h>
#include "routes.h"
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

#include <iostream>
int main(int argc, char** argv)
{
    web::server server(1234);
    configuration settings;
    settings.root_path = "/home/vladimir/Documents/proiect_mds/assets";
    settings.max_connections = 1000;
    settings.default_max_age = 99999999;
    try {
        server.init();
    } catch(const web::server::port_in_use& e) {
        std::cerr << "Port " << e.port << " is in use!" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    add_routes(server);
    server.set_config(settings);
    server.run();
    return 0;
}


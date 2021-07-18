/*************************************************************************
 *  Copyright (C) 2021 by Pranav Gade <pranavgade20@gmail.com>           *
 *                                                                       *
 *  This program is free software; you can redistribute it and/or        *
 *  modify it under the terms of the GNU General Public License as       *
 *  published by the Free Software Foundation; either version 3 of       *
 *  the License, or (at your option) any later version.                  *
 *                                                                       *
 *  This program is distributed in the hope that it will be useful,      *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of       *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        *
 *  GNU General Public License for more details.                         *
 *                                                                       *
 *  You should have received a copy of the GNU General Public License    *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.*
 *************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <thread>
#include <chrono>
#include "networking/ServerSocket.h"
#include "networking/Socket.h"
#include "networking/Request.h"
#include "networking/Response.h"
#include "pots/Pot.h"
#include "pots/CoffeePot.h"
#include "pots/DecafPot.h"
#include "pots/TeaPot.h"

/**
 * The entrypoint to our program. It takes in the port and pot type, ans starts a ServerSocket to
 * listen at the specified port. When a request is received, it uses the brew method of the appropriate
 * pot to brew your coffee and return  the correct response
 * @param argc
 * @param argv
 * @return nothing, it listens forever
 */
int main(int argc, char **argv) {
    ServerSocket serverSocket((std::stoi(argv[1])));
    Pot *pot;
    if (strcmp(argv[2], "coffeepot") == 0) {
        pot = new CoffeePot;
    } else if (strcmp(argv[2], "decafpot") == 0) {
        pot = new DecafPot;
    } else if (strcmp(argv[2], "teapot") == 0) {
        pot = new TeaPot;
    } else pot = new Pot;

    std::cout << "listening as a " << argv[2] << " on port " << argv[1] << std::endl;

    std::list<std::thread*>* threads = new std::list<std::thread*>;
    auto gc = [=]{
        while (true) {
            std::cout << threads->size() << std::endl;
            if (threads->size() == 0) std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            else {
                std::thread* obj = threads->front();
                std::cout << "trying to clean a thread!" << std::endl;
                threads->pop_front();
                std::cout << "trying to join a thread!" << std::endl;
                obj->join();
                std::cout << "joined a thread!" << std::endl;
                delete obj;
                std::cout << "cleaned a thread!" << std::endl;
            }
        }
    };
    std::thread garbage_collector(gc);

    while (true) {
        Socket *socket = serverSocket.accept();
        auto lambda = [=](Socket* socket) {
            Request *request = new Request(socket);
            Response *response = pot->brew(request);
            response->sendResponse(socket);
            std::cout << "Response sent." << std::endl;
            socket->close();
            delete socket;
            delete request;
            delete response;
        };
        threads->push_back(new std::thread(lambda, socket));
    }

    garbage_collector.join();

    return 0;
}

/*************************************************************************
 *  Copyright (C) 2020 by Pranav Gade <pranavgade20@gmail.com>           *
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
#include "networking/ServerSocket.h"
#include "networking/Socket.h"
#include "networking/Request.h"
#include "networking/Response.h"
#include "pots/Pot.h"
#include "pots/CoffeePot.h"
#include "pots/TeaPot.h"

int main(int argc, char** argv) {
    ServerSocket serverSocket((std::stoi(argv[1])));
    Pot* pot;
    if (strcmp(argv[2], "coffeepot")) {
        pot = new CoffeePot;
    } else if (strcmp(argv[2], "teapot")) {
        pot = new TeaPot;
    } else pot = new Pot;

    while (true) {
        Socket* socket = serverSocket.accept();
        Request* request = new Request(socket);
        Response* response = pot->brew(request);
        response->sendResponse(socket);
        socket->close();
        delete socket;
        delete request;
        delete response;
    }

    return 0;
}

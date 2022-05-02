//
// Created by brostin on 02.05.22.
//

#pragma once


#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "com_handler.h"

using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;

class Server
{
private:
    tcp::acceptor acceptor_;
    void start_accept()
    {
        // socket
        con_handler::pointer connection = con_handler::create((boost::asio::io_context&)acceptor_.get_executor().context());

        // asynchronous accept operation and wait for a new connection.
        acceptor_.async_accept(connection->socket(),
                               boost::bind(&Server::handle_accept, this, connection,
                                           boost::asio::placeholders::error));
    }
public:
//constructor for accepting connection from client
    explicit Server(boost::asio::io_service& io_service): acceptor_(io_service, tcp::endpoint(tcp::v4(), 1234))
    {
        start_accept();
    }
    void handle_accept(con_handler::pointer connection, const boost::system::error_code& err)
    {
        if (!err) {
            connection->start();
        }
        start_accept();
    }
};

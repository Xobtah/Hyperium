//
// Created by xobtah on 10/03/17.
//

#include <iostream>
#include <string>

#include "../src/HTTPRequest.hpp"

int main()
{
    Hyperium::HTTPRequest   req(Hyperium::HTTPRequest::POST, "/");
    std::string             reqRawData;

    req.HeaderField("Lol", "Mdr").Data("PTDR")(reqRawData);
    std::cout << reqRawData << std::endl;
    return (0);
}
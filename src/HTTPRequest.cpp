//
// Created by xobtah on 10/03/17.
//

#include "HTTPRequest.hpp"

namespace Hyperium
{
    /*
     *  Ctor & Dtor
     */

    HTTPRequest::HTTPRequest(Method method, std::string path) : _method(this->MethodToString(method)), _path(path), _httpVersion("HTTP/1.1") {}

    HTTPRequest::~HTTPRequest() {}

    /*
     *  Public member functions
     */

    HTTPRequest &HTTPRequest::HeaderField(std::string key, std::string value)
    {
        _fields[key] = value;
        return (*this);
    }

    HTTPRequest &HTTPRequest::Data(std::string data)
    {
        _data = data;
        return (*this);
    }

    HTTPRequest &HTTPRequest::operator()(std::string &packet)
    {
        packet = _method + " " + _path + " " + _httpVersion + "\n";
        for (std::pair<std::string, std::string> field : _fields)
            packet += field.first + ": " + field.second + "\n";
        packet += "\n" + _data;
        return (*this);
    }

    /*
     *  Private member functions
     */

    std::string HTTPRequest::MethodToString(Method method)
    {
        switch (method)
        {
            case GET:
                return ("GET");
            case POST:
                return ("POST");
            default:
                return ("");
        }
    }
}
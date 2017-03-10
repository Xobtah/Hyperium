//
// Created by xobtah on 10/03/17.
//

#ifndef HYPERIUM_HTTPREQUEST_HPP
#define HYPERIUM_HTTPREQUEST_HPP

#include <string>
#include <map>

namespace Hyperium
{
    class   HTTPRequest
    {
    public:
        enum    Method
        {
            GET,
            POST
        };

        HTTPRequest(Method, std::string);
        ~HTTPRequest();

        HTTPRequest &HeaderField(std::string, std::string);
        HTTPRequest &Data(std::string);

        HTTPRequest &operator()(std::string&);

    private:
        std::string _method;
        std::string _path;
        std::string _httpVersion;
        std::map<std::string, std::string>  _fields;
        std::string _data;

        std::string MethodToString(Method);
    };
}

#endif //HYPERIUM_HTTPREQUEST_HPP

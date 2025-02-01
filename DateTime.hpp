#ifndef __DATETIME__HPP
#define __DATETIME__HPP

#include <iostream>
#include <ctime>
#include "IModule.hpp"

class DateTime: public IModule
{

private:

    std::string currentTime;

public:
    DateTime(){};
    ~DateTime(){};
    void init() ;
    void update() ;
    std::string getDisplayString() const ;
    std::string getGraphicString() const ;

};

#endif
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
    DateTime();
    ~DateTime();
    void init() override;
    void update() override;
    std::string getDisplayString() const override;
    std::string getGraphicString() const override;

};

DateTime::DateTime()
{

}

DateTime::~DateTime()
{

}

#endif
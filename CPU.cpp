/*
** EPITECH PROJECT, 2025
** Droid
** File description:
** c++
*/

#include "CPU.hpp"

void CPU :: init()
{
    std::ifstream ifs("/proc/cpuinfo");
    std::string line;

    while(std::getline(ifs, line)) {
    if (line.find("model name") != std::string::npos) {
    model = line.substr(line.find(":") + 2);
    std  ::cout << model << std::endl;
    }
    if (line.find("cpu cores") != std::string::npos) {
    line = line.substr(line.find(":") + 2);
    core = std ::stoi(line);
    }
    }
    frequency = 0.0;
    update();
}

void CPU   ::update ()
{
    std::ifstream ifs("/proc/stat");
    std::string line;
    std :: string corbeil;
    unsigned long long  user, nice, system, idle, iowait,irq, softirq;
    unsigned long long idleTime;
    size_t total;

    total = 0;
    idleTime = 0;
    for (int i = 0; i < core; i++) {
        getline(ifs, line);
        std::stringstream ss(line);
        ss >> corbeil;
        ss >> user  >> nice >> system >> idle >> iowait >> irq >> softirq;
        total += user + nice + system + idle + iowait + irq + softirq;
        idleTime += iowait + idle;
    }
    double difftotal = total - last_total;
    double diffidle = idleTime - last_idle;

    if (difftotal != 0) {
        last_total = total;
        last_idle = idleTime;
    }

    usage = 100  - ( diffidle / difftotal);

    std::ifstream file("/proc/cpuinfo");

    while (std::getline(file,line)) {
    {
        if (line.find("cpu MHz") != std::string::npos) {
            line = line.substr(line.find(":") + 1);
            frequency = std ::stoi(line);
        }
    }
    }
}

std::string CPU ::getDisplayString() const
{

    return "Model name :" + model + "\n" + "frequency usage: " + std::to_string(frequency) + "%\n";
}

std::string CPU ::getGraphicString() const
{
    return "Model name :" + model + "\n" + "frequency usage: " + std::to_string(frequency) + "%\n";
}
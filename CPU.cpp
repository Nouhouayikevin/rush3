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
    }
    if (line.find("cpu cores") != std::string::npos) {
    line = line.substr(line.find(":") + 2);
    core = std ::stoi(line);
    }
    }
    frequency = 0.0;
    cores_usage.clear();
    update();
}

void CPU   ::update ()
{
    std::ifstream ifs("/proc/stat");
    std::string line;
    std :: string corbeil;
    unsigned long long  user, nice, system, idle, iowait,irq, softirq;
    unsigned long long total = 0;
    unsigned long long idleTime = 0;

    for (int i = 0; i < core; i++) {
        if (!std::getline(ifs, line)) break;
        std::stringstream ss(line);
        ss >> corbeil;
        ss >> user  >> nice >> system >> idle >> iowait >> irq >> softirq;
        total += user + nice + system + idle + iowait + irq + softirq;
        idleTime += iowait + idle;

    double difftotal = total - last_total;
    double diffidle = idleTime - last_idle;

        if(difftotal > 0){  
	    	usage=100-(static_cast<double>(diffidle)/difftotal)*100.00;  
		    cores_usage.push_back(usage);  
	    } else {  
	        cores_usage.push_back(100-(static_cast<double>(diffidle)/difftotal)*100.00);  
	    }
    }

    last_total = total;
    last_idle = idleTime;

    std::ifstream file("/proc/cpuinfo");

    while (std::getline(file,line)) {
    
        if (line.find("cpu MHz") != std::string::npos) {
            line = line.substr(line.find(":") + 1);
            frequency = std ::stod(line);
            break;
        }
    }
}

std::string CPU ::getDisplayString() const
{
    std:: string setence = "";
    int i = 0;
    for (auto const & num: cores_usage) {
        i++;
        setence += "[Core n°" + std::to_string(i) + "..........."+ std::to_string(num) + "%]\n";
    }

    return "Model name :\n" + model + "\n" + "frequency usage: " + std::to_string(frequency) + " MHz\n" + setence;
}

std::string CPU ::getGraphicString() const
{
    std:: string setence = "";
    int i = 0;
    for (auto const & num: cores_usage) {
        if (i == 5)
            break;
        setence += "[Core n°" + std::to_string(i) + "..........."+ std::to_string(num) + "%]\n";
        i++;
    }
    return "Model name :\n" + model + "\n" + "frequency usage: " + std::to_string(frequency) + " MHz\n" + setence;
}
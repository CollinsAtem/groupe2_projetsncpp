#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Config
{
    public:
        Config();
        vector <string> readFiles();
        virtual ~Config();

    protected:

    private:
};

#endif // CONFIG_H

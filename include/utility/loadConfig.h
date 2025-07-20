//
// Created by denre on 20-07-2025.
//

#ifndef LOADCONFIG_H
#define LOADCONFIG_H

#include "./AppStruct.h"
class loadConfig {
public:
    static bool load(const char* filename, AppStruct& cfg);
};



#endif //LOADCONFIG_H

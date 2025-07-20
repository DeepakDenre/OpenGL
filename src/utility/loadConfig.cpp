//
// Created by denre on 20-07-2025.
//

#include <iostream>
#include "../../include/utility/loadConfig.h"
#include "../../include/tinyxml2/tinyxml2.h"
#include "../../include/utility/AppStruct.h"

struct AppStruct;
using namespace tinyxml2;
using namespace std;

bool loadConfig::load(const char *filename, AppStruct &cfg) {
    XMLDocument doc;
    if (doc.LoadFile(filename) != XML_SUCCESS) {
        cerr << "Failed to load " << filename << "\n";
        return false;
    }

    auto *root = doc.FirstChildElement("Config");
    if (!root) return false;

    // Window settings
    auto *win = root->FirstChildElement("Window");
    if (win) {
        win->FirstChildElement("Width")->QueryIntText(&cfg.width);
        win->FirstChildElement("Height")->QueryIntText(&cfg.height);
        cfg.title = win->FirstChildElement("Title")->GetText();
    }

    return true;
}

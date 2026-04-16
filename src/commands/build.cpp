#include <filesystem>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>

namespace fs = std::filesystem;

void cmd_build() {
    std::vector<std::string> files;

    for (auto& p : fs::recursive_directory_iterator("src")) {
        if (p.path().extension() == ".cpp") {
            files.push_back(p.path().string());
        }
    }

    std::string cmd = "g++ ";
    for (auto& f : files) cmd += f + " ";
    cmd += "-std=c++20 -o app";

    std::cout << cmd << "\n";
    std::system(cmd.c_str());
}
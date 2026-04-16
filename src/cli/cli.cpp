#include "cli.h"
#include <iostream>
#include <string>

void cmd_init(const std::string& name);
void cmd_build();
void cmd_run();

int run_cli(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage:\n";
        std::cout << "  Axiom init <project_name>\n";
        std::cout << "  Axiom build\n";
        std::cout << "  Axiom run\n";
        return 1;
    }

    std::string cmd = argv[1];

    if (cmd == "init") {
        if (argc < 3) {
            std::cout << "Error: project name required\n";
            return 1;
        }
        cmd_init(argv[2]);
    }
    else if (cmd == "build") {
        cmd_build();
    }
    else if (cmd == "run") {
        cmd_run();
    }
    else {
        std::cout << "Unknown command\n";
    }

    return 0;
}
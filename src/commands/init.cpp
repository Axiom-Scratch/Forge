#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

void cmd_init(const std::string& name) {
    fs::path root = name;

    if (fs::exists(root)) {
        std::cout << "Error: folder already exists\n";
        return;
    }

    // Create structure
    fs::create_directory(root);
    fs::create_directory(root / "src");

    // main.cpp
    std::ofstream main_file(root / "src/main.cpp");
    main_file << R"(#include <iostream>

int main() {
    std::cout << "Hello from Axiom!\n";
    return 0;
})";
    main_file.close();

    // project.toml
    std::ofstream toml(root / "project.toml");
    toml << "[project]\n";
    toml << "name = \"" << name << "\"\n";
    toml << "version = \"0.1.0\"\n\n";

    toml << "[build]\n";
    toml << "compiler = \"g++\"\n";
    toml << "std = \"c++20\"\n";
    toml << "output = \"" << name << "\"\n";
    toml.close();

    std::cout << "Created project: " << name << "\n";
}
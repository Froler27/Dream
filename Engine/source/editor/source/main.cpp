#include <filesystem>
#include <iostream>
#include <string>
#include <thread>
#include <unordered_map>

#include "runtime/engine.h"

int main(int argc, char** argv)
{
    std::filesystem::path executable_path(argv[0]);
    std::filesystem::path config_file_path = executable_path.parent_path() / "DreamEditor.ini";

    std::cout << executable_path.generic_string() << std::endl;

    Dream::Engine* engine = new Dream::Engine();

    engine->startEngine(config_file_path.generic_string());
    engine->initialize();

//     Dream::PiccoloEditor* editor = new Piccolo::PiccoloEditor();
//     editor->initialize(engine);
// 
//     editor->run();
// 
//     editor->clear();

    engine->run();

    engine->clear();
    engine->shutdownEngine();

    return 0;
}

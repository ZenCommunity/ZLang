#include "core/core.h"

int main(int argc, char * argv[]) {
    string source = argv[1];
    auto * engine = new Engine::Parser;
    engine->run(new App::Types::String(source));
    return 0;
}

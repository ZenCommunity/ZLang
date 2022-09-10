#include "core/core.h"

int main(int argc, char * argv[]) {
    string source = argv[1];
    auto * engine = new Engine;
    engine->start(source);
    engine->debugStorage();
    return 0;
}

#include "core/core.h"

void render(boolean output) {
    cout << "'" << output << "'" << endl;
}

void render(String * output) {
    cout << "'" << output->value_ << "'" << endl;
}

int main() {
    App * instance = AppContainer::GetInstance();

    // Strings
    String hello_world("Hello World");
    String hello_world_camel("hello_world");
    String hello("Hello");
    String world("World");
    String space(" ");
    String h("H");
    String e("e");
    String l("l");
    String o("o");
    String w("W");
    String r("r");
    String d("d");

    render(hello_world.contains(hello));
    render(hello_world.after(hello));
    render(hello_world.before(world));
    render(hello_world.afterLast(space));
    render(hello_world.beforeLast(space));
    render(hello_world.between(o, d));
    render(hello_world.between(h, o));

    cout << endl << "INPUT" << endl << endl;

    render(&hello_world);
    render(&hello);
    render(&world);
    render(&space);

    cout << endl << "VARIABLES" << endl << endl;

    auto * creator = new Variable("creator");
    creator->setValue(new Value(new String("Ian Torres")));

    cout << creator->getName() << endl;
    cout << creator->getValue()
                    ->getString() << endl << endl;

    auto * connected = new Variable("connected");
    connected->setValue(new Value(new Boolean(TRUE)));

    cout << connected->getName() << endl;
    cout << connected->getValue()
                    ->getBoolean() << endl << endl;

    instance->getStorage()
        ->insert(creator);

    cout << endl << "STORAGE" << endl << endl;

    cout << "Variable should exists: " << instance->getStorage()
                                                ->exists(creator->_name) << endl << endl;

    auto connectedOnStorage = instance->getStorage()
                                        ->get(creator->_name);

    cout << connectedOnStorage->getName() << endl;
    cout << connectedOnStorage->getValue()
                            ->getString() << endl << endl;
    return 0;
}

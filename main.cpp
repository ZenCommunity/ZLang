#include "core/core.h"

void render(boolean output)
{
    cout << "'" << output << "'" << endl;
}

void render(String * output)
{
    cout << "'" << output->value_ << "'" << endl;
}

int main() {
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

    Variable creator("creator", String("Ian Torres"));
    Variable verified("verified", Boolean(TRUE));

    cout << verified.getName() << endl;
    cout << verified.getValue() << endl;
    cout << endl;
    Boolean b_verified = get<Boolean>(verified.getValue());
    cout << verified.getName() << endl;
    cout << verified.getValue() << endl;
    cout << verified.getValue() << endl;
    cout << b_verified.isTrue() << endl;

    cout << endl;

    cout << endl << "STORAGE" << endl << endl;

    Storage storage;
    storage.insert(creator);

    cout << "Variable should exists: " << storage.exists(creator._name) << endl;
    Variable connectedOnStorage = storage.get(creator._name);
    cout << connectedOnStorage.getName() << endl;
    cout << connectedOnStorage.getValue() << endl;
    return 0;
}

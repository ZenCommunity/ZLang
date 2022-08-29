#include "core/core.h"


void render(string output)
{
    cout << "'" << output << "'" << endl;
}

void render(boolean output)
{
    cout << "'" << output << "'" << endl;
}

int main() {
    // Strings
    string hello_world = "Hello World";
    string hello_world_camel = "hello_world";
    string hello = "Hello";
    string world = "World";
    string space = " ";
    string h = "H";
    string e = "e";
    string l = "l";
    string o = "o";
    string w = "W";
    string r = "r";
    string d = "d";

    render(String::contains(hello_world, hello));
    render(String::after(hello_world, hello));
    render(String::before(hello_world, world));
    render(String::afterLast(hello_world, space));
    render(String::beforeLast(hello_world, space));
    render(String::between(hello_world, o, d));
    render(String::betweenFirst(hello_world, h, o));

    cout << endl << "INPUT" << endl << endl;

    cout << hello_world << endl;
    cout << hello << endl;
    cout << world << endl;
    cout << space << endl;

    cout << "VARIABLES" << endl << endl;

    Variable p_name;
    p_name._name = "username";

    Value v_string;
    v_string._value = "iantorres@outlook.com";

    p_name.setValue(v_string);

    Variable p_connected;
    p_connected._name = "connected";

    Value v_connected;
    v_connected._value = TRUE;

    p_connected.setValue(v_connected);

    cout << p_name.getName() << endl;
    cout << p_name.getValue() << endl;

    cout << p_connected.getName() << endl;
    cout << p_connected.getValue() << endl;

    cout << endl << "STORAGE" << endl << endl;

    Storage storage;

    storage.insert(p_connected);

    cout << "Variable should exists: " << storage.exists(p_connected._name) << endl;

    Variable s_connected = storage.get(p_connected._name);

    cout << s_connected.getName() << endl;
    cout << s_connected.getValue() << endl;

    return 0;
}

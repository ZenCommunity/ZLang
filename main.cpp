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

    Variable t_name;
    t_name._name = "creator";

    Value t_string;
    t_string._value = String("Ian Torres");

    t_name.setValue(t_string);

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

    Variable t_verified;
    t_verified._name = "verified";

    Value v_verified;
    v_verified._value = Boolean(TRUE);

    t_verified.setValue(v_verified);

    cout << p_name.getName() << endl;
    cout << p_name.getValue() << endl;

    cout << endl;

    cout << p_connected.getName() << endl;
    cout << p_connected.getValue() << endl;

    cout << endl;

    cout << t_name.getName() << endl;
    cout << t_name.getValue() << endl;

    cout << endl;

    Boolean b_verified = get<Boolean>(v_verified._value);
    cout << t_verified.getName() << endl;
    cout << t_verified.getValue() << endl;
    cout << t_verified.getValue() << endl;
    cout << b_verified.isTrue() << endl;

    cout << endl;

    cout << endl << "STORAGE" << endl << endl;

    Storage storage;

    storage.insert(p_connected);

    cout << "Variable should exists: " << storage.exists(p_connected._name) << endl;

    Variable s_connected = storage.get(p_connected._name);

    cout << s_connected.getName() << endl;
    cout << s_connected.getValue() << endl;

    Boolean instanceA(TRUE);
    String instanceB("Hello World");
    TypeValue t_instanceA = instanceA;
    return 0;
}

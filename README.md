# ZLang

Z is a programming language oriented to bring high performance and secure runtime.

## Features

### Optimized from the beginning

Z will not include inefficient instructions on the source code.

### Design based on performance

Z will be designed using performance-first. The code will run as fast as possible.

### Safe oriented language

Z will implement scope management, thread safe and exceptions handlers.

### Extensions by default

Z will implement plugins and libraries.

## Codes using Z

### Input and Output

```Z
➜ nano io 
def name = in.read("What is your name? ")
out.print("Hello ${name}, welcome to Z.")

➜ z io
What is your name? Core
Hello Core, welcome to Z.
```

### Using Strings

```Z
➜ nano strings 
def name = "Ian"
out.print(name.after("I"))

➜ z strings
an
```

### Using Exceptions

```Z
➜ nano exception 
try {
    def name = "Ian"
    out.print(name.after("x"))
} catch {
    default (case) => "Something when wrong",
                      "The error was triggered by ${case.triggered()}.",
                      "The reason was ${case.quotes.reason()}.",
}

➜ z exception
NotFound Exception
==================
Something went wrong
The error was triggered by String::after.
The reason was "The input doesn't have x".
```

### Using Plugins

```Z
➜ nano mysql
#include "core.h"
#include "connection.h"

Plugin mysql = Plugins::define("MySQL", "mysql", PluginScope::GLOBAL);

mysql.defineFunction("connect", [](Parameters){
    connection = MySQL::connection(Parameters.get("host"), Parameters.get("user"), Parameters.get("password"));
    if (!connection->works()) {
        throw new ConnectionRefused(connection->errors());
    }
    return connection;
})

➜ ./compile.sh --with-plugins="mysql"

➜ nano client
try {
    def connection = mysql_connect("localhost", "root", "pasword");
} catch {
    default (case) => case.error()
}

➜ z client
ConnectionRefused Exception
===========================
SQLSTATE[HY000] [2002] Connection Refused
```






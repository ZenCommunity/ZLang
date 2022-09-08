#include "core/core.h"

int main(int argc, char * argv[]) {
    App * instance = AppContainer::GetInstance();

    cout << argc << endl;

    cout << argv[0] << endl;

    return 0;
}

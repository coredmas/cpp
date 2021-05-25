#include <iostream>
#include <typeinfo>
using namespace std;

std::string g_ref = "Test";

std::string& getRef(){
    return g_ref;
}

int main() {
//    auto x = 4;
//    auto y = 3.37;
//    auto ptr = &x;
//    cout << typeid(x).name() << endl
//         << typeid(y).name() << endl
//         << typeid(ptr).name() << endl;

    auto&& test = getRef();
    g_ref = "Test1";
    cout << test << endl;

    return 0;
}

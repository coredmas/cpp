#include <iostream>

#include <stdio.h>
#include <string>

void print(const std::string& name) {
    printf("const value detected:%s\n", name.c_str());
}

void print(std::string& name) {
    printf("lvalue detected%s\n", name.c_str());
}

void print(std::string&& name) {
    printf("rvalue detected:%s\n", name.c_str());
}

int main() {
    std::string name = "lvalue";
    const std::string cname = "cvalue";
    std::string rvalu = "rvalu";

    print(name);
    print(cname);
    print(rvalu + "e");
}
/*
 * void print(const std::string& name) can replace void print(std::string&& name)
 * BUT
 * void print(std::string&& name) can NOT replace void print(const std::string& name)
 * as a result we can not call  print(cname);
 */
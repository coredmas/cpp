#include <iostream>
#include <stdio.h>
#include <string.h>

class String{
public:
    String() = default;
    String(const char* str){
        printf("Created String!\n");
        size_ = strlen(str) + 1;
        data_ = new char[size_];
        memset(data_,'\0',size_);
        memcpy(data_,str,size_);
    }
    String(const String& other){
        printf("Copied String!\n");
        size_ = other.size_;
        data_ = new char[size_];
        memset(data_,'\0',size_);
        memcpy(data_,other.data_,size_);
    }
    String(String&& other){
        printf("Moved String!\n");
        size_ = other.size_;
        data_ = other.data_;
        other.data_ = nullptr;
        other.size_ = 0;
    }
    ~String(){
        printf("Destroyed String!\n");
        size_ = 0;
        delete [] data_;
    }
    void Print(){
        printf("%s \n",data_);
    }
private:
    char* data_;
    int size_;
};
class Entity{
public:
    Entity(const String& str):str_(str){
        printf("Created Entity!\n");
    }
//    Entity(String&& str):str_(str){
//        //inside of this method str is lvalue again!!! so we need to move it again
//        printf("Moved Entity!\n");
//    }
    Entity(String&& str):str_(std::move(str)){
        printf("Moved Entity!\n");
    }
    void PrintName(){
        str_.Print();
    }
    ~Entity(){
        printf("Destroyed Entity!\n");
    }
private:
    String str_;
};

int main() {
    //Entity obj(String("dmas"));
    Entity obj("dmas");
    obj.PrintName();
    //result
//    Created String!
//    Copied String!
//    Created Entity!
//    Destroyed String!
//    dmas
//    Destroyed Entity!
//    Destroyed String!
    return 0;
}

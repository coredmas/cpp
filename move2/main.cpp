#include <iostream>
#include <stdio.h>
#include <string.h>

class String{
public:
    String():data_(nullptr){}
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
    String& operator=(String&& other){
        printf("Moved Assignment String!\n");

        if(this == &other){
            return *this;
        }

        size_ = 0;
        delete [] data_;

        size_ = other.size_;
        data_ = other.data_;
        other.data_ = nullptr;
        other.size_ = 0;
        return *this;
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

int main() {

    String str4;
    String str5("Apple");
    //str4 = str5; //use of deleted function ‘constexpr String& String::operator=(const String&)’
    //str4.operator=(std::move(str5)); works well also
    str4 = std::move(str5);
    //std::move - convert the object to be a temporary. as a result you can steal resources from it
    //result
//Created String!
//Moved Assignment String!
//Destroyed String!
//Destroyed String!

    return 0;
}

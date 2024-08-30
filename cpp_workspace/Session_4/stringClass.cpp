#include <iostream>
#include<cstring>
class sstring{
    const char* string = nullptr;   
    long long length;
public:
    sstring(const char* ptr){
        string = ptr;
        length = strlen(ptr);
    }
    void sPrint(void){
        std::cout<<string<<std::endl;
    }
};

int main(){

    sstring s1("43943897");
    s1.sPrint();
    sstring s2("23424asasweq");
    s2.sPrint();
    return 0;
}
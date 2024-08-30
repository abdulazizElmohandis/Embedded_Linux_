#include <iostream>


class myData{
    public:
    int ID;
    void setter(int ID){
        this->ID = ID;
    }
};

int main(){


    myData obj;
    obj.setter(1);
     std::cout << "ID: " << obj.ID << std::endl;
    return 0;
}





#include <iostream>
#include <sstream>
#include <string>

int main(){
std::string frame = "Aziz 201291 90.9";
std::string name ;
int ID  = 0;
double grade = 0;
std::stringstream ss(frame);
ss >> name >> ID >> grade;
std::cout << "Name: " << name << " ID: " << ID << " Grade: " << grade << std::endl;


}
# Operator Overloading

- Operator overloading is a compile-time polymorphism in which the operator is overloaded to provide the special meaning to the user-defined data type.

### operators cant be overloaded:
- `sizeof`
- `?:`
- `::`
- `.`
- `.*`

logical (&& , || ) lose short-circuit evaluation when overloaded.

```cpp
//example of operator oeverloading

class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}
    Complex operator + (Complex const &obj) {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void print() {
        std::cout << real << " + i" << imag << std::endl;
    }
};
```
 
*Write Notes here*
postfix and prefix increment and decrement operators are overloaded as follows:
```cpp
void operator ++ () //prefix
void operator ++ (int) //postfix

int operator ++ (int){
    int temp = data;
    data++;
    return temp;
}
//return type is int because the value of the object before increment is returned.




```




fanctor example:
```cpp
// Functor example
class Add {
public:
    // Overload operator() to perform addition
    int operator()(int a, int b) const {
        return a + b;
    }
};

int main() {
    // Create an instance of the functor
    Add add;

    // Use the functor to add two numbers
    int result = add(3, 4);

    // Print the result
    std::cout << "Result of addition: " << result << std::endl;

    return 0;
}
```

observe that there is a diffrence between calling the functor and calling the constructor of the class.

```cpp
Add add;
int result = add(3, 4);
//calling the operator() function.
```

```cpp
int result = Add()(3, 4);
//calling the constructor of the class and then calling the operator() function.
//this is a temporary object.
```

call the functor using temperory object and std::function:
```cpp 
std::function<int(int, int)> t = Add();//temp object
int result = t(3, 4);
// smart enough to call the functor
```

### converting operator overloading:
```cpp
class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}
    operator int() { //conversion operator
        return real;
    }
};

int main() {
    Complex c(12, 7);
    int x = c; //conversion operator is called
    std::cout << x << std::endl;
    return 0;
}
```
std::string converting operator overloading:
```cpp
class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}
    operator std::string() { //conversion operator
        return std::to_string(real) + " + i" + std::to_string(imag);
    }
};

int main() {
    Complex c(12, 7);
    std::string s = c; //conversion operator is called
    std::cout << s << std::endl;
    return 0;
}
```

Example of constructor that takes a single argument:
```cpp
#include <iostream>



class Data {
public:
    std::string msg; 
    // Constructor that takes a std::string
    Data( std::string str) : msg(str){}
};

int main(){
    // Create a temporary std::string object
    std::string str = "Hello, World!";
    Data data(str);
    // Pass the temporary std::string object to the Data constructor

    Data d2 = std::string("Hello, World!");
    std::cout << d2.msg << std::endl;
    return 0;
}
```

d2 calls the constructor of the class Data that takes a single argument of type std::string. The temporary std::string object is passed to the constructor of the class Data. The constructor of the class Data initializes the member variable msg with the value of the temporary std::string object. then the temp object is assigned to d2.
like you make this:
```cpp
    Data d2 = Data(std::string("Hello, World!"));
```

Misra rule 12-1-3: All constructors that can be called with a single argument must be declared explicit.

```cpp

    explicit Data( std::string str) : msg(str){}

```
so that the implicit conversion is not allowed.

you have to call the constructor explicitly:
```cpp
    Data d2 = Data(std::string("Hello, World!"));
```
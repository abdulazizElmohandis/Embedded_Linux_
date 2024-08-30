tasks: 
- read articles in the pdf 
- order in constructor parameters
# Constructors


## Delegating Constructors 
- Definition: A constructor that calls another constructor of the same class to reuse code and avoid duplication.


```` cpp
class MyClass {
public:
    int x, y;
    MyClass(int val) : MyClass(val, 0) {}  // Delegating to another constructor
    MyClass(int val1, int val2) { x = val1; y = val2; }
};
````

## Initializer List in constructors
Definition: A special syntax used to initialize member variables directly, before the constructor body executes.

- example:
```cpp
class MyClass {
public:
    int x;
    const int y;
    MyClass(int a, int b) : x(a), y(b) {}  // Initializer list
};
```
### **uisng it with const and Reference Members**
  - initialising refrences and const using initializer list.
  
example:
```cpp
class MyClass {
public:
    int &ref;
    MyClass(int &r) : ref(r) {}  // ref must be initialized using an initializer list
};
```
### explantion: 

Reference Members: When a reference member is declared in a class, it must be bound to an existing variable when the object is created. This binding is done through the initializer list. The reference doesn't go through a phase of being "uninitialized" or "dangling"; it's initialized directly through the initializer list.



- Smaller Compiled Code Size compared to not using initializier list comparing with initialising a member in the constructor and also in the class body.

## Delete
 - prevent to make objects of the class

(MORE INFO LATER)


 # Const Method


 cannot modify any member

 ``` cpp
    class MyClass {
public:
    int getter() const{
        return 1;
    }
    int x, y;
    
};
```
- can modify pramaeters and local variables, static members.

- can modify members using mutable keyword with varibale declaration.
- const instances can only call const methods
- non const instances can call both

 ## MISRA rules in const Methods

 - cant return a pointer or a refrence of a class mem

# Friend class in cpp only  ;( 

can access private members in friend class

```cpp
//example of friend class in cpp
class MyClass {
    friend class MyFriendClass;
    int x;
};

class MyFriendClass {
public:
    void myFriendFunction(MyClass &obj) {
        obj.x = 10;  // Allowed: MyFriendClass is a friend of MyClass
    }
};

```

or friend function

```cpp
class MyClass {
    friend void myFriendFunction(MyClass &obj);
    int x;
};
```

# Static Members
## static member variables rules

#### static members are shared among all objects of the class. and not related to any object. 

- can be accessed using the class name and the scope resolution operator **myClass::x**

- definition of static members is done outside the class
- if static const can be initialized inside the class (but should be integral data type otherwise not)
- static const cant be initialized by parameters of the constructor

## Static Member Functions
static is not related to the instance of the class but related to the class itself.

- cant acess non static members.
- cant access to (this)
```cpp
//example of static member function
class MyClass { 
public:
    static void myStaticFunction() {
        cout << "Static function" << endl;
        x = 10;  // Allowed: x is a static member
    }
    static int x;
};

```
 
- static keyword is not used outside the class when defining the function outside.


# Legacy code
to use c libraries in cpp code we use extern "C" keyword to tell the compiler that the function is in c language.

```cpp 
extern "C" {
    #include "mycfile.h"
}
```

# Regex


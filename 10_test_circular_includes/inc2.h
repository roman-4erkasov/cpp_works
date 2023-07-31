#pragma once
#include <iostream>
#include "inc1.h"

namespace a::c {
    void fun2(){
        std::cout << "fun2"<<std::endl;
        // a::b::fun1();
    }
    void fun21(){
        a::b::fun1();
    }
}
#pragma once
#include <iostream>
#include "inc2.h"

namespace a::b {
    void fun1(){
        std::cout << "fun1"<<std::endl;
    }
    void fun12(){
        a::c::fun2();
    }
}
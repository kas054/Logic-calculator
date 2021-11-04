//
// Created by PC on 04.11.2021.
//

#ifndef LOGIC_CALCULATOR_STACK_H
#define LOGIC_CALCULATOR_STACK_H
#include <iostream>
#include "logicelement.h"
namespace Prog3_3 {
    class Stack{
    private:
        static const int QUOTA = 10;
        int SZ;
        int top;
        int *ar;
    public:
        Stack() :SZ(QUOTA), top(0), ar(new int[QUOTA]){}
        Stack(int el) :SZ(QUOTA), top(1), ar(new int[QUOTA]){ ar[0] = el; }
        Stack(const Stack&);
        Stack(Stack&&);

        ~Stack(){ delete[] ar; }
        Stack &operator =(const Stack &);
        Stack &operator =(Stack &&);
        int push(int);
        int pop(int&);
        Stack & operator +=(const Stack &);
        Stack & operator ()(Stack &);
        int getSize() const { return top; }
        int getMaxSize() const{ return SZ; }
        friend std::ostream & operator <<(std::ostream &, const Stack &);
    };

    class Binar_Operations{
    private:
        LogicElement Or;
        LogicElement And;
        LogicElement Impl;
        LogicElement Xor;
        LogicElement array[4];
    public:
        Binar_Operations();
        int find_answer(int num1, int num2, int oper) const;
        friend int Get_answer(int num1, int num2, int pos);
    };

    class Unar_operations{
    private:
        LogicElement No;
    public:
        Unar_operations();
        int find_answer(int num);

    };

   int Get_answer(int num1, int num2 = 2, int pos = 10);
}
#endif //LOGIC_CALCULATOR_STACK_H

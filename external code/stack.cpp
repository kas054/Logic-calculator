//
// Created by PC on 04.11.2021.
//

#include "stack.h"
namespace Prog3_3{

    Stack::Stack(const Stack &st) :top(st.top), SZ(st.SZ)
    {
        ar = new int[SZ];
        for (int i = 0; i < top; ++i)
            ar[i] = st.ar[i];
    }

    Stack::Stack(Stack &&st):top(st.top), SZ(st.SZ), ar(st.ar)
    {
        st.ar = nullptr;
    }

    Stack & Stack::operator =(const Stack &st)
    {
        if (this != &st){
            top = st.top;
            SZ = st.SZ;
            delete[] ar;
            ar = new int[SZ];
            for (int i = 0; i < top; ++i)
                ar[i] = st.ar[i];
        }
        return *this;
    }

    Stack & Stack::operator =(Stack &&st)
    {
        int tmp = top;
        top = st.top;
        st.top = tmp;
        tmp = SZ;
        SZ = st.SZ;
        st.SZ = tmp;
        int *ptr = ar;
        ar = st.ar;
        st.ar = ptr;
        return *this;
    }

    int Stack::pop(int &el)
    {
        int rc = top - 1;
        if (top > 0)
            el = ar[--top];
        return rc;
    }

    int Stack::push(int el)
    {
        if (top >= SZ){
            SZ += QUOTA;
            int *old = ar;
            ar = new int[SZ];
            for (int i = 0; i < top; ++i)
                ar[i] = old[i];
            delete[] old;
        }
        ar[top++] = el;
        return top;
    }

    Stack & Stack::operator +=(const Stack &st)
    {
        Stack tmp(st);
        int el;
        while (tmp.pop(el) >= 0)
            push(el);
        return *this;
    }

    Stack & Stack::operator ()(Stack &st)
    {
        int el;
        while (st.pop(el) >= 0)
            push(el);
        return *this;
    }
    std::ostream & operator <<(std::ostream &s, const Stack &st)
    {
        const std::string ms[7]{"0", "1", "or", "and", "implication", "XOR", "no"};
        if (st.top == 0)
            s << "Stack is empty";
        else
            for (int i = st.top - 1; i >= 0; --i) {
                s << ms[st.ar[i]] << ' ';
            }
        s << std::endl;
        return s;
    }

    Binar_Operations::Binar_Operations() {
        const Terminal zero(Input,0, 1);
        const Terminal one(Input, 1, 1);
        const Terminal zero_2(Output,0, 1);
        const Terminal one_2(Output, 1, 1);
    for (int i = 0; i < 12; i +=3){
        if (i == 0){
            Or += zero;
            Or += zero;
            Or += zero_2;

            And += zero;
            And += zero;
            And += zero_2;

            Impl += zero;
            Impl += zero;
            Impl += one_2;

            Xor += zero;
            Xor += zero;
            Xor += zero_2;
        }
        else if (i == 3){
            Or += zero;
            Or += one;
            Or += one_2;

            And += zero;
            And += one;
            And += zero_2;

            Impl += zero;
            Impl += one;
            Impl += one_2;

            Xor += zero;
            Xor += one;
            Xor += one_2;
        }
        else if (i == 6){
            Or += one;
            Or += zero;
            Or += one_2;

            And += one;
            And += zero;
            And += zero_2;

            Impl += one;
            Impl += zero;
            Impl += zero_2;

            Xor += one;
            Xor += zero;
            Xor += one_2;
        }
        else if (i == 9){
            Or += one;
            Or += one;
            Or += one_2;

            And += one;
            And += one;
            And += one_2;

            Impl += one;
            Impl += one;
            Impl += one_2;

            Xor += one;
            Xor += one;
            Xor += zero_2;
        }
    }
    array[0] = Or;
    array[1] = And;
    array[2] = Impl;
    array[3] = Xor;
    }

    int Binar_Operations::find_answer(int num1, int num2, int oper) const {
        LogicElement current = (this->array)[oper];
        int answer;
        for (int i = 0; i < 10; i += 3){
            if ((current[i]).getposition() == num1 && (current[i + 1]).getposition() == num2){
                answer = (current[i + 2]).getposition();
                break;
            }
        }
        return answer;
    }

    Unar_operations::Unar_operations() {
        const Terminal zero(Input,0, 1);
        const Terminal one(Input, 1, 1);
        const Terminal zero_2(Output,0, 1);
        const Terminal one_2(Output, 1, 1);
        No += zero;
        No += one_2;
        No += one;
        No += zero_2;
    }

    int Unar_operations::find_answer(int num) {
        int answer;
        for (int i = 0; i < 4; i += 2){
            if (No.positioncheck(i) == num)
                answer = No.positioncheck(i + 1);
        }
        return answer;
    }

    int Get_answer(int num1, int num2, int pos){
        int answer;
        if (num2 == 2) // unar operation
        {
            Unar_operations unar;
            answer = unar.find_answer(num1);
        }
        else{
            Binar_Operations binar;
            answer = binar.find_answer(num1, num2, pos);
        }
        return  answer;
    }
}
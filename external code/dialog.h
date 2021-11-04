//
// Created by PC on 04.11.2021.
//

#ifndef LOGIC_CALCULATOR_DIALOG_H
#define LOGIC_CALCULATOR_DIALOG_H
#include "stack.h"
namespace Menu {
    int chooseVariant(const char *msgs[], int N);
    int Input_num(Prog3_3::Stack* stack, Prog3_3::Stack* stack_p);
    int Choose_operator(Prog3_3::Stack* stack, Prog3_3::Stack* stack_p);
    void start(Prog3_3::Stack* stack);
    template <class V> int getInt(V &a);
}

#endif //LOGIC_CALCULATOR_DIALOG_H

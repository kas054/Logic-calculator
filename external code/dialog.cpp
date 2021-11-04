//
// Created by PC on 04.11.2021.
//

#include "dialog.h"
#include <iostream>
using namespace Prog3_3;
namespace Menu {
    template <class V> int getInt(V &a){
        int n;
        do {
            std::cin >> a;
            n = std::cin.good();
            if (n < 0)
                return 0;
            if (n == 0) {
                printf("%s\n", "Error, try again:");
                std::cin.clear();
                scanf("%*s", 0);
            }
        } while (!n);
        return 1;
    }

    int chooseVariant(const char *msgs[], int N){
        const char *errmsg = "";
        int rc;
        int i, n;
        do{

            std::cout << errmsg << std::endl;
            errmsg = "You are wrong. Try again, please!";

            for(i = 0; i < N; ++i)
                std::cout << msgs[i] << std::endl;
            puts("Make your choice: --> ");
            n = getInt<int>(rc);
            if(n == 0)
                rc = 0;
        } while(rc < 0 || rc >= N);
        return rc;
    }

    int Input_num(Prog3_3::Stack* stack, Prog3_3::Stack* stack_p){
        int number;
        const char *errmsg = "";
        do{
            std::cout << errmsg << std::endl;
            errmsg = "Only 0 or 1";
            getInt <int>(number);
        } while (number != 0 && number != 1);
        stack->push(number);
        stack_p->push(number);
        return 1;
    }

    int Choose_operator(Prog3_3::Stack* stack, Prog3_3::Stack* stack_p){
        const char *msgs[] = {"0 - Or", "1 - And", "2 - Implication", "3 - Xor", "4 - No"};
        const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);
        int number, num1, num2, result;
        const char *errmsg = "";

        std:: cout << "Please, enter: " <<std::endl;
        for(int i = 0; i < NMsgs; ++i)
            std::cout << msgs[i] << std::endl;
        do{
            std::cout << errmsg << std::endl;
            errmsg = "Try again, please";
            getInt <int>(number);
        } while (number != 0 && number != 1 && number != 2 && number != 3 && number != 4);

        stack_p->push(number + 2);

        if (number == 4) {
            stack->pop(num1);
            result = Get_answer(num1);
        }
        else{
            stack->pop(num2);
            stack->pop(num1);
            result = Get_answer(num1, num2, number);
        }
        stack->push(result);
        return 1;
    }

    void start(Prog3_3::Stack* stack)
    {
        std::cout << "Use reverse polish notation" << std::endl;
        int rc;
        Prog3_3::Stack stack_p;
        const char *msgs[] = {"0. Quit", "1. Enter number (0 or 1)", "2. Choose logic operator"};
        const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);
        int (*fptr[])(Prog3_3::Stack* stack, Prog3_3::Stack* stack_p) = { nullptr, Input_num, Choose_operator };
        while(rc = chooseVariant(msgs, NMsgs)){
            std:: cout << "Your expression: ";
            std:: cout << stack_p  << std::endl;
            if(!fptr[rc](stack, &stack_p))
                break;
        }
        std:: cout << "Answer: ";
        std:: cout << *stack  << std::endl;
    }

}


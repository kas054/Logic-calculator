#include "stack.h"
#include "dialog.h"
int main() {
    Prog3_3::Stack *stack = new Prog3_3::Stack();
    Menu::start(stack);
    delete stack;
    return 0;
}

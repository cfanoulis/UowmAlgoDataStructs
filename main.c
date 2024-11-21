#include <stdio.h>
#include "vendor/stack.h"
#include "vendor/str_stack.h"

void part_1();
void part_2();

void main() {
    part_1();
}

void part_1() {
    stack_element_type input = -999;

    stack_type values;
    stack_type largest_values;

    initialize(&values);
    initialize(&largest_values);

    while (input != -1) {
        printf("Give me a number:");
        scanf("%d", &input);

        stack_element_type tmp = -1;

        switch (input) {
            case 0:
                pop(&values, &tmp);
            printf("Last number was %d\n", tmp);
            break;

            case -1:
                pop(&largest_values, &tmp);
            printf("Largest number was %d\n", tmp);
            break;

            default:
                push(&values, input);

            if(is_empty(largest_values)) {push(&largest_values, input);} else {
                top(largest_values, &tmp);
                if(tmp < input) push(&largest_values, input);
            }

            printf("Number stacked successfully!\n");
            break;
        }
    }
}
void part_2() {

}
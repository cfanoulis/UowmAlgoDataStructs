#include <stdio.h>
#include "vendor/stack.h"

int part_1();
int part_2();
void display_word(stack_type *stack);


int main() {
    printf("Select part to run:\n1) Largest in the history of the stack\n2) Reversing sentences\n>");
    int choice;
    scanf("%d", &choice);
    printf("=======\n");
    switch (choice) {
        case 1:
            return part_1();
        case 2:
            return part_2();
        default:
            printf("Invalid!");
        return -1;
    }
}

int part_1() {
    stack_element_type input = -999;
    stack_type values;
    stack_type largest_values;

    initialize(&values);
    initialize(&largest_values);

    while (input != -1) {
        stack_element_type tmp = -1;

        printf("Give me a number:");
        scanf("%d", &input);

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

    return 0;
}


int part_2() {
    printf("Input file (escape properly!):");
    char* filename = "";
    scanf("%.256s", filename);
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    stack_type stack1;
    stack_type stack2;

    initialize(&stack1);
    initialize(&stack2);

    while (!feof(fp)) {
        char in = fgetc(fp);

        if(in == '.' || in == '!' || in =='?') {
            while(!is_empty(stack1)) {
                int tmp;
                pop(&stack1, &tmp);

                if(tmp == ' ') {
                    display_word(&stack2);
                    printf(" ");
                } else {
                    push(&stack2, tmp);
                }
            }

            // empty stack2 for your last word
            display_word(&stack2);
            printf("\n");
        } else {
            push(&stack1, in);
        }
    }

    fclose(fp);
    return 0;
}

/// Εμφανίζει τα περιεχόμενα μίας στοίβας ως μια συμβολοσειρά
/// Η συμβολοσειρά ακολουθεί τη λογική FIFO - δηλαδή
/// @param stack Στοίχα τύπου int που περιέχει έγκυρους κωδικούς ASCII
void display_word(stack_type *stack) {
    while(!is_empty(*stack)) {
        int tmp;
        pop(stack, &tmp);
        printf("%c", tmp);
    }
}
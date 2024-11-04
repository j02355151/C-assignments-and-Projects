#include <stdio.h>
#define MAX_LEN 100  //it is the max length of the stack

//function to push elements to stack
//parameters: stack array, value to be pushed, pointer to stack top
//return: void
void push (char *stack, char value, int *stackTop){

    // if stack is full
    if (*stackTop == MAX_LEN) {
        printf("Stack is full.\n\n");
        return ;
    }

  //increment the top of the stack
    *stackTop = *stackTop +1;
    stack[*stackTop] = value;
    printf("Pushed %c to stack\n\n", value);

}

//function to pop elements from stack
//parameters: stack array,  pointer to stack top
//return: popped element
char pop (char *stack, int *stackTop) {

     //if stack is empty
    if ( *stackTop == -1) {
        printf("Stack is Empty\n\n");
        return '\0';
    }
     char temp = stack[*stackTop] ;

     //decrement the top of the stack
     *stackTop = *stackTop -1;

     //return the popped element
     return temp ;

}

int main(){

  char stack[5000];
  int stackTop = -1 ;
  char input ;


//take continuous input from user until a negative number is entered
  while(1){
    printf("1) PUSH \n2) POP \nChoose an option to perform your task: ");
    int op;
    scanf("%d", &op);
    getchar();

    //push
    if (op == 1) {
        printf("Enter a character(alphabet): ") ;
        scanf("%c", &input) ;

       // check if the input is an alphabet
        if ( (input >= 65 && input < 91) || (input >= 97 && input < 123)) {
            push(stack, input, &stackTop);
        }

        // if it is not an alphabet break the loop
        else  break;
    }
   // POP
    else if (op == 2) {
        char popped_elem = pop(stack, &stackTop);
        if(popped_elem != '\0'){
            printf("Popped %c from stack\n\n", popped_elem);
        }
    }

    else {
        printf("Invalid Choice. \n\n");
    }
  }

 printf("You entered a n invalid character\nPoppping all elements from stack:\n");
 //popping all elements from stack
 while(stackTop > -1){
     char popped_elem = pop(stack, &stackTop);
     printf("%c\n", popped_elem);
 }
printf("Now stack is empty!!\n");
}

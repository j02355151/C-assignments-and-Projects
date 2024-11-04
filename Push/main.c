#include <stdio.h>
#define MAX_LEN 100   //it is the max length of the stack


//function to push elements to stack
//parameters: stack array, value to be pushed, pointer to stack top
//return: void
void push (int *stack, int value, int *stackTop){

    ///if the stack is full
    if (*stackTop == MAX_LEN) {
        printf("Stack is full.\n\n");
        return ;
    }

    //increment the top of the stack
    *stackTop = *stackTop +1;

    //push the new value to stack
    stack[*stackTop] = value;
    printf("Pushed %d to stack\n\n", value);

}


//function to pop elements from stack
//parameters: stack array,  pointer to stack top
//return: popped element
int pop (int *stack, int *stackTop) {

    //if stack is empty
    if ( *stackTop == -1) {
        printf("Stack is Empty\n\n");
        return -1 ;
    }


     int temp = stack[*stackTop] ;

    //decrement the top of the stack
     *stackTop = *stackTop -1;

     //return the popped element
     return temp ;

}

int main(){

  int stack[5000];
  int stackTop = -1 ;
  int input = 0 ;


  //take continuous input from user until a negative number is entered
  while(1){
    printf("1) PUSH \n2) POP \nChoose an option to perform your task: ");
    int op;
    scanf("%d", &op);

    //push
    if (op == 1) {
        printf("Enter a number between 1 - 1000 (inclusive): ") ;
        scanf("%d", &input) ;

        //check is eneterd value is valid
        if ( input >0 && input < 1001) {
            push(stack, input, &stackTop);
        }

        //if its is negative
        else if(input < 0) break;
        //if its positive but out of range
        else {
            printf("Error: Number should be between 1 to 1000 (inclusive) \n\n");
        }
    }
    //pop
    else if (op == 2) {
        int popped_elem = pop(stack, &stackTop);
        if(popped_elem != -1){
            printf("Popped %d from stack\n\n", popped_elem);
        }
    }

    else {
        printf("Invalid Choice. \n\n");
    }
  }

 printf("You entered a negative number\nPoppping all elements from stack:\n");

 //popping all elements from stack
 while(stackTop > -1){
     int popped_elem = pop(stack, &stackTop);
     printf("%d\n", popped_elem);
 }
printf("Now stack is empty!!\n");
}

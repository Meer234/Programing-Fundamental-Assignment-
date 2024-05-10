#include<stdio.h>

int collatz_Sequence(int);
int Calculate_longest_collatz(int);

int main (){
    int Limit;
    int Ans;
    
    printf("Enter the Number: ");   //taking input from user
    scanf("%d", &Limit);
    
    Ans = Calculate_longest_collatz(Limit);  //calling the function 
    
    printf("Starting Number is of Given Limit is: %d\n", Ans);
    printf("Length is: %d", collatz_Sequence(Ans));
    
    return 0;
}

int collatz_Sequence(int num){
    int counter = 1; // Starting with 1 because the initial number also counts in the sequence
    
    for (; num != 1; counter++) {
        if (num % 2 == 0) {             //condition if num is even simply divide it by 2 
                                        //if number is odd than mulitply it by 3 then +1
                                        // then that number will go again in the loop for itration 
            num /= 2;           
        } else {
            num = (num * 3) + 1;
        }
    }                      
     //In the end it will return the maximum length of that number which will given to the function as arguments
    
    return counter;
}

int Calculate_longest_collatz(int limit){
    int max_length = 0;
    int starting_number = 0;                 //creating variables that's are needed 
    int just_length;
    
    for(int i = 1; i <= limit; i++){            //using for loop for finding Maximum length of a number
        just_length = collatz_Sequence(i);
        if(just_length > max_length){        //if just length is greater than max length it will assign to the variable maximum length 
            max_length = just_length;          //after assigning that number will store to the variable starting number
            starting_number = i;
        }
    }
          // In the end it will return the starting number to the main function
    return starting_number;
}


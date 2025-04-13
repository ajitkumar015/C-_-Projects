#include<stdio.h>
#include<math.h>

double division(double,double);
double modulus(int,int);
void print_menu();

int main(){
    int choice;
    double first, second, result;
    while(1) {
    print_menu();
    scanf("%d",&choice);
    if(choice == 7){
        break;
    }

    printf("\nPlease! Enter the First number :)");
    scanf("%lf", &first);
    printf("\nNow, Enter the second Number :)");
    scanf("%lf", &second);

    switch(choice){
        case 1:
             result = first + second;
             break;
        case 2:
             result = first - second;
             break;
        case 3:
             result = first * second;
             break;       
        case 4:
             result = division(first, second);
             break;  
        case 5:
             result = modulus((int)first, (int)second);
             break;   
        case 6:
             result = pow(first, second);
             break;  
        default:
             break;     
            
    }
      if (!isnan(result)){
        printf("\nThe result is: %lf", result);
      } 
   
    } while (choice != 7);
    return 0;
}
double division(double a, double b){
if(b == 0){ 
fprintf(stderr, "\nInvalid Argument for Division\n");
    // Return NaN for invalid division
    // Note: You can also use a custom error handling mechanism here.
    // For example, you could set a global error variable or use a callback function.
    // Here, we just print an error message and return NaN.
    // In C, you can use the math library to return NaN.
return NAN;
}else{
    return a/b;
}
}
double modulus(int a, int b){
    if(b == 0){ 
        fprintf(stderr, "\nInvalid Argument for Modulus:\n");
        return NAN; // Return 0 for invalid modulus
    } else {
        return a % b;
    }
}
void print_menu(){
    printf("\n---------------------------------------\n");
    printf("\nWelcome to my Simple calculator:)\n");
    printf("\nChoose one of the Following Options\n");
    printf("\n1. Addition");
    printf("\n2. Substract");
    printf("\n3. multiply");
    printf("\n4. Divide");
    printf("\n5. Modulous");
    printf("\n6. Power");
    printf("\n7. Exit");
    printf("\nNow, Enter your Choice : ");
}

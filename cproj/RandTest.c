#include <stdio.h>

#include <stdlib.h>

float get_mean(int max);

int main(int args) {
    // Write C code here
    printf("Welcome to the Random Number Test\n");
    printf("The mean test is %.2f",get_mean(1000));

    /*switch (args)
    {
    case 1:
        printf("The mean test is %.2f",get_mean(1000));
        break;
    
    default:
        break;
    }*/

    return 0;
}

int get_random(){
    int randon_number=(int)(10.0*rand()/(RAND_MAX+ 1.0));
    return randon_number;
}

float get_mean(int max){
    int i;
    int sum_rand = 0;
    float mean;
    for (i=1;i<=max;i++){
        sum_rand = sum_rand + get_random();
    }
    mean = sum_rand/max;
    return mean;
}
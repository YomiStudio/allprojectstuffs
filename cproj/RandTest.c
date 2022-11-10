#include <stdio.h>

#include <stdlib.h>
//function declaration
int get_random_number();
float get_mean_test(int max);
void count_occurrence(int num,int* count);
void get_frequency_test(int max);
void get_serial_test(int max);
void get_poker_test(int max);
void get_pocker_test(int max);
int arr[10] = {0,0,0,0,0,0,0,0,0,0};
void check_cardinality(int a, int b, int c, int d);
int same_num, three_same, two_same_pair, one_same_pair,none_identical;

int main() {
    // This is the entry point to the entire program.
    printf("Welcome to the Random Number Test\n");
    
    /*char str[4];

    str[0] = get_random_number();
    str[1] = get_random_number();
    str[2] = get_random_number();

    printf("%d")*/

    //sample test, delete later
    int args;
    printf("Type the test option? ");
    scanf("%d",&args);
    //end here

    switch (args)
    {
    case 1:
        //this branch presents the mean test result
        printf("The mean test is %.2f\n",get_mean_test(1000));
        break;
    case 2:
        //this branch presents the frequency test result
        get_frequency_test(10000);
        break;
    case 3:
        //this branch presents the serial test result
        get_serial_test(10000);
        break;
    case 4:
        //this branch presents the poker test result
        get_poker_test(1000);
        break;
    case 5:
        //this branch presents the pocker test result
        get_pocker_test(1000);
        break;
    default:
        printf("The single number is %d\n",get_random_number());
        break;
    }

    return 0;
}

//returns a single random number
int get_random_number(){
    int randon_number=(int)(10.0*rand()/(RAND_MAX+ 1.0));
    return randon_number;
}

//return the mean test
float get_mean_test(int max){
    int i;
    int sum_rand = 0;
    float mean;
    for (i=1;i<=max;i++){
        sum_rand = sum_rand + get_random_number();
    }
    mean = sum_rand/max;
    return mean;
}

//count occurrence of single digit numbers generated
void count_occurrence(int num,int* count){
       switch (num)
        {
        case 0:
            *(count+0) += 1;
            break;
        case 1:
            *(count+1) += 1;
            break;
        case 2:
            *(count+2) += 1;
            break;
        case 3:
            *(count+3) += 1;
            break;
        case 4:
            *(count+4) += 1;
            break;
        case 5:
            *(count+5) += 1;
            break;
        case 6:
            *(count+6) += 1;
            break;
        case 7:
            *(count+7) += 1;
            break;
        case 8:
            *(count+8) += 1;
            break;
        case 9:
            *(count+9) += 1;
            break;    
        default:         
            break;
        }
}

//tabulate the frequency test when called
void get_frequency_test(int max){
    int i;
    float p;

    //generate the random number supplied in the max and count their occurrence respectively.
    for(i=1;i<=max;i++){
        count_occurrence(get_random_number(),arr);
    }
    
    //print the percentage of the frequency of the numbers 0 through 9
    printf("Digit\tPercentage\n");
    for(i=0;i<10;i++){
        p = (float) arr[i]/ max * 100;
        printf("%d\t    %.2f\n",i,p);
    }
}

void get_serial_test(int max){
    int i,j;
    float p;
    //2 dimensional array to hold the count of the pairs
    
}
//
void get_poker_test(int max){
    int i;
    
    for (i=1;i<=max;i++){
        check_cardinality(get_random_number(),get_random_number(),get_random_number(),get_random_number());
    }
    printf("Table of Cardinality:\n");
    printf("\n%d",same_num);
    printf("\n%d",three_same);
    printf("\n%d",two_same_pair);
    printf("\n%d",one_same_pair);
    printf("\n%d\n",none_identical);

}

void check_cardinality(int a, int b, int c, int d){
    printf("%d%d%d%d\n",a,b,c,d);

    if((a==b) && (b==c) && (c==d)){
        same_num+=1;
    }
    else if (((a==b) && (b==c)) || ((b==c) && (c==d)) || ((a==c) && (c==d)) || ((a==b) && (b==d)) ){
        three_same+=1;
    }
    else if(((a==b) && (c==d))){
        two_same_pair+=1;
    }
    else if((((a==d) && (b!=c)) || ((a==c) && (b!=d)) || ((b==c) && (a!=d))|| ((b==d) && (a!=c)))){
        one_same_pair+=1;
    }
    else
        none_identical+=1;
}

void get_pocker_test(int max){

}


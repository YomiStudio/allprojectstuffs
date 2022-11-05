#include <stdio.h>

#include <stdlib.h>
//function declaration
int get_random_number();
float get_mean_test(int max);
void count_occurrence(int num,int* count);
void tabulate_frequency_test(int max);
void tabulate_serial_test(int max);
int arr[10] = {0,0,0,0,0,0,0,0,0,0};

int main() {
    // This is the entry point to the entire program.
    printf("Welcome to the Random Number Test\n");
    
    //sample test, delete later
    int args;
    printf("Type the test option? ");
    scanf("%d",&args);
    //end here

    switch (args)
    {
    case 1:
        //this branch presents the mean test result
        printf("The mean test is %.2f",get_mean_test(1000));
        break;
    case 2:
        //this branch presents the frequency test result
        tabulate_frequency_test(10000);
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
void tabulate_frequency_test(int max){
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

void tabulate_serial_test(int max){
    
}
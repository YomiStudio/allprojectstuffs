//This program is written by Festus

//This program is designed to test randomness of generated pseudo random numbers 
//according Kendall and Babbington-Smith.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// function declaration
int get_random_number();
float get_percentage(int frequency, int total);
float get_mean_test(int max);
void count_occurrence(int num, int *count);
void get_frequency_test(int max);
void get_serial_test(int max);
void get_poker_test(int max);
void get_pocker_test(int max);
void check_cardinality(int a, int b, int c, int d);
void print_cardinality();

//variable declaration
int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int same_num, three_same, two_same_pair, one_same_pair, none_identical;

int main(int argc, char *argv[])
{
    // This is the entry point to the entire program.
    printf("Welcome to the Random Number Test\n");
    printf("Name: Festus \n");

    int arg;
    //check for option passed in the command line
    if( argc == 2){
        arg = (int) atoi(argv[1]);
    }
    else{
        arg = 10;
    }
    switch (arg)
    {
    case 1:
        // this branch presents the mean test result
        printf("The mean test for 1000 pseudo random numbers is %.2f\n", get_mean_test(1000));
        break;
    case 2:
        // this branch presents the frequency test result
        printf("The Percentage of the Frequency of 10000 pseudo random numbers from zero(0) throught nine(9) is as follows:\n");
        get_frequency_test(10000);
        break;
    case 3:
        // this branch presents the serial test result
        printf("The Percentage of the pair of 10000 pseudo random number from 00, 01,02,...99 is as follows:\n");
        get_serial_test(10000);
        break;
    case 4:
        // this branch presents the poker test result
        printf("The cardinality of 1000 pseudo random number of four digits is as follows:\n");
        get_poker_test(1000);
        break;
    case 5:
        // this branch presents the pocker test result
        printf("The cardinality of 1000 pseudo random number of four digits stored in a file is as follows:\n");
        get_pocker_test(5);
        break;
    default:
        printf("The option selected is not available, choose a number between 1 and 5 inclusive\n");
        break;
    }

    return 0;
}

// function definition for the program
// returns a single random number
int get_random_number()
{
    int randon_number = (int)(10.0 * rand() / (RAND_MAX + 1.0));
    return randon_number;
}
//calculate and return the percentage from a given value
float get_percentage(int frequency, int total){
    float p = (float) frequency / total * 100;
    return p;
}
// return the mean test
float get_mean_test(int max)
{
    int i;
    int sum_rand = 0;
    float mean;
    for (i = 1; i <= max; i++)
    {
        sum_rand = sum_rand + get_random_number();
    }
    mean = sum_rand / max;
    return mean;
}

// count occurrence of single digit numbers generated
// we get the random number and increase the count by 1 if found.
// this uses a pointer to get the change the array value.
void count_occurrence(int num, int *count)
{
    switch (num)
    {
    case 0:
        *(count + 0) += 1;
        break;
    case 1:
        *(count + 1) += 1;
        break;
    case 2:
        *(count + 2) += 1;
        break;
    case 3:
        *(count + 3) += 1;
        break;
    case 4:
        *(count + 4) += 1;
        break;
    case 5:
        *(count + 5) += 1;
        break;
    case 6:
        *(count + 6) += 1;
        break;
    case 7:
        *(count + 7) += 1;
        break;
    case 8:
        *(count + 8) += 1;
        break;
    case 9:
        *(count + 9) += 1;
        break;
    default:
        break;
    }
}

// tabulate the frequency test when called
void get_frequency_test(int max)
{
    int i;

    // generate the random number supplied in the max and count their occurrence respectively.
    for (i = 1; i <= max; i++)
    {
        count_occurrence(get_random_number(), arr);
    }

    // print the percentage of the frequency of the numbers 0 through 9
    printf("Digit\tPercentage\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d\t    %.2f\n", i, get_percentage(arr[i], max));
    }
}

void get_serial_test(int max)
{
    int n, i, j;
    // 2 dimensional array to hold the count of the pairs
    int arr[10][10];

    // initialise the arrays with zeros
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            arr[i][j] = 0;
        }
    }

    // get the numbers and count the pairs
    for (n = 1; n <= max; n++)
    {
        int s1 = get_random_number();
        int s2 = get_random_number();

        //check for pairs with the numbers generated
        for (i = 0; i <= 9; i++)
        {
            for (j = 0; j <= 9; j++)
            {
                if ((s1 == i) && (s2 == j))
                {
                    arr[i][j] += 1;
                    break;
                }
            }
        }
    }
    
    //print the labels from 0 to 9 across the column
    printf("\n\t");
    for (i = 0; i <= 9; i++)
        {
            printf("*%d*\t",i);
        }
// calculate the percentage of each pair and print
    for (i = 0; i < 10; i++)
    {
        //print the labels from 0 to 9 across the row
        printf("\n*%d*",i);
        for (j = 0; j < 10; j++)
        {
            //calculate the percentage            
            printf("\t%.2f", get_percentage(arr[i][j], max));
        }        
    }
}
//this functions accepts a given number and generate 4 random pairs
void get_poker_test(int max)
{
    int i;

    // generate the four random number at the same time and check its cardinality
    for (i = 1; i <= max; i++)
    {
        check_cardinality(get_random_number(), get_random_number(), get_random_number(), get_random_number());
    }
    // calls the cardinality function to print the result
    print_cardinality(same_num, three_same, two_same_pair, one_same_pair, none_identical);
}
// print the result of the cardinality
void print_cardinality()
{
    printf("Table of Cardinality:\n");
    printf("\n%d", same_num);
    printf("\n%d", three_same);
    printf("\n%d", two_same_pair);
    printf("\n%d", one_same_pair);
    printf("\n%d\n", none_identical);
}
//this functions checks for cardinality
void check_cardinality(int a, int b, int c, int d)
{
    printf("%d-%d-%d-%d\n", a, b, c, d);

    if ((a == b) && (b == c) && (c == d))
    {
        same_num += 1;
    }
    else if (((a == b) && (b == c)) || ((b == c) && (c == d)) || ((a == c) && (c == d)) || ((a == b) && (b == d)))
    {
        three_same += 1;
    }
    else if (((a == b) && (c == d)))
    {
        two_same_pair += 1;
    }
    else if ((((a == d) && (b != c)) || ((a == c) && (b != d)) || ((b == c) && (a != d)) || ((b == d) && (a != c))))
    {
        one_same_pair += 1;
    }
    else
        none_identical += 1;
}

void get_pocker_test(int max)
{
    // declare the pointer variable for interacting with file
    FILE *fptr;

    // change this to appropriate location
    // fptr = fopen("C:\\4randompairs.txt","w");
    fptr = fopen("/home/yomzy/Desktop/4randompairs.txt", "w");

    // check if the process was successful, exit the program if it failed
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    // get number and store in file
    int n;
    for (n = 1; n <= max; n++)
    {
        fprintf(fptr, "%d %d %d %d\n", get_random_number(), get_random_number(), get_random_number(), get_random_number());
    }

    fclose(fptr);
    exit(0);
    // retrieve the numbers from the file into variables
    // check for cardinality
    char num_row[5];
    // if ((fptr = fopen("C:\\4randompairs.txt","r")) == NULL){
    if ((fptr = fopen("/home/yomzy/Desktop/4randompairs.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    //reads the numbers in file until it gets to the end of the file
    int p0,p1,p2,p3;
    char p;

    while ((fscanf(fptr, "%[^\n]", num_row)) != EOF)
    {
        fgetc(fptr);
        
        while (num_row)
        {
            /* code */
        }
        

        /*
        p0 = (int) atoi(p);
        p1 = (int) atoi(num_row);
        p2 = (int) atoi(num_row);
        p3 = (int) atoi(num_row);
        
       check_cardinality(p,p1,p2,p3);*/
    }
    fclose(fptr);

    // print cardinality
    //print_cardinality();
}
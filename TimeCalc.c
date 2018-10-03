#include <stdio.h> 
#include<omp.h>
#include <time.h> 
#define threadcount 10
// A function that terminates when enter key is pressed 
void fun() 
{ 
    int arr[50000], count0 = 0, count1 = 0, count2 = 0, count3 = 0;
    int x[threadcount];
    //For loop with the actual work load
    omp_set_num_threads(10);
    #pragma omp parallel for
    for(int i = 0; i<52; i++){
        x[omp_get_thread_num()]++;
    }
    //Loop to display the number of threads and the number of times it was invoked
    for(int i= 0;i<threadcount;i++){
        printf("The thread %d invoked %d these many times\n",i,x[i]);
    }
} 
  
// The main program calls fun() and measures time taken by fun() 
int main() 
{ 
    // Calculate the time taken by fun() 
    clock_t t; 
    t = clock(); 
    fun(); 
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
  
    printf("Program took %f seconds to execute \n", time_taken); 
    return 0; 
} 
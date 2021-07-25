/*
NOTE: The question does not specify the times to fail the specific conditions.
In itself, the question is ambiguous and the objective of the question could not be clear to me.
Also, the test case provided says max[1][2] = 1 and alloc[1][2] = 5, which is not possible.
*/

#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LIMIT 200
#define ONE 1
long max[LIMIT][LIMIT]; 
long alloc[LIMIT][LIMIT]; 
long need[LIMIT][LIMIT]; 
long avail[LIMIT]; 
long i, j, p, r; 
long finish[LIMIT] = {0}; 
long flag = 0; 

void solve(){
  while(ONE){ 
    for(flag = 0, i = 0; i < p; i++){ 
      if(finish[i] == 0) { 
        for(j = 0; j < r; j++) { 
          if(need[i][j] <= avail[j]) 
            continue;  
          else
            break;  
        } 
        if(j == r) { 
          for(j = 0; j < r; j++) 
            avail[j] += alloc[i][j];  
            flag = ONE;  
            finish[i] = ONE;  
        } 
      } 
    } 
    if(flag == 0) {
       break;  
    }
  } 
}


int main(){ 
  
  printf("SIMULATION OF DEADLOCK PREVENTION\n");  
  printf("Enter number of processes, resources\n");  
  scanf("%ld %ld", &p, &r); 
  printf("Enter allocation matrix\n");  

  for(j = 0; j < r; j++)
    for(i = 0; i < p; i++) 
      scanf("%ld", &alloc[i][j]);  

  printf("Enter max matrix\n");  

  for(j = 0; j < r; j++) {
    for(i = 0; i < p; i++) {
      scanf("%ld", &max[i][j]);  
    }
  }

  printf("Enter available matrix\n");  

  for(i = 0; i < r; i++) {
    scanf("%ld", &avail[i]);  
  }

  for(i = 0; i < p; i++) {
    for(j = 0; j < r; j++) {
      need[i][j] = max[i][j] - alloc[i][j];  
    }
  }  
  long pro; 
  for(pro = 0; pro < p; pro++){
    if(flag == 0) {
      if(finish[pro] == 0){
        // 1
        printf("\n\nFailing: Mutual exclusion");  
        for(j = 0; j < r; j++){ /*checking for mutual exclusion*/ 
          if(avail[j] < need[pro][j]) 
            avail[j] = need[pro][j];  
        }

        solve(); 
        if(finish[pro] == ONE)
          printf("\nBy allocating required resources to process %ld dead lock is prevented ", pro);  
        // 2

        printf("\nlack of preemption");  
        for(j = 0; j < r; j++){ 
          if(avail[j] < need[pro][j]) 
            avail[j] = need[pro][j];  
          alloc[pro][j] = 0;  
        } 

        solve(); 
        if(finish[pro] == ONE)
          printf("\ndaed lock is prevented by allocating needed resources");  
        // 3
        
        printf("\nfailing:Hold and Wait condition\n");  
        for(j = 0; j < r; j++){ /*checking hold and wait condition*/ 
          if(avail[j] < need[pro][j]) 
            avail[j] = need[pro][j];  
        } 
        solve(); 
        // avoiding any condition out of 3 can prevent deadlock 
      } 
    }
  }

} 


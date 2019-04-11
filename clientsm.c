/*
  R6 - 38 
  MERIN CHERIAN
  EXPERIMENT 6
  SHARED MEMORY
      CLIENT SIDE
*/

#include<stdio.h>
#include<sys/shm.h>//for shared memory functions

int main()
{
   int shmid,addr;
   char str[10]="";
   
   key_t key; //Each shared m/m will have a unique key set by the user
   key = 100;//key value

   shmid = shmget( key,100,IPC_CREAT|0666);//Fn for creating shared m/m and returning id
   printf("\n%d\n", shmid);
   
   /*
    Parametres:-
       key             -> key value
       100             -> Number of pages
       IPC_CREAT|0666  -> A flag used for creating shared m/m 
                      (0666 is the permission for reading, writing on the m/m) 
    */
  
    addr = shmat(shmid , NULL, 0);//Fn for attaching shared m/m to address space
    
    /*
     Parametres:-
        shmid       -> shared m/m id
        |NULL        -> Points to the desired address of the shared memory segment.
        |0           -> Specifies a set of flags that indicate the specific shared memory conditions and options to implement.
    */
 
     printf("CLIENT SIDE:-\nEnter the expression:- ");
     scanf("%s", str);

     sprintf(addr,str);//Fn to write exp into shared m/m
   
     shmdt(addr);//Fn to dettach from memory
     return 0;

}

   




      

       







  

   

/* 
   38
   Author :- Merin Cherian
   EXP 1
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{

  int n1,n2,n3,n4;
   
  printf("Parent Pid : %d\n", getppid());  

  n1=fork();//Function to create process
  
  if(n1==0)
   {
       printf("First Child : ");
       printf("%d", getpid()); //Function for returning process id
       printf("\n");
   }
  
   else 
   {

       n2=fork();
    
       if(n2==0) //If the return value is zero, then child has been created
       {
          printf("Second Child : ");
          printf("%d", getpid());
          printf("\n");
        }

       else if(n2<0)
          printf("Error");
      
       else
       {
          n3=fork();
 
          if(n3==0)
          {
               printf("Third child : ");
               printf("%d", getpid());
               printf("\n");
          }

          else if(n3<0)
               printf("Error");
        
       }


   }


}

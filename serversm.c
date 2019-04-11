/* 
  R6 - 38
  MERIN CHERIAN
  EXP 6
  SHARED MEMORY (SERVER)
*/

#include<stdio.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
  int shmid,addr,result=0,i;
  char str[10]="";
  
  key_t key;
  key=100;//This value is used to obtain the id of the shared m/m

  shmid = shmget( key , 100 , IPC_CREAT|0666);//Getting id
  printf("\n%d\n", shmid);
  addr = shmat (shmid , NULL , 0);//Attaching to address space

  sscanf( addr,"%s",str);

  for(i=0;i< strlen(str);i++)
   {  if(isdigit (str[i]))   
         result = result + str[i] - 48;
                            
    }
  printf("SERVER SIDE\nRESULT:- %d\n",result);
  shmdt(addr);
}

  
  
  

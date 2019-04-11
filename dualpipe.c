/* R6-38 
   MERIN CHERIAN
   EXPERIMENT 5
   DUALPIPE
*/



#include<stdio.h>
#include<string.h>
#include<sys/ipc.h> // header file for pipe system call



int main()
 {
  

   int fd1[2],fd2[2],len,pid,len2;
   char message[40]=" This is a test for parent. ";
   char message2[40]=" This is a test for child. ";
   char reply[40]=" ";
   len=strlen(message);  
   len2=strlen(message2);
   pipe(fd1);
   pipe(fd2);

   pid=fork();
 
   if(pid<0)
    {
      printf("Error");
      
    }
   else if(pid>0)//Parent gets execited first
    {
      close(fd1[0]);//0 is read end (fd1 is first pipe)
      close(fd2[1];//1 is write end (fd2 is second pipe)
      write(fd1[1],message,len);
      printf("Message sent by parent( pid - %d ): %s",getpid(),message);
      printf("\n");
      read(fd2[0],reply,len);
      printf("Message received by parent( pid - %d ): %s",getpid(),reply);
      printf("\n");
      close(fd1[1]);
      close(fd2[0]);
    }
   else
   {

     close(fd1[1]);// fd1 is for child to parent
     close(fd2[0]);// fd2 is for parent to child
     write(fd2[1],message2,len);
     printf("Message sent by child( pid - %d ): %s",getpid(),message2);
     printf("\n");
     read(fd1[0],reply,len);
     printf("Message received by parent( pid - %d ): %s",getpid(),reply);
     printf("\n");
     close(fd1[0]);
     close(fd2[1]);
 
   }



   return 0;
}

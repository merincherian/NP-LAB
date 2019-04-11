//38
//AUTHOR :- MERIN CHERIAN
// EXP 2

#include<stdio.h>
#include<stdlib.h>

int main()
{
 
    int pid, a[100][100], b[100][100], c[100][100],i,j,k,s,m,n;
  
    printf("Enter the number of rows: ");
    scanf("%d", &m);
 
    printf("\n Enter the number of coloumns: ");
    scanf("%d", &n);

    printf("Enter the elements of first matrix");

    for( i=0;i<m;i++)
     {
           for(j=0;j<n;j++)
            {
                scanf("%d", &a[i][j]);
            }
      }
  
     printf("Enter the  elements of the second matrix");

  
     for( i=0;i<m;i++)
     {
          for(j=0;j<n;j++)
           {
              scanf("%d", &b[i][j]);
            }
      }
  

     pid=fork();
   
     if (pid==0)
	{
	      printf("\nTHIS IS THE CHILD PROCESS (Process ID= %d)",getpid());
	      
              if (m!=n)
	       {
                  printf("Multiplication is not possible");
                }
      	      
               else
                {
	     	  
                  for (i=0;i<m;i++)//Perform multiplication
		    {
	          
                       for (j=0;j<n;j++)
		 	  {
		             s=0;
		  
                    	     for (k=0;k<n;k++)
	                        {
			 	  c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
			         }
		          }
	             }
		
                   printf("\nThe resultant matrix is: ");
	   	 
                   for (i=0;i<m;i++) 
                    {
		       printf("\n");
		       for (j=0;j<n;j++)
			 {
		   	    printf("%d\t",c[i][j]);
			  }
		    }
	        }
      
     }
 
  else if (pid<0)
      {
	  printf("ERROR: No Child process is created.\n");
      }
 
  else
      {
      
	printf("\nTHIS IS THE PARENT MATRIX (Process ID= %d)",getpid());
	
        for (i=0;i<m;i++)
	  {
             for (j=0;j<n;j++)
		{
	   	   c[i][j]=a[i][j]+b[i][j];
		}
	  }
 
	printf("\nThe resultant matrix is: ");
	for (i=0;i<m;i++)
	  {
	     printf("\n");
	     for (j=0;j<n;j++)
	       {
	       	 printf("%d\t",c[i][j]);
		}
	  }
	
       }
  

   printf("\n");

}


  

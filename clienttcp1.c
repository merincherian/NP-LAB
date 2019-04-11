#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
  int clientSocket;
  char buffer[1024];
  struct sockaddr_in serverAddr; /* "sockaddr_in" Already defined structure, defined in the kernel*/
  socklen_t addr_size;

  /*---- Create the socket. The three arguments are: ----*/
  /* 1) Internet domain 2) Stream socket 3) Default protocol,hence 0 specifies TCP (TCP in this case) */
  
  /*The socket function returns a unique SOCKET DESCRIPTOR ( code associated with socket)*/  


  clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  
  /*---- Configure settings of the server address struct ----*/
  /* Address family = Internet */
  serverAddr.sin_family = AF_INET;

  /* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(7891);/*Virtual ports*/
 
  /* Set IP address to localhost */

  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  /*sin_addr is structure within the sockaddr_in structure*/
  /* Set all bits of the padding field to 0 */

  

  /*---- Connect the socket to the server using the address struct ----*/
  
  if(connect(clientSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0 )
    printf("There was an error in establishing connection.");

  /*---- Read the message from the server into the buffer ----*/
  recv(clientSocket, buffer,sizeof(buffer), 0);

  /*---- Print the received message ----*/
  printf("Data received: %s",buffer);   

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() 
{
    int sock = 0;
    struct sockaddr_in serv_addr;

    // Create TCP socket for IPV4 domain
    if ( ( sock = socket( AF_INET, SOCK_STREAM, 0 ) ) < 0 ) 
    {
        printf( "\n Socket creation error \n" );
        return -1;
    }

    serv_addr.sin_family = AF_INET;  // AF_INET represents IPV4 address
    serv_addr.sin_port = htons( PORT );  // converts port number to network byte order

    serv_addr.sin_addr.s_addr = inet_addr( "127.0.0.1" ); // Use "127.0.0.1" for localhost

    // Connect to server with specified address and port number
    if ( connect( sock, ( struct sockaddr * )&serv_addr, sizeof( serv_addr ) ) < 0 ) 
    {
        printf( "\nConnection Failed \n" );
        return -1;
    }

    // Read the action from stdin
    char action[ BUFFER_SIZE ];
    printf( "Enter action (UPPER or LOWER): " );
    fgets( action, BUFFER_SIZE, stdin );
    action[ strcspn( action, "\n" ) ] = 0; // Remove newline character

    // Send action to server
    send( sock, action, strlen( action ), 0 );

    // Read the greeting from server and store in some character array. Print the greeting
    char server_response[ BUFFER_SIZE ] = { 0 };
    read( sock, server_response, BUFFER_SIZE );
    printf( "%s\n", server_response );

    // If the operation is not invalid, enter the message from stdin using fgets and send it to the server
    if ( strcmp( server_response, "Invalid operation" ) != 0 ) 
    {
        char message[ BUFFER_SIZE ];
        printf( "Enter the message: " );
        fgets( message, BUFFER_SIZE, stdin );
        message[ strcspn( message, "\n" ) ] = 0; // Remove newline character
        send( sock, message, strlen( message ), 0 );

        // Read the response from server and print it
        memset( server_response, 0, BUFFER_SIZE ); // Clear the buffer
        read( sock, server_response, BUFFER_SIZE );
        printf( "Server response: %s\n", server_response );
    }

    // Close the socket
    close( sock );

    return 0;
}

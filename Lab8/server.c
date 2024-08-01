#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void toUpperCase( char *str ) 
{
    while ( *str ) 
    {
        *str = toupper( ( unsigned char )*str );
        str++;
    }
}

void toLowerCase( char *str ) 
{
    while ( *str ) 
    {
        *str = tolower( ( unsigned char )*str );
        str++;
    }
}

int main() 
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof( address );

    // Create a TCP socket for IPV4 domain
    if ( ( server_fd = socket( AF_INET, SOCK_STREAM, 0 ) ) == 0 ) 
    {
        perror( "socket failed" );
        return 1;
    }

    // Initialize address structure
    address.sin_family = AF_INET;    // IPV4 address
    address.sin_addr.s_addr = INADDR_ANY;  // INADDR_ANY allows connections from any IP address
    address.sin_port = htons( PORT );  // set PORT number appropriate for the network

    // Bind the socket to the specified address and port
    if ( bind( server_fd, ( struct sockaddr * )&address, sizeof( address ) ) < 0 ) 
    {
        perror( "bind failed" );
        return 1;
    }

    // Listen for connections
    if ( listen( server_fd, 1 ) < 0 ) 
    {  
        perror( "listen" );
        return 1;
    }

    // Keep accepting incoming connections and process requests
    while ( 1 ) 
    {
        if ( ( new_socket = accept( server_fd, ( struct sockaddr * )&address, ( socklen_t * )&addrlen ) ) < 0 ) 
        {
            perror( "accept" );
            return 1;
        }

        // Read data from client
        char buffer[ BUFFER_SIZE ] = { 0 };
        int valread = read( new_socket, buffer, BUFFER_SIZE );
        buffer[ strcspn( buffer, "\n" ) ] = 0; // Remove newline character if present

        // Create greeting message
        char greeting[ BUFFER_SIZE ];
        printf( "Action received: %s", buffer );

        // Arrays for converted string and request
        char converted[ BUFFER_SIZE ] = { 0 };
        char request[ BUFFER_SIZE ] = { 0 };

        // Handle the action received from client
        if ( strcmp( buffer, "UPPER" ) == 0 || strcmp( buffer, "LOWER" ) == 0 ) 
        {
            // Send the greeting
            send( new_socket, greeting, strlen( greeting ), 0 );
            
            // Read the string to convert
            valread = read( new_socket, request, BUFFER_SIZE );
            request[ strcspn( request, "\n" ) ] = 0; // Remove newline character if present
            
            // Perform conversion based on action
            if ( strcmp( buffer, "UPPER" ) == 0 ) 
            {
                strcpy( converted, request );
                toUpperCase( converted );
            } 
            else if ( strcmp( buffer, "LOWER" ) == 0 ) 
            {
                strcpy( converted, request );
                toLowerCase( converted );
            }
            
            // Send the converted string back to the client
            send( new_socket, converted, strlen( converted ), 0 );
        } 
        else 
        {
            // Invalid action
            char invalidMessage[] = "Invalid operation";
            send( new_socket, invalidMessage, strlen( invalidMessage ), 0 );
        }

        // Close the socket
        close( new_socket );
    }

    return 0;
}
/*
cypher

Author: Daniel Lu
email: dizzylu@gmail.com


###################### Description ##########################

This program accepts a text stream from stdin one character at a time. 
It outputs an encrypted/decrypted stream to stdout one character at a time. 

The encryption is done using a key provided as an argument to the program.  
Encryption/decryption is specified with an 'e' or 'd' argument, respectively. 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cypher.h"

int main( int argc, char *argv[])
{
        if( argc != 3 ) {
                fprintf(stderr, "to encrypt: ./cypher e <key>\nto decrypt: ./cypher d <key>\n" );
                exit(1); 
        }
        
        char check_encrypt_mode = *argv[1];
        
        if( (check_encrypt_mode != 'e') && (check_encrypt_mode != 'd') ) {
                fprintf(stderr, "First argument must be 'e' or 'd'!\nto encrypt: ./cypher e <key>\nto decrypt: ./cypher d <key>\n" );
                exit(1);
        }
        
        char *key = argv[2];
        int key_len = strlen(key);

        int c;
        int i = 0;

        while ( EOF != (c = fgetc(stdin)) ) {
           
                int output_char = 0;
                if( check_encrypt_mode == 'e') {
                        output_char = encrypt(c, key, key_len, i);
                } else if( check_encrypt_mode == 'd') {
                        output_char = decrypt(c, key, key_len, i);
                }
                
                fputc(output_char, stdout);
                i++;
        }


        exit(0);
}

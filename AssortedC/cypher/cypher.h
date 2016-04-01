//Encryption, decryption lib for cypher.c

int encrypt(int input, char *key, int key_len, int index) 
{
        int output;
        
        if( (input >= 32) && (input <= 126)) {
                output = (input - 32 + key[index % key_len]) % 95 + 32;
        } else {
                output = input;
        }

        return output;
}

int decrypt(int input, char *key, int key_len, int index) 
{
        int output;
        
        if( (input >= 32) && (input <= 126)) {
                output = (input - 32 - key[index % key_len] + 3 * 95) % 95 + 32;
        } else {
                output = input;
        }

        return output;

}

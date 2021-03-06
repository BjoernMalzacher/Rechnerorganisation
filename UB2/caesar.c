/**
 * Karlsruher Institut fuer Technologie
 * Institut fuer Technische Informatik (ITEC) 
 * Vorlesung Rechnerorganisation
 *
 * Autor: Bjoern Malzacher
 * Matrikelnummer: 2353051
 * Tutoriumsnummer: 08
 * Name des Tutors: Sandro Negri
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Returns the length of the given text.
 * \param text
 * \return the length of text
 */
static unsigned int stringLength(char* text) {
 unsigned int i;
 while (*text != '\0') {
     i +=1;
     text +=1;
 }
 return i;
}


/**
 * create a buffer which is as big as text
 *
 * \param text
 * \return char* buffer
 */
static char* createBuffer(char* text)
{
    // allocate the buffer memory
    // + 1 for the trailing \0
    int bufferSize = stringLength(text) + 1;
    // allocate and set the buffer to 0
    char* buffer = (char*)calloc(bufferSize, sizeof(char));

    return buffer;
}


/**
 * if c is a letter it will be rotated by n
 * \param c the character
 * \param n the rotate offset
 * \return the rotated character
 */
static char rotateChar(char c, int n) {
    
    if(c >= 'A' && c <='Z') {
      if((c+n)>= 'Z'){
          
          c = 'A'+ (((c+n)-'A')% (26));
      }else{
          c +=n;
      }
        return c;
    }
    if(c >= 'a' && c <='z') {
      if((c+n)>= 'z'){
          c = 'a'+(((c+n)-'a')% (26));
      }else{
          c +=n;
      }
        return c;
    }
}


/**
 * Returns the crypted string of text.
 *
 * \param text to encrypt.
 * \param key
 * \return crypted text
 */
static char* encrypt(char* text, int key) {
    char* buffer = createBuffer(text);
    char* bufferstart = buffer;
    while (*text != '\0') {
        
        *buffer = rotateChar( *text, key);
        buffer ++; 
        text+=1;
    }
   
    
    return bufferstart;
}


/**
 * Returns the decrypted string of crypted.
 *
 * \param crypted
 * \param key
 * \return crypted text
 */
static char* decrypt(char* crypted, int key) {
    ;
    char* buffer = createBuffer(crypted);
    char* bufferstart = buffer;
    while (*crypted!= '\0') {
        
        *buffer = rotateChar( *crypted, 26-key);
        buffer ++; 
        crypted+=1;
    }
    return bufferstart;
}


#ifndef TEST
/**
 * main method
 * Queries the number to use as input parameter for the function calls
 *
 * \param argc unused
 * \param argv unused
 * \return returns 0
 */
int main(int argc, char* argv[])
{
    char plain[256];
    int key;

    printf("Bitte geben Sie einen Text ein:\n> ");
    // for visual studio 
    // scanf_s("%255[^\n]", plain, _countof(plain));
    scanf("%255[^\n]", plain);

    printf("Bitte geben Sie einen Schluessel ein:\n> ");
    // for visual studio
    // scanf_s("%i", &key);
    scanf("%i", &key);

    char* crypted = encrypt(plain, key);
    printf("crypted:   %s\n", crypted);
    char* decrypted = decrypt(crypted, key);
    printf("decrypted: %s\n", decrypted);
    printf("%s\n",encrypt("Bj??rn Malzacher",2353051));
    printf("%s\n",encrypt("Peter M??ller", 1234567));
    free(crypted);
    free(decrypted);
    return 0;
}
#endif

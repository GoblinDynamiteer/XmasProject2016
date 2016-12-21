/* 
Mjukvaruutvecklare Inbyggda System
Applicerad Yrkesmatematik
Julprojekt 2016/2017

Johan K�mpe 
*/

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

//Antal tecken f�r textstr�ngar
#define N 256

//Antal siffror efter kommatecken, f�r bin�ra flyttal
#define DECIMALTECKEN 10

void vand(char *str);
char *convert_to_binary(int decimal);
char *convert_to_binary_frac(double decimal);
char *convert_decimal_to_binary(double decimal);

char *convert_to_base(int decimal, int base);
char *convert_to_base_frac(double dec_frac, int max_digits, int base);
char *convert_dec_to_base(double dec_frac, int max_digits, int base);

double convert_base_to_dec(char *base_frac, int max_digits, int base);


char numToChar(int num);
int charToNum(char num);
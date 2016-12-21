/* 
Mjukvaruutvecklare Inbyggda System
Applicerad Yrkesmatematik
Julprojekt 2016

Johan K�mpe 
*/

#include "libconvert.h"

/* V�nder p� en char-array. Anv�nds f�r konvertering
fr�n hela decimaltal till bin�ra tal. */
void vand(char *str){
	//lower / upper index
	int lix, uix = strlen(str)-1;
	char temp;
	for(lix = 0; lix < uix; lix++, uix--){
		temp = str[uix];
		str[uix] = str[lix];
		str[lix] = temp;
	}
}

//Konverterar dec (int) till bin�r (char array)
char *convert_to_binary(int decimal){
	char *omvand = malloc(sizeof(char) * N);
	//oix: omvandling index:
	int t, oix;
	oix = 0;
	//Om inkommande tal att omvandla �r 0, returneras 0
	if(!decimal){
		omvand[oix] = '0';
		oix++;
	}
	else{
		/* Den bin�ra siffran �r resten av delning med 2
		p� det decimala talet. */
		for(t = decimal; t != 0; t=t/2){
			if(t%2 == 1){
				omvand[oix] = '1';
			}
			else{
				omvand[oix] = '0';
			}
			oix++;
		}
	}
	omvand[oix] = '\0';
	//V�nder p� tecknen i char-arrayen
	vand(omvand);
	return omvand;
}

//Konverterar tal med bas 10 till tal med valfri bas 'base'
char *convert_to_base(int decimal, int base){
	char *omvand = malloc(sizeof(char) * N);
	//oix: omvandling index:
	int t, oix, num;
	oix = 0;
	//Om inkommande tal att omvandla �r 0, returneras 0
	if(!decimal){
		omvand[oix] = '0';
		oix++;
	}
	else{
		/* Siffran �r resten av delning med talbasen 'base'
		p� det decimala talet. */
		for(t = decimal; t != 0; t=t/base){
			num = t % base;
			omvand[oix] = numToChar(num);
			oix++;
		}
	}
	omvand[oix] = '\0';
	//V�nder p� tecknen i char-arrayen
	vand(omvand);
	return omvand;
}

//TEMP
char *convert_to_base_frac(float dec_frac, int max_digits, int base){
	char *base_frac = malloc(sizeof(char) * N);
	//oix: omvandling index:
	int oix = 0, num;
	/* Parameter anses vara i form: 0.##### 
	D�rf�r s�tts str�ngens b�rjan till .#
	*/
	base_frac[oix] = '.';
	oix++;
	if(!dec_frac){
		base_frac[oix] = '0';
		oix++;
	}
	else{
		for(dec_frac=dec_frac*base; dec_frac != 0.0 && 
		max_digits > 0; dec_frac=dec_frac*base){
			num = dec_frac;
			dec_frac = dec_frac - num ;
			base_frac[oix] = numToChar(num);
			oix++;
			//printf("\nmax_digits: %d\n", max_digits);
			max_digits--;
		}
	}
	base_frac[oix] = '\0';
	return base_frac;
}

//Konverterar int till char 0-9: 0-9 11+: A+
char numToChar(int num){
	char c;
	/* ASCII-tecknet '0' har v�rdet 48, och siffran 0 har 0. 
	F�r att konvertera talet 0 till tecknet '0', kan man s�ledes anv�nda 
	0 + '0'. Osv f�r 1,2,3 */
	if(0 <= num && num < 10){
		c = num + '0';
	}
	/* F�r tal �ver 9 anv�nds det versala alfabetet. A-Z
	F�r att konvertera talet 10 till tecknet 'A', adderas v�rdet f�r 'A'
	och sedan subtraheras 10. S�ledes blir 11 = B, 12 = C osv.
	*/
	else{
		c = num + 'A' - 10;
	}
	return c;
}

//Konverterar float (double) till bin�r (char array)
char *convert_to_binary_frac(double decfloat){
	char *binarfloat = malloc(sizeof(char) * N);
	//oix: omvandling index:
	int oix, counter = 0;
	/* Parameter anses vara i form: 0.##### 
	D�rf�r s�tts bin�ra str�ngens b�rjan till 0.#
	*/
	binarfloat[0] = '0';
	binarfloat[1] = '.';
	oix = 2;
	for(decfloat=decfloat*2; decfloat != 0.0 || 
		counter > DECIMALTECKEN; decfloat=decfloat*2){
		if(decfloat >= 1.0){
			decfloat = decfloat - 1.0;
			binarfloat[oix] = '1';
		}
		else{
			binarfloat[oix] = '0';
		}
		oix++;
		counter++;
		if(counter == 20){
			break;
		}
	}
	binarfloat[oix] = '\0';
	return binarfloat;
}

/* Anv�nder funktionerna convert_f_to_binary & convert_to_binary
f�r att konvertera ett flyttal i decimalform till ett bin�rt flyttal */
char *convert_to_binary_TEMPNAMNFIXA(double decimal){
	char *binarD = malloc(sizeof(char) * N);
	char *binarF = malloc(sizeof(char) * N);
	int heltal = decimal;
	decimal = decimal - heltal;
	/* Om flyttal, anropas konverteringsfunktion, 
	annars s�tts str�ng till nolltecken */
	if(decimal > 0.00000000){
		binarF = convert_to_binary_frac(decimal);
	}
	else{
		binarF[0] ='\0';
	}
	/* Om inmatat heltal �r st�rre �n 1, 
	annars s�tts str�ng till tecken 0 */
	if(heltal > 0){
		binarD = convert_to_binary(heltal);
	}
	else{
		binarD[0] ='0';
		binarD[1] ='\0';
	}
	/* Returnerar sammansatta char-arrayer, 
	+1 f�r att f� bort den initiala nollan i str�ngen binarF */
	return strcat(binarD, binarF+1);
}
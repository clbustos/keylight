/**
 * The MIT License (MIT)
 * Copyright (c) 2013 Claudio Bustos
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/** 
 * Keylight: A little program to manage the backlight of Asus Keyboards
 * Note: This works on my Asus R401VB. Look into  /sys/devices
 * for your configuration
 */
 
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> /* for exit */
// Change the next light acording to your system configuration
#define FILE_BRIGHT "/sys/devices/platform/asus-nb-wmi/leds/asus::kbd_backlight/brightness" 

int main(int argc, char* argv[])
{
	FILE *file;
	int val;
	file=fopen(FILE_BRIGHT,"r");
	//puts("hola");
	if (file == NULL) {
		fprintf(stderr, "Can't open dev file!\n");
		exit(EXIT_FAILURE);
	}
	fscanf(file,"%d",&val);
	int fc;
	if(argc==1) {
		printf("Value:%d\n", val);
	} else if (argc==2) {
		fc=(int)*argv[1];
		if(isdigit(fc)) {
			fc=fc-'0';
			if(fc>=0 & fc<=3) {
				write_dig(fc);
			}
		} else if(fc=='+') {
			if(val<3) val++;
			
			write_dig(val);
		} else if(fc=='-') {
			if(val>0) val--;
			write_dig(val);
		}
	}
	exit(EXIT_SUCCESS);
}

int write_dig(int dig) {
	FILE *file;
	file = fopen(FILE_BRIGHT,"w"); 

	if (file == NULL) {
		fprintf(stderr, "Can't open dev file for writing. Use as su\n");
		exit(EXIT_FAILURE);
	}
	fprintf(file,"%d",dig);
	fclose(file);
}

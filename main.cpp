#include "mbed.h"
#include "uLCD_4DGL.h"

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;
DigitalIn But1(A0);         // decrease the freq
DigitalIn But2(A1);         // confirm freq
DigitalIn But3(A2);         // increase the freq
DigitalIn mypin(USER_BUTTON);
AnalogOut aout(PA_4);       // set the analog output
AnalogIn AIN(A3);           // set the analog input


int main(){
	float sele;
	float temp = 1.0;     // the frequency shown on the uLCD
	float freq = 1000.0/240.0;     // the confirm frequency (the frequency of the output wave)	
	float data[100];    // sampled data
	uint16_t sample = 0;
	aout = 1;

    while (1) {
		// scan the button
		uLCD.printf("\n%f\n", temp);
		if (But1 == 1) {
			if(temp != 0.125)
			temp = temp/2.0;
			else temp=temp;
			uLCD.color(BLUE);  
            uLCD.background_color(WHITE);
            uLCD.textbackground_color(WHITE);
            uLCD.cls();
            // basic printf demo = 16 by 18 characters on screen
            uLCD.locate(1, 1);
            uLCD.text_width(4); //4X size text
            uLCD.text_height(4);
            uLCD.color(GREEN);
            uLCD.printf("\n%f\n", temp);
		}

		if (But2 == 1) {
			sele = temp;
			
			//conf = 1;
			uLCD.color(BLUE);  
            uLCD.background_color(WHITE);
            uLCD.textbackground_color(WHITE);
            uLCD.cls();
            // basic printf demo = 16 by 18 characters on screen
            uLCD.locate(1, 1);
            uLCD.text_width(4); //4X size text
            uLCD.text_height(4);
            uLCD.color(GREEN);
            uLCD.printf("\n%f\n", sele);
			break;
		}

		if (But3 == 1) {
			if(temp!=1)
			temp = temp*2.0;
			else 
			temp=temp;
			uLCD.color(BLUE);  
            uLCD.background_color(WHITE);
            uLCD.textbackground_color(WHITE);
            uLCD.cls();
            // basic printf demo = 16 by 18 characters on screen
            uLCD.locate(1, 1);
            uLCD.text_width(4); //4X size text
            uLCD.text_height(4);
            uLCD.color(GREEN);
            uLCD.printf("\n%f\n", temp);
		}
	}
	printf("%f\r\n", freq);
	while(1){
		if (!mypin) break;
		if(sele==1){
		for (int i = 0; i < 17; i++) {
            sample = (uint16_t)(59578 * i / 17);
            aout.write_u16(sample);
            data[i] = AIN;
            wait_us(20000/freq);
        }
        for (int i = 0; i < 16; i++) {
            sample = sample;
            aout.write_u16(sample);
            data[i + 17] = AIN;
            wait_us(20000/freq);
        }
		for (int i = 0; i < 17; i++) {
            sample = (uint16_t)(59578 * (17 - i) / 17);
            aout.write_u16(sample);
	        data[i + 33] = AIN;
            wait_us(20000/freq);
        }
        
			for (int i = 0; i < 17; i++) {
            sample = (uint16_t)(59578 * i / 17);
            aout.write_u16(sample);
            data[i+50] = AIN;
            wait_us(20000/freq);
        }
        for (int i = 0; i < 16; i++) {
            sample = sample;
            aout.write_u16(sample);
            data[i + 67] = AIN;
            wait_us(20000/freq);
        }
		for (int i = 0; i < 17; i++) {
            sample = (uint16_t)(59578 * (17 - i) / 17);
            aout.write_u16(sample);
	        data[i + 83] = AIN;
            wait_us(20000/freq);
        }
		}
		if(sele==0.5){
			for (int i = 0; i < 8; i++) {
            sample = (uint16_t)(59578 * i / 8);
            aout.write_u16(sample);
            data[i] = AIN;
            wait_us(20000/freq);
        }
        for (int i = 0; i < 34; i++) {
            sample = sample;
            aout.write_u16(sample);
            data[i + 8] = AIN;
            wait_us(20000/freq);
        }
		for (int i = 0; i < 8; i++) {
            sample = (uint16_t)(59578 * (8 - i) / 8);
            aout.write_u16(sample);
	        data[i + 42] = AIN;
            wait_us(20000/freq);
        }
        
		for (int i = 0; i < 8; i++) {
            sample = (uint16_t)(59578 * i / 8);
            aout.write_u16(sample);
            data[i+50] = AIN;
            wait_us(20000/freq);
        }
        for (int i = 0; i < 34; i++) {
            sample = sample;
            aout.write_u16(sample);
            data[i + 58] = AIN;
            wait_us(20000/freq);
        }
		for (int i = 0; i < 8; i++) {
            sample = (uint16_t)(59578 * (8 - i) / 8);
            aout.write_u16(sample);
	        data[i + 92] = AIN;
            wait_us(20000/freq);
        }
		}
		if(sele==0.25){
			for (int i = 0; i < 5; i++) {
            sample = (uint16_t)(59578 * i / 5);
            aout.write_u16(sample);
            data[i] = AIN;
            wait_us(20000/freq);
        }
        for (int i = 0; i < 40; i++) {
            sample = sample;
            aout.write_u16(sample);
            data[i + 5] = AIN;
            wait_us(20000/freq);
        }
		for (int i = 0; i < 5; i++) {
            sample = (uint16_t)(59578 * (5 - i) / 5);
            aout.write_u16(sample);
	        data[i + 45] = AIN;
            wait_us(20000/freq);
        }
        
		for (int i = 0; i < 5; i++) {
            sample = (uint16_t)(59578 * i / 5);
            aout.write_u16(sample);
            data[i+50] = AIN;
            wait_us(20000/freq);
        }
        for (int i = 0; i < 40; i++) {
            sample = sample;
            aout.write_u16(sample);
            data[i + 55] = AIN;
            wait_us(20000/freq);
        }
		for (int i = 0; i < 5; i++) {
            sample = (uint16_t)(59578 * (5 - i) / 5);
            aout.write_u16(sample);
	        data[i + 95] = AIN;
            wait_us(20000/freq);
        }
		}
        if(sele==0.125){
			for (int i = 0; i < 3; i++) {
            sample = (uint16_t)(59578 * i *8/ 3);
            aout.write_u16(sample);
            data[i] = AIN;
            wait_us(20000/freq);
        }
        for (int i = 0; i < 44; i++) {
            sample = sample;
            aout.write_u16(sample);
            data[i + 3] = AIN;
            wait_us(20000/freq);
        }
		for (int i = 0; i < 3; i++) {
            sample = (uint16_t)(59578 * (2 - i)*8 / 3);
            aout.write_u16(sample);
	        data[i + 47] = AIN;
            wait_us(20000/freq);
        }
        
		for (int i = 0; i < 3; i++) {
            sample = (uint16_t)(59578 * i *8/ 3);
            aout.write_u16(sample);
            data[i+50] = AIN;
            wait_us(20000/freq);
        }
        for (int i = 0; i < 44; i++) {
            sample = sample;
            aout.write_u16(sample);
            data[i + 53] = AIN;
            wait_us(20000/freq);
        }
		for (int i = 0; i < 3; i++) {
            sample = (uint16_t)(59578 * (2 - i)*8 / 3);
            aout.write_u16(sample);
	        data[i + 97] = AIN;
            wait_us(20000/freq);
        }
		}   
    }
    for (int i = 0; i < 100; i++) {
            printf("%f\r\n", data[i]);
    }
}

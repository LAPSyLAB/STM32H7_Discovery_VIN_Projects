/*
 * melody.h
 *
 *  Created on: May 27, 2021
 *      Author: rozman
 */

#ifndef INC_MELODY_H_
#define INC_MELODY_H_

/*
 * melody.h
 *
 *  Created on: Feb 22, 2019
 *      Author: lukasz
 */

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

const uint32_t marioMelody[] = {
		  NOTE_E7, NOTE_E7, 0, NOTE_E7,
		  0, NOTE_C7, NOTE_E7, 0,
		  NOTE_G7, 0, 0,  0,
		  NOTE_G6, 0, 0, 0,

		  NOTE_C7, 0, 0, NOTE_G6,
		  0, 0, NOTE_E6, 0,
		  0, NOTE_A6, 0, NOTE_B6,
		  0, NOTE_AS6, NOTE_A6, 0,

		  NOTE_G6, NOTE_E7, NOTE_G7,
		  NOTE_A7, 0, NOTE_F7, NOTE_G7,
		  0, NOTE_E7, 0, NOTE_C7,
		  NOTE_D7, NOTE_B6, 0, 0,

		  NOTE_C7, 0, 0, NOTE_G6,
		  0, 0, NOTE_E6, 0,
		  0, NOTE_A6, 0, NOTE_B6,
		  0, NOTE_AS6, NOTE_A6, 0,

		  NOTE_G6, NOTE_E7, NOTE_G7,
		  NOTE_A7, 0, NOTE_F7, NOTE_G7,
		  0, NOTE_E7, 0, NOTE_C7,
		  NOTE_D7, NOTE_B6, 0, 0
};

const uint32_t secondMelody[] = {
		  NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4,
		  NOTE_G4, NOTE_C5, NOTE_AS4, NOTE_A4,
		  NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_DS4, NOTE_D4,
		  NOTE_C4, NOTE_D4,0,

		  NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4,
		  NOTE_G4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4,      //29               //8
		  NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_DS4, NOTE_D4,
		  NOTE_C4, NOTE_D4,0,

		  NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_DS5, NOTE_D5,
		  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5,
		  NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_FS4, NOTE_D5, NOTE_C5,
		  NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_AS4,             //58

		  NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_DS5, NOTE_D5,
		  NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_G4,
		  NOTE_A4, 0, NOTE_AS4, NOTE_A4, 0, NOTE_G4,
		  NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4, 0,

		  NOTE_C4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_DS4,
		  NOTE_C4, NOTE_D4, 0,
		  NOTE_C4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_DS4,
		  NOTE_C4, NOTE_D4
};

const uint32_t marioDuration[] = {
		  12, 12, 12, 12,
		  12, 12, 12, 12,
		  12, 12, 12, 12,
		  12, 12, 12, 12,

		  12, 12, 12, 12,
		  12, 12, 12, 12,
		  12, 12, 12, 12,
		  12, 12, 12, 12,

		  9, 9, 9,
		  12, 12, 12, 12,
		  12, 12, 12, 12,
		  12, 12, 12, 12,

		  12, 12, 12, 12,
		  12, 12, 12, 12,
		  12, 12, 12, 12,
		  12, 12, 12, 12,

		  9, 9, 9,
		  12, 12, 12, 12,
		  12, 12, 12, 12,
		  12, 12, 12, 12,
};

const uint32_t secondDuration[] = {
  8,4,8,4,
  4,4,4,12,
  4,4,4,4,4,4,
  4,16,4,

  8,4,8,4,
  4,2,1,1,2,1,1,12,
  4,4,4,4,4,4,
  4,16,4,

  4,4,4,4,4,4,
  4,4,4,12,
  4,4,4,4,4,4,
  4,4,4,12,

  4,4,4,4,4,4,
  2,1,1,2,1,1,4,8,4,
  2,6,4,2,6,4,
  2,1,1,16,4,

  4,8,4,4,4,
  4,16,4,
  4,8,4,4,4,
  4,20,
};


//##############**"Titanic" **##############//
const uint32_t Titanic_Melody[] = {
NOTE_E4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_B4, NOTE_E4,
NOTE_E4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_E4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_B4, NOTE_F5,
NOTE_E4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_B4, NOTE_E4,
NOTE_E4, NOTE_B4, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_B3, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_B3, NOTE_E4,
NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4


};
const uint32_t Titanic_duration[] = {
8,8,8,8,8,8,4,8,8,8,8,8,8,4,8,8,8,8,8,8,4,8,8,8,8,4,4,8,8,8,8,8,8,4,8,8,8,8,8,8,4,8,8,8,8,8,8,1,
8,8,8,8,4,4,4,8,4,4,8,8,8,8,4,8,8,4,8,4,8,8,4,8,4,1



};
//###########End of Titanic#############//

//##############**"HE IS A PIRATE" Theme song of Pirates of caribbean**##############//
const uint32_t  Pirates_notes[] = {
NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4,
NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4,
NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4,
NOTE_A3, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_F4,
NOTE_F4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_D4,
0, NOTE_A3, NOTE_C4, NOTE_B3, NOTE_D4, NOTE_B3, NOTE_E4, NOTE_F4,
NOTE_F4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4,
NOTE_D4, 0, 0, NOTE_A3, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_F4,
NOTE_G4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4,
NOTE_A4, NOTE_D4, 0, NOTE_D4, NOTE_E3, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_A4,
NOTE_D4, 0, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_F4, NOTE_D4
};
const uint32_t   Pirates_durations[] = {
4,8,4,8,4,8,8,8,8,4,8,4,8,4,8,8,8,8,4,8,4,8,
4,8,8,8,8,4,4,8,8,4,4,8,8,4,4,8,8,
8,4,8,8,8,4,4,8,8,4,4,8,8,4,4,8,4,
4,8,8,8,8,4,4,8,8,4,4,8,8,4,4,8,8,
8,4,8,8,8,4,4,4,8,4,8,8,8,4,4,8,8
};
//###########End of He is a Pirate song#############//


//##############**"Crazy Frog" song of Crazy frog album**##############//
const uint32_t   CrazyFrog_notes[] = {
  NOTE_D4, 0, NOTE_F4, NOTE_D4, 0, NOTE_D4, NOTE_G4, NOTE_D4, NOTE_C4,
  NOTE_D4, 0, NOTE_A4, NOTE_D4, 0, NOTE_D4, NOTE_AS4, NOTE_A4, NOTE_F4,
  NOTE_D4, NOTE_A4, NOTE_D5, NOTE_D4, NOTE_C4, 0, NOTE_C4, NOTE_A3, NOTE_E4, NOTE_D4,
  0,NOTE_D4,NOTE_D4
};

const uint32_t   CrazyFrog_durations[] = {
  8, 8, 6, 16, 16, 16, 8, 8, 8,
  8, 8, 6, 16, 16, 16, 8, 8, 8,
  8, 8, 8, 16, 16, 16, 16, 8, 8, 2,
  8,4,4
};
//###########End of Crazy Frog#############//



const uint32_t* melody[] ={marioMelody, secondMelody, Titanic_Melody,Pirates_notes,CrazyFrog_notes};
const uint32_t* noteDurations[] = {marioDuration, secondDuration, Titanic_duration,Pirates_durations,CrazyFrog_durations};
const uint16_t melodySlowfactor[] ={15, 30, 20, 20, 20};

const uint32_t melodySizes[] ={sizeof(marioMelody)/sizeof(uint32_t),
						sizeof(secondDuration)/sizeof(uint32_t),
						sizeof(Titanic_duration)/sizeof(uint32_t),
						sizeof(Pirates_durations)/sizeof(uint32_t),
						sizeof(CrazyFrog_durations)/sizeof(uint32_t)};


#endif /* INC_MELODY_H_ */

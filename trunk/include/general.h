/* 
**  SpaceBubble for Wii - Created by wplaat (www.plaatsoft.nl)
**  
**  Copyright (C) 2008-2010
**  =======================
**
**  This program is free software; you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, version 2.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program; if not, write to the Free Software
**  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "GRRLIB.h"

#define PROGRAM_NAME	    		"SpaceBubble"
#define PROGRAM_VERSION     	"0.93"
#define RELEASE_DATE        	"08-01-2010" 

// Check latest available version 
#define URL1                	"http://www.plaatsoft.nl/service/releasenotes4.html"
#define ID1			        		"UA-6887062-1"

// Fetch Release notes
#define URL2                	"http://www.plaatsoft.nl/service/releasenotes4.html"
#define ID2				   	 	"UA-6887062-1"

// Set Get Today HighScore
#define URL3                	"http://www.plaatsoft.nl/service/score_set_today.php"
#define ID3				    		"UA-6887062-1"

// Set Get Global HighScore
#define URL4                	"http://www.plaatsoft.nl/service/score_set_global.php"
#define ID4				    		"UA-6887062-1"

#define URL_TOKEN           	" Version "
#define HIGHSCORE_FILENAME  	"sd:/apps/SpaceBubble/highscore.xml"
#define SETTING_FILENAME    	"sd:/apps/SpaceBubble/setting.xml"
#define TRACE_FILENAME      	"sd:/apps/SpaceBubble/spacebubble.trc"
#define GAME_DIRECTORY      	"sd:/apps/SpaceBubble/"
#define MP3_DIRECTORY       	"sd:/music/"

#define WSP_POINTER_X       	200
#define WSP_POINTER_Y       	250

#define COLOR_WHITESMOKE    	0xFFFFFF
#define COLOR_LIGHTRED      	0x3333FF
#define COLOR_DARKBLACK     	0x000000

#define IMAGE_COLOR				0xFFFFFFFF
#define IMAGE_COLOR1        	0xEEEEEEEE
#define IMAGE_COLOR2        	0xDDDDDDDD
#define IMAGE_COLOR3        	0x44444444
#define IMAGE_COLOR4        	0xAAAAAAAA

#define MAX_BUTTONS         	10
#define MAX_RUMBLE				4
#define MAX_BOARDSIZE 			14
#define MAX_BUBBLES   			(MAX_BOARDSIZE*MAX_BOARDSIZE)
#define MAX_HORZ_PIXELS			640
#define MAX_VERT_PIXELS			480

#define MAX_LOCAL_HIGHSCORE 	100
#define MAX_TODAY_HIGHSCORE	50
#define MAX_GLOBAL_HIGHSCORE	50

#define MAX_SETTINGS				10
#define MAX_LEVEL    	    	7
#define MAX_LEN			    	256
#define MAX_ANGLE					360
#define MIN_ALFA					127
#define MAX_ALFA					255
#define MAX_SIZE		    		1.0
#define MIN_BUBBLE_SIZE			1.0
#define MAX_BUBBLE_SIZE			1.1
#define MAX_SOUND_VOLUME		10
#define MAX_MUSIC_TRACK     	9
#define MAX_LINES		    		200
#define MAX_BUFFER_SIZE			8192
#define MAX_IDLE_TIME	    	10
#define MAX_POINTER         	4
#define EXPLODE_STEP	    		4
#define OUT_OF_TIME		    	15

#define IR_X_OFFSET         	40
#define IR_Y_OFFSET         	40

#define SCROLLBAR_x         	600
#define SCROLLBAR_Y_MIN     	150
#define SCROLLBAR_Y_MAX     	310

#define MUSIC_MULTIPLER			5
#define EFFECT_MULTIPLER		20

#define BUTTON_A            	(WPAD_BUTTON_A     | WPAD_CLASSIC_BUTTON_A)
#define BUTTON_HOME         	(WPAD_BUTTON_HOME  | WPAD_CLASSIC_BUTTON_HOME)
#define BUTTON_1            	(WPAD_BUTTON_1     | WPAD_CLASSIC_BUTTON_X)
#define BUTTON_2            	(WPAD_BUTTON_2     | WPAD_CLASSIC_BUTTON_Y)
#define BUTTON_UP           	(WPAD_BUTTON_UP    | WPAD_CLASSIC_BUTTON_UP)
#define BUTTON_DOWN         	(WPAD_BUTTON_DOWN  | WPAD_CLASSIC_BUTTON_DOWN)
#define BUTTON_LEFT         	(WPAD_BUTTON_LEFT  | WPAD_CLASSIC_BUTTON_LEFT)
#define BUTTON_RIGHT        	(WPAD_BUTTON_RIGHT | WPAD_CLASSIC_BUTTON_RIGHT)
#define BUTTON_PLUS         	(WPAD_BUTTON_PLUS  | WPAD_CLASSIC_BUTTON_PLUS)

// -----------------------------------------------------------
// ENUMS
// -----------------------------------------------------------
 
enum
{
   stateIntro1=0,   
   stateIntro2=1, 
   stateIntro3=2, 
   stateMenu=3,
   stateGame=4,
   stateLevelCleared=5,
   stateGameOver=6,
   stateQuit=7,
   stateLocalHighScore=8,
   stateTodayHighScore=9,
   stateGlobalHighScore=10,
   stateHelp1=11,
	stateHelp2=12,
   stateCredits=13,
   stateSound=14,
   stateReleaseNotes=15,
   stateSettings=16,  
   stateNone=17
};

enum
{
   fontTitle=0,
   fontSubTitle=1,
   fontSubTitle2=2,
   fontParagraph=3,
   fontNormal=4,
   fontSpecial=5,
   fontNew=6,
   fontButton=7,
   fontWelcome=8
};

// -----------------------------------------------------------
// TYPEDEFS 
// -----------------------------------------------------------
 
typedef struct 
{
  // png + jpg Image index  
  GRRLIB_texImg *background1;
  GRRLIB_texImg *background2;
  
  GRRLIB_texImg *panel1;
  GRRLIB_texImg *button1;
  GRRLIB_texImg *button1select;  
  GRRLIB_texImg *button2;
  GRRLIB_texImg *button2select;  
  GRRLIB_texImg *bar;
  GRRLIB_texImg *barCursor;
  GRRLIB_texImg *sound;
  
  GRRLIB_texImg *pointer1;
  GRRLIB_texImg *pointer2;
  GRRLIB_texImg *pointer3;
  GRRLIB_texImg *pointer4;
  
  GRRLIB_texImg *scrollbar;
  GRRLIB_texImg *scrollTop;
  GRRLIB_texImg *scrollMiddle;
  GRRLIB_texImg *scrollBottom;  
  
  GRRLIB_texImg *noBubble;
  GRRLIB_texImg *blueBubble;
  GRRLIB_texImg *blueSelectBubble;
  GRRLIB_texImg *yellowBubble;
  GRRLIB_texImg *yellowSelectBubble;
  GRRLIB_texImg *greenBubble;
  GRRLIB_texImg *greenSelectBubble;
  GRRLIB_texImg *redBubble;
  GRRLIB_texImg *redSelectBubble;
  GRRLIB_texImg *pinkBubble;
  GRRLIB_texImg *pinkSelectBubble;
  GRRLIB_texImg *lightblueBubble;
  GRRLIB_texImg *lightblueSelectBubble;
  GRRLIB_texImg *blackBubble;
  GRRLIB_texImg *blackSelectBubble;
  GRRLIB_texImg *whiteBubble;
  GRRLIB_texImg *whiteSelectBubble;
  GRRLIB_texImg *gameboard;

  GRRLIB_texImg *logo;  
  GRRLIB_texImg *logo1;
  GRRLIB_texImg *logo2;
  GRRLIB_texImg *logo3;
  GRRLIB_texImg *logo4;
  GRRLIB_texImg *logo5;
  GRRLIB_texImg *logo6;
} 
image;

image images;

typedef struct
{
   int   x;
   int   y;
   int   color;
   int   width;
   int   height;
   bool  selected;
   bool  enabled;
   bool  check;
   float size;
   bool  sizeDirection;
   bool  hint;
} 
bubble;

bubble bubbles[MAX_BUBBLES+1];

typedef struct
{
   int   x;
   int   y;
   int   color;
   int   width;
   int   height;
   int   alfa;
   float size;
   bool  enabled;
   bool  moveX;
   bool  moveY;
} 
explode;

explode explodes[MAX_BUBBLES+1];

typedef struct
{
   int  x;
   int  y;
   int  width;
   int  height;
   GRRLIB_texImg *image;
} 
board;

board gameboard[MAX_BUBBLES];

// Setting[0] First Character Initial
// Setting[1] Second Character Initial
// Setting[2] Third Character Initial
// Setting[3] Music volume
// Setting[4] Sound Effect volume
// Setting[5] Loop music track
// Setting[6] MP3 support

typedef struct
{
   char   key[MAX_LEN];
   char   value[MAX_LEN];
}
setting;

setting settings[MAX_SETTINGS+1];

typedef struct
{
   time_t localTime;
   int    level;
   int    score; 
   char   name[MAX_LEN];
}
highscore;

highscore localHighScore[MAX_LOCAL_HIGHSCORE+1];


typedef struct
{
   time_t dt;
   char   score[MAX_LEN];
   char   name[MAX_LEN];
   char   location[MAX_LEN];
}
topscore;

topscore todayHighScore[MAX_TODAY_HIGHSCORE+1];
topscore globalHighScore[MAX_GLOBAL_HIGHSCORE+1];


typedef struct
{
   GRRLIB_texImg *image;
   GRRLIB_texImg *imageSelect;
   char  name[MAX_LEN]; 
   int   x;
   int   y;
} 
button;

button buttons[MAX_BUTTONS+1];


struct 
{
  // General game variables
  time_t  localTime;
  time_t  playTime;
  time_t  prevPlayTime;
  time_t  idleTime;
  int     score;
  int     level;
  int     possiblities;
  char    name[MAX_LEN];
  int     maxTime;
  int     bubbleCount;
  
  // Variables for score calculation
  int     timeBonus;
  int     timeBonusFactor;
  int     timeBonusScore;
  int     bubbleOver;
  int     bubbleOverFactor;
  int     bubbleOverScore;
  int     totalClear;
  int     totalClearFactor;
  int     totalClearScore;
  int     extraBonus;
  int     selectScore;
}
game;


typedef struct 
{
  ir_t    ir;
  int     x;
  int     xOffset;
  int     y;
  int     yOffset;
  int     angle;
  int     rumble;
  GRRLIB_texImg *image;
}
pointer;

pointer pointers[MAX_POINTER];

// -----------------------------------------------------------
// The End
// -----------------------------------------------------------
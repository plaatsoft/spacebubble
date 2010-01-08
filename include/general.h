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

#define PROGRAM_NAME	    		"SpaceBubble"
#define PROGRAM_VERSION     	"0.93"
#define RELEASE_DATE        	"07-01-2010" 

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
#define IMAGE_COLOR         	0xFFFFFFFF

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

#define MAX_LOCAL_HIGHSCORE 	50
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
// The End
// -----------------------------------------------------------
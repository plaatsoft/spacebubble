/**
 * 
 * @file
 * @brief This file contain all defines.
 * @author wplaat
 *
 *  Copyright (C) 2008-2011 PlaatSoft
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef __GENERAL_H__
#define __GENERAL_H__

#include <wiiuse/wpad.h>

#include "GRRLIB.h"

#define PROGRAM_NAME	    		"SpaceBubble"
#define PROGRAM_VERSION     	"0.98"
#define RELEASE_DATE        	"24-03-2011" 

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

#define GRRLIB_WHITESMOKE   	0xFFFFFFFF
#define GRRLIB_WHITE_TRANS   	0xFFFFFF44
#define GRRLIB_LIGHTRED     	0x3333FFFF
#define GRRLIB_BLACK 			0x000000FF
#define GRRLIB_BLACK_TRANS		0x00000044
#define GRRLIB_BLACK_TRANS_2	0x000000AA
#define GRRLIB_MAROON  			0x800000FF
#define GRRLIB_GREEN   			0x008000FF
#define GRRLIB_OLIVE   			0x808000FF
#define GRRLIB_NAVY    			0x000080FF
#define GRRLIB_PURPLE  			0x800080FF
#define GRRLIB_TEAL    			0x008080FF
#define GRRLIB_GRAY    			0x808080FF
#define GRRLIB_SILVER  			0xC0C0C0FF
#define GRRLIB_RED     			0xFF0000FF
#define GRRLIB_LIME    			0x00FF00FF
#define GRRLIB_YELLOW  			0xFFFF00FF
#define GRRLIB_BLUE    			0x0000FFFF
#define GRRLIB_FUCHSIA 			0xFF00FFFF
#define GRRLIB_AQUA    			0x00FFFFFF
#define GRRLIB_WHITE   			0xFFFFFFFF

#define IMAGE_COLOR				0xFFFFFFFF
#define IMAGE_COLOR1        	0xEEEEEEEE
#define IMAGE_COLOR2        	0xDDDDDDDD
#define IMAGE_COLOR3        	0x44444444
#define IMAGE_COLOR4        	0xAAAAAAAA

#define MAX_BUTTONS         	20
#define MAX_RUMBLE				4
#define MAX_BOARDSIZE 			14
#define MAX_BUBBLES   			(MAX_BOARDSIZE*MAX_BOARDSIZE)
#define MAX_HORZ_PIXELS			640
#define MAX_VERT_PIXELS			480
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

#define MAX_LOCAL_HIGHSCORE 	100
#define MAX_TODAY_HIGHSCORE	50
#define MAX_GLOBAL_HIGHSCORE	50

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
	stateIntro4=3, 
   stateMenu=4,
   stateGame=5,
   stateLevelCleared=6,
   stateGameOver=7,
   stateQuit=8,
   stateLocalHighScore=9,
   stateTodayHighScore=10,
   stateGlobalHighScore=11,
   stateHelp1=12,
	stateHelp2=13,
   stateCredits=14,
   stateSound=15,
   stateReleaseNotes=16,
   stateSettings=17,  
	stateDonate=18,
   stateNone=19
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
  
  GRRLIB_texImg *intro4;
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
  int 	 rating;
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

/**
 * @mainpage Wii SpaceBubble Documentation
 * Welcome to the SpaceBubble documentation.
 *
 * @section Introduction
 * SpaceBubble is a 2D classic game for the Nintendo Wii.
 *
 * @section Links
 * Website: http://www.plaatsoft.nl\n
 * Code: http://code.google.com/p/spacebubble\n
 *
 * @section Credits
 * Documentation: wplaat\n
 *
 * @section ReleaseNotes
 *
 * <b>24-03-2011 Version 0.98</b>
 * - GUI:
 *  - Update menu screen information.
 * - Core:
 *  - Optimise core performance.
 *  - Added intro screen 4 (WarQuest game info)
 * - General:
 *  - Build game with devkitPPC r21 compiler.
 *
 * <b>13-09-2010 Version 0.97</b>
 * - GUI:
 *  - Update menu screen information.
 * - Core:
 *  - Solve random freeze problem during startup of game.
 * - General:
 *  - Build game with devkitPPC r21 compiler. 
 *
 *  <b>11-09-2010 Version 0.96</b>
 *  - GUI:
 *   - Update menu screen information.
 *   - Overall FPS has improved 50 percent. Thanks Crayon
 *  - Core:
 *   - Use GRRLIB 4.3.0 as graphical engine.
 *   - libpng was updated to version 1.4.2
 *   - libjpeg was updated to version 8b
 *   - zlib was updated to version 1.2.5
 *   - FreeType was updated to 2.3.12
 *  - General:
 *   - Maintenance release.
 *   - Build game with devkitPPC r21 compiler.
 *
 *  <b>31-03-2010 Version 0.95</b>
 *  - GUI:
 *    - Update menu screen information.
 *  - Core:
 *   - WiiMote timeout increase from 60 to 300 seconds.
 *   - Added local highscore position calculation.
 *   - Improve stability.
 *   - Use libfat 1.0.7 as disk access engine.
 *   - Use libogc 1.8.3 as Wii interface engine
 *  - General:
 *   - Make source code compliant with r21 compiler.
 *   - Improve source code documentation.
 *   - Added screenshots to source code documentation.
 *   - Build game with devkitPPC r21 compiler.
 *
 *  <b>17-02-2010 Version 0.94</b>
 *  - GUI:
 *   - Improve game settings screen.
 *   - Added donate screen. 
 *   - Update main menu screen information.
 *   - Improve bubble graphics.
 *  - Core:
 *   - Extend user name from 3 to 6 characters.
 *   - Default user name is based on Wii nickname.
 *   - Increase http buffer size from 8kb to 10kb.
 *  - General:
 *   - Added source code to Google Code Repository
 *   - Added source code documentation (Javadoc style).
 *   - Added Doxygen (automatic documentation generation tool) config file.
 *   - Build game with devkitPPC r19 compiler.
 *
 *  <b>08-01-2010 Version 0.93</b>
 *  - GUI:
 *   - Improve main menu screen.
 *   - Added 60Hz (640x480) TV Mode support.
 *   - Added extra help screen with WiiMote control information.
 *  - Core:
 *   - Increase local highscore list to maximum 100 entries.
 *   - Store current game score in highscore area also when game is quited.
 *   - use GRRLIB v4.2.0 library as graphical engine.
 *   - Use libogc v1.8.1 library as Wii interface engine.
 *  - General:
 *   - Build game with devkitPPC r19 compiler.
 *
 *  <b>19-11-2009 Version 0.92</b>
 *  - GUI:
 *    - Added today top highscore screen.
 *  - Core: 
 *   - Added functionality to trace game events to trace file.
 *   - High score is send to web service if score is better then 5000 points.
 *   - Improve network thread
 *   - Use libfat v1.0.6 as disk access engine
 *   - Use libmxml v2.6 library as xml engine
 *   - Use libogc v1.8.0 library as Wii interface engine
 *  - General:
 *   - Build game with devkitPPC r19 compiler.
 *
 *  <b>17-09-2009 Version 0.91</b>
 *  - Core:
 *   - Maintenance release
 *   - This version is compiled with the newest available Wii libraries.
 *   - Use the asndlib (part of libogc) now as standard sound engine.
 *   - Use libfat 1.0.4 as disk access engine.
 *   - Use libogc 1.7.1a as Wii interface engine
 *  - General:
 *   - Game build with devkitPPC r17 compiler.
 *
 *  <b>09-03-2009 Version 0.90</b>
 *  - GUI:
 *   - Improve intro screens.
 *   - Added fps information on all screens.
 *  - Core:
 *   - Added new GRRLIB v4.0 library as graphical render engine.
 *   - Added screenshot functionality with plus button.
 *   - Pictures are store on the SdCard in the following directory sd:/apps/SpaceBubble
 *  - General:
 *   - Game build with devkitPPC r17 compiler.
 *
 *  <b>14-02-2000 Version 0.80</b>
 *  - GUI:
 *   - Show frame per second information on game screen.
 *   - Added information popup windows.
 *  - Core: 
 *   - Improve Frame-per-second performance during game play.
 *   - Add 10 seconds extra playtime to each level.
 *   - Disable MP3 background music support. Too slow!
 *   - Bug fix: Global highscore screen is not crashing anymore!
 *   - Use libogc 1.7.1 as Wii inteface engine.
 *  - General:
 *   - Game build with devkitPPC r16 compiler.
 *
 *  <b>08-02-2009 Version 0.70</b>
 *  - GUI:
 *   - Increase gameboard size from 12x12 to 14x14 bubbles. 
 *   - Improve level cleared screen.
 *  - Core: 
 *   - Added total clear (no bubbles left) bonus per level. 
 *   - Remove gameboard control buttons. Use the WiiMote A button instead.
 *   - Press the Home button on WiiMote to return to the menu screen.
 *   - High score is send to web service if score is better then 12.000 point.
 *   - Only this first WiiMote can control the music and stop a running game.
 *   - Bug fix: Do not show bubble select hint when game is over. 
 *   - Bug fix: Hint is now always working correct.
 *  - General:
 *   - Game build with devkitPPC r16 compiler.
 * 
 *  <b>05-02-2009 Version 0.60</b>
 *  - GUI:
 *   - Rename "General Setting" menu button to "User Initials".
 *   - Add level seven with more bonus points to earn.
 *   - Bug fix: Clock color is now showed always right.
 *  - Core:
 *   - Add two, three and four multi player mode.
 *   - Added in sound settings button "loop music track".
 *   - Sound settings are stored in configuration file.
 *   - Play random music track during game.
 *   - If player is 10 seconds idle give a random bubble select hint.
 *   - From level five SuperShift bubble option is activated.
 *   - Improve score calculation on cleared level screen.
 *  - General:
 *   - Game build with devkitPPC r15 compiler.
 *
 *  <b>28-01-2009 Version 0.50</b>
 *  - GUI:
 *   - Added bubble destroy graphical effect.
 *   - Added 10 seconds extra playtime to each level.
 *   - Clock color is changing to red for the last 15 seconds.
 *   - Improve help screen.
 *   - Reposition some buttons.
 *  - Core:
 *   - Hot fix: Prevent crash if IR pointer is going out of the screen.
 *   - Adjusted effect and music default volume.
 *  - General:
 *   - Game build with devkitPPC r15 compiler.
 *
 *  <b>26-01-2009 Version 0.40</b>
 *  - GUI:
 *   - Show score of selected bubbles on screen.
 *   - The 40 highest global scores are showed.
 *   - Reposition some buttons.
 *   - Added level cleared information screen.
 *   - Added clock color is changing to red for the last 10 seconds.
 *   - Adapted button size on most screens.
 *  - Core:
 *   - Increase http receive buffer size to 8196 bytes.
 *   - HotFix: Prevent random crashes if wifi connection does not response.
 *   - HotFix: Prevent wrong calculation of possible moves.
 *   - Added Winner text if player clears all six levels.
 *   - Added 2.000 bonus points if you clear all levels.
 *   - Added clock sound effects.
 *  - General:
 *   - Game build with devkitPPC r15 compiler.
 * 
 *  <b>24-01-2009 Version 0.30</b>
 *  - GUI:
 *   - Added scrollbar to highscore and release notes screens.
 *   - The fifty highest local scores are showed.
 *   - The thirty highest global localHighScore are showed.
 *   - Improve button layout.
 *   - Improve three intro screen.
 *  - General:
 *   - Game build with devkitPPC r15 compiler.
 *
 *  <b>23-01-2009 Version 0.20</b>
 *  - GUI:
 *   - Added help screen information.
 *   - Added Local / Global highscore functionality.
 *   - Added game info panel to game screen.
 *   - Added countdown clock.
 *  - Core:
 *   - Added 9 background music tracks.
 *   - Added several sound effects.
 *   - Each level has it on score matrix and time parameter.
 *   - Added player initials setting screen.
 *   - Added load/save game setting to sdcard.
 *   - Use only one unique cookie number during the game.
 *   - Improve score calculation.
 *   - If level is cleared (remaining time * factor) is added to score.
 *   - Added ShiftRight bubble functionality.
 *   - Added six game levels.
 *   - Gamescore is send anonymouse to webservices on internet.
 *  - General:
 *   - Cleanup not used source code.
 *   - First offical release for the Wii HomeBrew scene.
 *   - Game build with devkitPPC r15 compiler.
 *
 *  <b>19-01-2009 Version 0.10</b>
 *  - GUI:
 *   - Created intro screens.
 *   - Created raw gameboard layout 
 *  - General:
 *   - Started programming.
 *   - Basic game engine ready.
 *   - Game build with devkitPPC r15 compiler.
 *
 * @section WishList
 *  - Multi language support (Move language to xml data files)
 *  - Add Nintendo external LAN device support 
 *
 * @section ScreenShots
 * This section contain some screenshots of the game.
 * - <a href="../screenshots/SpaceBubble-intro1.jpg">Intro Screen 1</a>
 * - <a href="../screenshots/SpaceBubble-intro2.jpg">Intro Screen 2</a>
 * - <a href="../screenshots/SpaceBubble-intro3.jpg">Intro Screen 3</a>
 * - <a href="../screenshots/SpaceBubble-mainmenu.jpg">Main Menu Screen</a>
 * - <a href="../screenshots/SpaceBubble-game1.jpg">Game Screen 1</a>
 * - <a href="../screenshots/SpaceBubble-game2.jpg">Game Screen 2</a>
 * - <a href="../screenshots/SpaceBubble-game3.jpg">Level cleared Screen</a>
 * - <a href="../screenshots/SpaceBubble-game4.jpg">Quit game screen</a>
 * - <a href="../screenshots/SpaceBubble-highscore1.jpg">Local Highscore screen</a>
 * - <a href="../screenshots/SpaceBubble-highscore2.jpg">Today Highscore screen</a>
 * - <a href="../screenshots/SpaceBubble-highscore3.jpg">Global Highscore screen</a>
 * - <a href="../screenshots/SpaceBubble-help1.jpg">Help 1 screen</a>
 * - <a href="../screenshots/SpaceBubble-help2.jpg">Help 2 screen </a>
 * - <a href="../screenshots/SpaceBubble-credits.jpg">Credits screen</a>
 * - <a href="../screenshots/SpaceBubble-releasenotes.jpg">Release Notes screen</a>
 * - <a href="../screenshots/SpaceBubble-soundsettings.jpg">Sound Settings screen</a>
 * - <a href="../screenshots/SpaceBubble-gamesettings.jpg">Game Settings screen</a>
 * - <a href="../screenshots/SpaceBubble-donate.jpg">Donate screen</a>
 * 
 * @section Licence
 * Copyright (c) 2008-2010 Plaatsoft
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
 #endif
 
// -----------------------------------------------------------
// The End
// -----------------------------------------------------------
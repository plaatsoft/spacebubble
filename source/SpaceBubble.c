/* 
**  SpaceBubble for Wii - Created by wplaat (www.plaatsoft.nl)
**
**  SpaceBubble is a classic board puzzle game based bubble breaker. Select multiple 
**  bubbles with the same color and destroy them, the more you hit in one the higher 
**  score you will get.
**
**  Key Features:
**  - 2D Bubble Gameboard with special graphical effects
**  - Support one to four players
**  - Seven game levels
**  - Game score is shared with all players
**  - Easy menu system
**  - WiiMote IR control
**  - 16 music tracks
**  - Several sound effects
**  
**  Copyright (C) 2009
**  ==================
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
**
**  Release Notes:
**  ==============
**
** Wishlist:
**  - Nintendo Game Cube controller support
**  - Nintendo Wii Classic controller support
**  - Multi language support (Move language to xml data files)
**  - Nintendo External LAN device support 
**
**  19/11/2009 Version 0.92
**  - Added today top highscore screen.
**  - Added functionality to trace game events to trace file.
**  - High score is send to web service if score is better then 5000 points.
**  - Improve network thread
**  - Use libfat 1.0.6 as disk access engine
**  - Use libmxml 2.6 library as xml engine
**  - Use libogc 1.8.0 library as Wii interface engine
**  - Build game with devkitPPC r19 compiler.
**
**  17/09/2009 Version 0.91
**  - This version is compiled with the newest available Wii libraries.
**  - Use the asndlib (part of libogc) now as standard sound engine.
**  - Use libfat 1.0.4 as disk access engine.
**  - Build game with libogc 1.7.1a and devkitPPC 1.5.0 (r17) compiler.
**
**  09/03/2009 Version 0.90
**  - Added new GRRLIB v4.0 library as graphical render engine.
**  - Improve intro screens.
**  - Added fps information on all screens.
**  - Added screenshot functionality with plus button.
**  - Pictures are store on the SdCard in the following directory sd:/apps/SpaceBubble
**
**  14/02/2000 Version 0.81
**  - Hot fix: Solve major bug in global highscore screen. If the local score did
**    not contain more the 13 entries the global highscore screen crashed. Oeps.
**  - Build game with libogc 1.7.1 and devkitPPC r16 compiler.
**
**  11/02/2009 Version 0.80
**  - Improve Frame-per-second performance during game play.
**  - Show frame per second information on game screen.
**  - Added information popup windows.
**  - Add 10 seconds extra playtime to each level.
**  - Disable MP3 background music support. Too slow!
**  - Bug fix: Global highscore screen is not crashing anymore!
**
**  08/02/2009 Version 0.70
**  - Increase gameboard size from 12x12 to 14x14 bubbles. 
**  - Added total clear (no bubbles left) bonus per level. 
**  - Remove gameboard control buttons. Use the WiiMote A button instead.
**  - Press the Home button on WiiMote to return to the menu screen.
**  - High score is send to web service if score is better then 12.000 point.
**  - Only this first WiiMote can control the music and stop a running game.
**  - Bug fix: Do not show bubble select hint when game is over. 
**  - Bug fix: Hint is now always working correct.
**
**  05/02/2009 Version 0.60
**  - Add two, three and four multi player mode.
**  - Added in sound settings button "loop music track".
**  - Sound settings are stored in configuration file.
**  - Play random music track during game.
**  - If player is 10 seconds idle give a random bubble select hint.
**  - From level five SuperShift bubble option is activated.
**  - Rename "General Setting" menu button to "User Initials".
**  - Improve score calculation on cleared level screen.
**  - Add level seven with more bonus points to earn.
**  - Bug fix: Clock color is now showed always right.
**
**  28/01/2009 Version 0.50
**  - Hot fix: Prevent crash if IR pointer is going out of the screen.
**  - Adjusted effect and music default volume.
**  - Added bubble destroy graphical effect.
**  - Add 10 seconds extra playtime to each level.
**  - Clock color is changing to red for the last 15 seconds.
**  - Improve help screen.
**  - Reposition some buttons.
**
**  26/01/2009 Version 0.40
**  - Show score of selected bubbles on screen.
**  - The 40 highest global scores are showed.
**  - Reposition some buttons.
**  - Add level cleared information screen.
**  - Increase http receive buffer size to 8196 bytes.
**
**  25/01/2009 Version 0.31
**  - Hot fix: Prevent random crashes if wifi connection does not response.
**  - Hot fix: Prevent wrong calculation of possible moves.
**  - Added Winner text if player clears all six levels.
**  - Added 2.000 bonus points if you clear all levels.
**  - Added clock color is changing to red for the last 10 seconds.
**  - Added clock sound effects.
**  - Adapted button size on most screens.
** 
**  24/01/2009 Version 0.30
**  - Added scrollbar to highscore and release notes screens.
**  - The fifty highest local scores are showed.
**  - The thirty highest global localHighScore are showed.
**  - Improve button layout.
**  - Improve three intro screen.
**
**  23/01/2009 Version 0.20
**  - Added 9 background music tracks.
**  - Added several sound effects.
**  - Each level has it on score matrix and time parameter.
**  - First offical release for the Wii HomeBrew scene.
**
**  22/01/2009 Version 0.13
**  - Added player initials setting screen.
**  - Added load/save game setting to sdcard.
**  - Use only one unique cookie number during the game.
**  - Improve score calculation.
**  - If level is cleared (remaining time * factor) is added to score.
**
**  21/01/2009 Version 0.12
**  - Added Local / Global highscore functionality.
**  - Added game info panel to game screen.
**  - Added countdown clock.
**   
**  20/01/2009 Version 0.11
**  - Added ShiftRight bubble functionality.
**  - Added six game levels.
**  - Gamescore is send anonymouse to webservices on internet.
**  - Added help screen information.
**  - Cleanup not used source code.
**
**  19/01/2009 Version 0.10
**  - Started programming.
**  - Created raw gameboard layout
**  - Created intro screens.
**  - Basic game engine ready.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ogcsys.h>
#include <gccore.h>
#include <gcmodplay.h> 
#include <wiiuse/wpad.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h> 
#include <asndlib.h>
#include <fat.h>
#include <mxml.h>
#include <sys/dir.h>
#include <mp3player.h>
#include <ogc/lwp_watchdog.h>	
 
#include "http.h"
#include "GRRLIB.h"
#include "trace.h"
#include "effect1_pcm.h"
#include "effect2_pcm.h"
#include "effect3_pcm.h"
#include "track1_mod.h"
#include "track2_mod.h"
#include "track3_mod.h"
#include "track4_mod.h"
#include "track5_mod.h"
#include "track6_mod.h"
#include "track7_mod.h"
#include "track8_mod.h"
#include "track9_mod.h"

// -----------------------------------------------------------
// DEFINES
// -----------------------------------------------------------

#define PROGRAM_NAME	    	"SpaceBubble"
#define PROGRAM_VERSION     	"0.92"
#define RELEASE_DATE        	"19-11-2009" 

// Check latest available version 
#define URL1                	"http://www.plaatsoft.nl/service/releasenotes4.html"
#define ID1			        	"UA-6887062-1"

// Fetch Release notes
#define URL2                	"http://www.plaatsoft.nl/service/releasenotes4.html"
#define ID2				   	 	"UA-6887062-1"

// Set Get Today HighScore
#define URL3                	"http://www.plaatsoft.nl/service/score_set_today.php"
#define ID3				    	"UA-6887062-1"

// Set Get Global HighScore
#define URL4                	"http://www.plaatsoft.nl/service/score_set_global.php"
#define ID4				    	"UA-6887062-1"

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

#define MAX_BUTTONS         	10
#define MAX_RUMBLE				4
#define MAX_BOARDSIZE 			14
#define MAX_BUBBLES   			(MAX_BOARDSIZE*MAX_BOARDSIZE)
#define MAX_HORZ_PIXELS			640
#define MAX_VERT_PIXELS			480

#define MAX_LOCAL_HIGHSCORE 	50
#define MAX_TODAY_HIGHSCORE	 	50
#define MAX_GLOBAL_HIGHSCORE	50

#define MAX_SETTINGS			10
#define MAX_LEVEL    	    	7
#define MAX_LEN			    	256
#define MAX_ANGLE				360
#define MIN_ALFA				127
#define MAX_ALFA				255
#define MAX_SIZE		    	1.0
#define MIN_BUBBLE_SIZE			1.0
#define MAX_BUBBLE_SIZE			1.2
#define MAX_SOUND_VOLUME		10
#define MAX_MUSIC_TRACK     	9
#define MAX_LINES		    	200
#define MAX_BUFFER_SIZE			8192
#define MAX_IDLE_TIME	    	10
#define MAX_POINTER         	4
#define EXPLODE_STEP	    	4
#define OUT_OF_TIME		    	15
#define IR_X_OFFSET         	40
#define IR_Y_OFFSET         	40
#define SCROLLBAR_x         	600
#define SCROLLBAR_Y_MIN     	150
#define SCROLLBAR_Y_MAX     	310

#define MUSIC_MULTIPLER			5
#define EFFECT_MULTIPLER		20

#define BUTTON_A            (WPAD_BUTTON_A     | WPAD_CLASSIC_BUTTON_A)
#define BUTTON_HOME         (WPAD_BUTTON_HOME  | WPAD_CLASSIC_BUTTON_HOME)
#define BUTTON_1            (WPAD_BUTTON_1     | WPAD_CLASSIC_BUTTON_X)
#define BUTTON_2            (WPAD_BUTTON_2     | WPAD_CLASSIC_BUTTON_Y)
#define BUTTON_UP           (WPAD_BUTTON_UP    | WPAD_CLASSIC_BUTTON_UP)
#define BUTTON_DOWN         (WPAD_BUTTON_DOWN  | WPAD_CLASSIC_BUTTON_DOWN)
#define BUTTON_LEFT         (WPAD_BUTTON_LEFT  | WPAD_CLASSIC_BUTTON_LEFT)
#define BUTTON_RIGHT        (WPAD_BUTTON_RIGHT | WPAD_CLASSIC_BUTTON_RIGHT)
#define BUTTON_PLUS         (WPAD_BUTTON_PLUS  | WPAD_CLASSIC_BUTTON_PLUS)

// -----------------------------------------------------------
// PROTOTYPES
// -----------------------------------------------------------

void loadLocalHighScoreFile(char* filename);
void saveLocalHighScoreFile(char* filename);

void loadTodayHighScore(char *buffer);
void loadGlobalHighScore(char *buffer);

void drawText(int x, int y, int type, char *text);
void buttonExit(int index);
void bubbleShiftDown(void);
void bubblePossibleOption(void);
void initBubbles(void);
int  bubbleEnabledCount(void);
int  bubbleSelectedCount(void);
void initExplodes(void);
void bubbleHint(void);

// -----------------------------------------------------------
// TYPEDEFS 
// -----------------------------------------------------------
 
typedef struct 
{
  // png + jpg Image index  
  GRRLIB_texImg background1;
  GRRLIB_texImg background2;
  
  GRRLIB_texImg panel1;
  GRRLIB_texImg button1;
  GRRLIB_texImg button1select;  
  GRRLIB_texImg button2;
  GRRLIB_texImg button2select;  
  GRRLIB_texImg bar;
  GRRLIB_texImg barCursor;
  GRRLIB_texImg sound;
  
  GRRLIB_texImg pointer1;
  GRRLIB_texImg pointer2;
  GRRLIB_texImg pointer3;
  GRRLIB_texImg pointer4;
  
  GRRLIB_texImg scrollbar;
  GRRLIB_texImg scrollTop;
  GRRLIB_texImg scrollMiddle;
  GRRLIB_texImg scrollBottom;  
  
  GRRLIB_texImg noBubble;
  GRRLIB_texImg blueBubble;
  GRRLIB_texImg blueSelectBubble;
  GRRLIB_texImg yellowBubble;
  GRRLIB_texImg yellowSelectBubble;
  GRRLIB_texImg greenBubble;
  GRRLIB_texImg greenSelectBubble;
  GRRLIB_texImg redBubble;
  GRRLIB_texImg redSelectBubble;
  GRRLIB_texImg pinkBubble;
  GRRLIB_texImg pinkSelectBubble;
  GRRLIB_texImg lightblueBubble;
  GRRLIB_texImg lightblueSelectBubble;
  GRRLIB_texImg blackBubble;
  GRRLIB_texImg blackSelectBubble;
  GRRLIB_texImg whiteBubble;
  GRRLIB_texImg whiteSelectBubble;
  GRRLIB_texImg gameboard;

  GRRLIB_texImg logo;  
  GRRLIB_texImg logo1;
  GRRLIB_texImg logo2;
  GRRLIB_texImg logo3;
  GRRLIB_texImg logo4;
  GRRLIB_texImg logo5;
  GRRLIB_texImg logo6;
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
   GRRLIB_texImg image;
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
   GRRLIB_texImg image;
   GRRLIB_texImg imageSelect;
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
  GRRLIB_texImg image;
}
pointer;

pointer pointers[MAX_POINTER];

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
   stateHelp=11,
   stateCredits=12,
   stateSound=13,
   stateReleaseNotes=14,
   stateSettings=15,  
   stateNone=16
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
// VARIABLES
// -----------------------------------------------------------

u32     *frameBuffer[1] = {NULL};
GXRModeObj *rmode = NULL;
Mtx     GXmodelView2D;
static  MODPlay snd1;
char    appl_user3[MAX_LEN];

int     yOffset           = 0;
int     yjpegOffset       = 0;
int     angle             = 0;
float   size              = 0;
float   wave1             = 0;
float   wave2             = 0;

bool    selected1         = false;
bool    selected2         = false;
bool    selectedA         = false;
int     scrollIndex       = 0;
bool    scrollEnabled     = false;

int     stateMachine        = stateIntro1;
int     prevStateMachine    = stateNone;

int     maxLocalHighScore  = 0;
int     maxTodayHighScore  = 0;
int     maxGlobalHighScore = 0;

int     maxButtons        = 0;
int     maxBubbles        = 0;
int     maxGameboard      = 0;
int     maxExplodes		  = 0;
int     selectedMusic     = 1;
int     musicVolume       = 5;
int     effectVolume      = 9;
int     loopMusicTrack    = 1;
int     enableMP3		  = 0;
int     hintCount		  = 0;
bool    bPowerOff         = false;	
bool    gameResult		  = false;

// MP3 support
//char    mp3files[1000][80]; 
//int     mp3count=0;
//char    mp3file[MAXPATHLEN]; 
//char    *mp3buffer=NULL;*/

// Background1 Image
extern const unsigned char     pic4data[];
extern int      pic4length;

// Panel Image
extern const unsigned char     pic5data[];
extern int      pic5length;

// Button1 Image
extern const unsigned char     pic10data[];
extern int      pic10length;

// Button1select Image
extern const unsigned char     pic11data[];
extern int      pic11length;

// Button2 Image
extern const unsigned char     pic12data[];
extern int      pic12length;

// Button2select Image
extern const unsigned char     pic13data[];
extern int      pic13length;

// bar Image
extern const unsigned char     pic14data[];
extern const int      pic14length;

// barCursor Image
extern const unsigned char     pic15data[];
extern const int      pic15length;

// Sound Image
extern const unsigned char     pic16data[];
extern const int      pic16length;

// Pointer1 Image
extern const unsigned char     pic17data[];
extern const int      pic17length;

// Black Bubble Image
extern const unsigned char     pic18data[];
extern const int      pic18length;

// Blue Bubble Image
extern const unsigned char     pic19data[];
extern const int      pic19length;

// Blue Select Bubble Image
extern const unsigned char     pic20data[];
extern const int      pic20length;

// Yellow Bubble Image
extern const unsigned char     pic21data[];
extern const int      pic21length;

// Yellow Select Bubble Image
extern const unsigned char     pic22data[];
extern const int      pic22length;

// Green Bubble Image
extern const unsigned char     pic23data[];
extern const int      pic23length;

// Green Select Bubble Image
extern const unsigned char     pic24data[];
extern const int      pic24length;

// Red Bubble Image
extern const unsigned char     pic25data[];
extern const int      pic25length;

// Red Select Bubble Image
extern const unsigned char     pic26data[];
extern const int      pic26length;

// Pink Bubble Image
extern const unsigned char     pic27data[];
extern const int      pic27length;

// PinkSelect Bubble Image
extern const unsigned char     pic28data[];
extern const int      pic28length;

// LightBlue Bubble Image
extern const unsigned char     pic29data[];
extern const int      pic29length;

// LightBlue Select Bubble Image
extern const unsigned char     pic30data[];
extern const int      pic30length;

// Black Bubble Image
extern const unsigned char     pic31data[];
extern const int      pic31length;

// Black Select Bubble Image
extern const unsigned char     pic32data[];
extern const int      pic32length;

// Scrollbar image
extern const unsigned char     pic33data[];
extern const int      pic33length;

// ScrollTop image
extern const unsigned char     pic34data[];
extern const int      pic34length;

// ScrollMiddle image
extern const unsigned char     pic35data[];
extern const int      pic35length;

// scrollBottom image
extern const unsigned char     pic36data[];
extern const int      pic36length;
    
// White Bubble Image
extern const unsigned char     pic37data[];
extern const int      pic37length;

// WhiteSelect Bubble Image
extern const unsigned char     pic38data[];
extern const int      pic38length;

// Pointer2 Image
extern const unsigned char     pic39data[];
extern const int      pic39length;

// Pointer3 Image
extern const unsigned char     pic40data[];
extern const int      pic40length;

// Pointer4 Image
extern const unsigned char     pic41data[];
extern const int      pic41length;

// Background1 Image
extern const unsigned char     pic42data[];
extern const  int      pic42length;

// Logo1 Image
extern const unsigned char     pic43data[];
extern const int      pic43length;

// Logo2 Image
extern const unsigned char     pic44data[];
extern const int      pic44length;

// Logo3 Image
extern const unsigned char     pic45data[];
extern const int      pic45length;

// Logo4 Image
extern const unsigned char     pic46data[];
extern const int      pic46length;

// Logo5 Image
extern const unsigned char     pic47data[];
extern const int      pic47length;

// Background2 Image
extern const unsigned char     pic48data[];
extern const int      pic48length;

// Logo6 Image
extern const unsigned char     pic49data[];
extern const int      pic49length;


// -----------------------------------------------------------
// GAME LOGIC
// -----------------------------------------------------------

static u8 CalculateFrameRate() 
{
    static u8 frameCount = 0;
    static u32 lastTime;
    static u8 FPS = 0;
    u32 currentTime = ticks_to_millisecs(gettime());

    frameCount++;
    if(currentTime - lastTime > 1000) {
        lastTime = currentTime;
        FPS = frameCount;
        frameCount = 0;
    }
    return FPS;
}

/*int initMP3Files(void)
{
  mp3count= 0;

  struct stat st;
  DIR_ITER* dir; 
  dir = diropen (MP3_DIRECTORY); 

  if (dir == NULL) //If empty
  {
	return -1;
  } 
  else 
  {
	 while (dirnext(dir,mp3file,&st) == 0) 
	 {
		if (!(st.st_mode & S_IFDIR ))
		{
		  // st.st_mode & S_IFDIR indicates a directory
		  strcpy(mp3files[mp3count], mp3file);
		  ++mp3count;	
		}		
	 
      }	
   }	
   return mp3count;
}*/

/*s32  my_reader(void *fp,void *dat, s32 size)
{
	
	return fread(dat, 1, size, fp);
}*/

int initMusicTrack(void)
{
   char *s_fn="initMusicTrack";
   traceEvent(s_fn,0,"enter");
   
   /*if (enableMP3)
   {
       long lSize=0;
       char tmp[MAX_LEN];
       sprintf(tmp,"%s%s",MP3_DIRECTORY, mp3files[selectedMusic]);	   
	   
	   if (mp3buffer!=NULL)
	   {
 	      free (mp3buffer);	   
	   }
	   
	   FILE* pFile = fopen (tmp, "r");
		 
	   //Check that pFile exist
	   if (pFile!=NULL) 
	   {   
		  // obtain file size:
		  fseek (pFile , 0 , SEEK_END);
		  lSize = ftell (pFile);
		  rewind (pFile);

		  // allocate memory to contain the whole file:
		  mp3buffer = (char*) malloc (sizeof(char)*lSize);
		  if (mp3buffer == NULL) 
		  {
		     return -1;
		  }
		 
          // copy the file into the buffer:
		  int result = fread (mp3buffer,1,lSize,pFile);
		  if (result != lSize) return -2;

   		  // whole file is now loaded in the memory buffer
  	  	  fclose (pFile); 
	   }
	   else
	   {
	      return -3;
       } 
	 		
	   //if (mp3buffer != NULL) 
	   if (pFile != NULL) 
	   {
		   MP3Player_Init();		
		   //MP3Player_PlayBuffer(mp3buffer,lSize,NULL);
		   MP3Player_PlayFile(pFile, my_reader, NULL);
	   }
   }
   else*/
   {
     MODPlay_Init(&snd1);
     MODPlay_Stop(&snd1);
     MODPlay_Pause(&snd1,false);
 
     if (loopMusicTrack==1)
     {
        // Restart music track after finished
        snd1.manual_polling=false;
     }
     else
     {
        // Stop after music track finised
        snd1.manual_polling=true;
     }
   
     switch (selectedMusic)
     {
       case 1 : MODPlay_SetMOD(&snd1, track1_mod);
		 	    MODPlay_Start(&snd1);	
		 	    break;	
			   
       case 2 : MODPlay_SetMOD(&snd1, track2_mod);
			    MODPlay_Start(&snd1);	
			    break;
			   
       case 3 : MODPlay_SetMOD(&snd1, track3_mod);
			    MODPlay_Start(&snd1);	
			    break;
			   
       case 4 : MODPlay_SetMOD(&snd1, track4_mod);
			    MODPlay_Start(&snd1);	
			    break;
			   
       case 5 : MODPlay_SetMOD(&snd1, track5_mod);
		 	    MODPlay_Start(&snd1);	
			    break;	
		   
	   case 6 : MODPlay_SetMOD(&snd1, track6_mod);
			    MODPlay_Start(&snd1);	
			    break;	
			   
	   case 7 : MODPlay_SetMOD(&snd1, track7_mod);
			    MODPlay_Start(&snd1);	
			    break;	
			   
	   case 8 : MODPlay_SetMOD(&snd1, track8_mod);
			    MODPlay_Start(&snd1);	
			    break;	
			   
	   case 9 : MODPlay_SetMOD(&snd1, track9_mod);
			    MODPlay_Start(&snd1);	
			    break;
     } 
     MODPlay_SetVolume( &snd1, musicVolume*MUSIC_MULTIPLER,musicVolume*MUSIC_MULTIPLER); 
  }
  
  	traceEvent(s_fn,0,"leave [0]");
  return 0;
}

void initSound(void)
{
   char *s_fn="initSound";
   traceEvent(s_fn,0,"enter");
   
   // Init Sound engine	
   SND_Init(INIT_RATE_48000); 
   SND_Pause(0);
   
   initMusicTrack();	
   
   	traceEvent(s_fn,0,"leave [void]");
}

void initThreads(void)
{ 
   char *s_fn="initThreads";
   traceEvent(s_fn,0,"enter");
   
   char userData1[MAX_LEN];
   char userData2[MAX_LEN];

   // Set userData1   		 
   memset(userData1,0x00,sizeof(userData1));
   sprintf(userData1,"%s=%s",PROGRAM_NAME,PROGRAM_VERSION);
		
   // Get userData2 
   memset(userData2,0x00,sizeof(userData2));
   sprintf(userData2,"appl=%s",PROGRAM_NAME);
	   
   tcp_start_thread(PROGRAM_NAME, PROGRAM_VERSION, 
			ID1, URL1, 
			ID2, URL2, 
			ID3, URL3, 
			ID4, URL4, 
			URL_TOKEN, userData1, userData2);
   
   	traceEvent(s_fn,0,"leave [void]");
}

void initButtons(void)
{ 
   switch (stateMachine)
   {
      case stateMenu:
      {
        maxButtons=9;

		// Play button 
		buttons[0].image=images.button1;
		buttons[0].imageSelect=images.button1select;
		strcpy(buttons[0].name,"Play");
		buttons[0].x=370;
		buttons[0].y=10+yOffset;
   
		// High Score button 
		buttons[1].image=images.button1;
		buttons[1].imageSelect=images.button1select;
		strcpy(buttons[1].name,"High Score");   
		buttons[1].x=370;
		buttons[1].y=50+yOffset;

		// Help button 
		buttons[2].image=images.button1;
		buttons[2].imageSelect=images.button1select;
		strcpy(buttons[2].name,"Help" );
		buttons[2].x=370;
		buttons[2].y=90+yOffset;
	   
		// Credits button 
		buttons[3].image=images.button1;
		buttons[3].imageSelect=images.button1select;
		strcpy(buttons[3].name,"Credits" );
		buttons[3].x=370;
		buttons[3].y=130+yOffset;
   
        // Sound button 
		buttons[4].image=images.button1;
		buttons[4].imageSelect=images.button1select;
		strcpy(buttons[4].name,"Sound Settings" );
		buttons[4].x=370;
		buttons[4].y=170+yOffset;
		
		// Release Notes button 
		buttons[5].image=images.button1;
		buttons[5].imageSelect=images.button1select;
		strcpy(buttons[5].name,"Release Notes" );
		buttons[5].x=370;
		buttons[5].y=210+yOffset;
				
		// Initials Settings button 
		buttons[6].image=images.button1;
		buttons[6].imageSelect=images.button1select;
		strcpy(buttons[6].name,"User Initials" );
		buttons[6].x=370;
		buttons[6].y=250+yOffset;
		
		// Exit HBC button 
		buttons[7].image=images.button1;
		buttons[7].imageSelect=images.button1select;
		strcpy(buttons[7].name,"Exit HBC" );
		buttons[7].x=370;
		buttons[7].y=350+yOffset;
      
		// Reset Wii button 
		buttons[8].image=images.button1;
		buttons[8].imageSelect=images.button1select;
		strcpy(buttons[8].name,"Reset Wii" );
		buttons[8].x=370;
		buttons[8].y=390+yOffset;
    }
    break;
  
    case stateGame:
    {
		maxButtons=0;
	}
	break;
	
	case stateLevelCleared:
    {
		maxButtons=1;
		
		// Next button 
		buttons[0].image=images.button2;
		buttons[0].imageSelect=images.button2select;
		strcpy(buttons[0].name,"Next" );
		buttons[0].x=370;
		buttons[0].y=350+yOffset;
	}
	break;
	
	case stateQuit:
	{
		maxButtons=2;
		
		// Yes button 
		buttons[0].image=images.button2;
		buttons[0].imageSelect=images.button2select;
		strcpy(buttons[0].name,"Yes");
		buttons[0].x=310;
		buttons[0].y=250+yOffset;
	
		// No button 
		buttons[1].image=images.button2;
		buttons[1].imageSelect=images.button2select;
		strcpy(buttons[1].name,"No");
		buttons[1].x=400;
		buttons[1].y=250+yOffset;
	}
	break;
	
    case stateGameOver:
    {
		maxButtons=1;
		
		// Back button 
		buttons[0].image=images.button2;
		buttons[0].imageSelect=images.button2select;
		strcpy(buttons[0].name,"Back");
		buttons[0].x=355;
		buttons[0].y=250+yOffset;
	}
	break;
	
    case stateLocalHighScore:
	{
	    maxButtons=2;

		// Next button 
		buttons[0].image=images.button2;
		buttons[0].imageSelect=images.button2select;
		strcpy(buttons[0].name,"Next");
		buttons[0].x=280;
		buttons[0].y=400+yOffset;
		
		// Scrollbar button 
		buttons[1].image=images.scrollbar;
		buttons[1].imageSelect=images.scrollbar;
		strcpy(buttons[1].name,"");
		buttons[1].x=SCROLLBAR_x;
		buttons[1].y=SCROLLBAR_Y_MIN;
	}
	break;
	  
	case stateTodayHighScore:
	{
	    maxButtons=2;

		// Next button 
		buttons[0].image=images.button2;
		buttons[0].imageSelect=images.button2select;
		strcpy(buttons[0].name,"Next");
		buttons[0].x=280;
		buttons[0].y=400+yOffset;
		
		// Scrollbar button 
		buttons[1].image=images.scrollbar;
		buttons[1].imageSelect=images.scrollbar;
		strcpy(buttons[1].name,"");
		buttons[1].x=SCROLLBAR_x;
		buttons[1].y=SCROLLBAR_Y_MIN;
	}
	break;
	
	case stateGlobalHighScore:
	{
	    maxButtons=2;

		// Next button 
		buttons[0].image=images.button2;
		buttons[0].imageSelect=images.button2select;
		strcpy(buttons[0].name,"Next");
		buttons[0].x=280;
		buttons[0].y=400+yOffset;
		
		// Scrollbar button 
		buttons[1].image=images.scrollbar;
		buttons[1].imageSelect=images.scrollbar;
		strcpy(buttons[1].name,"");
		buttons[1].x=SCROLLBAR_x;
		buttons[1].y=SCROLLBAR_Y_MIN;
	}
	break;
	  
	case stateHelp:
	{
	    maxButtons=1;

		// Back button 
		buttons[0].image=images.button2;
		buttons[0].imageSelect=images.button2select;
		strcpy(buttons[0].name,"Back");
		buttons[0].x=280;
		buttons[0].y=400+yOffset;
	}
	break;
	  
	case stateCredits:
	{
	    maxButtons=1;

		// Back button 
		buttons[0].image=images.button2;
		buttons[0].imageSelect=images.button2select;
		strcpy(buttons[0].name,"Back");
		buttons[0].x=300;
		buttons[0].y=400+yOffset;
	}
	break;
	  
	  
	case stateSound:
    {
        maxButtons=9;

		// Music Volume - button 
		buttons[0].image=images.button2;
		buttons[0].imageSelect=images.button2select;
		strcpy(buttons[0].name,"-");
		buttons[0].x=20;
		buttons[0].y=130+yOffset;
   
		// Music Volume + button 
		buttons[1].image=images.button2;
		buttons[1].imageSelect=images.button2select;
		strcpy(buttons[1].name,"+");   
		buttons[1].x=540;
		buttons[1].y=130+yOffset;
		
		// Effect Volume - button 
		buttons[2].image=images.button2;
		buttons[2].imageSelect=images.button2select;
		strcpy(buttons[2].name,"-");
		buttons[2].x=20;
		buttons[2].y=230+yOffset;
   
		// Effect Volume + button 
		buttons[3].image=images.button2;
		buttons[3].imageSelect=images.button2select;
		strcpy(buttons[3].name,"+");   
		buttons[3].x=540;
		buttons[3].y=230+yOffset;
		
		// Music track - button 
		buttons[4].image=images.button2;
		buttons[4].imageSelect=images.button2select;
		strcpy(buttons[4].name,"-");
		buttons[4].x=140;
		buttons[4].y=310+yOffset;
   
		// Music track + button 
		buttons[5].image=images.button2;
		buttons[5].imageSelect=images.button2select;
		strcpy(buttons[5].name,"+");   
		buttons[5].x=420;
		buttons[5].y=310+yOffset;
		
		// Back button 
		buttons[6].image=images.button2;
		buttons[6].imageSelect=images.button2select;
		strcpy(buttons[6].name,"Back");
		buttons[6].x=280;
		buttons[6].y=400+yOffset;
		
		// Loop music track button 
		buttons[7].image=images.button2;
		buttons[7].imageSelect=images.button2select;
		if (loopMusicTrack==0)
		{
		   strcpy(buttons[7].name,"No");
		}
		else
		{
		   strcpy(buttons[7].name,"Yes");
		}
		buttons[7].x=60;
		buttons[7].y=400+yOffset;
		
		// MP3 music support button 
		buttons[8].image=images.button2;
		buttons[8].imageSelect=images.button2select;
		if (enableMP3==0)
		{
		   strcpy(buttons[8].name,"No");
		}
		else
		{		
  		   strcpy(buttons[8].name,"Yes");
		}
		buttons[8].x=500;
		buttons[8].y=400+yOffset;
	}
	break;
   
    case stateReleaseNotes:
	{
	    maxButtons=2;
	  		
		// Back button 
		buttons[0].image=images.button2;
		buttons[0].imageSelect=images.button2select;
		strcpy(buttons[0].name,"Back");
		buttons[0].x=280;
		buttons[0].y=400+yOffset;
		
		// Scrollbar button 
		buttons[1].image=images.scrollbar;
		buttons[1].imageSelect=images.scrollbar;
		strcpy(buttons[1].name,"");
		buttons[1].x=SCROLLBAR_x;
		buttons[1].y=SCROLLBAR_Y_MIN;
	}
	break;
	  
	case stateSettings:
	{
	    maxButtons=7;
		
	    // First letter + button 
		buttons[0].image=images.button2;
		buttons[0].imageSelect=images.button2select;
		strcpy(buttons[0].name,"+");
		buttons[0].x=100;
		buttons[0].y=130+yOffset;
   
		// First letter - button 
		buttons[1].image=images.button2;
		buttons[1].imageSelect=images.button2select;
		strcpy(buttons[1].name,"-");   
		buttons[1].x=100;
		buttons[1].y=295+yOffset;
				
		// Second letter + button 
		buttons[2].image=images.button2;
		buttons[2].imageSelect=images.button2select;
		strcpy(buttons[2].name,"+");
		buttons[2].x=280;
		buttons[2].y=130+yOffset;

		// Second letter - button 
		buttons[3].image=images.button2;
		buttons[3].imageSelect=images.button2select;
		strcpy(buttons[3].name,"-");   
		buttons[3].x=280;
		buttons[3].y=295+yOffset;
				
		// Third letter + button 
		buttons[4].image=images.button2;
		buttons[4].imageSelect=images.button2select;
		strcpy(buttons[4].name,"+");
		buttons[4].x=460;
		buttons[4].y=130+yOffset;
   
		// Third letter - button 
		buttons[5].image=images.button2;
		buttons[5].imageSelect=images.button2select;
		strcpy(buttons[5].name,"-");   
		buttons[5].x=460;
		buttons[5].y=295+yOffset;
		
		// Back button 
		buttons[6].image=images.button2;
		buttons[6].imageSelect=images.button2select;
		strcpy(buttons[6].name,"Back");
		buttons[6].x=280;
		buttons[6].y=400+yOffset;
	}
	break;
  }
}

void initGame()
{
   char *s_fn="initGame";
   traceEvent(s_fn,0,"enter");
   
   // Init variables
   selectedA=false;   
   selected1=false;
   selected2=false;
      
   angle=0; 
   size=0;
 
   initBubbles();
   initExplodes();
   
   	traceEvent(s_fn,0,"leave [void]");
}

void initLevel()
{
   char *s_fn="initLevel";
   traceEvent(s_fn,0,"enter");
   
   // Increes Level
   game.level++;	

   switch (game.level)
   {
      case 1:  game.maxTime=30;	           
			   break;

      case 2:  game.maxTime=55;	           
			   break;		

      case 3:  game.maxTime=70;	           
			   break;	   
			   
	  case 4:  game.maxTime=85;	           
			   break;
			   
	  case 5:  game.maxTime=95;	           
			   break;
			   
	  case 6:  game.maxTime=105;	           
			   break;
			   
	  case 7:  game.maxTime=120;	           
			   break;
   }   
   // Reset time
   game.localTime=time(NULL);   
   game.idleTime=time(NULL);
   game.selectScore=0;
   
   	traceEvent(s_fn,0,"leave [void]");
}
  			 
void initImages(void)
{
   char *s_fn="initImages";
   traceEvent(s_fn,0,"enter");
   
   // Buttons & Panels
   images.background1=GRRLIB_LoadTexture( pic4data);
   images.background2=GRRLIB_LoadTexture( pic48data);
   
   images.panel1=GRRLIB_LoadTexture(pic5data);
   images.button1=GRRLIB_LoadTexture( pic10data);
   images.button1select=GRRLIB_LoadTexture( pic11data);     
   images.button2=GRRLIB_LoadTexture( pic12data);
   images.button2select=GRRLIB_LoadTexture( pic13data);    
   images.bar=GRRLIB_LoadTexture( pic14data); 
   images.barCursor=GRRLIB_LoadTexture( pic15data);
   images.sound=GRRLIB_LoadTexture( pic16data);    
     
   images.pointer1=GRRLIB_LoadTexture( pic17data); 
   pointers[0].image=images.pointer1;
   images.pointer2=GRRLIB_LoadTexture( pic39data); 
   pointers[1].image=images.pointer2;
   images.pointer3=GRRLIB_LoadTexture( pic40data); 
   pointers[2].image=images.pointer3;
   images.pointer4=GRRLIB_LoadTexture( pic41data); 
   pointers[3].image=images.pointer4;
   
   images.scrollbar=GRRLIB_LoadTexture(pic33data);
   images.scrollTop=GRRLIB_LoadTexture( pic34data);
   images.scrollMiddle=GRRLIB_LoadTexture( pic35data);
   images.scrollBottom=GRRLIB_LoadTexture( pic36data);
      
   images.noBubble=GRRLIB_LoadTexture(pic18data); 
   images.blueBubble=GRRLIB_LoadTexture( pic19data); 
   images.blueSelectBubble=GRRLIB_LoadTexture( pic20data); 
   images.yellowBubble=GRRLIB_LoadTexture(pic21data); 
   images.yellowSelectBubble=GRRLIB_LoadTexture( pic22data); 
   images.greenBubble=GRRLIB_LoadTexture( pic23data); 
   images.greenSelectBubble=GRRLIB_LoadTexture( pic24data); 
   images.redBubble=GRRLIB_LoadTexture( pic25data); 
   images.redSelectBubble=GRRLIB_LoadTexture( pic26data); 
   images.pinkBubble=GRRLIB_LoadTexture( pic27data); 
   images.pinkSelectBubble=GRRLIB_LoadTexture( pic28data); 
   images.lightblueBubble=GRRLIB_LoadTexture( pic29data); 
   images.lightblueSelectBubble=GRRLIB_LoadTexture( pic30data); 
   images.blackBubble=GRRLIB_LoadTexture( pic31data); 
   images.blackSelectBubble=GRRLIB_LoadTexture(pic32data); 
   images.whiteBubble=GRRLIB_LoadTexture( pic37data); 
   images.whiteSelectBubble=GRRLIB_LoadTexture( pic38data); 
   images.gameboard=GRRLIB_LoadTexture( pic42data);   

   images.logo1=GRRLIB_LoadTexture( pic43data ); 
   images.logo2=GRRLIB_LoadTexture( pic44data );
   images.logo3=GRRLIB_LoadTexture( pic45data );
   images.logo4=GRRLIB_LoadTexture( pic46data );
   images.logo5=GRRLIB_LoadTexture( pic47data );
   images.logo6=GRRLIB_LoadTexture( pic49data );
   
   images.logo=GRRLIB_LoadTexture( pic44data );
   GRRLIB_InitTileSet(&images.logo, images.logo.w, 1, 0);
   
   traceEvent(s_fn,0,"leave [void]");
}


void initTodayHighScore(void)
{
   char *s_fn="initTodayHighScore";
   traceEvent(s_fn,0,"enter");
   
  int i;   

  // Clear today highscore memory
  for(i=0; i<MAX_TODAY_HIGHSCORE; i++)
  {
  	todayHighScore[i].score[0]=0x00;
	todayHighScore[i].dt=0;
	todayHighScore[i].name[0]=0x00;
	todayHighScore[i].location[0]=0x00;
  } 
  traceEvent(s_fn,0,"leave [void]");
}

void initGlobalHighScore(void)
{
   char *s_fn="initGlobalHighScore";
   traceEvent(s_fn,0,"enter");
   
  int i;   

  // Clear global highscore memory
  for(i=0; i<MAX_GLOBAL_HIGHSCORE; i++)
  {
  	globalHighScore[i].score[0]=0x00;
	globalHighScore[i].dt=0;
	globalHighScore[i].name[0]=0x00;
	globalHighScore[i].location[0]=0x00;
  } 
  
  traceEvent(s_fn,0,"leave [void]");
}

	
void initBubbles(void)
{
   char *s_fn="initBubbles";
   traceEvent(s_fn,0,"enter");
   
   int x,y;
   int xoffset=172;
   int yoffset=20;
   maxBubbles=0;
	
   for (y=0; y<MAX_BOARDSIZE; y++)
   {	
      for (x=0; x<MAX_BOARDSIZE; x++)
      {	
	       int nr=(y*MAX_BOARDSIZE)+x;
		   int color=rand() % (game.level+1);
		    
		   bubbles[nr].color=color;
		   bubbles[nr].enabled=true;
		   bubbles[nr].selected=false;
		   bubbles[nr].x=(32*x)+xoffset;
		   bubbles[nr].y=(32*y)+yoffset;
		   bubbles[nr].width=32;
		   bubbles[nr].height=32;	
		   bubbles[nr].size=MIN_BUBBLE_SIZE;  
		   bubbles[nr].hint=false;   
		   bubbles[nr].sizeDirection=false;
		   maxBubbles++;
	   }	
    }	
	bubblePossibleOption();
	bubbleHint();
	
		traceEvent(s_fn,0,"leave [void]");
}

void initGameBoard(void)
{
   char *s_fn="initGameBoard";
   traceEvent(s_fn,0,"enter");
   
   int x,y;
   int xoffset=172;
   int yoffset=20;	
   maxGameboard=0;
	
   for (y=0; y<MAX_BOARDSIZE; y++)
   {	
      for (x=0; x<MAX_BOARDSIZE; x++)
      {	
	      int nr=(y*MAX_BOARDSIZE)+x;
		  gameboard[nr].image=images.noBubble;
		  gameboard[nr].x=(32*x)+xoffset;
		  gameboard[nr].y=(32*y)+yoffset;
		  gameboard[nr].width=32;
		  gameboard[nr].height=32;			
		  maxGameboard++;
	   }	
    }	
	
		traceEvent(s_fn,0,"leave [void]");
}

void initExplodes(void)
{
   char *s_fn="initExplodes";
   traceEvent(s_fn,0,"enter");
   
   int i;
   maxExplodes=0;
	
   for (i=0; i<MAX_BUBBLES; i++)
   {	
      explodes[i].color=0;
	  explodes[i].size=0.0;
	  explodes[i].alfa=0;
	  explodes[i].enabled=false;
	  explodes[i].x=0;
	  explodes[i].y=0;
	  explodes[i].width=0;
	  explodes[i].height=0;		   
   }	
   
   	traceEvent(s_fn,0,"leave [void]");
}

void initStateMachine(void)
{	   
    // Start next mod music track
    if (snd1.manual_polling && snd1.paused) 
	{
	  if (selectedMusic<MAX_MUSIC_TRACK) selectedMusic++; else selectedMusic=1;   
      initMusicTrack();
	}

    switch(stateMachine)
    {
		case stateMenu:
		{
		   if (stateMachine!=prevStateMachine) initButtons();
		   prevStateMachine=stateMachine;
		}
		break;
		
		case stateQuit:
        case stateGame:
		{  		 
		   if (stateMachine!=prevStateMachine) initButtons();
		   prevStateMachine=stateMachine;
 
		   game.playTime = time(NULL)-game.localTime;  
           if ( game.playTime!=game.prevPlayTime) 
		   {
		     if  ( ((game.maxTime-game.playTime)<=OUT_OF_TIME) || ((game.playTime%5)==0) ) 
		     {		   
   	           SND_SetVoice(SND_GetFirstUnusedVoice(), VOICE_MONO_8BIT, 8000, 0, (u8 *) effect1_pcm, effect1_pcm_size, effectVolume*EFFECT_MULTIPLER, effectVolume*EFFECT_MULTIPLER, NULL);
		       game.prevPlayTime=game.playTime;
			 }
		   }
		   		
		   if (game.possiblities==0)
		   {			  
    	      SND_SetVoice(SND_GetFirstUnusedVoice(), VOICE_MONO_8BIT, 8000, 0, (u8 *) effect2_pcm, effect2_pcm_size, effectVolume*EFFECT_MULTIPLER, effectVolume*EFFECT_MULTIPLER, NULL);				   
			  gameResult=true; 
			  stateMachine=stateLevelCleared;	
		   }

           if (	game.playTime>=game.maxTime )
		   {
		      // Player lose, time up
  	          SND_SetVoice(SND_GetFirstUnusedVoice(), VOICE_MONO_8BIT, 8000, 0, (u8 *) effect2_pcm, effect2_pcm_size, effectVolume*EFFECT_MULTIPLER, effectVolume*EFFECT_MULTIPLER, NULL);
   			  gameResult=false;  
		      stateMachine=stateGameOver;	
           }		   
		}
		break;
		  
		case stateLevelCleared:
		{
		   if (stateMachine!=prevStateMachine) 
		   {
		       initButtons();
			   prevStateMachine=stateMachine;
			 
			   switch (game.level)
			   {
				   case 1:  game.timeBonus=game.maxTime-game.playTime;
							game.timeBonusFactor=10;
							game.timeBonusScore=game.timeBonus*game.timeBonusFactor;							
							game.bubbleOver=bubbleEnabledCount();
							game.bubbleOverFactor=-30;
							game.bubbleOverScore=game.bubbleOver*game.bubbleOverFactor;							
							game.extraBonus=0;							
							if (game.bubbleOver==0) game.totalClearFactor=1; else game.totalClearFactor=0;
							game.totalClear=250;
							game.totalClearScore=game.totalClear*game.totalClearFactor;
							break;
					
					case 2: game.timeBonus=game.maxTime-game.playTime;
							game.timeBonusFactor=20;
							game.timeBonusScore=game.timeBonus*game.timeBonusFactor;							
							game.bubbleOver=bubbleEnabledCount();
							game.bubbleOverFactor=-25;
							game.bubbleOverScore=game.bubbleOver*game.bubbleOverFactor;							
							game.extraBonus=250;	
							if (game.bubbleOver==0) game.totalClearFactor=1; else game.totalClearFactor=0;
							game.totalClear=500;
							game.totalClearScore=game.totalClear*game.totalClearFactor;          
							break;		

					case 3: game.timeBonus=game.maxTime-game.playTime;
							game.timeBonusFactor=30;
							game.timeBonusScore=game.timeBonus*game.timeBonusFactor;	           							
							game.bubbleOver=bubbleEnabledCount();
							game.bubbleOverFactor=-20;
							game.bubbleOverScore=game.bubbleOver*game.bubbleOverFactor;							
							if (game.bubbleOver==0) game.totalClearFactor=1; else game.totalClearFactor=0;
							game.totalClear=1000;
							game.totalClearScore=game.totalClear*game.totalClearFactor;
							game.extraBonus=500;
							break;	   
			   
					case 4: game.timeBonus=game.maxTime-game.playTime;
							game.timeBonusFactor=40;
							game.timeBonusScore=game.timeBonus*game.timeBonusFactor;    							
							game.bubbleOver=bubbleEnabledCount();
							game.bubbleOverFactor=-15;
							game.bubbleOverScore=game.bubbleOver*game.bubbleOverFactor;							
							if (game.bubbleOver==0) game.totalClearFactor=1; else game.totalClearFactor=0;
							game.totalClear=1500;
							game.totalClearScore=game.totalClear*game.totalClearFactor;
							game.extraBonus=1000;
							break;
			   
					case 5: game.timeBonus=game.maxTime-game.playTime;
							game.timeBonusFactor=50;
							game.timeBonusScore=game.timeBonus*game.timeBonusFactor;							
							game.bubbleOver=bubbleEnabledCount();
							game.bubbleOverFactor=-10;
							game.bubbleOverScore=game.bubbleOver*game.bubbleOverFactor;							
							if (game.bubbleOver==0) game.totalClearFactor=1; else game.totalClearFactor=0;
							game.totalClear=2000;
							game.totalClearScore=game.totalClear*game.totalClearFactor;
							game.extraBonus=1500;
							break;
			   
					case 6: game.timeBonus=game.maxTime-game.playTime;
							game.timeBonusFactor=60;
							game.timeBonusScore=game.timeBonus*game.timeBonusFactor;        							
							game.bubbleOver=bubbleEnabledCount();
							game.bubbleOverFactor=-5;
							game.bubbleOverScore=game.bubbleOver*game.bubbleOverFactor;							
							if (game.bubbleOver==0) game.totalClearFactor=1; else game.totalClearFactor=0;
							game.totalClear=2500;
							game.totalClearScore=game.totalClear*game.totalClearFactor;
							game.extraBonus=2500;							
							break;
							
					case 7: game.timeBonus=game.maxTime-game.playTime;
							game.timeBonusFactor=70;
							game.timeBonusScore=game.timeBonus*game.timeBonusFactor; 							
							game.bubbleOver=bubbleEnabledCount();
							game.bubbleOverFactor=-1;
							game.bubbleOverScore=game.bubbleOver*game.bubbleOverFactor;
							if (game.bubbleOver==0) game.totalClearFactor=1; else game.totalClearFactor=0;
							game.totalClear=3000;
							game.totalClearScore=game.totalClear*game.totalClearFactor;
							game.extraBonus=3000;							
							break;
			    }
		   }
		   
		}
		break;
		
		case stateGameOver:
		{
		   if (stateMachine!=prevStateMachine) initButtons();
		   prevStateMachine=stateMachine;
		}
		break;
						
		case stateLocalHighScore:
		{
		   if (stateMachine!=prevStateMachine) initButtons();
		   prevStateMachine=stateMachine;
		}
		break;
		
		case stateTodayHighScore:
		{
		   if (stateMachine!=prevStateMachine) 
		   {		   
		   	  char *buffer=tcp_get_today_highscore();
		      loadTodayHighScore(buffer);		     
		      initButtons();
		   }
		   prevStateMachine=stateMachine;
		}
		break;
		
		case stateGlobalHighScore:
		{
		   if (stateMachine!=prevStateMachine) 
		   {		   
		   	  char *buffer=tcp_get_global_highscore();
		      loadGlobalHighScore(buffer);		     
		      initButtons();
		   }
		   prevStateMachine=stateMachine;
		}
		break;
		
		case stateHelp:
		{
		   if (stateMachine!=prevStateMachine) initButtons();
		   prevStateMachine=stateMachine;
		}
		break;
		
		case stateCredits:
		{
		   if (stateMachine!=prevStateMachine) initButtons();
		   prevStateMachine=stateMachine;
		}
		break;
		
		case stateSound:
		{
		   if (stateMachine!=prevStateMachine) initButtons();
		   prevStateMachine=stateMachine;
		}
		break;
		
		case stateReleaseNotes:
		{
		   if (stateMachine!=prevStateMachine)  initButtons();
		   prevStateMachine=stateMachine;
		}
		break;
		
		case stateSettings:
		{
		   if (stateMachine!=prevStateMachine) initButtons();
		   prevStateMachine=stateMachine;
		}
		break;
	} 	
}

//	PowerOff callback function.
void doPowerOff( void )
{
    char *s_fn="doPowerOff";
    traceEvent(s_fn,0,"enter");
   
	bPowerOff = true;
	
	 traceEvent(s_fn,0,"leave [void]");
	return;
}

//	PowerOff callback function for the Wii Remote power button.
void doPadPowerOff( s32 chan )
{
    char *s_fn="doPadPowerOff";
    traceEvent(s_fn,0,"enter");
	
	if ( chan == WPAD_CHAN_0 )
	{
		bPowerOff = true;
	}
	
	traceEvent(s_fn,0,"leave [void]");
	return;
}

void saveLocalHighScoreFile(char* filename)
{
    char *s_fn="saveLocalHighScoreFile";
    traceEvent(s_fn,0,"enter");
	
   int i;
   bool store=false;
   int selectedHighScore=0;
   mxml_node_t *xml;
   mxml_node_t *group;
   mxml_node_t *data;   
   char tmp[MAX_LEN];
      
   xml = mxmlNewXML("1.0");
   
   group = mxmlNewElement(xml, "SpaceBubble");
   
   for(i=0; i<MAX_LOCAL_HIGHSCORE; i++)
   {
      if ((game.score>=localHighScore[i].score) && !store)
	  {
	     sprintf(tmp, "entry%d", i);
         data = mxmlNewElement(group, tmp);
  
	     sprintf(tmp, "%d", (int) game.localTime);
         mxmlElementSetAttr(data, "localTime", tmp);
	  
	     sprintf(tmp, "%d", game.score);
	     mxmlElementSetAttr(data, "score", tmp);

		 sprintf(tmp, "%d", game.level);
	     mxmlElementSetAttr(data, "level", tmp);
		 
	     mxmlElementSetAttr(data, "name", game.name);
		 
		 store=true;
	  }
	  else
	  {	  
        sprintf(tmp, "entry%d", i);
        data = mxmlNewElement(group, tmp);
  
	    sprintf(tmp, "%d", (int) localHighScore[selectedHighScore].localTime);
        mxmlElementSetAttr(data, "localTime", tmp);
	  
  	    sprintf(tmp, "%d", localHighScore[selectedHighScore].score);
	    mxmlElementSetAttr(data, "score", tmp);
		
		sprintf(tmp, "%d", localHighScore[selectedHighScore].level);
	    mxmlElementSetAttr(data, "level", tmp);
		
	    mxmlElementSetAttr(data, "name", localHighScore[selectedHighScore].name);
		
		selectedHighScore++;		
	  }	  
   }
  
   /* now lets save the xml file to a file! */
   FILE *fp;
   fp = fopen(filename, "w");

   mxmlSaveFile(xml, fp, MXML_NO_CALLBACK);
   
   /*Time to clean up!*/
   fclose(fp);
   mxmlDelete(data);
   mxmlDelete(group);
   mxmlDelete(xml);
   
    traceEvent(s_fn,0,"leave [void]");
}

void saveSettingFile(char* filename)
{
    char *s_fn="saveSettingFile";
    traceEvent(s_fn,0,"enter");
	
   int i;
   mxml_node_t *xml;
   mxml_node_t *group;
   mxml_node_t *data;   
   char temp[MAX_LEN];
      
   xml = mxmlNewXML("1.0");
   
   group = mxmlNewElement(xml, "SpaceBubble");
   
   for(i=0; i<MAX_SETTINGS; i++)
   {
        sprintf(temp, "entry%d", i);
        data = mxmlNewElement(group, temp);
  
        mxmlElementSetAttr(data, "key", settings[i].key);	  
 	    mxmlElementSetAttr(data, "value", settings[i].value);			  
   }
  
   /* now lets save the xml file to a file! */
   FILE *fp;
   fp = fopen(filename, "w");

   mxmlSaveFile(xml, fp, MXML_NO_CALLBACK);
   
   fclose(fp);
   mxmlDelete(data);
   mxmlDelete(group);
   mxmlDelete(xml);
   
   // Update game.name value
   if ((settings[0].value[0]!=0x00) && (settings[1].value[0]!=0x00) && (settings[2].value[0]!=0x00))
   {
      sprintf(temp,"%c%c%c",settings[0].value[0],settings[1].value[0],settings[2].value[0]);
      strcpy(game.name,temp);
   }
   
    traceEvent(s_fn,0,"leave [void]");
}

void loadTodayHighScore(char *buffer)
{
    char *s_fn="loadTodayHighScore";
    traceEvent(s_fn,0,"enter");
	
   int i;
   mxml_node_t *tree=NULL;
   mxml_node_t *data=NULL;
   const char *tmp;
   char temp[MAX_LEN];
   
   maxTodayHighScore=0;
   
   // Clear memory
   for(i=0; i<MAX_TODAY_HIGHSCORE; i++)
   {
      	todayHighScore[i].score[0]=0x00;
		todayHighScore[i].dt=0;
		todayHighScore[i].name[0]=0x00;
		todayHighScore[i].location[0]=0x00;
   } 
	 
   // If xml data available, parse it....
   if ((buffer!=NULL) && (strlen(buffer)>0))
   {  
      tree = mxmlLoadString(NULL, buffer, MXML_NO_CALLBACK);

      for(i=0; i<MAX_TODAY_HIGHSCORE; i++)
      {		
	    sprintf(temp, "item%d", i+1);
        data = mxmlFindElement(tree, tree, temp, NULL, NULL, MXML_DESCEND);

        tmp=mxmlElementGetAttr(data,"dt");   
        if (tmp!=NULL) todayHighScore[maxTodayHighScore].dt=atoi(tmp); else todayHighScore[maxTodayHighScore].dt=0; 
		
		tmp=mxmlElementGetAttr(data,"score");   
        if (tmp!=NULL) strcpy(todayHighScore[maxTodayHighScore].score,tmp); else strcpy(todayHighScore[maxTodayHighScore].score,"");
		
        tmp=mxmlElementGetAttr(data,"name");   
        if (tmp!=NULL) strcpy(todayHighScore[maxTodayHighScore].name,tmp); else strcpy(todayHighScore[maxTodayHighScore].name,"");

		tmp=mxmlElementGetAttr(data,"location");   
        if (tmp!=NULL) strcpy(todayHighScore[maxTodayHighScore].location,tmp); else strcpy(todayHighScore[maxTodayHighScore].location,"");
		
		// Entry is valid (Keep the inforamtion)
        if (strlen(todayHighScore[maxTodayHighScore].score)>0) maxTodayHighScore++;	
      }   
      mxmlDelete(data);
      mxmlDelete(tree);
   }
   
    traceEvent(s_fn,0,"leave [void]");
}

void loadGlobalHighScore(char *buffer)
{
    char *s_fn="loadGlobalHighScore";
    traceEvent(s_fn,0,"enter");
	
   int i;
   mxml_node_t *tree=NULL;
   mxml_node_t *data=NULL;
   const char *tmp;
   char temp[MAX_LEN];
   
   maxGlobalHighScore=0;
   
   // Clear memory
   for(i=0; i<MAX_GLOBAL_HIGHSCORE; i++)
   {
      	globalHighScore[i].score[0]=0x00;
		globalHighScore[i].dt=0;
		globalHighScore[i].name[0]=0x00;
		globalHighScore[i].location[0]=0x00;
   } 
	 
   // If xml data available, parse it....
   if ((buffer!=NULL) && (strlen(buffer)>0))
   {  
      tree = mxmlLoadString(NULL, buffer, MXML_NO_CALLBACK);

      for(i=0; i<MAX_GLOBAL_HIGHSCORE; i++)
      {		
	    sprintf(temp, "item%d", i+1);
        data = mxmlFindElement(tree, tree, temp, NULL, NULL, MXML_DESCEND);

        tmp=mxmlElementGetAttr(data,"dt");   
        if (tmp!=NULL) globalHighScore[maxGlobalHighScore].dt=atoi(tmp); else globalHighScore[maxGlobalHighScore].dt=0; 
		
		tmp=mxmlElementGetAttr(data,"score");   
        if (tmp!=NULL) strcpy(globalHighScore[maxGlobalHighScore].score,tmp); else strcpy(globalHighScore[maxGlobalHighScore].score,"");
		
        tmp=mxmlElementGetAttr(data,"name");   
        if (tmp!=NULL) strcpy(globalHighScore[maxGlobalHighScore].name,tmp); else strcpy(globalHighScore[maxGlobalHighScore].name,"");

		tmp=mxmlElementGetAttr(data,"location");   
        if (tmp!=NULL) strcpy(globalHighScore[maxGlobalHighScore].location,tmp); else strcpy(globalHighScore[maxGlobalHighScore].location,"");
		
		// Entry is valid (Keep the inforamtion)
        if (strlen(globalHighScore[maxGlobalHighScore].score)>0) maxGlobalHighScore++;	
      }   
      mxmlDelete(data);
      mxmlDelete(tree);
   }
   
    traceEvent(s_fn,0,"leave [void]");
}

void loadLocalHighScoreFile(char* filename)
{
    char *s_fn="loadLocalHighScoreFile";
    traceEvent(s_fn,0,"enter");
	
   int i;
   FILE *fp;
   mxml_node_t *tree=NULL;
   mxml_node_t *data=NULL;
   const char *tmp;
   char temp[MAX_LEN];

   maxLocalHighScore=0;
   
   /*Load our xml file! */
   fp = fopen(filename, "r");
   
   if (fp!=NULL)
   {
     tree = mxmlLoadFile(NULL, fp, MXML_NO_CALLBACK);
     fclose(fp);

     for(i=0; i<MAX_LOCAL_HIGHSCORE; i++)
     {
	    sprintf(temp, "entry%d", i);
        data = mxmlFindElement(tree, tree, temp, NULL, NULL, MXML_DESCEND);
  
  	    tmp=mxmlElementGetAttr(data,"score"); 
		if (tmp!=NULL) localHighScore[maxLocalHighScore].score=atoi(tmp); else localHighScore[maxLocalHighScore].score=0;
		
        tmp=mxmlElementGetAttr(data,"localTime");   
        if (tmp!=NULL) localHighScore[maxLocalHighScore].localTime=atoi(tmp); else localHighScore[maxLocalHighScore].localTime=0;
				
		tmp=mxmlElementGetAttr(data,"level"); 
		if (tmp!=NULL) localHighScore[maxLocalHighScore].level=atoi(tmp); else localHighScore[maxLocalHighScore].level=0;
		
		tmp=mxmlElementGetAttr(data,"name"); 
		if (tmp!=NULL) strcpy(localHighScore[maxLocalHighScore].name,tmp); else strcpy(localHighScore[maxLocalHighScore].name,"");
		
		// Entry is valid (Keep the inforamtion)
        if (localHighScore[maxLocalHighScore].score>0) maxLocalHighScore++;		
	 } 
   }
   else
   {
     // If file not found, create empty highscore list.
     for(i=0; i<MAX_LOCAL_HIGHSCORE; i++)
     {
       	localHighScore[i].localTime=0;
		localHighScore[i].score=0;
		localHighScore[i].level=0;
		memset(localHighScore[i].name,0x00,MAX_LEN);
	 } 
   }
   
   mxmlDelete(data);
   mxmlDelete(tree);
   
    traceEvent(s_fn,0,"leave [void]");
}
 
void loadSettingFile(char* filename)
{
    char *s_fn="loadSettingFile";
    traceEvent(s_fn,0,"enter");
	
   int i;
   FILE *fp;
   mxml_node_t *tree=NULL;
   mxml_node_t *data=NULL;
   const char *tmp;
   char temp[MAX_LEN];
   
   /*Load our xml file! */
   fp = fopen(filename, "r");
   if (fp!=NULL)
   {
     tree = mxmlLoadFile(NULL, fp, MXML_NO_CALLBACK);
     fclose(fp);

     for(i=0; i<MAX_SETTINGS; i++)
     {
	    sprintf(temp, "entry%d", i);
        data = mxmlFindElement(tree, tree, temp, NULL, NULL, MXML_DESCEND);
  
        tmp=mxmlElementGetAttr(data,"key");   
        if (tmp!=NULL) strcpy(settings[i].key,tmp); else strcpy(settings[i].key,"");
		
		tmp=mxmlElementGetAttr(data,"value"); 
		if (tmp!=NULL) strcpy(settings[i].value,tmp); else strcpy(settings[i].value,"");
		
		switch (i)
		{
		   case 3: if (strcmp(settings[i].key,"MUSIC_VOLUME")==0)
				   {
					  musicVolume=atoi(settings[i].value);
				   }
		           break;

           case 4: if (strcmp(settings[i].key,"EFFECT_VOLUME")==0)
		           {
				      effectVolume=atoi(settings[i].value);
				   }
		           break;

           case 5: if (strcmp(settings[i].key,"LOOP_TRACK")==0)
		           {
				      loopMusicTrack=atoi(settings[i].value);
				   }
				   break;
					
		   case 6: if (strcmp(settings[i].key,"PLAY_MP3")==0)
		           { 
				      enableMP3=atoi(settings[i].value);
				   }
				   break;
	    } 
	 } 
   }
   else
   {
     // If file not found, create empty highscore list.
     for(i=0; i<MAX_SETTINGS; i++)
     {
        memset(settings[i].key,0x00, MAX_LEN);
		memset(settings[i].value,0x00, MAX_LEN);

		// Setting[0] First Character Initial
		strcpy(settings[0].key,"FIRST_CHAR");		
		strcpy(settings[0].value,"A");
		
		// Setting[1] Second Character Initial
		strcpy(settings[1].key,"SECOND_CHAR");
		strcpy(settings[1].value,"A");
		
		// Setting[2] Third Character Initial
		strcpy(settings[2].key,"THIRD_CHAR");
		strcpy(settings[2].value,"A");
		
		// Setting[3] Music volume
		strcpy(settings[3].value,"5");
		strcpy(settings[3].key,"MUSIC_VOLUME");
		
		// Setting[4] Sound Effect volume
		strcpy(settings[4].value,"9");
		strcpy(settings[4].key,"EFFECT_VOLUME");
		
		// Setting[5] Loop music track
		strcpy(settings[5].value,"0");
		strcpy(settings[5].key,"LOOP_TRACK");
		
		// Setting[6] MP3 support
		strcpy(settings[6].value,"0");
		strcpy(settings[6].key,"PLAY_MP3");
	 } 
   }

   mxmlDelete(data);
   mxmlDelete(tree);
   
   // Update game.name value  
   if ((settings[0].value[0]!=0x00) && (settings[1].value[0]!=0x00) && (settings[2].value[0]!=0x00))
   {
      sprintf(temp,"%c%c%c",settings[0].value[0],settings[1].value[0],settings[2].value[0]);
      strcpy(game.name,temp);
   }
    traceEvent(s_fn,0,"leave [void]");
}

// Gameboard matrix (10x10)
// 00 01 02 03 04 05 06 07 08 09 
// 10 11 12 13 14 15 16 17 18 19 
// 20 21 22 23 24 25 26 27 28 29
// 30 31 32 33 34 35 36 37 38 39
// 40 41 42 43 44 45 46 47 48 49
// 50 51 52 53 54 55 56 57 58 59
// 60 61 62 63 64 65 66 67 68 69
// 70 71 72 73 74 75 76 77 78 79
// 80 81 82 83 84 85 86 87 88 89
// 90 91 92 93 94 95 96 97 98 99

void bubbleSuperShiftRight(void)
{
   int x, y, i, nr;
   for (i=0; i<MAX_BOARDSIZE; i++) 
   {   
     for (y=0; y<MAX_BOARDSIZE; y++)
     {
       for (x=(MAX_BOARDSIZE-1);x>0;x--)    
       {  
		 nr=(y*MAX_BOARDSIZE)+x;
	 	 if ( !bubbles[nr].enabled && bubbles[nr-1].enabled)
	     {	   
	       bubbles[nr].enabled=bubbles[nr-1].enabled;
		   bubbles[nr].selected=false;
		   bubbles[nr].color=bubbles[nr-1].color;
			   
		   bubbles[nr-1].enabled=false;
		   bubbles[nr-1].selected=false;
		 }
	   }
     }
   }
}

void bubbleShiftRight(void)
{
   int x, y, i, nr;
   for (i=0; i<MAX_BOARDSIZE; i++) 
   {
     for (x=(MAX_BOARDSIZE-1);x>0;x--)
     {  
       if ( !bubbles[((MAX_BOARDSIZE-1)*MAX_BOARDSIZE)+x].enabled )
	   {
         for (y=0; y<MAX_BOARDSIZE; y++)
         {  
		   nr=(y*MAX_BOARDSIZE)+x;
	       bubbles[nr].enabled=bubbles[nr-1].enabled;
		   bubbles[nr].selected=false;
		   bubbles[nr].color=bubbles[nr-1].color;
			   
		   bubbles[nr-1].enabled=false;
		   bubbles[nr-1].selected=false;
		  }
        }
	 }
   }        
}

void bubbleShiftDown(void)
{
   int x, y1, y2;
   for (x=0;x<MAX_BOARDSIZE;x++)
   {   
      for (y2=(MAX_BOARDSIZE-1);y2>0;y2--)
      {  
	     if (!bubbles[(y2*MAX_BOARDSIZE)+x].enabled )
		 {
           for (y1=(y2-1);y1>=0;y1--)
           {  
	         if ( bubbles[(y1*MAX_BOARDSIZE)+x].enabled )
		     {			  
		       bubbles[(y2*MAX_BOARDSIZE)+x].enabled=true;
			   bubbles[(y2*MAX_BOARDSIZE)+x].selected=false;
			   bubbles[(y2*MAX_BOARDSIZE)+x].color=bubbles[(y1*MAX_BOARDSIZE)+x].color;
			   
			   bubbles[(y1*MAX_BOARDSIZE)+x].enabled=false;
			   bubbles[(y1*MAX_BOARDSIZE)+x].selected=false;
			   
			   break;
		     }
		   }
		 }
	  }
   }        
}

void bubbleMultiSelect3(int nr)
{
   int x=nr % MAX_BOARDSIZE;
   int y=nr / MAX_BOARDSIZE;
   		
   hintCount++;
		
   // Set select flag for bubble	   
   bubbles[nr].hint=true;
   
   // Find all connected bubbles with the same color.
   if ((x>0) && (bubbles[nr].color==bubbles[nr-1].color) && !bubbles[nr-1].hint && bubbles[nr-1].enabled) bubbleMultiSelect3(nr-1); 
   if ((x<(MAX_BOARDSIZE-1)) && (bubbles[nr].color==bubbles[nr+1].color) && !bubbles[nr+1].hint && bubbles[nr+1].enabled) bubbleMultiSelect3(nr+1);
   if ((y>0) && (bubbles[nr].color==bubbles[nr-MAX_BOARDSIZE].color) && !bubbles[nr-MAX_BOARDSIZE].hint && bubbles[nr-MAX_BOARDSIZE].enabled) bubbleMultiSelect3(nr-MAX_BOARDSIZE); 
   if ((y<(MAX_BOARDSIZE-1)) && (bubbles[nr].color==bubbles[nr+MAX_BOARDSIZE].color) && !bubbles[nr+MAX_BOARDSIZE].hint && bubbles[nr+MAX_BOARDSIZE].enabled) bubbleMultiSelect3(nr+MAX_BOARDSIZE); 
}

void bubbleHint(void)
{ 
  if (game.possiblities==0) return;
  
  int i;
  int nr;
  do
  {
    hintCount=0;
    for (i=0; i<maxBubbles; i++) bubbles[i].hint=false;  
	nr=rand() % MAX_BUBBLES;
    if (bubbles[nr].enabled) bubbleMultiSelect3(nr);
  }
  while (hintCount<=1);
}


void bubbleMultiSelect2(int nr)
{
   int x=nr % MAX_BOARDSIZE;
   int y=nr / MAX_BOARDSIZE;
   		
   // Set select flag for bubble	   
   bubbles[nr].check=true;
   game.bubbleCount++;
   
   // Find all connected bubbles with the same color.
   if ((x>0) && (bubbles[nr].color==bubbles[nr-1].color) && !bubbles[nr-1].check && bubbles[nr-1].enabled) bubbleMultiSelect2(nr-1); 
   if ((x<(MAX_BOARDSIZE-1)) && (bubbles[nr].color==bubbles[nr+1].color) && !bubbles[nr+1].check && bubbles[nr+1].enabled) bubbleMultiSelect2(nr+1);
   if ((y>0) && (bubbles[nr].color==bubbles[nr-MAX_BOARDSIZE].color) && !bubbles[nr-MAX_BOARDSIZE].check && bubbles[nr-MAX_BOARDSIZE].enabled) bubbleMultiSelect2(nr-MAX_BOARDSIZE); 
   if ((y<(MAX_BOARDSIZE-1)) && (bubbles[nr].color==bubbles[nr+MAX_BOARDSIZE].color) && !bubbles[nr+MAX_BOARDSIZE].check && bubbles[nr+MAX_BOARDSIZE].enabled) bubbleMultiSelect2(nr+MAX_BOARDSIZE); 
}

void bubblePossibleOption(void)
{
  int i;
  for (i=0; i<maxBubbles; i++) bubbles[i].check=false;  
  
  game.possiblities=0;  
  for (i=0; i<maxBubbles; i++)
  {     
     if (!bubbles[i].check && bubbles[i].enabled)
	 {
	    game.bubbleCount=0;		
		bubbleMultiSelect2(i);
		if (game.bubbleCount>1) game.possiblities++;
	 }
  }
}

void bubbleExplodeMove(void)
{
  int i;
  for (i=0; i<MAX_BUBBLES; i++)
  {     
     if (explodes[i].enabled) 
	 {
	    if (!explodes[i].moveX)
		{
		   if (explodes[i].x>10) explodes[i].x-=EXPLODE_STEP; else explodes[i].enabled=false;
		}
		else
		{
		   if (explodes[i].x<(MAX_HORZ_PIXELS-10)) explodes[i].x+=EXPLODE_STEP; else explodes[i].enabled=false;
		}
		
		if (!explodes[i].moveY)
		{
		   if (explodes[i].y>10) explodes[i].y-=EXPLODE_STEP; else explodes[i].enabled=false;
	    }
		else
		{
		   if (bubbles[i].y<(MAX_VERT_PIXELS-10)) explodes[i].y+=EXPLODE_STEP; else explodes[i].enabled=false;
		}
		if (explodes[i].alfa>3) explodes[i].alfa-=3;
		if (explodes[i].size>0) explodes[i].size+=0.02;
	 }
  }
}

void bubbleRemove(void)
{
   int i;
   
   // If two or more bubbles are selected then remove them.
   if (game.selectScore>1)
   {
      game.score+=game.selectScore;
	  
      for (i=0; i<maxBubbles; i++)
      {
        if (bubbles[i].selected) 
	    {
		  bubbles[i].selected=false;
		  bubbles[i].enabled=false;
		  
          // Add remove bubble to explodes list		  
		  explodes[maxExplodes].x=bubbles[i].x;
		  explodes[maxExplodes].y=bubbles[i].y;
		  explodes[maxExplodes].width=bubbles[i].width;
		  explodes[maxExplodes].height=bubbles[i].height;
		  explodes[maxExplodes].color=bubbles[i].color;
		  explodes[maxExplodes].alfa=MAX_ALFA;
		  explodes[maxExplodes].enabled=true;
		  explodes[maxExplodes].size=1.0;
		  if ((rand() % 2)==0) explodes[maxExplodes].moveX=true; else explodes[maxExplodes].moveX=false;
		  if ((rand() % 2)==0) explodes[maxExplodes].moveY=true; else explodes[maxExplodes].moveY=false;
		  maxExplodes++;
		  
	    }	  
      }
      bubbleShiftDown();
	  
	  if (game.level<5)
	  {
	     bubbleShiftRight();
      }
	  else
	  {
	     bubbleSuperShiftRight();
	  }
   }
}

void bubbleMultiSelect(int nr)
{
   int x=nr % MAX_BOARDSIZE;
   int y=nr / MAX_BOARDSIZE;
   		
   // Set select flag for bubble	   
   bubbles[nr].selected=true;
   
   // Find all connected bubbles with the same color.
   if ((x>0) && (bubbles[nr].color==bubbles[nr-1].color) && !bubbles[nr-1].selected && bubbles[nr-1].enabled) bubbleMultiSelect(nr-1); 
   if ((x<(MAX_BOARDSIZE-1)) && (bubbles[nr].color==bubbles[nr+1].color) && !bubbles[nr+1].selected && bubbles[nr+1].enabled) bubbleMultiSelect(nr+1);
   if ((y>0) && (bubbles[nr].color==bubbles[nr-MAX_BOARDSIZE].color) && !bubbles[nr-MAX_BOARDSIZE].selected && bubbles[nr-MAX_BOARDSIZE].enabled) bubbleMultiSelect(nr-MAX_BOARDSIZE); 
   if ((y<(MAX_BOARDSIZE-1)) && (bubbles[nr].color==bubbles[nr+MAX_BOARDSIZE].color) && !bubbles[nr+MAX_BOARDSIZE].selected && bubbles[nr+MAX_BOARDSIZE].enabled) bubbleMultiSelect(nr+MAX_BOARDSIZE); 
}

int bubbleEnabledCount(void)
{
   int i;
   int count=0;
   for (i=0; i<maxBubbles; i++)
   {
      if (bubbles[i].enabled) count++;
   }
   return count;
}

int bubbleSelectedCount(void)
{
   int i;
   int count=0;
   for (i=0; i<maxBubbles; i++)
   {
      if (bubbles[i].selected) count++;
   }
   return count;
}

int bubbleSelected(int x, int y)
{
   int i,j;
   int count;
    
   for (i=0; i<maxBubbles; i++)
   {
       if ( (x>=bubbles[i].x+1) && (x<=bubbles[i].x+bubbles[i].width-1) && 
	        (y>=bubbles[i].y+1) && (y<=bubbles[i].y+bubbles[i].height-1) )
	   {	      
		  if (bubbles[i].enabled)
		  {
		     // Reset idle hint timer
             game.idleTime=time(NULL);
			 for (j=0;j<maxBubbles;j++) bubbles[j].size=MIN_BUBBLE_SIZE;
      
		     if (bubbles[i].selected) 
		     { 
			 	// Double select is remove action
   		        bubbleRemove(); 				
				bubblePossibleOption();
				bubbleHint();
				game.selectScore=0;
			 }
             else
			 {	
			    // new selection clear old selections
				for (j=0;j<maxBubbles;j++) bubbles[j].selected=false;
   
			    // Single select is select action
			    bubbleMultiSelect(i);
				count=bubbleSelectedCount();				
				game.selectScore=count*(count-1);
		     }          			  
             SND_SetVoice(SND_GetFirstUnusedVoice(), VOICE_MONO_16BIT, 22050, 0, (char *) effect3_pcm, effect3_pcm_size, effectVolume*EFFECT_MULTIPLER, effectVolume*EFFECT_MULTIPLER, NULL);
 	         return i;			 
		  }
	   }	   
   }
   return -1;
}

// -----------------------------------------------------------
// BUTTON LOGIC
// -----------------------------------------------------------

int buttonSelected(int x, int y, bool sound)
{
   int i;
   
   for (i=0; i<maxButtons; i++)
   {
       if ( (x>=buttons[i].x) && (x<=buttons[i].x+buttons[i].image.w) && 
	        (y>=buttons[i].y) && (y<=buttons[i].y+buttons[i].image.h) )
	   {
          if (sound) SND_SetVoice(SND_GetFirstUnusedVoice(), VOICE_MONO_16BIT, 22050, 0, (char *) effect3_pcm, effect3_pcm_size, effectVolume*EFFECT_MULTIPLER, effectVolume*EFFECT_MULTIPLER, NULL);
	      return i;
	   }	   
   }
   return -1;
}

void button1x(void)
{
   if (!selected1)
   {
      selected1=true;
	  
      if (selectedMusic<MAX_MUSIC_TRACK) selectedMusic++; else selectedMusic=1;   
      initMusicTrack();
   }        
}

void button2y(void)
{
   if (!selected2)
   { 
      selected2=true;   
      if (selectedMusic>1) selectedMusic--; else selectedMusic=MAX_MUSIC_TRACK;   
      initMusicTrack();
   }
}

void buttonMinus(int index)
{
   switch (index)   
   {
       case 0:
	      // Music volume
	      if (musicVolume>0) musicVolume--;   
	      MODPlay_SetVolume( &snd1, musicVolume*MUSIC_MULTIPLER,musicVolume*MUSIC_MULTIPLER);
		  break;
       
	   case 1:
          // Effect volume
          if (effectVolume>0) effectVolume--; 
		  break;
   
       case 2:
	      // Prev music track
          MODPlay_Stop(&snd1);
          if (selectedMusic>1) selectedMusic--; else selectedMusic=MAX_MUSIC_TRACK;
	      initMusicTrack();
		  break;
	
	    case 3:
		  // First Character
		  if (settings[0].value[0]==0x00) 
		  {
		     settings[0].value[0]='A';
			 strcpy(settings[0].key,"FIRST_CHAR");
		  }
		  else
		  {
		     if (settings[0].value[0]>65) settings[0].value[0]--; else settings[0].value[0]='Z';
		  }		
		  break;
		  
		case 4:
		  // Second Character
		  if (settings[1].value[0]==0x00) 
		  {
		     settings[1].value[0]='A';
			 strcpy(settings[1].key,"SECOND_CHAR");
		  }
		  else
		  {
		     if (settings[1].value[0]>65) settings[1].value[0]--; else settings[1].value[0]='Z';
		  }		
		  break;
		  
		case 5:
		  // Third Character
		  if (settings[2].value[0]==0x00) 
		  {
		     settings[2].value[0]='A';
			 strcpy(settings[2].key,"THIRD_CHAR");
		  }
		  else
		  {
		     if (settings[2].value[0]>65) settings[2].value[0]--; else settings[2].value[0]='Z';
		  }		
		  break;
   }
}

void buttonPlus(int index)
{
   switch (index)
   {
      case 0:
         // Music volume
	     if (musicVolume<MAX_SOUND_VOLUME) musicVolume++;   
	     MODPlay_SetVolume( &snd1, musicVolume*MUSIC_MULTIPLER,musicVolume*MUSIC_MULTIPLER); 
		 break;
		 
	  case 1:
         // Effect volume
         if (effectVolume<MAX_SOUND_VOLUME) effectVolume++; 
		 break;
		 
	  case 2:
	     // Next music Track
         MODPlay_Stop(&snd1);
         if (selectedMusic<MAX_MUSIC_TRACK) selectedMusic++; else selectedMusic=1;
	     initMusicTrack();
		 break;
		 
	  case 3:
		  // First Character
		  if (settings[0].value[0]==0x00) 
		  {
		     settings[0].value[0]='A';
			 strcpy(settings[0].key,"FIRST_CHAR");
		  }
		  else
		  {
		     if (settings[0].value[0]<90) settings[0].value[0]++; else settings[0].value[0]='A';
		  }		
		  break;
		  
	  case 4:
		  // Second Character
		  if (settings[1].value[0]==0x00) 
		  {
		     settings[1].value[0]='A';
			 strcpy(settings[1].key,"SECOND_CHAR");
		  }
		  else
		  {
		     if (settings[1].value[0]<90) settings[1].value[0]++; else settings[1].value[0]='A';
		  }		
		  break;
		  
	  case 5:
		  // Third Character
		  if (settings[2].value[0]==0x00) 
		  {
		     settings[2].value[0]='A';
			 strcpy(settings[2].key,"THIRD_CHAR");
		  }
		  else
		  {
		     if (settings[2].value[0]<90) settings[2].value[0]++; else settings[2].value[0]='A';
		  }		
		  break;
   }
}

void buttonScroll(int x,int y )
{ 
  switch (stateMachine)
  {
     case stateLocalHighScore:
	 case stateTodayHighScore:
	 case stateGlobalHighScore:
	 case stateReleaseNotes:
	 {     
  	    switch (buttonSelected(x,y,false))
		{
		  case 1: if ((y-40)>SCROLLBAR_Y_MIN && (y-40)<SCROLLBAR_Y_MAX) 
				  {
				     buttons[1].y=y-40;	
					 scrollIndex=(buttons[1].y-SCROLLBAR_Y_MIN)/6;
				  }
                  break;	  
        }
	 }
  }
}

void buttonA(int x, int y)
{
  if (selectedA) return;
  selectedA=true;
	  
  int i;
  for (i=0; i<MAX_POINTER; i++) pointers[i].rumble=MAX_RUMBLE;
	 
  switch (stateMachine)
  {
     case stateIntro1:
	 {
	   size=0;
	   stateMachine=stateIntro2;
	 }
	 break;

	 case stateIntro2:
	 {
	   stateMachine=stateIntro3;
	 }
	 break;
	 
	 case stateIntro3:
	 {
	   stateMachine=stateMenu;
	 }
	 break;

     case stateMenu:
     {
        switch (buttonSelected(x,y,true))
	    {
          case 0: // play button	      
           
		          // Reset score 
				  game.score=0;
				  
				  // Reset level
				  game.level=0;	
				  
				  // Init game
				  initLevel();
				  initGame(); 
				  
				  stateMachine=stateGame;
			      break;
	  
	      case 1: // High Score button 
		          scrollIndex=0;
				  stateMachine=stateLocalHighScore;
			      break;
				  
		  case 2: // Help button 
				  stateMachine=stateHelp;
			      break;
	  
	      case 3: // Credits button 		 
				  stateMachine=stateCredits;
			      break;
		  
		  case 4: // Sound button 		 
				  stateMachine=stateSound;
			      break;
				  
		  case 5: // Release Notes button 		
				  scrollIndex=0; 
				  stateMachine=stateReleaseNotes;
			      break;
				  
		  case 6: // Setting button 		 
				  stateMachine=stateSettings;
			      break;
				  
		  case 7: // Exit HBC button 
			      buttonExit(0);
			      break;	
				  
		  case 8: // Reset Wii button 
				  buttonExit(1);
			      break; 
	    }
     }
	 break;

     case stateGame:
	 {
	   bubbleSelected(x, y);
     }
	 break;

	 case stateQuit:
	 {
	    switch (buttonSelected(x,y,true))
	    {
          case 0: // Yes button	      
                  stateMachine=stateMenu;
			      break;
	  
	      case 1: // No button 
				  stateMachine=stateGame;
			      break;
	    }
	 }
	 break;
	 
	 case stateLevelCleared:
     {
	    switch (buttonSelected(x,y,true))
	    {
          case 0: // Next button	      
                  if (game.level<MAX_LEVEL)
				  {
					 initLevel(); 	
					 initGame();        
					 game.score+=game.timeBonusScore+game.bubbleOverScore+game.extraBonus+game.totalClearScore;
					 stateMachine=stateGame;
				  }
				  else
				  {
					 game.score+=game.timeBonusScore+game.bubbleOverScore+game.extraBonus+game.totalClearScore;
					 stateMachine=stateGameOver;	
				  }  	   
				  break;
		}
     }
	 break;
	 
	 case stateGameOver:
     {
	   switch (buttonSelected(x,y,true))
	   {
          case 0: // Back button	     
                  		
				  // Save score
				  saveLocalHighScoreFile(HIGHSCORE_FILENAME);
				  loadLocalHighScoreFile(HIGHSCORE_FILENAME);	
				  if (game.score>5000)
				  { 
					 sprintf(appl_user3,"appl=%s&level=%d&score=%d&name=%s&dt=%d",PROGRAM_NAME,game.level,game.score,game.name,(int)game.localTime);
					 tcp_set_state(TCP_REQUEST3a, appl_user3);	
				  }				
				  stateMachine=stateMenu;   	   
				  break;
	   }
	 }
	 break;
	 
     case stateSound:
	 {     
  	      switch (buttonSelected(x,y,true))
	      {
			 case 0: // - music volume button event	           
			         buttonMinus(0);
			         break;	   
			 
			 case 1: // + music volume button event	           
			         buttonPlus(0);
			         break;	 
					 
			 case 2: // - effect volume button event	           
			         buttonMinus(1);
			         break;	   
			 
			 case 3: // + effect volume button event	           
			         buttonPlus(1);
			         break;	 
					 
			 case 4: // - music track button event	           
			         buttonMinus(2);
			         break;	   
			 
			 case 5: // + music track  button event	           
			         buttonPlus(2);
			         break;
					 
			 case 6: // Back button event    
					 {
					   char tmp[MAX_LEN];
					   					   
					   // Setting[3] Music volume					  
					   sprintf(tmp,"%d",musicVolume);
					   strcpy(settings[3].value,tmp);
					   strcpy(settings[3].key,"MUSIC_VOLUME");
					   
					   // Setting[4] Sound Effect volume
					   sprintf(tmp,"%d",effectVolume );
					   strcpy(settings[4].value,tmp);
					   strcpy(settings[4].key,"EFFECT_VOLUME");
					   
					   // Setting[5] Loop music track
					   sprintf(tmp,"%d",loopMusicTrack );
					   strcpy(settings[5].value,tmp);
					   strcpy(settings[5].key,"LOOP_TRACK");
					   
					   // Setting[6] MP3 support
					   sprintf(tmp,"%d",enableMP3 );
					   strcpy(settings[6].value,tmp);
					   strcpy(settings[6].key,"PLAY_MP3");
					   
					   saveSettingFile(SETTING_FILENAME);  
					   stateMachine=stateMenu;  
					 }					
			         break;	   
					 
			 case 7: // Automatic next track music track button 
					 if (loopMusicTrack==0)
					 {
 				       strcpy(buttons[7].name,"Yes");
					   loopMusicTrack=1;
		
					    // Restart music track after finished
					   snd1.manual_polling=false;	  
					 } 
					 else
					 {
					   strcpy(buttons[7].name,"No");
					   loopMusicTrack=0;
					   
					   // Stop after music track finised
					   snd1.manual_polling=true;

					 }
					 break; 
					
			 case 8: // MP3 music support button 
					 if (enableMP3==0)
					 {
 				       strcpy(buttons[8].name,"Yes");
					   enableMP3=1;
					 }
					 else
					 {
					   strcpy(buttons[8].name,"No");
					   enableMP3=0;
					 }
					 break; 						 
		  }
	 }
	 break;

     case stateReleaseNotes:
	 {     
  	      switch (buttonSelected(x,y,true))
	      {		
			 case 0: // Back button event          
			         stateMachine=stateMenu;
			         break;	   
					 
		  }
	 }
	 break;
	 	 
	 case stateLocalHighScore:
     {
        switch (buttonSelected(x,y,true))
	    {
          case 0: // Next button	
				  scrollIndex=0;
				  stateMachine=stateTodayHighScore;
			      break;	     
	    }
     }
	 break;
	 
	 case stateTodayHighScore:
     {
        switch (buttonSelected(x,y,true))
	    {
          case 0: // Back button
				  scrollIndex=0;	
				  stateMachine=stateGlobalHighScore;
			      break;	     
	    }
     }
	 break;
	 
	 case stateGlobalHighScore:
     {
        switch (buttonSelected(x,y,true))
	    {
          case 0: // Back button	
				  scrollIndex=0;
				  stateMachine=stateMenu;
			      break;	     
	    }
     }
	 break;
	 	 
	 case stateHelp:
     {
        switch (buttonSelected(x,y,true))
	    {
          case 0: // Next button	
				  stateMachine=stateMenu;
			      break;	     
	    }
     }
	 break;
	 
	 case stateCredits:
     {
        switch (buttonSelected(x,y,true))
	    {
          case 0: // Next button	
				  stateMachine=stateMenu;
			      break;	     
	    }
     }
	 break;
	 
	 case stateSettings:
	 {     
  	      switch (buttonSelected(x,y,true))
	      {
			 case 0: // + First Character button event	           
			         buttonPlus(3);
			         break;	   
			 
			 case 1: // - First Character button event	           
			         buttonMinus(3);
			         break;	 
					 
			 case 2: // + Second Character button event           
			         buttonPlus(4);
			         break;	   
			 
			 case 3: // - Second Character button event         
			         buttonMinus(4);
			         break;	 
					 
			 case 4: // + Third Character button event         
			         buttonPlus(5);
			         break;	   
			 
			 case 5: // - Third Character button event           
			         buttonMinus(5);
			         break;
					 
			 case 6: // Back button event      
					 saveSettingFile(SETTING_FILENAME);    
			         stateMachine=stateMenu;
			         break;	   
					 
		  }
	 }
	 break;
  }  
}
	
void buttonExit(int index)
{    
   // Stop network thread
   tcp_stop_thread();
	
   // Stop rumble
   WPAD_Rumble(0,0);
		
   // Stop music
   MODPlay_Stop(&snd1);
	
   // Exit game
   if (index==0)
   {   
       // Exit to loader
	   exit(0);
   }
   else
   {
       // Reset Wii
	   SYS_ResetSystem(SYS_RESTART,0,0);	
   }
}
 
// -----------------------------------------------------------
// SCREEN LOGIC
// -----------------------------------------------------------

void drawButtons()
{
   int i;
   int j;
   
   boolean selected=false;
   
   for (i=0; i<maxButtons; i++)
   {	  
      selected=false;
	  
      if ((!scrollEnabled) && (strlen(buttons[i].name)==0)) continue;
	  
	  for (j=0 ;j<MAX_POINTER; j++)
	  {
        if ((pointers[j].xOffset>=buttons[i].x) && (pointers[j].xOffset<=buttons[i].x+buttons[i].image.w) && 
	        (pointers[j].yOffset>=buttons[i].y) && (pointers[j].yOffset<=buttons[i].y+buttons[i].image.h) )			
	    {
			selected=true;
			if (--pointers[j].rumble>0) WPAD_Rumble(j,1); else WPAD_Rumble(j,0);
	    }
	  }

      if (selected)
      {  
	    // Draw selected button
         GRRLIB_DrawImg(buttons[i].x, buttons[i].y, buttons[i].imageSelect, 0, 1, 1, IMAGE_COLOR );		  
	  }
	  else
	  {
		// Draw not selected button
	    GRRLIB_DrawImg(buttons[i].x, buttons[i].y, buttons[i].image, 0, 1, 1, IMAGE_COLOR );
	  }
	  drawText(buttons[i].x,buttons[i].y, fontButton, buttons[i].name);
    }
	
	// If no button selected, stop rumble on all pointers
	if (!selected) 
	{
	   for (j=0; j<MAX_POINTER; j++) 
	   {
	      WPAD_Rumble(j,0);
	      pointers[j].rumble=MAX_RUMBLE;
	   }
	}
}

GRRLIB_texImg imageBubble(boolean selected, int color)
{
    if (selected)
    {  
	  // Show selected bubble
      switch (color)
      {
        case 0: return images.blueSelectBubble;
  	 		    break;
			  
	    case 1: return images.yellowSelectBubble;
	 		    break;
			  
	    case 2: return images.greenSelectBubble;
	 		    break;
			  
	    case 3: return images.redSelectBubble;
	 		    break;
 			  
        case 4: return images.pinkSelectBubble;
	 	  	    break;

	    case 5: return images.lightblueSelectBubble;
	 		    break;

	    case 6: return images.blackSelectBubble;
	 		    break;
				
		case 7: return images.whiteSelectBubble;
	 		    break;
			  
	    default:return images.noBubble;
	 		    break;
      }
    }
    else
    {
	   // Show not selected bubble
       switch (color)
       {
        case 0: return images.blueBubble;
	 		    break;
			  
	    case 1: return images.yellowBubble;
	 		    break;
			  
	    case 2: return images.greenBubble;
	 		    break;

	    case 3: return images.redBubble;
	 		    break;
			  
	    case 4: return images.pinkBubble;
	 		    break;
			  
	    case 5: return images.lightblueBubble;
	 		    break;
			  			  
	    case 6: return images.blackBubble;
	 		    break;
				
		case 7: return images.whiteBubble;
	 		    break;
			  
	    default:return images.noBubble;
	 		    break;
	  }
    }
}

void drawGameboard(void)
{
   /*int i;   
   for (i=0; i<maxGameboard; i++)
   {
       GRRLIB_DrawImg(gameboard[i].x, gameboard[i].y, gameboard[i].image, 0, 1, 1, IMAGE_COLOR );
   }*/
   
   
   // Better fps performance when gameboard is one image instead of 196 small images.
   int xoffset=172;
   int yoffset=20;	
   
   GRRLIB_DrawImg(xoffset, yoffset, images.gameboard, 0, 1, 1, IMAGE_COLOR );
}

void drawBubbles(void)
{
   int i;   
   for (i=0; i<maxBubbles; i++)
   {
      if (bubbles[i].enabled)
	  {
         GRRLIB_DrawImg(bubbles[i].x, bubbles[i].y, imageBubble(bubbles[i].selected,bubbles[i].color), 0, bubbles[i].size, bubbles[i].size, IMAGE_COLOR);

		 // bubble with hint option enable will change size value
		 if (((time(NULL)-game.idleTime)>MAX_IDLE_TIME) && bubbles[i].hint && ((stateMachine==stateGame) || stateMachine==stateQuit))
		 {
		    game.selectScore=0;
		    bubbles[i].selected=false;
		    if (bubbles[i].sizeDirection)
			{
			   if (bubbles[i].size<MAX_BUBBLE_SIZE) bubbles[i].size+=0.05; else bubbles[i].sizeDirection=false;
			}
			else
			{
			   if (bubbles[i].size>MIN_BUBBLE_SIZE) bubbles[i].size-=0.05; else bubbles[i].sizeDirection=true;
			}  
         }		    
	  }
   }
}

void drawExplodes(void)
{
   int i;   
   
   for (i=0; i<MAX_BUBBLES; i++)
   {
      if (explodes[i].enabled)
	  {
         GRRLIB_DrawImg(explodes[i].x, explodes[i].y, 
		   imageBubble(false,explodes[i].color), 0, 
		   explodes[i].size, explodes[i].size , 0xFFFFFF00 | explodes[i].alfa );
	  }
   }
}

void drawText(int x, int y, int type, char *text)
{
   char tmp[MAX_LEN];
   memset(tmp,0x00,sizeof(tmp));
   
   if (text!=NULL)
   {    		
     strcpy(tmp, text);
	 
     switch (type)
     {	   	   	 
       case fontTitle: 
	   {
	      if (x==0) x=320-((strlen(tmp)*34)/2);  
		  GRRLIB_Printf2(x, y, tmp, 72, COLOR_WHITESMOKE); 
	   }
	   break;
  
       case fontWelcome: 
	   {
		  GRRLIB_Printf2(x, y, tmp, 40, COLOR_WHITESMOKE); 
	   }
	   break;
	   
	   case fontSubTitle:
	   {
	      if (x==0) x=320-((strlen(tmp)*20)/2);
		  GRRLIB_Printf2(x, y, tmp, 30, COLOR_WHITESMOKE);          
	   }
	   break;
	   
	   case fontSubTitle2:
	   {
	      if (x==0) x=320-((strlen(tmp)*20)/2);
		  GRRLIB_Printf2(x, y, tmp, 30, COLOR_LIGHTRED);          
	   }
	   break;
	   	   
	   case fontParagraph:
	   {
	       if (x==0) x=320-((strlen(tmp)*10)/2);	   
		   GRRLIB_Printf2(x, y, tmp, 24, COLOR_WHITESMOKE);            
	   }
	   break;
	   	   
	   case fontNormal:
	   {
	       if (x==0) x=320-((strlen(tmp)*7)/2);
		   GRRLIB_Printf2(x, y, tmp, 18, COLOR_WHITESMOKE);            
	   }
	   break;
	         
	   case fontNew:
	   {
	       if (x==0) x=320-((strlen(tmp)*8)/2);	   
		   GRRLIB_Printf2(x, y, tmp, 22, COLOR_WHITESMOKE);            
	   }
	   break;
	   
	   case fontSpecial:
	   {
	       if (x==0) x=320-((strlen(tmp)*10)/2);
		   GRRLIB_Printf2(x, y, tmp, 10, COLOR_WHITESMOKE);            
	   }
	   break;
	   
	   case fontButton:
	   {
	       if (strlen(tmp)==1)
		   {
		      GRRLIB_Printf2(x+35, y, tmp, 24, COLOR_WHITESMOKE);            
		   }
		   else
		   {
		      GRRLIB_Printf2(x+20, y, tmp, 24, COLOR_WHITESMOKE);    
		   }		   
	   }
	   break;
	 }
   }
}

void drawInfoBar(void)
{
   char tmp[MAX_LEN];
   struct tm *dt;
		
   // Draw panels
   GRRLIB_DrawImg(10,0, images.panel1, 0, 1.0, 1.0, IMAGE_COLOR );
   GRRLIB_DrawImg(10,120, images.panel1, 0, 1.0, 1.0, IMAGE_COLOR );
   GRRLIB_DrawImg(10,240, images.panel1, 0, 1.0, 1.0, IMAGE_COLOR );
   GRRLIB_DrawImg(10,360, images.panel1, 0, 1.0, 1.0, IMAGE_COLOR );  
  
   // Init text layer	  
   GRRLIB_initTexture();
		  
   drawText(55, 20, fontSubTitle, "Score");
   sprintf(tmp,"%05d", game.score);
   drawText(50, 50, fontSubTitle, tmp);
		  
   time_t timeLevel=game.maxTime-game.playTime;
   dt = localtime(&timeLevel);		  
   sprintf(tmp,"%02d:%02d", dt->tm_min, dt->tm_sec);
   if (timeLevel<=OUT_OF_TIME)
   {
	  drawText(55, 140, fontSubTitle2, "Time");
	  drawText(50, 170, fontSubTitle2, tmp);
   }
   else
   {
	  drawText(55, 140, fontSubTitle, "Time");  
	  drawText(50, 170, fontSubTitle, tmp);
   }
		   
   drawText(50, 265, fontSubTitle, "Level");
   sprintf(tmp,"%d", game.level);
   drawText(80, 295, fontSubTitle, tmp);
		  
   drawText(50, 385, fontSubTitle, "Moves");
   sprintf(tmp," %02d", game.possiblities);
   drawText(70, 415, fontSubTitle, tmp);   
}
		  		  
void drawScreen(void)
{ 	   
    int i=0;
	char tmp[MAX_LEN];
				  
    switch( stateMachine )	
	{	

	   case stateIntro1:
	   {
	      int  ypos=yOffset;
		  
	      // Draw background
		  GRRLIB_DrawImg(0,0, images.background1, 0, 1, 1, IMAGE_COLOR );
		  
		  // Draw background
		  GRRLIB_DrawImg(((640-images.logo1.w)/2) , ((480-images.logo1.h)/2)-20, images.logo1, 0, size, size, IMAGE_COLOR );
		  
		  // Init text layer	  
          GRRLIB_initTexture();	
		  
		  drawText(0, ypos, fontParagraph,  "Created by wplaat"  );
		  ypos+=20;
		  drawText(0, ypos, fontParagraph,  "http://www.plaatsoft.nl"  );
		  ypos+=340;
		  drawText(40, ypos, fontNormal,  "This software is open source and may be copied, distributed or modified"  );
		  ypos+=20;
		  drawText(60, ypos, fontNormal,  "under the terms of the GNU General Public License (GPL) version 2" );
		  
		  sprintf(tmp,"%d fps", CalculateFrameRate());
		  drawText(20, 460, fontSpecial, tmp);
		  
		  // Draw text layer on top of background 
          GRRLIB_DrawImg2(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 255);
	   }	   
	   break;
	   
	   case stateIntro2:
	   {
	      int  ypos=yOffset+320;
		  int  j;
		  
	      // Draw background
		  GRRLIB_DrawImg(0,0, images.background2, 0, 1, 1, IMAGE_COLOR );

		  // Draw Plaatsoft logo		 
   	      for(j=0;j<images.logo.h;j++)
		  {
             GRRLIB_DrawTile(((640-images.logo2.w)/2)+sin(wave1)*50, (((480-images.logo2.h)/2)-50)+j, images.logo, 0, 1, 1, IMAGE_COLOR,j );
             wave1+=0.02;
          }
		  wave2+=0.02;
          wave1=wave2;
		  
		  // Init text layer	  
          GRRLIB_initTexture();	
		  
		  drawText(0, ypos, fontParagraph,  "Please visit my website for more information."  );
		  ypos+=40;
		  drawText(0, ypos, fontParagraph,  "http://www.plaatsoft.nl"  );
			  
		  sprintf(tmp,"%d fps", CalculateFrameRate());
		  drawText(20, 460, fontSpecial, tmp);
		  
		  // Draw text layer on top of background 
          GRRLIB_DrawImg2(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 255);
	   }	   
	   break;
	   	   
	   case stateIntro3:
	   {
	      int  ypos=yOffset+390;

		  // Draw background
		  GRRLIB_DrawImg(0,0, images.logo3, 0, 0.95, 0.98, IMAGE_COLOR );
		  GRRLIB_DrawImg(310,0, images.logo4, 0, 0.95, 0.98, IMAGE_COLOR );
		  GRRLIB_DrawImg(0,240, images.logo5, 0, 0.95, 0.98, IMAGE_COLOR );
		  GRRLIB_DrawImg(310,240, images.logo6, 0, 0.95, 0.98, IMAGE_COLOR );
		  
          GRRLIB_DrawImg(350, 240, images.logo2, 0, 0.5, 0.5, IMAGE_COLOR );

		  // Init text layer	  
          GRRLIB_initTexture();	
		  
		  drawText(350, ypos, fontNormal,  "Some more Wii games developed"  );
		  ypos+=20;
		  drawText(400, ypos, fontNormal,  "by www.plaatsoft.nl"  );
			 
		  sprintf(tmp,"%d fps", CalculateFrameRate()); 
		  drawText(580, 460, fontSpecial, tmp); 
 
		  // Draw text layer on top of background 
          GRRLIB_DrawImg2(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 255);
	   }	   
	   break;

	   case stateMenu:
	   {
	      int  ypos=yOffset;
		  char *version;
		  
   	      // Init text layer	  
          GRRLIB_initTexture();
		   
		  //debug stuff
		  //if (snd1.manual_polling)  drawText(10, 200, fontNormal, "snd1.manual_polling=true");
		  //if (snd1.paused)  drawText(10, 220, fontNormal, "snd1.paused=true");
		  //if (snd1.playing)  drawText(10, 240, fontNormal, "snd1.playing=true");

	      /// Draw background
		  GRRLIB_DrawImg(0,0, images.background1, 0, 1, 1, IMAGE_COLOR );
		  		  
		  sprintf(tmp,"%s v%s",PROGRAM_NAME, PROGRAM_VERSION );
		  drawText(20, ypos, fontWelcome, tmp);
          ypos+=50;
          
     	  sprintf(tmp,"%s",RELEASE_DATE );
		  drawText(20, ypos, fontParagraph, tmp);
		  ypos+=230;
		   
          version=tcp_get_version();
          if ( (version!=NULL) && (strlen(version)>0) && (strcmp(version,PROGRAM_VERSION)!=0) )
          {    
	         sprintf(tmp,"New version [v%s] is available.",version);
	         drawText(20, ypos, fontNew, tmp);
			 
			 ypos+=20;			 			 			 
			 sprintf(tmp,"Check the release notes.");
	         drawText(20, ypos, fontNew, tmp);			 
          }  

          sprintf(tmp,"NETWORK THREAD: %s",tcp_get_state());
		  drawText(20, 440, fontSpecial, tmp);
 
		  sprintf(tmp,"%d fps", CalculateFrameRate());
		  drawText(20, 460, fontSpecial, tmp);
		  
		  // Draw buttons
	      drawButtons(); 
		  
		  // Draw text layer on top of gameboard 
          GRRLIB_DrawImg2(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 255);	
	   }
	   break;
	   
	   case stateGame:
       {   		  		   
	      // Draw background
		  GRRLIB_DrawImg(0,0, images.background1, 0, 1.0, 1.0, IMAGE_COLOR );
      	
		  // Draw gameboard		  
		  drawGameboard();

		  // Explode bubble effect
		  bubbleExplodeMove();
		  
		  // Draw explode
		  drawExplodes();
		  
		  // Draw bubbles
		  drawBubbles();
		  		  		  	  
		  // Draw Game Info bar
          drawInfoBar();
		  		 
		  // Draw buttons
	      drawButtons(); 
		  
		  // Show selected bubble score ir1
		  for (i=0; i<MAX_POINTER; i++)
		  {
		    if ((game.selectScore>1) && (pointers[i].xOffset>10) && (pointers[i].xOffset<MAX_HORZ_PIXELS-10) && (pointers[i].yOffset>10) && (pointers[i].yOffset<MAX_VERT_PIXELS-10))
		    {
  		       sprintf(tmp,"[%d]", game.selectScore);
		       drawText(pointers[i].xOffset-20, pointers[i].yOffset-20, fontNormal, tmp);
		    }	
		  }

		  sprintf(tmp,"%d fps", CalculateFrameRate());
		  drawText(80, 460, fontSpecial, tmp);
			
		  // Draw text layer on top of gameboard 
          GRRLIB_DrawImg2(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 255);	
	   }
	   break;
	   	   
	   case stateLevelCleared:
	   {
	      int ypos=yOffset;		   
				  	         	
	      // Draw background
		  GRRLIB_DrawImg(0,0, images.background1, 0, 1.0, 1.0, IMAGE_COLOR );
      		
  		   // Draw gameboard		  
		  drawGameboard();

		  // Explode bubble effect
		  bubbleExplodeMove();
		  
		  // Draw explode
		  drawExplodes();
		  
		  // Draw bubbles
		  drawBubbles();
		 
		  // Draw Game Info bar
          drawInfoBar();
  
          // Draw Popup window
          GRRLIB_DrawImg(320, 190, images.panel1, 0, 2.5, 3.1, IMAGE_COLOR );
	 
		  // Draw Bonus information
		  ypos+=70;		   
		  drawText(305, ypos, fontSubTitle, "LEVEL CLEARED");
		  ypos+=30;		   
		  drawText(330, ypos, fontSubTitle, "WELL DONE!");
		  
		  ypos+=50;	
		  drawText(230, ypos, fontParagraph, "Time Bonus");
		  sprintf(tmp,"%d * %d = ",game.timeBonus,game.timeBonusFactor);
		  drawText(370, ypos, fontParagraph, tmp);		  
		  sprintf(tmp,"%d",game.timeBonusScore);
		  drawText(505, ypos, fontParagraph, tmp);
		  
		  ypos+=35;	
		  drawText(230, ypos, fontParagraph, "Bubbles Over");
		  sprintf(tmp,"%d * %d = ",game.bubbleOver,game.bubbleOverFactor);
		  drawText(370, ypos, fontParagraph, tmp);	
		  sprintf(tmp,"%d",game.bubbleOverScore);
		  drawText(505, ypos, fontParagraph, tmp);
		  
		  ypos+=35;	
		  drawText(230, ypos, fontParagraph, "Total Clear");
		  sprintf(tmp,"%d * %d = ",game.totalClear,game.totalClearFactor);
		  drawText(370, ypos, fontParagraph, tmp);	
		  sprintf(tmp,"%d",game.totalClearScore);
		  drawText(505, ypos, fontParagraph, tmp);
		  
		  ypos+=35;	
		  drawText(230, ypos, fontParagraph, "Extra Bonus");
		  sprintf(tmp,"%d",game.extraBonus);
		  drawText(505, ypos, fontParagraph, tmp);
		   
		  ypos+=20;	
		  drawText(505, ypos, fontParagraph, "____ +");
		  
		  ypos+=35;	
		  drawText(230, ypos, fontParagraph, "Total Bonus");
		  sprintf(tmp,"%d",game.timeBonusScore+game.bubbleOverScore+game.extraBonus+game.totalClearScore);
		  drawText(505, ypos, fontParagraph, tmp);
		    		 	  
		  // Draw buttons
	      drawButtons(); 

		  sprintf(tmp,"%d fps", CalculateFrameRate());
		  drawText(80, 460, fontSpecial, tmp);
		   		  
          // Draw text layer on top of gameboard 
          GRRLIB_DrawImg2(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 255);	
	   }
	   break;
	   
	   case stateGameOver:
	   {
	      int ypos=yOffset+170;		   
				  	         	
		  // Draw background
		  GRRLIB_DrawImg(0,0, images.background1, 0, 1.0, 1.0, IMAGE_COLOR );
      		
		  // Draw gameboard		  
		  drawGameboard();

		  // Explode bubble effect
		  bubbleExplodeMove();
		  
		  // Draw explode
		  drawExplodes();
		  
		  // Draw bubbles
		  drawBubbles();
		  
		  // Draw Game Info bar
          drawInfoBar();

          // Draw Popup window
          GRRLIB_DrawImg(315,185, images.panel1, 0, 1.5, 1.5, IMAGE_COLOR );
		  		  		  
		  // Draw text 
		  if (gameResult)
		  {	   
		     drawText(330, ypos, fontSubTitle, "YOU WIN!");
		  }
		  else
		  {
		     drawText(320, ypos, fontSubTitle, "GAME OVER"); 
		  }
		 	  
		   // Draw buttons
	      drawButtons(); 
		  				   		  
		  sprintf(tmp,"%d fps", CalculateFrameRate());
		  drawText(80, 460, fontSpecial, tmp);
		  
          // Draw text layer on top of gameboard 
          GRRLIB_DrawImg2(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 255);	
	   }
	   break;

	   case stateQuit:
	   {
	      int ypos=yOffset+170;		   
				  	         	
		  // Draw background
		  GRRLIB_DrawImg(0,0,images.background1, 0, 1.0, 1.0, IMAGE_COLOR );
      		
		  // Draw gameboard		  
		  drawGameboard();

		  // Explode bubble effect
		  bubbleExplodeMove();
		  
		  // Draw explode
		  drawExplodes();
		  
		  // Draw bubbles
		  drawBubbles();
    				  
		  // Draw Game Info bar
          drawInfoBar();

          // Draw Popup window
          GRRLIB_DrawImg(315,185, images.panel1, 0, 1.5, 1.5, IMAGE_COLOR );
		  		  
		  // Draw text
		  drawText(315, ypos, fontSubTitle, "QUIT GAME?");
		 	  
		   // Draw buttons
	      drawButtons(); 
		  				   		
		  sprintf(tmp,"%d fps", CalculateFrameRate());
		  drawText(80, 460, fontSpecial, tmp);
		  
          // Draw text layer on top of gameboard 
          GRRLIB_DrawImg2(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 255);	
	   }
	   break;
	   	   
	   case stateLocalHighScore:
	   {
	      int  ypos=yOffset;
	      struct tm *local;
		  int startEntry;
		  int endEntry;
		  		  
		  if (maxLocalHighScore<13)
		  {
		    startEntry=0;
			endEntry=maxLocalHighScore;
			scrollEnabled=false;
		  }
		  else
		  {
			 startEntry=(((float) maxLocalHighScore-13.0)/26.0)*(float)scrollIndex;
			 endEntry=startEntry+13;
			 scrollEnabled=true;
		  }
		  
		  // Init text layer	  
          GRRLIB_initTexture();
		  				   
          // Draw background
          GRRLIB_DrawImg(0,0, images.background1, 0, 1, 1, IMAGE_COLOR );
      	     	
		  // Draw scrollbar
		  if (scrollEnabled)
		  {
		    ypos=SCROLLBAR_Y_MIN;
            GRRLIB_DrawImg(SCROLLBAR_x,ypos, images.scrollTop, 0, 1, 1, IMAGE_COLOR );
		    for (i=0; i<9; i++) 
		    {
		      ypos+=24;
		      GRRLIB_DrawImg(SCROLLBAR_x,ypos, images.scrollMiddle, 0, 1, 1, IMAGE_COLOR );
		    }
		    ypos+=24;
		    GRRLIB_DrawImg(SCROLLBAR_x,ypos, images.scrollBottom, 0, 1, 1, IMAGE_COLOR );
		  }
		 
	      // Draw title
		  ypos=yOffset;
	      drawText(0, ypos, fontTitle, "      Local High Score");	

          // Show Content
          ypos+=90;
		  drawText(60, ypos, fontParagraph, "TOP"  );
	      drawText(130, ypos, fontParagraph, "DATE"  );
	      drawText(320, ypos, fontParagraph, "SCORE" );
		  drawText(410, ypos, fontParagraph, "NAME"  );
		  drawText(500, ypos, fontParagraph, "LEVEL" );
		  ypos+=10;
		  
          for (i=startEntry; i<endEntry; i++)
	      {
  	          ypos+=20;  
	    
		      sprintf(tmp,"%02d", i+1);
		      drawText(60, ypos, fontNormal, tmp);
			  
	          local = localtime(&localHighScore[i].localTime);
	          sprintf(tmp,"%02d-%02d-%04d %02d:%02d:%02d", 
			     local->tm_mday, local->tm_mon+1, local->tm_year+1900, 
			     local->tm_hour, local->tm_min, local->tm_sec);
		      drawText(130, ypos, fontNormal, tmp);
	   
	   	      sprintf(tmp,"%05d", localHighScore[i].score);
		      drawText(320, ypos, fontNormal, tmp);
	
		      drawText(410, ypos, fontNormal, localHighScore[i].name);
	  
	          sprintf(tmp,"%02d", localHighScore[i].level);
		      drawText(500, ypos, fontNormal, tmp);
		  }	 
		
          // Draw buttons
	      drawButtons(); 

		  sprintf(tmp,"%d fps", CalculateFrameRate());
		  drawText(20, 460, fontSpecial, tmp);
		  
          // Draw text layer on top of gameboard 
          GRRLIB_DrawImg2(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 255);	 	   
	   }
	   break;
	   
	   case stateTodayHighScore:
	   {	      
		  int  ypos=yOffset;
	      struct tm *local;
		  int startEntry;
		  int endEntry;
		  		  
		  if (maxTodayHighScore<13)
		  {
		    startEntry=0;
			endEntry=maxTodayHighScore;
			scrollEnabled=false;
		  }
		  else
		  {
			 startEntry=(((float) maxTodayHighScore-13.0)/26.0)*(float)scrollIndex;
			 endEntry=startEntry+13;
			 scrollEnabled=true;
		  }
		  
          // Init text layer	  
          GRRLIB_initTexture();
		   
          // Draw background
          GRRLIB_DrawImg(0,0, images.background1, 0, 1, 1, IMAGE_COLOR );
      	     	
		  // Draw scrollbar
		  if (scrollEnabled)
		  {
		    ypos=SCROLLBAR_Y_MIN;
            GRRLIB_DrawImg(SCROLLBAR_x,ypos, images.scrollTop, 0, 1, 1, IMAGE_COLOR );
		    for (i=0; i<9; i++) 
		    {
		      ypos+=24;
		      GRRLIB_DrawImg(SCROLLBAR_x,ypos, images.scrollMiddle, 0, 1, 1, IMAGE_COLOR );
		    }
		    ypos+=24;
		    GRRLIB_DrawImg(SCROLLBAR_x,ypos, images.scrollBottom, 0, 1, 1, IMAGE_COLOR );
		  }
		  
	      // Draw title
		  ypos=yOffset;
	      drawText(0, ypos, fontTitle, "   Today High Score");	

          // Show Content
          ypos+=90;

		  drawText(20, ypos, fontParagraph,  "TOP"  );
	      drawText(80, ypos, fontParagraph, "DATE" );
	      drawText(270, ypos, fontParagraph, "SCORE" );
		  drawText(350, ypos, fontParagraph, "NAME"  );
		  drawText(430, ypos, fontParagraph, "LOCATION" );
		  ypos+=10;
		  
		  if (todayHighScore[0].dt!=0)
		  {
            for (i=startEntry; i<endEntry; i++)
            {
  	          ypos+=20;  
	    
		      sprintf(tmp,"%02d", i+1);
		      drawText(20, ypos, fontNormal, tmp);
			  			  
	          local = localtime(&todayHighScore[i].dt);
	          sprintf(tmp,"%02d-%02d-%04d %02d:%02d:%02d", 
			     local->tm_mday, local->tm_mon+1, local->tm_year+1900, 
			     local->tm_hour, local->tm_min, local->tm_sec);
		      drawText(80, ypos, fontNormal, tmp);
	   
		      drawText(270, ypos, fontNormal, todayHighScore[i].score);			  
			  drawText(350, ypos, fontNormal, todayHighScore[i].name);			  
			  drawText(430, ypos, fontNormal, todayHighScore[i].location);
		    }			
		  }
		  else
		  {
		      ypos+=120;
		      drawText(0, ypos, fontParagraph, "No information available!");
			  ypos+=20;
			  drawText(0, ypos, fontParagraph, "Information could not be fetch from internet.");
		  }
			 
          // Draw buttons
	      drawButtons(); 
		  
		  sprintf(tmp,"%d fps", CalculateFrameRate());
		  drawText(20, 460, fontSpecial, tmp);
		  
          // Draw text layer on top of gameboard 
          GRRLIB_DrawImg2(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 255);	 	   
	   }
	   break;
	   
	   case stateGlobalHighScore:
	   {	      
		  int  ypos=yOffset;
	      struct tm *local;
		  int startEntry;
		  int endEntry;
		  		  
		  if (maxGlobalHighScore<13)
		  {
		    startEntry=0;
			endEntry=maxGlobalHighScore;
			scrollEnabled=false;
		  }
		  else
		  {
			 startEntry=(((float) maxGlobalHighScore-13.0)/26.0)*(float)scrollIndex;
			 endEntry=startEntry+13;
			 scrollEnabled=true;
		  }
		  
          // Init text layer	  
          GRRLIB_initTexture();
		   
          // Draw background
          GRRLIB_DrawImg(0,0, images.background1, 0, 1, 1, IMAGE_COLOR );
      	     	
		  // Draw scrollbar
		  if (scrollEnabled)
		  {
		    ypos=SCROLLBAR_Y_MIN;
            GRRLIB_DrawImg(SCROLLBAR_x,ypos, images.scrollTop, 0, 1, 1, IMAGE_COLOR );
		    for (i=0; i<9; i++) 
		    {
		      ypos+=24;
		      GRRLIB_DrawImg(SCROLLBAR_x,ypos, images.scrollMiddle, 0, 1, 1, IMAGE_COLOR );
		    }
		    ypos+=24;
		    GRRLIB_DrawImg(SCROLLBAR_x,ypos, images.scrollBottom, 0, 1, 1, IMAGE_COLOR );
		  }
		  
	      // Draw title
		  ypos=yOffset;
	      drawText(0, ypos, fontTitle, "   Global High Score");	

          // Show Content
          ypos+=90;

		  drawText(20, ypos, fontParagraph,  "TOP"  );
	      drawText(80, ypos, fontParagraph, "DATE" );
	      drawText(270, ypos, fontParagraph, "SCORE" );
		  drawText(350, ypos, fontParagraph, "NAME"  );
		  drawText(430, ypos, fontParagraph, "LOCATION" );
		  ypos+=10;
		  
		  if (globalHighScore[0].dt!=0)
		  {
            for (i=startEntry; i<endEntry; i++)
            {
  	          ypos+=20;  
	    
		      sprintf(tmp,"%02d", i+1);
		      drawText(20, ypos, fontNormal, tmp);
			  			  
	          local = localtime(&globalHighScore[i].dt);
	          sprintf(tmp,"%02d-%02d-%04d %02d:%02d:%02d", 
			     local->tm_mday, local->tm_mon+1, local->tm_year+1900, 
			     local->tm_hour, local->tm_min, local->tm_sec);
		      drawText(80, ypos, fontNormal, tmp);
	   
		      drawText(270, ypos, fontNormal, globalHighScore[i].score);			  
			  drawText(350, ypos, fontNormal, globalHighScore[i].name);			  
			  drawText(430, ypos, fontNormal, globalHighScore[i].location);
		    }			
		  }
		  else
		  {
		      ypos+=120;
		      drawText(0, ypos, fontParagraph, "No information available!");
			  ypos+=20;
			  drawText(0, ypos, fontParagraph, "Information could not be fetch from internet.");
		  }
			 
          // Draw buttons
	      drawButtons(); 
		  
		  sprintf(tmp,"%d fps", CalculateFrameRate());
		  drawText(20, 460, fontSpecial, tmp);
		  
          // Draw text layer on top of gameboard 
          GRRLIB_DrawImg2(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 255);	 	   
	   }
	   break;
	   	   
	   case stateHelp:
	   {
	      int  ypos=yOffset;
		  
		  // Init text layer	  
          GRRLIB_initTexture();
		  
	      // Draw background
		  GRRLIB_DrawImg(0,0, images.background1, 0, 1, 1, IMAGE_COLOR );
		  
		   // Show title
		  drawText(0, ypos, fontTitle, "Help");
          ypos+=100;
		  
		  drawText(0, ypos, fontParagraph, "SpaceBubble is a classic board puzzle game based");
		  ypos+=25;
     	  drawText(0, ypos, fontParagraph, "on bubble breaker. Select multiple bubbles");	
		  ypos+=25;
	      drawText(0, ypos, fontParagraph, "with the same color and destroy them, the more");
		  ypos+=25;
	      drawText(0, ypos, fontParagraph, "you hit in one the higher score you will get.");		
		
          ypos+=60;
	      drawText(0, ypos, fontParagraph, "Tip: You can control which music track is played during");
		  ypos+=25;
	      drawText(0, ypos, fontParagraph, "the game with the 1 and 2 button on your WiiMote!");
		  
		  ypos+=60;
	      drawText(0, ypos, fontParagraph, "Note: The global highscore contains the Top 40 of best");
		  ypos+=25;
	      drawText(0, ypos, fontParagraph, "internet players. Only one entry per player is showed.");
				  
		  // Draw buttons
	      drawButtons(); 
		  
		  sprintf(tmp,"%d fps", CalculateFrameRate());
		  drawText(20, 460, fontSpecial, tmp);
		  
		  // Draw text layer on top of gameboard 
          GRRLIB_DrawImg2(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 255);
	   }
	   break;
	   
	   case stateCredits:
	   {
	      int  ypos=yOffset;
 
          // Init text layer	  
          GRRLIB_initTexture();
 
	      // Draw background
		  GRRLIB_DrawImg(0,0, images.background1, 0, 1, 1, IMAGE_COLOR );
		  
		  // Show title
		  drawText(0, ypos, fontTitle, "      Credits");
          ypos+=90;
		  
		  // Show Content
	      drawText(0, ypos, fontParagraph, "GAME LOGIC ");
          ypos+=20;
	      drawText(0, ypos, fontNormal, "wplaat");

	      ypos+=30;
	      drawText(0, ypos, fontParagraph, "GAME GRAPHICS  ");
  	      ypos+=20;
	      drawText(0, ypos, fontNormal, "wplaat");
	
	      ypos+=30;
	      drawText(0, ypos, fontParagraph, "MUSIC ");
	      ypos+=20;
	      drawText(0, ypos, fontNormal, "modarchive.org  ");

	      ypos+=30;
	      drawText(0, ypos, fontParagraph, "SOUND EFFECTS  ");
	      ypos+=20;
	      drawText(0, ypos, fontNormal, "wplaat");
  
  	      ypos+=30;
	      drawText(0, ypos, fontParagraph, "TESTERS");
	      ypos+=20;
	      drawText(0, ypos, fontNormal, "wplaat");	  
		  ypos+=20;
	      drawText(0, ypos, fontNormal, "Jan (thanks for your briljant ideas)");  		  	  	
												
	      ypos+=30;
	      drawText(0, ypos, fontNormal,"Greetings to everybody in the Wii homebrew scene");

		  // Draw buttons
	      drawButtons(); 

		  sprintf(tmp,"%d fps", CalculateFrameRate());
		  drawText(20, 460, fontSpecial, tmp);
		  
		  // Draw text layer on top of gameboard 
          GRRLIB_DrawImg2(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 255);
	   }
	   break;
	   
	   case stateSound:
	   {
	      int  ypos=yOffset;
	
	      // Init text layer	  
          GRRLIB_initTexture();
 
	      // Draw background
		  GRRLIB_DrawImg(0,0, images.background1, 0, 1, 1, IMAGE_COLOR );
		  
	      // Draw Sound icon
	      GRRLIB_DrawImg((640/2)-128, ((480/2)-140)+yOffset, images.sound, angle, 1.4, 1.4, IMAGE_COLOR );
	
		  // Show title
		  drawText(0, ypos, fontTitle, "   Sound Settings");
          ypos+=100;
		  
          // Draw content	
          drawText(0, ypos, fontParagraph, "Music Volume");	
	      ypos+=20;
          GRRLIB_DrawImg(104,ypos,images.bar, 0, 1, 1, IMAGE_COLOR );
	      ypos+=10;
	      GRRLIB_DrawImg(115+(musicVolume*40),ypos, images.barCursor, 0, 1, 1, IMAGE_COLOR );
  
          ypos+=80;
          drawText(0, ypos, fontParagraph, "Effects Volume" );
	      ypos+=20;	
	      GRRLIB_DrawImg(104,ypos, images.bar, 0, 1, 1, IMAGE_COLOR );
	      ypos+=10;
	      GRRLIB_DrawImg(115+(effectVolume*40),ypos,images.barCursor, 0, 1, 1, IMAGE_COLOR );
	
	      ypos+=70;
		  sprintf(tmp,"  Music track [%d]", selectedMusic);
	      drawText(0, ypos, fontParagraph, tmp);	
		  
		  drawText(60, 395, fontNormal,  "Loop track");	
		  drawText(505, 395, fontNormal, "Play MP3");	
		  		
		   // Draw buttons
	      drawButtons(); 
		  
		  sprintf(tmp,"%d fps", CalculateFrameRate());
		  drawText(20, 460, fontSpecial, tmp);
		  
		  // Draw text layer on top of gameboard 
          GRRLIB_DrawImg2(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 255);
	   }
	   break;
	   
	   case stateReleaseNotes:
	   {
	      int  ypos;
	      int  i=0;
		  int len=0;
		  int  lineCount=0;
		  int maxLines=0;
		  char *buffer;
		  char text[MAX_BUFFER_SIZE];
		  
		  int startEntry;
		  int endEntry;
		  		  
		  // Fetch release notes from network thread
		  buffer=tcp_get_releasenote();
          if (buffer!=NULL) 
		  {
		     strncpy(text,buffer,MAX_BUFFER_SIZE);
			 len=strlen(text);
			 for (i=0;i<len;i++) if (text[i]=='\n') maxLines++;
		  }
		  
		  // Calculate start and end line.
		  if (maxLines<18)
		  {
		    startEntry=0;
			endEntry=maxLines;
			scrollEnabled=false;
		  }
		  else
		  {
			 startEntry=(((float) maxLines-18.0)/26.0)*(float)scrollIndex;
			 endEntry=startEntry+18;
			 scrollEnabled=true;
		  }
		  
	      // Init text layer	  
          GRRLIB_initTexture();
 
	      // Draw background
		  GRRLIB_DrawImg(0,0,images.background1, 0, 1, 1, IMAGE_COLOR );

          // Draw scrollbar
		  if (scrollEnabled)
		  {
		    ypos=SCROLLBAR_Y_MIN;
            GRRLIB_DrawImg(SCROLLBAR_x,ypos, images.scrollTop, 0, 1, 1, IMAGE_COLOR );
		    for (i=0; i<9; i++) 
		    {
		      ypos+=24;
		      GRRLIB_DrawImg(SCROLLBAR_x,ypos, images.scrollMiddle, 0, 1, 1, IMAGE_COLOR );
		    }
		    ypos+=24;
		    GRRLIB_DrawImg(SCROLLBAR_x,ypos, images.scrollBottom, 0, 1, 1, IMAGE_COLOR );
		  }
		 
	      // Draw Title	
		  ypos=yOffset;
          drawText(0, ypos, fontTitle, "Release Notes");
          ypos+=80;
	      
		  if (len!=0)
		  {		  
		    int startpos=0;
  		    for (i=0; i<len; i++)
		    {
			  if (text[i]=='\n') 
			  {			   
			     text[i]=0x00;
				 
				 // Show only 17 lines on screen
			     if ((lineCount++)>endEntry) break;
			     if (lineCount>startEntry) 
				 {				   
			        ypos+=15;
				    sprintf(tmp,"%s",text+startpos);
			        drawText(40, ypos, fontNormal, tmp);	
				 }		
			     startpos=i+1;
		
		      }
		    }
		  }
		  else
		  {
		     ypos+=120;
			 drawText(0, ypos, fontParagraph, "No information available!" );	
		     ypos+=20;
			 drawText(0, ypos, fontParagraph, "Information could not be fetch from internet.");
		  }
		  
		  // Draw buttons
	      drawButtons(); 

		  sprintf(tmp,"%d fps", CalculateFrameRate());
		  drawText(20, 460, fontSpecial, tmp);
		  
		  // Draw text layer on top of gameboard 
          GRRLIB_DrawImg2(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 255);
	   }
	   break;
	   
	   case stateSettings:
	   {
	      int ypos=yOffset;	   
			  	         	
	      // Init text layer	  
          GRRLIB_initTexture();
		   
	      // Draw background
		  GRRLIB_DrawImg(0,0,images.background1, 0, 1.0, 1.0, IMAGE_COLOR );
      		
	      // Draw Title	
          drawText(0, ypos, fontTitle, "    User Initials");
          ypos+=90;
		  
		  drawText(0, ypos, fontParagraph, "This user initials are used in the highscore area.");	
	      ypos+=80;
		  
	      // Draw panels		 
		  GRRLIB_DrawImg(60,ypos, images.panel1, 0, 1.0, 1.0, IMAGE_COLOR );
      	  GRRLIB_DrawImg(240,ypos, images.panel1, 0, 1.0, 1.0, IMAGE_COLOR );
		  GRRLIB_DrawImg(420,ypos, images.panel1, 0, 1.0, 1.0, IMAGE_COLOR );
      	  ypos+=10;
		  
		  // Draw text  
		  if (settings[0].value[0]!=0x00) drawText(110, ypos, fontTitle, settings[0].value);
		  if (settings[1].value[0]!=0x00) drawText(300, ypos, fontTitle, settings[1].value);
		  if (settings[2].value[0]!=0x00) drawText(480, ypos, fontTitle, settings[2].value);

		  ypos+=170;
	  	  //drawText(0, ypos, fontParagraph, "This initials are used in the highscore area.");	
	      
		   // Draw buttons
	      drawButtons(); 
		  
		  sprintf(tmp,"%d fps", CalculateFrameRate());
		  drawText(20, 460, fontSpecial, tmp);
				  
          // Draw text layer on top of gameboard 
          GRRLIB_DrawImg2(0, 0, GRRLIB_GetTexture(), 0, 1.0, 1.0, 255);	
	   }
	   break;
	}
}

// -----------------------------------------------------------
// MAIN
// -----------------------------------------------------------

int main()
{
    char *s_fn="main";
    int i;
			
    // Init video layer
    VIDEO_Init();
	
	// Init wiimote layer
    WPAD_Init();
    WPAD_SetIdleTimeout(60); // Wiimote is shutdown after 60 seconds of innactivity.
	//WPAD_SetDataFormat(WPAD_CHAN_0, WPAD_FMT_BTNS_ACC_IR);	// enable accelerometers and IR
    WPAD_SetDataFormat(WPAD_CHAN_ALL,WPAD_FMT_BTNS_ACC_IR);
  
  	// Set Shutdown Callbacks.
	SYS_SetPowerCallback( doPowerOff );
	WPAD_SetPowerButtonCallback( doPadPowerOff );
	
    // Obtain the preferred video mode from the system
	// This will correspond to the settings in the Wii menu
	rmode = VIDEO_GetPreferredMode(NULL);
		
	// Set up the video registers with the chosen mode
	VIDEO_Configure(rmode);
	
	if (rmode->xfbHeight==528)
	{
	    // TV mode PAL 50Hz
	    yOffset = 25;  
		yjpegOffset = 25;
	}
	else
	{      
	    // TV mode PAL 60Hz
	    yOffset = 25;
		yjpegOffset = 0;
	}

    // Init Fat
    fatInitDefault();

	// Open trace module
	traceOpen(TRACE_FILENAME);
	traceEvent(s_fn, 0,"%s %s Started", PROGRAM_NAME, PROGRAM_VERSION);
	
	// Load highscore from SD card
    loadLocalHighScoreFile(HIGHSCORE_FILENAME);	
	
	// Load setting from SD card
	loadSettingFile(SETTING_FILENAME);	
	
    // Init Http thread
	initThreads();
	
  	// Init game variables    
	//initMP3Files();
    initImages();
	initGame();	
	initSound();
	initGameBoard();
	initTodayHighScore();
	initGlobalHighScore();
	
	// Init FreeType font engine
	GRRLIB_InitFreetype();
	  			
    // Init GRRLib graphics library
    GRRLIB_Init();
        
	// Make screen black
	GRRLIB_FillScreen(0xFFFFFF);
    GRRLIB_Render();
		
	// Repeat forever
    while(!bPowerOff )
	{		
        // icon angle 
	    if (++angle>=MAX_ANGLE) angle=0;
		if (size<=MAX_SIZE) size+=0.05;
		
        // Init StateMachine			
	    initStateMachine();
			
        // Draw game board and other items (buttons, bubbles, etc...)
        drawScreen();		

	    // Scan for button events
		WPAD_SetVRes(0, 640, 480);
        WPAD_ScanPads();
			
		for (i=0; i<MAX_POINTER; i++)
		{
		  u32 wpaddown = WPAD_ButtonsDown(i);
		  u32 wpadup = WPAD_ButtonsDown(i);
		  u32 wpadheld = WPAD_ButtonsHeld(i);
		
          // Scan for ir events 
		  WPAD_IR(i, &pointers[i].ir); 
		  pointers[i].x=pointers[i].ir.sx-WSP_POINTER_X;
		  pointers[i].xOffset=pointers[i].x+IR_X_OFFSET;
		  pointers[i].y=pointers[i].ir.sy-WSP_POINTER_Y;
		  pointers[i].yOffset=pointers[i].y+IR_Y_OFFSET;
		  pointers[i].angle=pointers[i].ir.angle;
				
          // Scan for button events
		  if (wpadheld & BUTTON_A) buttonScroll(pointers[i].xOffset,pointers[i].yOffset);	 		
          if (wpaddown & BUTTON_A) buttonA(pointers[i].xOffset,pointers[i].yOffset); 		
		  if (wpadup & BUTTON_A) selectedA=false;
		  
		  // Only this first WiiMote can control the music and stop a running game.
		  if (i==0)
		  {		  
		    if (wpaddown & BUTTON_HOME) 
			{ 
			   if (stateMachine==stateGame) stateMachine=stateQuit;			   
			}
		  
  		    if (wpaddown & BUTTON_1 ) button1x();								
            if (wpadup & BUTTON_1) selected1=false;		
		  
		    if (wpaddown & BUTTON_2 ) button2y();		
		    if (wpadup & BUTTON_2) selected2=false;
		
		    // Make screenshot 
		    if (wpadheld & BUTTON_PLUS)
		    {
		      char filename[MAX_LEN];
      	      struct tm *level;	   
		      time_t dt=time(NULL);
		      level = localtime(&dt);
		      sprintf(filename,"%sSpaceBubble-%04d%02d%02d%02d%02d%02d.png", GAME_DIRECTORY, level->tm_year+1900,level->tm_mon+1, level->tm_mday,  level->tm_hour, level->tm_min, level->tm_sec);		  
              GRRLIB_ScrShot(filename);	
		    }
		  }
	
       	  // Draw wiimote ir pointer
          GRRLIB_DrawImg( pointers[i].x, pointers[i].y, pointers[i].image, pointers[i].angle, 1, 1, IMAGE_COLOR );			 
		}
		GRRLIB_Render();
	}
	
	GRRLIB_Exit();
		
	// Shut the system down.
	if ( bPowerOff )
	{
		traceEvent(s_fn, 0,"Shut the system down");
		traceEvent(s_fn, 0,"%s %s Stopped", PROGRAM_NAME, PROGRAM_VERSION);
		traceClose();
		
		SYS_ResetSystem( SYS_POWEROFF, 0, 0 );
    }

    return 0;
}

// -----------------------------------------------------------
// THE END
// -----------------------------------------------------------


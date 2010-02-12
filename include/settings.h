/** 
 *  @file
 *  @brief The file contain the settings prototypes
 *  @author wplaat
 *
 *  Copyright (C) 2008-2010 PlaatSoft
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

#ifndef __SETTINGS_H__
#define __SETTINGS_H__

#include "general.h"

#define MAX_NAME_SIZE 7

struct
{
   char name[MAX_NAME_SIZE];
   int  musicVolume;   
	int  effectVolume;
	int  loopMusicTrack;
}
settings;

/**
 * Load Settings file 
 * @param filename	The xml setting data
 */
void loadSettingFile(char* filename);


/** 
 * Save the setting xml file
 * @param filename	The setting filename.
 */
void saveSettingFile(char* filename);


#endif

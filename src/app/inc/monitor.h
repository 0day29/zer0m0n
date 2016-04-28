////////////////////////////////////////////////////////////////////////////
//
//	zer0m0n 
//
//  Copyright 2013 Conix Security, Nicolas Correia, Adrien Chevalier
//
//  This file is part of zer0m0n.
//
//  Zer0m0n is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Zer0m0n is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with Zer0m0n.  If not, see <http://www.gnu.org/licenses/>.
//
//
//	File :		monitor.h
//	Abstract :	Monitored processes list handling
//	Revision : 	v1.0
//	Author :	Adrien Chevalier & Nicolas Correia
//	Email :		adrien.chevalier@conix.fr nicolas.correia@conix.fr
//	Date :		2013-12-26	  
//	Notes : 	
//
/////////////////////////////////////////////////////////////////////////////
#ifndef __MONITOR_H
#define __MONITOR_H

#include "logs_dispatcher.h"

/////////////////////////////////////////////////////////////////////////////
// STRUCTS
/////////////////////////////////////////////////////////////////////////////

// Monitored process linked list 		
typedef struct _MONITORED_PROCESS_ENTRY {
		ULONG pid;
		PVOID flink;
} MONITORED_PROCESS_ENTRY,*PMONITORED_PROCESS_ENTRY;

/////////////////////////////////////////////////////////////////////////////
// GLOBALS
/////////////////////////////////////////////////////////////////////////////

PMONITORED_PROCESS_ENTRY monitored_process_list;

/////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
/////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Description :
//		Removes all of the monitored list entries (stops monitoring).
//	Parameters :
//		None
//	Return value :
//		int : 1 if no error was encountered, otherwise, returns -1.	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int cleanMonitoredProcessList();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Description :
//		Adds "pid" process in the monitored list and its associated socket id(starts monitoring this process).
//	Parameters :
//		_in_ ULONG new_pid : Process Identifier.
//	Return value :
//		int : 0 if success, -1 if not.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int startMonitoringProcess(ULONG new_pid);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Description :
//		Returns TRUE if pid is in the monitored list (if it is actually monitored).
//	Parameters :
//		_in_ ULONG pid : Process Identifier.
//	Return value :
//		int : 0 if found, -1 if not.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int isProcessMonitoredByPid(ULONG pid);


#endif

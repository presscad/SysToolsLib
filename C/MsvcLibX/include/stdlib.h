/*****************************************************************************\
*                                                                             *
*   Filename:	    stdlib.h						      *
*                                                                             *
*   Description:    MsvcLibX extensions to stdlib.h.			      *
*                                                                             *
*   Notes:	    							      *
*                                                                             *
*   History:								      *
*    2016-09-13 JFL Created this file.					      *
*    2020-03-29 JFL Added mkstmp() definitions.				      *
*									      *
*         � Copyright 2016 Hewlett Packard Enterprise Development LP          *
* Licensed under the Apache 2.0 license - www.apache.org/licenses/LICENSE-2.0 *
\*****************************************************************************/

#ifndef	_MSVCLIBX_stdlib_H
#define	_MSVCLIBX_stdlib_H	1

#include "msvclibx.h"

#include UCRT_INCLUDE_FILE(stdlib.h) /* Include MSVC's own <stdlib.h> file */

#ifdef __cplusplus
extern "C" {
#endif

/************************ MS-DOS-specific definitions ************************/

#ifdef _MSDOS	/* Automatically defined when targeting an MS-DOS application */

extern int mkstemp(char *pszName);	/* Create a temporary file */

#endif /* defined(_MSDOS) */

/************************ Win32-specific definitions *************************/

#ifdef _WIN32	/* Automatically defined when targeting a Win32 application */

extern char *_fullpathU(char *absPath, const char *relPath, size_t maxLength);

#if defined(_UTF8_SOURCE)
#define _fullpath _fullpathU		/* For processing UTF-8 pathnames */
#endif

/* Create a temporary file */
extern int mkstempM(char *pszName, UINT cp);	/* Multi-encoding version */
extern int mkstempA(char *pszName);		/* ANSI version */
extern int mkstempU(char *pszName);		/* UTF-8 version */

#if defined(_UTF8_SOURCE)
#define mkstemp mkstempU		/* For processing UTF-8 pathnames */
#else
#define mkstemp mkstempA		/* For processing UTF-8 pathnames */
#endif

#endif /* defined(_WIN32) */

/********************** End of OS-specific definitions ***********************/

#ifdef __cplusplus
}
#endif

#endif /* defined(_MSVCLIBX_stdlib_H)  */


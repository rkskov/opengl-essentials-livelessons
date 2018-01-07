/**
 *	types.h - These definitions are for linux/windows cross compiler compatibility
 *
 * author: Eric Young 01/22/2004
 */


#ifndef TYPES_H_
#define TYPES_H_

#define MIN(a,b) ((a < b) ? a : b)
#define MAX(a,b) ((a > b) ? a : b)
#define CLAMP(val,lower,upper) MAX(MIN(val,upper),lower)

#if defined(WIN32)
  #include <windows.h>
  #include <winbase.h>
#if !defined(_WIN32_WCE)
  #include <process.h>
#endif
  #include <winioctl.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <tchar.h>
#if !defined(_WIN32_WCE)
  #include <conio.h>
#endif
  #include <time.h>

  #if defined(_WIN32_WCE)
    #include <windev.h>
  #endif

  typedef char             int8_t;
  typedef unsigned char    uint8_t;

  typedef short            int16_t;
  typedef unsigned short   uint16_t;
  typedef long             int32_t;
  typedef unsigned long    uint32_t;
  typedef __int64          int64_t;
  typedef unsigned __int64 uint64_t;
  typedef __int64          INT64;
  typedef unsigned __int64 UINT64;

  typedef LONGLONG         int64_t;
  typedef ULONGLONG        uint64_t;

  // create some equivalent constants in windows that linux have
  typedef void*            PVOID;

  // common constants
  #define SUCCESS         0
  #define FAILURE        -1
  #define IOCTL_FAIL(status)    (status == 0)

  /* unusual return codes */
  #define UNIMPLEMENTED	-1001
  #define STATIC
  #define snprintf _snprintf

  #define DEV_NULL NULL

  #define usleep(time)     Sleep(time / 1000)
  #define sleep            Sleep

  /** sleep for x milliseconds */
  inline void nap(unsigned long msec) {    Sleep(msec); }

  typedef double VWTIME;
  /**
   *	returns the amount of time in seconds since some arbitrary moment.
   */
  inline VWTIME VWGetTime() {
	  return 0.0;
//	  return (VWTIME)timeGetTime() / 1000.00;
  }



//copies a char string into a TCHAR string
static int tstrncpy(TCHAR* dest, const char* src, int n) {
	int i = 0;
	if(n <= 0) return 0;
	while(i < n && *src != '\n') {
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return i;
}

static int tstrcpy(TCHAR* dest, const char* src)
{
   return tstrncpy(dest, src, strlen(src));
}
#if defined(_WIN32_WCE)
#define genericStrICmp _stricmp
#define genericStrNICmp _strnicmp
#else
#define genericStrICmp stricmp
#define genericStrNICmp strnicmp
#endif

#else // Definitions for  Linux

  // this definitions are for linux
  #include <stdio.h>
  #include <stdlib.h>
  #include <fcntl.h>
  #include <math.h>
  #include <inttypes.h>
  #include <errno.h>
  #include <unistd.h>
  #include <sched.h>

  #include <string.h>
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <sys/ioctl.h>
  #include <sys/mman.h>
  #include <sys/time.h>
  #include <sys/timeb.h>

  #include <linux/ioctl.h>

  #include <time.h>
  #include <pthread.h>

  // these are needed for Win32/Linux string comparisons
  #define genericStrICmp strcasecmp
  #define genericStrNICmp strncasecmp

  typedef int				 BOOL;
  typedef long int           LONG;
  typedef short int          SHORT;
  typedef char               CHAR;

  typedef unsigned long int  DWORD;
  typedef unsigned short     WORD;
  typedef unsigned char      BYTE;
  typedef unsigned int       UINT;

  typedef long long          INT64;
  typedef unsigned long long UINT64;

  typedef int                PT_FILEHANDLE;
  typedef void             * DLL_HANDLE;

  typedef unsigned long      DWORD;
  typedef unsigned long*     LPDWORD;
  typedef void*              LPOVERLAPPED;
  typedef void*              OVERLAPPED;
  typedef void*              LPVOID;
  typedef void*              PVOID;
  typedef void               VOID;
  typedef int                HANDLE;         // note that handle here is assumed to be
                                             // a pointer to a file decriptor
  typedef int*               PHANDLE;
  typedef int                BOOL;

  typedef unsigned long      UINT32;
  typedef unsigned long      ULONG;
  typedef unsigned short     USHORT;
  typedef unsigned char      UCHAR;
  typedef long long          INT64;
  typedef long long          LARGE_INTEGER;
  typedef unsigned char      BYTE;

  /* These are defined so we can use TCHAR compatible string calls */
  #define _TINT int
  #define _T(arg) arg
  #define TCHAR char
  #define tstrcpy  strcpy
  #define tstrncpy strncpy
  #define _tcscat  strcat
  #define _tcscpy(str1, str2) strcpy(str1, str2)
  #define _tcslen(str1) strlen(str1)
  #define _tfopen(filename, access)  fopen(filename, access)
  #define _gettc    getc
  #define _puttc    putc
  #define _stscanf  sscanf
  #define _stprintf sprintf
  #define _sntprintf snprintf
  #define _tprintf  printf



  /* common constants */
  #define SUCCESS         0
  #define FAILURE        -1

  #define IOCTL_FAIL(status)    (status < 0)

  /** unusual return codes */
  #define UNIMPLEMENTED	-1001

  // create some equivalent constants in linux that windows have
  #define STATIC             static

  #ifndef TRUE
        #define TRUE 1
  #endif

  #ifndef FALSE
        #define FALSE 0
  #endif

  #ifndef INVALID_HANDLE_VALUE
        #define INVALID_HANDLE_VALUE -1
  #endif

  /** sleep for x milliseconds */
  inline void nap(unsigned long msec) {    usleep(msec*1000); }

  #define Sleep sleep

  typedef double VWTIME;
  /** returns the amount of time in seconds since some arbitrary moment. */
  inline VWTIME VWGetTime() { return 0.0; }


#endif // end of the WIN32/Linux definitions


  // These are common declared types

  typedef unsigned char * PU8;
  typedef unsigned char    U8;
  typedef unsigned short   U16;
  typedef unsigned long    U32;
  typedef signed char    S8;
  typedef signed short   S16;
  typedef signed long    S32;


#if defined(_DEBUG)
  #define dbgprint(string) { printf string; fflush(stdout); }
#else
  #define dbgprint(string)
#endif

#include <string>

#if defined(_WIN32_WCE)
typedef struct {
	DWORD	dwSize;
	int		nNumOpens;
	// PCI related variables
	DWORD	vw_dwPciAddr;
	DWORD	vw_dwPciLength;
	DWORD	vw_dwDeviceID;		// the PCI Device ID
	DWORD	vw_dwRevisionID;	// the PCI chip revision
	HANDLE	vw_hIsrHandler;		// installable ISR
	DWORD	vw_dwBusNumber;
	DWORD	vw_dwInterfaceType;
	DWORD	vw_IntrID;			// translated interrupt ID
// more stuff follows but not needed for current uses
} DRVCONTEXT, *PDRVCONTEXT;

#endif

#endif // end of TYPES_H_

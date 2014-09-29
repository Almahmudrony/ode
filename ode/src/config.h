/* This file was autogenerated by Premake */
#ifndef _ODE_CONFIG_H_
#define _ODE_CONFIG_H_


/******************************************************************
 * CONFIGURATON SETTINGS - you can change these, and then rebuild
 *   ODE to modify the behavior of the library.
 *
 *   dTRIMESH_ENABLED  - enable/disable trimesh support
 *   dTRIMESH_OPCODE   - use the OPCODE trimesh engine
 *   dTRIMESH_GIMPACT  - use the GIMPACT trimesh engine
 *                       Only one trimesh engine should be enabled.
 *
 *   dTRIMESH_16BIT_INDICES (todo: opcode only)
 *                       Setup the trimesh engine to use 16 bit
 *                       triangle indices. The default is to use
 *                       32 bit indices. Use the dTriIndex type to
 *                       detect the correct index size.
 *
 *   dTRIMESH_OPCODE_USE_NEWOLD_TRIMESH_TRIMESH_COLLIDER
 *                       Use old implementation of trimesh-trimesh collider
 *                       (for backward compatibility only)
 *
 *   dOU_ENABLED       
 *   dATOMICS_ENABLED
 *   dTLS_ENABLED
 *                       Use generic features of OU library, atomic API
 *                       and TLS API respectively.
 *                       Generic features and atomic API are always enabled, 
 *                       unless threading interface support is disabled.
 *                       Using TLS for global variables allows calling ODE 
 *                       collision detection functions from multiple threads.
 *
 *   dBUILTIN_THREADING_IMPL_ENABLED
 *                       Include built-in multithreaded threading 
 *                       implementation (still must be created and assigned
 *                       to be used).
 *
 ******************************************************************/

#define dTRIMESH_ENABLED 1
#define dTRIMESH_OPCODE 1
#define dTRIMESH_16BIT_INDICES 0

#define dTRIMESH_OPCODE_USE_OLD_TRIMESH_TRIMESH_COLLIDER 0

/* #define dOU_ENABLED 1 */
/* #define dATOMICS_ENABLED 1 */
/* #define dTLS_ENABLED 1 */

/* #define dTHREADING_INTF_DISABLED 1 */
/* #define dBUILTIN_THREADING_IMPL_ENABLED 1 */


/******************************************************************
 * SYSTEM SETTINGS - you shouldn't need to change these. If you
 *   run into an issue with these settings, please report it to
 *   the ODE bug tracker at:
 *      http://sf.net/tracker/?group_id=24884&atid=382799
 ******************************************************************/

/* Try to identify the platform */
#if defined(_XENON)
  #define ODE_PLATFORM_XBOX360
#elif defined(SN_TARGET_PSP_HW)
  #define ODE_PLATFORM_PSP
#elif defined(SN_TARGET_PS3)
  #define ODE_PLATFORM_PS3
#elif defined(_MSC_VER) || defined(__CYGWIN32__) || defined(__MINGW32__)
  #define ODE_PLATFORM_WINDOWS
#elif defined(__linux__)
  #define ODE_PLATFORM_LINUX
#elif defined(__APPLE__) && defined(__MACH__)
  #define ODE_PLATFORM_OSX
#else
  #error "Need some help identifying the platform!"
#endif

/* Additional platform defines used in the code */
#if defined(ODE_PLATFORM_WINDOWS) && !defined(WIN32)
  #define WIN32
#endif

#if defined(__CYGWIN32__) || defined(__MINGW32__)
  #define CYGWIN
#endif

#if defined(ODE_PLATFORM_OSX)
  #define macintosh
#endif

#if !defined(ODE_PLATFORM_OSX) && !defined(ODE_PLATFORM_PS3)
  #include <malloc.h>
#endif

#if !defined(ODE_PLATFORM_WINDOWS)
  #include <alloca.h>
#endif


#ifdef dSINGLE
       #define dEpsilon  FLT_EPSILON
#else
       #define dEpsilon  DBL_EPSILON
#endif

/* An integer type that can be safely cast to a pointer. This definition
 * should be safe even on 64-bit systems */
typedef size_t intP;

/* The efficient alignment. most platforms align data structures to some
 * number of bytes, but this is not always the most efficient alignment.
 * for example, many x86 compilers align to 4 bytes, but on a pentium it is
 * important to align doubles to 8 byte boundaries (for speed), and the 4
 * floats in a SIMD register to 16 byte boundaries. many other platforms have
 * similar behavior. setting a larger alignment can waste a (very) small
 * amount of memory. NOTE: this number must be a power of two. */
#define EFFICIENT_ALIGNMENT 16

/* Basic OU functionality is required if either atomic API or TLS support
 * is enabled. */
#if dATOMICS_ENABLED || dTLS_ENABLED
#undef dOU_ENABLED
#define dOU_ENABLED 1
#endif


#include "typedefs.h"


#endif

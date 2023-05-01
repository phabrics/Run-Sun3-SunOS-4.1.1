/* tmeconfig.h
 *
 * This is an automatically generated file - please modify 'configure.in'.
 */

#ifndef _TMECONFIG_H
#define _TMECONFIG_H

#define _TME_ALIGNOF_INT16_T 1
#define _TME_ALIGNOF_INT32_T 1
#define _TME_ALIGNOF_INT64_T 1
#define _TME_HAVE_DLFCN_H 1
#define _TME_HAVE_FLOAT_H 1
#define _TME_HAVE_GETPAGESIZE 1
#define _TME_HAVE_GTK 
#define _TME_HAVE_INTTYPES_H 1
#define _TME_HAVE_ISINFF 
#define _TME_HAVE_LIMITS_H 1
#define _TME_HAVE_LONG_DOUBLE 1
#define _TME_HAVE_LONG_DOUBLE_WIDER 1
#define _TME_HAVE_MEMORY_H 1
#define _TME_HAVE_MMAP 1
#define _TME_HAVE_STDARG_H 1
#define _TME_HAVE_STDINT_H 1
#define _TME_HAVE_STDIO_H 1
#define _TME_HAVE_STDLIB_H 1
#define _TME_HAVE_STRINGS_H 1
#define _TME_HAVE_STRING_H 1
#define _TME_HAVE_SYS_IOCTL_H 1
#define _TME_HAVE_SYS_STAT_H 1
#define _TME_HAVE_SYS_TYPES_H 1
#define _TME_HAVE_UNISTD_H 1
#define _TME_SIZEOF_DOUBLE 8
#define _TME_SIZEOF_FLOAT 4
#define _TME_SIZEOF_INT 4
#define _TME_SIZEOF_LONG 8
#define _TME_SIZEOF_LONG_DOUBLE 16
#define _TME_SIZEOF_SHORT 2
/* #undef HAVE_AF_LINK */
/* #undef HAVE_BSWAP16 */
/* #undef HAVE_BSWAP32 */
/* #undef HAVE_BSWAP64 */
/* #undef HAVE_IOCTLS_H */
/* #undef HAVE_NET_IF_DL_H */
/* #undef HAVE_SOCKADDR_SA_LEN */
/* #undef HAVE_SYS_BSWAP_H */
/* #undef HAVE_SYS_SOCKETIO_H */
/* #undef HAVE_SYS_SOCKIO_H */
/* #undef WORDS_BIGENDIAN */
#define TME_FLOAT_FORMAT_DOUBLE TME_FLOAT_FORMAT_IEEE754_DOUBLE
#define TME_FLOAT_FORMAT_FLOAT TME_FLOAT_FORMAT_IEEE754_SINGLE
/* #undef FLOAT_FORMAT_LONG_DOUBLE */
#define TME_BUSMAX_LOG2 TME_BUS64_LOG2
#define TME_HAVE_RECODE ( 0 )
#define TME_RECODE_SIZE_GUEST_MAX TME_RECODE_SIZE_64
#define TME_RELEASE_MAJOR ( 0 )
#define TME_RELEASE_MINOR ( 8 )
#define TME_BUILD_TARGET "x86_64-unknown-linux-gnu"
#define TME_HAVE_INT64_T
#define _TME_PRI64 "l"
typedef signed long tme_int64_t;
typedef unsigned long tme_uint64_t;
#define _TME_PRI32 ""
typedef signed int tme_int32_t;
typedef unsigned int tme_uint32_t;
typedef signed short tme_int16_t;
typedef unsigned short tme_uint16_t;
typedef signed char tme_int8_t;
typedef unsigned char tme_uint8_t;

/* features that aren't currently controlled by a configure option: */
#define TME_THREADS_SJLJ

#endif /* !_TMECONFIG_H */

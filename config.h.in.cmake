/* DO NOT MODIFY! config.h: autogenerated by CMake from config.h.in.cmake. */

/* Define to default visibility of PKCS#11 entry points */
#cmakedefine CRYPTOKI_VISIBILITY @CRYPTOKI_VISIBILITY@

/* The default log level */
#cmakedefine DEFAULT_LOG_LEVEL "@DEFAULT_LOG_LEVEL@"

/* Default storage backend for token objects */
#cmakedefine DEFAULT_OBJECTSTORE_BACKEND "@DEFAULT_OBJECTSTORE_BACKEND@"

/* The default PKCS#11 library */
#cmakedefine DEFAULT_PKCS11_LIB "@DEFAULT_PKCS11_LIB@"

/* The default location of softhsm2.conf */
#cmakedefine DEFAULT_SOFTHSM2_CONF "@DEFAULT_SOFTHSM2_CONF@"

/* The default location of the token directory */
#cmakedefine DEFAULT_TOKENDIR "@DEFAULT_TOKENDIR@"

/* The default storage mode (optimization merge cache and FS) */
#define DEFAULT_OBJSTORE_CREATE_ONLY @DEFAULT_OBJSTORE_CREATE_ONLY@

/* Define if advanced AES key wrap without pad is supported */
#cmakedefine HAVE_AES_KEY_WRAP @HAVE_AES_KEY_WRAP@

/* Define if advanced AES key wrap with pad is supported */
#cmakedefine HAVE_AES_KEY_WRAP_PAD @HAVE_AES_KEY_WRAP_PAD@

/* define if the compiler supports basic C++11 syntax */
#cmakedefine HAVE_CXX11 @HAVE_CXX11@

/* Define to 1 if you have the <dlfcn.h> header file. */
#cmakedefine HAVE_DLFCN_H @HAVE_DLFCN_H@

/* Define if you have dlopen */
#cmakedefine HAVE_DLOPEN @HAVE_DLOPEN@

/* Define to 1 if you have the `getpwuid_r' function. */
#cmakedefine HAVE_GETPWUID_R @HAVE_GETPWUID_R@

/* Define to 1 if you have the <inttypes.h> header file. */
#cmakedefine HAVE_INTTYPES_H @HAVE_INTTYPES_H@

/* Define to 1 if you have the `crypto' library (-lcrypto). */
#cmakedefine HAVE_LIBCRYPTO @HAVE_LIBCRYPTO@

/* Define to 1 if you have the `sqlite3' library (-lsqlite3). */
#cmakedefine HAVE_LIBSQLITE3 @HAVE_LIBSQLITE3@

/* Whether LoadLibrary is available */
#cmakedefine HAVE_LOADLIBRARY @HAVE_LOADLIBRARY@

/* Define to 1 if you have the <memory.h> header file. */
#cmakedefine HAVE_MEMORY_H @HAVE_MEMORY_H@

/* Build with object store database backend. */
#cmakedefine HAVE_OBJECTSTORE_BACKEND_DB @HAVE_OBJECTSTORE_BACKEND_DB@

/* Define to 1 if you have the <openssl/ssl.h> header file. */
#cmakedefine HAVE_OPENSSL_SSL_H @HAVE_OPENSSL_SSL_H@

/* Define to 1 if you have the <pthread.h> header file. */
#cmakedefine HAVE_PTHREAD_H @HAVE_PTHREAD_H@

/* Define to 1 if you have the <sqlite3.h> header file. */
#cmakedefine HAVE_SQLITE3_H @HAVE_SQLITE3_H@

/* Define to 1 if you have the <stdint.h> header file. */
#cmakedefine HAVE_STDINT_H @HAVE_STDLIB_H@

/* Define to 1 if you have the <stdlib.h> header file. */
#cmakedefine HAVE_STDLIB_H @HAVE_STDLIB_H@

/* Define to 1 if you have the <strings.h> header file. */
#cmakedefine HAVE_STRINGS_H @HAVE_STRINGS_H@

/* Define to 1 if you have the <string.h> header file. */
#cmakedefine HAVE_STRING_H @HAVE_STRING_H@

/* Define to 1 if you have the <sys/mman.h> header file. */
#cmakedefine HAVE_SYS_MMAN_H @HAVE_SYS_MMAN_H@

/* Define to 1 if you have the <sys/stat.h> header file. */
#cmakedefine HAVE_SYS_STAT_H @HAVE_SYS_STAT_H@

/* Define to 1 if you have the <sys/types.h> header file. */
#cmakedefine HAVE_SYS_TYPES_H @HAVE_SYS_TYPES_H@

/* Define to 1 if you have the <unistd.h> header file. */
#cmakedefine HAVE_UNISTD_H @HAVE_UNISTD_H@

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#cmakedefine LT_OBJDIR "@LT_OBJDIR@"

/* Maximum PIN length */
#cmakedefine MAX_PIN_LEN @MAX_PIN_LEN@

/* Minimum PIN length */
#cmakedefine MIN_PIN_LEN @MIN_PIN_LEN@

/* Name of package */
#cmakedefine PACKAGE "@PACKAGE@"

/* Define to the address where bug reports for this package should be sent. */
#cmakedefine PACKAGE_BUGREPORT "@PACKAGE_BUGREPORT@"

/* Define to the full name of this package. */
#cmakedefine PACKAGE_NAME "@PACKAGE_NAME@"

/* Define to the full name and version of this package. */
#cmakedefine PACKAGE_STRING "@PACKAGE_STRING@"

/* Define to the one symbol short name of this package. */
#cmakedefine PACKAGE_TARNAME "@PACKAGE_TARNAME@"

/* Define to the home page for this package. */
#cmakedefine PACKAGE_URL "@PACKAGE_URL@"

/* Define to the version of this package. */
#cmakedefine PACKAGE_VERSION "@PACKAGE_VERSION@"

/* Non-paged memory for secure storage */
#cmakedefine SENSITIVE_NON_PAGE @SENSITIVE_NON_PAGE@

/* Define to 1 if you have the ANSI C header files.
 *
 * FIXME: CMake currently does not implement a way to detect STDC_HEADERS like
 *        autotools, so we're setting it to '1' by default.
 */
 #cmakedefine STDC_HEADERS @STDC_HEADERS@

/* Version number of package */
#cmakedefine VERSION "@VERSION@"

/* SoftHSM major version number via PKCS#11 */
#cmakedefine VERSION_MAJOR @VERSION_MAJOR@

/* SoftHSM minor version number via PKCS#11 */
#cmakedefine VERSION_MINOR @VERSION_MINOR@

/* Compile with AES GCM */
#cmakedefine WITH_AES_GCM @WITH_AES_GCM@

/* Compile with Botan support */
#cmakedefine WITH_BOTAN @WITH_BOTAN@

/* Compile with ECC support */
#cmakedefine WITH_ECC @WITH_ECC@

/* Compile with EDDSA support */
#cmakedefine WITH_EDDSA @WITH_EDDSA@

/* Compile with FIPS 140-2 mode */
#cmakedefine WITH_FIPS @WITH_FIPS@

/* Compile with GOST support */
#cmakedefine WITH_GOST @WITH_GOST@

/* Compile with OpenSSL support */
#cmakedefine WITH_OPENSSL @WITH_OPENSSL@

/* Compile with raw RSA PKCS PSS */
#cmakedefine WITH_RAW_PSS @WITH_RAW_PSS@

/*
 * Remainder is specific for Windows build to
 * set some default that aren't configured from
 * cmake yet, and provide compatibility functions.
 */
#ifdef _WIN32

/* The default log level */
#undef DEFAULT_LOG_LEVEL
#define DEFAULT_LOG_LEVEL "INFO"

/* Default storage backend for token objects */
#undef DEFAULT_OBJECTSTORE_BACKEND
#define DEFAULT_OBJECTSTORE_BACKEND "file"

/* The default PKCS#11 library */
#undef DEFAULT_PKCS11_LIB
#define DEFAULT_PKCS11_LIB "softhsm2.dll"

/* The default location of softhsm2.conf */
#undef DEFAULT_SOFTHSM2_CONF
#define DEFAULT_SOFTHSM2_CONF "softhsm2.conf"

/* The default location of the token directory */
#undef DEFAULT_TOKENDIR
#define DEFAULT_TOKENDIR "tokens"

/* Whether LoadLibrary is available */
#undef HAVE_LOADLIBRARY
#define HAVE_LOADLIBRARY 1


/* Define to 1 if you have the <stdlib.h> header file. */
#undef HAVE_STDLIB_H
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#undef HAVE_STRINGS_H

/* Define to 1 if you have the <string.h> header file. */
#undef HAVE_STRING_H
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#undef HAVE_SYS_STAT_H
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#undef HAVE_SYS_TYPES_H
#define HAVE_SYS_TYPES_H 1

/* Maximum PIN length */
#undef MAX_PIN_LEN
#define MAX_PIN_LEN 255

/* Minimum PIN length */
#undef MIN_PIN_LEN
#define MIN_PIN_LEN 4

/* Define to 1 if you have getpassphrase(). */
#define HAVE_GETPASSPHRASE

/* Addition things */

char *getpassphrase(const char *prompt);
int setenv(const char *name, const char *value, int overwrite);

/* At least Vista */

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif

#if _MSC_VER < 1900
#define snprintf _snprintf
#endif
#define strcasecmp _stricmp
#define strncasecmp _strnicmp

/* Prevent inclusion of winsock.h in windows.h */

#define WIN32_LEAN_AND_MEAN 1

#include <windows.h>

/* avoid collision from min and max macros */

#undef min
#undef max

/* Temporary for debug */

#undef DEBUG_LOG_STDERR
// #define DEBUG_LOG_STDERR 1

/* To avoid unsafe warnings (off) */

// #pragma warning(disable: 4996)

#endif

#cmakedefine DEBUG_LOG_STDOUT @DEBUG_LOG_STDOUT@

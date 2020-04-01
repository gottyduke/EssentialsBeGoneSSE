#ifndef ESBG_VERSION_INCLUDED
#define ESBG_VERSION_INCLUDED

#define MAKE_STR_HELPER(a_str) #a_str
#define MAKE_STR(a_str) MAKE_STR_HELPER(a_str)

#define ESBG_VERSION_MAJOR	2
#define ESBG_VERSION_MINOR	0
#define ESBG_VERSION_PATCH	0
#define ESBG_VERSION_BETA	0
#define ESBG_VERSION_VERSTRING	MAKE_STR(ESBG_VERSION_MAJOR) "." MAKE_STR(ESBG_VERSION_MINOR) "." MAKE_STR(ESBG_VERSION_PATCH) "." MAKE_STR(ESBG_VERSION_BETA)

#endif

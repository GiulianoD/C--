#ifndef CROSSPLAY_H_
#define CROSSPLAY_H_

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
   #define CLS "clear"
   #define START_CHORME_ "start chrome "
#elif __APPLE__
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR
         // iOS, tvOS, or watchOS Simulator
    #elif TARGET_OS_MACCATALYST
         // Mac's Catalyst (ports iOS API into Mac, like UIKit).
    #elif TARGET_OS_IPHONE
        // iOS, tvOS, or watchOS device
    #elif TARGET_OS_MAC
        // Other kinds of Apple platforms
    #else
    #   error "Unknown Apple platform"
    #endif
#elif __linux__
    #define CLS "cls"
    #define START_CHORME_ "chrome "
#elif __unix__
    #define CLS "cls"
    #define START_CHORME_ "chrome "
#elif defined(_POSIX_VERSION)
    #define CLS "cls"
    #define START_CHORME_ "chrome "
#else
#   error "Unknown compiler"
#endif

#include "_crossplay/_system_commons.c"
#include "_crossplay/_file_commons.c"

void pause();
void open_chrome(char *lnk);
FILE *open_file(const char *path, const char *mode);

#endif

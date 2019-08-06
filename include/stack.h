#pragma once
#if defined _WIN32 || defined __CYGWIN__
#    ifdef BUILDING_JFLCSTD
#        define JFLCSTD_PUBLIC __declspec(dllexport)
#    else
#        define JFLCSTD_PUBLIC __declspec(dllimport)
#    endif
#else
#    ifdef BUILDING_JFLCSTD
#        define JFLCSTD_PUBLIC __attribute__((visibility("default")))
#    else
#        define JFLCSTD_PUBLIC
#    endif
#endif

typedef JFLCSTD_PUBLIC struct Stack { void *data, struct Stack *next, size_t length_, } Stack;

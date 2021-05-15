#ifndef _CITRUS_H_
#define _CITRUS_H_

// Debug print macros.
#ifdef DEBUG_BUILD
#include <stdio.h>
#define debug(fmt, ...)                                                        \
  do {                                                                         \
    fprintf(stderr, "(%s:%d@%s): ", __FILE__, __LINE__, __func__);             \
    fprintf(stderr, fmt, ##__VA_ARGS__);                                       \
  } while (0)
#else
#define debug(fmt, ...)
#endif

// Test macros
#ifdef UNIT_TEST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define assert(expr)                                                           \
  do {                                                                         \
    fprintf(stderr, "(%s:%d): assert(" #expr ") => ", __FILE__, __LINE__);     \
    if (expr) {                                                                \
      fprintf(stderr, "\x1b[32;1mOK\x1b[0m\n");                                \
    } else {                                                                   \
      fprintf(stderr, "\x1b[31;1mFAILED\x1b[0m\n");                            \
      exit(1);                                                                 \
    }                                                                          \
  } while (0)
#define assert_int(expr1, expr2)                                               \
  do {                                                                         \
    fprintf(stderr, "(%s:%d): assert_int(" #expr1 ", " #expr2 ") => ",         \
            __FILE__, __LINE__);                                               \
    if (expr1 == expr2) {                                                      \
      fprintf(stderr, "\x1b[32;1mOK\x1b[0m\n");                                \
    } else {                                                                   \
      fprintf(stderr, "\x1b[31;1mFAILED\x1b[0m (found %d)\n", expr1);          \
      exit(1);                                                                 \
    }                                                                          \
  } while (0)
#define assert_char(expr1, expr2)                                              \
  do {                                                                         \
    fprintf(stderr, "(%s:%d): assert_char(" #expr1 ", " #expr2 ") => ",        \
            __FILE__, __LINE__);                                               \
    if (expr1 == expr2) {                                                      \
      fprintf(stderr, "\x1b[32;1mOK\x1b[0m\n");                                \
    } else {                                                                   \
      fprintf(stderr, "\x1b[31;1mFAILED\x1b[0m (found '%c')\n", expr1);        \
      exit(1);                                                                 \
    }                                                                          \
  } while (0)
#define assert_str(expr1, expr2)                                               \
  do {                                                                         \
    fprintf(stderr, "(%s:%d): assert_str(" #expr1 ", " #expr2 ") => ",         \
            __FILE__, __LINE__);                                               \
    if (strcmp(expr1, expr2) == 0) {                                           \
      fprintf(stderr, "\x1b[32;1mOK\x1b[0m\n");                                \
    } else {                                                                   \
      fprintf(stderr, "\x1b[31;1mFAILED\x1b[0m (found \"%s\")\n", expr1);      \
      exit(1);                                                                 \
    }                                                                          \
  } while (0)
#define assert_strn(expr1, expr2, len)                                         \
  do {                                                                         \
    fprintf(stderr,                                                            \
            "(%s:%d): assert_strn(" #expr1 ", " #expr2 ", " #len ") => ",      \
            __FILE__, __LINE__);                                               \
    if (strncmp(expr1, expr2, len) == 0) {                                     \
      fprintf(stderr, "\x1b[32;1mOK\x1b[0m\n");                                \
    } else {                                                                   \
      fprintf(stderr, "\x1b[31;1mFAILED\x1b[0m (found \"%s\")\n", expr1);      \
      exit(1);                                                                 \
    }                                                                          \
  } while (0)
#endif

#endif

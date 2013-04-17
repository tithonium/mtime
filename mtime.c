/* Copyright (C) 2006 Midgard Systems Group
   Derived from time/ctime.c from glibc
 */

#include <time.h>
#include "mtime.h"

char *
mtime (const time_t *t)
{
  return masctime (mlocaltime (t));
}


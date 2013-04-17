/* Copyright (C) 2006 Midgard Systems Group
   Derived from time/ctime.c from glibc
 */

#include <time.h>
#include "mtime.h"

struct tm _tmbuf;

struct tm *
mlocaltime_r (t, tp)
     const time_t *t;
     struct tm *tp;
{
  return m_offtime (t, 1, tp);
}

struct tm *
mlocaltime (t)
     const time_t *t;
{
  return m_offtime(t, 1, &_tmbuf);
}

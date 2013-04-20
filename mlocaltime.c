/* Copyright (C) 2006 Midgard Systems Group
   Derived from time/ctime.c from glibc
 */

#include <time.h>
#include "mlocaltime.h"
#include "mofftime.h"

struct tm *mlocaltime_r(const time_t *t, struct tm *tp) {
  return m_offtime(t, 1, tp);
}

struct tm _tmbuf;

struct tm *mlocaltime (const time_t *t) {
  return m_offtime(t, 1, &_tmbuf);
}

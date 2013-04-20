/* Copyright (C) 2006 Midgard Systems Group
   Derived from time/ctime.c from glibc
 */

#include <stdio.h>
#include <time.h>
#include "masctime.h"
#include "mtimedefs.h"

static const char format[]     = "%.3s %.3s%3d %.2d:%.2d:%.2d %d";
static const char slipformat[] = "%.3s %.3s%3d --:--:-- %d";
static char result[              3+1+ 3+1+20+1+20+1+20+1+20+1+20+1];

/* Returns a string of the form "Day Mon dd hh:mm:ss yyyy\n"
   which is the representation of TP in that form.  */
char *masctime (const struct tm *tp) {
  return masctime_r(tp, result);
}

char *masctime_r (const struct tm *tp, char *buf) {
  if (tp == NULL) {
    return NULL;
  }

  if(tp->tm_hour >= 24) {
    if (sprintf (buf, slipformat,
                 (tp->tm_wday < 0 || tp->tm_wday >= 7 ? "???" : _m_weekday_name[tp->tm_wday]),
                 (tp->tm_mon < 0 || tp->tm_mon >= 24 ? "???" : _m_ab_month_name[tp->tm_mon]),
                 tp->tm_mday,
                 tp->tm_year
                ) < 0)
      return NULL;
  } else {
    if (sprintf (buf, format,
                 (tp->tm_wday < 0 || tp->tm_wday >= 7 ? "???" : _m_weekday_name[tp->tm_wday]),
                 (tp->tm_mon < 0 || tp->tm_mon >= 24 ? "???" : _m_ab_month_name[tp->tm_mon]),
                 tp->tm_mday,
                 tp->tm_hour,
                 tp->tm_min,
                 tp->tm_sec,
                 tp->tm_year
                ) < 0)
      return NULL;
  }

  return buf;
}

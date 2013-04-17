#include <stdio.h>
#include <time.h>
#include "mtime.h"

#define SECS_PER_MINUTE 60
#define SECS_PER_HOUR   (60 * SECS_PER_MINUTE)
#define SECS_PER_DAY    ((SECS_PER_HOUR * 24) + (SECS_PER_MINUTE * 39) + 35)
#define SECS_PER_YEAR   (668.5991 * SECS_PER_DAY)


int main() {
  unsigned int y;
  time_t t, tt, ttt;
  struct tm tmbuf, ttmbuf;
  char *a, buf[10];
  int s;

  printf("BEGIN:VCALENDAR\nVERSION:2.0\nCALSCALE:GREGORIAN\nX-WR-CALNAME:Marty's Martian Birthdays\nX-WR-TIMEZONE:US/Pacific\n");

  t = 225948360;
  for(y = 0; y <= 50; t+=SECS_PER_YEAR, y++) {
    if(y == 0)
      continue;
//    fprintf(stderr, " t %u: %s  %s", t, mtime(&t), ctime(&t));
    a = mtime(&t);

    //day
    buf[0] = a[9]; buf[1] = a[10]; buf[2] = 0;
    s = atoi(buf) * SECS_PER_DAY;
    // hour
    buf[0] = a[11]; buf[1] = a[12]; buf[2] = 0;
    s += atoi(buf) * SECS_PER_HOUR;
    // min
    buf[0] = a[14]; buf[1] = a[15]; buf[2] = 0;
    s += atoi(buf) * SECS_PER_MINUTE;
    // hour
    buf[0] = a[17]; buf[1] = a[18]; buf[2] = 0;
    s += atoi(buf);
    s -= 785559; // Kar 8 20:55:59
    tt = t - s;
//    fprintf(stdout, "tt %u: %s  %s", tt, a = mtime(&tt), ctime(&tt));

    ttt = tt + 86400;
    localtime_r(&tt, &tmbuf);
    localtime_r(&ttt, &ttmbuf);

    printf("BEGIN:VEVENT\nDTSTART;VALUE=DATE:%4.4d%2.2d%2.2d\nDTEND;VALUE=DATE:%4.4d%2.2d%2.2d\nSUMMARY:Marty's %d%s Martian Birthday\nEND:VEVENT\n", tmbuf.tm_year + 1900, tmbuf.tm_mon + 1, tmbuf.tm_mday, ttmbuf.tm_year + 1900, ttmbuf.tm_mon + 1, ttmbuf.tm_mday, y, 
             (y > 3 && y < 21 ? "th" : (y % 10 == 1 ? "st" : ( y % 10 == 2 ? "nd" : ( y % 10 == 3 ? "rd" : "th" ) ) ) )
          );


  }

  printf("END:VCALENDAR\n");

  return 0;
}


/*
          1         2
01234567890123456789012
Lun Kar  8 20:55:59 195
Ven Kar  9 11:02:49 196
*/

#include <stdio.h>
#include <time.h>
#include "mtime.h"

int main() {
  time_t t;
  struct tm tmbuf;

  t = 0;
  printf("T:[%d]\n\n", t);

  gmtime_r(&t, &tmbuf);
  printf("gmtime:    tm_sec[%2.2d]  tm_min[%2.2d]  tm_hour[%2.2d]  tm_mday[%2.2d]  tm_mon[%2.2d]  tm_year[%3.3d]  tm_wday[%1.1d]  tm_yday[%3.3d]  tm_isdst[%d]\n",
         tmbuf.tm_sec, tmbuf.tm_min, tmbuf.tm_hour, tmbuf.tm_mday, tmbuf.tm_mon, tmbuf.tm_year, tmbuf.tm_wday, tmbuf.tm_yday, tmbuf.tm_isdst);
  printf("           %s\n", asctime(&tmbuf));
  printf("           %s\n", ctime(&t));

  m_offtime (&t, 0, &tmbuf);
  printf("m_offtime: tm_sec[%2.2d]  tm_min[%2.2d]  tm_hour[%2.2d]  tm_mday[%2.2d]  tm_mon[%2.2d]  tm_year[%3.3d]  tm_wday[%1.1d]  tm_yday[%3.3d]  tm_isdst[%d]\n",
         tmbuf.tm_sec, tmbuf.tm_min, tmbuf.tm_hour, tmbuf.tm_mday, tmbuf.tm_mon, tmbuf.tm_year, tmbuf.tm_wday, tmbuf.tm_yday, tmbuf.tm_isdst);
  printf("           %s\n", masctime(&tmbuf));
  printf("           %s\n", mtime(&t));

  printf("--------------------------------------------------\n");

  t = 1149649200;
  printf("T:[%d]\n\n", t);

  gmtime_r(&t, &tmbuf);
  printf("gmtime:    tm_sec[%2.2d]  tm_min[%2.2d]  tm_hour[%2.2d]  tm_mday[%2.2d]  tm_mon[%2.2d]  tm_year[%3.3d]  tm_wday[%1.1d]  tm_yday[%3.3d]  tm_isdst[%d]\n",
         tmbuf.tm_sec, tmbuf.tm_min, tmbuf.tm_hour, tmbuf.tm_mday, tmbuf.tm_mon, tmbuf.tm_year, tmbuf.tm_wday, tmbuf.tm_yday, tmbuf.tm_isdst);
  printf("           %s\n", asctime(&tmbuf));

  m_offtime (&t, 0, &tmbuf);
  printf("m_offtime: tm_sec[%2.2d]  tm_min[%2.2d]  tm_hour[%2.2d]  tm_mday[%2.2d]  tm_mon[%2.2d]  tm_year[%3.3d]  tm_wday[%1.1d]  tm_yday[%3.3d]  tm_isdst[%d]\n",
         tmbuf.tm_sec, tmbuf.tm_min, tmbuf.tm_hour, tmbuf.tm_mday, tmbuf.tm_mon, tmbuf.tm_year, tmbuf.tm_wday, tmbuf.tm_yday, tmbuf.tm_isdst);
  printf("           %s\n", masctime(&tmbuf));

  printf("--------------------------------------------------\n");

  t = 225948360;
  printf("T:[%d]\n\n", t);

  gmtime_r(&t, &tmbuf);
  printf("gmtime:    tm_sec[%2.2d]  tm_min[%2.2d]  tm_hour[%2.2d]  tm_mday[%2.2d]  tm_mon[%2.2d]  tm_year[%3.3d]  tm_wday[%1.1d]  tm_yday[%3.3d]  tm_isdst[%d]\n",
         tmbuf.tm_sec, tmbuf.tm_min, tmbuf.tm_hour, tmbuf.tm_mday, tmbuf.tm_mon, tmbuf.tm_year, tmbuf.tm_wday, tmbuf.tm_yday, tmbuf.tm_isdst);
  printf("           %s\n", asctime(&tmbuf));

  m_offtime (&t, 0, &tmbuf);
  printf("m_offtime: tm_sec[%2.2d]  tm_min[%2.2d]  tm_hour[%2.2d]  tm_mday[%2.2d]  tm_mon[%2.2d]  tm_year[%3.3d]  tm_wday[%1.1d]  tm_yday[%3.3d]  tm_isdst[%d]\n",
         tmbuf.tm_sec, tmbuf.tm_min, tmbuf.tm_hour, tmbuf.tm_mday, tmbuf.tm_mon, tmbuf.tm_year, tmbuf.tm_wday, tmbuf.tm_yday, tmbuf.tm_isdst);
  printf("           %s\n", masctime(&tmbuf));

  printf("--------------------------------------------------\n");

  time(&t);
  printf("T:[%d]\n\n", t);

  gmtime_r(&t, &tmbuf);
  printf("gmtime:    tm_sec[%2.2d]  tm_min[%2.2d]  tm_hour[%2.2d]  tm_mday[%2.2d]  tm_mon[%2.2d]  tm_year[%3.3d]  tm_wday[%1.1d]  tm_yday[%3.3d]  tm_isdst[%d]\n",
         tmbuf.tm_sec, tmbuf.tm_min, tmbuf.tm_hour, tmbuf.tm_mday, tmbuf.tm_mon, tmbuf.tm_year, tmbuf.tm_wday, tmbuf.tm_yday, tmbuf.tm_isdst);
  printf("           %s\n", asctime(&tmbuf));

  m_offtime (&t, 0, &tmbuf);
  printf("m_offtime: tm_sec[%2.2d]  tm_min[%2.2d]  tm_hour[%2.2d]  tm_mday[%2.2d]  tm_mon[%2.2d]  tm_year[%3.3d]  tm_wday[%1.1d]  tm_yday[%3.3d]  tm_isdst[%d]\n",
         tmbuf.tm_sec, tmbuf.tm_min, tmbuf.tm_hour, tmbuf.tm_mday, tmbuf.tm_mon, tmbuf.tm_year, tmbuf.tm_wday, tmbuf.tm_yday, tmbuf.tm_isdst);
  printf("           %s\n", masctime(&tmbuf));

  printf("--------------------------------------------------\n");

  for(t = 1149649200; t < 1149649200+86400; t+= 3599) {
    m_offtime (&t, 0, &tmbuf);
    printf("           %s\n", masctime(&tmbuf));
  }

  printf("--------------------------------------------------\n");

  for(t = 1149663262; t < 1149665667; t+= 1) {
    printf(" %d: %s  %s", t, mtime(&t), ctime(&t));
  }

  printf("--------------------------------------------------\n");

  return 0;
}

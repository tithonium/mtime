#ifndef _MASCTIME_H
#define _MASCTIME_H 1

char *masctime(const struct tm *tp);
char *masctime_r(const struct tm *tp, char *buf);

#endif

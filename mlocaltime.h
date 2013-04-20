#ifndef _MLOCALTIME_H
#define _MLOCALTIME_H 1

struct tm *mlocaltime_r(const time_t *t, struct tm *tp);
struct tm *mlocaltime(const time_t *t);

#endif

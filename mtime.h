#ifndef	_MTIME_H

# define _MTIME_H	1

char *masctime (const struct tm *tp);
char *masctime_r (const struct tm *tp, char *buf);
struct tm *mlocaltime_r (const time_t *t, struct tm *tp);
struct tm *mlocaltime (const time_t *t);

struct tm *m_offtime (const time_t *t, long int offset, struct tm *tp);

char *mtime (const time_t *t);

#endif /* <mtime.h> not already included.  */

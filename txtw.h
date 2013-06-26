#ifndef _TXTW_H
#define _TXTW_H

#define FONT_FAMILY     "sans-serif"
#define FONT_SIZE       16
#define ALT_MAGIC_CHAR  '\\'
#define ALT_BEGIN_SEQ   '('
#define ALT_END_SEQ     ')'
#define MAXLEN          256
#define MIN(A, B)       ((A) < (B) ? (A) : (B))

int text_width(char *, int, char *);

#endif

#ifndef __TXTFIND_H__
#define __TXTFIND_H__

#define LINE 256
#define WORD 30
#define MAXLINES 250

int getLine(char s[]);
int getWord(char w[]);
int subString(char *str1, char *str2);
int similar (char *s, char *t, int n);
void print_lines(char *str);
void print_similar_words(char *str);

#endif

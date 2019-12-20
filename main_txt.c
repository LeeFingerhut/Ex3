#include <stdio.h>
#include "txtfind.h"

int main()
{
   char ref[WORD]={0};
   getWord(ref);
   char opt[WORD]={0};
   getWord(opt);
   if(*opt == 'a')
   {
      print_lines(ref);
   }
   else if(*opt == 'b')
   {
      print_similar_words(ref);
   }
   else
   {
      printf("wrong opt\n");
   }
   return 0;
}

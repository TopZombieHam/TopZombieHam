/* {\hrulefill} *
{\ % beginning of TeX mode

\input fonts.tex % define fonts
\input title.tex % title and authors

% end of TeX mode}
* {\hrulefill} */


/* {\hrulefill\ pas\_bold.c\ \hrulefill} */
/*{\ In PASCAL, several key words are usually printed in bold face.
Our {\bf src2tex} and {\bf src2latex} print those key words
in bold typewriter fonts if the input file is written in PASCAL. \hfill}*/


#include <stdio.h>
#include "src2tex.h"

extern int *dec_buf_ptr();
extern int *inc_buf_ptr();

/* {\hrulefill\ table of key words of PASCAL\ \hrulefill} */
/* {\rm If input source file is written in PASCAL, then
the following words are printed in bold face.\hfill}*/

char *PAS_Table[] =
{"absolute", "and", "array",
 "begin",
 "case", "const",
 "define", "div", "downto", "do",
 "else", "end", "external",
 "file", "forward", "for", "function",
 "goto",
 "if", "inline", "in",
 "label", "let",
 "mod",
 "nil", "not",
 "of", "or", "out",
 "packed", "procedure", "program",
 "record", "repeat", "return",
 "set", "shl", "shr", "string",
 "then", "to", "type",
 "until",
 "var",
 "while", "with",
 "xor",
 ""};


/* {\hrulefill\ compare two words\ \hrulefill} */
/* {\rm This function compares two strings

\smallskip
\qquad{\tt buf\_ptr}={\sl string1},\ {\tt tbl\_ptr}={\sl string2}
\smallskip

\noindent
and returns

\smallskip
$\qquad\displaystyle{\tt flag}\cases{
	=0 &if {\sl string1=string2}\cr
	\not=0 &otherwise\ .\cr}$
\smallskip

\noindent
However, compare\_word() is slightly different from strcmp().
\hfill}*/

int compare_word(buf_ptr, tbl_ptr)
int *buf_ptr;
char *tbl_ptr;
{
    char c;
    int *ptr, flag = 0;

    /* {\ if the previous character is either an
       alphabet or a number, then returns -1 \hfill} */
    ptr = dec_buf_ptr(buf_ptr);
    c = *ptr;
    if ((c >= '0') && (c <= '9'))
	return (-1);
    if ((c >= 'A') && (c <= 'Z'))
	return (-1);
    if ((c >= 'a') && (c <= 'z'))
	return (-1);
    if (c == '_')
      return (-1);
    /* flag $\not=0$ if two strings are different {\hfill} */
    /* flag = 0 otherwise {\hfill} */
    ptr = buf_ptr;
    while (*tbl_ptr != '\0')
      {
	  c = *ptr;
	  /* upper case -> lower case {\hfill} */
	  if ((c >= 'A') && (c <= 'Z'))
	      c += 0x20;
	  flag = c - *tbl_ptr;
	  if (flag != 0)
	      break;
	  ptr = inc_buf_ptr(ptr);
	  ++tbl_ptr;
      }
    /* {\ if the next character is either an
       alphabet or a number, then returns -1 \hfill} */
    c = *ptr;
    if ((c >= '0') && (c <= '9'))
	return (-1);
    if ((c >= 'A') && (c <= 'Z'))
	return (-1);
    if ((c >= 'a') && (c <= 'z'))
	return (-1);
    if (c == '_')
      return (-1);
    return flag;
}


/* {\hrulefill\ get bold face flag\ \hrulefill} */
/* {\rm This function compares a string

\smallskip
\qquad{\tt buf\_ptr}={\sl string}
\smallskip

\noindent
with key words stored in {\tt PAS\_Table[]}.
If there exists a key word which is equal to given {\sl string},
then it returns the length of {\sl string}.\hfill}*/

int get_bf_flag(buf_ptr)
int *buf_ptr;
{
    char **table, *ptr;
    int i = 0;

    for (table = PAS_Table; **table != '\0'; ++table)
      {
	if (compare_word(buf_ptr, *table) == 0)
	  {
#ifdef DEBUGGING
	    printf("compare_word(): ");
	    printf("a reserved word \"%s\" is found in PAS_table\n", *table);
#endif
	    /* strlen(*table) {\hfill} */
	    for (i= 0, ptr = *table; *ptr != '\0'; ++i, ++ptr);
	    break;
	  }
      }
    return i;
}

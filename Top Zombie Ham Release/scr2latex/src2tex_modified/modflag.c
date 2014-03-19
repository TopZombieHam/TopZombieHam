/* {\hrulefill} *
{\ % beginning of TeX mode

\input fonts.tex % define fonts
\input title.tex % title and authors

% end of TeX mode}
* {\hrulefill} */


/* {\hrulefill\ modflag.c\ \hrulefill} */


#include <stdio.h>
#include "src2tex.h"

extern int BAS_flag;
extern int C_flag;
extern int CBL_flag;
extern int F77_flag;
extern int HTML_flag;
extern int JAVA_flag;
extern int LISP_flag;
extern int MAKE_flag;
extern int PAS_flag;
extern int PERL_flag;
extern int SH_flag;
extern int TCL_flag;

extern int MAC_flag;
extern int MAP_flag;
extern int MAT_flag;
extern int MLAB_flag;
extern int MPAD_flag;
extern int RED_flag;

extern int *dec_buf_ptr();
extern int *inc_buf_ptr();
extern void set_lang_flag();


/* {\hrulefill\ get comment flag\ \hrulefill} */
/* {\rm When {\tt stat\_flag}$=0$, the function {\tt get\_comment\_flag()}
increases {\tt stat\_flag} first and determines language type
by using functions

\smallskip

\qquad
{\tt set\_bas\_flag()}, {\tt set\_c\_flag()}, {\tt set\_f77\_flag()},
	{\tt set\_lisp\_flag()}, {\tt set\_pas\_flag()}, etc.

\smallskip

\noindent
For instance, if input file is written in C, then language flags
{\tt BAS\_flag}, {\tt C\_flag}, {\tt F77\_flag},
	{\tt LISP\_flag}, {\tt PAS\_flag}, {\it etc\/\ }
are set as follows:

\smallskip

$\qquad\displaystyle
	{\tt BAS\_flag}=0, {\tt C\_flag}=1, {\tt F77\_flag}=0,
	{\tt LISP\_flag}=0, {\tt PAS\_flag}=0\ , \cdots .$

\smallskip

\noindent
In the main part of function {\tt get\_comment\_flag()},
the procedure is branched into five cases.
In each case, comment flag {\tt com\_flag} is set to 1,
{\it i.e.\/}, {\tt com\_flag}$=1$,
if and only if integer pointer {\tt buf\_ptr} points a character of
comment area of source program.

$\qquad\displaystyle
{\tt com\_flag}=\cases{
	1 &if {\tt buf\_ptr} points a character of comment area\cr
	0 &otherwise\ .\cr}$

\noindent
As is easily seen, it is not so difficult to distinguish comment area
from program area, if language type is determined in advance. \hfill} */

int get_comment_flag(buf_ptr)
int *buf_ptr;
{
    static int stat_flag = 0;		/* {\ status flag \hfill} */
    static int paren_counter = 0;	/* {\ parentheses counter \hfill} */
    static int brace_counter = 0;	/* {\ brace counter \hfill} */
    static int com_flag = 0;		/* {\ comment flag \hfill} */
    static int char_counter = 0;	/* {\ character counter \hfill} */
    static int qt_counter = 0;		/* {\ single quotation counter
					   \hfill} */
    static int bqt_counter = 0;		/* {\ back quotation counter
					   \hfill} */
    static int dqt_counter = 0;		/* {\ double quotation counter
					   \hfill} */
    static int slash_counter = 0;	/* {\ slash counter \hfill} */
    static int rgx_counter = 0;		/* {\ regular expression counter
					   \hfill} */
    static int warn_flag = 0;		/* {\ warning flag \hfill} */
    int *ptr;
    char c_2, c_1, c0, c1, c2, c3, c4, c5, c6;

    /* {\ determine language \hfill} */
    if (stat_flag == 0)
      {
	  ++stat_flag;
	  set_lang_flag(buf_ptr);
      }
    /* {\ get a neighborhood of buf\_ptr \hfill} */
    ptr = dec_buf_ptr(buf_ptr);
    c_1 = *ptr;
    ptr = dec_buf_ptr(ptr);
    c_2 = *ptr;
    c0 = *buf_ptr;
    ptr = inc_buf_ptr(buf_ptr);
    c1 = *ptr;
    ptr = inc_buf_ptr(ptr);
    c2 = *ptr;
    ptr = inc_buf_ptr(ptr);
    c3 = *ptr;
    ptr = inc_buf_ptr(ptr);
    c4 = *ptr;
    ptr = inc_buf_ptr(ptr);
    c5 = *ptr;
    ptr = inc_buf_ptr(ptr);
    c6 = *ptr;
    /* {\ set comment flag of BASIC \hfill} */
    if (BAS_flag == 1)
      {
	if ((c0 == '"') && (com_flag == 0))
	  {
	    ++dqt_counter;
	    dqt_counter %= 2;
	  }
	if (dqt_counter == 0)
	  {
	    if ((com_flag == 1) && (c_1 == '\n'))
	      com_flag = 0;
	    if (char_counter == 0)
	      {
		if ((com_flag == 0) && (c_1 <= ' ') && (c0 == 0x27))
		  {
		    com_flag = 1;
		    if ((c1 == '{') && (c2 == '\\') & (c3 == ' '))
		      *buf_ptr = ' ';
		  }
		if ((com_flag == 0) && (c_1 <= ' ')
		    && ((c0 == 'R') || (c0 == 'r'))
		    && ((c1 == 'E') || (c1 == 'e'))
		    && ((c2 == 'M') || (c2 == 'm')))
		  com_flag = 1;
	      }
	  }
	if (c0 == '\n')
	  char_counter = 0;
	else
	  {
	    if (char_counter != 0)
	      ++char_counter;
	    else
	      if ((c0 > '9') || ((c0 > ' ') && (c0 < '0')))
		++char_counter;
	  }
	return com_flag;
      }
    /* {\ set comment flag of C or MACSYMA\hfill} */
    if ((C_flag == 1) || (MAC_flag == 1))
      {
	if ((((c_2 == '\\') && (c_1 == '\\')) || (c_1 != '\\'))
	    && (c0 == '"')
	    && ((c_1 != 0x27) || (c1 != 0x27)) && (com_flag == 0))
	  {
	    ++dqt_counter;
	    dqt_counter %= 2;
	  }
	if (dqt_counter == 0)
	  {
	    if ((com_flag == 1) && (c_2 == '*') && (c_1 == '/'))
	      com_flag = 0;
	    if ((com_flag == 3) && ( c_1 == '\n'))
	      com_flag = 0;
	    if ((com_flag == 0) && (c0 == '/') && (c1 == '*'))
	      com_flag = 1;
	    if ((com_flag == 0) && (c0 == '/') && (c1 == '/'))
	      com_flag = 3;
	  }
	return (com_flag % 2);
      }
    /* {\ set comment flag of COBOL \hfill} */
    if (CBL_flag == 1)
      {
	if ((com_flag == 1) && (char_counter == 0)
	    && (c_1 == '\n'))
	  com_flag = 0;
	if ((com_flag == 0) && (char_counter == 0)
	    && ((c6 == '*') || (c6 == '/')))
	  com_flag = 1;
	if (c0 == '\n')
	  char_counter = 0;
	else
	  ++char_counter;
	return com_flag;
      }
    /* {\ set comment flag of FORTRAN \hfill} */
    if (F77_flag == 1)
      {
	if ((c0 == 0x27) && (com_flag == 0))
	  {
	    ++qt_counter;
	    qt_counter %= 2;
	  }
	if (qt_counter == 0)
	  {
	    if((com_flag == 1) && ((c_1 == '\r') || (c_1 == '\n')))
	      com_flag = 0;
	    if ((com_flag == 1)
		&& ((c_1 == 'C') || (c_1 == 'c') || (c_1 == '*'))
		&& ((c0 == '\r') || (c0 == '\n')))
	      com_flag = 0;
	    if (char_counter == 0)
	      {
		if ((com_flag == 0) && ((c0 == 'C') || (c0 == 'c')))
		  com_flag = 1;
		if ((com_flag == 0) && (c0 == '*'))
		  {
		    com_flag = 1;
		    if ((c1 == '{') && (c2 == '\\') & (c3 == ' '))
		      *buf_ptr = ' ';
		  }
	      }
	  }
	if (c0 == '\n')
	  char_counter = 0;
	else
	  ++char_counter;
	return com_flag;
      }
    /* {\ set comment flag of HTML \hfill} */
    if (HTML_flag == 1)
      {
	if ((((c_2 == '\\') && (c_1 == '\\')) || (c_1 != '\\'))
	    && (c0 == '"')
	    && ((c_1 != 0x27) || (c1 != 0x27)) && (com_flag == 0))
	  {
	    ++dqt_counter;
	    dqt_counter %= 2;
	  }
	if (dqt_counter == 0)
	  {
	    if ((com_flag == 1) && (c_2 == '-') && (c_1 == '>'))
	      com_flag = 0;
	    if ((com_flag == 0)
		&& (c0 == '<') && (c1 == '!') && (c2 = '-'))
	      com_flag = 1;
	  }
	return com_flag;
      }
    /* {\ set comment flag of JAVA \hfill} */
    if (JAVA_flag == 1)
      {
	if ((((c_2 == '\\') && (c_1 == '\\')) || (c_1 != '\\'))
	    && (c0 == '"')
	    && ((c_1 != 0x27) || (c1 != 0x27)) && (com_flag == 0))
	  {
	    ++dqt_counter;
	    dqt_counter %= 2;
	  }
	if (dqt_counter == 0)
	  {
	    if ((com_flag == 1) && (c_2 == '*') && (c_1 == '/'))
	      com_flag = 0;
	    if ((com_flag == 3) && ( c_1 == '\n'))
	      com_flag = 0;
	    if ((com_flag == 0) && (c0 == '/') && (c1 == '*'))
	      com_flag = 1;
	    if ((com_flag == 0) && (c0 == '/') && (c1 == '/'))
	      com_flag = 3;
	  }
	return (com_flag % 2);
      }
    /* {\ set comment flag of LISP \hfill} */
    if (LISP_flag == 1)
      {
	if ((c0 == '"') && (com_flag == 0))
	  {
	    ++dqt_counter;
	    dqt_counter %= 2;
	  }
	if (dqt_counter == 0)
	  {
	    if ((com_flag == 1) && ( c_1 == '\n'))
	      com_flag = 0;
	    if ((com_flag == 0) && (c0 == ';'))
	      {
		com_flag = 1;
		if ((c1 == '{') && (c2 == '\\') & (c3 == ' '))
		  *buf_ptr = ' ';
	      }
	  }
	return com_flag;
      }
    /* {\ set comment flag of MAKE \hfill} */
    if (MAKE_flag == 1)
      {
	if ((c0 == 0x27) && (com_flag == 0)
	    && (bqt_counter == 0) && (dqt_counter == 0))
	  {
	    ++qt_counter;
	    qt_counter %= 2;
	  }
	if ((c0 == 0x60) && (com_flag == 0)
	    && (qt_counter == 0) && (dqt_counter == 0))
	  {
	    ++bqt_counter;
	    bqt_counter %= 2;
	  }
	if ((c0 == '"') && (com_flag == 0)
	    && (qt_counter == 0) && (bqt_counter == 0))
	  {
	    ++dqt_counter;
	    dqt_counter %= 2;
	  }
	if ((qt_counter == 0) && (bqt_counter == 0) && (dqt_counter == 0))
	  {
	    if ((com_flag == 1)
		&& (c_2 != '\\') && ((c_1 == '\r') || (c_1 == '\n')))
	      com_flag = 0;
	    if ((com_flag == 1)
		&& (c_1 == '#') && ((c0 == '\r') || (c0 == '\n')))
	      com_flag = 0;
	    if ((com_flag == 0)
		&& (c0 == '#'))
	      {
		com_flag = 1;
		if ((c1 == '{') && (c2 == '\\') & (c3 == ' '))
		  *buf_ptr = ' ';
	      }
	  }
	return com_flag;
      }
    /* {\ set comment flag of MuPAD \hfill} */
    if (MPAD_flag == 1)
      {
	if ((c0 == 0x27) && (com_flag == 0)
	    && (bqt_counter == 0) && (dqt_counter == 0))
	  {
	    ++qt_counter;
	    qt_counter %= 2;
	  }
	if ((c0 == 0x60) && (com_flag == 0)
	    && (qt_counter == 0) && (dqt_counter == 0))
	  {
	    ++bqt_counter;
	    bqt_counter %= 2;
	  }
	if ((c0 == '"') && (com_flag == 0)
	    && (qt_counter == 0) && (bqt_counter == 0))
	  {
	    ++dqt_counter;
	    dqt_counter %= 2;
	  }
	if ((qt_counter == 0) && (bqt_counter == 0) && (dqt_counter == 0))
	  {
	    if ((com_flag == 1)
		&& (c_1 != '\\') && (c0 == '#'))
	      com_flag = 0;
	    if ((com_flag == 0)
		&& ((c_1 <= 0x20) || (c_1 == ';')) && (c0 == '#'))
	      com_flag = 1;
	  }
	return com_flag;
      }
    /* {\ set comment flag of PASCAL \hfill} */
    if (PAS_flag == 1)
      {
	if ((c0 == 0x27) && (com_flag == 0))
	  {
	    ++qt_counter;
	    qt_counter %= 2;
	  }
	  if ((qt_counter == 0) && (c_1 != '\\') && (c0 == '{'))
	    ++brace_counter;
	  if ((qt_counter == 0) && (c_1 != '\\') && (c0 == '}'))
	    --brace_counter;
	if (qt_counter == 0)
	  {
	    if ((brace_counter == 0) && (com_flag == 1) && (c_1 == '}'))
	      com_flag = 0;
	    if ((brace_counter == 1) && (com_flag == 0) && (c0 == '{'))
	      com_flag = 1;
	    if ((com_flag == 3) && (c_2 == '*') && (c_1 == ')'))
	      com_flag = 0;
	    if ((com_flag == 0) && (c0 == '(') && (c1 == '*'))
	      com_flag = 3;
	  }
	return (com_flag % 2);
      }
    /* {\ set comment flag of PERL \hfill} */
    if (PERL_flag == 1)
      {
	if ((((c_2 != '$') && (c_1 == 'm') && (c0 == '!'))
	     || ((c_1 != '\\') && (c0 == '?')))
	    && (com_flag == 0) && (rgx_counter == 0)
	    && (paren_counter == 0) && (brace_counter == 0)
	    && (qt_counter == 0) && (bqt_counter == 0)
	    && (dqt_counter == 0) && (slash_counter == 0))
	    ++rgx_counter;
	if ((c_1 != '\\') && ((c0 == '!') || (c0 == '?'))
	    && (com_flag == 0) && (rgx_counter == 1)
	    && (paren_counter == 0) && (brace_counter == 0)
	    && (qt_counter == 0) && (bqt_counter == 0)
	    && (dqt_counter == 0) && (slash_counter == 0))
	    --rgx_counter;
	if ((c_1 != '\\') && ((c0 == '(') || (c0 == ')'))
	    && (com_flag == 0) && (rgx_counter == 0)
	    && (brace_counter == 0) 
	    && (qt_counter == 0) && (dqt_counter == 0)
	    && (bqt_counter == 0) && (slash_counter == 0))
	  {
	    ++paren_counter;
	    paren_counter %= 2;
	  }
	if ((c_1 != '\\') && (c0 == '{')
	    && (((c_1 >= 'A') && (c_1 <= 'Z'))
		|| ((c_1 >= 'a') && (c_1 <= 'z')))
	    && (com_flag == 0) && (rgx_counter == 0)
	    && (paren_counter == 0) && (brace_counter == 0)
	    && (qt_counter == 0) && (bqt_counter == 0)
	    && (dqt_counter == 0) && (slash_counter == 0))
	  ++brace_counter;
	if ((c_1 != '\\') && (c0 == '}')
	    && (com_flag == 0) && (rgx_counter == 0)
	    && (paren_counter == 0) && (brace_counter == 1)
	    && (qt_counter == 0) && (bqt_counter == 0)
	    && (dqt_counter == 0) && (slash_counter == 0))
	  --brace_counter;
	if ((c_1 != '\\') && (c0 == 0x27)
	    && (com_flag == 0) && (rgx_counter == 0)
	    && (paren_counter == 0) && (brace_counter == 0)
	    && (bqt_counter == 0)
	    && (dqt_counter == 0) && (slash_counter == 0))
	  {
	    ++qt_counter;
	    qt_counter %= 2;
	  }
	if ( (((c_1 == 'q') && (c0 == '|'))
	      || ((c_1 != '\\') && (c0 == '|')))
	    && (com_flag == 0) && (rgx_counter == 0)
	    && (paren_counter == 0) && (brace_counter == 0)
	    && (bqt_counter == 0)
	    && (dqt_counter == 0) && (slash_counter == 0))
	  {
	    qt_counter += 2;
	    qt_counter %= 4;
	  }
	if ((c_1 != '\\') && (c0 == 0x60)
	    && (com_flag == 0) && (rgx_counter == 0)
	    && (paren_counter == 0) && (brace_counter == 0)
	    && (qt_counter == 0) && (bqt_counter == 0)
	    && (dqt_counter == 0) && (slash_counter == 0))
	  bqt_counter = 1;
	if ((c_1 != '\\') && (c0 == 0x60)
	    && (com_flag == 0) && (rgx_counter == 0)
	    && (paren_counter == 0) && (brace_counter == 0)
	    && (qt_counter == 0) && (bqt_counter == 1)
	    && (dqt_counter == 0) && (slash_counter == 0))
	  bqt_counter = 0;
	if ((c_1 != '\\') && (c0 == '"')
	    && (com_flag == 0) && (rgx_counter == 0)
	    && (paren_counter == 0) && (brace_counter == 0)
	    && (qt_counter == 0) && (bqt_counter == 0)
	    && (slash_counter == 0))
	  {
	    ++dqt_counter;
	    dqt_counter %= 2;
	  }
	if ((c_1 == ' ') && (c0 == '/')
	    && (com_flag == 0) && (rgx_counter == 0)
	    && (paren_counter == 0) && (brace_counter == 0)
	    && (qt_counter == 0) && (bqt_counter == 0)
	    && (dqt_counter == 0) && (slash_counter == 0))
	  slash_counter = 2;
	if ((c_2 != '$') && ((c_1 >= 'a') && (c_1 <= 'z')) && (c0 == '/')
	    && (com_flag == 0) && (rgx_counter == 0)
	    && (paren_counter == 0) && (brace_counter == 0)
	    && (qt_counter == 0) && (bqt_counter == 0)
	    && (dqt_counter == 0) && (slash_counter == 0))
	  slash_counter = 3;
	if ((((c_1 != '\\') || ((c_2 == '\\') && (c_1 == '\\')))
	     && (c0 == '/'))
	    && (com_flag == 0) && (rgx_counter == 0)
	    && (paren_counter == 0) && (brace_counter == 0)
	    && (qt_counter == 0) && (bqt_counter == 0)
	    && (dqt_counter == 0) && (slash_counter != 0))
	  --slash_counter;
	if ((rgx_counter == 0)
	    && (paren_counter == 0) && (brace_counter == 0)
	    && (qt_counter == 0) && (bqt_counter == 0)
	    && (dqt_counter == 0) && (slash_counter == 0))
	  {
/*
	    if ((com_flag == 1)
		&& (c_2 != '\\') && ((c_1 == '\r') || (c_1 == '\n')))
	      com_flag = 0;
*/
	    if ((com_flag == 1)
		&& ((c_1 == '\r') || (c_1 == '\n')))
	      com_flag = 0;
	    if ((com_flag == 1)
		&& (c_1 == '#') && ((c0 == '\r') || (c0 == '\n')))
	      com_flag = 0;
	    if ((com_flag == 0)
		&& (rgx_counter == 0)
		&& (paren_counter == 0) && (brace_counter == 0)
		&& (qt_counter == 0) && (bqt_counter == 0)
		&& (dqt_counter == 0) && (slash_counter == 0)
		&& ((stat_flag++ == 1)
		    || (c_1 == '\t') || (c_1 == '\n')
		    || (c_1 == ' ') || (c_1 == ';'))
		&& (c0 == '#'))
	      {
		com_flag = 1;
		if ((c1 == '{') && (c2 == '\\') & (c3 == ' '))
		  *buf_ptr = ' ';
	      }
	  }
	if (c0 == '\n')
	  char_counter = 0;
	else
	  ++char_counter;
	return com_flag;
      }
    /* {\ set comment flag of SHELL \hfill} */
    if (SH_flag == 1)
      {
	if ((c0 == 0x27) && (com_flag == 0)
	    && (bqt_counter == 0) && (dqt_counter == 0))
	  {
	    ++qt_counter;
	    qt_counter %= 2;
	  }
	if ((c0 == 0x60) && (com_flag == 0)
	    && (qt_counter == 0) && (dqt_counter == 0))
	  {
	    ++bqt_counter;
	    bqt_counter %= 2;
	  }
	if ((c0 == '"') && (com_flag == 0)
	    && (qt_counter == 0) && (bqt_counter == 0))
	  {
	    ++dqt_counter;
	    dqt_counter %= 2;
	  }
	if ((qt_counter == 0) && (bqt_counter == 0) && (dqt_counter == 0))
	  {
	    if ((com_flag == 1)
		&& (c_2 != '\\') && ((c_1 == '\r') || (c_1 == '\n')))
	      com_flag = 0;
	    if ((com_flag == 1)
		&& (c_1 == '#') && ((c0 == '\r') || (c0 == '\n')))
	      com_flag = 0;
	    if ((com_flag == 0)
		&& (c_1 != '$') && (c0 == '#'))
	      {
		com_flag = 1;
		if ((c1 == '{') && (c2 == '\\') & (c3 == ' '))
		  *buf_ptr = ' ';
	      }
	  }
	return com_flag;
      }
    /* {\ set comment flag of TCL/TK \hfill} */
    if (TCL_flag == 1)
      {
	if ((c0 == 0x27) && (com_flag == 0)
	    && (bqt_counter == 0) && (dqt_counter == 0))
	  {
	    ++qt_counter;
	    qt_counter %= 2;
	  }
	if ((c0 == 0x60) && (com_flag == 0)
	    && (qt_counter == 0) && (dqt_counter == 0))
	  {
	    ++bqt_counter;
	    bqt_counter %= 2;
	  }
	if ((c0 == '"') && (com_flag == 0)
	    && (qt_counter == 0) && (bqt_counter == 0))
	  {
	    ++dqt_counter;
	    dqt_counter %= 2;
	  }
	if ((qt_counter == 0) && (bqt_counter == 0) && (dqt_counter == 0))
	  {
	    if ((com_flag == 1)
		&& (c_2 != '\\') && ((c_1 == '\r') || (c_1 == '\n')))
	      com_flag = 0;
	    if ((com_flag == 1)
		&& (c_1 == '#') && ((c0 == '\r') || (c0 == '\n')))
	      com_flag = 0;
	    if ((com_flag == 0)
		&& (c0 == '#'))
	      {
		com_flag = 1;
		if ((c1 == '{') && (c2 == '\\') & (c3 == ' '))
		  *buf_ptr = ' ';
	      }
	  }
	return com_flag;
      }
    /* {\ set comment flag of MAPLE \hfill} */
    if (MAP_flag == 1)
      {
	if ((com_flag == 0)
	    && (c_1 != 0x27) && (c0 == 0x27) && (c1 != 0x27))
	  {
	    ++qt_counter;
	    qt_counter %= 2;
	  }
	if (qt_counter == 0)
	  {
	    if ((com_flag == 1)
		&& (c_2 != '\\') && ((c_1 == '\r') || (c_1 == '\n')))
	      com_flag = 0;
	    if ((com_flag == 1)
		&& (c_1 == '#') && ((c0 == '\r') || (c0 == '\n')))
	      com_flag = 0;
	    if ((com_flag == 0)
		&& (c0 == '#'))
	      {
		com_flag = 1;
		if ((c1 == '{') && (c2 == '\\') & (c3 == ' '))
		  *buf_ptr = ' ';
	      }
	  }
	return com_flag;
      }
    /* {\ set comment flag of MATHEMATICA \hfill} */
    if (MAT_flag == 1)
      {
	if ((c0 == '"') && (com_flag == 0))
	  {
	    ++dqt_counter;
	    dqt_counter %= 2;
	  }
	if (dqt_counter == 0)
	  {
	    if ((com_flag == 1) && (c_2 == '*') && (c_1 == ')'))
	      com_flag = 0;
	    if ((com_flag == 0) && (c0 == '(') && (c1 == '*'))
	      com_flag = 1;
	  }
	return com_flag;
      }
    /* {\ set comment flag of MATLAB \hfill} */
    if (MLAB_flag == 1)
      {
	if ((c0 == 0x27) && (qt_counter == 1))
	  qt_counter = 0;
	if (((c_1 < '0') || ((c_1 > '9') && (c_1 < 'A'))
	     || ((c_1 > 'Z') && (c_1 < 'a')) || (c_1 > 'z'))
	    && (c_1 != '\\') && (c_1 != '.')
	    && (c_1 != ')') && (c_1 != ']')
	    && (c0 == 0x27) && (com_flag == 0))
	  qt_counter = 1;
	if ((c_1 != '\\') && (c0 == '"') && (com_flag == 0))
	  {
	    ++dqt_counter;
	    dqt_counter %= 2;
	  }
	if ((qt_counter == 0) && (dqt_counter == 0))
	  {
	    if ((com_flag == 1) && ( c_1 == '\n'))
	      com_flag = 0;
	    if ((com_flag == 0) && ((c0 == '#') || (c0 == '%')))
	      {
		com_flag = 1;
		if ((c1 == '{') && (c2 == '\\') & (c3 == ' '))
		  *buf_ptr = ' ';
	      }
	  }
	return com_flag;
      }
    /* {\ set comment flag of REDUCE \hfill} */
    if (RED_flag == 1)
      {
	if ((c0 == '"') && (com_flag == 0))
	  {
	    ++dqt_counter;
	    dqt_counter %= 2;
	  }
	if (dqt_counter == 0)
	  {
	    if ((com_flag == 1) && ( c_1 == '\n'))
	      com_flag = 0;
	    if ((com_flag == 0) && (c0 == '%'))
	      {
		com_flag = 1;
		if ((c1 == '{') && (c2 == '\\') & (c3 == ' '))
		  *buf_ptr = ' ';
	      }
	    if ((com_flag == 3) && (c_1 == ';'))
	      com_flag = 0;
	    if ((com_flag == 0)
		&& ((c0 == 'C') || (c0 == 'c'))
		&& ((c1 == 'O') || (c1 == 'o'))
		&& ((c2 == 'M') || (c2 == 'm'))
		&& ((c3 == 'M') || (c3 == 'm'))
		&& ((c4 == 'E') || (c4 == 'e'))
		&& ((c5 == 'N') || (c5 == 'n'))
		&& ((c6 == 'T') || (c6 == 't')))
	      com_flag = 3;
	  }
	return (com_flag % 2);
      }
    return com_flag;
}


/* {\hrulefill\ get {\TeX} mode flag\ \hrulefill} */
/* {\rm This function sets math flag {\tt math\_flag} and
escape flag {\tt esc\_flag} as follows:

$\qquad\displaystyle
{\tt math\_flag}\cases{
	\not=0 &if {\tt buf\_ptr} points between \$ and \$
	  \quad(or\ $\backslash$( and $\backslash$)\ )\cr
	\not=0 &if {\tt buf\_ptr} points between \$\$ and \$\$
	  \quad(or\ $\backslash$[ and $\backslash$]\ )\cr
	=0 &otherwise\ ,\cr}$

\smallskip

$\qquad\displaystyle
{\tt esc\_flag}\kern.62em \cases{
	\not=0 &if {\tt buf\_ptr} points between $\{\backslash$ and $\}$\cr
	=0 &otherwise\ .\cr}$

\noindent
And it returns

\qquad
{\tt tex\_flag} = {\tt ((maht\_flag != 0) | (esc\_flag != 0))}

\noindent
at the last stage.\hfill} */

int get_tex_flag(buf_ptr)
int *buf_ptr;
{
    static int math_flag = 0;		/* {\ math flag \hfill} */
    static int ds_flag = 0;		/* {\ display math flag \hfill} */
    static int esc_flag = 0;		/* {\ escape from quasi-TeX flag
					 \hfill} */
    static int rcs_flag = 0;		/* {\ RCS flag \hfill} */
    static int brace_counter = 0;	/* {\ brace counter \hfill} */
    char a[4], b[10];			/* {\ mini buffer a[3]...a[0]=
					   b[0]...b[9] \hfill} */
    char c0, c1, c2;
    int i, *ptr, *ptr1, *ptr2, tex_flag, tex_counter;

    /* {\ unset math\_flag and esc\_flag (\TeX$\to$quasi-\TeX) \hfill} */
    ptr = buf_ptr;
    a[0] = *ptr;
    ptr = dec_buf_ptr(ptr);
    a[1] = *ptr;
    ptr = dec_buf_ptr(ptr);
    a[2] = *ptr;
    ptr = dec_buf_ptr(ptr);
    a[3] = *ptr;
#ifdef LATEX
    if (rcs_flag != 0)			/* {\ reset RCS flag \hfill} */
      if ((a[2] != '\\') && (a[2] != '$')
	  && (a[1] == '$') && (a[0] != '$'))
	--rcs_flag;
    if (math_flag != 0)			/* {\ reset LaTeX math flag \hfill} */
      {
	if (ds_flag == 0)
	  {
	    if ((a[1] == '$') && (a[0] != '$'))
	      if ((a[2] != '\\') && (a[2] != '$'))
		--math_flag;
	    if ((a[2] == '\\') && (a[1] == ')'))
	      math_flag = 0;
	  }
	else
	  {
	    if ((a[2] == '\\') && (a[1] == ']'))
	      {
		math_flag = 0;
		ds_flag = 0;
	      }
	  }
      }
#else
    if (rcs_flag != 0)			/* {\ reset RCS flag \hfill} */
      if ((a[2] != '\\') && (a[2] != '$')
	  && (a[1] == '$') && (a[0] != '$'))
	--rcs_flag;
    if (math_flag != 0)			/* {\ reset TeX math flag \hfill} */
      {
	  if ((a[1] == '$') && (a[0] != '$'))
	    {
	      if (ds_flag == 0)
		{
		  if ((a[2] != '\\') && (a[2] != '$'))
		    --math_flag;
		}
	      else
		{
		  if ((a[3] != '\\') && (a[3] != '$') && (a[2] == '$'))
		    --math_flag;
		  if (math_flag == 0)
		    ds_flag = 0;
		}
	    }
      }
#endif
    if (esc_flag != 0)
      {
	if ((a[1] != '\\') && (a[0] == '{'))
	  ++brace_counter;
	if ((a[1] != '\\') && (a[0] == '}'))
	  --brace_counter;
	if (esc_flag == 2)
	  {
	    if (brace_counter == 0)
	      {
		if (a[0] != '}')
		  {
		    fprintf(stderr, "\nError: brace counter error !!\n");
		    exit(EXIT_FAILURE);
		  }
		--esc_flag;
		*buf_ptr = ' ';		/* {\ replace a
					   \TeX-mode-end-brace with a space
					   \hfill} */
	      }
	  }
	else
	  --esc_flag;
      }

    /* {\ set math\_flag and esc\_flag (quasi-\TeX$\to$\TeX) \hfill} */
    ptr = buf_ptr;
    b[0] = *ptr;
    ptr = inc_buf_ptr(ptr);
    b[1] = *ptr;
    ptr = inc_buf_ptr(ptr);
    b[2] = *ptr;
    ptr = inc_buf_ptr(ptr);
    b[3] = *ptr;
    ptr = inc_buf_ptr(ptr);
    b[4] = *ptr;
    ptr = inc_buf_ptr(ptr);
    b[5] = *ptr;
    ptr = inc_buf_ptr(ptr);
    b[6] = *ptr;
    ptr = inc_buf_ptr(ptr);
    b[7] = *ptr;
    ptr = inc_buf_ptr(ptr);
    b[8] = *ptr;
    ptr = inc_buf_ptr(ptr);
    b[9] = *ptr;
#ifdef LATEX
    if (math_flag == 0)
      {
	if ((a[1] != '\\') && (a[1] != '$') && (b[0] == '$'))
	  {
	    if (b[1] != '$')	/* {\ check RCS keywords here \hfill} */
	      {
		if ((b[1] == 'A') && (b[2] == 'u') && (b[3] == 't')
		    && (b[4] == 'h') && (b[5] == 'o') && (b[6] == 'r')
		    && ((b[7] == ':') || (b[7] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'D') && (b[2] == 'a') && (b[3] == 't')
		    && (b[4] == 'e')
		    && ((b[5] == ':') || (b[5] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'H') && (b[2] == 'e') && (b[3] == 'a')
		    && (b[4] == 'd') && (b[5] == 'e') && (b[6] == 'r')
		    && ((b[7] == ':') || (b[7] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'I') && (b[2] == 'd')
		    && ((b[3] == ':') || (b[3] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'L') && (b[2] == 'o') && (b[3] == 'c')
		    && (b[4] == 'k') && (b[5] == 'e') && (b[6] == 'r')
		    && ((b[7] == ':') || (b[7] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'L') && (b[2] == 'o') && (b[3] == 'g')
		    && ((b[4] == ':') || (b[4] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'R') && (b[2] == 'e') && (b[3] == 'v')
		    && (b[4] == 'i') && (b[5] == 's') && (b[6] == 'i')
		    && (b[7] == 'o') && (b[8] == 'n')
		    && ((b[9] == ':') || (b[9] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'R') && (b[2] == 'C') && (b[3] == 'S')
		    && (b[4] == 'f') && (b[5] == 'i') && (b[6] == 'l')
		    && (b[7] == 'e')
		    && ((b[8] == ':') || (b[8] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'S') && (b[2] == 'o') && (b[3] == 'n')
		    && (b[4] == 'y') && (b[5] == 'I') && (b[6] == 'd')
		    && ((b[7] == ':') || (b[7] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'S') && (b[2] == 'o') && (b[3] == 'u')
		    && (b[4] == 'r') && (b[5] == 'c') && (b[6] == 'e')
		    && ((b[7] == ':') || (b[7] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'S') && (b[2] == 't') && (b[3] == 'a')
		    && (b[4] == 't') && (b[5] == 'e')
		    && ((b[6] == ':') || (b[6] == '$')))
		  rcs_flag = 2;
	      }
	    if ((BAS_flag == 0) && (PERL_flag == 0))
	      {
		if (b[1] != '$')
		  math_flag = 2;
	      }
	    else		/* {\ else-part takes care of BASIC
				   or PERL string variables \hfill} */
	      {
		if ((BAS_flag != 0)
		    && (b[1] != '$')
		    && ((a[1] < '0') || (a[1] > '9'))
		    && ((a[1] < 'A') || (a[1] > 'Z'))
		    && ((a[1] < 'a') || (a[1] > 'z')))
		  math_flag = 2;
		if ((PERL_flag != 0)
		    && (b[1] != '$')
		    && ((b[1] < 'A') || (b[1] > 'Z'))
		    && ((b[1] < 'a') || (b[1] > 'z')))
		  math_flag = 2;
	      }
	  }
	/* {\ If LaTeX is not used properly, then {\bf src2latex}
	   simply unset math\_flag . \hfill} */
	if ((math_flag != 0)
	    && ((MAKE_flag != 0) || (PERL_flag != 0)
		|| (SH_flag != 0) || (TCL_flag != 0)))
	  {
	    ptr = buf_ptr;
	    tex_counter = 0;
	    for (i = 0; i < (int)(FORMULA_LEN_MAX); ++i)
	      {
		c0 = *ptr;
		ptr1 = inc_buf_ptr(ptr);
		c1 = *ptr1;
		ptr2 = inc_buf_ptr(ptr1);
		c2 = *ptr2;
		if ((c0 == '\n') && (c1 != '#'))
		  break;
		if ((c0 != '\\') && (c1 == '$') && (c2 <= ' '))
		  break;
		if ((c0 == '_') || (c0 == '^') || (c0 == '\\'))
		  ++tex_counter;
		ptr = ptr1;
	      }
	    if (i >= (int)(FORMULA_LEN_MAX))
	      math_flag = 0;
	    if ((c0 == '\n') && (c1 != '#'))
	      math_flag = 0;
	    if ((c0 != '\\') && (c1 == '$') && (c2 <= ' ')
		&& (tex_counter == 0))
	      math_flag = 0;
#ifdef DEBUGGING
	    printf ("get_tex_flag(): math_flag is set to %d\n",
		    math_flag);
#endif
	  }
	if ((b[1] <= ' ') && (b[0] == '\\') && (b[1] == '(')
	    && (((b[2] >= '0') && (b[2] <= '9'))
		|| ((b[2] >= 'a') && (b[2] <= 'z'))
		|| ((b[2] == '\\') && (b[3] >= 'a') && (b[3] <= 'z'))
		|| (b[2] == '{')))
	  math_flag = 2;
	if ((b[1] <= ' ') && (b[0] == '\\') && (b[1] == '[')
	    && (((b[2] >= '0') && (b[2] <= '9'))
		|| ((b[2] >= 'a') && (b[2] <= 'z'))
		|| ((b[2] == '\\') && (b[3] >= 'a') && (b[3] <= 'z'))
		|| (b[2] == '{')))
	  {
	    math_flag = 2;
	    ds_flag = 1;
	  }
      }
#else
    if (math_flag == 0)
      {
	if ((a[1] != '\\') && (a[1] != '$') && (b[0] == '$'))
	  {
	    if (b[1] != '$')	/* {\ check RCS keywords here \hfill} */
	      {
		if ((b[1] == 'A') && (b[2] == 'u') && (b[3] == 't')
		    && (b[4] == 'h') && (b[5] == 'o') && (b[6] == 'r')
		    && ((b[7] == ':') || (b[7] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'D') && (b[2] == 'a') && (b[3] == 't')
		    && (b[4] == 'e')
		    && ((b[5] == ':') || (b[5] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'H') && (b[2] == 'e') && (b[3] == 'a')
		    && (b[4] == 'd') && (b[5] == 'e') && (b[6] == 'r')
		    && ((b[7] == ':') || (b[7] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'I') && (b[2] == 'd')
		    && ((b[3] == ':') || (b[3] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'L') && (b[2] == 'o') && (b[3] == 'c')
		    && (b[4] == 'k') && (b[5] == 'e') && (b[6] == 'r')
		    && ((b[7] == ':') || (b[7] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'L') && (b[2] == 'o') && (b[3] == 'g')
		    && ((b[4] == ':') || (b[4] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'R') && (b[2] == 'e') && (b[3] == 'v')
		    && (b[4] == 'i') && (b[5] == 's') && (b[6] == 'i')
		    && (b[7] == 'o') && (b[8] == 'n')
		    && ((b[9] == ':') || (b[9] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'R') && (b[2] == 'C') && (b[3] == 'S')
		    && (b[4] == 'f') && (b[5] == 'i') && (b[6] == 'l')
		    && (b[7] == 'e')
		    && ((b[8] == ':') || (b[8] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'S') && (b[2] == 'o') && (b[3] == 'u')
		    && (b[4] == 'r') && (b[5] == 'c') && (b[6] == 'e')
		    && ((b[7] == ':') || (b[7] == '$')))
		  rcs_flag = 2;
		if ((b[1] == 'S') && (b[2] == 't') && (b[3] == 'a')
		    && (b[4] == 't') && (b[5] == 'e')
		    && ((b[6] == ':') || (b[6] == '$')))
		  rcs_flag = 2;
	      }
	    if ( (BAS_flag == 0) && (PERL_flag == 0))
	      {
		if (b[1] != '$')
		  math_flag = 2;
	      }
	    else		/* {\ else-part takes care of BASIC
				   or PERL string variables \hfill} */
	      {
		if ((BAS_flag != 0)
		    && (b[1] != '$')
		    && ((a[1] < '0') || (a[1] > '9'))
		    && ((a[1] < 'A') || (a[1] > 'Z'))
		    && ((a[1] < 'a') || (a[1] > 'z')))
		  math_flag = 2;
		if ((PERL_flag != 0)
		    && (b[1] != '$')
		    && ((b[1] < 'A') || (b[1] > 'Z'))
		    && ((b[1] < 'a') || (b[1] > 'z')))
		  math_flag = 2;
	      }
	    /* {\ If TeX is not used properly, then {\bf src2tex}
	       simply unset math\_flag . \hfill} */
	    if ((math_flag != 0)
		&& ((MAKE_flag != 0) || (PERL_flag != 0)
		    || (SH_flag != 0) || (TCL_flag != 0)))
	      {
		ptr = buf_ptr;
		tex_counter = 0;
		for (i = 0; i < (int)(FORMULA_LEN_MAX); ++i)
		  {
		    c0 = *ptr;
		    ptr1 = inc_buf_ptr(ptr);
		    c1 = *ptr1;
		    ptr2 = inc_buf_ptr(ptr1);
		    c2 = *ptr2;
		    if ((c0 == '\n') && (c1 != '#'))
		      break;
		    if ((c0 != '\\') && (c1 == '$') && (c2 <= ' '))
		      break;
		    if ((c0 == '_') || (c0 == '^') || (c0 == '\\'))
		      ++tex_counter;
		    ptr = ptr1;
		  }
		if (i >= (int)(FORMULA_LEN_MAX))
		  math_flag = 0;
		if ((c0 == '\n') && (c1 != '#'))
		  math_flag = 0;
		if ((c0 != '\\') && (c1 == '$') && (c2 <= ' ')
		    && (tex_counter == 0))
		  math_flag = 0;
#ifdef DEBUGGING
		printf ("get_tex_flag(): math_flag is reset to %d\n",
			math_flag);
#endif
	      }
	    if ((b[1] == '$') && (b[2] != '$'))
	      {
		math_flag = 2;
		ds_flag = 1;
	      }
	  }
      }
#endif
    if ((math_flag == 0) && (esc_flag == 0))
      {
	  if ((a[1] != '\\') && (b[0] == '{'))
	    {
		if ((b[1] == '\\') || ((b[1] == '{') && (b[2] == '\\')))
		  {
		      brace_counter = 1;
		      esc_flag = 2;
		      *buf_ptr = ' ';	/* {\ replace a
					   \TeX-mode-start-brace
					   with a space \hfill} */
		  }
		if ((b[1] == '\\') && (b[2] == ' '))
		  {
		    /* {\ replace a \TeX-mode-start-backslash
		       with a blank space \hfill} */
		    ptr = inc_buf_ptr(buf_ptr);
		    *ptr = '{';
		    ptr = inc_buf_ptr(ptr);
		    *ptr = '}';
		  }
		if ((b[1] == '{') && (b[2] == '\\') && (b[3] == ' '))
		  {
		    /* {\ replace a \TeX-mode-start-backslash
		       with a blank space \hfill} */
		    ptr = inc_buf_ptr(buf_ptr);
		    ptr = inc_buf_ptr(ptr);
		    *ptr = '{';
		    ptr = inc_buf_ptr(ptr);
		    *ptr = '}';
		  }
	    }
      }
    if (rcs_flag != 0)
      tex_flag = (esc_flag != 0);
    else
      tex_flag = ((math_flag != 0) | (esc_flag != 0));
    return tex_flag;
}

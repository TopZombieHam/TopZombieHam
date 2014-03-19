/* {\hrulefill} *
{\ % beginning of TeX mode

\input fonts.tex % define fonts
\input title.tex % title and authors

% end of TeX mode}
* {\hrulefill} */


/* {\hrulefill\ options.c\ \hrulefill} */


#include <stdio.h>
#include "src2tex.h"

extern int *inc_buf_ptr();
extern int *dec_buf_ptr();

int Htab_Size = HTAB_SKIP;		/*{\ horizontal tabulation skip
					  amount \hfill} */
int Vtab_Size = VTAB_SKIP;		/*{\ vertical tabulation skip
					  amount \hfill} */
#ifdef ASCII
/* {\ ASCII J\TeX \hfill} */
char Bold[] = "\\bf\\gt ";		/* bold type {\hfill} */
char Italic[] = "\\it\\mc ";		/* italic type {\hfill} */
char Roman[] = "\\rm\\mc ";		/* roman type {\hfill} */
char SmallCaps[] = "\\sc\\gt ";		/* small caps type {\hfill} */
char Slant[] = "\\sl\\mc ";		/* slanted type {\hfill} */
char Typewriter[] = "\\tt\\mc ";	/* typewriter type {\hfill} */
#else
#ifdef NTT
/* {\ NTT J\TeX \hfill} */
char Bold[] = "\\bf\\dg ";		/* bold type {\hfill} */
char Italic[] = "\\it\\dm ";		/* italic type {\hfill} */
char Roman[] = "\\rm\\dm ";		/* roman type {\hfill} */
char SmallCaps[] = "\\sc\\dg ";		/* small caps type {\hfill} */
char Slant[] = "\\sl\\dm ";		/* slanted type {\hfill} */
char Typewriter[] = "\\tt\\dm ";	/* typewriter type {\hfill} */
#else
/* {\ \TeX \hfill} */
char Bold[] = "\\bf ";			/* bold type {\hfill} */
char Italic[] = "\\it ";		/* italic type {\hfill} */
char Roman[] = "\\rm ";			/* roman type {\hfill} */
char SmallCaps[] = "\\sc ";		/* small caps type {\hfill} */
char Slant[] = "\\sl ";			/* slanted type {\hfill} */
char Typewriter[] = "\\tt ";		/* typewriter type {\hfill} */
#endif
#endif
char *TextModeFont = Typewriter;	/* text mode font {\hfill} */
char *TeXModeFont = Roman;		/*{\ quasi-\TeX\ and \TeX\ mode
					   font \hfill} */


/* {\hrulefill\ string comparison\ \hrulefill} */
/* {\ Like {\tt strcmp()}, this function {\tt str\_cmp()}
compares two strings stored at integer pointer {\tt iptr}
and character pointer {\tt cptr}.
{\tt Str\_cmp()} returns 0 if and only if given two strings are identical.
\hfill} */

int str_cmp(iptr, cptr)
int  *iptr;
char *cptr;
{
  while ((char)*iptr == *cptr)
    {
      if (*(cptr + 1) == '\0')
	break;
      iptr = inc_buf_ptr(iptr);
      ++cptr;
    }
  return (char)*iptr - *cptr;
}


/* {\hrulefill\ ascii to integer\ \hrulefill} */
/* {\null{\tt Asc2int()} is a substitute of {\tt atoi()}.
We just want to keep our source code closed under {\sl stdio.h}
in order to remain it highly portable.\hfill} */

int asc2int(iptr)
int *iptr;
{
  int value = 0;

  while (((char)*iptr >= '0') && ((char)*iptr <= '9'))
    {
      value = 10 * value + (int)((char)*iptr - '0');
      iptr = inc_buf_ptr(iptr);
    }
  return value;
}


/* {\hrulefill\ search next word\ \hrulefill} */
/* {\ This function {\tt next\_word(iptr1,iptr2)}
simply increases buffer pointer {\tt iptr1}
until either it comes to the first character of the next word
or it coincides with iptr2, and returns {\tt iptr1}.\hfill} */

int *next_word(iptr1, iptr2)
int *iptr1, *iptr2;
{
  if (iptr1 == iptr2)
    return iptr1;
  while ((iptr1 = inc_buf_ptr(iptr1)) != iptr2)
    {
      if (((((char)*(iptr1 - 1) < 'a') || ((char)*(iptr1 - 1) > 'z'))
	   && (((char)*(iptr1 - 1) < '0') || ((char)*(iptr1 - 1) > '9')))
	   && ((((char)*iptr1 >= 'a') && ((char)*iptr1 <= 'z'))
	      || (((char)*iptr1 >= '0') && ((char)*iptr1 <='9'))))
	break;
    }
  return iptr1;
}


/* {\hrulefill\ parse options\ \hrulefill} */
/* {\ {\tt\ Parse\_options()\ } changes several environment variables
of {\bf src2tex} and {\bf src2latex} dynamically.
Since using src2tex escape sequence is pretty tricky,
we have decided to make very strict syntax checking
before parsing options. 
Function {\tt\ parse\_options()\ } returns \ 1\ ,
if src2tex escape sequence is found,
and returns \ 0\  otherwise.\hfill}*/

int parse_options(ptr)
flag_char *ptr;
{
  int brace_counter = 0;
  int error_flag = 0;
  int i, *iptr1, *iptr2, *iptr3;

  iptr1 = ptr->buffer;
  while (((char)*iptr1 != '\\') && ((char)*iptr1 != '\n') && (*iptr1 != EOF))
    {
      if ((((char)*iptr1 >= 'A') && ((char)*iptr1 <= 'Z'))
	  || (((char)*iptr1 >= 'a') && ((char)*iptr1 <= 'z')))
	++error_flag;
      iptr1 = inc_buf_ptr(iptr1);
    }
  /* checking syntax {\hfill} */
  if (str_cmp(iptr1, "\\src2tex{") != 0)
    return 0;
  if (error_flag != 0)
    {
      fprintf(stderr,
	      "\nError: syntax error of src2tex escape sequence\n");
      fprintf(stderr,
	      "       \\src2tex{...} is not written properly\n");
      fprintf(stderr,
	      "       junks are found before \\src2tex sequence\n");
      exit(EXIT_FAILURE);
    }
  if (ptr->flag == 1)
    {
      iptr2 = dec_buf_ptr(iptr1);
      if (*iptr2 != '{')
	{
	  fprintf(stderr,
		  "\nError: syntax error of src2tex escape sequence\n");
	  fprintf(stderr,
		  "       \\src2tex{...} is not written properly\n");
	  fprintf(stderr,
		  "       missing a left brace { \n");
	  exit(EXIT_FAILURE);
	}
    }
  for (i = 0, iptr2 = iptr1; i < 256; ++i, iptr2 = inc_buf_ptr(iptr2))
    {
      if ((char)*iptr2 == '{')
	++brace_counter;
      if ((char)*iptr2 == '}')
	--brace_counter;
      if (((char)*iptr2 == '}') && (brace_counter == 0))
	break;
      if (((char)*iptr2 == '\n') || (*iptr2 == EOF))
	break;
    }
  if (((char)*iptr2 != '}') || (brace_counter != 0))
    {
      fprintf(stderr,
	      "\nError: syntax error of src2tex escape sequence\n");
      fprintf(stderr,
	      "       \\src2tex{...} is not written properly\n");
      fprintf(stderr,
	      "       missing right brace } \n");
      exit(EXIT_FAILURE);
    }
  iptr3 = iptr2;
  while (((char)*iptr3 != '\n') && (*iptr3 != EOF))
    {
      if ((((char)*iptr3 >= 'A') && ((char)*iptr3 <= 'Z'))
	  || (((char)*iptr3 >= 'a') && ((char)*iptr3 <= 'z')))
	{
	  fprintf(stderr,
		  "\nError: syntax error of src2tex escape sequence\n");
	  fprintf(stderr,
		  "       \\src2tex{...} is not written properly\n");
	  fprintf(stderr,
		  "       junks are found after \\src2tex sequence\n");
	  exit(EXIT_FAILURE);
	}
      iptr3 = inc_buf_ptr(iptr3);
    }
#ifdef DEBUGGING
  printf("parse_options():\n");
#endif
  /* start parsing {\hfill} */
  for (i = 1; i == 8; ++i)
    iptr1 = inc_buf_ptr(iptr1);
  iptr1 = next_word(iptr1, iptr2);
  while(iptr1 != iptr2)
    {
      /* parsing htab option {\hfill} */
      if (str_cmp(iptr1, "htab") == 0)
	{
	  iptr1 = next_word(iptr1, iptr2);
	  if (((char)*iptr1 >= '0') && ((char)*iptr1 <= '9'))
	    Htab_Size = asc2int(iptr1);
	}
      /* parsing vtab option {\hfill} */
      if (str_cmp(iptr1, "vtab") == 0)
	{
	  iptr1 = next_word(iptr1, iptr2);
	  if (((char)*iptr1 >= '0') && ((char)*iptr1 <= '9'))
	    Vtab_Size = asc2int(iptr1);
	}
      /* TeXt font {\hfill} */
      if (str_cmp(iptr1, "textfont") == 0)
	{
	  iptr1 = next_word(iptr1, iptr2);
	  if (str_cmp(iptr1, "bf") == 0)
	    TextModeFont = Bold;
	  if (str_cmp(iptr1, "it") == 0)
	    TextModeFont = Italic;
	  if (str_cmp(iptr1, "rm") == 0)
	    TextModeFont = Roman;
	  if (str_cmp(iptr1, "sc") == 0)
	    TextModeFont = SmallCaps;
	  if (str_cmp(iptr1, "sl") == 0)
	    TextModeFont = Slant;
	  if (str_cmp(iptr1, "tt") == 0)
	    TextModeFont = Typewriter;
	}
      /* TeX font {\hfill} */
      if (str_cmp(iptr1, "texfont") == 0)
	{
	  iptr1 = next_word(iptr1, iptr2);
	  if (str_cmp(iptr1, "bf") == 0)
	    TeXModeFont = Bold;
	  if (str_cmp(iptr1, "it") == 0)
	    TeXModeFont = Italic;
	  if (str_cmp(iptr1, "rm") == 0)
	    TeXModeFont = Roman;
	  if (str_cmp(iptr1, "sc") == 0)
	    TeXModeFont = SmallCaps;
	  if (str_cmp(iptr1, "sl") == 0)
	    TeXModeFont = Slant;
	  if (str_cmp(iptr1, "tt") == 0)
	    TeXModeFont = Typewriter;
	}
      iptr1 = next_word(iptr1, iptr2);
    }
#ifdef DEBUGGING
  printf("Htab_Size=%d\n",Htab_Size);
  printf("Vtab_Size=%d\n",Vtab_Size);
  printf("TextModeFont=%s\n",TextModeFont);
  printf("TeXModeFont=%s\n",TeXModeFont);
#endif
  return 1;
}

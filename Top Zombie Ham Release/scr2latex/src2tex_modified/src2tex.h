/* {\hrulefill} *
{\ % beginning of TeX mode

\input fonts.tex % define fonts
\input title.tex % title and authors

% end of TeX mode}
* {\hrulefill} */


/* {\hrulefill\ src2tex.h\ \hrulefill} */


/* {\hrulefill\ debugging switch\ \hrulefill} */
/* {\ This parameter is just prepared for debugging. 
If you are interested in what {\bf src2tex} and {\bf src2latex} are doing,
you could use it \hfill} */

/* #define DEBUGGING */


/* {\hrulefill\ plain mode switch\ \hrulefill} */
/* {\ If {\tt PLAIN} is defined, you will get plain {\bf src2tex}
and {\bf src2latex}. In this case, they do not output any escape sequences
$\backslash$footline$\cdots$,
$\backslash$documentstyle$\cdots$,
$\backslash$begin$\cdots$
at the beginning of convertion and
$\backslash$bye$\cdots$,
$\backslash$end$\cdots$
at the end of file.\hfill} */

/* #define PLAIN */


/* {\hrulefill\ title and version\ \hrulefill} */
/* {\ A string {\tt VERSION} is used in {\sl fileio.c}
   and {\sl langflag.c} \hfill} */

#define VERSION "2.12h"


/* {\hrulefill\ ASCII and NTT J{\TeX} switch\ \hrulefill} */
/* {\ {\bf Src2tex} and {\bf src2latex} are designed to generate
universal {\TeX}-code which would be acceptable to any {\TeX}.
If you are an ASCII J{\TeX} [resp. NTT J{\TeX}] user
and if you are sure that you won't use any other {\TeX},
it is better to undefine {\tt NTT} [resp. {\tt ASCII}].
Furthermore, if you are a non-Japanese {\TeX} user,
please undefine the following two parameters {\tt ASCII} and {\tt NTT}.
\hfill} */

#define ASCII
#define NTT


/* {\hrulefill\ LaTeX option and style file\ \hrulefill} */
/* {\ If you need no default option and style,
you have only to undefine the following definitions.\hfill} */

#define LATEXOPTION "12pt"
#define LATEXSTYLE "article"


/* {\hrulefill\ DOS/UNIX switch\ \hrulefill} */
/* {\ Undefine {\tt UNIX} and define {\tt DOS} if you are a DOS user.
Be careful! If you define both parameters simultaneously,
you will end up with contradictions.\hfill} */

/* #define UNIX */
/* #undef DOS */


/* {\hrulefill\ exit parameters\ \hrulefill} */

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1


/* {\hrulefill\ buffer size = $2^{14}$\ \hrulefill} */
/* {\ The authors think that $2^{14}=16384$ would be enough.
However, if you think that {\bf src2tex} is too slow,
it would be better to replace $2^{14}$ with $2^{13}$ or $2^{12}$.\hfill} */

#ifndef UNIX
#define BUFFER_SIZE 8192
#else
#define BUFFER_SIZE 16384
#endif


/* {\hrulefill\ maximum filename length\ \hrulefill} */

#ifndef UNIX
#define FNAME_LEN_MAX 13
#else
#define FNAME_LEN_MAX 256
#endif


/* {\hrulefill\ space size in the unit of width of an m\ \hrulefill} */

#define SPACE .5


/* {\hrulefill\ horizontal tab skip in the unit of width of
   a {\tt SPACE}\ \hrulefill} */

#define HTAB_SKIP 8


/* {\hrulefill\ vertical tab skip in the unit of height of an x\ \hrulefill} */

#define VTAB_SKIP 4


/* {\hrulefill\ maximum length of non-display style mathematical
   formula\ \hrulefill} */
/* {\ One of the authors believes that long non-display style
mathematical formula is not beautiful.
He thinks that long formula should be written in display style.\hfill} */

#define FORMULA_LEN_MAX 512


/* {\hrulefill\ structure of flagged character\ \hrulefill} */
/*
$$
{\tt flag}
    =\cases{0\quad\rm(text\ mode)\cr
            1\quad\rm(quasi-\TeX\ mode)\cr
            2\quad\rm (\TeX\ mode)\cr},
\quad
{\tt character}
    =\rm input\ character,
\quad
{\tt buffer}
    =\rm buffer\ address,
$$
*/
#include <stdlib.h>
typedef struct
{
    int flag;
    int character;
    int *buffer;
}
flag_char;

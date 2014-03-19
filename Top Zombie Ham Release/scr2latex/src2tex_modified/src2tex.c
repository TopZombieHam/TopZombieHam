/* {\hrulefill} *
{\ % beginning of TeX mode

\input fonts.tex % define fonts
\input title.tex % title and authors

\bigskip

\centerline{\bf Abstract}

\medskip

{\midinsert\narrower\narrower
One of the authors has a strong desire for combining
documentation and manual with source program by using
{\TeX}'s beautiful text and PostScript figures
without any big literate programming tools,
such as WEB system ($\,$[8]$\,$) or something like that ($\,$[15]$\,$).
Unfortunately, most of literate programming tools require
too much laborious effort to learn their usages,
and also, as far as the authors know, no such tools allow to
patch PS and EPS figures upon text.
It is quite convenient if source program itself is its
document, manual and releasenote simultaneously, in which you can
explain usages, programming techniques, algorithms,
theoretical backgrounds, {\it etc\ } in terms of high quality
{\TeX}t, mathematical formulae and beautiful figures.
Here the authors would like to release softwares {\bf src2tex}
and {\bf src2latex}.
Those softwares would give an easy-to-use unified environment of source
program, documentation and manual. They believe that
{\bf src2tex} and {\bf src2latex} work effectively for a relatively
small set of source programs, such as education and experiment programs.
In fact, their src2tex-project itself consists of several
education programs, and {\bf src2tex} has worked very well
in their project.
For practical usages of {\bf src2tex} and {\bf src2latex} it would be better
to compare \ {\sl newton.c, simpson.c, hanoi.c,} {\it etc\/}
\ with \ {\sl newton.c.ps, simpson.c.ps, hanoi.c.ps,} {\it etc\/}
\ respectively.
\endinsert}

\bigskip

\centerline{\bf 1. Introduction}

\bigskip

Our softwares {\bf src2tex} and {\bf src2latex} are a sort of text converters
from various types of source program files to plain\TeX\ and
L\kern-.35em\raise.33ex\hbox{\eightcmr A}\kern-.2em\hbox{\TeX}\ format files,
{\it e.g.},

\centerline{{\quad\tt src1.c} $\Rightarrow$ {\tt src1.c.tex},
\ {\tt src2.f} $\Rightarrow$ {\tt src2.f.tex}.}

\noindent
However, {\ \bf src2tex\ } and {\ \bf src2latex\ } are not simple
pretty-printers.
Our {\bf src2tex} and {\bf src2latex} are designed to fulfill the following
desires:

\medskip

\itemitem{(1)}{\bf src2tex} and {\bf src2latex} can identify differences
	of various computer languages, such as
	BASIC, C, C++, OBJECTIVE{\tt-}C, COBOL, FORTRAN, HTML, JAVA, LISP,
	MAKE, PASCAL, PERL, SCHEME, SHELL, TCL/TK;
	ASIR, MACSYMA, MAPLE, MATHEMATICA, MATLAB, MAXIMA, MuPAD,
	OCTAVE, REDUCE.\footnote{**}
	{ASIR, JAVA, MACSYMA, MAPLE, MATHEMATICA, MATLAB, REDUCE
	are registered trademarks of
	Fujitsu Laboratories, Ltd.,
	Sun Microsystems, Inc.,
	Macsyma Inc.,
	Waterloo Maple Software,
	Wolfram Research, Inc.,
	The MathWorks, Inc.,
	The Rand Corporation
	respectively.}
\itemitem{(2)}{\bf src2tex} and {\bf src2latex} allow to use {\TeX}'s
	powerful typesetting mechanism within comment area of source program.
\itemitem{(3)}{\bf src2tex} and {\bf src2latex} enable to patch PS and EPS
	files upon source file without any difficulties.
\itemitem{(4)}{\bf src2tex} and {\bf src2latex} accept EUC Kanji code
	characters.

\medskip

\noindent
{\it Remark\/}. Kanji : a Japanese system of writing based on
	the Chinese one and composed principally of characters
	borrowed or adapted from Chinese, a single character
	belonging to the kanji system of writing
(quoted from ''Webster's Third New International Dictionary
	of the English Language Unabridged'',
	{\sl G. \& C. Herrian Company}, 1971)

\medskip

Using {\bf src2tex} or {\bf src2latex},
you can embed mathematical formulae into comment area of source program.
For instance, you can insert formulae

$$ \sum_{\nu=1}^n\nu={n(n+1)\over2} $$

$$ \Gamma(x+1)=x!\sim\sqrt{2\pi x}\,x^xe^{-x} $$

$$\sqrt{\pi}\,(2n-1)!!{(1-p)^n\over p^{n+{1\over2}}}
     =\int_0^\infty e^{-pt}\,{H_{2n}\bigl(\sqrt{t}\,\bigr)\over\sqrt{t}}\,dx$$

\medskip

\noindent
into comment area of C, like this.
You can even include EPS files, by virtue of {\sl dvi2ps}
or something like that, as follows:

\vskip 1\baselineskip
\special{epsfile=prob1.eps hscale=0.5 vscale=0.5}
\special{epsfile=prob2.eps hoffset=225 hscale=0.5 vscale=0.5}
\vskip 9cm

\bigskip

\centerline{\bf 2. Compilation and Installation}

\bigskip

In order to compile and install {\bf src2tex} and {\bf src2latex},
you have only to issue the following commands:

\medskip

\qquad{\tt \% make}

\qquad{\tt \% make install}

\medskip

\noindent
After that, you would find executable files {\bf src2tex} and
{\bf src2latex} in your current directory.
You could copy them to a suitable place, {\sl e.g.},

\medskip

\qquad{\tt \% cp src2tex $\tilde{\ }$/bin/}

\qquad{\tt \% cp src2latex $\tilde{\ }$/bin/}

\medskip\noindent
If you could not make executables, it would be better
to read PostScript files
{\sl\ fileio.c.ps, getdata.c.ps, langflag.c. ps,
modflag.c.ps, pas\_bold.c.ps, src2tex.c.ps, text2tex.c.ps}
and {\sl tools.c.ps}.

\medskip

\noindent
{\it Remark 1\/}.
The authors are very glad if you can type

\medskip

\qquad{\tt \% make report}

\medskip

\noindent
and send your local {\ \sl /etc/motd\ } file
to kamano@po.iijnet.or.jp.
They think this would give invaluable information
for further development of {\bf src2tex}.

\medskip

\noindent
{\it Remark 2\/}.
If you are a DOS user, you have only to type

\qquad{\tt \% make dos}

\noindent
You will get {\bf src2tex.exe} and {\bf src2ltex.exe}
in the present working directory.

\medskip

Furthermore, shell scripts {\bf src2tex2dvi} and {\bf src2tex2ps}
might be useful.
{\bf Src2tex2dvi} and {\bf src2tex2ps} are text converters
from source program file to DVI and PostScript files.
Those shell scripts are nothing more than combinations of free softwares
{\sl src2tex}, {\sl jtex}, {\sl dvi2ps}, {\sl nkf} and {\sl psnup}.
Maybe, it is necessary to modify {\bf src2tex2dvi} and {\bf src2tex2ps}
so that they work properly at your site
({\it cf}., also, {\sl src2latex2dvi} and {\sl src2latex2ps}).
For DOS users, we would like to provide two batch files
{\sl src2dvi.bat} and {\sl tex2tex.bat}
({\it cf}., {\sl DOS\_USER}).

\bigskip

\centerline{\bf 3. Manual}

\bigskip

The usage of {\bf src2tex} and {\bf src2latex} is quite simple.
It suffices to input

\medskip

\qquad{\tt \% src2tex  {\sl source-file-name}}

\qquad{\tt \% src2latex  {\sl source-file-name}}

\medskip

\noindent
on the command line.
No options are available and no options will be added,
since we believe that it is no good
to implement various options and circumvent programming difficulties.
Their usage is so simple that we do not feel any necessities
to write online manuals.
If no input-file-name is given, {\bf src2tex} and {\bf src2latex}
read data from {\it standard input\/}
and write them out to {\it standard output\/}.
When {\sl source-file-name} is given, {\bf src2tex} and {\bf src2latex} try
to identify language which is used in the given file.
First, they see {\sl file-name-suffix} and determine language type
as follows :

\vskip 0.5\baselineskip

\settabs\+ \hskip5.5cm & \hskip 1cm & \hskip 2cm \cr
\+ \qquad\qquad{\tt .tex, .txt} & $\Rightarrow$ & {\tt TEXT} \cr
\+ \qquad\qquad{\tt .bas, .vb} & $\Rightarrow$ & {\tt BASIC} \cr
\+ \qquad\qquad{\tt .c, .cpp, .vc} & $\Rightarrow$
	& {\tt C, C++, OBJECTIVE-C} \cr
\+ \qquad\qquad{\tt .cbl, .cob} & $\Rightarrow$ & {\tt COBOL} \cr
\+ \qquad\qquad{\tt .f, .for} & $\Rightarrow$ & {\tt FORTRAN} \cr
\+ \qquad\qquad{\tt .html} & $\Rightarrow$ & {\tt HTML} \cr
\+ \qquad\qquad{\tt .java} & $\Rightarrow$ & {\tt JAVA} \cr
\+ \qquad\qquad{\tt .el, .lsp, .sc, .scm} & $\Rightarrow$
					& {\tt LISP, SCHEME} \cr
\+ \qquad\qquad{\tt \ makefile} & $\Rightarrow$ & {\tt MAKE} \cr
\+ \qquad\qquad{\tt .p, .pas, .tp} & $\Rightarrow$ & {\tt PASCAL} \cr
\+ \qquad\qquad{\tt .pl, .prl} & $\Rightarrow$ & {\tt PERL} \cr
\+ \qquad\qquad{\tt .sh, .csh, .ksh} & $\Rightarrow$ & {\tt SHELL} \cr
\+ \qquad\qquad{\tt .tcl, .tk} & $\Rightarrow$ & {\tt TCL/TK} \cr
\+ \qquad\qquad{\tt .asi, .asir, .asr} & $\Rightarrow$ & {\tt ASIR} \cr
\+ \qquad\qquad{\tt .mac, .max} & $\Rightarrow$ & {\tt MACSYMA, MAXIMA} \cr
\+ {\qquad\qquad\tt .map, .mpl} & $\Rightarrow$ & {\tt MAPLE} \cr
\+ \qquad\qquad{\tt .mat, .mma} & $\Rightarrow$ & {\tt MATHEMATICA} \cr
\+ \qquad\qquad{\tt .ml, .mtlb, .oct} & $\Rightarrow$ & {\tt MATLAB, OCTAVE}\cr
\+ \qquad\qquad{\tt .mu} & $\Rightarrow$ &{\tt MuPAD} \cr
\+ \qquad\qquad{\tt .red, .rdc} & $\Rightarrow$ &{\tt REDUCE} \cr

\vskip 0.5\baselineskip

\noindent
Next, they search key words and attempt to determine language.
After that, if there exists a file {\sl src2tex.s2t}
[resp. {\sl src2latex.s2t} ],
then {\bf src2tex} [resp. {\bf src2latex} ] simply includes it
at the beginning of output procedure.
In case of \ DOS, {\sl src2ltex.s2t} is read instead of {\sl src2latex.s2t}.

Our {\bf src2tex} and {\bf src2latex} have three modes:
text mode, quasi-{\TeX} mode and {\TeX} mode.
First, you are in default text mode.
As you can imagine, text mode is nothing more than typewriter mode.
In text mode, "what you see is what you get".
Second, you find that you are in quasi-{\TeX} mode when you enter into
comment area.
For instance, if input file is C source file, then

%         ___________        ________________
%        |           |----->|                |
%        | text mode |      | quasi-TeX mode |
%        |___________|<-----|________________|
%

\special{epsfile=figure1.eps hoffset=25 hscale=.7 vscale=.7}
\vskip 4cm

\noindent
In quasi-{\TeX} mode of {\bf src2tex},
you can input any characters as in text mode
except the following four key words
\ \ $\{\backslash$\ \ ,\ \ $\}$\ \ ,\ \ {\$}\ \ and\ \ {\$\$}\ \ .
However, it is to be noted that
font and spacing sizes are different from those of text mode.
Third, when you are in quasi-{\TeX} mode of {\bf src2tex},
you are allowed to enter into {\TeX} mode and escape from
it by using one of the following pairs:
\ $\{\backslash$ \ and \ $\}$\ ,\ \ {\$} \ and \ {\$}\ ,
\ \ {\$\$} \ and \ {\$\$}\ .
To be more explicit,

%	 ________________        __________
%	|                |----->|          |
%	| quasi-TeX mode |      | TeX mode |
%	|________________|<-----|__________|
%

\ \vskip -1\baselineskip
\special{epsfile=figure2.eps hoffset=25 hscale=.7 vscale=.7}
\vskip 4cm

\noindent
Literally, {\TeX} mode is genuine plain {\TeX} mode. You can use plain {\TeX}
there without any restrictions.
{\bf Src2tex} is designed to use the above
key words as follows:

\medskip

\qquad\${\sl mathematical formulae}\$

\medskip

\qquad\$\${\sl display style mathematical formulae}\$\$

\medskip

\qquad$\{\backslash\ ${\sl TeXt and mathematical formulae}$\}$

\medskip

\noindent
{\it Remark 1\/}.
In the above expressions \$ , \$\$ and $\backslash$ are
all passed to {\TeX} transparently.
However, braces $\{$ and $\}$ are both replaced with blank spaces.
For example, a phrase

\qquad{\tt $\{\backslash$bf bold face$\}$}

\noindent
is translated into

\qquad{\tt\ $\backslash$bf bold face}

\noindent
and passed to {\TeX}.
If you really want to get {\tt $\{\backslash$bf bold face$\}$},
then you have to use

\qquad{\tt$\{\{\backslash$bf bold face$\}\}$}

\noindent
instead. Actually,

\medskip

\qquad$\{\{\backslash\ ${\sl TeXt and mathematical formulae}$\}\}$

\medskip

\noindent
is the other door to {\TeX} mode. This method provides a safe encapslated
transition from {\TeX} mode to quasi-{\TeX} mode.

\medskip

\noindent
{\it Remark 2\/}.
{\bf Src2tex} and {\bf src2latex} have several fail-safe mechanisms.
If you do not write mathematical formula properly,
{\bf src2tex} thinks that you have no knowledge of {\TeX},
{\it i.e.\/}, you are not allowed to use {\TeX}.
For instance, if you really want to enter into {\TeX} mode,
it is better not to write

\qquad\$T\_abc\$\ .

\noindent
As a substitute, you should use either

\qquad\$T\_$\{$abc$\}$\$\qquad or\qquad\$T\_a\ bc\$

\noindent
({\it cf.\/}\ [9]).
In case of BASIC or PERL,
{\ \$\ } sign which means string variable is not always recognized
as a {\TeX} mode transition key word.
For example, you cannot enter into {\TeX} mode with

\qquad{\tt A\$, str1\$, ...}

\noindent
in BASIC comment area.
You are not able to use {\TeX} mode of PERL with

\qquad{\tt \$A, \$str1, ...}

\noindent
either.
It would be better to use \$\$ or $\{\backslash$ in BASIC and PERL.

\medskip

\noindent
{\it Remark 3\/}.
As you can easily imagine, in quasi-{\TeX} mode of {\bf src2latex},
you have to use \ $\backslash$(\ ,\ $\backslash$)\ ,\ $\backslash$[
\ and\ $\backslash$]\ instead of \ \$\ ,\ \$\ ,\ \$\$\ and\ \$\$\ respectively.
In case of {\bf src2latex}, if you want to use a certain non-default
documentstyle, say {\tt\ twocolumn, 12pt, jarticle\ } style, then you have
only to insert a comment area with a phrase

\qquad{\tt $\{$$\backslash$documentstyle[twocolumn,12pt]$\{$jarticle$\}$}$\}$

\medskip

\noindent
at the beginning of source file.
The general form of this phrase is given by

\medskip

\qquad{\tt $\{$$\backslash$documentstyle[{\sl latex option}]$\{${\sl
	latex style}$\}$}$\}$

\medskip

\noindent
If you have already installed  {\sl dvi2ps}  or something like that,
you can include EPS files when you are in {\TeX} mode. In case of {\sl dvi2ps},
a line

\medskip

\qquad$\{\backslash$special$\{$epsfile={\sl eps file name ...}$\}\}$

\medskip

\noindent
would suffice to patch an EPS figure upon comment area.

For practical usages, it is better to read source files of
{\bf src2tex}
({\it e.g.},\ fileio.c, getdata.c,
langflag.c, modflag.c, src2tex.c, text2tex.c, tools.c),
since they are written in src2tex style.
For instance, if you input three commands

\medskip

\qquad{\tt\% src2tex src2tex.c}

\qquad{\tt\% tex src2tex.c.tex }

\qquad{\tt\% dvi2ps src2tex.c.dvi > src2tex.c.ps}

\medskip

\noindent
in the source files directory of {\bf src2tex}, you will get a PostScript file

\medskip

\qquad{\tt src2tex.c.ps}

\medskip

\noindent
which would show most of useful technicalities of {\bf src2tex}. We would like
to suggest you to compare {\sl src2tex.c} with {\sl src2tex.c.ps} carefully
by using one of PostScript pre-viewers. You could learn practical
usages quite easily.

\bigskip

\centerline{\bf 4. Dirty Tricks}

\bigskip

There is a dirty trick which enables to change certain global variables
of {\bf src2tex} and {\bf src2latex} dynamically.
For instance, if you want to put

\medskip

{\sl\qquad tabulation\ size = 4\ characters}

{\sl\qquad Text\ mode\ font = roman\ type}

{\sl\qquad (quasi-)\TeX\ mode\ font = slanted\ type}

\medskip

\noindent
you have only to insert a line of comment area with src2tex escape sequence
of the form

\medskip

{\tt\qquad$\{\backslash$src2tex$\{$htab=4\ textfont=rm\ texfont=sl$\}\}$}

\medskip

\noindent
Generally, src2tex escape sequence is define by

\medskip

{\tt\qquad$\{\backslash$src2tex$\{$htab={\sl integer}
				textfont={\sl font type1}
				texfont={\sl font type2}$\}\}$}

\medskip

\noindent
where {\sl\ font type1\ } and {\sl\ font type2\ } are equal to
one of the following words respectively:

\medskip

{\tt\qquad bf, it, rm, sc, sl, tt\ .}

\medskip

\noindent
The meanings of the above key words would be self-evident ({\it cf.\/}\ [9]).
For practical examples, it would be better to read SCHEME source program
{\sl\ farmer+hen.scm\ } and PS file {\sl\ farmer+hen.scm.ps\ }
which is actually generated by issuing the following commands:

\medskip

{\tt\qquad \% src2latex farmer+hen.scm}

{\tt\qquad \% latex farmer+hen.scm.tex}

{\tt\qquad \% dvi2ps farmer+hen.scm.dvi > farmer+hen.scm.ps}

\medskip

Another dirty trick is

\medskip

{\tt\qquad -<$\,n\,$>}

\medskip

\noindent
option of {\bf src2tex} and {\bf src2latex}.
When you are in debugging mode,
you usually need line numbers
and you sometimes want to restrict page length.
If you type

\medskip

\qquad{\tt \% src2tex -<$n$>  {\sl source-file-name}}

\qquad{\tt \% src2latex -<$n$>  {\sl source-file-name}}

\medskip

\noindent
your source file is translated into debugging format.
For example,

\medskip

\qquad{\tt \% src2tex -35 sqrt\_mat.red}

\qquad{\tt \% tex sqrt\_mat.red.tex}

\qquad{\tt \% dvi2ps sqrt\_mat.red.dvi > sqrt\_mat.red.ps{\~\ }}

\qquad{\tt \% psnup -4 sqrt\_mat.red.ps{\~\ } > sqrt\_mat.red.ps}

\medskip

\noindent
gives the {\sl sqrt\_mat.red.ps} file.

\bigskip
\bigskip

\input thanks.tex % acknowledgement

\bigskip
\bigskip
\bigskip

\input references.tex % references

\bigskip

% end of TeX mode}
* {\hrulefill} */


/* {\hrulefill\ src2tex.c\ \hrulefill} */


#include <stdio.h>
#include "src2tex.h"

extern void get_fnames();
extern void init_lang_flag();
extern void open_files();
extern void close_files();
extern void text2tex();


/* {\hrulefill\ main function of src2tex\ \hrulefill} */


main(argc, argv)
int argc;
char **argv;
{
    char *cptr[2];			/* {\ character pointers of file
					   names \hfill} */
    FILE *fptr[2];			/* {\ stream pointers of
					   input/output files \hfill} */

    get_fnames(argc, argv, cptr);	/* {\ get file names from the
					   command line \hfill} */
    init_lang_flag(cptr);		/* {\ initialize language flags
					   \hfill} */
    open_files(cptr, fptr);		/* {\ open input and output files
					 \hfill} */
    text2tex(cptr,fptr);		/* {\rm Text$\to$\TeX\ translation
					 \hfill} */
    close_files(cptr, fptr);		/* {\ close input and output files
					 \hfill} */
    exit(EXIT_SUCCESS);
}

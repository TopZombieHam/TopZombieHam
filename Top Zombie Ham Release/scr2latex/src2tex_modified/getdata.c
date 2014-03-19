/* {\hrulefill} *
{\  % beginning of TeX mode

\input fonts.tex % define fonts
\input title.tex % title and authors

% end of TeX mode}
* {\hrulefill} */


/* {\hrulefill\ getdata.c\ \hrulefill} */


#include <stdio.h>
#include "src2tex.h"


/* {\hrulefill\ buffer storage\ \hrulefill} */
/* {\rm Input data are temporarily stored in buffer storage

\smallskip
\qquad{\tt Buffer[0] Buffer[1]} $\cdots$ {\tt Buffer[BUFFER\_SIZE-1]\ .}
\smallskip

\noindent
For further details, see the definitions of functions of getdata.c,
langflag.c, modflag.c and text2tex.c .\hfill} */

int Buffer[BUFFER_SIZE];


/* {\hrulefill\ increase buffer pointer buf\_ptr\ \hrulefill} */
/* {\rm We access buffer storage by using integer pointer to {\tt Buffer[]},
which we call buffer pointer.
This function simply increases buffer pointer
provided that {\tt Buffer[BUFFER\_SIZE]} is identified
with {\tt Buffer[0]}.\hfill} */

int *inc_buf_ptr(buf_ptr)
int *buf_ptr;
{
  if ((buf_ptr == Buffer -1) || (buf_ptr == Buffer + BUFFER_SIZE))
    {
      fprintf(stderr, "\nError: buffering error !!\n");
      exit(EXIT_FAILURE);
    }
  if (++buf_ptr == Buffer + BUFFER_SIZE)
    buf_ptr = Buffer;
  return buf_ptr;
}

/* {\hrulefill\ decrease buffer pointer buf\_ptr\ \hrulefill} */
/* {\rm This function is an inverse function of the above
{\tt inc\_buf\_ptr()}.
In fact, {\tt dec\_buf\_ptr()} decreases buffer pointer on the assumption
that {\tt Buffer[-1]} is identified with {\tt Buffer[BUFFER\_SIZE-1]}.
\hfill} */

int *dec_buf_ptr(buf_ptr)
int *buf_ptr;
{
  if ((buf_ptr == Buffer -1) || (buf_ptr == Buffer + BUFFER_SIZE))
    {
      fprintf(stderr, "\nError: buffering error !!\n");
      exit(EXIT_FAILURE);
    }
  if (buf_ptr-- == Buffer)
    buf_ptr += BUFFER_SIZE;
  return buf_ptr;
}


/* {\hrulefill\ fgetc to buffer {\tt Buffer[]}\ \hrulefill} */
/* {\rm In case of first call, {\it i.e.\/}, in case of {\tt stat\_flag}=0,
{\tt fgetc2buffer()} increases {\tt stat\_flag}
and fills $1\over2$ of buffer

\smallskip
\qquad{\tt Buffer[0] Buffer[1]}
	$\cdots$ {\tt Buffer[(int)(BUFFER\_SIZE/2)-1]}
\smallskip

\noindent
with input data which we {\tt fgetc()} from a file given on the command line.
After that, {\tt fgetc2buffer()} put

\smallskip
\qquad{\tt buf\_ptr1=Buffer, buf\_ptr2=Buffer+(int)(BUFFER\_SIZE/2)}
\smallskip

\noindent
and returns {\tt buf\_ptr1}.
When {\tt stat\_flag}$\not=0$, {\tt fgetc2buffer()} reads a datum
from a given file, substitutes it to {\tt *buf\_ptr2} and
increases {\tt buf\_ptr2}.
And also, it increases buffer pointer {\tt buf\_ptr1}
and returns {\tt buf\_ptr1}.
So, {\tt fgetc2buffer()} uses a half of {\tt Buffer[]} for input data
and the remaining half for input history.\hfill} */

int *fgetc2buffer(fptr)
FILE *fptr[];
{
    static int stat_flag = 0;
    static int *buf_ptr1, *buf_ptr2;
    int i;

    if (stat_flag == 0)
      {
	  ++stat_flag;
	  for (i = 0; i < (int) (BUFFER_SIZE / 2); ++i)
	      Buffer[i] = fgetc(fptr[0]);
	  for (i = (int) (BUFFER_SIZE / 2); i < BUFFER_SIZE; ++i)
	      Buffer[i] = 0x00;
	  buf_ptr1 = Buffer;
	  buf_ptr2 = Buffer + (int) (BUFFER_SIZE / 2);
	  return buf_ptr1;
      }
    else
      {
	  *buf_ptr2 = fgetc(fptr[0]);
	  buf_ptr2 = inc_buf_ptr(buf_ptr2);
	  buf_ptr1 = inc_buf_ptr(buf_ptr1);
	  return buf_ptr1;
      }
}

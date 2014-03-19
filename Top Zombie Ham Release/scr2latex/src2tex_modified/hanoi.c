/* {\hrulefill} *


{\ % beginning of TeX mode

\centerline{\bf Towers of Hanoi}

{\midinsert\narrower\narrower
\noindent
This program gives an answer to the following famous problem (towers of
Hanoi).
There is a legend that when one of the temples in Hanoi was constructed,
three poles were erected and a tower consisting of 64 golden discs was
arranged on one pole, their sizes decreasing regularly from bottom to top.
The monks were to move the tower of discs to the opposite pole, moving
only one at a time, and never putting any size disc above a smaller one.
The job was to be done in the minimum numbers of moves. What strategy for
moving discs will accomplish this optimum transfer?
\endinsert}

% end of TeX mode }

* {\hrulefill} */


/* {\hrulefill\ hanoi.c\ \hrulefill} */


#include <stdio.h>
#define ARRAY 8				/* {\ disc �ο� \hfill} */

int disc[3][ARRAY];			/* {\ disc �˴ؤ���ǡ������֤����
					   \hfill} */

void init_array()			/* {\ disc �˴ؤ���ǡ����ν����
					   \hfill} */
{
    int j;

    for (j = 0; j < ARRAY; ++j)		/* {\ [����] ���� {\bf for} �롼��
					   ��ȴ���Ф����塢����������
					   \hfill} */
					/* {\null{\tt disc[][]} �ˤϤɤΤ褦
					   �ʥǡ�������������뤳�Ȥ�
					   \hfill} */
					/* {\ �ʤ뤫������Ū�˽Ҥ٤衣
					   \hfill} */
      {
	  disc[0][j] = ARRAY - j;
	  disc[1][j] = 0;
	  disc[2][j] = 0;
      }
}

void print_result()			/* {\ ��̤�ɽ�� \hfill} */
{
    static long counter = 0;		/* {\ [����] ������ {\tt static}
					   ����������Τϡ��ʤ��ʤΤ�
					   \hfill} */
					/* {\ �ͤ��衣�⤷�� {\tt static}
					   ���������顢���������� \hfill} */
					/* {\ �����¸��򤷤Ƥߤ褦��
					   \hfill} */
    int i, j;

    printf("---#%d---\n", ++counter);
    for (i = 0; i <= 2; ++i)
      {
	  printf("[%d] ", i);
	  for (j = 0; j < ARRAY; ++j)
	    {
		if (disc[i][j] != 0)
		    printf("%d ", disc[i][j]);
		else
		    break;
	    }
	  printf("\n");
      }
}

void move_one_disc(i, j)		/* {\ 1��� disc �� pole $i$ ����
					   pole $j$ �˰�ư���� \hfill} */
{
    static int *ptr[3] = {disc[0] + ARRAY, disc[1], disc[2]};

    (*ptr[j]++) = (*--ptr[i]);		/* {\ [����] {\tt ++} �ϥݥ���
					   �θ�ˤ��ꡢ{\tt --} �ϥݥ���
					   \hfill} */
					/* {\ �����ˤ��롣�ʤ������Τ褦��
					   ���ʤ���Фʤ�ʤ� \hfill} */
					/* {\ �Τ��������衣\hfill} */
    *ptr[i] = 0;
}

void move_discs(n, i, j, k)		/* {\ �夫�� $n$ ���ܤޤǤ� disc
					   ��pole $i$ ���� pole $j$ ��
					   \hfill} */
					/* {\ pole $k$ ���ͳ���ơ���ư����
					   \hfill} */
int n, i, j, k;
{
    if (n >= 1)
      {
	  move_discs(n - 1, i, k, j);	/* {\ �ؿ� {\tt move\_discs()}
					   ����ǡ�����˼�ʬ���� \hfill} */
	  move_one_disc(i, j);		/* {\ {\tt move\_discs()} ���Ȥ��
					   �Ƥ��롣���Τ褦�� \hfill} */
	  print_result();		/* {\ ��ˡ�ϡ��ֺƵ�Ū�ƤӤ�����
					   �Ȥ����롣�츫 \hfill} */
	  move_discs(n - 1, k, j, i);	/* {\ ʣ���˸���������Ǥ⡢
					   �Ƶ�Ū��ˡ���Ѥ���ȡ�\hfill} */
      }					/* {\ ��ñ�˲򤱤Ƥ��ޤ����Ȥ���
					   ���Ф��Ф��롣\hfill} */
}

/* {\vskip 1cm
\special{epsfile=hanoi1.eps hscale=0.365 vscale=0.3}
\special{epsfile=hanoi2.eps hoffset=225 hscale=0.35 vscale=0.3}
\vskip 5cm

\noindent
���Ȥ��С��ؿ� {\tt move\_discs(4,i,j,k)} ��ƤӽФ����Ȥϡ�
��ޤΤ褦�����򤹤뤳�Ȥ��б����롣\hfill} */

main()
{
    init_array();
    move_discs(ARRAY, 0, 1, 2);		/* {\ {\tt ARRAY} ��� disc ��
					   pole 0 ���� pole 1 �� pole 2
					   \hfill} */
					/* {\ ���ͳ���ơ���ư
					   ���� \hfill} */
}

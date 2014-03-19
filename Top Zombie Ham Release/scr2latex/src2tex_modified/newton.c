/* {\hrulefill} *

{\bf Newton-Raphson ˡ}

������ $f(x)=0$ ��򤯤���ˤϡ�������

$\displaystyle\qquad
	x_0=a,\quad x_{n+1}=x_n-{f(x_n)\over f'(x_n)}
	\qquad\cdots\cdots\ (\star)$

��Ŭ���ʽ���� $a$ ���Ф��Ʋ򤤤ơ����� $\{x_n\}$ �������롣
����� $a$ �����ޤ�Ϳ������С����ο���Ͼ�Ҥ���������
���Ĥβ� $\alpha$ �ˡ���«���뤳�Ȥ��Τ��Ƥ���, {\it i.e.},

$\displaystyle\qquad
	\exists\ \alpha=\lim_{n\to\infty}x_n
	\quad such\ that\quad f(\alpha)=0\ .$

������ $(\star)$ �ΰ�̣�Ȥ��μ�«���ͻҤϡ����οޤȼ��򸫤��
���������Ǥ��롣

{\special{epsfile=newton.eps hscale=.7 vscale=.7 hoffset=25}
\vskip 12cm}

$\displaystyle\qquad
	y-f(x_n)=f'(x_n)(x-x_n)
	\qquad\cdots\cdots\ \hbox{��}\ (x_n,f(x_n))\ \hbox{���̤�������������}$

$\displaystyle\qquad
	x_n-{f(x_n)\over f'(x_n)}
	\qquad\cdots\cdots\ \hbox{�嵭��������}\ x\ \hbox{���Ȥθ�����}
	\ x\ \hbox{��ɸ}$

���� $\{x_n\}$ �μ�«���ξ�������Ӽ�«�Υ���������ɾ���ϡ�
����ۤɴ�ñ�ʤ��ȤǤϤʤ���$\epsilon$-$\delta$ ��ˡ�Ȳ��ϳؤ˴ؤ���
�μ���ɬ�פȤ���롣��̣�Τ�������ˤϡ�����ʸ����Ҳ𤹤롣

�ʲ���C������ newton.c �ϡ�������

$\qquad\displaystyle x^2-5=0$

�β�Σ��Ĥ� $\sqrt{5}$ �Ǥ��뤳�Ȥ����ܤ��ơ�Newton-Raphson ˡ�� $\sqrt{5}$
�����ץ����Ǥ��롣{\tt A, F(X), DF(X)} ������򤤤���
���Ѥ��ơ��ƿͤǿ��ͼ¸���ԤäƤߤ褦��

* {\hrulefill} */


/* {\hrulefill\ newton.c\ \hrulefill} */


#include <stdio.h>
#define A 4.				/* ����� {\hfill} */
#define F(X) ((X)*(X)-5.)		/* Ϳ����줿�ؿ� {\hfill} */
#define DF(X) (2.*(X))			/* ����Ƴ�ؿ� {\hfill} */

main()
{
    double x, y;			/* �����٤Ƿ׻����� {\hfill} */

    x = A;				/* $\displaystyle x_0=a$ {\hfill} */
    printf("%.16f\n", x);		/* $x_0$ ��ɽ�� {\hfill} */
    y = x - F(x) / DF(x); 		/* $\displaystyle
				   	x_1=x_0 - {f(x_0)\over f'(x_0)}$
					{\hfill} */
    printf("%.16f\n", y);		/* $x_1$ ��ɽ�� {\hfill} */
    while (x != y)			/* {\ iteration ���äƤ�
					   �ͤ��Ѥ��ʤ��ʤä��齪λ
					   \hfill} */
    {
	x = y;
	y = x - F(x) / DF(x); 		/* $\displaystyle x_{n+1}=x_n
				   	- {f(x_n)\over f'(x_n)}$ {\hfill} */
	printf("%.16f\n", y);		/* $x_{n+1}$ ��ɽ�� {\hfill} */
    }
}

/* {\hrulefill} *

{\bf Simpson}�θ���

{\ % beginning of TeX mode

\noindent
����ʬ $\displaystyle\int_a^b f(x)\,dx$ ��׻������Ĥ���ˡ�Ȥ��ơ�
���ζ�������ɤ��Ȥ��롣

$$\int_a^b f(x)\,dx\sim{h\over3}\,(y_0+4y_1+2y_2+4y_3+2y_4+4y_5+
					\cdots +2y_{n-2}+4y_{n-1}+y_n)\ ,$$

\noindent
�����ǡ������� $n$ �϶����Ȥ���
$\displaystyle x_i=a+{i\over n}\,(b-a),\ y_i=f(x_i)\quad (i=0, 1, 2, \cdots, n)$
�Ȥ��롣
���θ����ξ����ϡ����Ū�䤵������
���ä�����Taylor ����������Ƴ���������

$$\int_{\xi-{1\over h}}^{\xi+{1\over h}}f(x)\,dx
	\sim\int_{\xi-{1\over h}}^{\xi+{1\over h}}p(x)\,dx
	={h\over3}\,\bigl(f(\xi-{1\over h})+4f(\xi)+f(\xi+{1\over h})\bigr)+O(h^5)$$

\noindent
�� $\,\displaystyle{n\over2}\,$ ��­����碌�뤳�Ȥˤ�ꡢ
���θ����Ͼ�������롣

\special{epsfile=simpson.eps hscale=.7 vscale=.7 hoffset=25}
\vskip 13cm

\noindent
�����ǡ�$p(x)$ �ϼ��Τ褦�ʾ�����­���룲����¿�༰��ɽ��:
$$
p\Bigl(\xi-{1\over h}\Bigr)=f\Bigl(\xi-{1\over h}\Bigr),
\ p(\xi)=f(\xi),
\ p\Bigl(\xi+{1\over h}\Bigr)=f\Bigl(\xi+{1\over h}\Bigr)\ .
$$

\noindent
{\tt A, B, F(X), N} ������򤤤�����Ѥ��ơ��ƿͤǿ��ͼ¸���ԤäƤߤ褦��

% end of TeX mode }

* {\hrulefill} */


/* {\hrulefill\ simpson.c\ \hrulefill} */


#include <stdio.h>
#define A 0.				/* ��ʬ�򤹤��� $[a, b]$ {\hfill} */
#define B 1.
#define F(X) ((X)*(X))			/* ����ʬ�ؿ� $f(x)$ {\hfill} */
#define N 20				/* {\ ��� $[a, b]$ ��ʬ��� $n$
					   \hfill} */

double simpson_rule()			/* {\ Simpson �θ������Ѥ���
					   $\displaystyle\int_a^b f(x)\,dx$
					   ��׻�����ؿ� \hfill} */
{
    long i;				/* long ������Ȥ� {\hfill} */
    double h, s, y[N + 1];		/* {\ ��å��� $h$, ��ʬ�� $s$,
					   ʬ�� $\displaystyle{i\over n}$
					   �Ǥδؿ��� $y_i$ \hfill} */

    h = 1. / (double) N;		/* {\ $\displaystyle h={1\over n}$
					 \hfill} */
    for (i = 0; i <= N; ++i)		/* {\ $\displaystyle y_i
					   =f\bigl({i\over n}\bigr)
					   \quad (i=0, 1, 2, \cdots, n)$
					   \hfill} */
	y[i] = F((double) i / (double) N);
					/* �ʲ��� {\hfill} */
					/* $\displaystyle
					   s={h\over3}(y_0+4y_1+2y_2+4y_3+
					   \cdots +4y_{n-1}+y_n)$ {\hfill} */
					/* �η׻� {\hfill} */
    s = y[0];
    for (i = 1; i < N; ++i)
    {
	if (i % 2 == 1)			/* {\ ������ {\tt i \% 2}= $i\ $
					   �� 2 �ǳ�ä�;�� \hfill} */
	    s += 4. * y[i];
	else
	    s += 2. * y[i];
    }
    s += y[N];
    s *= (h / 3.);
    return s;				/* $s$ ���ͤ��֤� {\hfill} */
}

main()
{
    double s;

    s = simpson_rule();			/* {\ �����������ؿ�
					   simpson\_rule() ��Ȥ� \hfill} */
    printf("%.16f\n", s);		/* {\ $s$ �򾮿����ʲ�16��ɽ������
					 \hfill} */
}

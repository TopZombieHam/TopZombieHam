;; {\documentstyle[a4j]{jarticle}}
;; {\src2tex{texfont=bf}}
;; [����] ���뤪ɴ�����󤬡���Ȭ�֤�����ʤ���¼�Ϥ����������δߤˤ�äƤ���
;; ��Ȭ�֤ˤϡ�����Ǥ�����줿����٥Ĥ����餤��϶�����ä��˥�ȥ꤬�Ѥޤ�
;; �Ƥ�������������¼�˻Ԥ�Ω�ĤΤǡ����λԤǥ���٥Ĥȥ˥�ȥ������Ȥ�
;; ���櫓�Ǥ��롣���θ�򡢤�ɴ������ˤ��ä���ʤĤ��Ƥ��ޤä����ĥͤΥ���
;; �����������ˤ�˥�ȥ�򿩤٤������ʤ��֤�ơ��夤����Ƥ�����
;; {\src2tex{texfont=rm}}
;; ���ơ���ΤۤȤ�ˤϰ��ۤξ����������Ĥʤ��Ǥ��ä����������ǡ���ɴ������
;; �ϥ˥�ȥꡢ����٥ġ����ĥͤΤ��٤Ƥ������δߤر��Фʤ���Фʤ�ʤ���
;; ���ä����Ȥˡ������������Ѿ������ä��Τǡ����򤢤�Ĥ뤪ɴ������ʳ���
;; ���٤˱��٤�Τϡ��˥�ȥꡢ����٥ġ����ĥͤΤ����Τɤ줫��Ĥ������ä���
;; �Ȥ�����ʢ�Τؤä��˥�ȥ�ϡ���ɴ�����󤬤��ʤ��ʤ�ȥ���٥Ĥ򿩤٤�
;; ���ޤ�������˥��ĥͤΥ������Ϥ�ɴ�������ܤ�Υ���ȡ��˥�ȥ�򿩤٤Ƥ�
;; �ޤ���
;; {\src2tex{texfont=bf}}
;; �ɤ���ä��顢��ɴ������ϼ����ɤ��˥�ȥꡢ����٥ġ����ĥͤΤ��٤Ƥ���
;; ¦�δߤ˱��٤��������

;; {\src2tex{texfont=sc}}
;; farmer+hen.scm  by  Kazuo AMANO
;; east-side-state is represented by list $(w\ x\ y\ z)$ where each $w, x, y, z = 0$ or $1$
;; example: {\null\[
;; \begin{array}{l}
;;	(1\ 1\ 1\ 1) = {\rm (farmer\ hen\ cabbage\ fox)-state}\\
;;	(0\ 1\ 0\ 1) = {\rm (none\ hen\ none\ fox)-state}\\
;;	(1\ 0\ 1\ 0) = {\rm (farmer\ none\ cabbage\ none)-state}
;; \end{array}
;; \]}
;; initial-state = (1 1 1 1)
;; state-sequence = (... state2 state1 initial-state)
;; state-tree = (... state-sequece2 state-sequence1 state-sequence0)

; {\src2tex{htab=4 textfont=it texfont=rm}}
;  ��������ؤΰ�ư
(define (west->east x seq)
  (let* ((y (car seq)) (fa (car y)) (he (cadr y)) (ca (caddr y)) (fo (cadddr y)))
    (cond ((= fa 0) (cons '() seq))
	  (else (cond ((and (equal? x 'hen) (= he 1)) (cons (list 0 0 ca fo) seq))
		      ((and (equal? x 'cabbage) (= ca 1)) (cons (list 0 he 0 fo) seq))
		      ((and (equal? x 'fox) (= fo 1)) (cons (list 0 he ca 0) seq))
		      (else (cons '() seq)))))))

; {\src2tex{htab=4 textfont=it texfont=rm}}
;  �줫�����ؤΰ�ư
(define (west<-east x seq)
  (let* ((y (car seq)) (fa (car y)) (he (cadr y)) (ca (caddr y)) (fo (cadddr y)))
    (cond ((= fa 1) (cons '() seq))
	  (else (cond ((and (equal? x 'hen) (= he 0)) (cons (list 1 1 ca fo) seq))
		      ((and (equal? x 'cabbage) (= ca 0)) (cons (list 1 he 1 fo) seq))
		      ((and (equal? x 'fox) (= fo 0)) (cons (list 1 he ca 1) seq))
		      ((equal? x 'none) (cons (list 1 he ca fo) seq))
		      (else (cons '() seq)))))))

; {\src2tex{htab=4 textfont=sl texfont=rm}}
;  ��λ��Ƚ��򤹤�ؿ�
(define (finished? tree)
  (let finished1? ((x tree))
    (cond ((null? x) #f)
	  ((equal? (caar x) '(0 0 0 0)) #t)
	  (else (finished1? (cdr x))))))

; {\src2tex{htab=4 textfont=sl texfont=rm}}
;  ��Ŭ���� branch ���ڤ���Ȥ��ؿ�
(define (rm-bad-seq tree)
  (let rm-bad-seq1 ((x tree) (y '()))
    (cond ((null? x) y)
	  ((null? (caar x)) (rm-bad-seq1 (cdr x) y))
	  ((equal? (caar x) '(1 0 1 0)) (rm-bad-seq1 (cdr x) y))
	  ((equal? (caar x) '(1 0 0 1)) (rm-bad-seq1 (cdr x) y))
	  ((equal? (caar x) '(0 1 1 0)) (rm-bad-seq1 (cdr x) y))
	  ((equal? (caar x) '(0 1 0 1)) (rm-bad-seq1 (cdr x) y))
	  ((equal? (caar x) '(1 1 1 1)) (rm-bad-seq1 (cdr x) y))
	  (else (rm-bad-seq1 (cdr x) (cons (car x) y))))))

; {\src2tex{htab=4 textfont=sl texfont=bf}}
;  branch ����Ĺ������ؿ�
(define (mkseq seq)
    (rm-bad-seq
     (list (west->east 'hen seq) (west->east 'cabbage seq) (west->east 'fox seq)
	   (west<-east 'hen seq) (west<-east 'cabbage seq) (west<-east 'fox seq)
	   (west<-east 'none seq))))

; {\src2tex{htab=4 textfont=tt texfont=bf}}
;  ���� tree ����ؿ�
(define (mktree initial-state)
  (let mktree1 ((x (list (list initial-state))))
    (cond ((finished? x) x)
	  (else (mktree1 (let mktree2 ((x1 x) (x2 '()))
			   (cond ((null? x1) x2)
				 (else (mktree2 (cdr x1) (append x2 (mkseq (car x1))))))))))))

; {\src2tex{htab=4 textfont=bf texfont=bf}}
;  main �ؿ�
(define (main-func)
  (let display-answer ((x (mktree '(1 1 1 1))))
    (cond ((null? x) (newline))
	  (else (cond ((equal? (caar x) '(0 0 0 0)) (display (car x)) (newline)))
		(display-answer (cdr x))))))

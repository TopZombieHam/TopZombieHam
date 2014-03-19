#{\hrulefill\ {\tt\#}
#	\vskip 1ex
#	\input fonts.tex % define fonts
#	\input title.tex % title and authors
#	\vskip 1ex
# \noindent{\tt\#}\ \hrulefill\ {\tt\#}}


#{\hrulefill\ Makefile\ \hrulefill\ {\tt\#}}


#{\hrulefill\ preliminaries\ \hrulefill\ {\tt\#}
# \par
# Here we just give preliminary definitions.
# If you don't have {\tt gcc}, please replace it with {\tt cc}
# and plug suitable values into {\tt CFLAGS}.
# \par
# \noindent{\tt\#}\ \hrulefill\ {\tt\#}}

CC	= gcc
CFLAGS	= -O2
SRCS	= fileio.c getdata.c langflag.c modflag.c options.c pas_bold.c \
	tools.c text2tex.c src2tex.c
OBJS	= fileio.o getdata.o langflag.o modflag.o options.o pas_bold.o \
	tools.o text2tex.o src2tex.o

#{\hrulefill\ make all\ \hrulefill\ {\tt\#}
# \par
# ``{\tt make all}'' gives you {\sl src2tex} and {\sl src2latex}.
# Hopefully, you do not encounter any errors.
# \par
# \noindent{\tt\#}\ \hrulefill\ {\tt\#}}

all :
	$(CC) $(CFLAGS) -DUNIX -DTEX -c $(SRCS)
	$(CC) $(OBJS) -o src2tex
	$(CC) $(CFLAGS) -DUNIX -DLATEX -c $(SRCS)
	$(CC) $(OBJS) -o src2latex

#{\hrulefill\ make install\ \hrulefill\ {\tt\#}
# \par
# ``{\tt make install}'' just strips {\sl src2tex} and {\sl src2latex},
# and removes object files.
# You have to move executables to your favorite directory by yourself.
# No online manual is available at the moment.
# \par
# \noindent{\tt\#}\ \hrulefill\ {\tt\#}}

install :
	strip ./src2tex
	strip ./src2latex
	rm -f ./$(OBJS)
	@-echo ""
	@-echo " So, you have finished installation successively."
	@-echo " Please copy src2tex and src2latex to a suitable"
	@-echo " directory you like."
	@-echo ""

install.man :
	@-echo ""
	@-echo " Sorry, there exists no online manual."
	@-echo ""

#{\hrulefill\ make dos\ \hrulefill\ {\tt\#}
# \par
# If you are a DOS user,
# please just type ``{\tt make dos}''
# instead of ``{\tt make all}'' and ``{\tt make install}''.
# Then you will get {\sl src2tex.exe} and {\sl src2ltex.exe} .
# IF you don't have {\tt gcc},
# please replace it with {\tt cc} or something like that.
# \par
# \noindent{\tt\#}\ \hrulefill\ {\tt\#}}

dos :
	@-echo ""
	@-echo " Please don't be panic when  \"make dos\"  does not work."
	@-echo " What you have to do is to be patient and edit Makefile"
	@-echo " carefully.  I am sure it would turn out to be a piece"
	@-echo " of cake."
	@-echo ""
	$(CC) $(CFLAGS) -DDOS -DTEX -c $(SRCS)
	$(CC) $(OBJS) -o src2tex
	$(CC) $(CFLAGS) -DDOS -DLATEX -c $(SRCS)
	$(CC) $(OBJS) -o src2ltex
	del *.o

#{\hrulefill\ make verbose\ \hrulefill\ {\tt\#}
# \par
# ``{\tt make verbose}'' generates noisy {\sl src2tex} and {\sl src2latex}.
# They report everything what they are doing.
# The authors are using them to find bugs.
# \par
# \noindent{\tt\#}\ \hrulefill\ {\tt\#}}

verbose :
	$(CC) -DDEBUGGING -DUNIX -DTEX -c $(SRCS)
	$(CC) $(OBJS) -o src2tex
	$(CC) -DDEBUGGING -DUNIX -DLATEX -c $(SRCS)
	$(CC) $(OBJS) -o src2latex

#{\hrulefill\ make plain\ \hrulefill\ {\tt\#}
# \par
# ``{\tt make plain}'' generates plain {\sl src2tex} and {\sl src2latex}.
# They do not output any preambles and postambles;
# they simply output {\TeX}t without anything like
# \item{}
# $\backslash$documentstyle$\cdots$,
# \item{}
# $\backslash$begin{document},
# \item{}
# $\backslash$end{document},
# \item{}
# $\backslash$bye,
# \par
# \noindent They would be useful when you have to insert program lists
# into your manuscript written in {\TeX}.
# \par
# \noindent{\tt\#}\ \hrulefill\ {\tt\#}}

plain :
	$(CC) -DPLAIN -DUNIX -DTEX -c $(SRCS)
	$(CC) $(OBJS) -o src2tex
	$(CC) -DPLAIN -DUNIX -DLATEX -c $(SRCS)
	$(CC) $(OBJS) -o src2latex

clean :
	rm -f ./$(OBJS)
	rm -f ./a.out
	rm -f ./src2tex
	rm -f ./src2latex ./src2ltex
	rm -f ./*~
	rm -f ./*.bak
	rm -f ./Makefile.tex
	rm -f ./*.h.tex
	rm -f ./*.c.tex
	rm -f ./*.scm.tex
	rm -f ./*.red.tex
	rm -f ./contrib/src2tex2dvi.tex
	rm -f ./contrib/src2tex2ps.tex
	rm -f ./contrib/src2latex2dvi.tex
	rm -f ./contrib/src2latex2ps.tex
	rm -f ./contrib/c2tex.tex
	rm -f ./contrib/*~
	rm -f ./contrib/*.bak

#{\hrulefill\ make docs\ \hrulefill\ {\tt\#}
# \par
# ``{\tt make docs}'' simply generates several examples
# by using {\sl src2tex2ps}, {\sl src2latex2ps}, {\it etc\/}.
# \par
# \noindent{\tt\#}\ \hrulefill\ {\tt\#}}

docs :
	src2tex2dvi Makefile
	src2tex2ps *.h
	src2tex2ps *.c
	src2latex2ps *.scm
	src2tex2ps popgen.red
	src2tex2ps -fourcolumns -pagelength 35 sqrt_mat.red
	cd ./contrib ; src2tex2dvi src2tex2dvi
	cd ./contrib ; src2tex2dvi src2tex2ps
	cd ./contrib ; src2tex2dvi src2latex2dvi
	cd ./contrib ; src2tex2dvi src2latex2ps
	cd ./contrib ; src2tex2dvi c2tex

#{\hrulefill\ make report\ \hrulefill\ {\tt\#}
# \par
# ``{\tt make report}'' send your local {\sl /etc/motd} file
# to one of the authors.
# This would be quite helpful for further development of {\sl src2tex}.
# \par
# \noindent{\tt\#}\ \hrulefill\ {\tt\#}}

report :
	@-if [ -f /etc/motd ] ; \
	then \
		echo "TITLE:src2tex version 2.12" > make_report.log; \
		echo USER:$(USER) >> make_report.log; \
		echo HOSTNAME:$(HOSTNAME) >> make_report.log; \
		cat /etc/motd >> make_report.log; \
		echo -n "reporting to kamano@po.iijnet.or.jp ... " ; \
		mail kamano@po.iijnet.or.jp \
			< make_report.log ; \
		echo "done" ; \
		rm make_report.log ; \
	else \
		echo "make report failed" ; \
		echo "thank you very much anyway" ; \
	fi

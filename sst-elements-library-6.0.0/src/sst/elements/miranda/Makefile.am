
AM_CPPFLAGS = \
	$(BOOST_CPPFLAGS) \
	$(MPI_CPPFLAGS) \
	-I$(top_srcdir)/src

compdir = $(pkglibdir)
comp_LTLIBRARIES = libmiranda.la

libmiranda_la_SOURCES = \
	miranda.cc \
	mirandaEvent.h \
	mirandaGenerator.h \
	mirandaCPU.cc \
	mirandaCPU.h	\
	generators/singlestream.h \
	generators/singlestream.cc \
	generators/randomgen.h \
	generators/randomgen.cc \
	generators/streambench.h \
	generators/streambench.cc \
	generators/revsinglestream.h \
	generators/inorderstreambench.h \
	generators/revsinglestream.cc \
	generators/stencil3dbench.h \
	generators/stencil3dbench.cc \
	generators/gupsgen.h \
	generators/gupsgen.cc \
	generators/nullgen.h \
	generators/spmvgen.h \
	generators/copygen.h

EXTRA_DIST = \
	tests/randomgen.py \
	tests/singlestream.py \
	tests/revsinglestream.py \
	tests/stencil3dbench.py \
	tests/streambench.py \
	tests/inorderstream.py \
	tests/copybench.py

libmiranda_la_LDFLAGS = -module -avoid-version

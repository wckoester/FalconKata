## Process this file with automake to produce Makefile.in

TESTS = check_roman
check_PROGRAMS = check_roman
check_roman_SOURCES = check_roman.c $(top_builddir)/src/roman.h
check_roman_CFLAGS = $(CFLAGS) $(CHECK_FLAGS)
check_roman_LDADD = $(top_builddir)/src/libroman.a $(LDFLAGS) $(CHECK_LIBS)

#
# Sample makefile for bash loadable builtin development
#
# Copyright (C) 2015-2022 Free Software Foundation, Inc.     

#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

PACKAGE = bash
VERSION = 5.2-release

PACKAGE_NAME = bash
PACKAGE_VERSION = 5.2-release

# Include some boilerplate Gnu makefile definitions.
prefix = /usr/local

exec_prefix = ${prefix}
bindir = ${exec_prefix}/bin
libdir = ${exec_prefix}/lib
infodir = ${datarootdir}/info
includedir = ${prefix}/include

datarootdir = ${prefix}/share

loadablesdir = ${libdir}/bash
headersdir = $(includedir)/$(PACKAGE_NAME)

topdir = ../..
BUILD_DIR = /work/src/bash-5.2.37
srcdir = .


# Support an alternate destination root directory for package building
DESTDIR =

INSTALL = ../../././support/install.sh -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
INSTALLMODE= -m 0755


CC = gcc -std=gnu11
RM = rm -f

SHELL = /bin/sh

host_os = osf5.1b
host_cpu = alphaev56
host_vendor = dec

CFLAGS = -O2 -mcpu=ev56 -D_OSF_SOURCE
LOCAL_CFLAGS = 
DEFS = -DHAVE_CONFIG_H
LOCAL_DEFS = -DSHELL

CPPFLAGS = -I/usr/local/include

BASHINCDIR = ${topdir}/include

SUPPORT_SRC = $(topdir)/support/

LIBBUILD = ${BUILD_DIR}/lib

INTL_LIBSRC = ${topdir}/lib/intl
INTL_BUILDDIR = ${LIBBUILD}/intl
INTL_INC = 
LIBINTL_H = 

CCFLAGS = $(DEFS) $(LOCAL_DEFS) $(LOCAL_CFLAGS) $(CFLAGS)

#
# These values are generated for configure by ${topdir}/support/shobj-conf.
# If your system is not supported by that script, but includes facilities for
# dynamic loading of shared objects, please update the script and send the
# changes to bash-maintainers@gnu.org.
#
SHOBJ_CC = gcc -std=gnu11
SHOBJ_CFLAGS = 
SHOBJ_LD = ${CC}
SHOBJ_LDFLAGS = -shared -Wl,-soname,$@ 
SHOBJ_XLDFLAGS = 
SHOBJ_LIBS = 
SHOBJ_STATUS = supported

INC = -I$(headersdir) -I$(headersdir)/include -I$(headersdir)/builtins

.c.o:
	$(SHOBJ_CC) $(SHOBJ_CFLAGS) $(CCFLAGS) $(INC) -c -o $@ $<

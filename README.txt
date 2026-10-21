=============================================================
GNU Bash 5.2.37 for Tru64 UNIX (OSF/1 5.1b) - Binary Package
Target: alphaev56-dec-osf5.1b
=============================================================

1. DESCRIPTION
   This package contains GNU Bash 5.2.37 built natively on
   Tru64 UNIX v5.1B (DEC Alpha EV56).
   It includes runtime shared libraries:
     - GNU gettext (libintl.so.1.0.1)
     - GNU libiconv (libiconv.so.3.1.0)

2. EXTRACT & FIX SYMLINKS
   Run the following commands as root to extract:

   # cd /usr/local
   # gzip -dc /path/to/Tru64_Bash_5.2.37_with_libs.tar.gz | /sbin/tar xvf -

   # Verify/fix library symlinks in /usr/local/lib:
   # cd /usr/local/lib
   # ln -sf libintl.so.1.0.1 libintl.so
   # ln -sf libiconv.so.3.1.0 libiconv.so
   # ln -sf libiconv.so.3.1.0 libiconv.so.3

3. REGISTRATION (/etc/shells)
   Add the following line to /etc/shells if not already present:

   /usr/local/bin/bash

4. ENVIRONMENT SETUP (.profile)
   Ensure /usr/local/lib is in your LD_LIBRARY_PATH:

   export LD_LIBRARY_PATH=/usr/local/lib:/usr/shlib:$LD_LIBRARY_PATH

   Add the following snippet to your ~/.profile for automatic session upgrade:

   if [ -x /usr/local/bin/bash ] && [ "$BASH_EXECED" != "1" ]; then
       case "$-" in
           *i*)
               export BASH_EXECED=1
               exec /usr/local/bin/bash -l
               ;;
       esac
   fi

5. VERIFICATION
   Test the installation using:

   # /usr/local/bin/bash --version
=============================================================

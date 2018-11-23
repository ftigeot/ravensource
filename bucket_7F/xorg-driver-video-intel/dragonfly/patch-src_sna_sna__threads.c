--- src/sna/sna_threads.c.orig	2018-09-06 12:00:04 UTC
+++ src/sna/sna_threads.c
@@ -29,6 +29,9 @@
 #include "config.h"
 #endif
 
+#define _WITH_GETLINE	/* to expose getline() in stdio.h on FreeBSD */
+#include <stdio.h>	/* for getline() */
+
 #include "sna.h"
 
 #include <unistd.h>

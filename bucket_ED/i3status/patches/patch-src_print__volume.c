--- src/print_volume.c.orig	2018-05-11 09:10:46 UTC
+++ src/print_volume.c
@@ -61,7 +61,7 @@ void print_volume(yajl_gen json_gen, cha
         free(instance);
     }
 
-#ifndef __OpenBSD__
+#if ! (defined __OPENBSD__  || defined __FreeBSD__ || defined __DragonFly__)
     /* Try PulseAudio first */
 
     /* If the device name has the format "pulse[:N]" where N is the

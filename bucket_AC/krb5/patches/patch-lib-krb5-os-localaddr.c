--- lib/krb5/os/localaddr.c.orig	2019-01-07 17:19:42 UTC
+++ lib/krb5/os/localaddr.c
@@ -176,6 +176,7 @@ printaddr(struct sockaddr *sa)
 }
 #endif
 
+#if 0
 static int
 is_loopback_address(struct sockaddr *sa)
 {
@@ -192,6 +193,7 @@ is_loopback_address(struct sockaddr *sa)
         return 0;
     }
 }
+#endif
 
 #ifdef HAVE_IFADDRS_H
 #include <ifaddrs.h>
@@ -463,12 +465,14 @@ foreach_localaddr (/*@null@*/ void *data
             ifp->ifa_flags &= ~IFF_UP;
             continue;
         }
+#if 0
         if (is_loopback_address(ifp->ifa_addr)) {
             /* Pretend it's not up, so the second pass will skip
                it.  */
             ifp->ifa_flags &= ~IFF_UP;
             continue;
         }
+#endif
         /* If this address is a duplicate, punt.  */
         match = 0;
         for (ifp2 = ifp_head; ifp2 && ifp2 != ifp; ifp2 = ifp2->ifa_next) {
@@ -597,11 +601,13 @@ foreach_localaddr (/*@null@*/ void *data
             }
             /*@=moduncon@*/
 
+#if 0
             /* None of the current callers want loopback addresses.  */
             if (is_loopback_address((struct sockaddr *)&lifr->lifr_addr)) {
                 Tprintf (("  loopback\n"));
                 goto skip;
             }
+#endif
             /* Ignore interfaces that are down.  */
             if ((lifreq.lifr_flags & IFF_UP) == 0) {
                 Tprintf (("  down\n"));
@@ -768,11 +774,13 @@ foreach_localaddr (/*@null@*/ void *data
             }
             /*@=moduncon@*/
 
+#if 0
             /* None of the current callers want loopback addresses.  */
             if (is_loopback_address(&lifr->iflr_addr)) {
                 Tprintf (("  loopback\n"));
                 goto skip;
             }
+#endif
             /* Ignore interfaces that are down.  */
             if ((lifreq.iflr_flags & IFF_UP) == 0) {
                 Tprintf (("  down\n"));
@@ -986,11 +994,13 @@ foreach_localaddr (/*@null@*/ void *data
         }
         /*@=moduncon@*/
 
+#if 0
         /* None of the current callers want loopback addresses.  */
         if (is_loopback_address(&ifreq.ifr_addr)) {
             Tprintf (("  loopback\n"));
             goto skip;
         }
+#endif
         /* Ignore interfaces that are down.  */
         if ((ifreq.ifr_flags & IFF_UP) == 0) {
             Tprintf (("  down\n"));
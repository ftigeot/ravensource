--- ext/NDBM_File/Makefile.PL.orig	2017-07-18 22:49:57 UTC
+++ ext/NDBM_File/Makefile.PL
@@ -4,5 +4,6 @@ WriteMakefile(
     LIBS => ["-L/usr/local/lib -lndbm", "-ldbm -lucb"],
     XSPROTOARG => '-noprototypes', 		# XXX remove later?
     VERSION_FROM => 'NDBM_File.pm',
+    dynamic_lib => { OTHERLDFLAGS => "-Wl,-rpath,@PREFIX@/lib" },
     INC => ($^O eq "MacOS" ? "-i ::::db:include" : "")
 );

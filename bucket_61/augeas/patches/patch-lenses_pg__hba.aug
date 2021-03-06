--- lenses/pg_hba.aug.orig	2016-05-07 22:55:54 UTC
+++ lenses/pg_hba.aug
@@ -81,6 +81,7 @@ module Pg_Hba =
     (* View: filter
         The pg_hba.conf conf file *)
     let filter = (incl "/var/lib/pgsql/data/pg_hba.conf" .
+                  incl "%%PREFIX%%/pgsql/data/pg_hba.conf" .
                   incl "/var/lib/pgsql/*/data/pg_hba.conf" .
                   incl "/var/lib/postgresql/*/data/pg_hba.conf" .
                   incl "/etc/postgresql/*/*/pg_hba.conf" )

--- linux/dvb/ca.h.orig	2014-12-01 09:58:18 UTC
+++ linux/dvb/ca.h
@@ -24,6 +24,10 @@
 #ifndef _DVBCA_H_
 #define _DVBCA_H_
 
+#ifdef __sun__
+#include <sys/ioccom.h>
+#endif
+
 /* slot interface types and info */
 
 typedef struct ca_slot_info {
@@ -80,9 +84,17 @@ typedef struct ca_pid {
 
 #define CA_RESET          _IO('o', 128)
 #define CA_GET_CAP        _IOR('o', 129, ca_caps_t)
+
+/* At least CA_GET_SLOT_INFO and CA_GET_MSG need to be _IOWR not _IOR.
+ * This is wrong on Linux too but there the driver doesn't care.
+ *
 #define CA_GET_SLOT_INFO  _IOR('o', 130, ca_slot_info_t)
 #define CA_GET_DESCR_INFO _IOR('o', 131, ca_descr_info_t)
 #define CA_GET_MSG        _IOR('o', 132, ca_msg_t)
+ */
+#define CA_GET_SLOT_INFO  _IOWR('o', 130, ca_slot_info_t)
+#define CA_GET_DESCR_INFO _IOR('o', 131, ca_descr_info_t)
+#define CA_GET_MSG        _IOWR('o', 132, ca_msg_t)
 #define CA_SEND_MSG       _IOW('o', 133, ca_msg_t)
 #define CA_SET_DESCR      _IOW('o', 134, ca_descr_t)
 #define CA_SET_PID        _IOW('o', 135, ca_pid_t)

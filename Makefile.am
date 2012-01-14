ACLOCAL_AMFLAGS = -I m4

plugin_LTLIBRARIES = gkr.la

gkr_la_SOURCES = src/plugin.c
gkr_la_LDFLAGS = -avoid-version -module
gkr_la_LIBADD = $(CLAWS_MAIL_LIBS) $(GNOME_KEYRING_LIBS)
gkr_la_CPPFLAGS = $(CLAWS_MAIL_CFLAGS) $(GNOME_KEYRING_CFLAGS)

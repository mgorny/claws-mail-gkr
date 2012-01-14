AC_PREREQ([2.60])
AC_INIT([claws-mail-gkr], [0])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([1.6 foreign dist-bzip2])

AC_PROG_CC
AC_USE_SYSTEM_EXTENSIONS
LT_INIT([disable-static])

PKG_CHECK_MODULES([CLAWS_MAIL], [claws-mail glib-2.0 gtk+-2.0])
PKG_CHECK_MODULES([GNOME_KEYRING], [gnome-keyring-1])

AC_MSG_CHECKING([for claws-mail plugin location])
plugindir=`$PKG_CONFIG --variable=plugindir claws-mail`
AC_MSG_RESULT([$plugindir])
AC_SUBST([plugindir])

AC_CONFIG_HEADER([config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

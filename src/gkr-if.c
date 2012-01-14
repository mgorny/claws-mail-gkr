#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <glib.h>

gboolean password_get_hook(gpointer source, gpointer hook_data) {
	g_print("password_get_hook() called.\n");

	return FALSE;
}

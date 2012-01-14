#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <glib.h>
#include <glib/gi18n.h>

#include "version.h"
#include "plugin.h"

#define PLUGIN_NAME (_("gnome-keyring"))

gint plugin_init(gchar **error)
{
	if (!check_plugin_version(MAKE_NUMERIC_VERSION(3,8,1,0),
				VERSION_NUMERIC, PLUGIN_NAME, error))
		return -1;

	return 0;
}

gboolean plugin_done(void)
{
	return TRUE;
}

const gchar *plugin_name(void)
{
	return PLUGIN_NAME;
}

const gchar *plugin_desc(void)
{
	return _("This plugin adds support for stroing password in gnome-keyring.");
}

const gchar *plugin_type(void)
{
	return "GTK2";
}

const gchar *plugin_licence(void)
{
	return "BSD";
}

const gchar *plugin_version(void)
{
	return VERSION;
}

struct PluginFeature *plugin_provides(void)
{
	static struct PluginFeature features[] = {
		{PLUGIN_OTHER, N_("Password storage")},
		{PLUGIN_NOTHING, NULL}
	};

	return features;
}

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <glib.h>
#include <gnome-keyring.h>

/* claws-mail */
#include "common/utils.h"
#include "gtk/inputdialog.h"

gchar *gkr_getpass(const gchar *user, const gchar *server, const gchar *proto) {
	GnomeKeyringResult ret;
	GList *items;
	GnomeKeyringInfo *gki;
	gchar *pass = NULL;

	if (!gnome_keyring_is_available())
		return NULL;

	ret = gnome_keyring_get_info_sync(NULL, &gki);
	if (ret == GNOME_KEYRING_RESULT_OK) {
		if (gnome_keyring_info_get_is_locked(gki)) {
			gchar *kpass = input_dialog_with_invisible("Keyring password input",
					"Input password for the default keyring:", NULL);

			if (kpass) {
				ret = gnome_keyring_unlock_sync(NULL, kpass);
				if (ret != GNOME_KEYRING_RESULT_OK)
					debug_print("gnome_keyring_unlock_sync() failed: %s\n",
							gnome_keyring_result_to_message(ret));
				g_free(kpass);
			}
		}

		gnome_keyring_info_free(gki);
	} else
		debug_print("gnome_keyring_get_info_sync() failed: %s\n",
				gnome_keyring_result_to_message(ret));

	ret = gnome_keyring_find_network_password_sync(user, NULL, server, NULL,
			proto, NULL, 0, &items);
	if (ret == GNOME_KEYRING_RESULT_OK) {
		if (items && items->data) {
			GnomeKeyringNetworkPasswordData *item = items->data;

			if (item->password && *(item->password)) {
				pass = g_strdup(item->password);
				gnome_keyring_network_password_list_free(items);
			}

			gnome_keyring_network_password_list_free(items);
		}
	} else
		debug_print("gnome_keyring_find_network_password_sync() failed: %s\n",
				gnome_keyring_result_to_message(ret));

	return pass;
}

/* libsecret - GLib wrapper for Secret Service
 *
 * Copyright 2011 Collabora Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2 of the licence or (at
 * your option) any later version.
 *
 * See the included COPYING file for more information.
 */

#ifndef __SECRET_PROMPT_H__
#define __SECRET_PROMPT_H__

#include <gio/gio.h>

#include "secret-types.h"

G_BEGIN_DECLS

#define SECRET_TYPE_PROMPT            (secret_prompt_get_type ())
#define SECRET_PROMPT(inst)           (G_TYPE_CHECK_INSTANCE_CAST ((inst), SECRET_TYPE_PROMPT, SecretPrompt))
#define SECRET_PROMPT_CLASS(class)    (G_TYPE_CHECK_CLASS_CAST ((class), SECRET_TYPE_PROMPT, SecretPromptClass))
#define SECRET_IS_PROMPT(inst)        (G_TYPE_CHECK_INSTANCE_TYPE ((inst), SECRET_TYPE_PROMPT))
#define SECRET_IS_PROMPT_CLASS(class) (G_TYPE_CHECK_CLASS_TYPE ((class), SECRET_TYPE_PROMPT))
#define SECRET_PROMPT_GET_CLASS(inst) (G_TYPE_INSTANCE_GET_CLASS ((inst), SECRET_TYPE_PROMPT, SecretPromptClass))

typedef struct _SecretPromptClass   SecretPromptClass;
typedef struct _SecretPromptPrivate SecretPromptPrivate;

struct _SecretPrompt {
	GDBusProxy parent_instance;
	SecretPromptPrivate *pv;
};

struct _SecretPromptClass {
	GDBusProxyClass parent_class;
	gpointer padding[8];
};

GType               secret_prompt_get_type                  (void) G_GNUC_CONST;

SecretPrompt *     secret_prompt_instance                  (SecretService *service,
                                                              const gchar *prompt_path);

gboolean            secret_prompt_run                       (SecretPrompt *self,
                                                              gulong window_id,
                                                              GCancellable *cancellable,
                                                              GError **error);

gboolean            secret_prompt_perform_sync              (SecretPrompt *self,
                                                              gulong window_id,
                                                              GCancellable *cancellable,
                                                              GError **error);

void                secret_prompt_perform                   (SecretPrompt *self,
                                                              gulong window_id,
                                                              GCancellable *cancellable,
                                                              GAsyncReadyCallback callback,
                                                              gpointer user_data);

gboolean            secret_prompt_perform_finish            (SecretPrompt *self,
                                                              GAsyncResult *result,
                                                              GError **error);

GVariant *          secret_prompt_get_result_value          (SecretPrompt *self,
                                                              const GVariantType *expected_type);

G_END_DECLS

#endif /* __G_SERVICE_H___ */
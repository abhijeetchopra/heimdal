/*
 * Copyright (c) 2011, Secure Endpoints Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef HEIMDAL_KRB5_KUSEROK_PLUGIN_H
#define HEIMDAL_KRB5_KUSEROK_PLUGIN_H 1

#define KRB5_PLUGIN_KUSEROK "kuserok-plugin"
#define KRB5_PLUGIN_KUSEROK_VERSION_0 0

typedef krb5_error_code (*set_result_f)(void *, const char *);

typedef struct krb5plugin_kuserok_ftable_desc {
    int			minor_version;
    krb5_error_code	(*init)(krb5_context, void **);
    void		(*fini)(void *);
    krb5_error_code	(*kuserok)(void *, krb5_context, const char *,
				   unsigned int, const char *, const char *,
				   krb5_const_principal,
				   krb5_boolean *);
} krb5plugin_kuserok_ftable;

#define KUSEROK_ANAME_TO_LNAME_OK        1
#define KUSEROK_K5LOGIN_IS_AUTHORITATIVE 2

#endif /* HEIMDAL_KRB5_KUSEROK_PLUGIN_H */
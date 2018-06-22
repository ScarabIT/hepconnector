/*
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *  captagent - Homer capture agent. Modular
 *  Duplicate SIP messages in Homer Encapulate Protocol [HEP] [ipv6 version]
 *
 *  Author: Alexandr Dubovikov <alexandr.dubovikov@gmail.com>
 *  (C) Homer Project 2012 (http://www.sipcapture.org)
 *
 *  Copyright (c) 2010-2016 <Alexandr Dubovikov>
 *  All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the <SIPCAPTURE>. The name of the SIPCAPTURE may not be used to
 * endorse or promote products derived from this software without specific
 * prior written permission.

 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Copyright (c) 2018 Maksym Sobolyev <sobomax@gmail.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 */

struct rc_info;
typedef struct rc_info rc_info_t;

struct hep_ctx {
    int sock;
    long initfails;
    struct addrinfo *ai;
    const struct addrinfo *hints;
    char *capt_host;
    char capt_port[sizeof("65535") + 1];
    char *capt_password;
    int   capt_id;
    int hep_version;
    int usessl;
    int pl_compress;

    struct hep_generic *hep_hdr;
    u_int16_t hdr_len;

    int sendPacketsCount;

#ifdef USE_SSL
    SSL *ssl;
    SSL_CTX *ctx;
#endif /* USE_SSL */
};

void hep_gen_dtor(struct hep_ctx *);
int hep_gen_fill(struct hep_ctx *, rc_info_t *);
int hep_gen_append(struct hep_ctx *, u_int16_t, u_int16_t, void *, u_int16_t);
int send_hep(struct hep_ctx *, rc_info_t *rcinfo, void *data, unsigned int len);
int init_hepsocket_blocking(struct hep_ctx *);
int init_hepsocket(struct hep_ctx *);

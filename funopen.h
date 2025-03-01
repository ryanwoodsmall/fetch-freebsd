/*
 * Copyright © 2004-2005, 2009, 2011-2013 Guillem Jover <guillem@hadrons.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef FUNOPEN_H
#define FUNOPEN_H

/*
 * Note: We diverge from the FreeBSD, OpenBSD and DragonFlyBSD declarations,
 * because seekfn() there wrongly uses fpos_t, assuming it's an integral
 * type, and any code using that on a system where fpos_t is a struct
 * (such as GNU-based systems or NetBSD) will fail to build. In which case,
 * as the code has to be modified anyway, we might just as well use the
 * correct declaration here.
 */
FILE *funopen(const void *cookie,
              int (*readfn)(void *cookie, char *buf, int size),
              int (*writefn)(void *cookie, const char *buf, int size),
              off_t (*seekfn)(void *cookie, off_t offset, int whence),
              int (*closefn)(void *cookie));

#endif

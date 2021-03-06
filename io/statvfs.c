/* Return information about the filesystem on which FILE resides.
   Copyright (C) 1998 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#include <errno.h>
#include <sys/statvfs.h>
#include <sys/statfsx.h>
#include <stddef.h>
#ifdef __WIN32__
#include <windows.h>
#include <stdio.h>
#include <limits.h>
#include <sys/fsinfo.h>
#endif /* __WIN32__ */

/* Return information about the filesystem on which FILE resides.  */
int
__statvfs (const char *file, struct statvfs *buf)
{
	struct statfsx64 xbuf;
	int res;
	res = __statfsx64(file, &xbuf);
	buf->f_bsize = xbuf.f_bsize;
	buf->f_frsize = xbuf.f_frsize;
	buf->f_blocks = xbuf.f_blocks;
	buf->f_bfree = xbuf.f_bfree;
	buf->f_bavail = xbuf.f_bavail;
	buf->f_files = xbuf.f_files;
	buf->f_ffree = xbuf.f_ffree;
	buf->f_favail = xbuf.f_favail;
	buf->f_fsid = xbuf.f_fsid;
	buf->f_flag = xbuf.f_flag;
	buf->f_namemax = xbuf.f_namelen;
	buf->f_spare[0] = 0;
	buf->f_spare[1] = 0;
	buf->f_spare[2] = 0;
	buf->f_spare[3] = 0;
	buf->f_spare[4] = 0;
	buf->f_spare[5] = 0;
	return res;
}
weak_alias (__statvfs, statvfs)
#ifndef __WIN32__
stub_warning (statvfs)
#include <libc/stub-tag.h>
#endif /* __WIN32__ */


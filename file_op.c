/*
 * Copyright (C) 2014 Wowz Labs.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*
 * File system operations functions code goes here
 */

#include <linux/module.h>
#include <linux/mm.h>

#include "multidevfs.h"

const struct file_operations multidevfs_file_operations = {
	.llseek		= multidevfs_llseek,
        .read           = multidevfs_read,
	.write		= multidevfs_write,
        .aio_read       = generic_file_aio_read,
        .aio_write      = generic_file_aio_write,
	.iterate	= multidevfs_iterate,
	.poll		= multidevfs_poll,
	.unlocked_ioctl	= multidevfs_unlocked_ioctl,
        .mmap           = generic_file_mmap,
	.open		= multidevfs_open,
	.flush		= multidevfs_flush,
	.release	= multidevfs_release,
        .fsync          = noop_fsync,
	.aio_fsync	= multidevfs_aio_fsync,
	.fasync		= multidevfs_fasync,
	.lock		= multidevfs_lock,
	.readv		= multidevfs_readv,
	.writev		= multidevfs_writev,
	.sendfile	= multidevfs_sendfile,
	.sendpage	= multidevfs_sendpage,
	
	.get_unmapped_area	= multidevfs_get_unmapped_area,

	.check_flags	= multidevfs_check_flags,
	.flock		= mutidevfs_flock,
	.splice_write	= mutidevfs_splice_write,
	.splice_read	= mutidevfs_splice_read,
	.setlease	= mutidevfs_setlease,
	.fallocate	= mutidevfs_fallocate
};


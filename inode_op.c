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
 * File inode operations functions code goes here
 */

#include <linux/module.h>
#include <linux/mm.h>

#include "multidevfs.h"

const struct inode_operations multidevfs_file_inode_operations = {
	.create		= multidefs_create_file,
	.lookup		= multidevfs_lookup,
	.link		= multidevfs_link,
	.unlink		= multidefs_unlink,
	.symlink	= multidevfs_symlink,
	.mkdir		= multidevfs_mkdir,
	.rmdir		= multidevfs_rmdir,
	.mknod		= multidevfs_mknod,
	.rename		= multidevfs_rename,
	.readlink	= multidevfs_readlink,
	.follow_link	= multidevfs_follow_link,
	.put_link	= multidevfs_put_link,
	.permission	= multidevfs_permission,
	.get_acl	= multidevfs_get_acl,
        .setattr	= multidevfs_setattr,
        .getattr	= multidevfs_getattr,
	.setxattr	= multidevfs_setxattr,
	.getxattr	= multidevfs_getxattr,
	.listxattr	= multidevfs_listxattr,
	.removexattr	= multidevfs_removexattr,
	.update_time	= multidevfs_update_time,
	.atomic_open	= multidevfs_atomic_open,
	.tmpfile	= multidevfs_tmpfile
}

};

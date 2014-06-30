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
 * File system superblock operations functions code goes here
 */

#include <linux/module.h>
#include <linux/mm.h>

#include "multidevfs.h"

const struct super_operations multidevfs_sops = {
        .alloc_inode	= multidevfs_alloc_inode,
        .destroy_inode	= multidevfs_destroy_inode,
        .dirty_inode	= multidevfs_dirty_inode,
        .write_inode 	= multidevfs_write_inode,
	.drop_inode	= multidevfs_drop_inode,
	.delete_inode	= multidevfs_delete_inode,
	.put_super	= multidevfs_put_super,
	.sync_fs	= multidevfs_sync_fs,
	.freeze_fs	= multidevfs_freeze_fs,
	.unfreeze_fs	= multidevfs_unfreeze_fs,
	.statfs		= multidevfs_statfs,
	.remount_fs	= multidevfs_remount_fs,
	.clear_inode	= multidevfs_clear_inode,
	.show_options	= multidevfs_show_options,
	.quota_read	= multidevfs_quota_read,
	.quota_write	= multidevfs_quota_write,

	.nr_cached_objects	= multidevfs_nr_cached_objects,
	.free_cached_objects	= multidevfs_free_cached_objects
}


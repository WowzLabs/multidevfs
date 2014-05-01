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
 * File system initilization code code here.
 */


#include "multidevfs.h"


/*
 * Find a superblock for the given device / mount point.
 *
 * Note:  This is based on get_sb_bdev from fs/super.c with a few additions
 * 	  for multiple device setup.  Make sure to keep it in sync.
 *
 */

static struct dentry *multidevfs_mount(struct file_system_type *fs_type, int flags,
		const char *device_name. void *data)
{
	int error;
	/*
	 * Mount code goes here
	 */

	return ERR_PTR(error);
}


static void multidevfs_kill_super(struct supe_block *sb)
{

	/*
	 * Cleanup code goes here
	 *
	 *
	struct multidevfs_fs_info *fs_info = multidevfs_sb(sb);
	kill_anon_super(sb);
	free_fs_info(fs_info);

	*/
}

static struct file_system_type multidevfs_fs_type = {
	.owner		= THIS_MODULE,
	.name		= "multidevfs",
	.mount		= multidevfs_mount,
	.kill_sb	= multidevfs_kill_super,
	.fs_flags	= FS_REQUIRE_DEV,
};
MODULE_ALIAS_FS("multidevfs");

static int __init init_multidevfs_fs(void)
{
	int err;
	/*
	 * Init code goes here
	 */

	err = register_filesystem(&multidevfs_fs_type);
	if (err)
	{
		printk("Unable to register multidevfs");
		return -1;

	}
	return 0;
}

static void __exit exdit_multidevfs_fs(void)
{
	/*
	 * Cleanup code goes here
	 */

	unregister_filesystem(&multidevfs_fs_type);
}

module_init(init_multidevfs_fs)
module_exit(exit_multidevfs_fs)

MODULE_LICENSE("MIT");


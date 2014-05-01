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

#include <linux/kernel.h>
#include <linux/blkdev.h>

static long multidevfs_ioctl_add_dev(struct multidevfs_root *root, 
		void __user *arg)
{
	/*
	 * Add device to pool/volume?
	 */

}


long multidevfs_ioctl(struct file *file, unsigned int
		cmd, unsinged long arg)
{
	void __user *argp = (void __user *)arg;
	mtdfs_volume *vol;
	/*
	 * Retrive volume from vol_id, if present.
	 * Use volume for further processing.
	 */

	switch(cmd) 
	{
		case MULTIDEVFS_ADD_DEV:
			return multidevfs_ioctl_add_dev(vol, argp);
		case MULTIDEVFS_DEL_DEV:
			return multidevfs_ioctl_del_dev(vol, argp);
		case MULTIDEVFS_CREATE_VOL:
			return multidevfs_ioctl_create_vol(argp);
		case MULTIDEVFS_DEL_VOL:
			return multidevfs_ioctl_del_vol(vol);
		default:
			return EPERM;
	}
}


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
 *
 */

#ifndef __MULTIDEVFS_H__
#define __MULTIDEVFS_H__

#include <linux/mm.h>
#include <linux/highmem.h>
#include <linux/fs.h>
#include <linux/semaphore.h>
#include <linux/completion.h>
#include <linux/backing-dev.h>
#include <linux/wait.h>
#include <linux/slab.h>
#include <linux/wait.h>
#include <linux/kobject.h>
#include <linux/pagemap.h>



/*
 * Flags and structures related to superblock
 */

#define MULTIDEVFS_CSUM_SIZE	32
#define MULTIDEVFS_FSID_SIZE	32
#define MULTIDEVFS_LABEL_SIZE	256


struct multidevfs_header {
	/* first four must match the superblock */
	u8 csum[MULTIDEVFS_CSUM_SIZE];
	u8 fsid[MULTIDEVFS_FSID_SIZE]; /* FS specific uuid */
} __attribute__ ((__packed__));

/*
 * The superblock basically lists the main trees of the FS
 * it currently lacks any block count etc...
 */

struct multidevfs _super_block {
	u8 csum[MULTIDEVFS_CSUM_SIZE];
	u8 fsid[BTRFS_FSID_SIZE];
	__le64 flags;

	char label[MULTIDEVFS_LABEL_SIZE];

} __attribute__ ((__packed__));


/*
 * RAID related 
 */

enum multidevfs_raid_types {
	MULTIDEVFS_RAID_RAID0,
	MULTIDEVFS_RAID_RAID1,
	MULTIDEVFS_RAID_RAID10,
	MULTIDEVFS_RAID_RAID5,
	MULTIDEVFS_RAID_RAID50,
	MULTIDEVFS_RAID_RAID6,
	MULTIDEVFS_NR_RAID_TYPES

};


/*
 * Disk related
 */

struct multidevfs_device {
	struct list_head dev_list;
	
	fmode_t mode;

	struct block_device *bdev;

	/* internal id for multidevfs */
	u64 devid;

	/* size of the disk */
	u64 total_bytes;

	u64 type;
}



/*
 * file system related or volume from SAN point of view.
 */

struct multidevfs_fs_info {
	u8 fsid[MULTIDEVFS_FSID_SIZE];
	
	/*
	 * disk list
	 * superblock pointer
	 * size of volume
	 * acutual size allocated.
	 * cache info
	 * slow storage pointer / Cloud storage
	 * state
	 * stripe hash table
	 * raid level
	 */
}


#endif //__MULTIDEVFS_H__

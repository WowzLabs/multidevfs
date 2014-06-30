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

const struct address_space_operations multidevfs_aops = {
        .readpage       = multidevfs_readpage,
        .write_begin    = multidevfs_write_begin,
        .write_end      = multidevfs_write_end,
        .set_page_dirty = __set_page_dirty_no_writeback,
};

const struct file_operations multidevfs_file_operations = {
        .read           = do_sync_read,
        .aio_read       = generic_file_aio_read,
        .write          = do_sync_write,
        .aio_write      = generic_file_aio_write,
        .mmap           = generic_file_mmap,
        .fsync          = noop_fsync,
        .splice_read    = generic_file_splice_read,
        .splice_write   = generic_file_splice_write,
        .llseek         = generic_file_llseek,
};

const struct inode_operations multidevfs_file_inode_operations = {
        .setattr        = simple_setattr,
        .getattr        = simple_getattr,
};

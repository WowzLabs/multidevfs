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
 * File system addressspace operations functions code goes here
 */

#include <linux/module.h>
#include <linux/mm.h>

#include "multidevfs.h"

const struct address_space_operations multidevfs_aops = {
	.writepage	= multidevfs-writepage,
        .readpage       = multidevfs_readpage,
	.writepages	= multidevfs_writepages,
	.set_page_dirty	= multidevfs_set_page_dirty,
	.readpages	= multidevfs_readpages,
        .write_begin    = multidevfs_write_begin,
        .write_end      = multidevfs_write_end,
	.bmap		= multidevfs_bmap,
	.invalidatepage	= multidevfs_invalidatepage,
	.releasepage	= multidevfs_releasepage,
	.freepage	= multidevfs_freepage,
	.direct_IO	= multidevfs_direct_IO,
	.get_xip_page	= multidevfs_get_xip_page,

	.migratepage	= multidevfs_migratepage,
	.launder_page	= multidevfs_launder_page,

	.is_partially_uptodate	= multidevfs_is_partially_uptodate,
	.is_dirty_writeback	= multidevfs_is_dirty_writeback,
	.error_remove_page	= multidevfs_error_remove_page,
	.swap_activate		= multidevfs_swap_activate,
	.swap_deactivate	= multidevfs_swap_deactivate
};

/* -*- mode: c; c-basic-offset: 8; indent-tabs-mode: nil; -*-
 * vim:expandtab:shiftwidth=8:tabstop=8:
 *
 *  lustre/osd/osd_internal.h
 *  Shared definitions and declarations for osd module
 *
 *  Copyright (c) 2006 Cluster File Systems, Inc.
 *   Author: Nikita Danilov <nikita@clusterfs.com>
 *
 *   This file is part of the Lustre file system, http://www.lustre.org
 *   Lustre is a trademark of Cluster File Systems, Inc.
 *
 *   You may have signed or agreed to another license before downloading
 *   this software.  If so, you are bound by the terms and conditions
 *   of that agreement, and the following does not apply to you.  See the
 *   LICENSE file included with this distribution for more information.
 *
 *   If you did not agree to a different license, then this copy of Lustre
 *   is open source software; you can redistribute it and/or modify it
 *   under the terms of version 2 of the GNU General Public License as
 *   published by the Free Software Foundation.
 *
 *   In either case, Lustre is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 *   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   license text for more details.
 */

#ifndef _OSD_INTERNAL_H
#define _OSD_INTERNAL_H

#if defined(__KERNEL__)

/* struct rw_semaphore */
#include <linux/rwsem.h>
#include <linux/lustre_iam.h>

#include <dt_object.h>
#include "osd_oi.h"

struct inode;
struct dentry;

struct dentry *osd_lookup(struct dentry *parent, const char *name);
struct dentry *osd_open(struct dentry *parent, const char *name, mode_t mode);

struct osd_thread_info {
        struct lu_fid       oti_fid;
        struct osd_inode_id oti_id;
        /*
         * XXX temporary: Buffer for fid->name conversion.
         */
        char                oti_name[32];
        /*
         * XXX temporary: for ->i_op calls.
         */
        struct qstr         oti_str;
        void                *scratch_key;
};

#endif /* __KERNEL__ */
#endif /* _OSD_INTERNAL_H */

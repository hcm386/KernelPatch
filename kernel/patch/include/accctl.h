/* SPDX-License-Identifier: GPL-2.0-or-later */
/* 
 * Copyright (C) 2023 bmax121. All Rights Reserved.
 */

#ifndef _KP_ACCCTL_H_
#define _KP_ACCCTL_H_

#include <ktypes.h>
#include <linux/cred.h>
#include <linux/spinlock.h>
#include <linux/sched.h>
#include <uapi/scdefs.h>

int set_priv_selinx_allow(struct task_struct *task, int val);
int commit_kernel_cred();
int commit_su(uid_t uid, const char *sctx);
int task_su(pid_t pid, uid_t to_uid, const char *sctx);

int selinux_hook_install();
int supercall_install();

#ifdef ANDROID
int su_compat_init();
int su_add_allow_uid(uid_t uid, uid_t to_uid, const char *scontext, int async);
int su_remove_allow_uid(uid_t uid, int async);
int su_allow_uid_nums();
int su_allow_uids(int is_user, uid_t *out_uids, int out_num);
int su_allow_uid_profile(int is_user, uid_t uid, struct su_profile *profile);
int su_reset_path(const char *path);
const char *su_get_path();
long supercall_android(long cmd, long arg1, long arg2,

                       long arg3);
#endif

#endif
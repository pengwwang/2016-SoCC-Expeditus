/*
  Network Simulation Cradle
  Copyright (C) 2003-2005 Sam Jansen

  This program is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the Free
  Software Foundation; either version 2 of the License, or (at your option)
  any later version.

  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc., 59
  Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#define UNIMPLEMENTED() nsc_assert(0, __func__);
#define U(func) void func(void) { UNIMPLEMENTED() }
extern void nsc_assert(int, const char *);

U(__down_read)
U(__down_read_trylock)
U(__down_write)
U(__down_write_trylock)
U(__downgrade_write)
U(seq_printf)
U(preempt_schedule)
U(seq_read)
U(seq_lseek)
U(seq_open)
U(remove_proc_entry)
U(diskmon_pop_curr_file)
U(proc_nmi_enabled)
U(diskmon_push_curr_file)
U(nr_running_cpu)
U(set_netdump_dest_multicast_or_broadcast)
U(set_netdump_dest_unicast)
U(disable_netdump)
U(drop_caches_sysctl_string)
U(simple_rename)
U(get_pid_task)
U(kill_litter_super)
U(sort)
U(__up_read)
U(__up_write)
U(param_set_int)
U(param_get_int)
U(get_task_mm)
U(mmput)
U(__put_task_struct)
U(generic_delete_inode)
U(generic_file_llseek)
U(generic_file_open)
U(d_alloc_root)
U(get_sb_single)
U(call_usermodehelper_keys)
U(find_task_by_pid_type)
U(simple_read_from_buffer)
U(__bitmap_and)
U(__bitmap_andnot)
U(__bitmap_empty)
U(__bitmap_equal)
U(__bitmap_intersects)
U(__bitmap_or)
U(__bitmap_subset)
U(partition_sched_domains)
U(bitmap_parselist)
U(bitmap_scnlistprintf)
U(bitmap_scnprintf)
U(lookup_one_len)
U(d_delete)
U(simple_rmdir)
U(dput)
U(dget_locked)
U(simple_unlink)
U(simple_lookup)
U(touch_atime)
U(percpu_pagelist_fraction_sysctl_handler)
U(proc_nr_files)
U(rwsem_downgrade_wake)
U(set_process_cpu_timer)
U(hrtimer_start)
U(hrtimer_try_to_cancel)
U(idle_cpu)
U(hrtimer_forward)
U(hrtimer_get_remaining)
U(drop_caches_sysctl_handler)
U(run_posix_cpu_timers)
U(generic_splice_sendpage)
U(current_fs_time)
U(class_device_initialize)
U(class_device_add)
U(xfrm_replay_notify)
U(__mark_inode_dirty)
U(get_netdump_dest)
U(set_netdump_dest)
U(account_user_time)
U(account_system_time)
U(cond_resched_lock)
U(strncpy_from_user)
U(lowmem_reserve_ratio_sysctl_handler)
U(check_tcp_syn_cookie)
U(class_device_del)
U(class_device_unregister)
U(class_device_rename)
U(class_device_put)
U(complete)
U(add_wait_queue)
U(add_wait_queue_exclusive)
U(__copy_from_user_ll)
U(__down_failed_interruptible)
U(__free_pages)
U(__bitmap_weight)
U(d_rehash)
U(d_instantiate)
U(d_alloc)
U(dirty_writeback_centisecs_handler)
U(get_sb_pseudo)
U(get_options)
U(get_empty_filp)
U(idr_remove)
U(idr_pre_get)
U(idr_get_new_above)
U(idr_find)
U(getnstimeofday)
U(kthread_create)
U(kthread_bind)
U(kill_anon_super)
U(ipv6_ext_hdr)
U(in_egroup_p)
U(lower_zone_protection_sysctl_handler)
U(min_free_kbytes_sysctl_handler)
U(no_llseek)
U(proc_unknown_nmi_panic)
U(put_filp)
U(secure_tcp_syn_cookie)
U(rwsem_down_write_failed)
U(rwsem_down_read_failed)
U(set_user_nice)
U(send_sigurg)
U(send_group_sig_info)
U(simple_statfs)
U(si_swapinfo)
U(crypto_hmac_init)
U(crypto_hmac_final)
U(__kill_fasync)
U(xfrm_state_insert)
U(xfrm_state_delete_tunnel)
U(wait_for_completion)
U(fget)
U(fget_light)
U(fd_install)
U(default_wake_function)
U(crypto_hmac_update)
U(get_unused_fd)
U(rwsem_wake)
U(remove_wait_queue)
U(register_cpu_notifier)
U(pskb_put)
U(kthread_should_stop)
U(ipv6_skip_exthdr)
U(crypto_hmac)
U(__xfrm_state_destroy)
U(__page_cache_release)
U(xfrm_aalg_get_byname)
U(xfrm4_tunnel_deregister)
U(wait_on_sync_kiocb)
U(skb_to_sgvec)
U(skb_icv_walk)
U(skb_cow_data)
U(__alloc_pages)
U(xfrm4_rcv)
U(sys_close)
U(put_unused_fd)
U(seq_putc)
U(xfrm_unregister_type)
U(simple_strtoul)
U(crypto_alloc_tfm)
U(yield)
U(xfrm_state_lookup)
U(wake_up_process)
U(seq_release)
U(kmem_cache_destroy)
U(fput)
U(crypto_free_tfm)
U(single_release)
U(single_open)
U(autoremove_wake_function)
U(seq_release_private)
U(seq_puts)
U(km_new_mapping)
U(f_setown)
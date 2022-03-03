/*
 * Virtio RDMA Device
 *
 * Copyright (C) 2021 Bytedance Inc.
 *
 * Authors:
 *  Junji Wei <weijunji@bytedance.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 *
 */

#ifndef _LINUX_VIRTIO_RDMA_H
#define _LINUX_VIRTIO_RDMA_H

#include <linux/types.h>
#include <infiniband/verbs.h>

#include "standard-headers/linux/virtio_ids.h"
#include "standard-headers/linux/virtio_config.h"
#include "standard-headers/linux/virtio_types.h"
#include "standard-headers/linux/if_ether.h"

struct virtio_rdma_config {
    uint8_t mac[ETH_ALEN];
	/* See VIRTIO_NET_F_STATUS and VIRTIO_NET_S_* above */
	__virtio16 status;
	/* Maximum number of each of transmit and receive queues;
	 * see VIRTIO_NET_F_MQ and VIRTIO_NET_CTRL_MQ.
	 * Legal values are between 1 and 0x8000
	 */
	__virtio16 max_virtqueue_pairs;
	/* Default maximum transmit unit advice */
	__virtio16 mtu;
	/*
	 * speed, in units of 1Mb. All values 0 to INT_MAX are legal.
	 * Any other value stands for unknown.
	 */
	uint32_t speed;
	/*
	 * 0x00 - half duplex
	 * 0x01 - full duplex
	 * Any other value stands for unknown.
	 */
	uint8_t duplex;
	/* maximum size of RSS key */
	uint8_t rss_max_key_size;
	/* maximum number of indirection table entries */
	uint16_t rss_max_indirection_table_length;
	/* bitmask of supported VIRTIO_NET_RSS_HASH_ types */
	uint32_t supported_hash_types;

    __le32         phys_port_cnt;

    __le64         sys_image_guid;
    __le32         vendor_id;
    __le32         vendor_part_id;
    __le32         hw_ver;
    __le64         max_mr_size;
    __le64         page_size_cap;
    __le32         max_qp;
    __le32         max_qp_wr;
    __le64         device_cap_flags;
    __le32         max_send_sge;
    __le32         max_recv_sge;
    __le32         max_sge_rd;
    __le32         max_cq;
    __le32         max_cqe;
    __le32         max_mr;
    __le32         max_pd;
    __le32         max_qp_rd_atom;
    __le32         max_res_rd_atom;
    __le32         max_qp_init_rd_atom;
    __le32         atomic_cap;
    __le32         max_mw;
    __le32         max_mcast_grp;
    __le32         max_mcast_qp_attach;
    __le32         max_total_mcast_qp_attach;
    __le32         max_ah;
    __le32         max_fast_reg_page_list_len;
    __le32         max_pi_fast_reg_page_list_len;
    __le16         max_pkeys;
    uint8_t        local_ca_ack_delay;
} QEMU_PACKED;

#endif

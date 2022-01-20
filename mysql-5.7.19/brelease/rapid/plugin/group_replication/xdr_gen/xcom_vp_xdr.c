/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "xcom_vp.h"
/* Copyright (c) 2010, 2016, Oracle and/or its affiliates. All rights reserved.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */

#include "xcom_vp_platform.h"

bool_t
xdr_xcom_proto (XDR *xdrs, xcom_proto *objp)
{
	register int32_t *buf;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_x_proto_range (XDR *xdrs, x_proto_range *objp)
{
	register int32_t *buf;

	 if (!xdr_xcom_proto (xdrs, &objp->min_proto))
		 return FALSE;
	 if (!xdr_xcom_proto (xdrs, &objp->max_proto))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_delivery_status (XDR *xdrs, delivery_status *objp)
{
	register int32_t *buf;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_cons_type (XDR *xdrs, cons_type *objp)
{
	register int32_t *buf;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_node_no (XDR *xdrs, node_no *objp)
{
	register int32_t *buf;

	 if (!xdr_uint32_t (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_synode_no (XDR *xdrs, synode_no *objp)
{
	register int32_t *buf;

	 if (!xdr_uint32_t (xdrs, &objp->group_id))
		 return FALSE;
	 if (!xdr_uint64_t (xdrs, &objp->msgno))
		 return FALSE;
	 if (!xdr_node_no (xdrs, &objp->node))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_trans_id (XDR *xdrs, trans_id *objp)
{
	register int32_t *buf;

	 if (!xdr_synode_no (xdrs, &objp->cfg))
		 return FALSE;
	 if (!xdr_uint32_t (xdrs, &objp->pc))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_node_set (XDR *xdrs, node_set *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->node_set_val, (u_int *) &objp->node_set_len, 100,
		sizeof (bool_t), (xdrproc_t) xdr_bool))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_blob (XDR *xdrs, blob *objp)
{
	register int32_t *buf;

	 if (!xdr_bytes (xdrs, (char **)&objp->data.data_val, (u_int *) &objp->data.data_len, 1024))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_node_address_1_0 (XDR *xdrs, node_address_1_0 *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->address, 1024))
		 return FALSE;
	 if (!xdr_blob (xdrs, &objp->uuid))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_node_list_1_0 (XDR *xdrs, node_list_1_0 *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->node_list_1_0_val, (u_int *) &objp->node_list_1_0_len, 100,
		sizeof (node_address_1_0), (xdrproc_t) xdr_node_address_1_0))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_node_address (XDR *xdrs, node_address *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->address, 1024))
		 return FALSE;
	 if (!xdr_blob (xdrs, &objp->uuid))
		 return FALSE;
	 if (!xdr_x_proto_range (xdrs, &objp->proto))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_node_list (XDR *xdrs, node_list *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->node_list_val, (u_int *) &objp->node_list_len, 100,
		sizeof (node_address), (xdrproc_t) xdr_node_address))
		 return FALSE;
	return TRUE;
}
/*
	Custom xdr functions to coerce rpcgen into handling different protocol versions.
	Protocol version is passed in an extended XDR object.
*/

#ifndef VERSION_CONTROL
#define VERSION_CONTROL

extern xcom_proto const my_min_xcom_version; /* The minimum protocol version I am able to understand */
extern xcom_proto const my_xcom_version; /* The maximum protocol version I am able to understand */

typedef node_list node_list_1_1; /* Alias for real type to avoid generating xdr call to xdr_node_list */

extern bool_t xdr_node_list_1_1 (XDR *, node_list_1_1*);

#endif
#ifndef CHECKED_DATA
#define CHECKED_DATA
typedef struct {
 u_int data_len;
 char *data_val;
} checked_data;
extern bool_t xdr_checked_data (XDR *, checked_data*);
#endif

bool_t
xdr_cargo_type (XDR *xdrs, cargo_type *objp)
{
	register int32_t *buf;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_node_no_array (XDR *xdrs, node_no_array *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->node_no_array_val, (u_int *) &objp->node_no_array_len, 100,
		sizeof (node_no), (xdrproc_t) xdr_node_no))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_synode_no_array (XDR *xdrs, synode_no_array *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->synode_no_array_val, (u_int *) &objp->synode_no_array_len, 1024,
		sizeof (synode_no), (xdrproc_t) xdr_synode_no))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_uncommitted_list (XDR *xdrs, uncommitted_list *objp)
{
	register int32_t *buf;

	 if (!xdr_uint32_t (xdrs, &objp->active))
		 return FALSE;
	 if (!xdr_synode_no_array (xdrs, &objp->vers))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_repository (XDR *xdrs, repository *objp)
{
	register int32_t *buf;

	 if (!xdr_synode_no (xdrs, &objp->vers))
		 return FALSE;
	 if (!xdr_synode_no_array (xdrs, &objp->msg_list))
		 return FALSE;
	 if (!xdr_uncommitted_list (xdrs, &objp->u_list))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_x_error (XDR *xdrs, x_error *objp)
{
	register int32_t *buf;

	 if (!xdr_int32_t (xdrs, &objp->nodeid))
		 return FALSE;
	 if (!xdr_int32_t (xdrs, &objp->code))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->message, 10240))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_trans_data (XDR *xdrs, trans_data *objp)
{
	register int32_t *buf;

	 if (!xdr_trans_id (xdrs, &objp->tid))
		 return FALSE;
	 if (!xdr_int32_t (xdrs, &objp->pc))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->cluster_name, 1024))
		 return FALSE;
	 if (!xdr_x_error (xdrs, &objp->errmsg))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_app_u (XDR *xdrs, app_u *objp)
{
	register int32_t *buf;

	 if (!xdr_cargo_type (xdrs, &objp->c_t))
		 return FALSE;
	switch (objp->c_t) {
	case unified_boot_type:
	case add_node_type:
	case remove_node_type:
	case force_config_type:
	case xcom_boot_type:
	case xcom_set_group:
		 if (!xdr_node_list_1_1 (xdrs, &objp->app_u_u.nodes))
			 return FALSE;
		break;
	case xcom_recover:
		 if (!xdr_repository (xdrs, &objp->app_u_u.rep))
			 return FALSE;
		break;
	case app_type:
		 if (!xdr_checked_data (xdrs, &objp->app_u_u.data))
			 return FALSE;
		break;
	case query_type:
		break;
	case query_next_log:
		break;
	case exit_type:
	case reset_type:
		break;
	case remove_reset_type:
		break;
	case begin_trans:
		break;
	case prepared_trans:
	case abort_trans:
		 if (!xdr_trans_data (xdrs, &objp->app_u_u.td))
			 return FALSE;
		break;
	case view_msg:
		 if (!xdr_node_set (xdrs, &objp->app_u_u.present))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_recover_action (XDR *xdrs, recover_action *objp)
{
	register int32_t *buf;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_app_data (XDR *xdrs, app_data *objp)
{
	register int32_t *buf;


	if (xdrs->x_op == XDR_ENCODE) {
		 if (!xdr_synode_no (xdrs, &objp->unique_id))
			 return FALSE;
		 if (!xdr_uint32_t (xdrs, &objp->group_id))
			 return FALSE;
		 if (!xdr_uint64_t (xdrs, &objp->lsn))
			 return FALSE;
		 if (!xdr_synode_no (xdrs, &objp->app_key))
			 return FALSE;
		 if (!xdr_cons_type (xdrs, &objp->consensus))
			 return FALSE;
		 if (!xdr_double (xdrs, &objp->expiry_time))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_bool (xdrs, &objp->notused))
				 return FALSE;
			 if (!xdr_bool (xdrs, &objp->log_it))
				 return FALSE;
			 if (!xdr_bool (xdrs, &objp->chosen))
				 return FALSE;

		} else {
		IXDR_PUT_BOOL(buf, objp->notused);
		IXDR_PUT_BOOL(buf, objp->log_it);
		IXDR_PUT_BOOL(buf, objp->chosen);
		}
		 if (!xdr_recover_action (xdrs, &objp->recover))
			 return FALSE;
		 if (!xdr_app_u (xdrs, &objp->body))
			 return FALSE;
		 if (!xdr_pointer (xdrs, (char **)&objp->next, sizeof (app_data), (xdrproc_t) xdr_app_data))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		 if (!xdr_synode_no (xdrs, &objp->unique_id))
			 return FALSE;
		 if (!xdr_uint32_t (xdrs, &objp->group_id))
			 return FALSE;
		 if (!xdr_uint64_t (xdrs, &objp->lsn))
			 return FALSE;
		 if (!xdr_synode_no (xdrs, &objp->app_key))
			 return FALSE;
		 if (!xdr_cons_type (xdrs, &objp->consensus))
			 return FALSE;
		 if (!xdr_double (xdrs, &objp->expiry_time))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_bool (xdrs, &objp->notused))
				 return FALSE;
			 if (!xdr_bool (xdrs, &objp->log_it))
				 return FALSE;
			 if (!xdr_bool (xdrs, &objp->chosen))
				 return FALSE;

		} else {
		objp->notused = IXDR_GET_BOOL(buf);
		objp->log_it = IXDR_GET_BOOL(buf);
		objp->chosen = IXDR_GET_BOOL(buf);
		}
		 if (!xdr_recover_action (xdrs, &objp->recover))
			 return FALSE;
		 if (!xdr_app_u (xdrs, &objp->body))
			 return FALSE;
		 if (!xdr_pointer (xdrs, (char **)&objp->next, sizeof (app_data), (xdrproc_t) xdr_app_data))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_synode_no (xdrs, &objp->unique_id))
		 return FALSE;
	 if (!xdr_uint32_t (xdrs, &objp->group_id))
		 return FALSE;
	 if (!xdr_uint64_t (xdrs, &objp->lsn))
		 return FALSE;
	 if (!xdr_synode_no (xdrs, &objp->app_key))
		 return FALSE;
	 if (!xdr_cons_type (xdrs, &objp->consensus))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->expiry_time))
		 return FALSE;
	 if (!xdr_bool (xdrs, &objp->notused))
		 return FALSE;
	 if (!xdr_bool (xdrs, &objp->log_it))
		 return FALSE;
	 if (!xdr_bool (xdrs, &objp->chosen))
		 return FALSE;
	 if (!xdr_recover_action (xdrs, &objp->recover))
		 return FALSE;
	 if (!xdr_app_u (xdrs, &objp->body))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->next, sizeof (app_data), (xdrproc_t) xdr_app_data))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_app_data_ptr (XDR *xdrs, app_data_ptr *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)objp, sizeof (app_data), (xdrproc_t) xdr_app_data))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_app_data_ptr_array (XDR *xdrs, app_data_ptr_array *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->app_data_ptr_array_val, (u_int *) &objp->app_data_ptr_array_len, 1024,
		sizeof (app_data_ptr), (xdrproc_t) xdr_app_data_ptr))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_app_data_list (XDR *xdrs, app_data_list *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)objp, sizeof (app_data_ptr), (xdrproc_t) xdr_app_data_ptr))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_key_range (XDR *xdrs, key_range *objp)
{
	register int32_t *buf;

	 if (!xdr_synode_no (xdrs, &objp->k1))
		 return FALSE;
	 if (!xdr_synode_no (xdrs, &objp->k2))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_bit_mask (XDR *xdrs, bit_mask *objp)
{
	register int32_t *buf;

	 if (!xdr_uint32_t (xdrs, objp))
		 return FALSE;
	return TRUE;
}

#define BITS_PER_BYTE 8
#define MASK_BITS ((uint32_t)(sizeof (bit_mask) * BITS_PER_BYTE)) /* bits per mask */
#define howmany_words(x, y) (((x)+((y)-1))/(y))


bool_t
xdr_bit_set (XDR *xdrs, bit_set *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->bits.bits_val, (u_int *) &objp->bits.bits_len, 100,
		sizeof (bit_mask), (xdrproc_t) xdr_bit_mask))
		 return FALSE;
	return TRUE;
}
#define BIT_OP(__n, __p, __op, __inv) ((__p)->bits.bits_val[(__n)/MASK_BITS] __op __inv (1u << ((__n) % MASK_BITS)))
#define BIT_XOR(__n, __p) BIT_OP(__n, __p, ^=, )
#define BIT_SET(__n, __p) BIT_OP(__n, __p, |=, )
#define BIT_CLR(__n, __p) BIT_OP(__n, __p, &=, ~)
#define BIT_ISSET(__n, __p) (BIT_OP(__n, __p, &, ) != 0ul)
#define BIT_ZERO(__p) memset((__p)->bits.bits_val, 0, (__p)->bits.bits_len * sizeof(*(__p)->bits.bits_val))
extern bit_set *new_bit_set(uint32_t bits);
extern bit_set *clone_bit_set(bit_set *orig);
extern void free_bit_set(bit_set *bs);

bool_t
xdr_ballot (XDR *xdrs, ballot *objp)
{
	register int32_t *buf;

	 if (!xdr_int32_t (xdrs, &objp->cnt))
		 return FALSE;
	 if (!xdr_node_no (xdrs, &objp->node))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_pax_op (XDR *xdrs, pax_op *objp)
{
	register int32_t *buf;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_pax_msg_type (XDR *xdrs, pax_msg_type *objp)
{
	register int32_t *buf;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_start_t (XDR *xdrs, start_t *objp)
{
	register int32_t *buf;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_snapshot (XDR *xdrs, snapshot *objp)
{
	register int32_t *buf;

	 if (!xdr_synode_no (xdrs, &objp->vers))
		 return FALSE;
	 if (!xdr_app_data_ptr_array (xdrs, &objp->snap))
		 return FALSE;
	 if (!xdr_uncommitted_list (xdrs, &objp->u_list))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_config (XDR *xdrs, config *objp)
{
	register int32_t *buf;

	 if (!xdr_synode_no (xdrs, &objp->start))
		 return FALSE;
	 if (!xdr_synode_no (xdrs, &objp->boot_key))
		 return FALSE;
	 if (!xdr_node_list_1_1 (xdrs, &objp->nodes))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_config_ptr (XDR *xdrs, config_ptr *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)objp, sizeof (config), (xdrproc_t) xdr_config))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_configs (XDR *xdrs, configs *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->configs_val, (u_int *) &objp->configs_len, 100,
		sizeof (config_ptr), (xdrproc_t) xdr_config_ptr))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_gcs_snapshot (XDR *xdrs, gcs_snapshot *objp)
{
	register int32_t *buf;

	 if (!xdr_synode_no (xdrs, &objp->log_start))
		 return FALSE;
	 if (!xdr_configs (xdrs, &objp->cfg))
		 return FALSE;
	 if (!xdr_blob (xdrs, &objp->app_snap))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_client_reply_code (XDR *xdrs, client_reply_code *objp)
{
	register int32_t *buf;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_pax_msg (XDR *xdrs, pax_msg *objp)
{
	register int32_t *buf;

	 if (!xdr_node_no (xdrs, &objp->to))
		 return FALSE;
	 if (!xdr_node_no (xdrs, &objp->from))
		 return FALSE;
	 if (!xdr_uint32_t (xdrs, &objp->group_id))
		 return FALSE;
	 if (!xdr_synode_no (xdrs, &objp->max_synode))
		 return FALSE;
	 if (!xdr_start_t (xdrs, &objp->start_type))
		 return FALSE;
	 if (!xdr_ballot (xdrs, &objp->reply_to))
		 return FALSE;
	 if (!xdr_ballot (xdrs, &objp->proposal))
		 return FALSE;
	 if (!xdr_pax_op (xdrs, &objp->op))
		 return FALSE;
	 if (!xdr_synode_no (xdrs, &objp->synode))
		 return FALSE;
	 if (!xdr_pax_msg_type (xdrs, &objp->msg_type))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->receivers, sizeof (bit_set), (xdrproc_t) xdr_bit_set))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->a, sizeof (app_data), (xdrproc_t) xdr_app_data))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->snap, sizeof (snapshot), (xdrproc_t) xdr_snapshot))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->gcs_snap, sizeof (gcs_snapshot), (xdrproc_t) xdr_gcs_snapshot))
		 return FALSE;
	 if (!xdr_client_reply_code (xdrs, &objp->cli_err))
		 return FALSE;
	 if (!xdr_bool (xdrs, &objp->force_delivery))
		 return FALSE;
	 if (!xdr_int32_t (xdrs, &objp->refcnt))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_file_name (XDR *xdrs, file_name *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, objp, 1024))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_file_name_array (XDR *xdrs, file_name_array *objp)
{
	register int32_t *buf;

	 if (!xdr_array (xdrs, (char **)&objp->file_name_array_val, (u_int *) &objp->file_name_array_len, 1024,
		sizeof (file_name), (xdrproc_t) xdr_file_name))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_file_copy_data (XDR *xdrs, file_copy_data *objp)
{
	register int32_t *buf;

	 if (!xdr_string (xdrs, &objp->clustername, 1024))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->copydir, 1024))
		 return FALSE;
	 if (!xdr_string (xdrs, &objp->server, 1024))
		 return FALSE;
	 if (!xdr_int32_t (xdrs, &objp->copy_port))
		 return FALSE;
	return TRUE;
}

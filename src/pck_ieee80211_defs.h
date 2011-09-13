/*
 * IEEE 802.11 Frame type definitions
 *
 * Copyright (c) 2002-2009, Jouni Malinen <j@w1.fi>
 * Copyright (c) 2007-2008 Intel Corporation
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef H_PCK_IEEE80211_DEFS
#define H_PCK_IEEE80211_DEFS

// Int inc
#include "ao_config.h"

// Structure packing
#ifndef STRUCT_PACKED
#define STRUCT_PACKED __attribute__ ((packed))
#endif

// Ethernet
#ifndef ETH_ALEN
#define ETH_ALEN 6
#endif

// Frame control field flags
#define WLAN_FC_PVER		0x0003
#define WLAN_FC_TODS		0x0100
#define WLAN_FC_FROMDS		0x0200
#define WLAN_FC_MOREFRAG	0x0400
#define WLAN_FC_RETRY		0x0800
#define WLAN_FC_PWRMGT		0x1000
#define WLAN_FC_MOREDATA	0x2000
#define WLAN_FC_ISWEP		0x4000
#define WLAN_FC_ORDER		0x8000

// Frame control field type and subtype fields
#define WLAN_FC_CONSTRUCT(type, stype) GUINT16_TO_LE((type << 2) | (stype << 4))
#define WLAN_FC_GET_TYPE(fc)	(((fc) & 0x000c) >> 2)
#define WLAN_FC_GET_STYPE(fc)	(((fc) & 0x00f0) >> 4)
#define WLAN_FC_GET_PVER(fc) (((fc) & WLAN_FC_PVER) >> 0)
#define WLAN_FC_GET_TODS(fc) (((fc) & WLAN_FC_TODS) >> 8)
#define WLAN_FC_GET_FROMDS(fc) (((fc) & WLAN_FC_FROMDS) >> 9)
#define WLAN_FC_GET_MOREFRAG(fc) (((fc) & WLAN_FC_MOREFRAG) >> 10)
#define WLAN_FC_GET_RETRY(fc) (((fc) & WLAN_FC_RETRY) >> 11)
#define WLAN_FC_GET_PWRMGT(fc) (((fc) & WLAN_FC_PWRMGT) >> 12)
#define WLAN_FC_GET_MOREDATA(fc) (((fc) & WLAN_FC_MOREDATA) >> 13)
#define WLAN_FC_GET_ISWEP(fc) (((fc) & WLAN_FC_ISWEP) >> 14)
#define WLAN_FC_GET_ORDER(fc) (((fc) & WLAN_FC_ORDER) >> 15)

// Sequence control field
#define WLAN_SEQ_CONSTRUCT(frag,seq) (((frag) & 0x0f) | (((seq) & 0xfff0) >> 4))
#define WLAN_SEQ_GET_FRAG(seq) ((seq) & (BIT(3) | BIT(2) | BIT(1) | BIT(0)))
#define WLAN_SEQ_GET_SEQ(seq) (((seq) & (~(BIT(3) | BIT(2) | BIT(1) | BIT(0)))) >> 4)

// Frame types
#define WLAN_FC_TYPE_MGMT		0
#define WLAN_FC_TYPE_CTRL		1
#define WLAN_FC_TYPE_DATA		2

// Frame subtypes - management
#define WLAN_FC_STYPE_ASSOC_REQ		0
#define WLAN_FC_STYPE_ASSOC_RESP	1
#define WLAN_FC_STYPE_REASSOC_REQ	2
#define WLAN_FC_STYPE_REASSOC_RESP	3
#define WLAN_FC_STYPE_PROBE_REQ		4
#define WLAN_FC_STYPE_PROBE_RESP	5
#define WLAN_FC_STYPE_BEACON		8
#define WLAN_FC_STYPE_ATIM		9
#define WLAN_FC_STYPE_DISASSOC		10
#define WLAN_FC_STYPE_AUTH		11
#define WLAN_FC_STYPE_DEAUTH		12
#define WLAN_FC_STYPE_ACTION		13

// Frame subtypes - control
#define WLAN_FC_STYPE_PSPOLL		10
#define WLAN_FC_STYPE_RTS		11
#define WLAN_FC_STYPE_CTS		12
#define WLAN_FC_STYPE_ACK		13
#define WLAN_FC_STYPE_CFEND		14
#define WLAN_FC_STYPE_CFENDACK		15

// Frame subtypes - data
#define WLAN_FC_STYPE_DATA		0
#define WLAN_FC_STYPE_DATA_CFACK	1
#define WLAN_FC_STYPE_DATA_CFPOLL	2
#define WLAN_FC_STYPE_DATA_CFACKPOLL	3
#define WLAN_FC_STYPE_NULLFUNC		4
#define WLAN_FC_STYPE_CFACK		5
#define WLAN_FC_STYPE_CFPOLL		6
#define WLAN_FC_STYPE_CFACKPOLL		7
#define WLAN_FC_STYPE_QOS_DATA		8
#define WLAN_FC_STYPE_QOS_DATACFACK	9
#define WLAN_FC_STYPE_QOS_DATACFPOLL	10
#define WLAN_FC_STYPE_QOS_DATACFACKPOLL	11
#define WLAN_FC_STYPE_QOS_NULL	        12

// Authentication algorithms
#define WLAN_AUTH_OPEN			0
#define WLAN_AUTH_SHARED_KEY		1
#define WLAN_AUTH_FT			2
#define WLAN_AUTH_LEAP			128

#define WLAN_AUTH_CHALLENGE_LEN 128

#define WLAN_CAPABILITY_ESS BIT(0)
#define WLAN_CAPABILITY_IBSS BIT(1)
#define WLAN_CAPABILITY_CF_POLLABLE BIT(2)
#define WLAN_CAPABILITY_CF_POLL_REQUEST BIT(3)
#define WLAN_CAPABILITY_PRIVACY BIT(4)
#define WLAN_CAPABILITY_SHORT_PREAMBLE BIT(5)
#define WLAN_CAPABILITY_PBCC BIT(6)
#define WLAN_CAPABILITY_CHANNEL_AGILITY BIT(7)
#define WLAN_CAPABILITY_SPECTRUM_MGMT BIT(8)
#define WLAN_CAPABILITY_SHORT_SLOT_TIME BIT(10)
#define WLAN_CAPABILITY_DSSS_OFDM BIT(13)

// Status codes (IEEE 802.11-2007, 7.3.1.9, Table 7-23)
#define WLAN_STATUS_SUCCESS 0
#define WLAN_STATUS_UNSPECIFIED_FAILURE 1
#define WLAN_STATUS_CAPS_UNSUPPORTED 10
#define WLAN_STATUS_REASSOC_NO_ASSOC 11
#define WLAN_STATUS_ASSOC_DENIED_UNSPEC 12
#define WLAN_STATUS_NOT_SUPPORTED_AUTH_ALG 13
#define WLAN_STATUS_UNKNOWN_AUTH_TRANSACTION 14
#define WLAN_STATUS_CHALLENGE_FAIL 15
#define WLAN_STATUS_AUTH_TIMEOUT 16
#define WLAN_STATUS_AP_UNABLE_TO_HANDLE_NEW_STA 17
#define WLAN_STATUS_ASSOC_DENIED_RATES 18
// IEEE 802.11b
#define WLAN_STATUS_ASSOC_DENIED_NOSHORT 19
#define WLAN_STATUS_ASSOC_DENIED_NOPBCC 20
#define WLAN_STATUS_ASSOC_DENIED_NOAGILITY 21
// IEEE 802.11h
#define WLAN_STATUS_SPEC_MGMT_REQUIRED 22
#define WLAN_STATUS_PWR_CAPABILITY_NOT_VALID 23
#define WLAN_STATUS_SUPPORTED_CHANNEL_NOT_VALID 24
// IEEE 802.11g
#define WLAN_STATUS_ASSOC_DENIED_NO_SHORT_SLOT_TIME 25
#define WLAN_STATUS_ASSOC_DENIED_NO_ER_PBCC 26
#define WLAN_STATUS_ASSOC_DENIED_NO_DSSS_OFDM 27
#define WLAN_STATUS_R0KH_UNREACHABLE 28
// IEEE 802.11w
#define WLAN_STATUS_ASSOC_REJECTED_TEMPORARILY 30
#define WLAN_STATUS_ROBUST_MGMT_FRAME_POLICY_VIOLATION 31
#define WLAN_STATUS_UNSPECIFIED_QOS_FAILURE 32
#define WLAN_STATUS_REQUEST_DECLINED 37
#define WLAN_STATUS_INVALID_PARAMETERS 38
// IEEE 802.11i
#define WLAN_STATUS_INVALID_IE 40
#define WLAN_STATUS_GROUP_CIPHER_NOT_VALID 41
#define WLAN_STATUS_PAIRWISE_CIPHER_NOT_VALID 42
#define WLAN_STATUS_AKMP_NOT_VALID 43
#define WLAN_STATUS_UNSUPPORTED_RSN_IE_VERSION 44
#define WLAN_STATUS_INVALID_RSN_IE_CAPAB 45
#define WLAN_STATUS_CIPHER_REJECTED_PER_POLICY 46
#define WLAN_STATUS_TS_NOT_CREATED 47
#define WLAN_STATUS_DIRECT_LINK_NOT_ALLOWED 48
#define WLAN_STATUS_DEST_STA_NOT_PRESENT 49
#define WLAN_STATUS_DEST_STA_NOT_QOS_STA 50
#define WLAN_STATUS_ASSOC_DENIED_LISTEN_INT_TOO_LARGE 51
// IEEE 802.11r
#define WLAN_STATUS_INVALID_FT_ACTION_FRAME_COUNT 52
#define WLAN_STATUS_INVALID_PMKID 53
#define WLAN_STATUS_INVALID_MDIE 54
#define WLAN_STATUS_INVALID_FTIE 55

// Reason codes (IEEE 802.11-2007, 7.3.1.7, Table 7-22)
#define WLAN_REASON_UNSPECIFIED 1
#define WLAN_REASON_PREV_AUTH_NOT_VALID 2
#define WLAN_REASON_DEAUTH_LEAVING 3
#define WLAN_REASON_DISASSOC_DUE_TO_INACTIVITY 4
#define WLAN_REASON_DISASSOC_AP_BUSY 5
#define WLAN_REASON_CLASS2_FRAME_FROM_NONAUTH_STA 6
#define WLAN_REASON_CLASS3_FRAME_FROM_NONASSOC_STA 7
#define WLAN_REASON_DISASSOC_STA_HAS_LEFT 8
#define WLAN_REASON_STA_REQ_ASSOC_WITHOUT_AUTH 9
// IEEE 802.11h
#define WLAN_REASON_PWR_CAPABILITY_NOT_VALID 10
#define WLAN_REASON_SUPPORTED_CHANNEL_NOT_VALID 11
// IEEE 802.11i
#define WLAN_REASON_INVALID_IE 13
#define WLAN_REASON_MICHAEL_MIC_FAILURE 14
#define WLAN_REASON_4WAY_HANDSHAKE_TIMEOUT 15
#define WLAN_REASON_GROUP_KEY_UPDATE_TIMEOUT 16
#define WLAN_REASON_IE_IN_4WAY_DIFFERS 17
#define WLAN_REASON_GROUP_CIPHER_NOT_VALID 18
#define WLAN_REASON_PAIRWISE_CIPHER_NOT_VALID 19
#define WLAN_REASON_AKMP_NOT_VALID 20
#define WLAN_REASON_UNSUPPORTED_RSN_IE_VERSION 21
#define WLAN_REASON_INVALID_RSN_IE_CAPAB 22
#define WLAN_REASON_IEEE_802_1X_AUTH_FAILED 23
#define WLAN_REASON_CIPHER_SUITE_REJECTED 24

// Information Element IDs
#define WLAN_EID_SSID 0
#define WLAN_EID_SUPP_RATES 1
#define WLAN_EID_FH_PARAMS 2
#define WLAN_EID_DS_PARAMS 3
#define WLAN_EID_CF_PARAMS 4
#define WLAN_EID_TIM 5
#define WLAN_EID_IBSS_PARAMS 6
#define WLAN_EID_COUNTRY 7
#define WLAN_EID_CHALLENGE 16
// EIDs defined by IEEE 802.11h - START
#define WLAN_EID_PWR_CONSTRAINT 32
#define WLAN_EID_PWR_CAPABILITY 33
#define WLAN_EID_TPC_REQUEST 34
#define WLAN_EID_TPC_REPORT 35
#define WLAN_EID_SUPPORTED_CHANNELS 36
#define WLAN_EID_CHANNEL_SWITCH 37
#define WLAN_EID_MEASURE_REQUEST 38
#define WLAN_EID_MEASURE_REPORT 39
#define WLAN_EID_QUITE 40
#define WLAN_EID_IBSS_DFS 41
// EIDs defined by IEEE 802.11h - END
#define WLAN_EID_ERP_INFO 42
#define WLAN_EID_HT_CAP 45
#define WLAN_EID_RSN 48
#define WLAN_EID_EXT_SUPP_RATES 50
#define WLAN_EID_MOBILITY_DOMAIN 54
#define WLAN_EID_FAST_BSS_TRANSITION 55
#define WLAN_EID_TIMEOUT_INTERVAL 56
#define WLAN_EID_RIC_DATA 57
#define WLAN_EID_HT_OPERATION 61
#define WLAN_EID_SECONDARY_CHANNEL_OFFSET 62
#define WLAN_EID_20_40_BSS_COEXISTENCE 72
#define WLAN_EID_20_40_BSS_INTOLERANT 73
#define WLAN_EID_OVERLAPPING_BSS_SCAN_PARAMS 74
#define WLAN_EID_MMIE 76
#define WLAN_EID_VENDOR_SPECIFIC 221

// Action frame categories (IEEE 802.11-2007, 7.3.1.11, Table 7-24)
#define WLAN_ACTION_SPECTRUM_MGMT 0
#define WLAN_ACTION_QOS 1
#define WLAN_ACTION_DLS 2
#define WLAN_ACTION_BLOCK_ACK 3
#define WLAN_ACTION_PUBLIC 4
#define WLAN_ACTION_RADIO_MEASUREMENT 5
#define WLAN_ACTION_FT 6
#define WLAN_ACTION_HT 7
#define WLAN_ACTION_SA_QUERY 8
#define WLAN_ACTION_WMM 17 // WMM Specification 1.1

// SA Query Action frame (IEEE 802.11w/D8.0, 7.4.9)
#define WLAN_SA_QUERY_REQUEST 0
#define WLAN_SA_QUERY_RESPONSE 1

#define WLAN_SA_QUERY_TR_ID_LEN 2

// Timeout Interval Type
#define WLAN_TIMEOUT_REASSOC_DEADLINE 1
#define WLAN_TIMEOUT_KEY_LIFETIME 2
#define WLAN_TIMEOUT_ASSOC_COMEBACK 3

// Frame control and duration header
struct ieee80211_fc {
	guint16 frame_control;
	guint16 duration_id;
} STRUCT_PACKED;

// Data frame header
struct ieee80211_hdr {
	guint16 frame_control;
	guint16 duration_id;
	guint8 addr1[6];
	guint8 addr2[6];
	guint8 addr3[6];
	guint16 seq_ctrl;
	// followed by 'guint8 addr4[6];' if ToDS and FromDS is set in data frame
} STRUCT_PACKED;

// Control frame headers
struct ieee80211_ctrl_rts {
	guint16 frame_control;
	guint16 duration_id;
	guint8 da[6];
	guint8 sa[6];
} STRUCT_PACKED;

struct ieee80211_ctrl_cts {
	guint16 frame_control;
	guint16 duration_id;
	guint8 da[6];
} STRUCT_PACKED;

struct ieee80211_ctrl_ack {
	guint16 frame_control;
	guint16 duration_id;
	guint8 da[6];
} STRUCT_PACKED;

struct ieee80211_ctrl_pspoll {
	guint16 frame_control;
	guint16 duration_id;
	guint8 bssid[6];
	guint8 sa[6];
} STRUCT_PACKED;

struct ieee80211_ctrl_cfend {
	guint16 frame_control;
	guint16 duration_id;
	guint8 da[6];
	guint8 bssid[6];
} STRUCT_PACKED;

// Management frame header
struct ieee80211_mgmt {
	guint16 frame_control;
	guint16 duration;
	guint8 da[6];
	guint8 sa[6];
	guint8 bssid[6];
	guint16 seq_ctrl;
	union {
		struct {
			guint16 auth_alg;
			guint16 auth_transaction;
			guint16 status_code;
			/* possibly followed by Challenge text */
			guint8 variable[0];
		} STRUCT_PACKED auth;
		struct {
			guint16 reason_code;
		} STRUCT_PACKED deauth;
		struct {
			guint16 capab_info;
			guint16 listen_interval;
			/* followed by SSID and Supported rates */
			guint8 variable[0];
		} STRUCT_PACKED assoc_req;
		struct {
			guint16 capab_info;
			guint16 status_code;
			guint16 aid;
			/* followed by Supported rates */
			guint8 variable[0];
		} STRUCT_PACKED assoc_resp, reassoc_resp;
		struct {
			guint16 capab_info;
			guint16 listen_interval;
			guint8 current_ap[6];
			/* followed by SSID and Supported rates */
			guint8 variable[0];
		} STRUCT_PACKED reassoc_req;
		struct {
			guint16 reason_code;
		} STRUCT_PACKED disassoc;
		struct {
			guint8 timestamp[8];
			guint16 beacon_int;
			guint16 capab_info;
			/* followed by some of SSID, Supported rates,
			 * FH Params, DS Params, CF Params, IBSS Params, TIM */
			guint8 variable[0];
		} STRUCT_PACKED beacon;
		struct {
			/* only variable items: SSID, Supported rates */
			guint8 variable[0];
		} STRUCT_PACKED probe_req;
		struct {
			guint8 timestamp[8];
			guint16 beacon_int;
			guint16 capab_info;
			/* followed by some of SSID, Supported rates,
			 * FH Params, DS Params, CF Params, IBSS Params */
			guint8 variable[0];
		} STRUCT_PACKED probe_resp;
		struct {
			guint8 category;
			union {
				struct {
					guint8 action_code;
					guint8 dialog_token;
					guint8 status_code;
					guint8 variable[0];
				} STRUCT_PACKED wmm_action;
				struct{
					guint8 action_code;
					guint8 element_id;
					guint8 length;
					guint8 switch_mode;
					guint8 new_chan;
					guint8 switch_count;
				} STRUCT_PACKED chan_switch;
				struct {
					guint8 action;
					guint8 sta_addr[ETH_ALEN];
					guint8 target_ap_addr[ETH_ALEN];
					guint8 variable[0]; /* FT Request */
				} STRUCT_PACKED ft_action_req;
				struct {
					guint8 action;
					guint8 sta_addr[ETH_ALEN];
					guint8 target_ap_addr[ETH_ALEN];
					guint16 status_code;
					guint8 variable[0]; /* FT Request */
				} STRUCT_PACKED ft_action_resp;
				struct {
					guint8 action;
					guint8 trans_id[WLAN_SA_QUERY_TR_ID_LEN];
				} STRUCT_PACKED sa_query_req;
				struct {
					guint8 action; /* */
					guint8 trans_id[WLAN_SA_QUERY_TR_ID_LEN];
				} STRUCT_PACKED sa_query_resp;
			} u;
		} STRUCT_PACKED action;
	} u;
} STRUCT_PACKED;

struct ieee80211_qos {
	guint8 priority:3;
	guint8 reserved3:1;
	guint8 eosp:1;
	guint8 ackpol:2;
	guint8 reserved1:1;
	guint8 reserved2;
} STRUCT_PACKED;

struct ieee80211_ht_capabilities {
	guint16 ht_capabilities_info;
	guint8 a_mpdu_params;
	guint8 supported_mcs_set[16];
	guint16 ht_extended_capabilities;
	guint32 tx_bf_capability_info;
	guint8 asel_capabilities;
} STRUCT_PACKED;


struct ieee80211_ht_operation {
	guint8 control_chan;
	guint8 ht_param;
	guint16 operation_mode;
	guint16 stbc_param;
	guint8 basic_set[16];
} STRUCT_PACKED;

#define ERP_INFO_NON_ERP_PRESENT BIT(0)
#define ERP_INFO_USE_PROTECTION BIT(1)
#define ERP_INFO_BARKER_PREAMBLE_MODE BIT(2)


#define HT_CAP_INFO_LDPC_CODING_CAP		((u16) BIT(0))
#define HT_CAP_INFO_SUPP_CHANNEL_WIDTH_SET	((u16) BIT(1))
#define HT_CAP_INFO_SMPS_MASK			((u16) (BIT(2) | BIT(3)))
#define HT_CAP_INFO_SMPS_STATIC			((u16) 0)
#define HT_CAP_INFO_SMPS_DYNAMIC		((u16) BIT(2))
#define HT_CAP_INFO_SMPS_DISABLED		((u16) (BIT(2) | BIT(3)))
#define HT_CAP_INFO_GREEN_FIELD			((u16) BIT(4))
#define HT_CAP_INFO_SHORT_GI20MHZ		((u16) BIT(5))
#define HT_CAP_INFO_SHORT_GI40MHZ		((u16) BIT(6))
#define HT_CAP_INFO_TX_STBC			((u16) BIT(7))
#define HT_CAP_INFO_RX_STBC_MASK		((u16) (BIT(8) | BIT(9)))
#define HT_CAP_INFO_RX_STBC_1			((u16) BIT(8))
#define HT_CAP_INFO_RX_STBC_12			((u16) BIT(9))
#define HT_CAP_INFO_RX_STBC_123			((u16) (BIT(8) | BIT(9)))
#define HT_CAP_INFO_DELAYED_BA			((u16) BIT(10))
#define HT_CAP_INFO_MAX_AMSDU_SIZE		((u16) BIT(11))
#define HT_CAP_INFO_DSSS_CCK40MHZ		((u16) BIT(12))
#define HT_CAP_INFO_PSMP_SUPP			((u16) BIT(13))
#define HT_CAP_INFO_40MHZ_INTOLERANT		((u16) BIT(14))
#define HT_CAP_INFO_LSIG_TXOP_PROTECT_SUPPORT	((u16) BIT(15))


#define EXT_HT_CAP_INFO_PCO			((u16) BIT(0))
#define EXT_HT_CAP_INFO_TRANS_TIME_OFFSET	1
#define EXT_HT_CAP_INFO_MCS_FEEDBACK_OFFSET	8
#define EXT_HT_CAP_INFO_HTC_SUPPORTED		((u16) BIT(10))
#define EXT_HT_CAP_INFO_RD_RESPONDER		((u16) BIT(11))


#define TX_BEAMFORM_CAP_TXBF_CAP ((u32) BIT(0))
#define TX_BEAMFORM_CAP_RX_STAGGERED_SOUNDING_CAP ((u32) BIT(1))
#define TX_BEAMFORM_CAP_TX_STAGGERED_SOUNDING_CAP ((u32) BIT(2))
#define TX_BEAMFORM_CAP_RX_ZLF_CAP ((u32) BIT(3))
#define TX_BEAMFORM_CAP_TX_ZLF_CAP ((u32) BIT(4))
#define TX_BEAMFORM_CAP_IMPLICIT_ZLF_CAP ((u32) BIT(5))
#define TX_BEAMFORM_CAP_CALIB_OFFSET 6
#define TX_BEAMFORM_CAP_EXPLICIT_CSI_TXBF_CAP ((u32) BIT(8))
#define TX_BEAMFORM_CAP_EXPLICIT_UNCOMPR_STEERING_MATRIX_CAP ((u32) BIT(9))
#define TX_BEAMFORM_CAP_EXPLICIT_BF_CSI_FEEDBACK_CAP ((u32) BIT(10))
#define TX_BEAMFORM_CAP_EXPLICIT_BF_CSI_FEEDBACK_OFFSET 11
#define TX_BEAMFORM_CAP_EXPLICIT_UNCOMPR_STEERING_MATRIX_FEEDBACK_OFFSET 13
#define TX_BEAMFORM_CAP_EXPLICIT_COMPRESSED_STEERING_MATRIX_FEEDBACK_OFFSET 15
#define TX_BEAMFORM_CAP_MINIMAL_GROUPING_OFFSET 17
#define TX_BEAMFORM_CAP_CSI_NUM_BEAMFORMER_ANT_OFFSET 19
#define TX_BEAMFORM_CAP_UNCOMPRESSED_STEERING_MATRIX_BEAMFORMER_ANT_OFFSET 21
#define TX_BEAMFORM_CAP_COMPRESSED_STEERING_MATRIX_BEAMFORMER_ANT_OFFSET 23
#define TX_BEAMFORM_CAP_SCI_MAX_OF_ROWS_BEANFORMER_SUPPORTED_OFFSET 25


#define ASEL_CAPABILITY_ASEL_CAPABLE ((guint8) BIT(0))
#define ASEL_CAPABILITY_EXPLICIT_CSI_FEEDBACK_BASED_TX_AS_CAP ((guint8) BIT(1))
#define ASEL_CAPABILITY_ANT_INDICES_FEEDBACK_BASED_TX_AS_CAP ((guint8) BIT(2))
#define ASEL_CAPABILITY_EXPLICIT_CSI_FEEDBACK_CAP ((guint8) BIT(3))
#define ASEL_CAPABILITY_ANT_INDICES_FEEDBACK_CAP ((guint8) BIT(4))
#define ASEL_CAPABILITY_RX_AS_CAP ((guint8) BIT(5))
#define ASEL_CAPABILITY_TX_SOUND_PPDUS_CAP ((guint8) BIT(6))

#define HT_INFO_HT_PARAM_SECONDARY_CHNL_OFF_MASK	((guint8) BIT(0) | BIT(1))
#define HT_INFO_HT_PARAM_SECONDARY_CHNL_ABOVE		((guint8) BIT(0))
#define HT_INFO_HT_PARAM_SECONDARY_CHNL_BELOW		((guint8) BIT(0) | BIT(1))
#define HT_INFO_HT_PARAM_REC_TRANS_CHNL_WIDTH		((guint8) BIT(2))
#define HT_INFO_HT_PARAM_RIFS_MODE			((guint8) BIT(3))
#define HT_INFO_HT_PARAM_CTRL_ACCESS_ONLY		((guint8) BIT(4))
#define HT_INFO_HT_PARAM_SRV_INTERVAL_GRANULARITY	((guint8) BIT(5))


#define OP_MODE_PURE                    0
#define OP_MODE_MAY_BE_LEGACY_STAS      1
#define OP_MODE_20MHZ_HT_STA_ASSOCED    2
#define OP_MODE_MIXED                   3

#define HT_INFO_OPERATION_MODE_OP_MODE_MASK	\
		((guint16) (0x0001 | 0x0002))
#define HT_INFO_OPERATION_MODE_OP_MODE_OFFSET		0
#define HT_INFO_OPERATION_MODE_NON_GF_DEVS_PRESENT	((guint8) BIT(2))
#define HT_INFO_OPERATION_MODE_TRANSMIT_BURST_LIMIT	((guint8) BIT(3))
#define HT_INFO_OPERATION_MODE_NON_HT_STA_PRESENT	((guint8) BIT(4))

#define HT_INFO_STBC_PARAM_DUAL_BEACON			((u16) BIT(6))
#define HT_INFO_STBC_PARAM_DUAL_STBC_PROTECT		((u16) BIT(7))
#define HT_INFO_STBC_PARAM_SECONDARY_BCN		((u16) BIT(8))
#define HT_INFO_STBC_PARAM_LSIG_TXOP_PROTECT_ALLOWED	((u16) BIT(9))
#define HT_INFO_STBC_PARAM_PCO_ACTIVE			((u16) BIT(10))
#define HT_INFO_STBC_PARAM_PCO_PHASE			((u16) BIT(11))


#define OUI_MICROSOFT 0x0050f2 /* Microsoft (also used in Wi-Fi specs)
				* 00:50:F2 */
#define WPA_IE_VENDOR_TYPE 0x0050f201
#define WPS_IE_VENDOR_TYPE 0x0050f204

#define WMM_OUI_TYPE 2
#define WMM_OUI_SUBTYPE_INFORMATION_ELEMENT 0
#define WMM_OUI_SUBTYPE_PARAMETER_ELEMENT 1
#define WMM_OUI_SUBTYPE_TSPEC_ELEMENT 2
#define WMM_VERSION 1

#define WMM_ACTION_CODE_ADDTS_REQ 0
#define WMM_ACTION_CODE_ADDTS_RESP 1
#define WMM_ACTION_CODE_DELTS 2

#define WMM_ADDTS_STATUS_ADMISSION_ACCEPTED 0
#define WMM_ADDTS_STATUS_INVALID_PARAMETERS 1
/* 2 - Reserved */
#define WMM_ADDTS_STATUS_REFUSED 3
/* 4-255 - Reserved */

/* WMM TSPEC Direction Field Values */
#define WMM_TSPEC_DIRECTION_UPLINK 0
#define WMM_TSPEC_DIRECTION_DOWNLINK 1
/* 2 - Reserved */
#define WMM_TSPEC_DIRECTION_BI_DIRECTIONAL 3

/*
 * WMM Information Element (used in (Re)Association Request frames; may also be
 * used in Beacon frames)
 */
struct wmm_information_element {
	/* Element ID: 221 (0xdd); Length: 7 */
	/* required fields for WMM version 1 */
	guint8 oui[3]; /* 00:50:f2 */
	guint8 oui_type; /* 2 */
	guint8 oui_subtype; /* 0 */
	guint8 version; /* 1 for WMM version 1.0 */
	guint8 qos_info; /* AP/STA specific QoS info */

} STRUCT_PACKED;

#define WMM_AC_AIFSN_MASK 0x0f
#define WMM_AC_AIFNS_SHIFT 0
#define WMM_AC_ACM 0x10
#define WMM_AC_ACI_MASK 0x60
#define WMM_AC_ACI_SHIFT 5

#define WMM_AC_ECWMIN_MASK 0x0f
#define WMM_AC_ECWMIN_SHIFT 0
#define WMM_AC_ECWMAX_MASK 0xf0
#define WMM_AC_ECWMAX_SHIFT 4

struct wmm_ac_parameter {
	guint8 aci_aifsn; /* AIFSN, ACM, ACI */
	guint8 cw; /* ECWmin, ECWmax (CW = 2^ECW - 1) */
	guint16 txop_limit;
}  STRUCT_PACKED;

/*
 * WMM Parameter Element (used in Beacon, Probe Response, and (Re)Association
 * Response frmaes)
 */
struct wmm_parameter_element {
	/* Element ID: 221 (0xdd); Length: 24 */
	/* required fields for WMM version 1 */
	guint8 oui[3]; /* 00:50:f2 */
	guint8 oui_type; /* 2 */
	guint8 oui_subtype; /* 1 */
	guint8 version; /* 1 for WMM version 1.0 */
	guint8 qos_info; /* AP/STA specif QoS info */
	guint8 reserved; /* 0 */
	struct wmm_ac_parameter ac[4]; /* AC_BE, AC_BK, AC_VI, AC_VO */

} STRUCT_PACKED;

/* WMM TSPEC Element */
struct wmm_tspec_element {
	guint8 eid; /* 221 = 0xdd */
	guint8 length; /* 6 + 55 = 61 */
	guint8 oui[3]; /* 00:50:f2 */
	guint8 oui_type; /* 2 */
	guint8 oui_subtype; /* 2 */
	guint8 version; /* 1 */
	/* WMM TSPEC body (55 octets): */
	guint8 ts_info[3];
	guint16 nominal_msdu_size;
	guint16 maximum_msdu_size;
	guint32 minimum_service_interval;
	guint32 maximum_service_interval;
	guint32 inactivity_interval;
	guint32 suspension_interval;
	guint32 service_start_time;
	guint32 minimum_data_rate;
	guint32 mean_data_rate;
	guint32 peak_data_rate;
	guint32 maximum_burst_size;
	guint32 delay_bound;
	guint32 minimum_phy_rate;
	guint16 surplus_bandwidth_allowance;
	guint16 medium_time;
} STRUCT_PACKED;


/* Access Categories / ACI to AC coding */
enum {
	WMM_AC_BE = 0 /* Best Effort */,
	WMM_AC_BK = 1 /* Background */,
	WMM_AC_VI = 2 /* Video */,
	WMM_AC_VO = 3 /* Voice */
};


#define OUI_BROADCOM 0x00904c /* Broadcom (Epigram) */

#define VENDOR_HT_CAPAB_OUI_TYPE 0x33 /* 00-90-4c:0x33 */

/* cipher suite selectors */
#define WLAN_CIPHER_SUITE_USE_GROUP	0x000FAC00
#define WLAN_CIPHER_SUITE_WEP40		0x000FAC01
#define WLAN_CIPHER_SUITE_TKIP		0x000FAC02
/* reserved: 				0x000FAC03 */
#define WLAN_CIPHER_SUITE_CCMP		0x000FAC04
#define WLAN_CIPHER_SUITE_WEP104	0x000FAC05
#define WLAN_CIPHER_SUITE_AES_CMAC	0x000FAC06

/* AKM suite selectors */
#define WLAN_AKM_SUITE_8021X		0x000FAC01
#define WLAN_AKM_SUITE_PSK		0x000FAC02

#endif

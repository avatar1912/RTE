/*
 * FreeModbus Libary: Win32 Port
 * Copyright (C) 2006 Christian Walter <wolti@sil.at>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id: port.h, v 1.5 2006/06/26 19:25:17 wolti Exp $
 */

#ifndef _PORT_H
#define _PORT_H

#include <assert.h>
#include <libopencm3/cm3/cortex.h>

#include <mb_common.h>

#include "serial_multi.h"

PR_BEGIN_EXTERN_C
/* ----------------------- Defines ------------------------------------------*/
#define ENTER_CRITICAL_SECTION() cm_disable_interrupts()
#define EXIT_CRITICAL_SECTION()  cm_enable_interrupts()

#define MB_PORT_HAS_CLOSE	1

#ifndef TRUE
#define TRUE            1
#endif

#ifndef FALSE
#define FALSE           0
#endif

/* ----------------------- Type definitions ---------------------------------*/
struct _mb_port_ser
{
    mb_port_base_struct base;
    uint32_t  uart_num;
    bool     tx_en;

	//timer
	DWORD           timeout;
	BOOL            timeout_enable;
	DWORD           time_last;

	DWORD           deafault_timeout;

	//events
	mb_event_enum queued_evt;
	BOOL     evt_in_queue;
};
/* ----------------------- Variable definitions -----------------------------*/
extern mb_port_ser_struct mbs_inst_usart;
extern mb_port_ser_struct mbm_inst_usart;

PR_END_EXTERN_C
#endif

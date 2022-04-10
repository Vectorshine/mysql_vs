
#ifndef page0page_h
#define page0page_h

#include "univ.i"

#include "page0page.h"
#include "page0types.h"
#ifndef UNIV_INNOCHECKSUM
#include "fil0fil.h"
#include "buf0buf.h"
#include "data0data.h"
#include "dict0dict.h"
#include "rem0rec.h"
#endif /* !UNIV_INNOCHECKSUM*/
#include "fsp0fsp.h"
#ifndef UNIV_INNOCHECKSUM
#include "mtr0mtr.h"

#ifdef UNIV_MATERIALIZE
#undef UNIV_INLINE
#define UNIV_INLINE
#endif

/*			bfidx_free_t
			===========
这一部分标志了空闲位置的起始位置
 */

typedef	byte		bfidx_header_t;
#endif /* !UNIV_INNOCHECKSUM */


/*-----------------------------*/
#define BFIDX_FREE 0	/* pointer to start of page free space */
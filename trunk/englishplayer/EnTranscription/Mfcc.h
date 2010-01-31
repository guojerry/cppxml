#pragma once

/*
* Assume P64 or LP64.  If you need to port this to a DSP, let us know.
*/
typedef int		int32;
typedef short		int16;
typedef signed char	int8;
typedef unsigned int	uint32;
typedef unsigned short	uint16;
typedef unsigned char	uint8;
typedef float		float32;
typedef double		float64;
#if defined(_MSC_VER)
typedef __int64	         int64;
typedef unsigned __int64 uint64;
#elif defined(HAVE_LONG_LONG) && (SIZEOF_LONG_LONG == 8)
typedef long long	   int64;
typedef unsigned long long uint64;
#else /* !HAVE_LONG_LONG && SIZEOF_LONG_LONG == 8 */
typedef double          int64;
typedef double          uint64;
#endif /* !HAVE_LONG_LONG && SIZEOF_LONG_LONG == 8 */

#include "fe_internal.h"

/**
* Error codes returned by stuff.
*/
enum fe_error_e {
	FE_SUCCESS = 0,
	FE_OUTPUT_FILE_SUCCESS  = 0,
	FE_CONTROL_FILE_ERROR = -1,
	FE_START_ERROR = -2,
	FE_UNKNOWN_SINGLE_OR_BATCH = -3,
	FE_INPUT_FILE_OPEN_ERROR = -4,
	FE_INPUT_FILE_READ_ERROR = -5,
	FE_MEM_ALLOC_ERROR = -6,
	FE_OUTPUT_FILE_WRITE_ERROR = -7,
	FE_OUTPUT_FILE_OPEN_ERROR = -8,
	FE_ZERO_ENERGY_ERROR = -9,
	FE_INVALID_PARAM_ERROR =  -10
};

#define E_ERROR	TRACE
#define E_FATAL	TRACE
#define E_INFO	TRACE
#define E_WARN	TRACE

class CMfcc
{
public:
	CMfcc(void);
	~CMfcc(void);

public:
	int32 fe_process_frame(int16 const *spch, int32 nsamps, mfcc_t * fr_cep);

private:
	int fe_free(fe_t * fe);
	fe_t* m_fe;
};

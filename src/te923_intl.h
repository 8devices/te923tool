#ifndef __TE923_INTL_H__
#define __TE923_INTL_H__

#ifdef ENABLE_GETTEXT
#include <libintl.h>
#else
#define gettext(x) (x)
#endif
#endif //__TE923_INTL_H__

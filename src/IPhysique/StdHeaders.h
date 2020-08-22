#ifndef __STDHEADERS__H
#define __STDHEADERS__H

// Disable some warnings to allow msvs2005 compile plugin 
// with maxsdk 5 and 6 without warnings.
#if _MSC_VER >= 1300  // Visual Studio .NET
#pragma warning(disable:4002) // too many actual parameters for macro 'FN_0'
#pragma warning(disable:4996) // 'strcpy' was declared deprecated
#pragma warning(disable:4101) // unreferenced local variable
#endif

#define nullptr (0)

// maxsdk headers
#include "Max.h"
#include "istdplug.h"
#include "iparamb2.h"
#include "iparamm2.h"
#include "modstack.h"
#include "guplib.h"
#include "iFnPub.h"
#include "phyexp.h"
#include "bipexp.h"

#endif // __STDHEADERS__H
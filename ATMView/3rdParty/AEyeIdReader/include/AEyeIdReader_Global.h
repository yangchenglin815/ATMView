#ifndef AEYEIDREADER_GLOBAL_H
#define AEYEIDREADER_GLOBAL_H

#include <QtCore/qglobal.h>
#include "HDstdapi.h"

//#pragma comment(lib, "3rdParty/AEyeIdReader/lib/HDstdapi.lib")

#ifdef AEYEIDREADER_LIB
# define AEYEIDREADER_EXPORT Q_DECL_EXPORT
#else
# define AEYEIDREADER_EXPORT Q_DECL_IMPORT
#endif

#endif // AEYEIDREADER_GLOBAL_H

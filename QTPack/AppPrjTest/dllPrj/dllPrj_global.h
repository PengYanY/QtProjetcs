#ifndef DLLPRJ_GLOBAL_H
#define DLLPRJ_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DLLPRJ_LIBRARY)
#  define DLLPRJ_EXPORT Q_DECL_EXPORT
#else
#  define DLLPRJ_EXPORT Q_DECL_IMPORT
#endif

#endif // DLLPRJ_GLOBAL_H

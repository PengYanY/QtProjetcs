#ifndef DLLPRJ2_GLOBAL_H
#define DLLPRJ2_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DLLPRJ2_LIBRARY)
#  define DLLPRJ2_EXPORT Q_DECL_EXPORT
#else
#  define DLLPRJ2_EXPORT Q_DECL_IMPORT
#endif

#endif // DLLPRJ2_GLOBAL_H

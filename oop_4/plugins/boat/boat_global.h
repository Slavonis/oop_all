#ifndef BOAT_GLOBAL_H
#define BOAT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BOAT_LIBRARY)
#define BOAT_EXPORT Q_DECL_EXPORT
#else
#define BOAT_EXPORT Q_DECL_IMPORT
#endif

#endif // BOAT_GLOBAL_H

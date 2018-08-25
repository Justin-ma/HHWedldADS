#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(QTADSOPERATE_LIB)
#  define QTADSOPERATE_EXPORT Q_DECL_EXPORT
# else
#  define QTADSOPERATE_EXPORT Q_DECL_IMPORT
# endif
#else
# define QTADSOPERATE_EXPORT
#endif

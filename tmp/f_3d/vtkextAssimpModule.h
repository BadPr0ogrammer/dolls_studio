
#ifndef VTKEXTASSIMP_EXPORT_H
#define VTKEXTASSIMP_EXPORT_H

#ifdef VTKEXTASSIMP_STATIC_DEFINE
#  define VTKEXTASSIMP_EXPORT
#  define VTKEXTASSIMP_NO_EXPORT
#else
#  ifndef VTKEXTASSIMP_EXPORT
#    ifdef vtkextAssimp_EXPORTS
        /* We are building this library */
#      define VTKEXTASSIMP_EXPORT 
#    else
        /* We are using this library */
#      define VTKEXTASSIMP_EXPORT 
#    endif
#  endif

#  ifndef VTKEXTASSIMP_NO_EXPORT
#    define VTKEXTASSIMP_NO_EXPORT 
#  endif
#endif

#ifndef VTKEXTASSIMP_DEPRECATED
#  define VTKEXTASSIMP_DEPRECATED __declspec(deprecated)
#endif

#ifndef VTKEXTASSIMP_DEPRECATED_EXPORT
#  define VTKEXTASSIMP_DEPRECATED_EXPORT VTKEXTASSIMP_EXPORT VTKEXTASSIMP_DEPRECATED
#endif

#ifndef VTKEXTASSIMP_DEPRECATED_NO_EXPORT
#  define VTKEXTASSIMP_DEPRECATED_NO_EXPORT VTKEXTASSIMP_NO_EXPORT VTKEXTASSIMP_DEPRECATED
#endif

/* NOLINTNEXTLINE(readability-avoid-unconditional-preprocessor-if) */
#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VTKEXTASSIMP_NO_DEPRECATED
#    define VTKEXTASSIMP_NO_DEPRECATED
#  endif
#endif

/* VTK-HeaderTest-Exclude: vtkextAssimpModule.h */

/* Include ABI Namespace */
#include "vtkABINamespace.h"

#endif /* VTKEXTASSIMP_EXPORT_H */

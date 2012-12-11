// bsls_atomicoperations_sparc_sun_cc_default.h                       -*-C++-*-
#ifndef INCLUDED_BSLS_ATOMICOPERATIONS_SPARC_SUN_CC_DEFAULT
#define INCLUDED_BSLS_ATOMICOPERATIONS_SPARC_SUN_CC_DEFAULT

#ifndef INCLUDED_BSLS_IDENT
#include <bsls_ident.h>
#endif
BSLS_IDENT("$Id: $")

//@PURPOSE: Provide default base implementations of atomics for Sparc/Sun.
//
//@CLASSES:
//  bsls::AtomicOperations_SPARC_SUN_CC_Default32: default base for 32bit mode.
//  bsls::AtomicOperations_SPARC_SUN_CC_Default64: default base for 64bit mode.
//
//@DESCRIPTION: This component provides default base classes necessary to
// implement atomics on the Sun Sparc platform with SunCC compiler.  The
// classes are for private use only.  See 'bsls_atomicoperations' and
// 'bsls_atomic' for the public interface to atomics.

#ifndef INCLUDED_BSLS_ATOMICOPERATIONS_DEFAULT
#include <bsls_atomicoperations_default.h>
#endif

#ifndef INCLUDED_BSLS_PLATFORM
#include <bsls_platform.h>
#endif

#ifndef INCLUDED_BSLS_TYPES
#include <bsls_types.h>
#endif

#if (defined(BSLS_PLATFORM_CPU_SPARC_V9)                                     \
                                     || defined(BSLS_PLATFORM_CPU_SPARC_32)) \
    && (defined(BSLS_PLATFORM_CMP_GNU) || defined(BSLS_PLATFORM_CMP_SUN))

namespace BloombergLP {

extern "C"
{
    // 32 bit operation shared between 32 bit and 64 bit platforms

    int bsls_AtomicOperations_Sparc_GetInt(
            const volatile int *atomicInt);

    void bsls_AtomicOperations_Sparc_SetInt(
            volatile int *atomicInt,
            int value);

    int bsls_AtomicOperations_Sparc_SwapInt(
            volatile int *atomicInt,
            int swapValue);

    int bsls_AtomicOperations_Sparc_SwapIntAcqRel(
            volatile int *atomicInt,
            int swapValue);

    int bsls_AtomicOperations_Sparc_TestAndSwapInt(
            volatile int *atomicInt,
            int compareValue,
            int swapValue);

    int bsls_AtomicOperations_Sparc_TestAndSwapIntAcqRel(
            volatile int *atomicInt,
            int compareValue,
            int swapValue);

    int bsls_AtomicOperations_Sparc_AddInt(
            volatile int *atomicInt,
            int value);

    int bsls_AtomicOperations_Sparc_AddIntRelaxed(
            volatile int *atomicInt,
            int value);
}

namespace bsls {

               // ===============================================
               // struct AtomicOperations_SPARC_SUN_CC_DefaultInt
               // ===============================================

template <typename IMP>
struct AtomicOperations_SPARC_SUN_CC_DefaultInt
    : AtomicOperations_DefaultInt<IMP>
{
    typedef Atomic_TypeTraits<IMP> AtomicTypes;

    using AtomicOperations_DefaultInt<IMP>::getIntRelaxed;
    using AtomicOperations_DefaultInt<IMP>::setIntRelaxed;

        // *** atomic functions for int ***

    // CLASS METHODS
    static int getInt(typename AtomicTypes::Int const *atomicInt);

    static int getIntAcquire(typename AtomicTypes::Int const *atomicInt);

    static void setInt(typename AtomicTypes::Int *atomicInt, int value);

    static void setIntRelease(typename AtomicTypes::Int *atomicInt, int value);

    static int swapInt(typename AtomicTypes::Int *atomicInt, int swapValue);

    static int swapIntAcqRel(typename AtomicTypes::Int *atomicInt,
                             int swapValue);

    static int testAndSwapInt(typename AtomicTypes::Int *atomicInt,
                              int compareValue,
                              int swapValue);

    static int testAndSwapIntAcqRel(typename AtomicTypes::Int *atomicInt,
                                    int compareValue,
                                    int swapValue);

    static int addIntNv(typename AtomicTypes::Int *atomicInt, int value);

    static int addIntNvRelaxed(typename AtomicTypes::Int *atomicInt,
                               int value);

    static int addIntNvAcqRel(typename AtomicTypes::Int *atomicInt, int value);
};

               // ==============================================
               // struct AtomicOperations_SPARC_SUN_CC_Default32
               // ==============================================

template <typename IMP>
struct AtomicOperations_SPARC_SUN_CC_Default32
    : AtomicOperations_SPARC_SUN_CC_DefaultInt<IMP>
    , AtomicOperations_DefaultInt64<IMP>
    , AtomicOperations_DefaultPointer32<IMP>
{};

               // ==============================================
               // struct AtomicOperations_SPARC_SUN_CC_Default64
               // ==============================================

template <typename IMP>
struct AtomicOperations_SPARC_SUN_CC_Default64
    : AtomicOperations_SPARC_SUN_CC_DefaultInt<IMP>
    , AtomicOperations_DefaultInt64<IMP>
    , AtomicOperations_DefaultPointer64<IMP>
{};

// ===========================================================================
//                        INLINE FUNCTION DEFINITIONS
// ===========================================================================

               // -----------------------------------------------
               // struct AtomicOperations_SPARC_SUN_CC_DefaultInt
               // -----------------------------------------------

template <typename IMP>
inline
int AtomicOperations_SPARC_SUN_CC_DefaultInt<IMP>::
    getInt(typename AtomicTypes::Int const *atomicInt)
{
    return bsls_AtomicOperations_Sparc_GetInt(&atomicInt->d_value);
}

template <typename IMP>
inline
int AtomicOperations_SPARC_SUN_CC_DefaultInt<IMP>::
    getIntAcquire(typename AtomicTypes::Int const *atomicInt)
{
    return getIntRelaxed(atomicInt);
}

template <typename IMP>
inline
void AtomicOperations_SPARC_SUN_CC_DefaultInt<IMP>::
    setInt(typename AtomicTypes::Int *atomicInt, int value)
{
    bsls_AtomicOperations_Sparc_SetInt(&atomicInt->d_value, value);
}

template <typename IMP>
inline
void AtomicOperations_SPARC_SUN_CC_DefaultInt<IMP>::
    setIntRelease(typename AtomicTypes::Int *atomicInt, int value)
{
    setIntRelaxed(atomicInt, value);
}

template <typename IMP>
inline
int AtomicOperations_SPARC_SUN_CC_DefaultInt<IMP>::
    swapInt(typename AtomicTypes::Int *atomicInt, int swapValue)
{
    return bsls_AtomicOperations_Sparc_SwapInt(&atomicInt->d_value, swapValue);
}

template <typename IMP>
inline
int AtomicOperations_SPARC_SUN_CC_DefaultInt<IMP>::
    swapIntAcqRel(typename AtomicTypes::Int *atomicInt, int swapValue)
{
    return bsls_AtomicOperations_Sparc_SwapIntAcqRel(&atomicInt->d_value,
                                                     swapValue);
}

template <typename IMP>
inline
int AtomicOperations_SPARC_SUN_CC_DefaultInt<IMP>::
    testAndSwapInt(typename AtomicTypes::Int *atomicInt,
                   int compareValue,
                   int swapValue)
{
    return bsls_AtomicOperations_Sparc_TestAndSwapInt(&atomicInt->d_value,
                                                      compareValue,
                                                      swapValue);
}

template <typename IMP>
inline
int AtomicOperations_SPARC_SUN_CC_DefaultInt<IMP>::
    testAndSwapIntAcqRel(typename AtomicTypes::Int *atomicInt,
                         int compareValue,
                         int swapValue)
{
    return bsls_AtomicOperations_Sparc_TestAndSwapIntAcqRel(
                                                        &atomicInt->d_value,
                                                        compareValue,
                                                        swapValue);
}

template <typename IMP>
inline
int AtomicOperations_SPARC_SUN_CC_DefaultInt<IMP>::
    addIntNv(typename AtomicTypes::Int *atomicInt, int value)
{
    return bsls_AtomicOperations_Sparc_AddInt(&atomicInt->d_value, value);
}

template <typename IMP>
inline
int AtomicOperations_SPARC_SUN_CC_DefaultInt<IMP>::
    addIntNvRelaxed(typename AtomicTypes::Int *atomicInt, int value)
{
    return bsls_AtomicOperations_Sparc_AddIntRelaxed(&atomicInt->d_value,
                                                     value);
}

template <typename IMP>
inline
int AtomicOperations_SPARC_SUN_CC_DefaultInt<IMP>::
    addIntNvAcqRel(typename AtomicTypes::Int *atomicInt, int value)
{
    return addIntNvRelaxed(atomicInt, value);
}

}  // close package namespace

}  // close enterprise namespace

#endif

#endif

// ----------------------------------------------------------------------------
// Copyright (C) 2012 Bloomberg L.P.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------- END-OF-FILE ----------------------------------

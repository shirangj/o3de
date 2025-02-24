/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

// include the required headers
#include "ThreadData.h"
#include <EMotionFX/Source/Allocators.h>


namespace EMotionFX
{
    AZ_CLASS_ALLOCATOR_IMPL(ThreadData, ThreadDataAllocator, 0)

    // default constructor
    ThreadData::ThreadData()
        : BaseObject()
    {
        mThreadIndex    = MCORE_INVALIDINDEX32;
    }


    // constructor
    ThreadData::ThreadData(uint32 threadIndex)
    {
        mThreadIndex    = threadIndex;
    }


    // destructor
    ThreadData::~ThreadData()
    {
    }


    // create
    ThreadData* ThreadData::Create()
    {
        return aznew ThreadData();
    }


    // create
    ThreadData* ThreadData::Create(uint32 threadIndex)
    {
        return aznew ThreadData(threadIndex);
    }


    void ThreadData::SetThreadIndex(uint32 index)
    {
        mThreadIndex = index;
    }


    uint32 ThreadData::GetThreadIndex() const
    {
        return mThreadIndex;
    }
}   // namespace EMotionFX

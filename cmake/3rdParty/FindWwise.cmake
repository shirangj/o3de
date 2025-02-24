#
# Copyright (c) Contributors to the Open 3D Engine Project.
# For complete copyright and license terms please see the LICENSE at the root of this distribution.
#
# SPDX-License-Identifier: Apache-2.0 OR MIT
#
#

# The current supported version of Wwise
set(WWISE_VERSION 2021.1.1.7601)

# Wwise Install Path
# Initialize to the default 3rdParty path
set(LY_WWISE_INSTALL_PATH "" CACHE PATH "Path to Wwise version ${WWISE_VERSION} installation.")

function(is_valid_sdk sdk_path is_valid)
    set(${is_valid} FALSE PARENT_SCOPE)
    if(EXISTS ${sdk_path})
        set(sdk_version_file ${sdk_path}/SDK/include/AK/AkWwiseSDKVersion.h)
        if(EXISTS ${sdk_version_file})
            string(FIND ${sdk_path} ${WWISE_VERSION} index)
            if(NOT index EQUAL -1)
                set(${is_valid} TRUE PARENT_SCOPE)
            else()
                # The install path doesn't contain the WWISE_VERSION string.
                # The path could still be correct, but it would require parsing the AkWwiseSDKVersion.h to verify.
            endif()
        endif()
    endif()
endfunction()

# Paths that will be checked, in order:
# - CMake cache variable
# - WWISEROOT Environment Variable
# - Standard 3rdParty path
set(WWISE_SDK_PATHS
    "${LY_WWISE_INSTALL_PATH}"
    "$ENV{WWISEROOT}"
    "${LY_3RDPARTY_PATH}/Wwise/${WWISE_VERSION}"
)

set(found_sdk FALSE)
foreach(test_path ${WWISE_SDK_PATHS})
    is_valid_sdk(${test_path} found_sdk)
    if(found_sdk)
        # Update the Wwise Install Path cache variable
        set(LY_WWISE_INSTALL_PATH "${test_path}")
        break()
    endif()
endforeach()

if(NOT found_sdk)
    # If we don't find a path that appears to be a valid Wwise install, we can bail here.
    # No 3rdParty::Wwise target will exist, so that can be checked elsewhere.
    return()
endif()

message(STATUS "Using Wwise SDK at ${LY_WWISE_INSTALL_PATH}")

set(WWISE_COMMON_LIB_NAMES
    # Core AK
    AkMemoryMgr
    AkMusicEngine
    AkSoundEngine
    AkStreamMgr
    AkSpatialAudio

    # AK Effects
    AkCompressorFX
    AkDelayFX
    AkMatrixReverbFX
    AkMeterFX
    AkExpanderFX
    AkParametricEQFX
    AkGainFX
    AkPeakLimiterFX
    AkRoomVerbFX
    AkGuitarDistortionFX
    AkStereoDelayFX
    AkPitchShifterFX
    AkTimeStretchFX
    AkFlangerFX
    AkTremoloFX
    AkHarmonizerFX
    AkRecorderFX

    # AK Sources
    AkSilenceSource
    AkSineSource
    AkToneSource
    AkAudioInputSource
    AkSynthOneSource
)

set(WWISE_CODEC_LIB_NAMES
    # AK Codecs
    AkVorbisDecoder
    AkOpusDecoder
)

set(WWISE_NON_RELEASE_LIB_NAMES
    # For remote profiling
    CommunicationCentral
)

set(WWISE_ADDITIONAL_LIB_NAMES
    # Additional Libraries
)

set(WWISE_COMPILE_DEFINITIONS
    $<IF:$<CONFIG:Release>,AK_OPTIMIZED,>
)


# The default install path might look different than the standard 3rdParty format (${LY_3RDPARTY_PATH}/<Name>/<Version>).
# Use these to get the parent path and folder name before adding the external 3p target.
get_filename_component(WWISE_3P_ROOT ${LY_WWISE_INSTALL_PATH} DIRECTORY)
get_filename_component(WWISE_FOLDER ${LY_WWISE_INSTALL_PATH} NAME)

ly_add_external_target(
    NAME Wwise
    VERSION "${WWISE_FOLDER}"
    3RDPARTY_ROOT_DIRECTORY "${WWISE_3P_ROOT}"
    INCLUDE_DIRECTORIES SDK/include
    COMPILE_DEFINITIONS ${WWISE_COMPILE_DEFINITIONS}
)

set(Wwise_FOUND TRUE)

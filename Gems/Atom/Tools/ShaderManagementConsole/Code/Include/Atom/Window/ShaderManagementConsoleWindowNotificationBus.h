/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#pragma once

#include <AzCore/EBus/EBus.h>

namespace ShaderManagementConsole
{
    class ShaderManagementConsoleWindowNotifications
        : public AZ::EBusTraits
    {
    public:
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Multiple;
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;

        virtual void OnShaderManagementConsoleWindowClosing() {};
    };
    using ShaderManagementConsoleWindowNotificationBus = AZ::EBus<ShaderManagementConsoleWindowNotifications>;

} // namespace ShaderManagementConsole

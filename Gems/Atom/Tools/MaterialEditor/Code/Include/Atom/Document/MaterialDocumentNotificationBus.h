/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once

#include <Atom/RPI.Reflect/Material/MaterialPropertyDescriptor.h>
#include <Atom/RPI.Public/Material/Material.h>

#include <AzCore/Asset/AssetCommon.h>
#include <AzCore/std/any.h>

#include <AtomToolsFramework/DynamicProperty/DynamicProperty.h>
#include <AtomToolsFramework/DynamicProperty/DynamicPropertyGroup.h>

namespace MaterialEditor
{
    class MaterialDocumentNotifications
        : public AZ::EBusTraits
    {
    public:
        static const AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Multiple;

        //! Signal that a material document was created
        //! @param documentId unique id of material document for which the notification is sent
        virtual void OnDocumentCreated([[maybe_unused]] const AZ::Uuid& documentId) {}

        //! Signal that a material document was destroyed
        //! @param documentId unique id of material document for which the notification is sent
        virtual void OnDocumentDestroyed([[maybe_unused]] const AZ::Uuid& documentId) {}

        //! Signal that a material document was opened
        //! @param documentId unique id of material document for which the notification is sent
        virtual void OnDocumentOpened([[maybe_unused]] const AZ::Uuid& documentId) {}

        //! Signal that a material document was closed
        //! @param documentId unique id of material document for which the notification is sent
        virtual void OnDocumentClosed([[maybe_unused]] const AZ::Uuid& documentId) {}

        //! Signal that a material document was saved
        //! @param documentId unique id of material document for which the notification is sent
        virtual void OnDocumentSaved([[maybe_unused]] const AZ::Uuid& documentId) {}

        //! Signal that a material document was selected
        //! @param documentId unique id of material document for which the notification is sent
        virtual void OnDocumentSelected([[maybe_unused]] const AZ::Uuid& documentId) {}

        //! Signal that a material document was modified
        //! @param documentId unique id of material document for which the notification is sent
        virtual void OnDocumentModified([[maybe_unused]] const AZ::Uuid& documentId) {}

        //! Signal that a material document dependency was modified
        //! @param documentId unique id of material document for which the notification is sent
        virtual void OnDocumentDependencyModified([[maybe_unused]] const AZ::Uuid& documentId) {}

        //! Signal that a material document was modified externally
        //! @param documentId unique id of material document for which the notification is sent
        virtual void OnDocumentExternallyModified([[maybe_unused]] const AZ::Uuid& documentId) {}

        //! Signal that a material document undo state was updated
        //! @param documentId unique id of material document for which the notification is sent
        virtual void OnDocumentUndoStateChanged([[maybe_unused]] const AZ::Uuid& documentId) {}

        //! Signal that a material property changed
        //! @param documentId unique id of material document for which the notification is sent
        //! @param property object containing the property value and configuration that was modified
        virtual void OnDocumentPropertyValueModified([[maybe_unused]] const AZ::Uuid& documentId, [[maybe_unused]] const AtomToolsFramework::DynamicProperty& property) {}

        //! Signal that the property configuration has been changed.
        //! @param documentId unique id of material document for which the notification is sent
        //! @param property object containing the property value and configuration that was modified
        virtual void OnDocumentPropertyConfigModified([[maybe_unused]] const AZ::Uuid& documentId, [[maybe_unused]] const AtomToolsFramework::DynamicProperty& property) {}
        
        //! Signal that the property group visibility has been changed.
        //! @param documentId unique id of material document for which the notification is sent
        //! @param groupId id of the group that changed
        //! @param visible whether the property group is visible
        virtual void OnDocumentPropertyGroupVisibilityChanged([[maybe_unused]] const AZ::Uuid& documentId, [[maybe_unused]] const AZ::Name& groupId, [[maybe_unused]] bool visible) {}
    };

    using MaterialDocumentNotificationBus = AZ::EBus<MaterialDocumentNotifications>;
} // namespace MaterialEditor

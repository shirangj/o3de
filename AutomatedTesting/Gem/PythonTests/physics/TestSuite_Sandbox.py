"""
Copyright (c) Contributors to the Open 3D Engine Project.
For complete copyright and license terms please see the LICENSE at the root of this distribution.

SPDX-License-Identifier: Apache-2.0 OR MIT

"""

# This suite consists of all test cases that are passing and have been verified.

import pytest
import os
import sys

from .FileManagement import FileManagement as fm
from ly_test_tools import LAUNCHERS

sys.path.append(os.path.dirname(os.path.abspath(__file__)) + '/../automatedtesting_shared')

from base import TestAutomationBase


revert_physics_config = fm.file_revert_list(['physxdebugconfiguration.setreg', 'physxdefaultsceneconfiguration.setreg', 'physxsystemconfiguration.setreg'], 'AutomatedTesting/Registry')


@pytest.mark.SUITE_sandbox
@pytest.mark.parametrize("launcher_platform", ['windows_editor'])
@pytest.mark.parametrize("project", ["AutomatedTesting"])
class TestAutomation(TestAutomationBase):

    ## Seems to be flaky, need to investigate
    def test_C19536274_GetCollisionName_PrintsName(self, request, workspace, editor, launcher_platform):
        from . import C19536274_GetCollisionName_PrintsName as test_module
        # Fixme: expected_lines=["Layer Name: Right"]
        self._run_test(request, workspace, editor, test_module)

    ## Seems to be flaky, need to investigate
    def test_C19536277_GetCollisionName_PrintsNothing(self, request, workspace, editor, launcher_platform):
        from . import C19536277_GetCollisionName_PrintsNothing as test_module
        # All groups present in the PhysX Collider that could show up in test
        # Fixme: collision_groups = ["All", "None", "All_NoTouchBend", "All_3", "None_1", "All_NoTouchBend_1", "All_2", "None_1_1", "All_NoTouchBend_1_1", "All_1", "None_1_1_1", "All_NoTouchBend_1_1_1", "All_4", "None_1_1_1_1", "All_NoTouchBend_1_1_1_1", "GroupLeft", "GroupRight"]
        # Fixme: for group in collision_groups:
        # Fixme:    unexpected_lines.append(f"GroupName: {group}")
        # Fixme: expected_lines=["GroupName: "]
        self._run_test(request, workspace, editor, test_module)

    ## Seems to be flaky, need to investigate
    @pytest.mark.xfail(
        reason="Editor crashes and errors about files accessed by multiple processes appear in the log.")
    @revert_physics_config
    def test_C15425929_Undo_Redo(self, request, workspace, editor, launcher_platform):
        from . import C15425929_Undo_Redo as test_module
        self._run_test(request, workspace, editor, test_module)

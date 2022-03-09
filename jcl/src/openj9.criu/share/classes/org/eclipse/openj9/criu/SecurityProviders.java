/*[INCLUDE-IF CRIU_SUPPORT]*/
/*******************************************************************************
 * Copyright (c) 2021, 2022 IBM Corp. and others
 *
 * This program and the accompanying materials are made available under
 * the terms of the Eclipse Public License 2.0 which accompanies this
 * distribution and is available at https://www.eclipse.org/legal/epl-2.0/
 * or the Apache License, Version 2.0 which accompanies this distribution and
 * is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * This Source Code may also be made available under the following
 * Secondary Licenses when the conditions for such availability set
 * forth in the Eclipse Public License, v. 2.0 are satisfied: GNU
 * General Public License, version 2 with the GNU Classpath
 * Exception [1] and GNU General Public License, version 2 with the
 * OpenJDK Assembly Exception [2].
 *
 * [1] https://www.gnu.org/software/classpath/license.html
 * [2] http://openjdk.java.net/legal/assembly-exception.html
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
 *******************************************************************************/
package org.eclipse.openj9.criu;

import java.security.CRIUConfigurator;

/**
 * Handles the security providers.
 */
public class SecurityProviders {

    /* Higher priority hooks are run last in pre-checkoint hooks, and are run
     * first in post restore hooks.
     */
    private static final int RESET_DIGESTS_PRIORITY = 100;
    private static final int RESTORE_SECURITY_PROVIDERS_PRIORITY = 100;

    /**
     * Resets the security digests during checkpoint.
     */
    public static void registerResetDigests() {
        J9InternalCheckpointHookAPI.registerPreCheckpointHook(RESET_DIGESTS_PRIORITY, "Reset the digests", () -> { //$NON-NLS-1$
            com.ibm.security.criu.SHA.resetDigests();
        });
    }
    
    /**
     * Adds the security providers during restore.
     */
    @SuppressWarnings({"deprecation" })
    public static void registerRestoreSecurityProviders() {
        J9InternalCheckpointHookAPI.registerPostRestoreHook(RESTORE_SECURITY_PROVIDERS_PRIORITY,
            "Restore the security providers", () -> { //$NON-NLS-1$
                System.out.println("Debug: Inside security restore hook!"); //$NON-NLS-1$
                System.out.println("Debug: Providers in list:"); //$NON-NLS-1$
                for (java.security.Provider p : java.security.Security.getProviders()) {
                    System.out.println(p.toString());
                }
                
                CRIUConfigurator.setCRIURestoreMode();

                System.out.println("Debug: Providers in list:"); //$NON-NLS-1$
                for (java.security.Provider p : java.security.Security.getProviders()) {
                    System.out.println(p.toString());
                }
            });
    }
}

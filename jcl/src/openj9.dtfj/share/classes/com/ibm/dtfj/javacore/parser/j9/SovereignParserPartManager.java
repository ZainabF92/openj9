/*[INCLUDE-IF Sidecar18-SE]*/
/*******************************************************************************
 * Copyright (c) 2007, 2017 IBM Corp. and others
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
 * [2] https://openjdk.org/legal/assembly-exception.html
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
 *******************************************************************************/
package com.ibm.dtfj.javacore.parser.j9;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;

public class SovereignParserPartManager {
	
	private static SovereignParserPartManager fManager;
	private HashMap fSovParts;
	
	
	
	public SovereignParserPartManager() {
		fSovParts = new HashMap();
	}
	
	
	/**
	 * 
	 * 
	 */
	public static SovereignParserPartManager getCurrent() {
		if (fManager == null) {
			fManager = new SovereignParserPartManager();
		}
		return fManager;
	}
	
	/**
	 * 
	 * @param partsList
	 */
	public void loadSovParts(ArrayList partsList) {
		if (partsList == null) {
			return;
		}
		fSovParts.clear();
		for (Iterator it = partsList.iterator(); it.hasNext();) {
			SovereignSectionParserPart part = (SovereignSectionParserPart) it.next();
			if (part != null) {
				fSovParts.put(part.getSectionName(), part);
			}
		}
	}
	
	
	/**
	 * 
	 * @param sectionName
	 * 
	 */
	public SovereignSectionParserPart getSovPart(String sectionName) {
		return (SovereignSectionParserPart)fSovParts.get(sectionName);
	}
	

}

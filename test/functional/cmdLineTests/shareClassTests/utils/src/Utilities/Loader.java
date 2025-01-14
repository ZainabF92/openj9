/*******************************************************************************
 * Copyright (c) 2005, 2020 IBM Corp. and others
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
package Utilities;

import java.io.FileInputStream;
import java.net.URL;
import java.util.Properties;

import CustomCLs.CustomURLClassLoader;
import Utilities.StringManipulator;
import Utilities.URLClassPathCreator;

/**
 * @author Matthew Kilner
 */
public class Loader {
	
	StringManipulator manipulator = new StringManipulator();

	public static void main(String[] args) {
		
		if(args.length != 2){
			System.out.println("\n Incorrect usage");
			System.out.println("\n Please specifiy -testfile <filename>");
		}
		
		Loader test = new Loader();
		
		String testFile = args[1];
		
		test.testWrapper(testFile);	
	}
	
	public void testWrapper(String testFileName){
		
		System.out.println("\n** Running loader for properties: "+testFileName+"\n");
		
		Properties props = new Properties();
		try{
			FileInputStream PropertiesFile = new FileInputStream(testFileName);
			props.load(PropertiesFile);
			
			PropertiesFile.close();
		} catch (Exception e){
			e.printStackTrace();
		}
		
		String classPath = props.getProperty("ClassPath");
		
		String nctls = props.getProperty("NumberOfClassesToLoad");
		Integer i = Integer.valueOf(nctls);
		int classesToLoadCount = i.intValue();
		
		String[] classesToLoad = new String[classesToLoadCount];
		String classesString = props.getProperty("ClassesToLoad");
		for(int index = 0; index < classesToLoadCount; index ++){
			classesToLoad[index] = manipulator.getStringElement(index, classesString);
		}
		
		executeTest(classPath, classesToLoad);
	}
	
	public void executeTest(String classpath, String[] classes){
		
		System.out.println("\nLoading Classes.....");
			URLClassPathCreator creator = new URLClassPathCreator(classpath);
			URL[] urlPath;
			urlPath = creator.createURLClassPath();
			CustomURLClassLoader cl = new CustomURLClassLoader(urlPath, this.getClass().getClassLoader());
			for(int index = 0; index < classes.length; index++){
				String classToLoad = classes[index];
				if (classToLoad != null){
					try{
						cl.loadClass(classToLoad);
					} catch (Exception e){
						e.printStackTrace();
					}
				}
			}
	}
	
}

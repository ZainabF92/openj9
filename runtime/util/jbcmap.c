/*******************************************************************************
 * Copyright (c) 1991, 2022 IBM Corp. and others
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
#include "j9.h"

const unsigned char sunJavaInstructionSizeTable[] = {
0x01 /* JBnop = 0 = 0x00 */,
0x01 /* JBaconstnull = 1 = 0x01 */,
0x01 /* JBiconstm1 = 2 = 0x02 */,
0x01 /* JBiconst0 = 3 = 0x03 */,
0x01 /* JBiconst1 = 4 = 0x04 */,
0x01 /* JBiconst2 = 5 = 0x05 */,
0x01 /* JBiconst3 = 6 = 0x06 */,
0x01 /* JBiconst4 = 7 = 0x07 */,
0x01 /* JBiconst5 = 8 = 0x08 */,
0x01 /* JBlconst0 = 9 = 0x09 */,
0x01 /* JBlconst1 = 10 = 0x0A */,
0x01 /* JBfconst0 = 11 = 0x0B */,
0x01 /* JBfconst1 = 12 = 0x0C */,
0x01 /* JBfconst2 = 13 = 0x0D */,
0x01 /* JBdconst0 = 14 = 0x0E */,
0x01 /* JBdconst1 = 15 = 0x0F */,
0x02 /* JBbipush = 16 = 0x10 */,
0x03 /* JBsipush = 17 = 0x11 */,
0x02 /* JBldc = 18 = 0x12 */,
0x03 /* JBldcw = 19 = 0x13 */,
0x03 /* JBldc2w = 20 = 0x14 */,
0x02 /* JBiload = 21 = 0x15 */,
0x02 /* JBlload = 22 = 0x16 */,
0x02 /* JBfload = 23 = 0x17 */,
0x02 /* JBdload = 24 = 0x18 */,
0x02 /* JBaload = 25 = 0x19 */,
0x01 /* JBiload0 = 26 = 0x1A */,
0x01 /* JBiload1 = 27 = 0x1B */,
0x01 /* JBiload2 = 28 = 0x1C */,
0x01 /* JBiload3 = 29 = 0x1D */,
0x01 /* JBlload0 = 30 = 0x1E */,
0x01 /* JBlload1 = 31 = 0x1F */,
0x01 /* JBlload2 = 32 = 0x20 */,
0x01 /* JBlload3 = 33 = 0x21 */,
0x01 /* JBfload0 = 34 = 0x22 */,
0x01 /* JBfload1 = 35 = 0x23 */,
0x01 /* JBfload2 = 36 = 0x24 */,
0x01 /* JBfload3 = 37 = 0x25 */,
0x01 /* JBdload0 = 38 = 0x26 */,
0x01 /* JBdload1 = 39 = 0x27 */,
0x01 /* JBdload2 = 40 = 0x28 */,
0x01 /* JBdload3 = 41 = 0x29 */,
0x01 /* JBaload0 = 42 = 0x2A */,
0x01 /* JBaload1 = 43 = 0x2B */,
0x01 /* JBaload2 = 44 = 0x2C */,
0x01 /* JBaload3 = 45 = 0x2D */,
0x01 /* JBiaload = 46 = 0x2E */,
0x01 /* JBlaload = 47 = 0x2F */,
0x01 /* JBfaload = 48 = 0x30 */,
0x01 /* JBdaload = 49 = 0x31 */,
0x01 /* JBaaload = 50 = 0x32 */,
0x01 /* JBbaload = 51 = 0x33 */,
0x01 /* JBcaload = 52 = 0x34 */,
0x01 /* JBsaload = 53 = 0x35 */,
0x02 /* JBistore = 54 = 0x36 */,
0x02 /* JBlstore = 55 = 0x37 */,
0x02 /* JBfstore = 56 = 0x38 */,
0x02 /* JBdstore = 57 = 0x39 */,
0x02 /* JBastore = 58 = 0x3A */,
0x01 /* JBistore0 = 59 = 0x3B */,
0x01 /* JBistore1 = 60 = 0x3C */,
0x01 /* JBistore2 = 61 = 0x3D */,
0x01 /* JBistore3 = 62 = 0x3E */,
0x01 /* JBlstore0 = 63 = 0x3F */,
0x01 /* JBlstore1 = 64 = 0x40 */,
0x01 /* JBlstore2 = 65 = 0x41 */,
0x01 /* JBlstore3 = 66 = 0x42 */,
0x01 /* JBfstore0 = 67 = 0x43 */,
0x01 /* JBfstore1 = 68 = 0x44 */,
0x01 /* JBfstore2 = 69 = 0x45 */,
0x01 /* JBfstore3 = 70 = 0x46 */,
0x01 /* JBdstore0 = 71 = 0x47 */,
0x01 /* JBdstore1 = 72 = 0x48 */,
0x01 /* JBdstore2 = 73 = 0x49 */,
0x01 /* JBdstore3 = 74 = 0x4A */,
0x01 /* JBastore0 = 75 = 0x4B */,
0x01 /* JBastore1 = 76 = 0x4C */,
0x01 /* JBastore2 = 77 = 0x4D */,
0x01 /* JBastore3 = 78 = 0x4E */,
0x01 /* JBiastore = 79 = 0x4F */,
0x01 /* JBlastore = 80 = 0x50 */,
0x01 /* JBfastore = 81 = 0x51 */,
0x01 /* JBdastore = 82 = 0x52 */,
0x01 /* JBaastore = 83 = 0x53 */,
0x01 /* JBbastore = 84 = 0x54 */,
0x01 /* JBcastore = 85 = 0x55 */,
0x01 /* JBsastore = 86 = 0x56 */,
0x01 /* JBpop = 87 = 0x57 */,
0x01 /* JBpop2 = 88 = 0x58 */,
0x01 /* JBdup = 89 = 0x59 */,
0x01 /* JBdupx1 = 90 = 0x5A */,
0x01 /* JBdupx2 = 91 = 0x5B */,
0x01 /* JBdup2 = 92 = 0x5C */,
0x01 /* JBdup2x1 = 93 = 0x5D */,
0x01 /* JBdup2x2 = 94 = 0x5E */,
0x01 /* JBswap = 95 = 0x5F */,
0x01 /* JBiadd = 96 = 0x60 */,
0x01 /* JBladd = 97 = 0x61 */,
0x01 /* JBfadd = 98 = 0x62 */,
0x01 /* JBdadd = 99 = 0x63 */,
0x01 /* JBisub = 100 = 0x64 */,
0x01 /* JBlsub = 101 = 0x65 */,
0x01 /* JBfsub = 102 = 0x66 */,
0x01 /* JBdsub = 103 = 0x67 */,
0x01 /* JBimul = 104 = 0x68 */,
0x01 /* JBlmul = 105 = 0x69 */,
0x01 /* JBfmul = 106 = 0x6A */,
0x01 /* JBdmul = 107 = 0x6B */,
0x01 /* JBidiv = 108 = 0x6C */,
0x01 /* JBldiv = 109 = 0x6D */,
0x01 /* JBfdiv = 110 = 0x6E */,
0x01 /* JBddiv = 111 = 0x6F */,
0x01 /* JBirem = 112 = 0x70 */,
0x01 /* JBlrem = 113 = 0x71 */,
0x01 /* JBfrem = 114 = 0x72 */,
0x01 /* JBdrem = 115 = 0x73 */,
0x01 /* JBineg = 116 = 0x74 */,
0x01 /* JBlneg = 117 = 0x75 */,
0x01 /* JBfneg = 118 = 0x76 */,
0x01 /* JBdneg = 119 = 0x77 */,
0x01 /* JBishl = 120 = 0x78 */,
0x01 /* JBlshl = 121 = 0x79 */,
0x01 /* JBishr = 122 = 0x7A */,
0x01 /* JBlshr = 123 = 0x7B */,
0x01 /* JBiushr = 124 = 0x7C */,
0x01 /* JBlushr = 125 = 0x7D */,
0x01 /* JBiand = 126 = 0x7E */,
0x01 /* JBland = 127 = 0x7F */,
0x01 /* JBior = 128 = 0x80 */,
0x01 /* JBlor = 129 = 0x81 */,
0x01 /* JBixor = 130 = 0x82 */,
0x01 /* JBlxor = 131 = 0x83 */,
0x03 /* JBiinc = 132 = 0x84 */,
0x01 /* JBi2l = 133 = 0x85 */,
0x01 /* JBi2f = 134 = 0x86 */,
0x01 /* JBi2d = 135 = 0x87 */,
0x01 /* JBl2i = 136 = 0x88 */,
0x01 /* JBl2f = 137 = 0x89 */,
0x01 /* JBl2d = 138 = 0x8A */,
0x01 /* JBf2i = 139 = 0x8B */,
0x01 /* JBf2l = 140 = 0x8C */,
0x01 /* JBf2d = 141 = 0x8D */,
0x01 /* JBd2i = 142 = 0x8E */,
0x01 /* JBd2l = 143 = 0x8F */,
0x01 /* JBd2f = 144 = 0x90 */,
0x01 /* JBi2b = 145 = 0x91 */,
0x01 /* JBi2c = 146 = 0x92 */,
0x01 /* JBi2s = 147 = 0x93 */,
0x01 /* JBlcmp = 148 = 0x94 */,
0x01 /* JBfcmpl = 149 = 0x95 */,
0x01 /* JBfcmpg = 150 = 0x96 */,
0x01 /* JBdcmpl = 151 = 0x97 */,
0x01 /* JBdcmpg = 152 = 0x98 */,
0x03 /* JBifeq = 153 = 0x99 */,
0x03 /* JBifne = 154 = 0x9A */,
0x03 /* JBiflt = 155 = 0x9B */,
0x03 /* JBifge = 156 = 0x9C */,
0x03 /* JBifgt = 157 = 0x9D */,
0x03 /* JBifle = 158 = 0x9E */,
0x03 /* JBificmpeq = 159 = 0x9F */,
0x03 /* JBificmpne = 160 = 0xA0 */,
0x03 /* JBificmplt = 161 = 0xA1 */,
0x03 /* JBificmpge = 162 = 0xA2 */,
0x03 /* JBificmpgt = 163 = 0xA3 */,
0x03 /* JBificmple = 164 = 0xA4 */,
0x03 /* JBifacmpeq = 165 = 0xA5 */,
0x03 /* JBifacmpne = 166 = 0xA6 */,
0x03 /* JBgoto = 167 = 0xA7 */,
0x03 /* JBjsr = 168 = 0xA8 */,
0x02 /* JBret = 169 = 0xA9 */,
0x01 /* JBtableswitch = 170 = 0xAA */,
0x01 /* JBlookupswitch = 171 = 0xAB */,
0x01 /* JBireturn = 172 = 0xAC */,
0x01 /* JBlreturn = 173 = 0xAD */,
0x01 /* JBfreturn = 174 = 0xAE */,
0x01 /* JBdreturn = 175 = 0xAF */,
0x01 /* JBareturn = 176 = 0xB0 */,
0x01 /* JBreturn = 177 = 0xB1 */,
0x03 /* JBgetstatic = 178 = 0xB2 */,
0x03 /* JBputstatic = 179 = 0xB3 */,
0x03 /* JBgetfield = 180 = 0xB4 */,
0x03 /* JBputfield = 181 = 0xB5 */,
0x03 /* JBinvokevirtual = 182 = 0xB6 */,
0x03 /* JBinvokespecial = 183 = 0xB7 */,
0x03 /* JBinvokestatic = 184 = 0xB8 */,
0x05 /* JBinvokeinterface = 185 = 0xB9 */,
0x05 /* JBinvokedynamic = 186 = 0xBA */,
0x03 /* JBnew = 187 = 0xBB */,
0x02 /* JBnewarray = 188 = 0xBC */,
0x03 /* JBanewarray = 189 = 0xBD */,
0x01 /* JBarraylength = 190 = 0xBE */,
0x01 /* JBathrow = 191 = 0xBF */,
0x03 /* JBcheckcast = 192 = 0xC0 */,
0x03 /* JBinstanceof = 193 = 0xC1 */,
0x01 /* JBmonitorenter = 194 = 0xC2 */,
0x01 /* JBmonitorexit = 195 = 0xC3 */,
0x01 /* JBwide = 196 = 0xC4 */,
0x04 /* JBmultianewarray = 197 = 0xC5 */,
0x03 /* JBifnull = 198 = 0xC6 */,
0x03 /* JBifnonnull = 199 = 0xC7 */,
0x05 /* JBgotow = 200 = 0xC8 */,
0x05 /* JBjsrw = 201 = 0xC9 */,
0x01 /* JBbreakpoint = 202 = 0xCA */,
0x03 /* JBaconst_init = 203 = 0xCB */ ,
0x03 /* JBwithfield = 204 = 0xCC */ ,
0x00 /* JBunimplemented = 205 = 0xCD */,
0x00 /* JBunimplemented = 206 = 0xCE */,
0x00 /* JBunimplemented = 207 = 0xCF */,
0x00 /* JBunimplemented = 208 = 0xD0 */,
0x00 /* JBunimplemented = 209 = 0xD1 */,
0x00 /* JBunimplemented = 210 = 0xD2 */,
0x00 /* JBunimplemented = 211 = 0xD3 */,
0x00 /* JBunimplemented = 212 = 0xD4 */,
0x00 /* JBunimplemented = 213 = 0xD5 */,
0x00 /* JBunimplemented = 214 = 0xD6 */,
0x00 /* JBunimplemented = 215 = 0xD7 */,
0x00 /* JBunimplemented = 216 = 0xD8 */,
0x00 /* JBunimplemented = 217 = 0xD9 */,
0x00 /* JBunimplemented = 218 = 0xDA */,
0x00 /* JBunimplemented = 219 = 0xDB */,
0x00 /* JBunimplemented = 220 = 0xDC */,
0x00 /* JBunimplemented = 221 = 0xDD */,
0x00 /* JBunimplemented = 222 = 0xDE */,
0x00 /* JBunimplemented = 223 = 0xDF */,
0x00 /* JBunimplemented = 224 = 0xE0 */,
0x00 /* JBunimplemented = 225 = 0xE1 */,
0x00 /* JBunimplemented = 226 = 0xE2 */,
0x00 /* JBunimplemented = 227 = 0xE3 */,
0x00 /* JBunimplemented = 228 = 0xE4 */,
0x00 /* JBunimplemented = 229 = 0xE5 */,
0x00 /* JBunimplemented = 230 = 0xE6 */,
0x00 /* JBunimplemented = 231 = 0xE7 */,
0x00 /* JBunimplemented = 232 = 0xE8 */,
0x00 /* JBunimplemented = 233 = 0xE9 */,
0x00 /* JBunimplemented = 234 = 0xEA */,
0x00 /* JBunimplemented = 235 = 0xEB */,
0x00 /* JBunimplemented = 236 = 0xEC */,
0x00 /* JBunimplemented = 237 = 0xED */,
0x00 /* JBunimplemented = 238 = 0xEE */,
0x00 /* JBunimplemented = 239 = 0xEF */,
0x00 /* JBunimplemented = 240 = 0xF0 */,
0x00 /* JBunimplemented = 241 = 0xF1 */,
0x00 /* JBunimplemented = 242 = 0xF2 */,
0x00 /* JBunimplemented = 243 = 0xF3 */,
0x00 /* JBunimplemented = 244 = 0xF4 */,
0x00 /* JBunimplemented = 245 = 0xF5 */,
0x00 /* JBunimplemented = 246 = 0xF6 */,
0x00 /* JBunimplemented = 247 = 0xF7 */,
0x00 /* JBunimplemented = 248 = 0xF8 */,
0x00 /* JBunimplemented = 249 = 0xF9 */,
0x00 /* JBunimplemented = 250 = 0xFA */,
0x00 /* JBunimplemented = 251 = 0xFB */,
0x00 /* JBunimplemented = 252 = 0xFC */,
0x00 /* JBunimplemented = 253 = 0xFD */,
0x01 /* JBimpdep1 = 254 = 0xFE */,
0x01 /* JBimpdep2 = 255 = 0xFF */
};



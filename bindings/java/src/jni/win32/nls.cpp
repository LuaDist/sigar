/*
 * Copyright (C) [2004, 2005, 2006], Hyperic, Inc.
 * This file is part of SIGAR.
 * 
 * SIGAR is free software; you can redistribute it and/or modify
 * it under the terms version 2 of the GNU General Public License as
 * published by the Free Software Foundation. This program is distributed
 * in the hope that it will be useful, but WITHOUT ANY WARRANTY; without
 * even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA.
 */

#ifdef WIN32

#include "win32bindings.h"
#include "javasigar.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint SIGAR_JNI(win32_LocaleInfo_getSystemDefaultLCID)
(JNIEnv *env, jclass objcls)
{
    return GetSystemDefaultLCID();
}

JNIEXPORT jstring SIGAR_JNI(win32_LocaleInfo_getAttribute)
(JNIEnv *env, jclass objcls, jint lcid, jint attr)
{
    char value[8192];
    int retval =
        GetLocaleInfo(lcid,
                      attr,
                      value, sizeof(value));

    if (retval) {
        return env->NewStringUTF(value);
    }
    else {
        return NULL;
    }
}

#ifdef __cplusplus
}
#endif
#endif /* WIN32 */
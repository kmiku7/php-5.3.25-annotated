/*
   +----------------------------------------------------------------------+
   | Zend Engine                                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) 1998-2013 Zend Technologies Ltd. (http://www.zend.com) |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.00 of the Zend license,     |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.zend.com/license/2_00.txt.                                |
   | If you did not receive a copy of the Zend license and are unable to  |
   | obtain it through the world-wide-web, please send a note to          |
   | license@zend.com so we can mail you a copy immediately.              |
   +----------------------------------------------------------------------+
   | Authors: Andi Gutmans <andi@zend.com>                                |
   |          Zeev Suraski <zeev@zend.com>                                |
   +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef ZEND_TYPES_H
#define ZEND_TYPES_H

typedef unsigned char zend_bool;
typedef unsigned char zend_uchar;
typedef unsigned int zend_uint;
typedef unsigned long zend_ulong;
typedef unsigned short zend_ushort;

#define HAVE_ZEND_LONG64
#ifdef ZEND_WIN32
typedef __int64 zend_long64;
typedef unsigned __int64 zend_ulong64;
#elif SIZEOF_LONG_LONG_INT == 8
typedef long long int zend_long64;
typedef unsigned long long int zend_ulong64;
#elif SIZEOF_LONG_LONG == 8
typedef long long zend_long64;
typedef unsigned long long zend_ulong64;
#else
# undef HAVE_ZEND_LONG64
#endif

#ifdef _WIN64
typedef __int64 zend_intptr_t;
typedef unsigned __int64 zend_uintptr_t;
#else
typedef long zend_intptr_t;
typedef unsigned long zend_uintptr_t;
#endif

typedef unsigned int zend_object_handle;
typedef struct _zend_object_handlers zend_object_handlers;


typedef struct _zend_object_value {
	// unsigned, 对象池索引
	// 整数类型, 具体对象在一个全局结构里维护.
	// EG(object_store).object_buckets
	// 需要hash过程？
	// 具体数据结构是 struct _zend_object
	zend_object_handle handle;

	// 这个指针值是类唯一的还是对象唯一的？仅仅是加快存取做的缓存？
	// http://www.lai18.com/content/425180.html
	// 根据这里的描述，在object创建的时候初始化，那么应该是对象唯一的
	// 然后对象运行时可能做出修改？how？
	// 见 file: zend_objects.c	line: 140
	//		retval.handlers = &std_object_handlers;
	zend_object_handlers *handlers;
} zend_object_value;

#endif /* ZEND_TYPES_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * indent-tabs-mode: t
 * End:
 */

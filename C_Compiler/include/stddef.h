//
//  stddef.h
//  C_Compiler
//
//  Created by 张少雄 on 12/28/16.
//  Copyright © 2016 张少雄. All rights reserved.
//

#ifndef stddef_h
#define stddef_h

#define NULL ((void *)0)

typedef unsigned long size_t;
typedef long ptrdiff_t;
typedef unsigned int wchar_t;
typedef long double max_align_t;

#define offsetof(type, member) ((size_t)&(((type *)0)->member))

#endif /* stddef_h */

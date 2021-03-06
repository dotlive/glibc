/* Test for vector sincosf ABI.
   Copyright (C) 2016-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include <math.h>

#define N 1000
float x[N], s[N], c[N];
float *s_ptrs[N];
float *c_ptrs[N];

int
test_sincosf_abi (void)
{
  int i;
  for(i = 0; i < N; i++)
  {
    x[i] = i / 3;
    s_ptrs[i] = &s[i];
    c_ptrs[i] = &c[i];
  }

#pragma omp simd
  for(i = 0; i < N; i++)
    sincosf (x[i], s_ptrs[i], c_ptrs[i]);

  return 0;
}

// Copyright 2012 Cloudera Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "udf-sample.h"

#include <string>
#include <stdio.h>

#define UNIT_X 408
#define UNIT_Y 324

StringVal FindInnerposInSet(FunctionContext* context, const FloatVal& x, const FloatVal& y,
  const StringVal& pos_set, const IntVal& radius, const IntVal& find_num) {
  if (x.is_null || y.is_null || pos_set.is_null || pos_set.len == 0 || radius.is_null)
    return StringVal::null();
  int32_t i;
  for(i = 0; (pos_set.ptr[i] == ' ') || (pos_set.ptr[i] == '\t') || (pos_set.ptr[i] == '\n'); i++){}
  if (pos_set.len <= i) 
    return StringVal::null();
  char tmp_x[21];
  char tmp_y[21];
  int32_t pos_index = 1;
  int32_t start = 0;
  int32_t end;
  int32_t res_find[find_num.val];
  int32_t res_index = 0;
  double pos_x = 0., pos_y = 0.;
  bool only_x = false;

  memset(tmp_x, 0x00, 21);
  memset(tmp_y, 0x00, 21);

  //debug
  //std::cout << "arg1:" << x.val << ", arg2:" << y.val << ", arg3:" << pos_set.ptr << ", arg4:" << radius.val << ", arg5:" << find_num.val << '\n'; 

  do {
    if (find_num.val <= res_index) break;
    end = start;
    while(end < pos_set.len) {
      if (pos_set.ptr[end] == ':') {
        only_x = false; break;
      } else if (pos_set.ptr[end] == ',') {
        only_x = true; break;
      } else {
        ++end;
      }
    }
    if (end - start > 20)
      context->SetError("The x-coordinate string size should less than 20.");
    memcpy(tmp_x, pos_set.ptr + start, end - start);
    tmp_x[end - start] = '\0';
    pos_x = atof(tmp_x);
    //debug
    //std::cout << "x in set: " << pos_x << '\n';
    if (!only_x)
      start = end + 1;
    else
      start = end;

    end = start;
    while(pos_set.ptr[end] != ',' && end < pos_set.len) ++end;
    if (end - start > 20)
      context->SetError("The y-coordinate string size should less than 20.");
    memcpy(tmp_y, pos_set.ptr + start, end - start);
    tmp_y[end - start] = '\0';
    pos_y = atof(tmp_y);
    //debug
    //std::cout << "y in set: " << pos_y << '\n';
    start = end + 1;

    if (((pos_x - (double)UNIT_X * radius.val < x.val) && (x.val < pos_x + (double)UNIT_X * radius.val)) &&
        ((pos_y - (double)UNIT_Y * radius.val < y.val) && (y.val < pos_y + (double)UNIT_Y * radius.val))) {
      res_find[res_index++] = pos_index;
      //debug
      //std::cout << "res_index:" << res_index << ", pos_index:" << pos_index << '\n';
    }
    ++pos_index;
  } while (start < pos_set.len);

  if (res_index == 0) return StringVal::null(); 
  char result_str[34 * res_index];
  int32_t offset = 0;
  for (int32_t j = 0; j < res_index; j++) {
    sprintf((char *)(result_str + offset), "%d", res_find[j]);
    int32_t len = strlen((char *)(result_str + offset));
    offset += len;
    if (j != res_index - 1) {
      memcpy(result_str + offset, ",", 1);
      ++offset;
    }
  }
  result_str[offset] = '\0';
  //debug
  //std::cout << "result_str:" << result_str << ", offset:" << offset << '\n';
  StringVal result = StringVal(context, offset); 
  memcpy(result.ptr, result_str, offset);
  return result; 
}


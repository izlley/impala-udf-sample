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


#ifndef IMPALA_UDF_SAMPLE_UDF_H
#define IMPALA_UDF_SAMPLE_UDF_H

#include <udf/udf.h>

using namespace impala_udf;

// Usage: > create function rsa-decryption(string) returns string
//          location '/user/cloudera/libudfsample.so' SYMBOL='RSAPrivateDecryption';                                                                              
//        > select rsa-decryption('');
StringVal FindInnerposInSet(FunctionContext* context, const FloatVal& x, const FloatVal& y,
  const StringVal& pos_set, const IntVal& radius, const IntVal& find_num = IntVal(1));

#endif

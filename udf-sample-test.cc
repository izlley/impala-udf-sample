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

#include <iostream>

#include <udf/udf-test-harness.h>
#include "udf-sample.h"

using namespace impala;
using namespace impala_udf;
using namespace std;

int main(int argc, char** argv) {
  bool passed = true;
  // Using the test harness helpers, validate the UDF returns correct results.
  // These tests validate:
  //  AddUdf(1, 2) == 3
  //  AddUdf(null, 2) == null
//  passed &= UdfTestHarness::ValidateUdf<IntVal, IntVal, IntVal>(
//      AddUdf, IntVal(1), IntVal(2), IntVal(3));
//  passed &= UdfTestHarness::ValidateUdf<IntVal, IntVal, IntVal>(
//      AddUdf, IntVal::null(), IntVal(2), IntVal::null());

  //  FindInnerposInSet(0, 0, "407:323,408:324,409:325,410:326", 1, 1) == 1
  //  FindInnerposInSet(0, 0, "407:323,408:324,409:325,410:326,400:320", 1, 3) == 2
  //  FindInnerposInSet(0, 0, "407:323,408:324,-407:-323,-408:-324,-407:323,-408:324,407:-323,408:-324", 1, 4) == 4
  //  FindInnerposInSet(0, 0, "408:324", 1, 1) == null
  //  FindInnerposInSet(0, 0, "407.99999:323.99999", 1, 1) == 1
  //  FindInnerposInSet(0, 0, "407.99999999999999999:323.99999999999999999", 1, 1) == error
  passed &= UdfTestHarness::ValidateUdf<StringVal, FloatVal, FloatVal, StringVal, IntVal, IntVal>(
      FindInnerposInSet, FloatVal(0), FloatVal(0), StringVal("407:323,408:324,409:325,410:326"), IntVal(1), IntVal(1), StringVal("1"));
  passed &= UdfTestHarness::ValidateUdf<StringVal, FloatVal, FloatVal, StringVal, IntVal, IntVal>(
      FindInnerposInSet, FloatVal(0), FloatVal(0), StringVal("407:323,408:324,409:325,410:326"), IntVal(2), IntVal(3), StringVal("1,2,3"));
  passed &= UdfTestHarness::ValidateUdf<StringVal, FloatVal, FloatVal, StringVal, IntVal, IntVal>(
      FindInnerposInSet, FloatVal(0), FloatVal(0), StringVal("407:323,408:324,409:325,410:326,400:320"), IntVal(1), IntVal(3), StringVal("1,5"));
  passed &= UdfTestHarness::ValidateUdf<StringVal, FloatVal, FloatVal, StringVal, IntVal, IntVal>(
      FindInnerposInSet, FloatVal(0), FloatVal(0), StringVal("407:323,408:324,-407:-323,-408:-324,-407:323,-408:324,407:-323,408:-324"), IntVal(1), IntVal(3), StringVal("1,3,5"));
  passed &= UdfTestHarness::ValidateUdf<StringVal, FloatVal, FloatVal, StringVal, IntVal, IntVal>(
      FindInnerposInSet, FloatVal(0), FloatVal(0), StringVal("408:324"), IntVal(1), IntVal(1), StringVal::null());
  passed &= UdfTestHarness::ValidateUdf<StringVal, FloatVal, FloatVal, StringVal, IntVal, IntVal>(
      FindInnerposInSet, FloatVal(0), FloatVal(0), StringVal("407.99999:323.99999"), IntVal(1), IntVal(1), StringVal("1"));
  passed &= UdfTestHarness::ValidateUdf<StringVal, FloatVal, FloatVal, StringVal, IntVal, IntVal>(
      FindInnerposInSet, FloatVal(0), FloatVal(0), StringVal(""), IntVal(1), IntVal(1), StringVal::null());
  passed &= UdfTestHarness::ValidateUdf<StringVal, FloatVal, FloatVal, StringVal, IntVal, IntVal>(
      FindInnerposInSet, FloatVal(0), FloatVal(0), StringVal(" \t\n "), IntVal(1), IntVal(1), StringVal::null());
  passed &= UdfTestHarness::ValidateUdf<StringVal, FloatVal, FloatVal, StringVal, IntVal, IntVal>(
      FindInnerposInSet, FloatVal(0), FloatVal(0), StringVal("0,0,100:200,0,1"), IntVal(1), IntVal(5), StringVal("1,2,3,4,5"));
  passed &= UdfTestHarness::ValidateUdf<StringVal, FloatVal, FloatVal, StringVal, IntVal, IntVal>(
      FindInnerposInSet, FloatVal(0), FloatVal(0), StringVal("0,1,-408"), IntVal(1), IntVal(2), StringVal("1,2"));
//  passed &= UdfTestHarness::ValidateUdf<StringVal, FloatVal, FloatVal, StringVal, IntVal, IntVal>(
//      FindInnerposInSet, FloatVal(0), FloatVal(0), StringVal("407.99999999999999999:323.99999999999999999"), IntVal(1), IntVal(1), StringVal::null());

  cout << "Tests " << (passed ? "Passed." : "Failed.") << endl;
  return !passed;
}

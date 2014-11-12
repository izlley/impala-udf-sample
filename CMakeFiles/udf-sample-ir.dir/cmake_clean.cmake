FILE(REMOVE_RECURSE
  "CMakeFiles/udf-sample-ir"
  "../../build/release//udf_samples/udf-sample.ll"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/udf-sample-ir.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)

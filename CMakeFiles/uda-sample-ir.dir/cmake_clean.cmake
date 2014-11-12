FILE(REMOVE_RECURSE
  "CMakeFiles/uda-sample-ir"
  "../../build/release//udf_samples/uda-sample.ll"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/uda-sample-ir.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)

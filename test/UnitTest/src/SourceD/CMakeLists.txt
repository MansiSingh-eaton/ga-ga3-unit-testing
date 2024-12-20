# Create test suite
#create_test_suite(SourceD_Test)

# Add files under test
#add_files_under_test(SourceD_Test SourceD/SourceD.cpp)

#include_source_files(SourceD_Test
 #   SourceD/SourceD.hpp 
#)

# Substitute mock files
#substitute_mock_files(SourceC_Test 
#src/SourceD/SourceD.hpp
#src/SourceD/SourceD.cpp
#)


# Add test sources
#target_sources(SourceC_Test PRIVATE SourceC_Test.cpp)
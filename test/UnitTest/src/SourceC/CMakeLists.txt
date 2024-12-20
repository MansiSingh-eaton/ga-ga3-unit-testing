# Create test suite
create_test_suite(SourceC_Test)

# Add files under test
add_files_under_test(SourceC_Test SourceC/SourceC.cpp)

include_source_files(SourceC_Test
    SourceC/SourceC.hpp 
)

# include_source_files(SourceC_Test
#     SourceD/SourceD.hpp SourceD/SourceD.cpp
# )

substitute_mock_files(SourceC_Test 
src/SourceD/SourceD.hpp
src/SourceD/SourceD.cpp
)

# Add test sources
target_sources(SourceC_Test PRIVATE SourceC_Test.cpp)
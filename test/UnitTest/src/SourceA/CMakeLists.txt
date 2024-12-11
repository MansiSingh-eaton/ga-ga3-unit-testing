# Create test suite
create_test_suite(SourceA_Test)

# Add files under test
add_files_under_test(SourceA_Test SourceA/SourceA.cpp)

include_source_files( SourceA_Test
    SourceA/SourceA.hpp
)

# Substitute mock files
substitute_mock_files(SourceA_Test 
src/SourceB/SourceB.hpp
src/SourceB/SourceB.cpp
)

# Add test sources
target_sources(SourceA_Test PRIVATE SourceA_Test.cpp)



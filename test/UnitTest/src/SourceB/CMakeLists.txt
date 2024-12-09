# Create test suite
create_test_suite(SourceB_Test)

# Add files under test
add_files_under_test(SourceB_Test SourceB/SourceB.cpp)

include_source_files(SourceB_Test
    SourceB/SourceB.hpp
)

# Add test sources
target_sources(SourceB_Test PRIVATE SourceB_Test.cpp)
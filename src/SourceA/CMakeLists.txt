
cmake_minimum_required(VERSION 3.10)



target_sources(app PRIVATE
    "SourceA.cpp"
)

target_include_directories(app PUBLIC "./")

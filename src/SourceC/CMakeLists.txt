
cmake_minimum_required(VERSION 3.10)



target_sources(app PRIVATE
    "SourceC.cpp"
)

target_include_directories(app PUBLIC "./")

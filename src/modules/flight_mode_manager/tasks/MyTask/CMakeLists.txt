px4_add_library(FlightTaskMyTask
    FlightTaskMyTask.cpp
)

target_link_libraries(FlightTaskMyTask PUBLIC FlightTask)
target_include_directories(FlightTaskMyTask PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

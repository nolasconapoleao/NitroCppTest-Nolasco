target_sources(
  utilities
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Rectangle.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Intersector.cpp
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Rectangle.h ${CMAKE_CURRENT_SOURCE_DIR}/Intersector.h
)

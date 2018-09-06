set(base_SRCS
    socket_operator.cpp
  )

add_library(levent_net ${base_SRCS})
target_link_libraries(levent_net pthread rt)

install(TARGETS levent_net DESTINATION lib)

file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/levent/net)

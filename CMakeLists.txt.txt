cmake_minimum_required(VERSION 3.22)
Project(CINEMAAPP)
set(src_files 
${CMAKE_SOURCE_DIR}/src/main.cpp 
${CMAKE_SOURCE_DIR}/src/customer/customer.cpp
${CMAKE_SOURCE_DIR}/src/cinema/movie/movie.cpp
${CMAKE_SOURCE_DIR}/src/payment/payment.cpp
${CMAKE_SOURCE_DIR}/src/reservation.cpp
${CMAKE_SOURCE_DIR}/src/cinema/cinema.cpp
${CMAKE_SOURCE_DIR}/src/cinema/showtime/hall/hall.cpp
#${CMAKE_SOURCE_DIR}/src/customer/Iobserve.cpp
#${CMAKE_SOURCE_DIR}/src/cinema/Isubject.cpp
${CMAKE_SOURCE_DIR}/src/notification_manager.cpp
${CMAKE_SOURCE_DIR}/src/payment/payment_method.cpp
${CMAKE_SOURCE_DIR}/src/payment/payment_status.cpp
${CMAKE_SOURCE_DIR}/src/cinema/showtime/hall/seat/seat_types.h
${CMAKE_SOURCE_DIR}/src/cinema/showtime/showtime.cpp
${CMAKE_SOURCE_DIR}/src/customer/UI/UI.cpp src/cinema/cinema.h src/cinema/movie/movie.cpp src/cinema/movie/movie.h src/cinema/movie/movie.h src/cinema/movie/movie.h src/payment/payment.cpp src/customer/customer.cpp src/customer/customer.h src/cinema/showtime/hall/hall.cpp src/cinema/showtime/hall/hall.h src/customer/Iobserve.h src/cinema/Isubject.h src/cinema/showtime/showtime.cpp src/cinema/showtime/showtime.h src/cinema/showtime/hall/seat/seat_types.h)

add_executable(appbinary ${src_files} src/cinema/movie/movie.h)
target_include_directories(appbinary PUBLIC inc/)
cmake_minimum_required(VERSION 3.28)
project(PBT)

set(CMAKE_CXX_STANDARD 23)

# Add ASan flags for Clang or GCC
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(ASAN_FLAGS "-fsanitize=address -fno-omit-frame-pointer")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ASAN_FLAGS}")
    set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} ${ASAN_FLAGS}")
endif()

include(FetchContent)

# Fetch libxlsxwriter from the master branch
FetchContent_Declare(
        libxlsxwriter
        GIT_REPOSITORY https://github.com/jmcnamara/libxlsxwriter.git
        GIT_TAG main  # Use the master branch
)

FetchContent_MakeAvailable(libxlsxwriter)

# Add the executable and link libraries
add_executable(PBT
        src/main.cpp
        src/MainMenu.cpp
        src/MainMenu.h
        src/Menu.cpp
        src/Menu.h
        src/Transaction.cpp
        src/Transaction.h
        src/CSVExporter.cpp
        src/CSVExporter.h
        src/CSVImporter.cpp
        src/CSVImporter.h
        src/ExcelExporter.cpp
        src/ExcelExporter.h
        src/Utils.cpp
        src/Utils.h
        src/TransactionManager.cpp
        src/TransactionManager.h
        src/CSVImporter.cpp
        src/CSVImporter.h
        src/TransactionParser.cpp
        src/TransactionParser.h
        src/Report.cpp
        src/Report.h
        src/BalanceReport.cpp
        src/BalanceReport.h
        src/CategoryReport.cpp
        src/CategoryReport.h
        src/ReportMenu.cpp
        src/ReportMenu.h
        src/ReportManager.cpp
        src/ReportManager.h
        src/MenuSwitcher.cpp
        src/MenuSwitcher.h
        src/MonthlyReport.cpp
        src/MonthlyReport.h
        src/QuarterlyReport.cpp
        src/QuarterlyReport.h
        src/DetailedCategoryReport.cpp
        src/DetailedCategoryReport.h
        src/DateRangeReport.cpp
        src/DateRangeReport.h
        src/PaymentModeReport.cpp
        src/PaymentModeReport.h
)

target_link_libraries(PBT PRIVATE xlsxwriter)

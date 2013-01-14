cmake_minimum_required(VERSION 2.8)


PROJECT(KanjiTools)

SET(QT_USE_QTSQL TRUE)
FIND_PACKAGE(Qt4 REQUIRED)




#Then all sources involved in the build process are assigned to two variables. 
#The SET command assigns the variable listed first with the values that follow. 
#The names, helloworld_SOURCES and helloworld_HEADERS, is by convention. 
#You can name them either way you like.

SET(KanjiTools_SOURCES main.cxx
db_connection.cpp
logindialog.cpp
kanjitoolswindow.cpp
kanjidialog.cpp
core.cpp
kanji_module.cpp
userdialog.cpp
user_account_module.cpp
basetest.cpp
onyoumitest1.cpp
onyoumitest2.cpp
kunyoumitest1.cpp
kunyoumitest2.cpp
connector_wrapper.cpp)
SET(KanjiTools_HEADERS logindialog.h kanjitoolswindow.h kanjidialog.h core.h kanji_module.h common.h userdialog.h
user_account_module.h
basetest.h
onyoumitest1.h
onyoumitest2.h
kunyoumitest1.h
kunyoumitest2.h)
SET(KanjiTools_FORMS logindialog.ui kanjitoolswindow.ui kanjidialog.ui userdialog.ui)
SET(KanjiTools_RESOURCES resources.qrc)

#Notice that the headers only include the headers that needs to be processed by moc. 
#All other headers can be left out of the CMakeLists.txt file. 
#This also implicates that if you add a Q_OBJECT macro to any of your classes you must ensure that it is listed here.

#To invoke moc, the macro QT4_WRAP_CPP is used. 
#It assigns the names of the resulting files to the variable listed first. 
#In this case the line looks as follows.

QT4_WRAP_CPP(KanjiTools_HEADERS_MOC ${KanjiTools_HEADERS})
QT4_WRAP_UI(KanjiTools_FORMS_HEADERS ${KanjiTools_FORMS})
QT4_ADD_RESOURCES(KanjiTools_RCC_SRCS ${KanjiTools_RESOURCES})

#What happens is that all headers are processed by moc and the names of the resulting source files are listed in the helloworld_HEADERS_MOC variable. 
#Again, the variable name is by convention rather than forced.

#In order to build a Qt application, the Qt include directories needs to be added as well as a range of defines need to be set. 
#This is handled through the commands INCLUDE and ADD_DEFINITIONS.

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

#Finally, CMake needs to know the name of the resulting executable and what to link it to. 
#This is conveniently handled by by the commands ADD_EXECUTABLE and TARGET_LINK_LIBRARIES. 
#Now CMake knows what to build, from what and through which steps.

ADD_EXECUTABLE(KanjiTools ${KanjiTools_SOURCES} 
    ${KanjiTools_HEADERS_MOC}
    ${KanjiTools_FORMS_HEADERS}
    ${KanjiTools_RCC_SRCS})
    
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

IF(UNIX)
SET(CMAKE_CXX_FLAGS "-std=gnu++0x")
ENDIF()


TARGET_LINK_LIBRARIES(KanjiTools ${QT_LIBRARIES})

SET(CMAKE_BUILD_TYPE Debug)



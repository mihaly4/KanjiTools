 
PROJECT(KanjiTools)
FIND_PACKAGE(Qt4 REQUIRED)

#Then all sources involved in the build process are assigned to two variables. 
#The SET command assigns the variable listed first with the values that follow. 
#The names, helloworld_SOURCES and helloworld_HEADERS, is by convention. 
#You can name them either way you like.

SET(KanjiTools_SOURCES main.cpp mainwindow.cpp)
SET(KanjiTools_HEADERS mainwindow.h)
SET(KanjiTools_FORMS mainwindow.ui)
#SET(KanjiTools_RESOURCES images.qrc)

#Notice that the headers only include the headers that needs to be processed by moc. 
#All other headers can be left out of the CMakeLists.txt file. 
#This also implicates that if you add a Q_OBJECT macro to any of your classes you must ensure that it is listed here.

#To invoke moc, the macro QT4_WRAP_CPP is used. 
#It assigns the names of the resulting files to the variable listed first. 
#In this case the line looks as follows.

QT4_WRAP_CPP(KanjiTools_HEADERS_MOC ${KanjiTools_HEADERS})
QT4_WRAP_UI(KanjiTools_FORMS_HEADERS ${KanjiTools_FORMS})
#QT4_ADD_RESOURCES(KanjiTools_RESOURCES_RCC ${KanjiTools_RESOURCES})

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
    ${KanjiTools_FORMS_HEADERS})
    #${KanjiTools_RESOURCES_RCC})
    
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

TARGET_LINK_LIBRARIES(KanjiTools ${QT_LIBRARIES})

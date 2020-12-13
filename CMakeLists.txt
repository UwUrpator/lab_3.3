cmake_minimum_required(VERSION 3.17)
project(lab_3_3)

set(CMAKE_CXX_STANDARD 20)

include_directories(source)

set(SOURCE_FILES
        main.cpp
        constants.hpp

        #source
        source/Graph/Graph.hpp
        source/Graph/NodesStates.hpp
        source/Dijkstra/Dijkstra.hpp

        #tests
        tests/TestRunner.hpp
        tests/Informator/Informator.hpp
        tests/DijkstraTester/DijkstraTester.hpp


        #interface
        interface/basic/SelectorUI.hpp
        interface/basic/SingleField.hpp
        interface/basic/MultiField.hpp
        interface/UIStarter.hpp
        interface/GraphUI.hpp
        )

add_executable(lab_3.3 ${SOURCE_FILES})

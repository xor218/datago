cmake_minimum_required(VERSION 3.21)


project(dataStructAndAlgorithm
    DESCRIPTION "数据结偶和算法"
    LANGUAGES C CXX
)


function(SrcAuto src)
    get_filename_component(fileNoExt ${src} NAME_WE)
    set(exeName ${fileNoExt}.out)
    add_executable(${exeName} ${src})
endfunction()

if(APPLE)
    set(scrs 
    /Users/min122218/xor218/datago/list/c/list_test.c
    )
endif()



if(LINUX)
    set(scrs 
    /home/min122218/xor218/datago/list/c/Qmalloc.c
    )
endif()


foreach(item ${scrs})
    SrcAuto(${item})
    
endforeach()

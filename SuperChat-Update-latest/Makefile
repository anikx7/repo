
all:./bin/SuperChat ./bin/unit_test

COMMON_LIBS=-L${OSPL_HOME}/lib/ \
            -ldcpssacpp \
            -lddskernel \
            -lpthread

CXX_FLAGS=-Wall -O0 -g -std=c++11

FILES_GENERATED_FROM_THE_IDL_BY_IDLPP= ./bin/SuperChatDcps_impl.h ./bin/SuperChat.cpp \
                                     ./bin/SuperChatSplDcps.cpp ./bin/SuperChatDcps.cpp \
                                     ./bin/SuperChatDcps_impl.cpp ./bin/ccpp_SuperChat.h \
                                     ./bin/SuperChatDcps.h ./bin/SuperChat.h ./bin/SuperChatSplDcps.h

${FILES_GENERATED_FROM_THE_IDL_BY_IDLPP}:./idl/SuperChat.idl
	idlpp -I ${OSPL_HOME}/etc/idl -l cpp ./idl/SuperChat.idl -d ./bin

SRC_FILES= src/DDSEntityManager.cpp src/CheckStatus.cpp src/nicks.cpp

bin/SuperChat: ${FILES_GENERATED_FROM_THE_IDL_BY_IDLPP} ./src/SuperChat.cpp ${SRC_FILES}
	g++ ${CXX_FLAGS} -o ./bin/SuperChat ./src/SuperChat.cpp \
               -I./src/ -I./include -I./bin \
               -I/usr/local/include -I/usr/local/include/FL/images -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT \
               -I${OSPL_HOME}/include/dcps/C++/SACPP/ \
               ${SRC_FILES} \
               ${FILES_GENERATED_FROM_THE_IDL_BY_IDLPP} \
               ${COMMON_LIBS} \
                -L/usr/local/lib -lfltk -lXfixes -lXext -lpthread -ldl -lm -lX11\
               -lncurses

bin/unit_test: ./src/unit_test.cpp ./src/nicks.h ./src/nicks.cpp
	g++ ${CXX_FLAGS} \
               -I./src/ -o bin/unit_test ./src/unit_test.cpp ./src/nicks.cpp \
              -lboost_unit_test_framework

clean:
	-rm -f ./bin/SuperChat ${FILES_GENERATED_FROM_THE_IDL_BY_IDLPP} bin/unit_test

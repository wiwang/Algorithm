CURR_DIR := $(shell pwd)
SRC_HOME := $(CURR_DIR)/../

#include $(SRC_HOME)/make.common

EXE = queue
OBJS = queue.o

ALLOWED_INCLUDE_PATH := -I.

$(EXE) : $(OBJS)
	$(CC) -o $@ $(OBJS)

# Makefile

# 编译器和通用选项
CXX = g++
CXXFLAGS_COMMON = -std=c++17 -Wall

# 第三方库, 使用fmt库(header only)
LDFLAGS = -lpthread
CPPFLAGS = -I ../external/fmt/include
# LDFLAGS = -L/path/to/libexample/ -lexample
# CPPFLAGS = -I/path/to/libexample/include

# 默认编译模式为 debug
BUILD_TYPE ?= debug

TARGETDIR = bin

ifeq ($(BUILD_TYPE), debug)
    CXXFLAGS = $(CXXFLAGS_COMMON) -Wextra -Wpedantic -Wconversion -O0 -g
    OBJDIR = obj/debug
		TARGETDIR = bin/debug
    TARGET = $(TARGETDIR)/main
else
    CXXFLAGS = $(CXXFLAGS_COMMON) -O3
    OBJDIR = obj/release
		TARGETDIR = bin/release
    TARGET = $(TARGETDIR)/main
endif

# 源文件
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))

# 设置默认目标
.DEFAULT_GOAL = all

all: $(OBJDIR) $(TARGETDIR) $(TARGET)

d:
	make all BUILD_TYPE=debug

r:
	make all BUILD_TYPE=release

al: d r

# 生成可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# 生成目标文件
$(OBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

# 确保目标文件夹和bin文件夹存在
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(TARGETDIR):
	mkdir -p $(TARGETDIR)

# 清理生成的文件
clean:
	rm -rf obj bin main

# 声明伪目标
.PHONY: all clean d r al

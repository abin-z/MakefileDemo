# MakefileDemo
### 一个用于简单项目的Makefile的模板
根目录下的Makefile.bak是一个基本Makefile模板, 适用于简单的Demo代码

- Makefile简单通用, 非常适合demo代码
- 支持debug和release模式
- 有单独文件夹保存.o文件和可执行文件
- 可以根据模板进行自定义或改进

**基本使用步骤** 
1. 新建一个文件夹, 例如`hello_demo`.
2. 将`Makefile.bak`复制到新建文件夹(hello_demo)中, 并删除`.bak`后缀.
3. 新建一个`main.cpp`文件, 写打印hello的代码.
    ```cpp
    #include <iostream>
    int main(void)
    {
      std::cout << "hello makefile.\n";
    }
    ```
4. 然后当前文件夹`hello_demo/`的命令行中输入`make`, 就会进入构建过程.
    ```sh
    [user@ubuntu hello_demo]$ make 
    mkdir -p obj/debug
    mkdir -p bin/debug
    g++ -std=c++17 -Wall -Wextra -Wpedantic -Wconversion -O0 -g  -o obj/debug/main.o -c main.cpp
    g++ obj/debug/main.o -o bin/debug/main -lpthread
    [user@ubuntu hello_demo]$ 
    ```
5. 可以看到生成了可执行文件main,执行`./bin/debug/main`命令即可运行
    ```sh
    [user@ubuntu hello_demo]$ ./bin/debug/main 
    hello makefile.
    [user@ubuntu hello_demo]$ 
    ```
6. 可以观察现在的目录架构如下:
   ```sh
    [user@ubuntu makefileDemo]$ tree hello_demo/
    hello_demo/
    ├── bin
    │   └── debug
    │       └── main
    ├── main.cpp
    ├── Makefile
    └── obj
        └── debug
            └── main.o

    4 directories, 4 files
    [user@ubuntu hello_demo]$ 
   ```

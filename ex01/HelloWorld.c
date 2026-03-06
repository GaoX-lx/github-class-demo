#include <stdio.h>

int main() {
    printf("Hello World!\n");
    char input_content[100]; // 定义数组存输入内容
    printf("请输入你想显示的内容：");
    scanf("%s", input_content); // 读取键盘输入
    printf("你输入的内容是：%s\n", input_content); // 输出输入内容
    return 0;
}
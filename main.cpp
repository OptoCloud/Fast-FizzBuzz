#include <string>
#include <chrono>
#include <cstring>

char buffer[128];
int bufferPos = 0;

template <typename T>
constexpr unsigned int toString(T num, char* str)
{
    unsigned int i = 0;

    if (num == 0) {
        str[i++] = '0';
        return i;
    }

    unsigned int si = i;
    while (num != 0) {
        T rem = num % 10;
        str[i++] = rem + '0';
        num /= 10;
    }
    unsigned int ei = i - 1;

    while (si != ei && si < ei) {
        std::swap(str[si++], str[ei--]);
    }

    return i;
}

int main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    unsigned int f = 3;
    unsigned int b = 5;
    unsigned int i = 0;

    int match = 0;
    while (match != 3) {
        i++;
        match = (i==f)+((i==b) * 2);

        switch (match) {
        case 0:
            bufferPos += toString(i, buffer + bufferPos);
            buffer[bufferPos++] = '\n';
            continue;
        case 1:
            memcpy(buffer + bufferPos, "Fizz!\n", 6);
            bufferPos += 6;
            f += 3;
            break;
        case 2:
            memcpy(buffer + bufferPos, "Buzz!\n", 6);
            bufferPos += 6;
            b += 5;
            break;
        case 3:
            memcpy(buffer + bufferPos, "FizzBuzz!\n", 10);
            bufferPos += 10;
            break;
        }
    }

    buffer[bufferPos++] = '\0';
    puts(buffer);
    auto end = std::chrono::high_resolution_clock::now();

    printf("Nanoseconds elapsed: %llu\n", std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count());
}

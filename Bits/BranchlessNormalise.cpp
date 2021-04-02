#include <iostream>
#include <chrono>

void printi(unsigned int val) {
    std::cout << val << std::endl;
}

void prints(const char* str) {
    std::cout << str << std::endl;
}

void PrintBinary(long n)
{
    long i;
    // std::cout << "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
        if((n & i) != 0)
        {
            std::cout << "1";
        }
        else
        {
            std::cout << "0";
        }
    }
    std::cout << std::endl;
}

int NormaliseUnsignedInt(unsigned int n) {
   return ((n | (~n + 1)) >> 31) & 1;
}

int BranchlessNormalisedVisual(unsigned int val) {
    prints("Input value:");
    printi(val);
    PrintBinary(val);

    unsigned int stage1 = ~val + 1;
    prints("Stage 1:");
    PrintBinary(stage1);

    unsigned int stage2 = val | stage1;
    prints("Stage 2:");
    PrintBinary(stage2);

    unsigned int stage3 = stage2 >> 31;
    prints("Stage 3:");
    PrintBinary(stage3);

    unsigned int stage4 = stage3 & 1;
    prints("Stage 4:");
    PrintBinary(stage4);

    prints("Output value:");
    return stage4;
}

int ReturnBranched(unsigned int val, int otherThing, int otherOtherThing) {
    if (val > 0) {
        return otherThing;
    } else {
        return otherOtherThing;
    }
}

int ReturnBranchless(unsigned int val, int otherThing, int otherOtherThing) {
    unsigned int which = NormaliseUnsignedInt(val);
    return which * otherThing + (1 - which) * otherOtherThing;
}

int main()
{
    prints("-------------------------------");
    prints("-----------Breakdown-----------");
    prints("-------------------------------");

    int six  = 6;
    int one  = 1;
    int zero = 0;
    int max  = ~0;

    printi(BranchlessNormalisedVisual(six));
    prints("-------------------------------");
    printi(BranchlessNormalisedVisual(one));
    prints("-------------------------------");
    printi(BranchlessNormalisedVisual(zero));
    prints("-------------------------------");
    printi(BranchlessNormalisedVisual(max));

    prints("");
    prints("-------------------------------");
    prints("-------Timing comparison-------");
    prints("-------------------------------");
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 99999999; i++) {
        ReturnBranched(rand() % 2, 100, 50);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto test1 = end - start;

    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 99999999; i++) {
        ReturnBranchless(rand() % 2, 100, 50);
    }
    end = std::chrono::high_resolution_clock::now();
    auto test2 = end - start;

    std::cout << "Method using branches: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(test1).count()
        << "ms" << std::endl;
    std::cout << "Branchless: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(test2).count()
        << "ms" << std::endl;


    return 0;
}

#include "timeArray.h"
#include <vector>

namespace JangJiwon2593266
{
    void printTimeArrayVector(std::vector<timeArray>& vector)
    {
        for (const auto& vi : v)
            vi.printAll();
        std::cout << v.size() << "/" << v.capacity() << std::endl;
    }
}

int main()
{
    using namespace JangJiwon2593266;

    timeArray ta1{3};
    ta1[0] = timeOfDay{1,1};
    ta1[1] = timeOfDay{2,2};
    ta1[2] = timeOfDay{3,3};
    ta1.printAll();

    timeArray ta2; ta2 = ta1;
    ta2.printAll();

    timeArray ta3; ta3 = std::move(ta2);
    ta2.printAll();

    std::vector<timeArray> v;
    printTimeArrayVector(v);
    v.push_back(ta1); printTimeArrayVector(v);
    v.push_back(std::move(ta1)); printTimeArrayVector(v);
    ta1.printAll();
    
    return 0;
}
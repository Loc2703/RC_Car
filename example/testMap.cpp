#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

//uint8_t Map(uint8_t key)
unsigned char Map(unsigned char key)
{
    // map<uint8_t,uint8_t> mp = {{0,0}, {1,14}, {2,28}, {3,42}, {4,56}, {5,70}, {6,84}, {7,100}};
//    uint8_t mp[] = {0,14,28,42,56,70,84,100};
	unsigned char mp[] = {0,14,28,42,56,70,84,100};
    return mp[key];
}

unsigned char Map_(unsigned char key)
{ 
	return (float)key/7*100;
}

int main()
{
    for(int i=0; i<=7; i++)
    {
//        cout << "One " << static_cast<int>(Map(i)) << endl;
        cout << "One " <<Map(i) << endl;
//    	cout << "Two " << static_cast<int>(Map_(i)) << endl;
	}
    return 0;
}

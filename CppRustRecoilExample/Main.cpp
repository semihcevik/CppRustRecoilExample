// Developed by BAKUNIN#0001

#include <Windows.h> // Win32 functions

#include <vector> // allows use of vectors

#include "Util.h" // Include the utility functions

std::vector<vector2> ak47 = { {-35, 50}, {5, 46}, {-55, 42}, {-42, 37}, {0, 33}, {16, 28}, {29, 24}, {38, 19}, {42, 14}, {42, 9}, {38, 9}, {30, 18}, {17, 25}, {0, 29}, {-15, 32}, {-27, 33}, {-37, 32}, {-43, 29}, {-46, 24}, {-45, 17}, {-42, 8}, {-35, 5}, {-24, 14}, {-11, 21}, {12, 25}, {36, 28}, {49, 28}, {49, 26}, {38, 21} };
double ak47_baseDelay = 60000 / 450; // converting round per minute to milliseconds (RPM can be found https://rust.gamepedia.com/Assault_Rifle)

int main()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_RBUTTON) & 0x8000) // this checks to see if the player is scoping. This will start to work the cpu because its running in a fast loop this can be altered ** 
		{
			for (int i = 0; i < ak47.size() && GetAsyncKeyState(VK_LBUTTON) & 0x8000; i++) // loop through the recoil table size of AK47
			{
				Util::simple_smooth(ak47[i].x, ak47[i].y, ak47_baseDelay);
			}

			//Sleep(1); ** Remove the comment to rest CPU while scoped
		}
		Sleep(1); // cpu usage
	}

	return EXIT_SUCCESS;
}

// Keep in mind this is only for ak47 and it is extremely basic and can be improved and edited in numerous ways. 
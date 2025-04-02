#include <iostream>
#include <cstring>
using namespace std;

class Girl;

class Boy
{
private:
	int height;
	friend class Girl;
public:
	Boy(int len) : height(len) {}
	void ShowYourFriendInfo(Girl& frn);
};

class Girl
{
private:
	char phName[20];
public:
	Girl(char* name)
	{
		strcpy_s(phName, 20, name);
	}
	void ShowYourFriendInfo(Boy& frn);
	friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl& frn)
{
	cout << "Her Phone Number : " << frn.phName << endl;
}

void Girl::ShowYourFriendInfo(Boy& frn)
{
	cout << "His Height : " << frn.height << endl;
}

int main(void)
{
	Boy boy(170);
	Girl girl((char*)"010-1234-5678");

	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);

	return 0;
}

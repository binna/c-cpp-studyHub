#ifndef __POINT_H_
#define __POINT_H_

class Point
{
private:
	int x;
	int y;
public:
	//bool InitMembers(int xpos, int ypos);
	Point(const int& xops, const int& ypos);
	
	int GetX() const;
	int GetY() const;
	bool SetX(int xpos);
	bool SetY(int ypos);
};
#endif
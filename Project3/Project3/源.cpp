#include<iostream>


using namespace std;





class stackonly
{
public:

	static stackonly getobject()
	{
		return stackonly();
	}
private:
	stackonly()
	{

	}

};
int main()
{

	stackonly::getobject();
	stackonly s = stackonly::getobject();
	stackonly p(stackonly::getobject());
	return 0;
}
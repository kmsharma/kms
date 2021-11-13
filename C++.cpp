#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class AutoPtr
{
	T* mptr;
public :
	AutoPtr()
	{
		mptr = nullptr;
	}

	AutoPtr(T* ptr) : mptr(ptr)
	{}


	//with deep copy 
	AutoPtr(AutoPtr& obj)
	{
		cout << "copy constr..." << endl;
		mptr = new T;
		*mptr = *obj.mptr;
	}

	//deep copy assignment operator
	AutoPtr& operator=(AutoPtr& obj)
	{
		cout << "assignment operator..." << endl;

		if (mptr)
			delete mptr;

		mptr = new T;
		*mptr = *obj.mptr;
		return *this;
	}


	////copy constructor doing move
	//AutoPtr(AutoPtr& obj)
	//{
	//	mptr = obj.mptr;
	//	obj.mptr = nullptr;
	//}

	////assignment operator doing move
	//AutoPtr& operator=(AutoPtr& obj)
	//{
	//	if (mptr)
	//		delete mptr;
	//	mptr = obj.mptr;
	//	obj.mptr = nullptr;
	//	return *this;
	//}


	//move constructor
	AutoPtr(AutoPtr&& obj) noexcept
	{
		cout << "move constr..." << endl;

		mptr = obj.mptr;
		obj.mptr = nullptr;
	}

	//move assignment
	AutoPtr& operator=(AutoPtr&& obj) noexcept
	{
		cout << "move assignment..." << endl;

		if (mptr == obj.mptr)
			return *this;

		if (mptr)
			delete mptr;

		mptr = obj.mptr;
		obj.mptr = nullptr;
		return *this;
	}


	//move assignment operator


	T& operator*()
	{
		return *mptr;
	}

	T* operator->()
	{
		return mptr;
	}

	~AutoPtr()
	{
		delete mptr;
	}
};


class Res
{
public :
	Res()
	{
		cout << "Res acquired." << endl;
	}

	~Res()
	{
		cout << "Res destroyed." << endl;
	}
};

int main()
{
	AutoPtr<Res> ptr1(new Res());	

	AutoPtr<Res> ptr2(ptr1);	//copy constructor

	AutoPtr<Res> ptr3;
	ptr3 = ptr1;			//assignment operator

	AutoPtr<Res> ptr4 = std::move(ptr1);	//move contr.

	AutoPtr<Res> ptr5;
	ptr5 = std::move(ptr4);			//move assignment

	return 0;
}
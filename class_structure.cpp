#include <stdio.h>
#include <assert.h>
#include <iostream>

class C_Base {
	public:
		C_Base() {}
		virtual ~C_Base(){}
		virtual void fun(){std::cout << "Class Base do...\n"; }
	protected:
		char name[8];
};

class C_Drivide :public C_Base {
	public:
		C_Drivide(){}
		virtual ~C_Drivide(){}
		virtual void fun(){std::cout << __FUNCTION__<<"\n"; }
		virtual void own_fun(){std::cout << __FUNCTION__ << "\n"; }
	protected:
	private:
		char my_name[8];
};


struct S_Base {
	public:
		S_Base() {}
		virtual ~S_Base(){}

		virtual void fun(){std::cout << "Struct Base do...\n"; }
	protected:
		char name[8];
};

struct S_Drivide : public S_Base{
	public:
		S_Drivide(){}
		virtual ~S_Drivide(){}
		virtual void fun(){std::cout << __FUNCTION__ << "\n"; }
		virtual void own_fun(){std::cout << __FUNCTION__ << std::endl; }
	private:
		char my_name[8];
};

void cast_test() {
	std::cout << "...comming soon...\n";
}

void inherit_test() {

	std::cout << "************************** part 1 ************************\n";
	C_Base cb;
	C_Drivide cd;
	S_Base sb;
	S_Drivide sd;
	printf("C_Base : %d\nC_Drivide : %d\nS_Base : %d\nS_Drivide : %d\n",
			sizeof(cb),sizeof(cd),sizeof(sb),sizeof(sd));
	cd.fun();
	sd.fun();

	std::cout << "************************** part 2 ************************\n";
	C_Drivide *cd_ptr = new C_Drivide;
	C_Base *cb_ptr = cd_ptr;
	S_Drivide *sd_ptr = new S_Drivide;
	S_Base *sb_ptr = sd_ptr;
	printf("C_Drivide : %d\nS_Drivide : %d\n",
			sizeof(*cd_ptr),sizeof(*sd_ptr));
	cd_ptr->fun();
	sd_ptr->fun();

	static_cast<C_Drivide*>(cb_ptr)->own_fun();
	assert(dynamic_cast<C_Drivide*>(cb_ptr));
	//assert(dynamic_cast<S_Drivide*>(cb_ptr));		// using dynamic_cast<> to prejudge cast OK or not, if not, cb_ptr == NULL
	dynamic_cast<C_Drivide*>(cb_ptr)->own_fun();
	((S_Drivide*)sb_ptr)->own_fun();							// to improve cast forcly is ok in structure inherit
	dynamic_cast<S_Drivide*>(sb_ptr)->own_fun();	 

}

int main (int ac, char ** av) {
	inherit_test();
	cast_test();
}

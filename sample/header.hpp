class Base{
	public:
		virtual int hello();
		virtual double goodbye() = 0;
};

class MyClass : public Base
{
	public:
		int field;
		virtual void method() const = 0;

		static const int static_field;
		static int static_method();
		virtual double goodbye();
	private:
		int field2;
};

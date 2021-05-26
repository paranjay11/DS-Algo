#include <bits/stdc++.h>
using namespace std;

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

class Product{
public:
	virtual ~Product(){};// we need to implement virtual destructor in the base class
	                     // and we need to define it too , otherwise it will throw 
	                     // undefined reference
	virtual string DoSomething()=0;
};

class concreteProduct1:public Product{
public:
	string DoSomething(){
		return "SOMETHING IS DONE BY CONCRETE PRODUCT 1";
	}
};

class concreteProduct2:public Product{
public:
	string DoSomething(){
		return "SOMETHING IS DONE BY CONCRETE PRODUCT 2";
	}
};

/**
 * The Creator class declares the factory method that is supposed to return an
 * object of a Product class. The Creator's subclasses usually provide the
 * implementation of this method.
 */

class Creator{
public:
	virtual ~Creator(){};// we need to implement virtual destructor in the base class
	                     // and we need to define it too , otherwise it will throw 
	                     // undefined reference
	virtual Product *FactoryMethod(int)=0;
	/**
   * Also note that, despite its name, the Creator's primary responsibility is
   * not creating products. Usually, it contains some core business logic that
   * relies on Product objects, returned by the factory method. Subclasses can
   * indirectly change that business logic by overriding the factory method and
   * returning a different type of product from it.
   */
	string someOperation(int k){
		Product* prod=this->FactoryMethod(k);
		string str="Crater has to implement : "+prod->DoSomething();
		delete prod; // we free the allocated memory because we dont need to use it after
		             // the scope ends
		return str;
	}	
};

/**
 * Concrete Creators override the factory method in order to change the
 * resulting product's type.
 */

class ConcreteCreator:public Creator{
public:

	/**
   * Note that the signature of the method still uses the abstract product type,
   * even though the concrete product is actually returned from the method. This
   * way the Creator can stay independent of concrete product classes.
   */
	Product *FactoryMethod(int k){
		switch(k){
			case 1: return new concreteProduct1();
			case 2: return new concreteProduct2();
			default: return new concreteProduct1();
		}
	}
};

int32_t main(){
	c_p_c();

	Creator *k=new ConcreteCreator();
	cout<<k->someOperation(2);

	return 0;
}
#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "------------Test with MutantStack------------" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	std::cout << "------------Test with std::list------------" << std::endl;

	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);
	std::list<int>::iterator itBeg = mlist.begin();
	std::list<int>::iterator itEnd = mlist.end();
	++itBeg;
	--itBeg;
	while (itBeg != itEnd)
	{
		std::cout << *itBeg << std::endl;
		++itBeg;
	}
	std::list<int> l(mlist);
	return 0;
return 0;
}

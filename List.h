#pragma once
#include"NODE.h"
#include"Ticket.h"


using ptrNODE = NODE*;

class List
{
private:
	ptrNODE head;
	
public:
	List() {};
	List(std::ifstream& file);
	ptrNODE get_head() const
	{
		return head;
	}
	void add_by_ptr(ptrNODE&ptr, TInfo elem);
	void add_to_head(TInfo elem);
	void add_to_tail(TInfo elem);
	void del_by_ptr(ptrNODE& ptr);
	void del_from_head();
	void print(std::ostream& stream = std::cout,const char* message="") const ;
	bool empty();
	void clear();
	~List()
	{
		clear();
	}

	List(const List& other);
	List& operator=(const List&other);
	List(List&& tmp);
	List& operator=(List&& tmp);


};
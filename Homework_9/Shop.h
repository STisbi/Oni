#ifndef _SHOP_H
#define _SHOP_H

#include <vector>
#include <string>

#include "Model.h"
#include "Component.h"
#include "Customer.h"

class Shop
{
	private:
		std::vector<Model> vModel;
		std::vector<Component> vComponent;
		std::vector<Customer> vCustomer;

	public:
		Shop();
		void mCreate_Model();
		void mCreate_Component();
		void mList_Models();
		void mList_Components();
		void mAdd_Customer();
		void mList_Customers();
};

#endif


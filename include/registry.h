#pragma once

#include <vector>
#include "exception"

template<typename T1, typename T2>
class Registry
{
	template<class K, class V>
	struct Pair
	{
		K _key;
		V _value;
	};
private:
	std::vector<Pair<T1, T2>> _registry;
public:
	Registry() = default;

	Registry(const T1& key, const T2& value)
	{
		add(key, value);
	}

	void add(const T1& key, const T2& value)
	{
		Pair<T1, T2> pair;
		pair._key = key;
		pair._value = value;
		_registry.push_back(pair);
	}

	void print()
	{

		for (int i = 0; i < this->_registry.size(); i++)
		{
			std::cout << "Key: " << this->_registry[i]._key
					  << " value: " << this->_registry[i]._value;
			std::cout << std::endl;
		}
	}
};
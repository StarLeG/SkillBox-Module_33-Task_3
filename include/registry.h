#pragma once

#include <vector>
#include "exception"


template<class T1, class T2>
class Registry
{
	template<class K,class V>
	struct Pair
	{
		K _key;
		V _value;
	};

private:
	std::vector<Pair<T1,T2>> _registry;
public:
	Registry() = default;

	Registry(const T1& key, const T2& value)
	{
		add(key,value);
	}
	~Registry() = default;

	void add(const T1& key, const T2& value)
	{
		Pair<T1,T2> pair;
		pair._key = key;
		pair._value = value;
		_registry.emplace_back(pair);
	}

	void print(int index = -2)
	{
		if(index == -2)
		{
			for(int i = 0;i < _registry.size();i++)
			{
				std::cout << _registry[i]._key;
				std::cout << " = ";
				std::cout <<  _registry[i]._value;
				std::cout << std::endl;
			}
			return;
		}

		if (index == -1)
		{
			std::cout << "This key  is missing" << std::endl;
			return;
		}

		if(index > 0 && index < _registry.size())
		{
			std::cout << "Find OK\n";
			std::cout << _registry[index]._key << " = " << _registry[index]._value << std::endl;
			return;
		}

		if(index < -2 || index > _registry.size())
		{
			throw std::invalid_argument("Index");
		}



	}

	int find(const T1& key)
	{
		int index = -1;
		for(int  i = 0; i < _registry.size();i++)
		{
			if(key == _registry[i]._key)
			{
				index = i;
				break;
			}
		}
		return index;
	}

	void remove(const T1& key)
	{
		int index = find(key);
		_registry.erase(_registry.begin() + index);
		std::cout << "Remove OK" << std::endl;
	}
};


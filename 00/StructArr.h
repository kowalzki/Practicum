#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "StructArr.h"

inline bool equalStr(std::string s1, std::string s2)
{
	int i;
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i]) return false;
	}
	if (s1[i] != s2[i]) return false;
	return true;
}

inline int lenInt(int a)
{
	int i = 0;
	do
	{
		a /= 10;
		i++;
	} while (a);
	return i;
}

inline unsigned int lenOfStr(std::string s)
{
	int i = 0;
	for (i; s[i] != '\0'; i++);
	return i;
}

inline bool strEqual(std::string s1, std::string s2)
{
	int i;
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i]) return false;
	}
	if (s1[i] != s2[i]) return false;
	return true;
}

inline std::string addSpace(std::string s, unsigned int setw)
{
	std::string ss = s;
	for (unsigned int i = lenOfStr(s); i < setw; i++)
	{
		ss += ' ';
	}
	return ss;
}

inline unsigned int strToInt(std::string s)
{
	int t = 0;
	for (int i = 0; s[i] != ' ' && s[i] != '\0'; i++)
	{
		t *= 10;
		t += (int)s[i] - 48;
	}
	return t;
}

struct structarr
{
	std::string structName;
	unsigned len;
	unsigned int id;
	std::string* titles;
	std::string* data;
	unsigned int* sizes;

	structarr(std::string cnfg)
	{
		set(cnfg);
	}

	structarr()
	{
		set_empty();
	}

	void set(std::string cnfg)
	{
		if (cnfg.empty())
		{
			set_empty();
			return;
		}
		structName = cnfg;
		std::ifstream ifs;
		ifs.open("C:\\Temp\\Pract\\_config.txt");
		std::string name;
		unsigned int len_t;
		do
		{
			ifs >> name >> len_t;
			if (equalStr(name, cnfg))
			{
				len = len_t;
				titles = new std::string[len];
				sizes = new unsigned int[len];
				data = new std::string[len];
				for (unsigned int i = 0; i < len; i++)
				{
					ifs >> titles[i];
				}
				for (unsigned int i = 0; i < len; i++)
				{
					ifs >> sizes[i];
					if (!sizes[i])
					{
						sizes[i] = lenOfStr(titles[i]);
					}
				}
				return;
			}
			else
			{
				std::string trash;
				for (unsigned int i = 0; i < len_t; i++)
				{
					ifs >> trash;
				}
				for (unsigned int i = 0; i < len_t; i++)
				{
					ifs >> trash;
				}
			}
		} while (ifs.peek() != EOF);
		ifs.close();
	}

	void set_empty()
	{
		structName = "";
		len = 0;
		id = 0;
		titles = nullptr;
		data = nullptr;
		sizes = nullptr;
	}

	~structarr()
	{
		if (titles) delete[] titles;
		if (data) delete[] data;
		if (sizes) delete[] sizes;
	}

	void showTitles()
	{
		for (unsigned int i = 0; i < len; i++)
		{
			std::cout << std::left << std::setw(sizes[i] + 2) << titles[i];
		}
	}

	void request()
	{
		std::cout << "Введите данные:\n";
		std::cin.ignore();
		for (unsigned int i = 0; i < len; i++)
		{
			std::cout << titles[i] << ":  ";
			std::getline(std::cin, data[i]);
			while (lenOfStr(data[i]) > sizes[i])
			{
				std::cout << "Лимит строки - " << sizes[i] << " символов, попробуйте ещё раз:\n";
				std::getline(std::cin, data[i]);
			}
		}
	}

	void show()
	{
		for (unsigned int i = 0; i < len; i++)
		{
			std::cout << std::left << std::setw(sizes[i] + 2) << data[i];
		}
	}

	bool read(std::ifstream* ifs)
	{
		if (!ifs) return false;
		if (ifs->peek() == EOF) return false;
		*ifs >> id;
		for (unsigned int i = 0; i < len; i++)
		{
			data[i] = "";
			read(ifs, &(data[i]), sizes[i] + 2, !i);
		}
		if (ifs->good())
			return true;
		return false;
	}

	void read(std::ifstream* ifs, std::string* target, unsigned int size, bool afterId)
	{
		if (afterId)
		{
			for (int i = 0; i < 5 - lenInt(id); i++)
			{
				ifs->get();
			}
		}
		for (int i = 0; i < size; i++)
		{
			*target += ifs->get();
		}
	}

	bool write(std::ofstream* ofs)
	{
		if (!ofs) return false;
		*ofs << std::left << std::setw(5) << id;
		for (int i = 0; i < len; i++)
		{
			*ofs << std::left << std::setw(sizes[i] + 2) << data[i];
		}
		if (ofs->good()) return true;
		return false;
	}
};
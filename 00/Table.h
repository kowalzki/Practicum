#pragma once
#include <string>
#include <fstream>
#include <iomanip>
#include "StructArr.h"

class table
{
public:
	std::string filename;
	std::string structname;

	table(std::string sn)
	{
		filename = makeFullWay(sn);
		structname = sn;
	}

	std::string makeFullWay(std::string sn)
	{
		return "C:\\Temp\\Pract\\" + sn + ".txt";
	}

	void addLine()
	{
		structarr line(structname);
		line.id = lastId() + 1;
		std::ofstream ofs;
		ofs.open(filename, std::ios_base::app);
		line.request();
		ofs << std::endl;
		line.write(&ofs);
		ofs.close();
	}

	void show()
	{
		if (!lastId())
		{
			std::cout << "\n   < Таблица пуста >\n\n";
			return;
		}
		std::ifstream ifs;
		ifs.open(filename);
		structarr line(structname);
		//std::cout << std::left << std::setw(5) << "ID";
		line.showTitles();
		std::cout << std::endl;
		while (line.read(&ifs))
		{
			//std::cout << std::left << std::setw(5) << line.id;
			line.show();
			std::cout << std::endl;
		}
		ifs.close();
	}

	void skipLine(std::ifstream* pifs)
	{
		structarr t(structname);
		std::string s;
		for (unsigned int i = 0; i < t.len; i++)
		{
			t.read(pifs, &s, t.sizes[i] + 2, !i);
		}
	}

	unsigned int lastId()
	{
		std::ifstream ifs;
		ifs.open(filename);
		int id = 0;
		if (ifs.peek() == EOF)
		{
			return id;
		}
		while (ifs)
		{
			ifs >> id;
			skipLine(&ifs);
			std::string trash;
		}
		ifs.close();
		return id;
	}

	void request(std::string* field, std::string* struct_name, unsigned int len,
		std::string filter_m_field = "", std::string filter_target = "", std::string filter_o_struct = "", std::string filter_o_field = "")
	{
		unsigned int lid = lastId();
		std::ifstream mifs;
		std::ifstream* ifs = new std::ifstream[len];
		mifs.open(filename);
		for (unsigned int j = 0; j < len; j++)
		{
			ifs[j].open(makeFullWay(struct_name[j]));
		}
		structarr mstr(structname);
		structarr* str = new structarr[len];
		for (unsigned int i = 0; i < len; i++)
		{
			str[i].set(struct_name[i]);
		}
		unsigned int* strId_i = new unsigned int[len];
		for (unsigned int j = 0; j < len; j++)
		{
			for (int i = 0; i < mstr.len; i++)
			{
				if (mstr.titles[i] == field[j])
				{
					strId_i[j] = i;
					break;
				}
			}
		}
		unsigned int filter_m_field_i = 0;
		unsigned int filter_o_field_i = 0;
		structarr ostr(filter_o_struct);
		if (!filter_m_field.empty())
		{
			for (unsigned int i = 0; i < mstr.len; i++)
			{
				if (mstr.titles[i] == filter_m_field)
				{
					filter_m_field_i = i;
					break;
				}
			}
		}
		if (!filter_o_field.empty())
		{
			for (unsigned int i = 0; i < ostr.len; i++)
			{
				if (ostr.titles[i] == filter_o_field)
				{
					filter_o_field_i = i;
					break;
				}
			}
		}
		if (!filter_o_field.empty())
		{
			filter_target = addSpace(filter_target, ostr.sizes[filter_o_field_i] + 2);
		}
		else if (!filter_m_field.empty())
		{
			filter_target = addSpace(filter_target, mstr.sizes[filter_m_field_i] + 2);
		}

		std::cout << "Структура отображения данных:\n\n";
		mstr.showTitles();
		std::cout << std::endl;
		for (unsigned int j = 0; j < len; j++)
		{
			str[j].showTitles();
			std::cout << std::endl;
		}
		std::cout << "\n\n\n";
		bool oneShowed = false;
		do
		{
			mstr.read(&mifs);
			for (unsigned int j = 0; j < len; j++)
			{
				while (ifs[j])
				{
					str[j].read(&ifs[j]);
					if (str[j].id == strToInt(mstr.data[strId_i[j]]))
					{
						break;
					}
				}
			}
			bool filterFlag = false;
			if (!filter_o_field.empty())
			{
				for (unsigned int j = 0; j < len; j++)
				{
					if (filter_o_struct == struct_name[j] && filter_target == str[j].data[filter_o_field_i])
					{
						filterFlag = true;
					}
				}
			}
			else if (!filter_m_field.empty() && filter_target == mstr.data[filter_m_field_i])
			{
				filterFlag = true;
			}
			else if (filter_m_field.empty())
			{
				filterFlag = true;
			}
			if (filterFlag)
			{
				mstr.show();
				for (unsigned int j = 0; j < len; j++)
				{
					std::cout << std::endl;
					str[j].show();
				}
				std::cout << "\n\n\n";
				oneShowed = true;
			}
			for (unsigned int j = 0; j < len; j++)
			{
				ifs[j].clear();
				ifs[j].seekg(0, std::ios::beg);
			}
		} while (mstr.id < lid);

		if (!oneShowed)
		{
			std::cout << "\n        < Ни одной записи, удовлетворяющей фильтру, не найдено >\n\n\n\n";
		}

		mifs.close();
		for (unsigned int j = 0; j < len; j++)
		{
			ifs[j].close();
		}
		delete[] ifs;
		delete[] strId_i;
		delete[] str;
	}
};
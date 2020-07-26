#include<memory>
#include<string>
#include<vector>
#include<iostream>

constexpr int size = 10;

class Widget
{
private:
	std::unique_ptr<int> data;
public:
	Widget(const int size) { data = std::make_unique<int>(size);  }

	void do_something() {}
};

void functionUsingWidget()
{
	Widget w(100000);

	w.do_something();
}

void string_string()
{
	std::string myString("");

	myString = myString + std::to_string(0.0f) + " " + std::to_string(10);
}

struct Song
{
	std::string artist;
	std::string title;

	Song(std::string a, std::string t) : artist(a), title(t){ };
};

void SongVector()
{
	std::vector<std::unique_ptr<Song>> songs;

	songs.push_back(std::make_unique<Song>("B'z", "Juice"));
	songs.push_back(std::make_unique<Song>("Namie Amuro", "Funky Town"));
	songs.push_back(std::make_unique<Song>("Kome Kome Club", "Kimi ga Iru Dake de"));
	songs.push_back(std::make_unique<Song>("Ayumi Hamasaki", "Poker Face"));

	for (const auto& song : songs)
	{
		std::cout << "Artist : " << song->artist << " Title : " << song->title << std::endl;
	}

}

void VectorAssign()
{
	std::vector<int> v1, v2, v3;

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	std::cout << "v1 = ";
	for (auto& v : v1)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	v2.assign(v1.begin(), v1.end());
	std::cout << "v2 = ";
	for (auto& v : v2)
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;

	v3.assign(7, 4);

	int size = int(v3.size());

	v3.assign({ 5, 6, 7 });

	size = int(v3.size());
}

void LambdaExpression()
{
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	int x = 2;
	int y = 7;
	auto result = find_if(std::begin(v), std::end(v), [=](int i) { return i > x && i < y;  });
}
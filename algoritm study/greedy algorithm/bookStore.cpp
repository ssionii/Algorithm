#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Book {
	int price;
	int point;
public:

	Book() {}

	Book(int price, int point) {
		this->price = price;
		this->point = point;
	}

	int getPrice() {
		return price;
	}
	int getPoint() {
		return point;
	}
};

bool compare(Book a, Book b) {
	if (a.getPoint() == b.getPoint()) {
		return a.getPrice() > b.getPrice();
	} else {
		return a.getPoint() > b.getPoint();
	}
}

class Store {
	vector <Book> list;
public:
	Store() {}
	void addBook(Book book) {
		list.push_back(book);
	}

	int totalPrice() {
		sort(list.begin(), list.end(), compare);

		int total = 0, cur_point = 0;
		for (int i = 0; i < list.size(); i++) {
			if (i == 0) {
				total += list.at(i).getPrice();
				cur_point += list.at(i).getPoint();
			}
			else {
				if (list.at(i).getPrice() - cur_point > 0) {
					total += list.at(i).getPrice() - cur_point;
					cur_point = list.at(i).getPoint();
				}
				else {
					cur_point += list.at(i).getPoint() - list.at(i).getPrice();
				}
			}
		}

		return total;
	}
};

int main()
{
	int test_case;
	cin >> test_case;
	
	for (int i = 0; i < test_case; i++) {
		int book_num, store_num;
		cin >> book_num >> store_num;

		Store *stores = new Store[store_num];

		int price, point;
		for (int j = 0; j < book_num; j++) {
			for (int k = 0; k < store_num; k++) {
				cin >> price >> point;
				stores[k].addBook(Book(price, point));
			}
		}

		int result = stores[0].totalPrice();
		for (int j = 1; j < store_num; j++) {
			if(result > stores[j].totalPrice())
				result = stores[j].totalPrice();
		}

		cout << result << endl;
			
	}

	return 0;
}
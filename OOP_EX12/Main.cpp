#include "People.cpp"
#include "Family.cpp"
#include "Group.cpp"
int main()
{
    People *a[4];                                 // tạo thông tin cho 4 người
    a[0] = new People("A", 20, "Dev", "1001");    // người thứ 1 có tên A,20t, Nghề: Dev , id : 1001
    a[1] = new People("B", 21, "Doctor", "1002"); // tương tự
    a[2] = new People("C", 10, "Unemplyed", "1003");
    a[3] = new People("D", 30, "Singer", "1004");
    vector<People *> p; // khởi tạo vector để luu thông tin của từng người
    for (auto x : a)
        p.push_back(x);
    for (auto x : p)
    { // xuất thông tin của từng người đó ra
        cout << "\t =======***=======\t\n";
        x->display();
        cout << "\n\t =======***=======\t\n";
    }
    // Tạo thông tin của ~ thành viên trong gia đình thứ nhất
    People x1("A1", 25, "Di", "1005");
    People y1("B1", 24, "Gay", "1006");
    People z1("C1", 8, "Unemployed", "1007");
    People t1("D1", 35, "Bitch", "1008");
    vector<People> p1;
    p1.push_back(x1);
    p1.push_back(y1);
    p1.push_back(z1); 
    p1.push_back(t1);
    Family f1("Giadinh1", "poor", "Vinh Dien", p1);
    // Tạo thông tin của ~ thành viên trong gia đình  thứ hai
    People x2("A2", 25, "Unemployed", "1005");
    People y2("B2", 24, "Doctor", "1006");
    People z2("C2", 8, "Unemployed", "1007");
    People t2("D2", 35, "Singer", "1008");
    vector<People> p2;
    p2.push_back(x2);
    p2.push_back(y2);
    p2.push_back(z2);
    p2.push_back(t2);
    Family f2("Giadinh2", "poor", "Dien An", p2);
    // tạo vector chứa các thông tin của từng gia đình
    vector<Family> familys;
    familys.push_back(f1);
    familys.push_back(f2);
    for (auto x : familys)
    { // test cho vui , xuất thông tin của từng gia đình đó ra
        cout << endl;
        fflush(stdin);
        x.display();
        cout << "\n\t =======***=======\t\n";
        fflush(stdin);
    }
    // Khởi tạo Group khu phố 1 là địa chỉ của các hộ gia đình đó
	Group gr("Khu pho 1", familys);
	// Tạo vector chứa thông tin những người Thất nghiệp ( Unemployed ) trong Gruop Khu phố 1
	vector<People > people(Group::getPeopleHaveNotJob(gr)); 
	cout << "Number people don't have job: " << people.size() << endl<<endl;
	for (auto x : Group::getPeopleHaveNotJob(gr)) { // Xuất thông tin của những người đó ra
		x.display();
		cout << "****" << endl;
	}
	for (int i = 0; i < people.size(); i++)  // bắt đầu xuất thông tin xuất thân của từng người thất nghiệp
	{
		// familys.size(): sl các gia đình
		// p.size() hoặc getP().size(): sl các thành viên trong gđ
		people[i].display();// in ra thông tin người thứ i+1 , cứ hiểu i = 0 thì in ra người thứ nhất , ai lại bảo in ra người thứ 0 ))
		for (int j = 0; j < familys.size(); j++)// chạy tới khi quét hết số lượng các gia đình để truy xuất thông tin của người đó
		{
			vector<People >P(familys[j].getP()); // lưu thông tin người thứ j+1 của gia đình đó vao vector P
			for (int k = 0; k < P.size(); k++)// chạy tới khi quét hết số lượng các thành viên trong gđ đó
			{  // nếu thông tin của người thứ j giống với thông tin của người thứ k+1 trong gia đình nào đó thì xuất thông tin gia đình đó
				if (P[k].getAge() == people[i].getAge() and P[k].getName() == people[i].getName() and P[k].getId() == people[i].getId())
				{   // nếu đã tìm thấy thì
					cout << "Con cua chu ho: " << familys[j].getNameF() << endl;
					cout << "Dia chi cua chu ho: " << familys[j].getAdd() << endl;
					cout << "\n ======***=======\t\n";
				}
			} // tiếp tục lặp lại với các gia đình tiếp theo
		}
		// tiếp tục truy xuất thông tin của người thất nghiệp kế tiếp
	}
	return 0;
}
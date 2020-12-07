#include "Invigilator.h"

Invigilator::Invigilator(string a,string b) {
	name = a;
	Invigilatornumber = b;
	Invigilatorwithtxt = "Invigilator" + b + ".txt";

	ifstream file(Invigilatorwithtxt);
	
	if (b == "1" || b == "2" || b == "4") {
		file.seekg(9, ios::cur);
   }
	
	if (b == "3" || b == "6") {
		file.seekg(8, ios::cur);
	}

	if (b == "5") {
		file.seekg(10, ios::cur);
	}

	

	int  i = 0, counter = 0;
	for (int z = 0; z < 1;) {

		for (; i < 5; i++) {
			file.seekg(1, ios::cur);
			file.get(mo[i]);

			if (mo[i] < 49 || mo[i] > 53) {
				counter++;
				break;
			};


		};

		if (counter > 0) {
			mo[i] = '0';
			counter = 0;
			file.seekg(-1, ios::cur);
			i++;
		}
		else
			break;
	};





	if (mo[4] == '0') {
		file.seekg(2, ios::cur);
	}
	else {
		file.seekg(3, ios::cur);
	}

	int  i1 = 0, counter1 = 0;
	for (int z = 0; z < 1;) {

		for (; i1 < 5; i1++) {
			file.seekg(1, ios::cur);
			file.get(tu[i1]);

			if (tu[i1] < 49 || tu[i1] > 53) {
				counter1++;
				break;
			};


		};

		if (counter1 > 0) {
			tu[i1] = '0';
			counter1 = 0;
			file.seekg(-1, ios::cur);
			i1++;
		}
		else
			break;
	};





	if (tu[4] == '0') {
		file.seekg(2, ios::cur);
	}
	else {
		file.seekg(3, ios::cur);
	}

	int  i2 = 0, counter2 = 0;
	for (int z = 0; z < 1;) {

		for (; i2 < 5; i2++) {
			file.seekg(1, ios::cur);
			file.get(we[i2]);

			if (we[i2] < 49 || we[i2] > 53) {
				counter2++;
				break;
			};


		};

		if (counter2 > 0) {
			we[i2] = '0';
			counter2 = 0;
			file.seekg(-1, ios::cur);
			i2++;
		}
		else
			break;
	};






	if (we[4] == '0') {
		file.seekg(2, ios::cur);
	}
	else {
		file.seekg(3, ios::cur);
	}

	int  i3 = 0, counter3 = 0;
	for (int z = 0; z < 1;) {

		for (; i3 < 5; i3++) {
			file.seekg(1, ios::cur);
			file.get(th[i3]);

			if (th[i3] < 49 || th[i3] > 53) {
				counter3++;
				break;
			};


		};

		if (counter3 > 0) {
			th[i3] = '0';
			counter3 = 0;
			file.seekg(-1, ios::cur);
			i3++;
		}
		else
			break;
	};







	if (th[4] == '0') {
		file.seekg(2, ios::cur);
	}
	else {
		file.seekg(3, ios::cur);
	}

	int  i4 = 0, counter4 = 0;
	for (int z = 0; z < 1;) {

		for (; i4 < 5; i4++) {
			file.seekg(1, ios::cur);
			file.get(fr[i4]);

			if (fr[i4] < 49 || fr[i4] > 53) {
				counter4++;
				break;
			};


		};

		if (counter4 > 0) {
			fr[i4] = '0';
			counter4 = 0;
			file.seekg(-1, ios::cur);
			i4++;
		}
		else
			break;
	};







	if (fr[4] == '0') {
		file.seekg(2, ios::cur);
	}
	else {
		file.seekg(3, ios::cur);
	}

	int  i5 = 0, counter5 = 0;
	for (int z = 0; z < 1;) {

		for (; i5 < 5; i5++) {
			file.seekg(1, ios::cur);
			file.get(sa[i5]);

			if (sa[i5] < 49 || sa[i5] > 53) {
				counter5++;
				break;
			};


		};

		if (counter5 > 0) {
			sa[i5] = '0';
			counter5 = 0;
			file.seekg(-1, ios::cur);
			i5++;
		}
		else
			break;
	};







	if (sa[4] == '0') {
		file.seekg(2, ios::cur);
	}
	else {
		file.seekg(3, ios::cur);
	}

	int  i6 = 0, counter6 = 0;
	for (int z = 0; z < 1;) {

		for (; i6 < 5; i6++) {
			file.seekg(1, ios::cur);
			file.get(su[i6]);

			if (su[i6] < 49 || su[i6] > 53) {
				counter6++;
				break;
			};


		};

		if (counter6 > 0) {
			su[i6] = '0';
			counter6 = 0;
			file.seekg(-1, ios::cur);
			i6++;
		}
		else
			break;
	};


}
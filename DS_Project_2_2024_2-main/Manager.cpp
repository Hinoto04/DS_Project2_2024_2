#include "Manager.h"

Manager::Manager(int bpOrder) {
	ofstream ofs;
	ofs.open("logs.txt");
	bp = new BpTree(&ofs, bpOrder);
}

Manager::~Manager() {

}

void Manager::run(const char* command_txt) {
	string tmp;
	LOAD();
	PRINT_BP();
	cin >> tmp;
	return;
}

bool Manager::LOAD() {

	ifstream ifs;
	ifs.open("input_data.txt");
	if (ifs.fail()) return false; //File DoesNotExist
	else if(ifs.eof()) return false; //File Empty
	else if (bp->getRoot() != nullptr) return false; //B+ Already Loaded
	while(!ifs.eof()) {
		string AName, FNum, Dest, Status;
		int Seats;
		ifs >> AName;
		ifs >> FNum;
		ifs >> Dest;
		ifs >> Seats;
		ifs >> Status;
		FlightData* fd = new FlightData();
		fd->SetAirlineName(AName);
		fd->SetFlightNumber(FNum);
		fd->SetDestination(Dest);
		fd->SetNumberofSeats(Seats);
		fd->SetStatus(Status);
		cout << "Insert Try" << endl;
		this->bp->Insert(fd);
		cout << "Insert Success" << endl;
	}
	return true;
}

bool Manager::VLOAD() {
	avl->GetVector(Print_vector);
	return true;
}

bool Manager::ADD() {
	return true;
}

bool Manager::PRINT_BP() {
	bp->Print();
	return true;
}

bool Manager::SEARCH_BP(string name) {
	return true;
}

bool Manager::SEARCH_BP(string start, string end) {
	return true;
}

bool Manager::SEARCH_AVL(string name) {
	return true;
}

bool Compare(FlightData* flight1, FlightData* flight2) {
	return true;
}

bool Manager::VPRINT(string type_) {
	return true;
}

void Manager::printErrorCode(int n) {
	ofstream fout;
	fout.open("log.txt", ofstream::app);
	fout << "========== ERROR ==========" <<endl;
	fout << n << endl;
	fout << "===========================" << endl << endl;
	fout.close();
}


#include<iostream>
#include "Devices.h"
#include "PcConfigurator.h"
#include "PC.h"
#include "memory"
using namespace std;

// вивід конфігурації на екран
void PrintPcConfiguration(const string& configName, shared_ptr <PC> pc) {
	cout << "\n======== " << configName << " ========\n";
	cout << "Box: " << pc->GetBox()->ToString() << endl;
	cout << "Main Board: " << pc->GetMainBoard()->ToString() << endl;
	cout << "Processor: " << pc->GetProcessor()->ToString() << endl;
	cout << "HDD: " << pc->GetHdd()->ToString() << endl;
	cout << "Memory: " << pc->GetMemory()->ToString() << endl;
}

int main() {
	// 
	{
		shared_ptr <PcConfigurator> configurator = make_shared<PcConfigurator>();
		shared_ptr <PC> pc1 = make_shared<PC>();
		//
		configurator->SetPCFactory(make_shared<HomePcFactory>());
		configurator->Configure((pc1));
		PrintPcConfiguration("Home configuration", pc1);

		shared_ptr <PC> pc2 = make_shared<PC>();
		// 
		configurator->SetPCFactory(make_shared <OfficePcFactory>());
		configurator->Configure(pc2);
		PrintPcConfiguration("Office configuration", (pc2));
	}
	return 0;
}
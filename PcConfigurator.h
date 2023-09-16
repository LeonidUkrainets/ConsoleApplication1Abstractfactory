#pragma once
#include<iostream>
#include "PC.h"
#include "Devices.h"
#include "Factories.h"
using namespace std;

// ���� ������������ 
class PcConfigurator
{
	/*	������������ */
	shared_ptr <IPCFactory> pcFactory;
public:
	PcConfigurator() {
		pcFactory = nullptr;
	}
	virtual ~PcConfigurator() {
	}
	shared_ptr <IPCFactory> GetPCFactory() {
		return (pcFactory);
	}
	void SetPCFactory(shared_ptr <IPCFactory> pcCurrentFactory) {
		pcFactory = (pcCurrentFactory);
	}
	/*
	������� �����
	*/
	void Configure(shared_ptr <PC> pc)
	{
		pc->SetBox((pcFactory->CreateBox()));
		pc->SetMainBoard((pcFactory->CreateMainBoard()));
		pc->SetHdd((pcFactory->CreateHdd()));
		pc->SetMemory((pcFactory->CreateMemory()));
		pc->SetProcessor((pcFactory->CreateProcessor()));
	}
};
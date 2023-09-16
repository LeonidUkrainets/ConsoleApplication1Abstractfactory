#pragma once
#include<iostream>
#include "Devices.h"
using namespace std;

/*
 Інтерфейс фабрики для системного блока
*/

class IPCFactory {
public:
	virtual shared_ptr <Box>       CreateBox() = 0;
	virtual shared_ptr <Processor> CreateProcessor() = 0;
	virtual shared_ptr <MainBoard> CreateMainBoard() = 0;
	virtual shared_ptr <Hdd>       CreateHdd() = 0;
	virtual shared_ptr <Memory>    CreateMemory() = 0;
};

/*
 Фабрика для "домашньої" конфігурації системного блока
*/
class HomePcFactory : public IPCFactory {
public:
	shared_ptr <Box> CreateBox()
	{
		return (make_shared <SilverBox>());
	}
	shared_ptr <Processor> CreateProcessor()
	{
		return  (make_shared < IntelProcessor>());
	}
	shared_ptr < MainBoard> CreateMainBoard()
	{
		return  (make_shared < MSIMainBord>());
	}
	shared_ptr < Hdd> CreateHdd()
	{
		return  (make_shared < SamsungHDD>());
	}
	shared_ptr < Memory> CreateMemory()
	{
		return  (make_shared < Ddr2Memory>());
	}
};
/*
* Фабрика для конфiгурацiї системного блока офісного ПК
*/
class OfficePcFactory : public IPCFactory {
public:
	shared_ptr < Box> CreateBox()
	{
		return  (make_shared < BlackBox>());
	}
	shared_ptr < Processor> CreateProcessor()
	{
		return  (make_shared < AmdProcessor>());
	}
	shared_ptr < MainBoard> CreateMainBoard()
	{
		return  (make_shared <AsusMainBord>());
	}
	shared_ptr < Hdd> CreateHdd()
	{
		return  (make_shared < LGHDD>());
	}
	shared_ptr < Memory> CreateMemory()
	{
		return  (make_shared < DdrMemory>());
	}
};